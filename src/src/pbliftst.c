/*
 pbliftst.c - interactive ISAM file test frame

 Copyright (C) 2002 - 2007   Peter Graf

   This file is part of PBL - The Program Base Library.
   PBL is free software.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   For more information on the Program Base Library or Peter Graf,
   please see: http://www.mission-base.com/.

    $Log: pbliftst.c,v $
    Revision 1.19  2021/06/12 11:18:27  peter
    Synchronizing with github version

    Revision 1.18  2018/03/11 19:07:07  peter
    Improved test framework

------------------------------------------------------------------------------
*/

/*
 * make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char * pbliftst_c_id = "$Id: pbliftst.c,v 1.19 2021/06/12 11:18:27 peter Exp $";

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

#include "pbl.h"

#define PBL_ISAMTEST_BUFLEN              2048

static FILE * logfile;
static FILE * infile;

#ifdef _WIN32
#include <direct.h>
#endif

#include <stdarg.h>

static void pblPrint(
char * format,
...
)
{
    va_list ap;

    /*
     * use fprintf to give out the text
     */
    va_start( ap, format );
    vfprintf( stdout,
              format,
              ap
            );
    va_end(ap);

    /*
     * use fprintf to give out the text
     */
    va_start( ap, format );
    vfprintf( logfile,
              format,
              ap
            );
    va_end(ap);
}

static void putChar( int c )
{
   static int last = 0;

   if( last == '\n' && c == '\n' )
   {
       return;
   }

   last = c;
   putc( last, logfile );
}

static int getNonSpace( FILE* file, int* lineNumber )
{
	int c = EOF;
	for(;;)
	{
		int c = getc( file );
		if( c == '\n' )
		{
			*lineNumber += 1;
		}
		if( isspace( c ) )
		{
			continue;
		}
		break;
	}
	return c;
}

static int diffFiles( FILE * file1, char * logFileName )
{
	int rc = 0;
	int c1;
	int c2;
	int lineNumber1 = 1;
	int lineNumber2 = 1;

#ifdef PBL_MS_VS_2012
#pragma warning(disable: 4996)
#endif
    FILE * file2 = fopen( logFileName, "r" );
    if( !file2 )
    {
        fprintf( stderr, "Failed to open %s, %s\n", logFileName, strerror( errno ));
        exit( -1 );
    }
	if( fseek( file1, 0L, SEEK_SET ) )
	{
		fprintf( stderr, "Failed to rewind input file, %s\n", strerror( errno ));
        exit( -1 );
	}
	for(;;)
	{
		c1 = getNonSpace( file1, &lineNumber1 );
		c2 = getNonSpace( file2, &lineNumber2 );

		if( c1 != c2 )
		{
			 printf( "# input and output differ in line %d\n", lineNumber1 );
             fprintf( logfile, "# input and output differ in line %d\n", lineNumber1 );
			 rc = lineNumber1;
			 break;
		}
		if( c1 == EOF || c2 == EOF )
		{
			break;
		}
	}
	fclose( file2 );
	return rc;
}

static int getChar( void )
{
    int c;
    c = getc( infile );

    /*
     * a '#' starts a comment for the rest of the line
     */
    if( c == '#')
    {
        /*
         * comments starting with ## are duplicated to the output
         */
        c = getc( infile );
        if( c == '#' )
        {
            putChar( '#' );
            putChar( '#' );

            while( c != '\n' && c != EOF )
            {
                c = getc( infile );
                if( c != EOF )
                {
                    putChar( c );
                }
            }
        }
        else
        {
            while( c != '\n' && c != EOF )
            {
                c = getc( infile );
            }
        }
    }

    if( c != EOF )
    {
        putChar( c );
    }

    return c;
}

static void getWord( char * buffer )
{
    int i;

    /*
     * skip preceeding blanks
     */
    int c = ' ';
    while( isspace( c ) )
    {
        c = getChar();
    }

    /*
     * read one word
     */
    for( i = 0; i < PBL_ISAMTEST_BUFLEN - 1; i++, c = getChar() )
    {
        if( c == EOF )
        {
            exit( 0 );
        }

        if( isspace( c ) )
        {
            *buffer = '\0';
            return;
        }
        *buffer++ = c;
    }

    *buffer = '\0';
}

