
##command: 

createArrayList
# createArrayList
# pblListNewArrayList( void )
# ok!

##command: 
clear
# pblListClear( 1 )
# ok

##command: 
toArray
# pblListToArray( )
# NULL, pbl_errno 1042

##command: 
setSize # setSize size

5
# pblListSetSize( 5 )
# rc 5

##command: 
iterator
# pblListIterator()
# OK

##command: 
iteratorSize
# pblIteratorSize()
# rc 5

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 0

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc -1

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 0

##command: 
previous
# pblIteratorPrevious()
# NO PREVIOUS, pbl_errno 1003

##command: 
next
# pblIteratorNext()
# next NULL

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 1

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc 0

##command: 
iteratorSet # iteratorSet itemIndex

0
# pblIteratorSet( 0 )
# set returned NULL

##command: 
iteratorSet # iteratorSet itemIndex

-1
# pblIteratorSet( NULL )
# set returned 0

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
next
# pblIteratorNext()
# next NULL

##command: 
iteratorSet # iteratorSet itemIndex

1
# pblIteratorSet( 1 )
# set returned NULL

##command: 
next
# pblIteratorNext()
# next NULL

##command: 
iteratorSet # iteratorSet itemIndex

2
# pblIteratorSet( 2 )
# set returned NULL

##command: 
next
# pblIteratorNext()
# next NULL

##command: 
iteratorSet # iteratorSet itemIndex

3
# pblIteratorSet( 3 )
# set returned NULL

##command: 
next
# pblIteratorNext()
# next NULL

##command: 
iteratorSet # iteratorSet itemIndex

4
# pblIteratorSet( 4 )
# set returned NULL

##command: 
iteratorFree
# pblIteratorFree()
# OK

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, NULL
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# OK i 4, 4
# Iteration DONE

##command: 
reverseIterator
# pblListReverseIterator()
# OK

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 5

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc 4

##command: 
hasNext
# pblIteratorHasNext()
# rc 0

##command: 
next
# pblIteratorNext()
# NO NEXT, pbl_errno 1003

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
previous
# pblIteratorPrevious()
# previous 4

##command: 
iteratorSet # iteratorSet itemIndex

14
# pblIteratorSet( 14 )
# set returned 4

##command: 
iteratorSet # iteratorSet itemIndex

-1
# pblIteratorSet( NULL )
# set returned 14

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 4

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc 3

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
previous
# pblIteratorPrevious()
# previous 3

##command: 
iteratorSet # iteratorSet itemIndex

13
# pblIteratorSet( 13 )
# set returned 3

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
previous
# pblIteratorPrevious()
# previous 2

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
previous
# pblIteratorPrevious()
# previous 1

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
previous
# pblIteratorPrevious()
# previous NULL

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 0

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc -1

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 0

##command: 
previous
# pblIteratorPrevious()
# NO PREVIOUS, pbl_errno 1003

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, NULL
# OK i 1, 1
# OK i 2, 2
# OK i 3, 13
# OK i 4, NULL
# Iteration DONE

##command: 
next
# pblIteratorNext()
# next NULL

##command: 
hasNext
# pblIteratorHasNext()
# rc 1

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
next
# pblIteratorNext()
# next 1

##command: 
iteratorAdd # iteratorAdd itemIndex

10
# pblIteratorAdd( 10 )
# rc 6

##command: 
iteratorAdd # iteratorAdd itemIndex

11
# pblIteratorAdd( 11 )
# rc 7

##command: 
previous
# pblIteratorPrevious()
# previous 11

##command: 
previous
# pblIteratorPrevious()
# previous 10

##command: 
next
# pblIteratorNext()
# next 10

##command: 
next
# pblIteratorNext()
# next 11

##command: 
next
# pblIteratorNext()
# next 2

##command: 
iteratorAdd # iteratorAdd itemIndex

12
# pblIteratorAdd( 12 )
# rc 8

##command: 
previous
# pblIteratorPrevious()
# previous 12

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, NULL
# OK i 1, 1
# OK i 2, 10
# OK i 3, 11
# OK i 4, 2
# OK i 5, 12
# OK i 6, 13
# OK i 7, NULL
# Iteration DONE

##command: 
iteratorRemove
# pblIteratorRemove()
# rc 7

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, NULL
# OK i 1, 1
# OK i 2, 10
# OK i 3, 11
# OK i 4, 2
# OK i 5, 13
# OK i 6, NULL
# Iteration DONE

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 5

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc 4

##command: 
iteratorRemove
# pblIteratorRemove()
# rc -1, pbl_errno 1040

##command: 
next
# pblIteratorNext()
# next 13

##command: 
iteratorRemove
# pblIteratorRemove()
# rc 6

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, NULL
# OK i 1, 1
# OK i 2, 10
# OK i 3, 11
# OK i 4, 2
# OK i 5, NULL
# Iteration DONE

##command: 
clear
# pblListClear( 1 )
# ok

##command: 
hasNext
# pblIteratorHasNext()
# rc -1, pbl_errno 1043

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc -1, pbl_errno 1043

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 5

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc 4

##command: 
next
# pblIteratorNext()
# NO NEXT, pbl_errno 1043

##command: 
previous
# pblIteratorPrevious()
# NO PREVIOUS, pbl_errno 1043

##command: 
iteratorAdd # iteratorAdd itemIndex

11
# pblIteratorAdd( 11 )
# rc -1, pbl_errno 1043

##command: 
next
# pblIteratorNext()
# NO NEXT, pbl_errno 1043

##command: 
iteratorSet # iteratorSet itemIndex

14
# pblIteratorSet( 14 )
# SET FAILED, pbl_errno 1043

##command: 
previous
# pblIteratorPrevious()
# NO PREVIOUS, pbl_errno 1043

