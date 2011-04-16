/*
 pblSetTest.c - pbl set test frame

 Copyright (C) 2008   Peter Graf

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

    $Log: pblSetTest.c,v $
    Revision 1.21  2010/08/14 20:10:30  peter
    Cleanup during linux tests of pblPriorityQueue interface.

    Revision 1.20  2010/05/19 22:38:45  peter
    Testing the map.

    Revision 1.19  2009/11/26 18:45:55  peter
    activated set test

    Revision 1.18  2009/10/20 21:08:00  peter
    Added the pblHtCurrentKey function.

    Revision 1.17  2009/09/03 20:48:59  peter
    Just some cleanup on sets.

    Revision 1.16  2009/03/27 23:56:23  peter
    Some cleanup

    Revision 1.15  2009/03/11 23:48:44  peter
    More tests and clean up.

    Revision 1.14  2009/03/08 20:56:50  peter
    port to gcc (Ubuntu 4.3.2-1ubuntu12) 4.3.2.
    Exposing the hash set and tree set interfaces.



*/

/*
 * make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char* pblSetTest_c_id = "$Id: pblSetTest.c,v 1.21 2010/08/14 20:10:30 peter Exp $";

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "pbl.h"

static FILE * log;
static FILE * infile;

static void putChar( int c )
{
   static int last = 0;

   if( last == '\n' && c == '\n' )
       return;

   last = c;
   ( void ) putc( last, log );
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
       while( c != '\n' && c != EOF )
       {
           c = getc( infile );
       }
    }

    if( c != EOF )
        putChar( c );

    return( c );
}


static void getWord( char * buffer )
{
    int c;

    /*
     * skip preceeding blanks
     */
    c = ' ';
    while( c== '\t' || c == ' ' || c == '\n' )
        c = getChar();

    /*
     * read one word
     */
    for(;; c = getChar())
    {
        if( c == EOF )
        {
            exit( 0 );
        }

        if( c== '\t' || c == ' ' || c == '\n' )
        {
            *buffer = '\0';
            return;
        }

        *buffer++ = c;
    }
}

static char * items[] = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "20", "21", "22", "23", "24", "25", "26", "27", "28", "29"
};

#if 0
int isPrime( unsigned int number )
{
    unsigned int i;
    for( i = 3; i < number / 2; i += 2 )
    {
        if( number / i * i == number )
        {
            return 0;
        }
    }

    return 1;
}

void printPower2Primes()
{
    unsigned int i = 1;
    unsigned int j;
    for( j = ( 1 << i++ ) + 1; i < 30; j = ( 1 << i++ ) + 1 )
    {
        unsigned int number = 0;
        for( number = j; number < 0xfffffff; number += 2 )
        {
            if( isPrime( number ))
            {
                printf( "%u\n", number );
                break;
            }
        }
    }
    exit( 0 );
}
#endif

typedef struct pblTestAggregationContext
{
    int counter;
    FILE * log;
    FILE * out;
} pblTestAggregationContext;

static int aggregation              /** Test aggregation function. */
    (
        void * context,      /** The application context passed.                              */
        int index,           /** The index of the element passed.                             */
        void * element       /** The collection element to aggregate.                         */
    )
{
    pblTestAggregationContext * pblTestContext = (pblTestAggregationContext *)context;

    if( pblTestContext->counter <= 0 )
    {
        return 1; /* break the aggregation */
    }

    fprintf( pblTestContext->out, "# aggregation counter %d, i %d, element %s\n", pblTestContext->counter, index, (char*)element );
    fprintf( pblTestContext->log, "# aggregation counter %d, i %d, element %s\n", pblTestContext->counter, index, (char*)element );

    pblTestContext->counter--;

    return 0; /* continue aggregation */
}

/**
 * test frame for the library
 */