static int commaStrlen( char * s )
{
    char *ptr = s;

    while( ptr && *ptr && *ptr != ',' )
    {
        ptr++;
    }

    return ptr - s;
}

/*
 * if given a string of the form ",key1,key2,key3" etc,
 * replaces the "," commas with the length of the following word
 */
static void commaToLength( char * s )
{
    while( s && *s )
    {
        if( *s == ',' )
        {
            *s = 0xff & commaStrlen( s + 1 );
        }

        s++;
    }
}

/**
 * test frame for the ISAM file library
 *
 * This test frame calls the PBL ISAM file library,
 * it is an interactive test frame capable of regression tests.
 *
 * <B>Interactive mode:</B>
 * <UL>
 * Call the program pbliftst from a UNIX or DOS shell.
 * <BR>
 * The following commands to test the PBL ISAM File Library are supplied:
 * <UL>
 * <PRE>
 q       FOR QUIT
 open filename keyfile1,dupfile2,... update
 transaction < START | COMMIT | ROLLBACK >
 close
 flush
 insert ,key1,key2... data
 ninsert n key1,key2,... data
 find index key < LT | LE | FI | EQ | LA | GE | GT >
 nfind n index key < LT | LE | FI | EQ | LA | GE | GT >
 get index < NEXT | PREV | FIRST | LAST | THIS >
 datalen
 readdata
 readkey index
 updatedata data
 updatekey index key
 ndelete n
 </PRE>
 * </UL>
 * See \Ref{pblKEYFILE_TestFrame} for an example to interactively use the
 * test frame.
 * </UL>
 * <B>Regression mode:</B>
 * <UL>
 * Five regression test cases are supplied with the PBL ISAM library.
 *
 * ISAM0001.TST, ISAM0002.TST, ISAM0003.TST, ISAM0004.TST and ISAM0005.TST.
 *
 * ISAM0001.TST and ISAM0004.TST are run when the "make test"
 * is done. Do the following if you want to run the test cases per hand
 * <PRE>
   1. Build the pbliftst executable.          make all
   2. Create the sub directory isamtest.      mkdir isamtest
   3. Clear the sub directory isamtest.       rm imamtest/0*
   4. Run the test frame on this file.        pbliftst ISAM0001.TST
   5. Compare ISAM0001.TST and pbliftst.log   diff ISAM0001.TST pbliftst.log
 </PRE>
 * There should be no differences reported, if so your build of the
 * PBL library is most likely ok!
 *
 * </UL>
 */