##command: 
iteratorRemove
# pblIteratorRemove()
# rc -1, pbl_errno 1043

##command: 
iteratorFree
# pblIteratorFree()
# OK

##command: 
clone
# pblListClone( 1 )
# ok size 0

##command: 
contains # contains itemIndex

-1
# pblListContains( NULL )
# rc 0

##command: 
contains # contains itemIndex

0
# pblListContains( 0 )
# rc 0

##command: 
containsAll
# pblListClone( 1 )
# ok size 0
# pblListContainsAll( 1, YES )
# rc 1
# pblListAdd( 1, NULL )
# pblListContainsAll( 1, NO )
# rc 0

##command: 
peek
# pblListPeek( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
poll
# pblListPoll( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
remove
# pblListRemove( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
getFirst
# pblListGetFirst( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
getLast
# pblListGetLast(  )
# NOT FOUND, pbl_errno 1042

##command: 
top
# pblListTop(  )
# NOT FOUND, pbl_errno 1042

##command: 
element
# pblListElement( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
equals
# pblListClone( 1 )
# ok size 0
# pblListEquals( 1, YES )
# rc 1
# pblListEquals( 1, YES )
# rc 1
# pblListAdd( 1, NULL )
# pblListEquals( 1, NO )
# rc 0

##command: 
getCapacity
# getCapacity
# rc 10

##command: 
get # get index

-1
# pblListGet( -1 )
# NOT FOUND, pbl_errno 1042

##command: 
get # get index

0
# pblListGet( 0 )
# NOT FOUND, pbl_errno 1042

##command: 
get # get index

5
# pblListGet( 5 )
# NOT FOUND, pbl_errno 1042

##command: 
IsArrayList
# pblListIsArrayList( 1 )
# rc 1

##command: 
IsEmpty
# pblListIsEmpty( 1 )
# rc 1

##command: 
IsLinkedList
# pblListIsLinkedList( 1 )
# rc 0

##command: 
IsList
# pblListIsList( 1 )
# rc 1

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
IsEmpty
# pblListIsEmpty( 1 )
# rc 0

##command: 
add # add itemIndex

1
# pblListAdd( 1 )
# rc 2

##command: 
add # add itemIndex

2
# pblListAdd( 2 )
# rc 3

##command: 
add # add itemIndex

3
# pblListAdd( 3 )
# rc 4

##command: 
add # add itemIndex

4
# pblListAdd( 4 )
# rc 5

##command: 
add # add itemIndex

5
# pblListAdd( 5 )
# rc 6

##command: 
add # add itemIndex

6
# pblListAdd( 6 )
# rc 7

##command: 
add # add itemIndex

7
# pblListAdd( 7 )
# rc 8

##command: 
add # add itemIndex

8
# pblListAdd( 8 )
# rc 9

##command: 
add # add itemIndex

9
# pblListAdd( 9 )
# rc 10

##command: 
add # add itemIndex

10
# pblListAdd( 10 )
# rc 11

##command: 
add # add itemIndex

11
# pblListAdd( 11 )
# rc 12

##command: 
getCapacity
# getCapacity
# rc 21

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# OK i 4, 4
# OK i 5, 5
# OK i 6, 6
# OK i 7, 7
# OK i 8, 8
# OK i 9, 9
# OK i 10, 10
# OK i 11, 11
# Iteration DONE

##command: 
get # get index

-1
# pblListGet( -1 )
# NOT FOUND, pbl_errno 1042

##command: 
get # get index

0
# pblListGet( 0 )
# get( 0 ) 0

##command: 
get # get index

1
# pblListGet( 1 )
# get( 1 ) 1

##command: 
get # get index

5
# pblListGet( 5 )
# get( 5 ) 5

##command: 
get # get index

10
# pblListGet( 10 )
# get( 10 ) 10

##command: 
get # get index

11
# pblListGet( 11 )
# get( 11 ) 11

##command: 
get # get index

12
# pblListGet( 12 )
# NOT FOUND, pbl_errno 1042

##command: 
peek
# pblListPeek( 1 )
# first 0

##command: 
getFirst
# pblListGetFirst( 1 )
# first 0

##command: 
getLast
# pblListGetLast(  )
# last 11

##command: 
top
# pblListTop(  )
# top 11

##command: 
element
# pblListElement( 1 )
# first 0

##command: 
element
# pblListElement( 1 )
# first 0

##command: 
IndexOf # IndexOf itemIndex

0
# pblListIndexOf( 0 )
# rc 0

##command: 
IndexOf # IndexOf itemIndex

4
# pblListIndexOf( 4 )
# rc 4

##command: 
IndexOf # IndexOf itemIndex

11
# pblListIndexOf( 11 )
# rc 11

##command: 
IndexOf # IndexOf itemIndex

12
# pblListIndexOf( 12 )
# rc -1

##command: 
LastIndexOf # LastIndexOf itemIndex

0
# pblListLastIndexOf( 0 )
# rc 0

##command: 
LastIndexOf # LastIndexOf itemIndex

4
# pblListLastIndexOf( 4 )
# rc 4

##command: 
LastIndexOf # LastIndexOf itemIndex

11
# pblListLastIndexOf( 11 )
# rc 11

##command: 
LastIndexOf # LastIndexOf itemIndex

12
# pblListLastIndexOf( 12 )
# rc -1

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# OK i 4, 4
# OK i 5, 5
# OK i 6, 6
# OK i 7, 7
# OK i 8, 8
# OK i 9, 9
# Iteration DONE

##command: 
addAt # addAt index itemIndex

0 10
# pblListAddAt( 0, 10 )
# rc 13

##command: 
addAt # addAt index itemIndex

1 11
# pblListAddAt( 1, 11 )
# rc 14

##command: 
addAt # addAt index itemIndex

2 12
# pblListAddAt( 2, 12 )
# rc 15