int pblSet_TestFrame( int argc, char * argv[] )
{
    char command[ 2048 ];
    char filename [ 2048 ];
    char buffer [ 2048 ];
    int  ival;
    int  dowork = 1;
    long rc;
    int  i;

    char * ptr;

    PblSet * testCollection = ( PblSet *) 0;
    PblIterator * testIterator = (PblIterator *) 0;

#if 0
    printPower2Primes();
#endif

    infile = stdin;
    if( argc > 1 )
    {
        infile = fopen( argv[ 1 ], "r" );
        if( !infile )
        {
            fprintf( stderr, "Failed to open %s, %s\n",
                     argv[ 1 ], strerror( errno ));
            exit( -1 );
        }
    }

    log = fopen( "./pblSetTest.log", "w" );
    if( !log )
    {
        fprintf( stderr, "cant open logfile, .\\pblSetTest.log\n" );
        exit( 1 );
    }

    while( dowork )
    {
        memset( command, 0, sizeof( command ));
        memset( filename, 0, sizeof( filename ));
        memset( buffer, 0, sizeof( buffer ));

        errno = 0;

        printf( "\n##command: \n" );
        fprintf( log, "\n##command: \n" );

        getWord( command );

        if( command[0] == 'q' || command[0] == 'Q' )
        {
            dowork = 0;
        }

        else if( !strcmp( command, "createTreeSet" ))
        {
            printf( "# pblSetNewTreeSet( void )\n" );
            fprintf( log, "# pblSetNewTreeSet( void )\n" );

            if( testCollection )
            {
                ( void ) pblSetFree( testCollection );
            }

            testCollection = pblSetNewTreeSet( );

            if( testCollection )
            {
                printf( "# ok!\n" );
                fprintf( log, "# ok!\n" );
            }
            else
            {
                printf( "# pbl_errno %d\n", pbl_errno );
                fprintf( log, "# pbl_errno %d\n", pbl_errno );
            }
        }

        else if( !strcmp( command, "createHashSet" ))
        {
            printf( "# pblSetNewHashSet( void )\n" );
            fprintf( log, "# pblSetNewHashSet( void )\n" );

            if( testCollection )
            {
                ( void ) pblSetFree( testCollection );
            }

            testCollection = pblSetNewHashSet( );

            if( testCollection )
            {
                printf( "# ok!\n" );
                fprintf( log, "# ok!\n" );
            }
            else
            {
                printf( "# pbl_errno %d\n", pbl_errno );
                fprintf( log, "# pbl_errno %d\n", pbl_errno );
            }
        }

        else if( !strcmp( command, "aggregate" ))
        {
            pblTestAggregationContext pblTestContext;

            if( !testCollection )
                continue;

            printf( "# aggregate counter\n" );
            fprintf( log, "# aggregate counter\n" );

            getWord( buffer );
            pblTestContext.counter = atoi( buffer );
            pblTestContext.log = log;
            pblTestContext.out = stdout;

            printf( "# pblCollectionAggregate( %d )\n", pblTestContext.counter );
            fprintf( log, "# pblCollectionAggregate( %d )\n", pblTestContext.counter );

            rc = pblCollectionAggregate( testCollection, &pblTestContext, aggregation );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }


        else if( !strcmp( command, "free" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetFree( %d )\n", 1 );
            fprintf( log, "# pblSetFree( %d )\n", 1 );

            pblSetFree( testCollection );
            testCollection = ( PblSet * ) 0;

            printf( "# ok" );
            fprintf( log, "# ok\n" );
        }

        else if( !strcmp( command, "add" ))
        {
            if( !testCollection )
                continue;

            printf( "# add itemIndex\n" );
            fprintf( log, "# add itemIndex\n" );

            getWord( buffer );
            ival = atoi( buffer );
            if( ival < 0)
            {
                ptr = NULL;
            }
            else
            {
                ptr = items[ ival ];
            }

            printf( "# pblSetAdd( %s )\n",
                    ptr ? ptr : "NULL" );

            fprintf( log, "# pblSetAdd( %s )\n",
                     ptr ? ptr : "NULL" );

            rc = pblSetAdd( testCollection, ptr );

            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "addAll" ))
        {
            PblSet * clone = ( PblSet *) 0;

            if( !testCollection )
                continue;

            printf( "# pblSetAddAll( %d )\n", 1 );
            fprintf( log, "# pblSetAddAll( %d )\n", 1 );

            clone = pblSetCloneRange( testCollection, 0, 0 );
            if( !clone )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        (long)-1, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        (long)-1, pbl_errno );
                break;
            }

            rc = pblSetAddAll( clone, testCollection );

            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                pblSetFree( clone );
                break;
            }

            pblSetPrint( stdout, clone );
            pblSetPrint( log, clone );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
            pblSetFree( clone );
        }

        else if( !strcmp( command, "clear" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetClear( %d )\n", 1 );
            fprintf( log, "# pblSetClear( %d )\n", 1 );

            pblSetClear( testCollection );

            printf( "# ok" );
            fprintf( log, "# ok\n" );
        }

        else if( !strcmp( command, "clone" ) )
        {
            PblSet * clone;

            if( !testCollection )
                continue;

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", 1 );
            fprintf( log, "# ok size %d\n", 1 );

            pblSetFree( clone );
        }

        else if( !strcmp( command, "cloneRange" ))
        {
            PblSet * clone;
            char ** array;

            if( !testCollection )
                continue;

            printf( "# cloneRange from to \n" );
            fprintf( log, "# cloneRange from to\n" );

            getWord( buffer );
            ival = atoi( buffer );

            getWord( command );
            i = atoi( command );

            printf( "# pblSetCloneRange( %d, %d )\n", ival, i );
            fprintf( log, "# pblSetCloneRange( %d, %d )\n",ival, i );

            clone = pblSetCloneRange( testCollection, ival, i );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                continue;
            }

            if( pblSetSize( clone ) == 0 )
            {
                printf( "# OK size %d\n", pblSetSize( clone ) );
                fprintf( log, "# OK size %d\n", pblSetSize( clone ) );
                pblSetFree( clone );
                continue;
            }

            printf( "# pblSetToArray( clone )\n" );
            fprintf( log, "# pblSetToArray( clone )\n" );

            array = (char**)pblSetToArray( clone );
            if( array == NULL )
            {
                printf( "# NULL, pbl_errno %d\n",
                        pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n",
                        pbl_errno );
                pblSetFree( clone );
                continue;
            }

            printf( "# OK size %d\n", pblSetSize( clone ) );
            fprintf( log, "# OK size %d\n", pblSetSize( clone ) );

            for( i = 0; i < pblSetSize( clone ); i++ )
            {
                char * item =  array[i];

                printf( "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
                fprintf( log, "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
            }

            PBL_FREE(array );

            printf( "# Clone Iteration DONE\n" );
            fprintf( log, "# Clone Iteration DONE\n" );

            pblSetFree( clone );
        }

        else if( !strcmp( command, "contains" ))
        {
            if( !testCollection )
                continue;

            printf( "# contains itemIndex\n" );
            fprintf( log, "# contains itemIndex\n" );

            getWord( buffer );
            ival = atoi( buffer );
            if( ival < 0)
            {
                ptr = NULL;
            }
            else
            {
                ptr = items[ ival ];
            }

            printf( "# pblSetContains( %s )\n",
                    ptr ? ptr : "NULL" );

            fprintf( log, "# pblSetContains( %s )\n",
                     ptr ? ptr : "NULL" );

            rc = pblSetContains( testCollection, ptr );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "containsAll" ) )
        {
            PblSet * clone;

            if( !testCollection )
                continue;

            printf( "# pblSetPrint( original )\n" );
            fprintf( log, "# pblSetPrint( original )\n" );

            pblSetPrint( stdout, testCollection );
            pblSetPrint( log, testCollection );

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( clone )\n" );
            fprintf( log, "# pblSetPrint( clone )\n" );

            pblSetPrint( stdout, clone );
            pblSetPrint( log, clone );

            printf( "\n# pblSetContainsAll( %d, YES )\n", 1 );
            fprintf( log, "# pblSetContainsAll( %d, YES )\n", 1 );

            rc = pblSetContainsAll( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "# pblSetAdd( %d, NotFound )\n", 1 );
            fprintf( log, "# pblSetAdd( %d, NotFound )\n", 1 );

            rc = pblSetAdd(clone, "NotFound" );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# pblSetContainsAll( %d, NO )\n", 1 );
            fprintf( log, "# pblSetContainsAll( %d, NO )\n", 1 );

            rc = pblSetContainsAll( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetFree( clone );
        }

        else if( !strcmp( command, "difference" ) )
        {
            PblSet * clone;
            PblSet * result;

            if( !testCollection )
                continue;

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetDifference( testSet, clone )\n" );
            fprintf( log, "# pblSetDifference( testSet, clone )\n" );

            result = pblSetDifference( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( difference )\n" );
            fprintf( log, "# pblSetPrint( difference )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );
            pblSetFree( result );

            printf( "# pblSetRemoveFirst( clone )\n" );
            fprintf( log, "# pblSetRemoveFirst( clone )\n" );

            ptr = pblSetRemoveFirst( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "# pblSetRemoveLast( clone )\n" );
            fprintf( log, "# pblSetRemoveLast( clone )\n" );

            ptr = pblSetRemoveLast( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "\n# pblSetDifference( testSet, clone )\n" );
            fprintf( log, "# pblSetDifference( testSet, clone )\n" );

            result = pblSetDifference( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( difference )\n" );
            fprintf( log, "# pblSetPrint( difference )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );
            pblSetFree( result );

            printf( "\n# pblSetDifference( clone, testSet )\n" );
            fprintf( log, "# pblSetDifference( clone, testSet )\n" );

            result = pblSetDifference( clone, testCollection );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( difference )\n" );
            fprintf( log, "# pblSetPrint( difference )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );

            pblSetFree( result );
            pblSetFree( clone );
        }

        else if( !strcmp( command, "element" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetElement( %d )\n", 1 );
            fprintf( log, "# pblSetElement( %d )\n", 1 );

            ptr = pblSetElement( testCollection );
            if( !ptr )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# first %s", ptr );
                fprintf( log, "# first %s\n", ptr );
            }
        }

        else if( !strcmp( command, "ensureCapacity" ))
        {
            if( !testCollection )
                continue;

            printf( "# ensureCapacity minCapacity\n" );
            fprintf( log, "# ensureCapacity minCapacity\n" );

            getWord( buffer );
            ival = atoi( buffer );

            printf( "# ensureCapacity( %d )\n",
                    ival );

            fprintf( log, "# ensureCapacity( %d )\n",
                     ival );

            rc = pblSetEnsureCapacity( testCollection, ival );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "equals" ) )
        {
            PblSet * clone;

            if( !testCollection )
                continue;

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetEquals( %d, YES )\n", 1 );
            fprintf( log, "# pblSetEquals( %d, YES )\n", 1 );

            rc = pblSetEquals( testCollection, testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "\n# pblSetEquals( %d, YES )\n", 1 );
            fprintf( log, "# pblSetEquals( %d, YES )\n", 1 );

            rc = pblSetEquals( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "# pblSetAdd( %d, NotFound )\n", 1 );
            fprintf( log, "# pblSetAdd( %d, NotFound )\n", 1 );

            rc = pblSetAdd(clone, "NotFound" );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# pblSetEquals( %d, NO )\n", 1 );
            fprintf( log, "# pblSetEquals( %d, NO )\n", 1 );

            rc = pblSetEquals( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetFree( clone );

            printf( "# pblCollectionConvertToArrayList( collection )\n");
            fprintf( log, "# pblCollectionConvertToArrayList( collection )\n" );

            clone = pblCollectionConvertToArrayList( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetEquals( testcollection, clone ) YES\n" );
            fprintf( log, "# pblSetEquals( testcollection, clone ) YES\n" );

            rc = pblSetEquals( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "\n# pblSetEquals( clone, testcollection ) YES\n" );
            fprintf( log, "# pblSetEquals( clone, testcollection ) YES\n" );

            rc = pblSetEquals( clone, testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetFree( clone );

            printf( "# pblCollectionConvertToLinkedList( collection )\n");
            fprintf( log, "# pblCollectionConvertToLinkedList( collection )\n" );

            clone = pblCollectionConvertToLinkedList( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetEquals( testcollection, clone ) YES\n" );
            fprintf( log, "# pblSetEquals( testcollection, clone ) YES\n" );

            rc = pblSetEquals( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "\n# pblSetEquals( clone, testcollection ) YES\n" );
            fprintf( log, "# pblSetEquals( clone, testcollection ) YES\n" );

            rc = pblSetEquals( clone, testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetFree( clone );

            printf( "# pblCollectionConvertToHashSet( collection )\n");
            fprintf( log, "# pblCollectionConvertToHashSet( collection )\n" );

            clone = pblCollectionConvertToHashSet( testCollection, NULL );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetEquals( testcollection, clone ) YES\n" );
            fprintf( log, "# pblSetEquals( testcollection, clone ) YES\n" );

            rc = pblSetEquals( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "\n# pblSetEquals( clone, testcollection ) YES\n" );
            fprintf( log, "# pblSetEquals( clone, testcollection ) YES\n" );

            rc = pblSetEquals( clone, testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetFree( clone );

            printf( "# pblCollectionConvertToTreeSet( collection )\n");
            fprintf( log, "# pblCollectionConvertToTreeSet( collection )\n" );

            clone = pblCollectionConvertToTreeSet( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetEquals( testcollection, clone ) YES\n" );
            fprintf( log, "# pblSetEquals( testcollection, clone ) YES\n" );

            rc = pblSetEquals( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "\n# pblSetEquals( clone, testcollection ) YES\n" );
            fprintf( log, "# pblSetEquals( clone, testcollection ) YES\n" );

            rc = pblSetEquals( clone, testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetFree( clone );

        }

        else if( !strcmp( command, "get" ))
        {
            if( !testCollection )
                continue;

            printf( "# get index\n" );
            fprintf( log, "# get index\n" );

            getWord( buffer );
            ival = atoi( buffer );

            printf( "# pblSetGet( %d )\n", ival );
            fprintf( log, "# pblSetGet( %d )\n", ival );

            ptr = pblSetGet( testCollection, ival );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# get( %d )  %s", ival, ptr ? ptr : "NULL" );
                fprintf( log, "# get( %d ) %s\n", ival, ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "getCapacity" ))
        {
            if( !testCollection )
                continue;

            printf( "# getCapacity\n" );
            fprintf( log, "# getCapacity\n" );

            rc = pblSetGetCapacity( testCollection );

            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "getCompareFunction" ))
        {
            if( !testCollection )
                continue;

            printf( "# getCompareFunction\n" );
            fprintf( log, "# getCompareFunction\n" );

            ptr = pblSetGetCompareFunction( testCollection );

            printf( "# %s\n", ptr ? "FUNCTION SET" : "NULL" );
            fprintf( log, "# %s\n", ptr ? "FUNCTION SET" : "NULL" );
        }

        else if( !strcmp( command, "getFirst" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetGetFirst( %d )\n", 1 );
            fprintf( log, "# pblSetGetFirst( %d )\n", 1 );

            ptr = pblSetGetFirst( testCollection );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# first %s", ptr ? ptr : "NULL" );
                fprintf( log, "# first %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "getHashValueFunction" ))
        {
            if( !testCollection )
                continue;

            printf( "# getHashValueFunction\n" );
            fprintf( log, "# getHashValueFunction\n" );

            ptr = pblSetGetHashValueFunction( testCollection );

            printf( "# %s\n", ptr ? "FUNCTION SET" : "NULL" );
            fprintf( log, "# %s\n", ptr ? "FUNCTION SET" : "NULL" );
        }

        else if( !strcmp( command, "getLast" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetGetLast(  )\n" );
            fprintf( log, "# pblSetGetLast(  )\n" );

            ptr = pblSetGetLast( testCollection );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# last %s", ptr ? ptr : "NULL" );
                fprintf( log, "# last %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "IndexOf" ))
        {
            if( !testCollection )
                continue;

            printf( "# IndexOf itemIndex\n" );
            fprintf( log, "# IndexOf itemIndex\n" );

            getWord( buffer );
            ival = atoi( buffer );
            if( ival < 0)
            {
                ptr = NULL;
            }
            else
            {
                ptr = items[ ival ];
            }

            printf( "# pblSetIndexOf( %s )\n",
                    ptr ? ptr : "NULL" );

            fprintf( log, "# pblSetIndexOf( %s )\n",
                     ptr ? ptr : "NULL" );

            rc = pblSetIndexOf( testCollection, ptr );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "intersection" ) )
        {
            PblSet * clone;
            PblSet * result;

            if( !testCollection )
                continue;

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetIntersection( testSet, clone )\n" );
            fprintf( log, "# pblSetIntersection( testSet, clone )\n" );

            result = pblSetIntersection( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( intersection )\n" );
            fprintf( log, "# pblSetPrint( intersection )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );
            pblSetFree( result );

            printf( "# pblSetRemoveFirst( clone )\n" );
            fprintf( log, "# pblSetRemoveFirst( clone )\n" );

            ptr = pblSetRemoveFirst( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "# pblSetRemoveLast( clone )\n" );
            fprintf( log, "# pblSetRemoveLast( clone )\n" );

            ptr = pblSetRemoveLast( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "\n# pblSetIntersection( testSet, clone )\n" );
            fprintf( log, "# pblSetIntersection( testSet, clone )\n" );

            result = pblSetIntersection( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( intersection )\n" );
            fprintf( log, "# pblSetPrint( intersection )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );
            pblSetFree( result );

            printf( "\n# pblSetIntersection( clone, testSet )\n" );
            fprintf( log, "# pblSetIntersection( clone, testSet )\n" );

            result = pblSetIntersection( clone, testCollection );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( intersection )\n" );
            fprintf( log, "# pblSetPrint( intersection )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );

            pblSetFree( result );
            pblSetFree( clone );
        }

        else if( !strcmp( command, "IsEmpty" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetIsEmpty( %d )\n", 1 );
            fprintf( log, "# pblSetIsEmpty( %d )\n", 1 );

            rc = pblSetIsEmpty( testCollection );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "IsHashSet" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetIsHashSet( %d )\n", 1 );
            fprintf( log, "# pblSetIsHashSet( %d )\n", 1 );

            rc = pblSetIsHashSet( testCollection );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "IsSet" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetIsSet( %d )\n", 1 );
            fprintf( log, "# pblSetIsSet( %d )\n", 1 );

            rc = pblSetIsSet( testCollection );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "IsSubset" ) )
        {
            PblSet * clone;

            if( !testCollection )
                continue;

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetIsSubset( testSet, testSet )\n" );
            fprintf( log, "# pblSetIsSubset( testSet, testSet )\n" );

            rc = pblSetIsSubset( testCollection, testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "\n# pblSetIsSubset( testSet, clone )\n" );
            fprintf( log, "# pblSetIsSubset( testSet, clone )\n" );

            rc = pblSetIsSubset( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "# pblSetRemoveFirst( clone )\n" );
            fprintf( log, "# pblSetRemoveFirst( clone )\n" );

            ptr = pblSetRemoveFirst( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "# pblSetRemoveLast( clone )\n" );
            fprintf( log, "# pblSetRemoveLast( clone )\n" );

            ptr = pblSetRemoveLast( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "\n# pblSetIsSubset( testSet, clone )\n" );
            fprintf( log, "# pblSetIsSubset( testSet, clone )\n" );

            rc = pblSetIsSubset( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "\n# pblSetIsSubset( clone, testSet )\n" );
            fprintf( log, "# pblSetIsSubset( clone, testSet )\n" );

            rc = pblSetIsSubset( clone, testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetFree( clone );
        }

        else if( !strcmp( command, "IsTreeSet" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetIsTreeSet( %d )\n", 1 );
            fprintf( log, "# pblSetIsTreeSet( %d )\n", 1 );

            rc = pblSetIsTreeSet( testCollection );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "LastIndexOf" ))
        {
            if( !testCollection )
                continue;

            printf( "# LastIndexOf itemIndex\n" );
            fprintf( log, "# LastIndexOf itemIndex\n" );

            getWord( buffer );
            ival = atoi( buffer );
            if( ival < 0)
            {
                ptr = NULL;
            }
            else
            {
                ptr = items[ ival ];
            }

            printf( "# pblSetLastIndexOf( %s )\n",
                    ptr ? ptr : "NULL" );

            fprintf( log, "# pblSetLastIndexOf( %s )\n",
                     ptr ? ptr : "NULL" );

            rc = pblSetLastIndexOf( testCollection, ptr );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "peek" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetPeek( %d )\n", 1 );
            fprintf( log, "# pblSetPeek( %d )\n", 1 );

            ptr = pblSetPeek( testCollection );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# first %s", ptr ? ptr : "NULL" );
                fprintf( log, "# first %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "poll" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetPoll( %d )\n", 1 );
            fprintf( log, "# pblSetPoll( %d )\n", 1 );

            ptr = pblSetPoll( testCollection );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# polled first %s", ptr ? ptr : "NULL" );
                fprintf( log, "# polled first %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "pop" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetPop( %d )\n", 1 );
            fprintf( log, "# pblSetPop( %d )\n", 1 );

            ptr = pblSetPop( testCollection );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# popped last %s", ptr ? ptr : "NULL" );
                fprintf( log, "# popped last %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "print" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetPrint( %d )\n", 1 );
            fprintf( log, "# pblSetPrint( %d )\n", 1 );

            pblSetPrint( stdout, testCollection );
            pblSetPrint( log, testCollection );
        }

        else if( !strcmp( command, "remove" ))
        {
            if( !testCollection )
                continue;

            printf( "# remove itemIndex\n" );
            fprintf( log, "# remove itemIndex\n" );

            getWord( buffer );
            ival = atoi( buffer );
            if( ival < 0)
            {
                ptr = NULL;
            }
            else
            {
                ptr = items[ ival ];
            }

            printf( "# pblSetRemoveElement( %s )\n",
                    ptr ? ptr : "NULL" );

            fprintf( log, "# pblSetRemoveElement( %s )\n",
                     ptr ? ptr : "NULL" );

            rc = pblSetRemoveElement( testCollection, ptr );

            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "removeAll" ))
        {
            PblList * clone = ( PblList *) 0;

            if( !testCollection )
                continue;

            printf( "# pblSetRemoveAll( %d )\n", 1 );
            fprintf( log, "# pblSetRemoveAll( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        (long)-1, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        (long)-1, pbl_errno );
                break;
            }

            rc = pblSetRemoveAll( testCollection, clone );

            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                pblSetFree( clone );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
            pblSetFree( clone );
        }

        else if( !strcmp( command, "removeAt" ))
        {
            if( !testCollection )
                continue;

            printf( "# removeAt index\n" );
            fprintf( log, "# removeAt index\n" );

            getWord( buffer );
            ival = atoi( buffer );

            printf( "# pblSetRemoveAt( %d )\n", ival );
            fprintf( log, "# pblSetRemoveAt( %d )\n", ival );

            ptr = pblSetRemoveAt( testCollection, ival );
            if( ptr == NULL )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# removed %d %s", ival, ptr ? ptr : "NULL" );
                fprintf( log, "# removed %d %s\n", ival, ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "removeFirst" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetRemoveFirst( %d )\n", 1 );
            fprintf( log, "# pblSetRemoveFirst( %d )\n", 1 );

            ptr = pblSetRemoveFirst( testCollection );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# removed first %s", ptr ? ptr : "NULL" );
                fprintf( log, "# removed first %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "removeLast" ) )
        {
            if( !testCollection )
                continue;

            printf( "# pblSetRemoveLast( %d )\n", 1 );
            fprintf( log, "# pblSetRemoveLast( %d )\n", 1 );

            ptr = pblSetRemoveLast( testCollection );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# removed last %s", ptr ? ptr : "NULL" );
                fprintf( log, "# removed last %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "retainAll" ))
        {
            PblSet * clone = ( PblSet *) 0;

            if( !testCollection )
                continue;

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        (long)-1, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        (long)-1, pbl_errno );
                break;
            }

            printf( "# pblSetRetainAll( original, clone )\n" );
            fprintf( log, "# pblSetRetainAll( original, clone )\n" );

            rc = pblSetRetainAll( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                pblSetFree( clone );
                break;
            }


            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            printf( "# pblSetRemoveFirst( clone )\n" );
            fprintf( log, "# pblSetRemoveFirst( clone, )\n" );

            ptr = pblSetRemoveFirst( clone );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# removed first %s\n", ptr ? ptr : "NULL" );
                fprintf( log, "# removed first %s\n", ptr ? ptr : "NULL" );
            }

            printf( "# pblSetRemoveLast( clone )\n" );
            fprintf( log, "# pblSetRemoveLast( clone )\n" );

            ptr = pblSetRemoveLast( clone );
            if( ptr == (char *)-1 )
            {
                printf( "# NOT FOUND, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NOT FOUND, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# removed last %s\n", ptr ? ptr : "NULL" );
                fprintf( log, "# removed last %s\n", ptr ? ptr : "NULL" );
            }

            pblSetPrint( stdout, clone );
            pblSetPrint( log, clone );

            printf( "# pblSetRetainAll( %d )\n", 1 );
            fprintf( log, "# pblSetRetainAll( %d )\n", 1 );

            rc = pblSetRetainAll( testCollection, clone );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                pblSetFree( clone );
                break;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );

            pblSetPrint( stdout, testCollection );
            pblSetPrint( log, testCollection );

            pblSetFree( clone );
        }

        else if( !strcmp( command, "size" ))
        {
            if( !testCollection )
                continue;


            printf( "# pblSetSize(  )\n"  );
            fprintf( log, "# pblSetSize(  )\n" );

            rc = pblSetSize( testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                break;
            }
            else
            {
                printf( "# rc %ld\n", rc );
                fprintf( log, "# rc %ld\n", rc );
            }
        }

        else if( !strcmp( command, "strcmp" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetSetCompareFunction( %d )\n", 1 );
            fprintf( log, "# pblSetSetCompareFunction( %d )\n", 1 );

            ptr = pblSetSetCompareFunction( testCollection, pblCollectionStringCompareFunction );

            printf( "# ok %s", ptr ? "Function was set" : "NULL" );
            fprintf( log, "# ok %s\n", ptr ? "Function was set" : "NULL" );
        }


        else if( !strcmp( command, "strhash" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetSetHashValueFunction( %d )\n", 1 );
            fprintf( log, "# pblSetSetHashValueFunction( %d )\n", 1 );

            ptr = pblSetSetHashValueFunction( testCollection, pblSetStringHashValue );

            printf( "# ok %s", ptr ? "Function was set" : "NULL" );
            fprintf( log, "# ok %s\n", ptr ? "Function was set" : "NULL" );
        }

        else if( !strcmp( command, "symmectricDifference" ) )
        {
            PblSet * clone;
            PblSet * result;

            if( !testCollection )
                continue;

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetSymmectricDifference( testSet, clone )\n" );
            fprintf( log, "# pblSetSymmectricDifference( testSet, clone )\n" );

            result = pblSetSymmectricDifference( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( SymmectricDifference )\n" );
            fprintf( log, "# pblSetPrint( SymmectricDifference )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );
            pblSetFree( result );

            printf( "# pblSetRemoveFirst( clone )\n" );
            fprintf( log, "# pblSetRemoveFirst( clone )\n" );

            ptr = pblSetRemoveFirst( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "# pblSetRemoveLast( clone )\n" );
            fprintf( log, "# pblSetRemoveLast( clone )\n" );

            ptr = pblSetRemoveLast( clone );
            if( !ptr )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# OK %s\n", ptr );
            fprintf( log, "# OK %s\n", ptr );

            printf( "\n# pblSetSymmectricDifference( testSet, clone )\n" );
            fprintf( log, "# pblSetSymmectricDifference( testSet, clone )\n" );

            result = pblSetSymmectricDifference( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( SymmectricDifference )\n" );
            fprintf( log, "# pblSetPrint( SymmectricDifference )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );

            pblSetFree( result );
            pblSetFree( clone );
        }

        else if( !strcmp( command, "toArray" ))
        {
            char ** array;
            if( !testCollection )
                continue;

            printf( "# pblSetToArray( )\n" );
            fprintf( log, "# pblSetToArray( )\n" );

            array = (char**)pblSetToArray( testCollection );
            if( array == NULL )
            {
                printf( "# NULL, pbl_errno %d\n",
                        pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n",
                        pbl_errno );
                continue;
            }

            printf( "# OK\n" );
            fprintf( log, "# OK\n" );

            for( i = 0; i < pblSetSize( testCollection ); i++ )
            {
                char * item =  array[i];

                printf( "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
                fprintf( log, "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
            }

            PBL_FREE(array );
            printf( "# Array Iteration DONE\n" );
            fprintf( log, "# Array Iteration DONE\n" );
        }

        else if( !strcmp( command, "trim" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetTrimToSize( )\n" );
            fprintf( log, "# pblSetTrimToSize( )\n" );

            rc = pblSetTrimToSize( testCollection );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
            }
            else
            {
                printf( "# rc %ld\n", rc );
                fprintf( log, "# rc %ld\n", rc );
            }
        }

        else if( !strcmp( command, "union" ) )
        {
            PblSet * clone;
            PblSet * result;

            if( !testCollection )
                continue;

            printf( "# pblSetCloneRange( set, 0, 0 )\n" );
            fprintf( log, "# pblSetCloneRange( set, 0, 0 )\n" );

            clone = pblSetCloneRange( testCollection, 0, 0 );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetUnion( testSet, empty )\n" );
            fprintf( log, "# pblSetUnion( testSet, empty )\n" );

            result = pblSetUnion( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( Union )\n" );
            fprintf( log, "# pblSetPrint( Union )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );

            pblSetFree( result );
            pblSetFree( clone );

            printf( "# pblSetClone( %d )\n", 1 );
            fprintf( log, "# pblSetClone( %d )\n", 1 );

            clone = pblSetClone( testCollection );
            if( !clone )
            {
                printf( "# NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# ok size %d", pblSetSize( clone ) );
            fprintf( log, "# ok size %d\n", pblSetSize( clone ) );

            printf( "\n# pblSetUnion( testSet, empty )\n" );
            fprintf( log, "# pblSetUnion( testSet, empty )\n" );

            result = pblSetUnion( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( Union )\n" );
            fprintf( log, "# pblSetPrint( Union )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );
            pblSetFree( result );

            printf( "# pblSetRemoveFirst( clone )\n" );
            fprintf( log, "# pblSetRemoveFirst( clone )\n" );

            ptr = pblSetRemoveFirst( clone );

            printf( "# result %s\n", ptr ? ptr :"NULL" );
            fprintf( log, "# result %s\n", ptr ? ptr :"NULL" );

            printf( "# pblSetRemoveLast( clone )\n" );
            fprintf( log, "# pblSetRemoveLast( clone )\n" );

            ptr = pblSetRemoveLast( clone );

            printf( "# result %s\n", ptr ? ptr :"NULL" );
            fprintf( log, "# result %s\n", ptr ? ptr :"NULL" );

            printf( "# pblSetAdd( %d, NotFound )\n", 1 );
            fprintf( log, "# pblSetAdd( %d, NotFound )\n", 1 );

            rc = pblSetAdd(clone, "NotFound" );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n", rc, pbl_errno );
                break;
            }

            printf( "\n# pblSetUnion( testSet, clone )\n" );
            fprintf( log, "# pblSetUnion( testSet, clone )\n" );

            result = pblSetUnion( testCollection, clone );
            if( !result )
            {
                printf( "# result NULL, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# result NULL, pbl_errno %d\n", pbl_errno );
                break;
            }

            printf( "# pblSetPrint( Union )\n" );
            fprintf( log, "# pblSetPrint( Union )\n" );

            pblSetPrint( stdout, result );
            pblSetPrint( log, result );

            pblSetFree( result );
            pblSetFree( clone );
        }

        else if( !strcmp( command, "iterate" ))
        {
            PblIterator  * iterator;

            i = 0;

            if( !testCollection )
                continue;

            printf( "# iterate maxIndex\n" );
            fprintf( log, "# iterate maxIndex\n" );
            getWord( buffer );
            ival = atoi( buffer );

            printf( "# pblIteratorNew( %d )\n",
                    ival );

            fprintf( log, "# pblIteratorNew( %d )\n",
                    ival );

            iterator = pblIteratorNew( (PblCollection*)testCollection );

            if( iterator == NULL )
            {
                printf( "# NULL, pbl_errno %d\n",
                        pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n",
                        pbl_errno );
                break;
            }

            printf( "# OK\n" );
            fprintf( log, "# OK\n" );


            while( ival-- > 0 && pblIteratorHasNext( iterator ))
            {
                char * item =  ( char *) pblIteratorNext( iterator );
                if( item == (void*)-1 )
                {
                    printf( "# FAILED i %d, pbl_errno %d\n", i, pbl_errno );
                    fprintf( log, "# FAILED i %d, pbl_errno %d\n",
                             i, pbl_errno );
                    break;
                }

                printf( "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
                fprintf( log, "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
                i++;
            }

            pblIteratorFree( iterator );
            printf( "# Iteration DONE\n" );
            fprintf( log, "# Iteration DONE\n" );

        }

        else if( !strcmp( command, "reverseIterate" ))
        {
            PblIterator  * iterator;

            i = 0;

            if( !testCollection )
                continue;

            printf( "# reverseIterate maxIndex\n" );
            fprintf( log, "# reverseIterate maxIndex\n" );
            getWord( buffer );
            ival = atoi( buffer );

            printf( "# pblSetReverseIterator( %d )\n",
                    ival );

            fprintf( log, "# pblSetReverseIterator( %d )\n",
                    ival );

            iterator = pblSetReverseIterator( (PblCollection*)testCollection );

            if( iterator == NULL )
            {
                printf( "# NULL, pbl_errno %d\n",
                        pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n",
                        pbl_errno );
                break;
            }

            printf( "# OK\n" );
            fprintf( log, "# OK\n" );


            while( ival-- > 0 && pblIteratorHasPrevious( iterator ))
            {
                char * item =  ( char *) pblIteratorPrevious( iterator );
                if( item == (void*)-1 )
                {
                    printf( "# FAILED i %d, pbl_errno %d\n", i, pbl_errno );
                    fprintf( log, "# FAILED i %d, pbl_errno %d\n",
                             i, pbl_errno );
                    break;
                }

                printf( "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
                fprintf( log, "# OK i %d, %s\n", i, item != NULL ? item : "NULL" );
                i++;
            }

            pblIteratorFree( iterator );
            printf( "# Iteration DONE\n" );
            fprintf( log, "# Iteration DONE\n" );

        }

        else if( !strcmp( command, "iterator" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblSetIterator( 1 )\n" );
            fprintf( log, "# pblSetIterator( 1 )\n" );

            testIterator = pblSetIterator( (PblCollection*)testCollection );
            if( testIterator == NULL )
            {
                printf( "# NULL, pbl_errno %d\n",
                        pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n",
                        pbl_errno );
                break;
            }

            printf( "# OK\n" );
            fprintf( log, "# OK\n" );
        }

        else if( !strcmp( command, "reverseIterator" ))
        {
            if( !testCollection )
                continue;

            printf( "# pblIteratorReverseNew( 1 )\n" );
            fprintf( log, "# pblIteratorReverseNew( 1 )\n" );

            testIterator = pblIteratorReverseNew( (PblCollection*)testCollection );
            if( testIterator == NULL )
            {
                printf( "# NULL, pbl_errno %d\n",
                        pbl_errno );
                fprintf( log, "# NULL, pbl_errno %d\n",
                        pbl_errno );
                break;
            }

            printf( "# OK\n" );
            fprintf( log, "# OK\n" );
        }

        else if( !strcmp( command, "iteratorAdd" ))
        {
            if( !testIterator )
                continue;

            printf( "# iteratorAdd itemIndex\n" );
            fprintf( log, "# iteratorAdd itemIndex\n" );

            getWord( buffer );
            ival = atoi( buffer );
            if( ival < 0)
            {
                ptr = NULL;
            }
            else
            {
                ptr = items[ ival ];
            }

            printf( "# pblIteratorAdd( %s )\n",
                    ptr ? ptr : "NULL" );

            fprintf( log, "# pblIteratorAdd( %s )\n",
                     ptr ? ptr : "NULL" );

            rc = pblIteratorAdd( testIterator, ptr );

            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                continue;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "iteratorFree" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorFree( )\n" );
            fprintf( log, "# pblIteratorFree()\n" );

            pblIteratorFree( testIterator );
            testIterator = NULL;

            printf( "# OK\n" );
            fprintf( log, "# OK\n" );
        }

        else if( !strcmp( command, "hasNext" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorHasNext( )\n" );
            fprintf( log, "# pblIteratorHasNext()\n" );

            rc = pblIteratorHasNext( testIterator );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                continue;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "hasPrevious" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorHasPrevious( )\n" );
            fprintf( log, "# pblIteratorHasPrevious()\n" );

            rc = pblIteratorHasPrevious( testIterator );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                continue;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "next" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorNext( )\n" );
            fprintf( log, "# pblIteratorNext()\n" );

            ptr = pblIteratorNext( testIterator );
            if( ptr == (char *)-1 )
            {
                printf( "# NO NEXT, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NO NEXT, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# next %s", ptr ? ptr : "NULL" );
                fprintf( log, "# next %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "nextIndex" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorNextIndex( )\n" );
            fprintf( log, "# pblIteratorNextIndex()\n" );

            rc = pblIteratorNextIndex( testIterator );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                continue;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "previous" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorPrevious( )\n" );
            fprintf( log, "# pblIteratorPrevious()\n" );

            ptr = pblIteratorPrevious( testIterator );
            if( ptr == (char *)-1 )
            {
                printf( "# NO PREVIOUS, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# NO PREVIOUS, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# previous %s", ptr ? ptr : "NULL" );
                fprintf( log, "# previous %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "previousIndex" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorPreviousIndex( )\n" );
            fprintf( log, "# pblIteratorPreviousIndex()\n" );

            rc = pblIteratorPreviousIndex( testIterator );

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "iteratorRemove" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorRemove( )\n" );
            fprintf( log, "# pblIteratorRemove()\n" );

            rc = pblIteratorRemove( testIterator );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                continue;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else if( !strcmp( command, "iteratorSet" ))
        {
            if( !testIterator )
                continue;

            printf( "# iteratorSet itemIndex\n" );
            fprintf( log, "# iteratorSet itemIndex\n" );

            getWord( buffer );
            ival = atoi( buffer );
            if( ival < 0)
            {
                ptr = NULL;
            }
            else
            {
                ptr = items[ ival ];
            }

            printf( "# pblIteratorSet( %s )\n",
                    ptr ? ptr : "NULL" );

            fprintf( log, "# pblIteratorSet( %s )\n",
                     ptr ? ptr : "NULL" );

            ptr = pblIteratorSet( testIterator, ptr );
            if( ptr == (char *)-1 )
            {
                printf( "# SET FAILED, pbl_errno %d\n", pbl_errno );
                fprintf( log, "# SET FAILED, pbl_errno %d\n", pbl_errno );
            }
            else
            {
                printf( "# set returned %s", ptr ? ptr : "NULL" );
                fprintf( log, "# set returned %s\n", ptr ? ptr : "NULL" );
            }
        }

        else if( !strcmp( command, "iteratorSize" ))
        {
            if( !testIterator )
                continue;

            printf( "# pblIteratorSize( )\n" );
            fprintf( log, "# pblIteratorSize()\n" );

            rc = pblIteratorSize( testIterator );
            if( rc < 0 )
            {
                printf( "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                fprintf( log, "# rc %ld, pbl_errno %d\n",
                        rc, pbl_errno );
                continue;
            }

            printf( "# rc %ld\n", rc );
            fprintf( log, "# rc %ld\n", rc );
        }

        else
        {
            printf( "# q       FOR QUIT\n" );
        }
    }

    return( 0 );
}

/*
 * Eclipse CDT does not like more than one main,
 * therefore hide all but one main with this -D option
 */
#ifdef _WIN32
#define ALTST_SHOW_MAIN
#endif

#ifndef CDT_BUILD
#define ALTST_SHOW_MAIN
#endif

#ifdef PBLTEST
#undef ALTST_SHOW_MAIN
#define ALTST_SHOW_MAIN 1
#endif

/* #define ALTST_SHOW_MAIN */
#ifdef ALTST_SHOW_MAIN

int main( int argc, char * argv[] )
{
    return( pblSet_TestFrame( argc, argv ));
}

#endif /* CDT_BUILD */
