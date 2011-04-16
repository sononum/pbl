/*
 pblhttst.c - hash table test frame

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

    $Log: pblhttst.c,v $
    Revision 1.10  2009/11/26 18:18:43  peter
    New Eclispse cpp version.

    Revision 1.9  2009/10/20 21:08:00  peter
    Added the pblHtCurrentKey function.

    Revision 1.8  2009/03/08 20:56:50  peter
    port to gcc (Ubuntu 4.3.2-1ubuntu12) 4.3.2.
    Exposing the hash set and tree set interfaces.

    Revision 1.7  2009/02/03 16:40:14  peter
    PBL vesion 1.04, optimizations,
    MAC OS X port, port to Microsoft Visual C++ 2008 Express Edition,
    exposing the array list and the linked list interface


    Revision 1.2  2002/09/12 20:47:01  peter
    added the isam file handling to the library

    Revision 1.1  2002/09/05 13:45:02  peter
    Initial revision

*/

/*
 * make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char* pblhttst_c_id = "$Id: pblhttst.c,v 1.10 2009/11/26 18:18:43 peter Exp $";

#include <stdio.h>
#include <memory.h>

#ifndef __APPLE__
#include <malloc.h>
#endif

#include "pbl.h"

/*****************************************************************************/
/* #defines                                                                  */
/*****************************************************************************/

/*****************************************************************************/
/* typedefs                                                                  */
/*****************************************************************************/

/*****************************************************************************/
/* globals                                                                   */
/*****************************************************************************/

/*****************************************************************************/
/* functions                                                                 */
/*****************************************************************************/

/*
 * test frame for the hash table library
 *
 * this test frame calls the hash table library,
 * it does not have any parameters, it is meant for
 * debugging the hash table library
 */
int pblHASHTABLE_TestFrame( int argc, char * argv[ ] )
{
    pblHashTable_t * ht;
    int    rc;
    size_t size;

    char * data;

    ht = pblHtCreate();
    fprintf( stdout, "pblHtCreate() ht = %p\n", ht );

    rc = pblHtInsert( ht, "123", 4, "123" );
    fprintf( stdout, "pblHtInsert( ht, 123, 4, 123 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "124", 4, "124" );
    fprintf( stdout, "pblHtInsert( ht, 124, 4, 124 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "125", 4, "125" );
    fprintf( stdout, "pblHtInsert( ht, 125, 4, 125 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "123", 4, "123" );
    fprintf( stdout, "pblHtInsert( ht, 123, 4, 123 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "123", 3, "123" );
    fprintf( stdout, "pblHtInsert( ht, 123, 3, 123 ) rc = %d\n", rc );

    data = pblHtLookup( ht, "123", 4 );
    fprintf( stdout, "pblHtLookup( ht, 123, 4 ) data = %s\n",
             data ? data : "NULL" );

    data = pblHtLookup( ht, "123", 3 );
    fprintf( stdout, "pblHtLookup( ht, 123, 3 ) data = %s\n",
             data ? data : "NULL" );

    data = pblHtLookup( ht, "124", 4 );
    fprintf( stdout, "pblHtLookup( ht, 124, 4 ) data = %s\n",
             data ? data : "NULL" );

    data = pblHtLookup( ht, "125", 4 );
    fprintf( stdout, "pblHtLookup( ht, 125, 4 ) data = %s\n",
             data ? data : "NULL" );

    data = pblHtLookup( ht, "126", 4 );
    fprintf( stdout, "pblHtLookup( ht, 126, 4 ) data = %s\n",
             data ? data : "NULL" );


    for( data = pblHtFirst( ht ); data; data = pblHtNext( ht ))
    {
        data = pblHtCurrent( ht );
        fprintf( stdout, "pblHtCurrent( ht ) data = %s\n",
                 data ? data : "NULL" );
        size = 0;
        data = pblHtCurrentKey( ht, &size );
        fprintf( stdout, "pblHtCurrentKey( ht, &size ) data = %s, size %ld\n",
                 data ? data : "NULL", size );

    }

    rc = pblHtRemove( ht, "125", 4 );
    fprintf( stdout, "pblHtRemove( ht, 125, 4 ) rc = %d\n", rc );

    data = pblHtFirst( ht );
    fprintf( stdout, "pblHtFirst( ht ) data = %s\n", data ? data : "NULL" );

    rc = pblHtDelete( ht );
    fprintf( stdout, "pblHtDelete( ht, 125, 4 ) rc = %d\n", rc );

    while( !pblHtRemove( ht, 0, 0 ));

    rc = pblHtInsert( ht, "123", 4, "123" );
    fprintf( stdout, "pblHtInsert( ht, 123, 4, 123 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "124", 4, "124" );
    fprintf( stdout, "pblHtInsert( ht, 124, 4, 124 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "125", 4, "125" );
    fprintf( stdout, "pblHtInsert( ht, 125, 4, 125 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "123", 4, "123" );
    fprintf( stdout, "pblHtInsert( ht, 123, 4, 123 ) rc = %d\n", rc );

    rc = pblHtInsert( ht, "123", 3, "123" );
    fprintf( stdout, "pblHtInsert( ht, 123, 3, 123 ) rc = %d\n", rc );


    for( data = pblHtFirst( ht ); data; data = pblHtNext( ht ))
    {
        pblHtRemove( ht, 0, 0 );
    }

    rc = pblHtDelete( ht );
    fprintf( stdout, "pblHtDelete( ht ) rc = %d\n", rc );

    return( rc );
}

/*
 * Eclipse CDT does not like more than one main,
 * therefore hide all but one main with this -D option
 */

#ifndef CDT_BUILD


int main( int argc, char * argv[] )
{
    return( pblHASHTABLE_TestFrame( argc, argv ));
}

#endif /* CDT_BUILD */

