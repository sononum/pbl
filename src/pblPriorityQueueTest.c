/*
 pblPriorityQueueTest.c - priorityQueue test frame

 Copyright (C) 2010   Peter Graf

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

 $Log: pblPriorityQueueTest.c,v $
 Revision 1.10  2010/10/01 20:44:31  peter
 Port to 64 bit windows

 Revision 1.9  2010/08/29 15:29:31  peter
 Added the heap functions.

 Revision 1.8  2010/08/20 20:10:26  peter
 Implemented the priority queue functions.


 */

/*
 * make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char* pblPriorityQueueTest_c_id =
        "$Id: pblPriorityQueueTest.c,v 1.10 2010/10/01 20:44:31 peter Exp $";

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
 * test frame for the priorityQueue library
 *
 * this test frame calls the priorityQueue library,
 * it does not have any parameters, it is meant for
 * debugging the priorityQueue library
 */
int pblPriorityQueue_TestFrame( void )
{
    PblPriorityQueue * priorityQueue;
    int rc;

    char * data;

    priorityQueue = pblPriorityQueueNew();
    fprintf( stdout, "pblPriorityQueueNew() priorityQueue = %s\n",
             priorityQueue ? "retptr" : "null" );

    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 1, "1" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 1, 1 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueInsert( priorityQueue, 2, "2" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 2, 2 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueInsert( priorityQueue, 3, "3" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 3, 3 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueInsert( priorityQueue, 4, "4" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 4, 4 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueInsert( priorityQueue, 5, "5" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 5, 5 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueSize( priorityQueue );
    fprintf( stdout, "pblPriorityQueueSize( priorityQueue ) rc = %d\n", rc );

    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 1, "1" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 1, 1 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueInsert( priorityQueue, 2, "21" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 21 ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 2, "22" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 22 ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 2, "23" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 23 ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 2, "24" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 24 ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 2, "25" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 25 ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 3, "3" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 3, 3 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueGetCapacity( priorityQueue );
    fprintf( stdout, "pblPriorityQueueGetCapacity( priorityQueue ) rc = %d\n",
             rc );

    rc = pblPriorityQueueTrimToSize( priorityQueue );
    fprintf( stdout, "pblPriorityQueueTrimToSize( priorityQueue ) rc = %d\n",
             rc );

    rc = pblPriorityQueueGetCapacity( priorityQueue );
    fprintf( stdout, "pblPriorityQueueGetCapacity( priorityQueue ) rc = %d\n",
             rc );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    pblPriorityQueueClear( priorityQueue );
    fprintf( stdout, "pblPriorityQueueClear( priorityQueue ) \n" );

    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    rc = pblPriorityQueueEnsureCapacity( priorityQueue, 9 );
    fprintf( stdout,
             "pblPriorityQueueEnsureCapacity( priorityQueue, 9 ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 1, "1" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 1, 1 ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 2, "2" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 2, 2 ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 3, "3" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 3, 3 ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 4, "4" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 4, 4 ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 5, "5a" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 5, 5a ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 5, "5b" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 5, 5b ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 6, "6" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 6, 6 ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 7, "7" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 7, 7 ) rc = %d\n", rc );

    rc = pblPriorityQueueAddLast( priorityQueue, 8, "8" );
    fprintf( stdout,
             "pblPriorityQueueAddLast( priorityQueue, 8, 8 ) rc = %d\n", rc );

    pblPriorityQueueConstruct( priorityQueue );
    fprintf( stdout, "pblPriorityQueueConstruct( priorityQueue ) \n" );

    for( rc = 0; rc < pblPriorityQueueSize( priorityQueue ); rc++ )
    {
        int priority;
        data = (char*)pblPriorityQueueGet( priorityQueue, rc, &priority );
        fprintf(
                 stdout,
                 "pblPriorityQueueGet( priorityQueue, %d ), priority = %d, data = %s\n",
                 rc, priority, data );
    }

    data = (char*)pblPriorityQueueRemoveAt( priorityQueue, 3, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveAt( priorityQueue, 3, &prio ) rc = %d, data = %s\n",
             rc, data );

    for( rc = 0; rc < pblPriorityQueueSize( priorityQueue ); rc++ )
    {
        int priority;
        data = (char*)pblPriorityQueueGet( priorityQueue, rc, &priority );
        fprintf(
                 stdout,
                 "pblPriorityQueueGet( priorityQueue, %d ), priority = %d, data = %s\n",
                 rc, priority, data );
    }

    rc = pblPriorityQueueInsert( priorityQueue, 4, "4" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 4, 4 ) rc = %d\n",
             rc );

    for( rc = 0; rc < pblPriorityQueueSize( priorityQueue ); rc++ )
    {
        int priority;
        data = (char*)pblPriorityQueueGet( priorityQueue, rc, &priority );
        fprintf(
                 stdout,
                 "pblPriorityQueueGet( priorityQueue, %d ), priority = %d, data = %s\n",
                 rc, priority, data );
    }

    rc = pblPriorityQueueSize( priorityQueue );
    fprintf( stdout, "pblPriorityQueueSize( priorityQueue ) rc = %d\n", rc );

    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    rc = pblPriorityQueueChangePriorityFirst( priorityQueue, -1 );
    fprintf(
             stdout,
             "pblPriorityQueueChangePriorityFirst( priorityQueue, -1 ) rc = %d\n",
             rc );

    rc = pblPriorityQueueChangePriorityAt( priorityQueue, rc, 8 );
    fprintf(
             stdout,
             "pblPriorityQueueChangePriorityAt( priorityQueue, 4, 8 ) rc = %d\n",
             rc );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf( 
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    if( rc == 1 )
    {
        PblPriorityQueue * other = pblPriorityQueueNew();

        rc = pblPriorityQueueInsert( other, 1, "1" );
        fprintf( stdout, "pblPriorityQueueInsert( other, 1, 1 ) rc = %d\n", rc );

        rc = pblPriorityQueueInsert( other, 2, "2" );
        fprintf( stdout, "pblPriorityQueueInsert( other, 2, 2 ) rc = %d\n", rc );

        rc = pblPriorityQueueInsert( other, 3, "3" );
        fprintf( stdout, "pblPriorityQueueInsert( other, 3, 3 ) rc = %d\n", rc );

        rc = pblPriorityQueueInsert( other, 4, "4" );
        fprintf( stdout, "pblPriorityQueueInsert( other, 4, 4 ) rc = %d\n", rc );

        rc = pblPriorityQueueInsert( other, 5, "5" );
        fprintf( stdout, "pblPriorityQueueInsert( other, 5, 5 ) rc = %d\n", rc );

        rc = pblPriorityQueueJoin( priorityQueue, other );
        fprintf( stdout,
                 "pblPriorityQueueJoin( priorityQueue, other ) rc = %d\n", rc );

        rc = pblPriorityQueueIsEmpty( other );
        fprintf( stdout, "pblPriorityQueueIsEmpty( other ) rc = %d\n", rc );

        pblPriorityQueueFree( other );
        fprintf( stdout, "pblPriorityQueueFree( other ) \n" );

        data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
        fprintf(
                 stdout,
                 "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
                 rc, data );

        data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
        fprintf(
                 stdout,
                 "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
                 rc, data );

        pblPriorityQueueClear( priorityQueue );
        fprintf( stdout, "pblPriorityQueueClear( priorityQueue ) \n" );

        rc = pblPriorityQueueIsEmpty( priorityQueue );
        fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n",
                 rc );
    }
    pblPriorityQueueFree( priorityQueue );
    fprintf( stdout, "pblPriorityQueueFree( priorityQueue ) \n" );

    return ( rc );
}

/*
 * Eclipse CDT does not like more than one main,
 * therefore hide all but one main with this -D option
 */

#ifdef CDT_BUILD
#define PQ_TST_SHOW_MAIN
#endif

#ifdef _WIN32
#define PQ_TST_SHOW_MAIN
#endif

#ifdef PBLTEST
#define PQ_TST_SHOW_MAIN
#endif

#ifdef PQ_TST_SHOW_MAIN

int main( int argc, char * argv[ ] )
{
    if( argc && argv )
    {
        return ( pblPriorityQueue_TestFrame() );
    }
    return ( pblPriorityQueue_TestFrame() );
}

#endif /* CDT_BUILD */