##command: 
addAt # addAt index itemIndex

3 13
# pblListAddAt( 3, 13 )
# rc 16

##command: 
addAt # addAt index itemIndex

4 14
# pblListAddAt( 4, 14 )
# rc 17

##command: 
addAt # addAt index itemIndex

5 15
# pblListAddAt( 5, 15 )
# rc 18

##command: 
addAt # addAt index itemIndex

6 16
# pblListAddAt( 6, 16 )
# rc 19

##command: 
addAt # addAt index itemIndex

7 17
# pblListAddAt( 7, 17 )
# rc 20

##command: 
addAt # addAt index itemIndex

8 18
# pblListAddAt( 8, 18 )
# rc 21

##command: 
addAt # addAt index itemIndex

9 19
# pblListAddAt( 9, 19 )
# rc 22

##command: 
addAt # addAt index itemIndex

10 20
# pblListAddAt( 10, 20 )
# rc 23

##command: 
addAt # addAt index itemIndex

0 21
# pblListAddAt( 0, 21 )
# rc 24

##command: 
addAt # addAt index itemIndex

24 22
# pblListAddAt( 24, 22 )
# rc 25

##command: 
add # add itemIndex

-1
# pblListAdd( NULL )
# rc 26

##command: 
add # add itemIndex

-1
# pblListAdd( NULL )
# rc 27

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 21
# OK i 1, 10
# OK i 2, 11
# OK i 3, 12
# OK i 4, 13
# OK i 5, 14
# OK i 6, 15
# OK i 7, 16
# OK i 8, 17
# OK i 9, 18
# OK i 10, 19
# OK i 11, 20
# OK i 12, 0
# OK i 13, 1
# OK i 14, 2
# OK i 15, 3
# OK i 16, 4
# OK i 17, 5
# OK i 18, 6
# OK i 19, 7
# OK i 20, 8
# OK i 21, 9
# OK i 22, 10
# OK i 23, 11
# OK i 24, 22
# OK i 25, NULL
# OK i 26, NULL
# Iteration DONE

##command: 
sort
# pblListSort( 1, pblCollectionStringCompareFunction )
# ok

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, NULL
# OK i 1, NULL
# OK i 2, 0
# OK i 3, 1
# OK i 4, 10
# OK i 5, 10
# OK i 6, 11
# OK i 7, 11
# OK i 8, 12
# OK i 9, 13
# OK i 10, 14
# OK i 11, 15
# OK i 12, 16
# OK i 13, 17
# OK i 14, 18
# OK i 15, 19
# OK i 16, 2
# OK i 17, 20
# OK i 18, 21
# OK i 19, 22
# OK i 20, 3
# OK i 21, 4
# OK i 22, 5
# OK i 23, 6
# OK i 24, 7
# OK i 25, 8
# OK i 26, 9
# Iteration DONE

##command: 
peek
# pblListPeek( 1 )
# first NULL

##command: 
getFirst
# pblListGetFirst( 1 )
# first NULL

##command: 
getLast
# pblListGetLast(  )
# last 9

##command: 
top
# pblListTop(  )
# top 9

##command: 
element
# pblListElement( 1 )
# first NULL

##command: 
reverse
# pblListReverse( 1 )
# ok

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 9
# OK i 1, 8
# OK i 2, 7
# OK i 3, 6
# OK i 4, 5
# OK i 5, 4
# OK i 6, 3
# OK i 7, 22
# OK i 8, 21
# OK i 9, 20
# OK i 10, 2
# OK i 11, 19
# OK i 12, 18
# OK i 13, 17
# OK i 14, 16
# OK i 15, 15
# OK i 16, 14
# OK i 17, 13
# OK i 18, 12
# OK i 19, 11
# OK i 20, 11
# OK i 21, 10
# OK i 22, 10
# OK i 23, 1
# OK i 24, 0
# OK i 25, NULL
# OK i 26, NULL
# Iteration DONE

##command: 
getCompareFunction
# getCompareFunction
# NULL

##command: 
strcmp
# pblListSetCompareFunction( 1 )
# ok

##command: 
getCompareFunction
# getCompareFunction
# FUNCTION SET

##command: 
sort
# pblListSort( 1, pblCollectionStringCompareFunction )
# ok

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, NULL
# OK i 1, NULL
# OK i 2, 0
# OK i 3, 1
# OK i 4, 10
# OK i 5, 10
# OK i 6, 11
# OK i 7, 11
# OK i 8, 12
# OK i 9, 13
# OK i 10, 14
# OK i 11, 15
# OK i 12, 16
# OK i 13, 17
# OK i 14, 18
# OK i 15, 19
# OK i 16, 2
# OK i 17, 20
# OK i 18, 21
# OK i 19, 22
# OK i 20, 3
# OK i 21, 4
# OK i 22, 5
# OK i 23, 6
# OK i 24, 7
# OK i 25, 8
# OK i 26, 9
# Iteration DONE

##command: 
reverse
# pblListReverse( 1 )
# ok

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 9
# OK i 1, 8
# OK i 2, 7
# OK i 3, 6
# OK i 4, 5
# OK i 5, 4
# OK i 6, 3
# OK i 7, 22
# OK i 8, 21
# OK i 9, 20
# OK i 10, 2
# OK i 11, 19
# OK i 12, 18
# OK i 13, 17
# OK i 14, 16
# OK i 15, 15
# OK i 16, 14
# OK i 17, 13
# OK i 18, 12
# OK i 19, 11
# OK i 20, 11
# OK i 21, 10
# OK i 22, 10
# OK i 23, 1
# OK i 24, 0
# OK i 25, NULL
# OK i 26, NULL
# Iteration DONE

##command: 
IndexOf # IndexOf itemIndex

10
# pblListIndexOf( 10 )
# rc 21