int pblISAMFILE_TestFrame( int argc, char * argv[] )
{
	char   * logFileName = "./pbliftst.log";
    char     command  [ PBL_ISAMTEST_BUFLEN ];
    char     filename [ PBL_ISAMTEST_BUFLEN ];
    char     buffer   [ PBL_ISAMTEST_BUFLEN ];
    int      update;
    int      ival;
    int      dowork = 1;
    long     rc = 0;
    int      len;
    char   * ptr;

    pblIsamFile_t * isam = ( pblIsamFile_t *) 0;

    /*
     * if an argument is given it is treated as a command file
     */
    infile = stdin;
    if( argc > 1 )
    {
#ifdef PBL_MS_VS_2012
#pragma warning(disable: 4996)
#endif
        infile = fopen( argv[ 1 ], "r" );
        if( !infile )
        {
            fprintf( stderr, "Failed to open %s, %s\n",
                     argv[ 1 ], strerror( errno ));
            exit( -1 );
        }
    }

    /*
     * open the log file
     */
    logfile = fopen( logFileName, "wb" );
    if( !logfile )
    {
        fprintf( stderr, "cant open logfile, %s, %s\n",
                 logFileName, strerror( errno ));
        exit( 1 );
    }

    /*
     * main command loop
     */
    while( dowork )
    {
        memset( command, 0, sizeof( command ));
        memset( filename, 0, sizeof( filename ));
        memset( buffer, 0, sizeof( buffer ));

        errno = 0;

        /*
         * read the next command
         */
        printf( "\n##command: \n" );
		fflush( stdout );
		fflush( logfile );
        getWord( command );

        /*
         * interpret the command given
         */
        if( command[0] == 'q' || command[0] == 'Q' )
        {
            dowork = 0;
        }

        else if( !strcmp( command, "open" ))
        {
            int    k;
            int    nkeys;
            char * keyfilenames[ PBL_ISAMTEST_BUFLEN ];
            int    keydup[ PBL_ISAMTEST_BUFLEN ];

            printf( "# open filename keyfile1,dkeyfile2,... update\n" );
            getWord( filename );

            getWord( buffer );
            ptr = buffer;

            for( nkeys = 0; nkeys < PBL_ISAMTEST_BUFLEN; )
            {
                keyfilenames[ nkeys++ ] = ptr;

                ptr = strchr( ptr, ',' );
                if( !ptr )
                {
                    break;
                }

                *ptr = 0;
                ptr++;
            }

            for( k = 0; k < nkeys; k++ )
            {
                if( strstr( keyfilenames[ k ], "dup" ))
                {
                    keydup[ k ] = 1;
                }
                else
                {
                    keydup[ k ] = 0;
                }
            }

            getWord( command );
            update = atoi( command );

            pblPrint( "# pblIsamOpen( %s, %d, %d )\n",
                    filename, nkeys, update );

            if( isam )
            {
                pblIsamClose( isam );
            }

            isam = pblIsamOpen( filename, update, NULL, nkeys,
                                keyfilenames, keydup );
            if( isam )
            {
                pblPrint( "# ok!\n" );
            }
            else
            {
                pblPrint( "# not ok! pbl_errno %d, errno %d\n", pbl_errno, errno );
            }
        }

        else if( !strcmp( command, "transaction" ))
        {
            printf( "# transaction < START | COMMIT | ROLLBACK >\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );

            if( !strncmp( buffer, "ST", 2 ))
            {
                pblPrint( "# pblIsamStartTransaction( )\n" );
                rc = pblIsamStartTransaction( 1, &isam );

            }
            else if( !strncmp( buffer, "CO", 2 ))
            {
                pblPrint( "# pblIsamCommit( COMMIT )\n" );
                rc = pblIsamCommit( 1, &isam, 0 );
            }
            else if( !strncmp( buffer, "RO", 2 ))
            {
                pblPrint( "# pblIsamCommit( ROLLBACK )\n" );
                rc = pblIsamCommit( 1, &isam, 1 );
            }
            else
            {
                rc = 0;
            }

            if( !rc )
            {
                pblPrint( "# rc 0\n" );
                continue;
            }
            pblPrint( "# rc %ld, pbl_errno %d, errno %d\n", rc, pbl_errno, errno );
        }

        else if( !strcmp( command, "close" ))
        {
            printf( "# close\n" );
            if( !isam )
            {
                continue;
            }

            pblPrint( "# pblIsamClose( %d )\n", 1 );

            rc = pblIsamClose( isam );

            isam = 0;

            if( !rc )
            {
                pblPrint( "# rc 0\n" );
                continue;
            }
            pblPrint( "# rc %ld, pbl_errno %d, errno %d\n", rc, pbl_errno, errno );

        }

        else if( !strcmp( command, "flush" ))
        {
            printf( "# flush\n" );
            if( !isam )
            {
                continue;
            }

            pblPrint( "# pblIsamFlush( %d )\n", 1 );

            rc = pblIsamFlush( isam );
            if( !rc )
            {
                pblPrint( "# rc 0\n" );
                continue;
            }

            pblPrint( "# rc %ld, pbl_errno %d, errno %d\n", rc, pbl_errno, errno );
        }

        else if( !strcmp( command, "readdata" ))
        {
            printf( "# readdata\n" );
            if( !isam )
            {
                continue;
            }

            pblPrint( "# pblIsamReadData( currentrecord )\n" );

            rc = pblIsamReadData( isam, (unsigned char *)buffer, sizeof( buffer ) );
            if( rc < 0 )
            {
                pblPrint( "# rd %ld, pbl_errno %d, errno %d\n",
                        rc, pbl_errno, errno );
            }
            else
            {
                pblPrint( "# datalen %ld, data %s\n", rc, buffer );
            }
        }

        else if( !strcmp( command, "readkey" ))
        {
            int index;

            printf( "# readkey index\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            index = atoi( buffer );

            pblPrint( "# pblIsamReadKey( currentrecord, %d )\n", index );

            rc = pblIsamReadKey( isam, index, (unsigned char *)buffer );
            if( rc < 0 )
            {
                pblPrint( "# rc %ld, pbl_errno %d, errno %d\n",
                        rc, pbl_errno, errno );
            }
            else
            {
                pblPrint( "# keylen %ld, key %s\n", rc, buffer );
            }
        }

        else if( !strcmp( command, "updatedata" ))
        {
            printf( "# updatedata data\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            ival = strlen( buffer ) + 1;

            pblPrint( "# pblIsamUpdateData( %s, %d )\n", buffer, ival );

            rc = pblIsamUpdateData( isam, (unsigned char *)buffer, ival );
            if( rc < 0 )
            {
                pblPrint( "# rc %ld, pbl_errno %d, errno %d\n",
                        rc, pbl_errno, errno );
            }
            else
            {
                pblPrint( "# datalen %ld\n", rc );
            }
        }

        else if( !strcmp( command, "updatekey" ))
        {
            int index;

            printf( "# updatekey index key\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            index = atoi( buffer );

            getWord( buffer );
            ival = strlen( buffer );

            pblPrint( "# pblIsamUpdateKey( %d, %s, %d )\n", index, buffer, ival );

            rc = pblIsamUpdateKey( isam, index, (unsigned char *)buffer, ival );
            if( rc < 0 )
            {
                pblPrint( "# rc %ld, pbl_errno %d, errno %d\n",
                        rc, pbl_errno, errno );
            }
            else
            {
                pblPrint( "# rc %ld\n", rc );
            }
        }

        else if( !strcmp( command, "ndelete" ))
        {
            int n;
            int i;

            printf( "# ndelete n\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            n = atoi( buffer );

            pblPrint( "# pblIsamDelete( %d records )\n", n );

            for( i = 0; i < n; i++ )
            {
                rc = pblIsamGet( isam, PBLTHIS, 0, (unsigned char *)buffer );
                if( rc < 0 )
                {
                    pblPrint( "# i %d, rc %ld, pbl_errno %d, errno %d\n",
                             i, rc, pbl_errno, errno );
                    break;
                }

                rc = pblIsamDelete( isam );
                if( rc < 0 )
                {
                    pblPrint( "# i %d, rc %ld, pbl_errno %d, errno %d\n",
                             i, rc, pbl_errno, errno );
                    break;
                }
            }
            if( rc >= 0 )
            {
                pblPrint( "# deleted %d records, rc %ld\n", i, rc );
            }
        }

        else if( !strcmp( command, "insert" ))
        {
            printf( "# insert ,key1,key2... data\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            getWord( filename );
            ival = strlen( buffer );
            len = strlen( filename ) + 1;

            pblPrint( "# pblIsamInsert( %d, %s, %d, %s, %d )\n",
                     1, buffer, ival, filename, len );

            commaToLength( buffer );

            rc = pblIsamInsert( isam, (unsigned char *)buffer, ival, (unsigned char *)filename, len );
            if( !rc )
            {
                pblPrint( "# rc 0\n" );
                continue;
            }

            pblPrint( "# rc %ld, pbl_errno %d, errno %d\n",
                    rc, pbl_errno, errno );
        }

        else if( !strcmp( command, "ninsert" ))
        {
            int    nkeys = 3;
            char * keys[ PBL_ISAMTEST_BUFLEN ];
            int    n;
            int    i;
            int    k;

            printf( "# ninsert n key1,key2,... data\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            n = atoi( buffer );

            getWord( buffer );
            getWord( filename );
            len = strlen( filename ) + 1;

            ptr = buffer;

            for( nkeys = 0; nkeys < PBL_ISAMTEST_BUFLEN; nkeys++ )
            {
                keys[ nkeys ] = ptr;

                ptr = strchr( ptr, ',' );
                if( !ptr )
                {
                    break;
                }

                *ptr = 0;
                ptr++;
            }

            for( i = 0; i < n; i++ )
            {
                if( i == 0 )
                {
                    ival = 1;
                }
                ival = 0;
                command[ 0 ] = 0;
                for( k = 0; k <= nkeys; k++ )
                {
                    snprintf( command + ival, sizeof( command ) - ival,
                              ",%s%d", keys[ k ], i );

                    ival += strlen( command + ival );
                }

                if( i == 0 )
                {
                    ival = strlen( command );
                    pblPrint( "# pblIsamInsert( %d, %s, %d, %s, %d )\n",
                             1, command, ival, filename, len );
                }

                commaToLength( command );

                rc = pblIsamInsert( isam, (unsigned char *)command, ival, (unsigned char *)filename, len );
                if( rc < 0 )
                {
                    pblPrint( "# i %d, rc %ld, pbl_errno %d, errno %d\n",
                            i, rc, pbl_errno, errno );
                    break;
                }
            }

            if( rc >= 0 )
            {
                pblPrint( "# inserted %d records, rc %ld\n", i, rc );
            }
        }

        else if( !strcmp( command, "datalen" ))
        {
            printf( "# datalen\n" );
            if( !isam )
            {
                continue;
            }

            pblPrint( "# pblIsamReadDatalen( currentrecord )\n" );

            rc = pblIsamReadDatalen( isam );
            if( rc < 0 )
            {
                pblPrint( "# rc %ld, pbl_errno %d, errno %d\n",
                        rc, pbl_errno, errno );
            }
            else
            {
                pblPrint( "# datalen %ld\n", rc );
            }
        }

        else if( !strcmp( command, "get" ))
        {
            int index;

            printf( "# get index < NEXT | PREV | FIRST | LAST | THIS >\n" );
            if( !isam )
            {
                continue;
            }


            getWord( buffer );
            index = atoi( buffer );

            getWord( filename );
            if( !strncmp( filename, "NE", 2 ))
            {
                ival = PBLNEXT;
            }
            else if( !strncmp( filename, "PR", 2 ))
            {
                ival = PBLPREV;
            }
            else if( !strncmp( filename, "FI", 2 ))
            {
                ival = PBLFIRST;
            }
            else if( !strncmp( filename, "LA", 2 ))
            {
                ival = PBLLAST;
            }
            else
            {
                ival = PBLTHIS;
            }

            pblPrint( "# pblIsamGet( %d, %d )\n", ival, index );

            rc = pblIsamGet( isam, ival, index, (unsigned char *)buffer );
            if( rc < 0 )
            {
                pblPrint( "# rc %ld, pbl_errno %d, errno %d\n",
                        rc, pbl_errno, errno );
            }
            else
            {
                pblPrint( "# keylen %ld, key %.*s\n", rc, rc, buffer );
            }
        }

        else if( !strcmp( command, "find" ))
        {
            int index = 0;

            printf( "# find index key < LT | LE | FI | EQ | LA | GE | GT >\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            index = atoi( buffer );

            getWord( buffer );
            getWord( filename );

            if( !strncmp( filename, "GT", 2 ))
            {
                ival = PBLGT;
            }
            else if( !strncmp( filename, "FI", 2 ))
            {
                ival = PBLFI;
            }
            else if( !strncmp( filename, "LA", 2 ))
            {
                ival = PBLLA;
            }
            else if( !strncmp( filename, "GE", 2 ))
            {
                ival = PBLGE;
            }
            else if( !strncmp( filename, "LE", 2 ))
            {
                ival = PBLLE;
            }
            else if( !strncmp( filename, "LT", 2 ))
            {
                ival = PBLLT;
            }
            else
            {
                strcpy( filename, "EQ" );
                ival = PBLEQ;
            }

            len = strlen( buffer );
            pblPrint( "# pblIsamFind( %s, %s, %d )\n",
                    filename, buffer, len );

            rc = pblIsamFind( isam, ival, index, (unsigned char *)buffer, len, (unsigned char *)filename );

            if( rc < 0 )
            {
                pblPrint( "# rc %ld, pbl_errno %d, errno %d\n",
                        rc, pbl_errno, errno );
            }
            else
            {
                pblPrint( "# keylen %ld, key %s\n", rc, filename );
            }
        }


        else if( !strcmp( command, "nfind" ))
        {
            int    index;
            int    n;
            int    i;

            printf( "# nfind n index key "
                    "< LT | LE | FI | EQ | LA | GE | GT >\n" );
            if( !isam )
            {
                continue;
            }

            getWord( buffer );
            n = atoi( buffer );

            getWord( buffer );
            index = atoi( buffer );

            /*
             * read the key to search for
             */
            getWord( buffer );

            getWord( filename );
            if( !strncmp( filename, "GT", 2 ))
            {
                ival = PBLGT;
            }
            else if( !strncmp( filename, "FI", 2 ))
            {
                ival = PBLFI;
            }
            else if( !strncmp( filename, "LA", 2 ))
            {
                ival = PBLLA;
            }
            else if( !strncmp( filename, "GE", 2 ))
            {
                ival = PBLGE;
            }
            else if( !strncmp( filename, "LE", 2 ))
            {
                ival = PBLLE;
            }
            else if( !strncmp( filename, "LT", 2 ))
            {
                ival = PBLLT;
            }
            else
            {
                strcpy( filename, "EQ" );
                ival = PBLEQ;
            }

            for( i = 0; i < n; i++ )
            {
				if( i == 127 )
				{
					len = strlen( command );
				}
                snprintf( command, sizeof( command ),
                          "%s%d", buffer,
                          ((( rand() << 16 ) ^ rand()) & 0x7fffffff ) % n );


                if( i == 0 )
                {
                    len = strlen( buffer );
                    pblPrint( "# pblIsamFind( %d, %s, %d, %s, %d )\n",
                             1, filename, index, buffer, len );
                }

                len = strlen( command );

				if( i == 127 )
				{
					len = strlen( command );
				}
                rc = pblIsamFind( isam, ival, index, (unsigned char *)command, len, (unsigned char *)filename );

                if(( rc < 0 ) && ( pbl_errno != PBL_ERROR_NOT_FOUND ))
                {
                    pblPrint( "# i %d, %s, %d, rc %ld, pbl_errno %d, errno %d\n",
                            i, command, len, rc, pbl_errno, errno );
                    break;
                }
            }

            if( i >= n )
            {
                pblPrint( "# found %d records, rc %ld\n", i, 0 );
            }
        }

        else
        {
            printf( "# q       FOR QUIT\n" );
            printf( "# open filename keyfile1,dkeyfile2,... update\n" );
            printf( "# transaction < START | COMMIT | ROLLBACK >\n" );
            printf( "# close\n" );
            printf( "# flush\n" );
            printf( "# insert ,key1,key2... data\n" );
            printf( "# ninsert n key1,key2,... data\n" );
            printf( "# find index key < LT | LE | FI | EQ | LA | GE | GT >\n" );
            printf( "# nfind n index key "
                    "< LT | LE | FI | EQ | LA | GE | GT >\n" );
            printf( "# get index < NEXT | PREV | FIRST | LAST | THIS >\n" );
            printf( "# datalen\n" );
            printf( "# readdata\n" );
            printf( "# readkey index\n" );
            printf( "# updatedata data\n" );
            printf( "# updatekey index key\n" );
            printf( "# ndelete n\n" );
        }
    }
    if( argc > 1 )
	{
		fflush( logfile );
		if( diffFiles( infile, logFileName ))
		{
			return -1;
		}
	}
    return 0;
}

/*
 * Eclipse CDT does not like more than one main,
 * therefore hide all but one main with this -D option
 */
#ifdef _WIN32
#define _SHOW_ISAM_MAIN
#endif

#ifdef _CDT_BUILD
#define _SHOW_ISAM_MAIN 1
#endif

#ifdef PBLTEST
#define _SHOW_ISAM_MAIN 1
#endif

#ifdef CDT_BUILD
#undef _SHOW_ISAM_MAIN
#endif

#ifdef _SHOW_ISAM_MAIN

int main( int argc, char * argv[] )
{
    return pblISAMFILE_TestFrame( argc, argv );
}

#endif /* CDT_BUILD */

