/*
 pblPerform.c - Performance test program.

 Copyright (C) 2009   Peter Graf

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

 $Log: pblPerform.c,v $
 Revision 1.9  2009/11/26 18:24:30  peter
 Made sure build works

 Revision 1.8  2009/09/03 20:48:59  peter
 Just some cleanup on sets.

 Revision 1.7  2009/03/27 23:56:23  peter
 Some cleanup

 Revision 1.6  2009/03/11 23:48:44  peter
 More tests and clean up.

 Revision 1.5  2009/03/11 22:03:22  peter
 More performance tests.

 Revision 1.4  2009/03/08 20:56:50  peter
 port to gcc (Ubuntu 4.3.2-1ubuntu12) 4.3.2.
 Exposing the hash set and tree set interfaces.


 Revision 1.1  2009/02/26 23:53:23  peter
 Performance tests


 */

/*
 * Make sure "strings <exe> | grep Id | sort -u" shows the source file versions
 */
char* pblPerform_c_id =
        "$Id: pblPerform.c,v 1.9 2009/11/26 18:24:30 peter Exp $";

#include <stdio.h>
#include <memory.h>
#include <sys/time.h>

#ifndef __APPLE__
#include <malloc.h>
#endif

#include <stdlib.h>

#include "pbl.h"

/*****************************************************************************/
/* #defines                                                                  */
/*****************************************************************************/

#define NumberOfPblTestKeys  2500000

#define START_TIMER  gettimeofday( &start, NULL );
#define END_TIMER( tag )\
{\
gettimeofday( &end, NULL );\
\
if( end.tv_usec < start.tv_usec )\
{\
    end.tv_usec += 1000000 - start.tv_usec;\
    start.tv_sec++;\
}\
\
printf( "%s took %ld.%.6ld\n", tag, (long)end.tv_sec - start.tv_sec, (long)end.tv_usec );\
}\

/*****************************************************************************/
/* Typedefs                                                                  */
/*****************************************************************************/

/*****************************************************************************/
/* Globals                                                                   */
/*****************************************************************************/
static char ** pblTestKeys;

static struct timeval start;
static struct timeval end;

static PblSet * hashSet;
static PblSet * treeSet;
static PblList * linkedList;
static PblList * arrayList;

/*****************************************************************************/
/* Function declarations                                                     */
/*****************************************************************************/

/*****************************************************************************/
/* Functions                                                                 */
/*****************************************************************************/

#ifdef _NOT_
/*
 * Test ++i versus i++
 */
int pblTestIpp()
{
    unsigned int i = 0;


    int a = 1;
    int b = 0;

    START_TIMER;

    for( i = 0; i < 0xffffffff; i++ )
    {
        int tmp = a;
        a = b;
        b = tmp;
    }


    END_TIMER("pblTestIpp");
    return 1;
}

#endif

/*
 * Prepare the data for the insert and lookup tests
 */
int pblTestPrepare()
{
    int i = 0;
    int index = 0;
    int high = 0;
    int low = 0;
    char buffer[ 256 ];
    char * ptr;
    char ** keys;

    START_TIMER;

    pblTestKeys = (char**)pbl_malloc( "pblTestPrepare", NumberOfPblTestKeys
            * sizeof(char *) );
    if( !pblTestKeys )
    {
        printf( "Error pbl_malloc %d", pbl_errno );
        exit( 1 );
    }
    keys = pblTestKeys;

    while( index < NumberOfPblTestKeys )
    {
        if( low == 0xffff )
        {
            low = 0;
            high++;
        }

        if( i++ % 40 )
        {
            low++;
            continue;
        }

        sprintf( buffer, "%d", high << 16 | low );
        ptr = pbl_strdup( "pblTestPrepare pbl_strdup", buffer );
        if( !ptr )
        {
            printf( "Error pblTestPrepare %d\n", pbl_errno );
            exit( 1 );
        }

        keys[ index++ ] = ptr;
        low++;
    }

    END_TIMER("pblTestPrepare");
    return 0;
}