##command: 
LastIndexOf # LastIndexOf itemIndex

10
# pblListLastIndexOf( 10 )
# rc 22

##command: 
offer # offer itemIndex

-1
# pblListOffer( NULL )
# rc 28

##command: 
getLast
# pblListGetLast(  )
# last NULL

##command: 
top
# pblListTop(  )
# top NULL

##command: 
offer # offer itemIndex

0
# pblListOffer( 0 )
# rc 29

##command: 
getLast
# pblListGetLast(  )
# last 0

##command: 
top
# pblListTop(  )
# top 0

##command: 
poll
# pblListPoll( 1 )
# polled first 9

##command: 
pop
# pblListPop( 1 )
# popped last 0

##command: 
push # push itemIndex

-1
# pblListPush( NULL )
# rc 28

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 29

##command: 
pop
# pblListPop( 1 )
# popped last 1

##command: 
pop
# pblListPop( 1 )
# popped last NULL

##command: 
peek
# pblListPeek( 1 )
# first 8

##command: 
poll
# pblListPoll( 1 )
# polled first 8

##command: 
poll
# pblListPoll( 1 )
# polled first 7

##command: 
poll
# pblListPoll( 1 )
# polled first 6

##command: 
remove
# pblListRemove( 1 )
# removed 5

##command: 
remove
# pblListRemove( 1 )
# removed 4

##command: 
removeAll
# pblListRemoveAll( 1 )
# rc 1

##command: 
iterate # iterate maxIndex

2
# pblListIterator( 2 )
# OK
# Iteration DONE

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
offer # offer itemIndex

2
# pblListOffer( 2 )
# rc 3

##command: 
addLast # addFirst itemLast

3
# pblListAddLast( 3 )
# rc 4

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# Iteration DONE

##command: 
removeAt # removeAt index

-1
# pblListRemoveAt( -1 )
# NOT FOUND, pbl_errno 1042

##command: 
removeAt # removeAt index

4
# pblListRemoveAt( 4 )
# NOT FOUND, pbl_errno 1042

##command: 
removeAt # removeAt index

0
# pblListRemoveAt( 0 )
# removed 0 0

##command: 
removeAt # removeAt index

1
# pblListRemoveAt( 1 )
# removed 1 2

##command: 
removeAt # removeAt index

1
# pblListRemoveAt( 1 )
# removed 1 3

##command: 
removeAt # removeAt index

1
# pblListRemoveAt( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
removeAt # removeAt index

0
# pblListRemoveAt( 0 )
# removed 0 1

##command: 
removeAt # removeAt index

0
# pblListRemoveAt( 0 )
# NOT FOUND, pbl_errno 1042

##command: 
IsEmpty
# pblListIsEmpty( 1 )
# rc 1

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 3

##command: 
offer # offer itemIndex

2
# pblListOffer( 2 )
# rc 4

##command: 
addLast # addFirst itemLast

3
# pblListAddLast( 3 )
# rc 5

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 1
# OK i 3, 2
# OK i 4, 3
# Iteration DONE

##command: 
removeElement # removeElement itemIndex

-1
# pblListRemoveElement( NULL )
# rc 0

##command: 
removeElement # removeElement itemIndex

4
# pblListRemoveElement( 4 )
# rc 0

##command: 
removeElement # removeElement itemIndex

1
# pblListRemoveElement( 1 )
# rc 1

##command: 
removeElement # removeElement itemIndex

1
# pblListRemoveElement( 1 )
# rc 1

##command: 
removeElement # removeElement itemIndex

1
# pblListRemoveElement( 1 )
# rc 0

##command: 
removeElement # removeElement itemIndex

0
# pblListRemoveElement( 0 )
# rc 1

##command: 
removeElement # removeElement itemIndex

3
# pblListRemoveElement( 3 )
# rc 1

##command: 
removeElement # removeElement itemIndex

2
# pblListRemoveElement( 2 )
# rc 1

##command: 
removeElement # removeElement itemIndex

2
# pblListRemoveElement( 2 )
# rc 0

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
offer # offer itemIndex

2
# pblListOffer( 2 )
# rc 3

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# Iteration DONE

##command: 
removeFirst
# pblListRemoveFirst( 1 )
# removed first 0

##command: 
removeFirst
# pblListRemoveFirst( 1 )
# removed first 1

##command: 
removeFirst
# pblListRemoveFirst( 1 )
# removed first 2

##command: 
removeFirst
# pblListRemoveFirst( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
offer # offer itemIndex

2
# pblListOffer( 2 )
# rc 3

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# Iteration DONE

##command: 
removeLast
# pblListRemoveLast( 1 )
# removed last 2

##command: 
removeLast
# pblListRemoveLast( 1 )
# removed last 1

##command: 
removeLast
# pblListRemoveLast( 1 )
# removed last 0

##command: 
removeLast
# pblListRemoveLast( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
offer # offer itemIndex

2
# pblListOffer( 2 )
# rc 3

##command: 
iterate # iterate maxIndex

10
# pblListIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# Iteration DONE

##command: 
removeLast
# pblListRemoveLast( 1 )
# removed last 2

##command: 
removeFirst
# pblListRemoveFirst( 1 )
# removed first 0

##command: 
removeLast
# pblListRemoveLast( 1 )
# removed last 1

##command: 
removeRange # removeRange from to

0 0
# pblListRemoveRange( 0, 0 )
# rc -1, pbl_errno 1042

##command: 
removeRange # removeRange from to

0 1
# pblListRemoveRange( 0, 1 )
# rc -1, pbl_errno 1042

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
removeRange # removeRange from to

0 0
# pblListRemoveRange( 0, 0 )
# rc 1

##command: 
removeRange # removeRange from to

1 1
# pblListRemoveRange( 1, 1 )
# rc -1, pbl_errno 1042

