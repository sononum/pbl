/*
 pbltest.c - test functions

 Copyright (C) 2002 - 2007   Peter Graf

   This file is part of PBL - The Program Base Library.
   PBL is free software.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   For more information on the Program Base Library or Peter Graf,
   please see: http://www.mission-base.com/.


    $Log: pbltest.c,v $
    Revision 1.7  2009/03/08 20:56:50  peter
    port to gcc (Ubuntu 4.3.2-1ubuntu12) 4.3.2.
    Exposing the hash set and tree set interfaces.


    Revision 1.4  2008/11/01 23:46:31  peter
    Guarded #include <malloc.h> during mal port

    Revision 1.3  2008/11/01 23:39:30  peter
    re-checkin during mac port

    Revision 1.2  2002/09/12 20:47:08  peter
    added the isam file handling to the library

    Revision 1.1  2002/09/05 13:45:03  peter
    Initial revision


*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 * make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char* pbltest_c_id = "$Id: pbltest.c,v 1.7 2009/03/08 20:56:50 peter Exp $";

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
 * Eclipse CDT does not like more than one main,
 * therefore hide all but one main with this -D option
 */
#ifndef CDT_BUILD

int main( int argc, char * argv[ ] )
{
    void * ht;
    int    rc;

    char * data;

    ht = pblHtCreate();

    rc = pblHtInsert( ht, "123", 4, "123" );
    rc = pblHtInsert( ht, "124", 4, "124" );
    rc = pblHtInsert( ht, "125", 4, "125" );
    rc = pblHtInsert( ht, "123", 4, "123" );
    rc = pblHtInsert( ht, "123", 3, "123" );

    data = pblHtLookup( ht, "123", 4 );
    data = pblHtLookup( ht, "123", 3 );
    data = pblHtLookup( ht, "124", 4 );
    data = pblHtLookup( ht, "125", 4 );
    data = pblHtLookup( ht, "126", 4 );

    for( data = pblHtFirst( ht ); data; data = pblHtNext( ht ))
    {
        data = pblHtCurrent( ht );
    }

    rc = pblHtRemove( ht, "125", 4 );

    data = pblHtFirst( ht );

    rc = pblHtDelete( ht );

    while( !pblHtRemove( ht, 0, 0 ));

    rc = pblHtInsert( ht, "123", 4, "123" );
    rc = pblHtInsert( ht, "124", 4, "124" );
    rc = pblHtInsert( ht, "125", 4, "125" );
    rc = pblHtInsert( ht, "123", 4, "123" );
    rc = pblHtInsert( ht, "123", 3, "123" );

    for( data = pblHtFirst( ht ); data; data = pblHtNext( ht ))
    {
        pblHtRemove( ht, 0, 0 );
    }

    rc = pblHtDelete( ht );

    return( rc );
}

#endif /* CDT_BUILD */