int pblIntCompare( const void *left, /** The left element for compare  */
const void *right /** The right element for compare */
)
{
    return **(int**)left - **(int**)right;
}

int pblIntHashValue( const void *element /** Element to calculate hash value for */
)
{
    return pblHtHashValue( (unsigned char *)element, sizeof(int) );
}

int pblStringHashValue( const void *element /** Element to calculate hash value for */
)
{
    return pblHtHashValueOfString( (unsigned char *)element );
}

void addToLinkedList()
{
    int rc;
    int i;

    START_TIMER;

    linkedList = pblListNewLinkedList();
    if( !linkedList )
    {
        printf( "Error pblListNewLinkedList %d\n", pbl_errno );
        exit( 1 );
    }

    if( pblListSetCompareFunction( linkedList, pblCollectionStringCompareFunction ) == (void*)-1 )
    {
        printf( "Error pblListSetCompareFunction %d\n", pbl_errno );
        exit( 1 );
    }

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        char * ptr = pblTestKeys[ i ];
        rc = pblListAdd( linkedList, ptr );
        if( rc <= 0 )
        {
            printf( "Error pblListAdd rc %d, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("addToLinkedList");

    printf( "List size %d\n", pblListSize( linkedList ) );
}

void addToArrayList()
{
    int rc;
    int i;

    START_TIMER;

    arrayList = pblListNewArrayList();
    if( !arrayList )
    {
        printf( "Error pblListNewArrayList %d\n", pbl_errno );
        exit( 1 );
    }

    if( pblListSetCompareFunction( arrayList, pblCollectionStringCompareFunction ) == (void*)-1 )
    {
        printf( "Error pblListSetCompareFunction %d\n", pbl_errno );
        exit( 1 );
    }

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        char * ptr = pblTestKeys[ i ];
        rc = pblListAdd( arrayList, ptr );
        if( rc <= 0 )
        {
            printf( "Error pblListAdd rc %d, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("addToArrayList");

    printf( "List size %d\n", pblListSize( arrayList ) );
}

void addToHashSet()
{
    int rc;
    int i;

    START_TIMER;

    hashSet = pblSetNewHashSet();
    if( !hashSet )
    {
        printf( "Error pblSetNewHashSet %d\n", pbl_errno );
        exit( 1 );
    }
    if( pblSetSetHashValueFunction( hashSet, pblStringHashValue ) == (void*)-1 )
    {
        printf( "Error pblSetSetHashValueFunction %d\n", pbl_errno );
        exit( 1 );
    }

    if( pblSetSetCompareFunction( hashSet, pblCollectionStringCompareFunction ) == (void*)-1 )
    {
        printf( "Error pblSetSetCompareFunction %d\n", pbl_errno );
        exit( 1 );
    }

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        char * ptr = pblTestKeys[ i ];
        rc = pblSetAdd( hashSet, ptr );
        if( rc <= 0 )
        {
            printf( "Error pblSetAdd rc %d, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("addToHashSet");

    printf( "Hash size %d\n", pblSetSize( hashSet ) );
}

void addToTreeSet()
{
    int rc;
    int i;

    START_TIMER;

    treeSet = pblSetNewTreeSet();
    if( !treeSet )
    {
        printf( "Error pblSetNewTreeSet %d\n", pbl_errno );
        exit( 1 );
    }
    if( pblSetSetHashValueFunction( treeSet, pblStringHashValue ) == (void*)-1 )
    {
        printf( "Error pblSetSetHashValueFunction %d\n", pbl_errno );
        exit( 1 );
    }

    if( pblSetSetCompareFunction( treeSet, pblCollectionStringCompareFunction ) == (void*)-1 )
    {
        printf( "Error pblSetSetCompareFunction %d\n", pbl_errno );
        exit( 1 );
    }

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        char * ptr = pblTestKeys[ i ];
        rc = pblSetAdd( treeSet, ptr );
        if( rc <= 0 )
        {
            printf( "Error pblSetAdd rc %d, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("addToTreeSet");

    printf( "Tree size %d\n", pblSetSize( treeSet ) );
}

void lookupArrayList()
{
    int i;
    int sum = 0;
    int loopEnd = NumberOfPblTestKeys / 10000;
    char buffer[ 256 ];

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        sprintf( buffer, "%d", i );

        sum += pblListContains( arrayList, buffer );
    }

    END_TIMER("lookupArrayList");

    printf( "Array list contained %d\n", sum );
}

void lookupLinkedList()
{
    int i;
    int sum = 0;
    int loopEnd = NumberOfPblTestKeys / 10000;
    char buffer[ 256 ];

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        sprintf( buffer, "%d", i );

        sum += pblListContains( linkedList, buffer );
    }

    END_TIMER("lookupLinkedList");

    printf( "Linked list contained %d\n", sum );
}

void lookupTreeSet()
{
    int i;
    int sum = 0;
    int loopEnd = NumberOfPblTestKeys * 10;
    char buffer[ 256 ];

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        sprintf( buffer, "%d", i );

        sum += pblSetContains( treeSet, buffer );
    }

    END_TIMER("lookupTreeSet");

    printf( "Tree contained %d\n", sum );
}

void lookupHashSet()
{
    int i;
    int sum = 0;
    int loopEnd = NumberOfPblTestKeys * 10;
    char buffer[ 256 ];

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        sprintf( buffer, "%d", i );

        sum += pblSetContains( hashSet, buffer );
    }

    END_TIMER("lookupHashSet");

    printf( "Hash contained %d\n", sum );
}

void freeLinkedList()
{
    START_TIMER;
    pblListFree( linkedList );
    END_TIMER("freeLinkedList");
}

void freeArrayList()
{
    START_TIMER;
    pblListFree( arrayList );
    END_TIMER("freeArrayList");
}

void freeHashSet()
{
    START_TIMER;
    pblSetFree( hashSet );
    END_TIMER("freeHashSet");
}

void freeTreeSet()
{
    START_TIMER;
    pblSetFree( treeSet );
    END_TIMER("freeTreeSet");
}

void removeFirstFromLinkedList()
{
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        rc = pblListRemoveFirst( linkedList );
        if( rc == (void*)-1 )
        {
            printf( "Error pblListRemoveFirst rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeFirstFromLinkedList");

    printf( "List size %d\n", pblListSize( linkedList ) );
}

void removeLastFromLinkedList()
{
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        rc = pblListRemoveLast( linkedList );
        if( rc == (void*)-1 )
        {
            printf( "Error pblListRemoveLast rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeLastFromLinkedList");

    printf( "List size %d\n", pblListSize( linkedList ) );
}

void removeFirstFromArrayList()
{
    int loopEnd = NumberOfPblTestKeys / 1000;
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        rc = pblListRemoveFirst( arrayList );
        if( rc == (void*)-1 )
        {
            printf( "Error pblListRemoveFirst rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeFirstFromArrayList");

    printf( "List size %d\n", pblListSize( arrayList ) );
}

void removeLastFromArrayList()
{
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        rc = pblListRemoveLast( arrayList );
        if( rc == (void*)-1 )
        {
            printf( "Error pblListRemoveLast rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeLastFromArrayList");

    printf( "List size %d\n", pblListSize( arrayList ) );
}

void removeFromHashSet()
{
    int i;
    int sum = 0;


    START_TIMER;

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        char * ptr = pblTestKeys[ i ];
        sum += pblSetRemoveElement( hashSet, ptr );
    }

    END_TIMER("removeFromHashSet");

    printf( "Hash contained %d\n", sum );
}

void removeFirstFromHashSet()
{
    int loopEnd = NumberOfPblTestKeys / 1000;
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        rc = pblSetRemoveFirst( hashSet );
        if( rc == (void*)-1 )
        {
            printf( "Error pblSetRemoveFirst rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeFirstFromHashSet");

    printf( "Set size %d\n", pblSetSize( hashSet ) );
}

void removeLastFromHashSet()
{
    int loopEnd = NumberOfPblTestKeys / 1000;
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        rc = pblSetRemoveLast( hashSet );
        if( rc == (void*)-1 )
        {
            printf( "Error pblSetRemoveLast rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeLastFromHashSet");

    printf( "Set size %d\n", pblSetSize( hashSet ) );
}

void removeMiddleFromHashSet()
{
    int loopEnd = NumberOfPblTestKeys / 10000;
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        rc = pblSetRemoveAt( hashSet, pblSetSize( hashSet ) / 2 );
        if( rc == (void*)-1 )
        {
            printf( "Error pblSetRemoveAt rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeMiddleFromHashSet");

    printf( "Set size %d\n", pblSetSize( hashSet ) );
}

void removeFromTreeSet()
{
    int i;
    int sum = 0;


    START_TIMER;

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        char * ptr = pblTestKeys[ i ];
        sum += pblSetRemoveElement( treeSet, ptr );
    }

    END_TIMER("removeFromToTreeSet");

    printf( "Tree contained %d\n", sum );
}

void removeFirstFromTreeSet()
{
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        rc = pblSetRemoveFirst( treeSet );
        if( rc == (void*)-1 )
        {
            printf( "Error pblSetRemoveFirst rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeFirstFromTreeSet");

    printf( "Set size %d\n", pblSetSize( treeSet ) );
}

void removeLastFromTreeSet()
{
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < NumberOfPblTestKeys; i++ )
    {
        rc = pblSetRemoveLast( treeSet );
        if( rc == (void*)-1 )
        {
            printf( "Error pblSetRemoveLast rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeLastFromTreeSet");

    printf( "Set size %d\n", pblSetSize( treeSet ) );
}

void removeMiddleFromTreeSet()
{
    int loopEnd = NumberOfPblTestKeys / 10000;
    void * rc;
    int i;

    START_TIMER;

    for( i = 0; i < loopEnd; i++ )
    {
        rc = pblSetRemoveAt( treeSet, pblSetSize( treeSet ) / 2 );
        if( rc == (void*)-1 )
        {
            printf( "Error pblSetRemoveLast rc %p, %d\n", rc, pbl_errno );
            exit( 1 );
        }
    }

    END_TIMER("removeMiddleFromTreeSet");

    printf( "Set size %d\n", pblSetSize( treeSet ) );
}

/*
 * Eclipse CDT does not like more than one main,
 * therefore hide all but one main with this -D option
 */
#ifndef CDT_BUILD
#define _SHOW_PBL_PERFORM_MAIN 1
#endif

#ifdef PBLTEST
#define _SHOW_PBL_PERFORM_MAIN 1
#endif

#ifdef _SHOW_PBL_PERFORM_MAIN

int main( int argc, char * argv[] )
{
    printf( "pblPerform\n\n" );

#ifdef _NOT_
    if( pblTestIpp())
    {
        return 0;
    }
#endif

    pblTestPrepare();
    printf( "\n" );


    addToLinkedList();
    removeFirstFromLinkedList();
    addToLinkedList();
    removeLastFromLinkedList();
    addToLinkedList();
    lookupLinkedList();
    freeLinkedList();
    printf( "\n" );

    addToArrayList();
    removeFirstFromArrayList();
    addToArrayList();
    removeLastFromArrayList();
    addToArrayList();
    lookupArrayList();
    freeArrayList();
    printf( "\n" );

    addToTreeSet();
    removeFromTreeSet();
    addToTreeSet();
    removeFirstFromTreeSet();
    addToTreeSet();
    removeLastFromTreeSet();
    addToTreeSet();
    lookupTreeSet();
    freeTreeSet();
    printf( "\n" );

    addToHashSet();
    removeFromHashSet();
    addToHashSet();
    removeFirstFromHashSet();
    addToHashSet();
    removeLastFromHashSet();
    addToHashSet();
    lookupHashSet();
    freeHashSet();
    printf( "\n" );

    return 0;
}

#endif