##command: 
removeRange # removeRange from to

0 1
# pblListRemoveRange( 0, 1 )
# rc 0

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
push # push itemIndex

2
# pblListPush( 2 )
# rc 3

##command: 
offer # offer itemIndex

3
# pblListOffer( 3 )
# rc 4

##command: 
addLast # addFirst itemLast

4
# pblListAddLast( 4 )
# rc 5

##command: 
removeRange # removeRange from to

0 3
# pblListRemoveRange( 0, 3 )
# rc 2

##command: 
iterate # iterate maxIndex

3
# pblListIterator( 3 )
# OK
# OK i 0, 3
# OK i 1, 4
# Iteration DONE

##command: 
removeRange # removeRange from to

0 3
# pblListRemoveRange( 0, 3 )
# rc -1, pbl_errno 1042

##command: 
removeRange # removeRange from to

0 2
# pblListRemoveRange( 0, 2 )
# rc 0

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
push # push itemIndex

2
# pblListPush( 2 )
# rc 3

##command: 
offer # offer itemIndex

3
# pblListOffer( 3 )
# rc 4

##command: 
addLast # addFirst itemLast

4
# pblListAddLast( 4 )
# rc 5

##command: 
removeRange # removeRange from to

1 4
# pblListRemoveRange( 1, 4 )
# rc 2

##command: 
iterate # iterate maxIndex

3
# pblListIterator( 3 )
# OK
# OK i 0, 0
# OK i 1, 4
# Iteration DONE

##command: 
removeRange # removeRange from to

0 2
# pblListRemoveRange( 0, 2 )
# rc 0

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
push # push itemIndex

2
# pblListPush( 2 )
# rc 3

##command: 
offer # offer itemIndex

3
# pblListOffer( 3 )
# rc 4

##command: 
addLast # addFirst itemLast

4
# pblListAddLast( 4 )
# rc 5

##command: 
removeRange # removeRange from to

2 5
# pblListRemoveRange( 2, 5 )
# rc 2

##command: 
iterate # iterate maxIndex

3
# pblListIterator( 3 )
# OK
# OK i 0, 0
# OK i 1, 1
# Iteration DONE

##command: 
removeRange # removeRange from to

0 2
# pblListRemoveRange( 0, 2 )
# rc 0

##command: 
add # add itemIndex

0
# pblListAdd( 0 )
# rc 1

##command: 
push # push itemIndex

1
# pblListPush( 1 )
# rc 2

##command: 
push # push itemIndex

2
# pblListPush( 2 )
# rc 3

##command: 
offer # offer itemIndex

3
# pblListOffer( 3 )
# rc 4

##command: 
addLast # addFirst itemLast

4
# pblListAddLast( 4 )
# rc 5

##command: 
removeRange # removeRange from to

0 5
# pblListRemoveRange( 0, 5 )
# rc 0

##command: 
clear
# pblListClear( 1 )
# ok

##command: 
retainAll
# pblListClone( 1 )
# pblListRetainAll( 1 )
# rc 0
# pblListRemoveAt( clone, 3 )
# NOT FOUND, pbl_errno 1042
# pblListRemoveFirst( clone )
# NOT FOUND, pbl_errno 1042
# pblListRemoveFirst( clone )
# NOT FOUND, pbl_errno 1042
# pblListRetainAll( 1 )
# rc 0

##command: 
add # add itemIndex

4
# pblListAdd( 4 )
# rc 1

##command: 
addAt # addAt index itemIndex

0 3
# pblListAddAt( 0, 3 )
# rc 2

##command: 
addAt # addAt index itemIndex

2 5
# pblListAddAt( 2, 5 )
# rc 3

##command: 
addFirst # addFirst itemIndex

2
# pblListAddFirst( 2 )
# rc 4

##command: 
addAt # addAt index itemIndex

0 1
# pblListAddAt( 0, 1 )
# rc 5

##command: 
addFirst # addFirst itemIndex

0
# pblListAddFirst( 0 )
# rc 6

##command: 
size
# pblListSize(  )
# rc 6

##command: 
iterate # iterate maxIndex

6
# pblListIterator( 6 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# OK i 4, 4
# OK i 5, 5
# Iteration DONE

##command: 
cloneRange # cloneRange from to

0 -1
# pblListCloneRange( 0, -1 )
# NULL, pbl_errno 1042

##command: 
cloneRange # cloneRange from to

0 0
# pblListCloneRange( 0, 0 )
# OK size 0

##command: 
cloneRange # cloneRange from to

0 1
# pblListCloneRange( 0, 1 )
# pblListToArray( clone )
# OK size 1
# OK i 0, 0
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

0 3
# pblListCloneRange( 0, 3 )
# pblListToArray( clone )
# OK size 3
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

0 5
# pblListCloneRange( 0, 5 )
# pblListToArray( clone )
# OK size 5
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# OK i 4, 4
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

0 6
# pblListCloneRange( 0, 6 )
# pblListToArray( clone )
# OK size 6
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# OK i 4, 4
# OK i 5, 5
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

0 7
# pblListCloneRange( 0, 7 )
# NULL, pbl_errno 1042

##command: 
cloneRange # cloneRange from to

1 -1
# pblListCloneRange( 1, -1 )
# NULL, pbl_errno 1042

##command: 
cloneRange # cloneRange from to

1 0
# pblListCloneRange( 1, 0 )
# NULL, pbl_errno 1042

##command: 
cloneRange # cloneRange from to

1 1
# pblListCloneRange( 1, 1 )
# OK size 0

##command: 
cloneRange # cloneRange from to

1 3
# pblListCloneRange( 1, 3 )
# pblListToArray( clone )
# OK size 2
# OK i 0, 1
# OK i 1, 2
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

