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
 Revision 1.15  2018/03/10 18:00:45  peter
 Cleanup of unneeded parentheses

 Revision 1.14  2016/09/19 14:54:07  peter
 Working on cgi handling

 Revision 1.13  2016/06/03 21:13:30  peter
 Syncing with GIT version.

 Revision 1.12  2015/02/22 07:06:07  peter
 Port to Visual Studio 2012.

 Revision 1.11  2010/11/01 11:56:12  peter
 Updated the priority queue documentation.


 */

/*
 * Make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char* pblPriorityQueueTest_c_id =
        "$Id: pblPriorityQueueTest.c,v 1.15 2018/03/10 18:00:45 peter Exp $";

#include <stdio.h>
#include <memory.h>

#ifndef __APPLE__
#include <malloc.h>
#endif

#include "pbl.h" /* The pbl include file */

/*
 * Test frame for the priorityQueue library
 *
 * This test frame calls the priorityQueue library,
 * it does not have any parameters, it is meant for
 * showing how to use the library and for debugging the
 * priorityQueue library.
 */
int pblPriorityQueue_TestFrame( void )
{
    int i;
    int rc;
    char * data;

    /*
     * The priority queue to be used below.
     */
    PblPriorityQueue * priorityQueue;

    /*
     * Create a new priority queue.
     */
    priorityQueue = pblPriorityQueueNew();
    fprintf( stdout, "pblPriorityQueueNew() priorityQueue = %s\n",
             priorityQueue ? "retptr" : "NULL" );
    if( priorityQueue == NULL)
    {
        return -1;
    }

    /*
     * Test if queue is empty.
     */
    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    /*
     * Insert the string "1" with a priority value of 1.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 1, "1" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 1, 1 ) rc = %d\n",
             rc );

    /*
     * Insert the string "2" with a priority value of 2.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 2, "2" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 2, 2 ) rc = %d\n",
             rc );

    /*
     * Insert the string "3" with a priority value of 3.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 3, "3" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 3, 3 ) rc = %d\n",
             rc );

    /*
     * Insert the string "4" with a priority value of 4.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 4, "4" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 4, 4 ) rc = %d\n",
             rc );

    /*
     * Insert the string "5" with a priority value of 5.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 5, "5" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 5, 5 ) rc = %d\n",
             rc );

    /*
     * Retrieve the size of the queue, should be 5.
     */
    rc = pblPriorityQueueSize( priorityQueue );
    fprintf( stdout, "pblPriorityQueueSize( priorityQueue ) rc = %d\n", rc );

    /*
     * Test if queue is empty.
     */
    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    /*
     * Retrieve the value with the highest priority, should be "5" with priority 5.
     */
    data = (char*)pblPriorityQueueGetFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueGetFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    /*
     * Remove the value with the highest priority, should be "5" with priority 5.
     */
    data = (char*)pblPriorityQueueRemoveFirst( priorityQueue, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveFirst( priorityQueue, &prio ) rc = %d, data = %s\n",
             rc, data );

    /*
     * Retrive and remove the entries one after another.
     */
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

    /*
     * Test if the queue is empty, should be true now!
     */
    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    /*
     * Insert the string "1" with a priority value of 1.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 1, "1" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 1, 1 ) rc = %d\n",
             rc );

    /*
     * Insert the string "21" with a priority value of 2.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 2, "21" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 21 ) rc = %d\n", rc );

    /*
     * Insert the string "22" with a priority value of 2, note this is a case of two entries having the same priority.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 2, "22" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 22 ) rc = %d\n", rc );

    /*
     * Insert the string "23" with a priority value of 2, note this is a case of more than two entries having the same priority.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 2, "23" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 23 ) rc = %d\n", rc );

    /*
     * Insert the string "24" with a priority value of 2, note this is a case of more than two entries having the same priority.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 2, "24" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 24 ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 2, "25" );
    fprintf( stdout,
             "pblPriorityQueueInsert( priorityQueue, 2, 25 ) rc = %d\n", rc );

    rc = pblPriorityQueueInsert( priorityQueue, 3, "3" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 3, 3 ) rc = %d\n",
             rc );

    /*
     * Retrieve the current capacity of the queue, i.e. the capacity of the underlying array list.
     */
    rc = pblPriorityQueueGetCapacity( priorityQueue );
    fprintf( stdout, "pblPriorityQueueGetCapacity( priorityQueue ) rc = %d\n",
             rc );

    /*
     * Trim the queue to its current size.
     */
    rc = pblPriorityQueueTrimToSize( priorityQueue );
    fprintf( stdout, "pblPriorityQueueTrimToSize( priorityQueue ) rc = %d\n",
             rc );

    /*
     * Retrieve the current capacity of the queue, i.e. the capacity of the underlying array list.
     */
    rc = pblPriorityQueueGetCapacity( priorityQueue );
    fprintf( stdout, "pblPriorityQueueGetCapacity( priorityQueue ) rc = %d\n",
             rc );

    /*
     * Retrieve and then remove the entries one after another
     */
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

    /*
     * Test if queue is empty, should return false!
     */
    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    /*
     * Clear the queue.
     */
    pblPriorityQueueClear( priorityQueue );
    fprintf( stdout, "pblPriorityQueueClear( priorityQueue ) \n" );

    /*
     * Test if queue is empty, should return true!
     */
    rc = pblPriorityQueueIsEmpty( priorityQueue );
    fprintf( stdout, "pblPriorityQueueIsEmpty( priorityQueue ) rc = %d\n", rc );

    /*
     * Make room for at least 9 entries. First step of construction a priority queue with O(N) steps!
     */
    rc = pblPriorityQueueEnsureCapacity( priorityQueue, 9 );
    fprintf( stdout,
             "pblPriorityQueueEnsureCapacity( priorityQueue, 9 ) rc = %d\n", rc );

    /*
     * Add a total of 9 entries WITHOUT ensuring the heap condition.
     */
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

    /*
     * Construct the priority queue with 9 elements.
     */
    pblPriorityQueueConstruct( priorityQueue );
    fprintf( stdout, "pblPriorityQueueConstruct( priorityQueue ) \n" );

    /*
     * Give out the entire queue, shows that the queue now fulfills the heap condition.
     */
    for( i = 0; i < pblPriorityQueueSize( priorityQueue ); i++ )
    {
        data = (char*)pblPriorityQueueGet( priorityQueue, i, &rc );
        fprintf(
                 stdout,
                 "pblPriorityQueueGet( priorityQueue, %d ), priority = %d, data = %s\n",
                 i, rc, data );
    }

    /*
     * Remove a specific element from the queue, ensure the heap condition.
     */
    data = (char*)pblPriorityQueueRemoveAt( priorityQueue, 3, &rc );
    fprintf(
             stdout,
             "pblPriorityQueueRemoveAt( priorityQueue, 3, &prio ) rc = %d, data = %s\n",
             rc, data );

    /*
     * Give out the entire queue.
     */
    for( i = 0; i < pblPriorityQueueSize( priorityQueue ); i++ )
    {
        data = (char*)pblPriorityQueueGet( priorityQueue, i, &rc );
        fprintf(
                 stdout,
                 "pblPriorityQueueGet( priorityQueue, %d ), priority = %d, data = %s\n",
                 i, rc, data );
    }

    /*
     * Insert a specific element.
     */
    rc = pblPriorityQueueInsert( priorityQueue, 4, "44" );
    fprintf( stdout, "pblPriorityQueueInsert( priorityQueue, 4, 4 ) rc = %d\n",
             rc );

    /*
     * Give out the entire queue.
     */
    for( i = 0; i < pblPriorityQueueSize( priorityQueue ); i++ )
    {
        data = (char*)pblPriorityQueueGet( priorityQueue, i, &rc );
        fprintf(
                 stdout,
                 "pblPriorityQueueGet( priorityQueue, %d ), priority = %d, data = %s\n",
                 i, rc, data );
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

    /*
     * Change the priority of the first entry.
     */
    rc = pblPriorityQueueChangePriorityFirst( priorityQueue, -1 );
    fprintf(
             stdout,
             "pblPriorityQueueChangePriorityFirst( priorityQueue, -1 ) rc = %d\n",
             rc );

    /*
     * Change the priority of the element back to its original value.
     */
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
        /*
         * Create an 'other' queue for testing the join of two queues.
         */
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

        /*
         * Join all entries from 'other' to the main queue.
         */
        rc = pblPriorityQueueJoin( priorityQueue, other );
        fprintf( stdout,
                 "pblPriorityQueueJoin( priorityQueue, other ) rc = %d\n", rc );

        /*
         * Test of 'other' is empty after the join.
         */
        rc = pblPriorityQueueIsEmpty( other );
        fprintf( stdout, "pblPriorityQueueIsEmpty( other ) rc = %d\n", rc );

        /*
         * Free all memory of the other queue, delete the other queue!
         */
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

    /*
     * Free all memory of the queue, delete the queue!
     */
    pblPriorityQueueFree( priorityQueue );
    fprintf( stdout, "pblPriorityQueueFree( priorityQueue ) \n" );

    return 0;
}

/*
 * Eclipse CDT does not like more than one main() function,
 * therefore we hide all but one main with this -D option
 */

#ifdef CDT_BUILD
#undef PQ_TST_SHOW_MAIN
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
        return pblPriorityQueue_TestFrame();
    }
    return pblPriorityQueue_TestFrame();
}

#endif