1 5
# pblListCloneRange( 1, 5 )
# pblListToArray( clone )
# OK size 4
# OK i 0, 1
# OK i 1, 2
# OK i 2, 3
# OK i 3, 4
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

1 6
# pblListCloneRange( 1, 6 )
# pblListToArray( clone )
# OK size 5
# OK i 0, 1
# OK i 1, 2
# OK i 2, 3
# OK i 3, 4
# OK i 4, 5
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

1 7
# pblListCloneRange( 1, 7 )
# NULL, pbl_errno 1042

##command: 
cloneRange # cloneRange from to

-1 6
# pblListCloneRange( -1, 6 )
# NULL, pbl_errno 1042

##command: 
cloneRange # cloneRange from to

0 6
# pblListCloneRange( 0, 6 )
# pblListToArray( clone )
# OK size 6
# OK i 0, 0
# OK i 1, 1
# OK i 2, 2
# OK i 3, 3
# OK i 4, 4
# OK i 5, 5
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

4 6
# pblListCloneRange( 4, 6 )
# pblListToArray( clone )
# OK size 2
# OK i 0, 4
# OK i 1, 5
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

5 6
# pblListCloneRange( 5, 6 )
# pblListToArray( clone )
# OK size 1
# OK i 0, 5
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

6 6
# pblListCloneRange( 6, 6 )
# OK size 0

##command: 
cloneRange # cloneRange from to

7 6
# pblListCloneRange( 7, 6 )
# NULL, pbl_errno 1042

##command: 
set # set index itemIndex

-1 -1
# pblListSet( -1, NULL )
# SET ERROR, pbl_errno 1042

##command: 
set # set index itemIndex

3 -1
# pblListSet( 3, NULL )
# set returned 3

##command: 
set # set index itemIndex

0 10
# pblListSet( 0, 10 )
# set returned 0

##command: 
set # set index itemIndex

5 15
# pblListSet( 5, 15 )
# set returned 5

##command: 
set # set index itemIndex

6 -1
# pblListSet( 6, NULL )
# SET ERROR, pbl_errno 1042

##command: 
iterate # iterate maxIndex

6
# pblListIterator( 6 )
# OK
# OK i 0, 10
# OK i 1, 1
# OK i 2, 2
# OK i 3, NULL
# OK i 4, 4
# OK i 5, 15
# Iteration DONE

##command: 
setFirst # setFirst itemIndex

0
# pblListSetFirst( 0 )
# set returned 10

##command: 
set # set index itemIndex

3 3
# pblListSet( 3, 3 )
# set returned NULL

##command: 
setLast # setLast itemIndex

5
# pblListSetLast( 5 )
# set returned 15

##command: 
reverseIterate # reverseIterate maxIndex

6
# pblListReverseIterator( 6 )
# OK
# OK i 0, 5
# OK i 1, 4
# OK i 2, 3
# OK i 3, 2
# OK i 4, 1
# OK i 5, 0
# Iteration DONE

##command: 
retainAll
# pblListClone( 1 )
# pblListRetainAll( 1 )
# rc 0
# pblListRemoveAt( clone, 3 )
# removed 3d 3
# pblListRemoveFirst( clone )
# removed first 0
# pblListRemoveFirst( clone )
# removed last 5
# pblListRetainAll( 1 )
# rc 1

##command: 
size
# pblListSize(  )
# rc 3

##command: 
iterate # iterate maxIndex

6
# pblListIterator( 6 )
# OK
# OK i 0, 1
# OK i 1, 2
# OK i 2, 4
# Iteration DONE

##command: 
reverseIterate # reverseIterate maxIndex

6
# pblListReverseIterator( 6 )
# OK
# OK i 0, 4
# OK i 1, 2
# OK i 2, 1
# Iteration DONE

##command: 
removeAll
# pblListRemoveAll( 1 )
# rc 1

##command: 
setFirst # setFirst itemIndex

1
# pblListSetFirst( 1 )
# SET ERROR, pbl_errno 1042

##command: 
set # set index itemIndex

0 0
# pblListSet( 0, 0 )
# SET ERROR, pbl_errno 1042

##command: 
setLast # setLast itemIndex

2
# pblListSetLast( 2 )
# SET ERROR, pbl_errno 1042

##command: 
size
# pblListSize(  )
# rc 0

##command: 
clear
# pblListClear( 1 )
# ok

##command: 
size
# pblListSize(  )
# rc 0

##command: 
clear
# pblListClear( 1 )
# ok

##command: 
clone
# pblListClone( 1 )
# ok size 0

##command: 
contains # contains itemIndex

-1
# pblListContains( NULL )
# rc 0

##command: 
contains # contains itemIndex

0
# pblListContains( 0 )
# rc 0

##command: 
containsAll
# pblListClone( 1 )
# ok size 0
# pblListContainsAll( 1, YES )
# rc 1
# pblListAdd( 1, NULL )
# pblListContainsAll( 1, NO )
# rc 0

##command: 
peek
# pblListPeek( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
getFirst
# pblListGetFirst( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
getLast
# pblListGetLast(  )
# NOT FOUND, pbl_errno 1042

##command: 
top
# pblListTop(  )
# NOT FOUND, pbl_errno 1042

##command: 
element
# pblListElement( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
equals
# pblListClone( 1 )
# ok size 0
# pblListEquals( 1, YES )
# rc 1
# pblListEquals( 1, YES )
# rc 1
# pblListAdd( 1, NULL )
# pblListEquals( 1, NO )
# rc 0

##command: 
getCapacity
# getCapacity
# rc 43

##command: 
get # get index

-1
# pblListGet( -1 )
# NOT FOUND, pbl_errno 1042

##command: 
get # get index

0
# pblListGet( 0 )
# NOT FOUND, pbl_errno 1042

##command: 
get # get index

5
# pblListGet( 5 )
# NOT FOUND, pbl_errno 1042

##command: 
ensureCapacity # ensureCapacity minCapacity

1
# ensureCapacity( 1 )
# rc 43

##command: 
getCapacity
# getCapacity
# rc 43

##command: 
IsEmpty
# pblListIsEmpty( 1 )
# rc 1

##command: 
addFirst # addFirst itemIndex

10
# pblListAddFirst( 10 )
# rc 1

##command: 
IsEmpty
# pblListIsEmpty( 1 )
# rc 0

##command: 
addLast # addFirst itemLast

11
# pblListAddLast( 11 )
# rc 2

##command: 
addFirst # addFirst itemIndex

12
# pblListAddFirst( 12 )
# rc 3

##command: 
addLast # addFirst itemLast

13
# pblListAddLast( 13 )
# rc 4

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 12
# OK i 1, 10
# OK i 2, 11
# OK i 3, 13
# Iteration DONE

##command: 
toArray
# pblListToArray( )
# OK
# OK i 0, 12
# OK i 1, 10
# OK i 2, 11
# OK i 3, 13
# Array Iteration DONE

##command: 
addAll
# pblListAddAll( 1 )
# rc 8

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 12
# OK i 1, 10
# OK i 2, 11
# OK i 3, 13
# OK i 4, 12
# OK i 5, 10
# OK i 6, 11
# OK i 7, 13
# Iteration DONE

##command: 
addAllAt # addAllAt index

1
# pblListAddAllAt( 1 )
# rc 16

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 12
# OK i 1, 12
# OK i 2, 10
# OK i 3, 11
# OK i 4, 13
# OK i 5, 12
# OK i 6, 10
# OK i 7, 11
# OK i 8, 13
# OK i 9, 10
# OK i 10, 11
# OK i 11, 13
# OK i 12, 12
# OK i 13, 10
# OK i 14, 11
# OK i 15, 13
# Iteration DONE

##command: 
addAllAt # addAllAt index

16
# pblListAddAllAt( 16 )
# rc 32

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 12
# OK i 1, 12
# OK i 2, 10
# OK i 3, 11
# OK i 4, 13
# OK i 5, 12
# OK i 6, 10
# OK i 7, 11
# OK i 8, 13
# OK i 9, 10
# OK i 10, 11
# OK i 11, 13
# OK i 12, 12
# OK i 13, 10
# OK i 14, 11
# OK i 15, 13
# OK i 16, 12
# OK i 17, 12
# OK i 18, 10
# OK i 19, 11
# OK i 20, 13
# OK i 21, 12
# OK i 22, 10
# OK i 23, 11
# OK i 24, 13
# OK i 25, 10
# OK i 26, 11
# OK i 27, 13
# OK i 28, 12
# OK i 29, 10
# OK i 30, 11
# OK i 31, 13
# Iteration DONE

##command: 
addAllAt # addAllAt index

0
# pblListAddAllAt( 0 )
# rc 64

##command: 
iterate # iterate maxIndex

100
# pblListIterator( 100 )
# OK
# OK i 0, 12
# OK i 1, 12
# OK i 2, 10
# OK i 3, 11
# OK i 4, 13
# OK i 5, 12
# OK i 6, 10
# OK i 7, 11
# OK i 8, 13
# OK i 9, 10
# OK i 10, 11
# OK i 11, 13
# OK i 12, 12
# OK i 13, 10
# OK i 14, 11
# OK i 15, 13
# OK i 16, 12
# OK i 17, 12
# OK i 18, 10
# OK i 19, 11
# OK i 20, 13
# OK i 21, 12
# OK i 22, 10
# OK i 23, 11
# OK i 24, 13
# OK i 25, 10
# OK i 26, 11
# OK i 27, 13
# OK i 28, 12
# OK i 29, 10
# OK i 30, 11
# OK i 31, 13
# OK i 32, 12
# OK i 33, 12
# OK i 34, 10
# OK i 35, 11
# OK i 36, 13
# OK i 37, 12
# OK i 38, 10
# OK i 39, 11
# OK i 40, 13
# OK i 41, 10
# OK i 42, 11
# OK i 43, 13
# OK i 44, 12
# OK i 45, 10
# OK i 46, 11
# OK i 47, 13
# OK i 48, 12
# OK i 49, 12
# OK i 50, 10
# OK i 51, 11
# OK i 52, 13
# OK i 53, 12
# OK i 54, 10
# OK i 55, 11
# OK i 56, 13
# OK i 57, 10
# OK i 58, 11
# OK i 59, 13
# OK i 60, 12
# OK i 61, 10
# OK i 62, 11
# OK i 63, 13
# Iteration DONE

##command: 
clone
# pblListClone( 1 )
# ok size 64

##command: 
contains # contains itemIndex

10
# pblListContains( 10 )
# rc 1

##command: 
contains # contains itemIndex

0
# pblListContains( 0 )
# rc 0

##command: 
contains # contains itemIndex

-1
# pblListContains( NULL )
# rc 0

##command: 
containsAll
# pblListClone( 1 )
# ok size 64
# pblListContainsAll( 1, YES )
# rc 1
# pblListAdd( 1, NULL )
# pblListContainsAll( 1, NO )
# rc 0

##command: 
peek
# pblListPeek( 1 )
# first 12

##command: 
getFirst
# pblListGetFirst( 1 )
# first 12

##command: 
getLast
# pblListGetLast(  )
# last 13

##command: 
top
# pblListTop(  )
# top 13

##command: 
element
# pblListElement( 1 )
# first 12

##command: 
ensureCapacity # ensureCapacity minCapacity

0
# ensureCapacity( 0 )
# rc 87

##command: 
ensureCapacity # ensureCapacity minCapacity

5
# ensureCapacity( 5 )
# rc 87

##command: 
ensureCapacity # ensureCapacity minCapacity

200
# ensureCapacity( 200 )
# rc 200

##command: 
equals
# pblListClone( 1 )
# ok size 64
# pblListEquals( 1, YES )
# rc 1
# pblListEquals( 1, YES )
# rc 1
# pblListAdd( 1, NULL )
# pblListEquals( 1, NO )
# rc 0

##command: 
setSize # setSize size

0
# pblListSetSize( 0 )
# rc 0

##command: 
getCapacity
# getCapacity
# rc 200

##command: 
trim
# pblListTrimToSize( )
# rc 0

##command: 
trim
# pblListTrimToSize( )
# rc 0

##command: 
getCapacity
# getCapacity
# rc 0

##command: 
iterate # iterate maxIndex

1
# pblListIterator( 1 )
# OK
# Iteration DONE

##command: 
setSize # setSize size

16
# pblListSetSize( 16 )
# rc 16

##command: 
getCapacity
# getCapacity
# rc 21

##command: 
trim
# pblListTrimToSize( )
# rc 16

##command: 
getCapacity
# getCapacity
# rc 16

##command: 
iterate # iterate maxIndex

17
# pblListIterator( 17 )
# OK
# OK i 0, NULL
# OK i 1, NULL
# OK i 2, NULL
# OK i 3, NULL
# OK i 4, NULL
# OK i 5, NULL
# OK i 6, NULL
# OK i 7, NULL
# OK i 8, NULL
# OK i 9, NULL
# OK i 10, NULL
# OK i 11, NULL
# OK i 12, NULL
# OK i 13, NULL
# OK i 14, NULL
# OK i 15, NULL
# Iteration DONE

##command: 
setSize # setSize size

8
# pblListSetSize( 8 )
# rc 8

##command: 
iterate # iterate maxIndex

9
# pblListIterator( 9 )
# OK
# OK i 0, NULL
# OK i 1, NULL
# OK i 2, NULL
# OK i 3, NULL
# OK i 4, NULL
# OK i 5, NULL
# OK i 6, NULL
# OK i 7, NULL
# Iteration DONE

##command: 
setSize # setSize size

24
# pblListSetSize( 24 )
# rc 24

##command: 
iterate # iterate maxIndex

25
# pblListIterator( 25 )
# OK
# OK i 0, NULL
# OK i 1, NULL
# OK i 2, NULL
# OK i 3, NULL
# OK i 4, NULL
# OK i 5, NULL
# OK i 6, NULL
# OK i 7, NULL
# OK i 8, NULL
# OK i 9, NULL
# OK i 10, NULL
# OK i 11, NULL
# OK i 12, NULL
# OK i 13, NULL
# OK i 14, NULL
# OK i 15, NULL
# OK i 16, NULL
# OK i 17, NULL
# OK i 18, NULL
# OK i 19, NULL
# OK i 20, NULL
# OK i 21, NULL
# OK i 22, NULL
# OK i 23, NULL
# Iteration DONE

##command: 
getCapacity
# getCapacity
# rc 33

##command: 
trim
# pblListTrimToSize( )
# rc 24

##command: 
getCapacity
# getCapacity
# rc 24

##command: 
iterate # iterate maxIndex

25
# pblListIterator( 25 )
# OK
# OK i 0, NULL
# OK i 1, NULL
# OK i 2, NULL
# OK i 3, NULL
# OK i 4, NULL
# OK i 5, NULL
# OK i 6, NULL
# OK i 7, NULL
# OK i 8, NULL
# OK i 9, NULL
# OK i 10, NULL
# OK i 11, NULL
# OK i 12, NULL
# OK i 13, NULL
# OK i 14, NULL
# OK i 15, NULL
# OK i 16, NULL
# OK i 17, NULL
# OK i 18, NULL
# OK i 19, NULL
# OK i 20, NULL
# OK i 21, NULL
# OK i 22, NULL
# OK i 23, NULL
# Iteration DONE

##command: 
setSize # setSize size

0
# pblListSetSize( 0 )
# rc 0

##command: 
iterator
# pblListIterator()
# OK

##command: 
iteratorAdd # iteratorAdd itemIndex

-1
# pblIteratorAdd( NULL )
# rc 1

##command: 
hasNext
# pblIteratorHasNext()
# rc 0

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
next
# pblIteratorNext()
# NO NEXT, pbl_errno 1003

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 1

##command: 
previous
# pblIteratorPrevious()
# previous NULL

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc -1

##command: 
iteratorRemove
# pblIteratorRemove()
# rc 0

##command: 
iteratorSet # iteratorSet itemIndex

-1
# pblIteratorSet( NULL )
# SET FAILED, pbl_errno 1040

##command: 
iteratorSize
# pblIteratorSize()
# rc 0

##command: 
iteratorFree
# pblIteratorFree()
# OK

##command: 
reverseIterator
# pblListReverseIterator()
# OK

##command: 
iteratorAdd # iteratorAdd itemIndex

-1
# pblIteratorAdd( NULL )
# rc 1

##command: 
hasNext
# pblIteratorHasNext()
# rc 0

##command: 
hasPrevious
# pblIteratorHasPrevious()
# rc 1

##command: 
next
# pblIteratorNext()
# NO NEXT, pbl_errno 1003

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 1

##command: 
previous
# pblIteratorPrevious()
# previous NULL

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc -1

##command: 
iteratorRemove
# pblIteratorRemove()
# rc 0

##command: 
iteratorSet # iteratorSet itemIndex

-1
# pblIteratorSet( NULL )
# SET FAILED, pbl_errno 1040

##command: 
iteratorSize
# pblIteratorSize()
# rc 0

##command: 
iteratorFree
# pblIteratorFree()
# OK

##command: 
quit