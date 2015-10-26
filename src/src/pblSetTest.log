
##command: 

createHashSet
# pblSetNewHashSet( void )
# ok!

##command: 
strhash
# pblSetSetHashValueFunction( 1 )
# ok Function was set

##command: 
getCompareFunction
# getCompareFunction
# NULL

##command: 
strcmp
# pblSetSetCompareFunction( 1 )
# ok NULL

##command: 
getHashValueFunction
# getHashValueFunction
# FUNCTION SET

##command: 
getCapacity
# getCapacity
# rc 0

##command: 
element
# pblSetElement( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
getFirst
# pblSetGetFirst( 1 )
# first NULL

##command: 
peek
# pblSetPeek( 1 )
# first NULL

##command: 
getLast
# pblSetGetLast(  )
# last NULL

##command: 
IndexOf # IndexOf itemIndex

0
# pblSetIndexOf( 0 )
# rc -1

##command: 
LastIndexOf # LastIndexOf itemIndex

0
# pblSetLastIndexOf( 0 )
# rc -1

##command: 
contains # contains itemIndex

0
# pblSetContains( 0 )
# rc 0

##command: 
remove # remove itemIndex

0
# pblSetRemoveElement( 0 )
# rc 0

##command: 
removeAt # removeAt index

0
# pblSetRemoveAt( 0 )
# NOT FOUND, pbl_errno 1042

##command: 
IsEmpty
# pblSetIsEmpty( 1 )
# rc 1

##command: 
IsHashSet
# pblSetIsHashSet( 1 )
# rc 1

##command: 
IsTreeSet
# pblSetIsTreeSet( 1 )
# rc 0

##command: 
IsSet
# pblSetIsSet( 1 )
# rc 1

##command: 
poll
# pblSetPoll( 1 )
# polled first NULL

##command: 
pop
# pblSetPop( 1 )
# popped last NULL

##command: 
removeFirst
# pblSetRemoveFirst( 1 )
# removed first NULL

##command: 
removeLast
# pblSetRemoveLast( 1 )
# removed last NULL

##command: 
size
# pblSetSize(  )
# rc 0

##command: 
toArray
# pblSetToArray( )
# NULL, pbl_errno 1042

##command: 
union
# pblSetCloneRange( set, 0, 0 )
# ok size 0
# pblSetUnion( testSet, empty )
# pblSetPrint( Union )
# size 0
# capacity 0
# step size 3
# pblSetClone( 1 )
# ok size 0
# pblSetUnion( testSet, empty )
# pblSetPrint( Union )
# size 0
# capacity 0
# step size 3
# pblSetRemoveFirst( clone )
# result NULL
# pblSetRemoveLast( clone )
# result NULL
# pblSetAdd( 1, NotFound )
# pblSetUnion( testSet, clone )
# pblSetPrint( Union )
# size 1
# capacity 8
# step size 3
# i 7, hashval 7, NotFound

##command: 
trim
# pblSetTrimToSize( )
# rc 0

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

5
# pblSetAdd( 5 )
# rc 1

##command: 
add # add itemIndex

7
# pblSetAdd( 7 )
# rc 1

##command: 
add # add itemIndex

9
# pblSetAdd( 9 )
# rc 1

##command: 
aggregate # aggregate counter

0
# pblCollectionAggregate( 0 )
# rc 1

##command: 
aggregate # aggregate counter

3
# pblCollectionAggregate( 3 )
# aggregation counter 3, i 0, element 3
# aggregation counter 2, i 1, element 9
# aggregation counter 1, i 2, element 5
# rc 1

##command: 
aggregate # aggregate counter

5
# pblCollectionAggregate( 5 )
# aggregation counter 5, i 0, element 3
# aggregation counter 4, i 1, element 9
# aggregation counter 3, i 2, element 5
# aggregation counter 2, i 3, element 7
# aggregation counter 1, i 4, element 1
# rc 0

##command: 
toArray
# pblSetToArray( )
# OK
# OK i 0, 3
# OK i 1, 9
# OK i 2, 5
# OK i 3, 7
# OK i 4, 1
# Array Iteration DONE

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 9
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 1

##command: 
size
# pblSetSize(  )
# rc 5

##command: 
IsEmpty
# pblSetIsEmpty( 1 )
# rc 0

##command: 
IndexOf # IndexOf itemIndex

0
# pblSetIndexOf( 0 )
# rc -1

##command: 
IndexOf # IndexOf itemIndex

1
# pblSetIndexOf( 1 )
# rc 4

##command: 
IndexOf # IndexOf itemIndex

9
# pblSetIndexOf( 9 )
# rc 1

##command: 
IndexOf # IndexOf itemIndex

10
# pblSetIndexOf( 10 )
# rc -1

##command: 
LastIndexOf # LastIndexOf itemIndex

0
# pblSetLastIndexOf( 0 )
# rc -1

##command: 
LastIndexOf # LastIndexOf itemIndex

1
# pblSetLastIndexOf( 1 )
# rc 4

##command: 
LastIndexOf # LastIndexOf itemIndex

9
# pblSetLastIndexOf( 9 )
# rc 1

##command: 
LastIndexOf # LastIndexOf itemIndex

10
# pblSetLastIndexOf( 10 )
# rc -1

##command: 
equals
# pblSetClone( 1 )
# ok size 5
# pblSetEquals( 1, YES )
# rc 1
# pblSetEquals( 1, YES )
# rc 1
# pblSetAdd( 1, NotFound )
# pblSetEquals( 1, NO )
# rc 0
# pblCollectionConvertToArrayList( collection )
# ok size 5
# pblSetEquals( testcollection, clone ) YES
# rc 1
# pblSetEquals( clone, testcollection ) YES
# rc 1
# pblCollectionConvertToLinkedList( collection )
# ok size 5
# pblSetEquals( testcollection, clone ) YES
# rc 1
# pblSetEquals( clone, testcollection ) YES
# rc 1
# pblCollectionConvertToHashSet( collection )
# ok size 5
# pblSetEquals( testcollection, clone ) YES
# rc 1
# pblSetEquals( clone, testcollection ) YES
# rc 1
# pblCollectionConvertToTreeSet( collection )
# ok size 5
# pblSetEquals( testcollection, clone ) YES
# rc 1
# pblSetEquals( clone, testcollection ) YES
# rc 1

##command: 
element
# pblSetElement( 1 )
# first 3

##command: 
getFirst
# pblSetGetFirst( 1 )
# first 3

##command: 
peek
# pblSetPeek( 1 )
# first 3

##command: 
getLast
# pblSetGetLast(  )
# last 1

##command: 
containsAll
# pblSetPrint( original )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 9
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 1
# pblSetClone( 1 )
# pblSetPrint( clone )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 9
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 1
# pblSetContainsAll( 1, YES )
# rc 1
# pblSetAdd( 1, NotFound )
# pblSetContainsAll( 1, NO )
# rc 0

##command: 
difference
# pblSetClone( 1 )
# ok size 5
# pblSetDifference( testSet, clone )
# pblSetPrint( difference )
# size 0
# capacity 0
# step size 3
# pblSetRemoveFirst( clone )
# OK 3
# pblSetRemoveLast( clone )
# OK 1
# pblSetDifference( testSet, clone )
# pblSetPrint( difference )
# size 2
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 6, hashval 6, 1
# pblSetDifference( clone, testSet )
# pblSetPrint( difference )
# size 0
# capacity 0
# step size 3

##command: 
symmectricDifference
# pblSetClone( 1 )
# ok size 5
# pblSetSymmectricDifference( testSet, clone )
# pblSetPrint( SymmectricDifference )
# size 0
# capacity 0
# step size 3
# pblSetRemoveFirst( clone )
# OK 3
# pblSetRemoveLast( clone )
# OK 1
# pblSetSymmectricDifference( testSet, clone )
# pblSetPrint( SymmectricDifference )
# size 2
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 6, hashval 6, 1

##command: 
intersection
# pblSetClone( 1 )
# ok size 5
# pblSetIntersection( testSet, clone )
# pblSetPrint( intersection )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 1
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 9
# pblSetRemoveFirst( clone )
# OK 3
# pblSetRemoveLast( clone )
# OK 1
# pblSetIntersection( testSet, clone )
# pblSetPrint( intersection )
# size 3
# capacity 8
# step size 3
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 9
# pblSetIntersection( clone, testSet )
# pblSetPrint( intersection )
# size 3
# capacity 8
# step size 3
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 9

##command: 
IsSubset
# pblSetClone( 1 )
# ok size 5
# pblSetIsSubset( testSet, testSet )
# rc 1
# pblSetIsSubset( testSet, clone )
# rc 1
# pblSetRemoveFirst( clone )
# OK 3
# pblSetRemoveLast( clone )
# OK 1
# pblSetIsSubset( testSet, clone )
# rc 1
# pblSetIsSubset( clone, testSet )
# rc 0

##command: 
strcmp
# pblSetSetCompareFunction( 1 )
# ok Function was set

##command: 
union
# pblSetCloneRange( set, 0, 0 )
# ok size 0
# pblSetUnion( testSet, empty )
# pblSetPrint( Union )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 9
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 1
# pblSetClone( 1 )
# ok size 5
# pblSetUnion( testSet, empty )
# pblSetPrint( Union )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 9
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 1
# pblSetRemoveFirst( clone )
# result 3
# pblSetRemoveLast( clone )
# result 1
# pblSetAdd( 1, NotFound )
# pblSetUnion( testSet, clone )
# pblSetPrint( Union )
# size 6
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 9
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 1
# i 7, hashval 7, NotFound

##command: 
trim
# pblSetTrimToSize( )
# rc 8

##command: 
contains # contains itemIndex

0
# pblSetContains( 0 )
# rc 0

##command: 
contains # contains itemIndex

1
# pblSetContains( 1 )
# rc 1

##command: 
contains # contains itemIndex

4
# pblSetContains( 4 )
# rc 0

##command: 
contains # contains itemIndex

5
# pblSetContains( 5 )
# rc 1

##command: 
contains # contains itemIndex

9
# pblSetContains( 9 )
# rc 1

##command: 
contains # contains itemIndex

10
# pblSetContains( 10 )
# rc 0

##command: 
addAll
# pblSetAddAll( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 6, 1
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 6, hashval 6, 9
# rc 5

##command: 
cloneRange # cloneRange from to

-1 0
# pblSetCloneRange( -1, 0 )
# NULL, pbl_errno 1042

##command: 
cloneRange # cloneRange from to

0 0
# pblSetCloneRange( 0, 0 )
# OK size 0

##command: 
cloneRange # cloneRange from to

0 3
# pblSetCloneRange( 0, 3 )
# pblSetToArray( clone )
# OK size 3
# OK i 0, 3
# OK i 1, 5
# OK i 2, 9
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

1 3
# pblSetCloneRange( 1, 3 )
# pblSetToArray( clone )
# OK size 2
# OK i 0, 5
# OK i 1, 9
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

2 5
# pblSetCloneRange( 2, 5 )
# pblSetToArray( clone )
# OK size 3
# OK i 0, 5
# OK i 1, 7
# OK i 2, 1
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

0 5
# pblSetCloneRange( 0, 5 )
# pblSetToArray( clone )
# OK size 5
# OK i 0, 3
# OK i 1, 9
# OK i 2, 5
# OK i 3, 7
# OK i 4, 1
# Clone Iteration DONE

##command: 
cloneRange # cloneRange from to

0 6
# pblSetCloneRange( 0, 6 )
# NULL, pbl_errno 1042

##command: 
getCapacity
# getCapacity
# rc 8

##command: 
ensureCapacity # ensureCapacity minCapacity

100
# ensureCapacity( 100 )
# rc 256

##command: 
trim
# pblSetTrimToSize( )
# rc 8

##command: 
ensureCapacity # ensureCapacity minCapacity

100
# ensureCapacity( 100 )
# rc 256

##command: 
getCapacity
# getCapacity
# rc 256

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 256
# step size 37
# i 128, hashval 128, 3
# i 130, hashval 130, 5
# i 132, hashval 132, 7
# i 134, hashval 134, 9
# i 142, hashval 142, 1

##command: 
poll
# pblSetPoll( 1 )
# polled first 3

##command: 
pop
# pblSetPop( 1 )
# popped last 1

##command: 
removeAll
# pblSetRemoveAll( 1 )
# rc 1

##command: 
clear
# pblSetClear( 1 )
# ok

##command: 
trim
# pblSetTrimToSize( )
# rc 0

##command: 
getFirst
# pblSetGetFirst( 1 )
# first NULL

##command: 
getLast
# pblSetGetLast(  )
# last NULL

##command: 
getHashValueFunction
# getHashValueFunction
# FUNCTION SET

##command: 
getCapacity
# getCapacity
# rc 0

##command: 
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

4
# pblSetAdd( 4 )
# rc 1

##command: 
iterate # iterate maxIndex

10
# pblIteratorNew( 10 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 4
# OK i 3, 1
# OK i 4, 0
# Iteration DONE

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
removeAt # removeAt index

-1
# pblSetRemoveAt( -1 )
# NOT FOUND, pbl_errno 1042

##command: 
removeAt # removeAt index

5
# pblSetRemoveAt( 5 )
# NOT FOUND, pbl_errno 1042

##command: 
removeAt # removeAt index

0
# pblSetRemoveAt( 0 )
# removed 0 3

##command: 
print
# pblSetPrint( 1 )
# size 4
# capacity 8
# step size 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
removeAt # removeAt index

3
# pblSetRemoveAt( 3 )
# removed 3 0

##command: 
print
# pblSetPrint( 1 )
# size 3
# capacity 8
# step size 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1

##command: 
removeAt # removeAt index

1
# pblSetRemoveAt( 1 )
# removed 1 4

##command: 
print
# pblSetPrint( 1 )
# size 2
# capacity 8
# step size 3
# i 1, hashval 1, 2
# i 6, hashval 6, 1

##command: 
removeAt # removeAt index

1
# pblSetRemoveAt( 1 )
# removed 1 1

##command: 
print
# pblSetPrint( 1 )
# size 1
# capacity 8
# step size 3
# i 1, hashval 1, 2

##command: 
removeAt # removeAt index

1
# pblSetRemoveAt( 1 )
# NOT FOUND, pbl_errno 1042

##command: 
removeAt # removeAt index

0
# pblSetRemoveAt( 0 )
# removed 0 2

##command: 
print
# pblSetPrint( 1 )
# size 0
# capacity 8
# step size 3

##command: 
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

4
# pblSetAdd( 4 )
# rc 1

##command: 
reverseIterate # reverseIterate maxIndex

10
# pblSetReverseIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 4
# OK i 3, 2
# OK i 4, 3
# Iteration DONE

##command: 
iterate # iterate maxIndex

10
# pblIteratorNew( 10 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 4
# OK i 3, 1
# OK i 4, 0
# Iteration DONE

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
iterator
# pblSetIterator( 1 )
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
# next 3

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
# SET FAILED, pbl_errno 1011

##command: 
iteratorSet # iteratorSet itemIndex

-1
# pblIteratorSet( NULL )
# SET FAILED, pbl_errno 1011

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
# next 2

##command: 
iteratorSet # iteratorSet itemIndex

1
# pblIteratorSet( 1 )
# SET FAILED, pbl_errno 1011

##command: 
next
# pblIteratorNext()
# next 4

##command: 
iteratorSet # iteratorSet itemIndex

2
# pblIteratorSet( 2 )
# SET FAILED, pbl_errno 1011

##command: 
next
# pblIteratorNext()
# next 1

##command: 
iteratorSet # iteratorSet itemIndex

3
# pblIteratorSet( 3 )
# SET FAILED, pbl_errno 1011

##command: 
next
# pblIteratorNext()
# next 0

##command: 
iteratorSet # iteratorSet itemIndex

4
# pblIteratorSet( 4 )
# SET FAILED, pbl_errno 1011

##command: 
iteratorFree
# pblIteratorFree()
# OK

##command: 
iterate # iterate maxIndex

10
# pblIteratorNew( 10 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 4
# OK i 3, 1
# OK i 4, 0
# Iteration DONE

##command: 
reverseIterate # reverseIterate maxIndex

10
# pblSetReverseIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 4
# OK i 3, 2
# OK i 4, 3
# Iteration DONE

##command: 
reverseIterator
# pblIteratorReverseNew( 1 )
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
# previous 0

##command: 
iteratorSet # iteratorSet itemIndex

14
# pblIteratorSet( 14 )
# SET FAILED, pbl_errno 1011

##command: 
iteratorSet # iteratorSet itemIndex

-1
# pblIteratorSet( NULL )
# SET FAILED, pbl_errno 1011

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
# previous 1

##command: 
iteratorSet # iteratorSet itemIndex

13
# pblIteratorSet( 13 )
# SET FAILED, pbl_errno 1011

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
# previous 4

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
# previous 3

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
# pblIteratorNew( 10 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 4
# OK i 3, 1
# OK i 4, 0
# Iteration DONE

##command: 
next
# pblIteratorNext()
# next 3

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
# next 2

##command: 
iteratorAdd # iteratorAdd itemIndex

10
# pblIteratorAdd( 10 )
# rc -1, pbl_errno 1011

##command: 
iteratorAdd # iteratorAdd itemIndex

11
# pblIteratorAdd( 11 )
# rc -1, pbl_errno 1011

##command: 
previous
# pblIteratorPrevious()
# previous 2

##command: 
previous
# pblIteratorPrevious()
# previous 3

##command: 
next
# pblIteratorNext()
# next 3

##command: 
next
# pblIteratorNext()
# next 2

##command: 
next
# pblIteratorNext()
# next 4

##command: 
iteratorAdd # iteratorAdd itemIndex

12
# pblIteratorAdd( 12 )
# rc -1, pbl_errno 1011

##command: 
previous
# pblIteratorPrevious()
# previous 4

##command: 
iterate # iterate maxIndex

10
# pblIteratorNew( 10 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 4
# OK i 3, 1
# OK i 4, 0
# Iteration DONE

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
iteratorRemove
# pblIteratorRemove()
# rc -1, pbl_errno 1011

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
iterate # iterate maxIndex

10
# pblIteratorNew( 10 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 4
# OK i 3, 1
# OK i 4, 0
# Iteration DONE

##command: 
nextIndex
# pblIteratorNextIndex()
# rc 2

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc 1

##command: 
iteratorRemove
# pblIteratorRemove()
# rc -1, pbl_errno 1011

##command: 
next
# pblIteratorNext()
# next 4

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
iteratorRemove
# pblIteratorRemove()
# rc -1, pbl_errno 1011

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 3, hashval 3, 4
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
previous
# pblIteratorPrevious()
# previous 4

##command: 
iterate # iterate maxIndex

10
# pblIteratorNew( 10 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 4
# OK i 3, 1
# OK i 4, 0
# Iteration DONE

##command: 
reverseIterate # reverseIterate maxIndex

10
# pblSetReverseIterator( 10 )
# OK
# OK i 0, 0
# OK i 1, 1
# OK i 2, 4
# OK i 3, 2
# OK i 4, 3
# Iteration DONE

##command: 
clear
# pblSetClear( 1 )
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
# rc 2

##command: 
previousIndex
# pblIteratorPreviousIndex()
# rc 1

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
# rc -1, pbl_errno 1011

##command: 
next
# pblIteratorNext()
# NO NEXT, pbl_errno 1043

##command: 
iteratorSet # iteratorSet itemIndex

14
# pblIteratorSet( 14 )
# SET FAILED, pbl_errno 1011

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
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

4
# pblSetAdd( 4 )
# rc 1

##command: 
add # add itemIndex

5
# pblSetAdd( 5 )
# rc 1

##command: 
add # add itemIndex

6
# pblSetAdd( 6 )
# rc 1

##command: 
add # add itemIndex

7
# pblSetAdd( 7 )
# rc 1

##command: 
add # add itemIndex

8
# pblSetAdd( 8 )
# rc 1

##command: 
add # add itemIndex

9
# pblSetAdd( 9 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 10
# capacity 16
# step size 3
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 14, hashval 14, 1
# i 15, hashval 15, 0

##command: 
remove # remove itemIndex

3
# pblSetRemoveElement( 3 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 9
# capacity 16
# step size 3
# i 1, hashval 1, 2
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 14, hashval 14, 1
# i 15, hashval 15, 0

##command: 
remove # remove itemIndex

2
# pblSetRemoveElement( 2 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 8
# capacity 16
# step size 3
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 14, hashval 14, 1
# i 15, hashval 15, 0

##command: 
remove # remove itemIndex

7
# pblSetRemoveElement( 7 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 7
# capacity 16
# step size 3
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 14, hashval 14, 1
# i 15, hashval 15, 0

##command: 
clear
# pblSetClear( 1 )
# ok

##command: 
print
# pblSetPrint( 1 )
# size 0
# capacity 16
# step size 3

##command: 
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

4
# pblSetAdd( 4 )
# rc 1

##command: 
add # add itemIndex

5
# pblSetAdd( 5 )
# rc 1

##command: 
add # add itemIndex

6
# pblSetAdd( 6 )
# rc 1

##command: 
add # add itemIndex

7
# pblSetAdd( 7 )
# rc 1

##command: 
add # add itemIndex

8
# pblSetAdd( 8 )
# rc 1

##command: 
add # add itemIndex

9
# pblSetAdd( 9 )
# rc 1

##command: 
add # add itemIndex

10
# pblSetAdd( 10 )
# rc 1

##command: 
add # add itemIndex

11
# pblSetAdd( 11 )
# rc 1

##command: 
add # add itemIndex

12
# pblSetAdd( 12 )
# rc 1

##command: 
add # add itemIndex

13
# pblSetAdd( 13 )
# rc 1

##command: 
add # add itemIndex

14
# pblSetAdd( 14 )
# rc 1

##command: 
add # add itemIndex

15
# pblSetAdd( 15 )
# rc 1

##command: 
add # add itemIndex

16
# pblSetAdd( 16 )
# rc 1

##command: 
add # add itemIndex

17
# pblSetAdd( 17 )
# rc 1

##command: 
add # add itemIndex

18
# pblSetAdd( 18 )
# rc 1

##command: 
add # add itemIndex

19
# pblSetAdd( 19 )
# rc 1

##command: 
add # add itemIndex

20
# pblSetAdd( 20 )
# rc 1

##command: 
add # add itemIndex

21
# pblSetAdd( 21 )
# rc 1

##command: 
add # add itemIndex

22
# pblSetAdd( 22 )
# rc 1

##command: 
add # add itemIndex

23
# pblSetAdd( 23 )
# rc 1

##command: 
add # add itemIndex

24
# pblSetAdd( 24 )
# rc 1

##command: 
add # add itemIndex

25
# pblSetAdd( 25 )
# rc 1

##command: 
add # add itemIndex

26
# pblSetAdd( 26 )
# rc 1

##command: 
add # add itemIndex

27
# pblSetAdd( 27 )
# rc 1

##command: 
iterate # iterate maxIndex

100
# pblIteratorNew( 100 )
# OK
# OK i 0, 3
# OK i 1, 2
# OK i 2, 5
# OK i 3, 4
# OK i 4, 7
# OK i 5, 6
# OK i 6, 9
# OK i 7, 8
# OK i 8, 1
# OK i 9, 0
# OK i 10, 19
# OK i 11, 17
# OK i 12, 18
# OK i 13, 15
# OK i 14, 16
# OK i 15, 13
# OK i 16, 14
# OK i 17, 11
# OK i 18, 12
# OK i 19, 10
# OK i 20, 21
# OK i 21, 20
# OK i 22, 23
# OK i 23, 22
# OK i 24, 25
# OK i 25, 24
# OK i 26, 27
# OK i 27, 26
# Iteration DONE

##command: 
print
# pblSetPrint( 1 )
# size 28
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 14, hashval 14, 1
# i 15, hashval 15, 0
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 22, hashval 22, 15
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
get # get index

-1
# pblSetGet( -1 )
# get( -1 ) NULL

##command: 
get # get index

0
# pblSetGet( 0 )
# get( 0 ) 3

##command: 
get # get index

1
# pblSetGet( 1 )
# get( 1 ) 2

##command: 
get # get index

2
# pblSetGet( 2 )
# get( 2 ) 5

##command: 
get # get index

14
# pblSetGet( 14 )
# get( 14 ) 16

##command: 
get # get index

26
# pblSetGet( 26 )
# get( 26 ) 27

##command: 
get # get index

27
# pblSetGet( 27 )
# get( 27 ) 26

##command: 
get # get index

28
# pblSetGet( 28 )
# get( 28 ) NULL

##command: 
remove # remove itemIndex

15
# pblSetRemoveElement( 15 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 27
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 14, hashval 14, 1
# i 15, hashval 15, 0
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

0
# pblSetRemoveElement( 0 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 26
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 14, hashval 14, 1
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

1
# pblSetRemoveElement( 1 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 25
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

2
# pblSetRemoveElement( 2 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 24
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

3
# pblSetRemoveElement( 3 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 23
# capacity 64
# step size 11
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

4
# pblSetRemoveElement( 4 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 22
# capacity 64
# step size 11
# i 2, hashval 2, 5
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

5
# pblSetRemoveElement( 5 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 21
# capacity 64
# step size 11
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

6
# pblSetRemoveElement( 6 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 20
# capacity 64
# step size 11
# i 4, hashval 4, 7
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

7
# pblSetRemoveElement( 7 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 19
# capacity 64
# step size 11
# i 6, hashval 6, 9
# i 7, hashval 7, 8
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

8
# pblSetRemoveElement( 8 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 18
# capacity 64
# step size 11
# i 6, hashval 6, 9
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

9
# pblSetRemoveElement( 9 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 17
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

10
# pblSetRemoveElement( 10 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 16
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

11
# pblSetRemoveElement( 11 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 15
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 27, hashval 27, 12
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

12
# pblSetRemoveElement( 12 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 14
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

13
# pblSetRemoveElement( 13 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 13
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 25, hashval 25, 14
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

14
# pblSetRemoveElement( 14 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 12
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

15
# pblSetRemoveElement( 15 )
# rc 0

##command: 
print
# pblSetPrint( 1 )
# size 12
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

16
# pblSetRemoveElement( 16 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 11
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

17
# pblSetRemoveElement( 17 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 10
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 21, hashval 21, 18
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

18
# pblSetRemoveElement( 18 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 9
# capacity 64
# step size 11
# i 18, hashval 18, 19
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

19
# pblSetRemoveElement( 19 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 8
# capacity 64
# step size 11
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

20
# pblSetRemoveElement( 20 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 7
# capacity 64
# step size 11
# i 48, hashval 48, 21
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

21
# pblSetRemoveElement( 21 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 6
# capacity 64
# step size 11
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

22
# pblSetRemoveElement( 22 )
# rc 1

##command: 
remove # remove itemIndex

23
# pblSetRemoveElement( 23 )
# rc 1

##command: 
remove # remove itemIndex

24
# pblSetRemoveElement( 24 )
# rc 1

##command: 
remove # remove itemIndex

25
# pblSetRemoveElement( 25 )
# rc 1

##command: 
remove # remove itemIndex

26
# pblSetRemoveElement( 26 )
# rc 1

##command: 
remove # remove itemIndex

27
# pblSetRemoveElement( 27 )
# rc 1

##command: 
add # add itemIndex

15
# pblSetAdd( 15 )
# rc 1

##command: 
add # add itemIndex

16
# pblSetAdd( 16 )
# rc 1

##command: 
add # add itemIndex

17
# pblSetAdd( 17 )
# rc 1

##command: 
add # add itemIndex

18
# pblSetAdd( 18 )
# rc 1

##command: 
add # add itemIndex

19
# pblSetAdd( 19 )
# rc 1

##command: 
add # add itemIndex

20
# pblSetAdd( 20 )
# rc 1

##command: 
add # add itemIndex

21
# pblSetAdd( 21 )
# rc 1

##command: 
add # add itemIndex

22
# pblSetAdd( 22 )
# rc 1

##command: 
add # add itemIndex

23
# pblSetAdd( 23 )
# rc 1

##command: 
add # add itemIndex

24
# pblSetAdd( 24 )
# rc 1

##command: 
add # add itemIndex

25
# pblSetAdd( 25 )
# rc 1

##command: 
add # add itemIndex

26
# pblSetAdd( 26 )
# rc 1

##command: 
add # add itemIndex

27
# pblSetAdd( 27 )
# rc 1

##command: 
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

4
# pblSetAdd( 4 )
# rc 1

##command: 
add # add itemIndex

5
# pblSetAdd( 5 )
# rc 1

##command: 
add # add itemIndex

6
# pblSetAdd( 6 )
# rc 1

##command: 
add # add itemIndex

7
# pblSetAdd( 7 )
# rc 1

##command: 
add # add itemIndex

8
# pblSetAdd( 8 )
# rc 1

##command: 
add # add itemIndex

9
# pblSetAdd( 9 )
# rc 1

##command: 
add # add itemIndex

10
# pblSetAdd( 10 )
# rc 1

##command: 
add # add itemIndex

11
# pblSetAdd( 11 )
# rc 1

##command: 
add # add itemIndex

12
# pblSetAdd( 12 )
# rc 1

##command: 
add # add itemIndex

13
# pblSetAdd( 13 )
# rc 1

##command: 
add # add itemIndex

14
# pblSetAdd( 14 )
# rc 1

##command: 
remove # remove itemIndex

27
# pblSetRemoveElement( 27 )
# rc 1

##command: 
remove # remove itemIndex

27
# pblSetRemoveElement( 27 )
# rc 0

##command: 
remove # remove itemIndex

26
# pblSetRemoveElement( 26 )
# rc 1

##command: 
remove # remove itemIndex

25
# pblSetRemoveElement( 25 )
# rc 1

##command: 
remove # remove itemIndex

24
# pblSetRemoveElement( 24 )
# rc 1

##command: 
remove # remove itemIndex

23
# pblSetRemoveElement( 23 )
# rc 1

##command: 
remove # remove itemIndex

22
# pblSetRemoveElement( 22 )
# rc 1

##command: 
remove # remove itemIndex

21
# pblSetRemoveElement( 21 )
# rc 1

##command: 
remove # remove itemIndex

20
# pblSetRemoveElement( 20 )
# rc 1

##command: 
remove # remove itemIndex

19
# pblSetRemoveElement( 19 )
# rc 1

##command: 
remove # remove itemIndex

18
# pblSetRemoveElement( 18 )
# rc 1

##command: 
remove # remove itemIndex

17
# pblSetRemoveElement( 17 )
# rc 1

##command: 
remove # remove itemIndex

16
# pblSetRemoveElement( 16 )
# rc 1

##command: 
remove # remove itemIndex

16
# pblSetRemoveElement( 16 )
# rc 0

##command: 
remove # remove itemIndex

15
# pblSetRemoveElement( 15 )
# rc 1

##command: 
remove # remove itemIndex

14
# pblSetRemoveElement( 14 )
# rc 1

##command: 
remove # remove itemIndex

13
# pblSetRemoveElement( 13 )
# rc 1

##command: 
remove # remove itemIndex

12
# pblSetRemoveElement( 12 )
# rc 1

##command: 
remove # remove itemIndex

11
# pblSetRemoveElement( 11 )
# rc 1

##command: 
remove # remove itemIndex

10
# pblSetRemoveElement( 10 )
# rc 1

##command: 
remove # remove itemIndex

9
# pblSetRemoveElement( 9 )
# rc 1

##command: 
remove # remove itemIndex

8
# pblSetRemoveElement( 8 )
# rc 1

##command: 
remove # remove itemIndex

7
# pblSetRemoveElement( 7 )
# rc 1

##command: 
remove # remove itemIndex

6
# pblSetRemoveElement( 6 )
# rc 1

##command: 
remove # remove itemIndex

5
# pblSetRemoveElement( 5 )
# rc 1

##command: 
remove # remove itemIndex

4
# pblSetRemoveElement( 4 )
# rc 1

##command: 
remove # remove itemIndex

3
# pblSetRemoveElement( 3 )
# rc 1

##command: 
remove # remove itemIndex

2
# pblSetRemoveElement( 2 )
# rc 1

##command: 
remove # remove itemIndex

1
# pblSetRemoveElement( 1 )
# rc 1

##command: 
remove # remove itemIndex

0
# pblSetRemoveElement( 0 )
# rc 1

##command: 
remove # remove itemIndex

0
# pblSetRemoveElement( 0 )
# rc 0

##command: 
add # add itemIndex

8
# pblSetAdd( 8 )
# rc 1

##command: 
add # add itemIndex

15
# pblSetAdd( 15 )
# rc 1

##command: 
add # add itemIndex

17
# pblSetAdd( 17 )
# rc 1

##command: 
add # add itemIndex

21
# pblSetAdd( 21 )
# rc 1

##command: 
add # add itemIndex

23
# pblSetAdd( 23 )
# rc 1

##command: 
add # add itemIndex

26
# pblSetAdd( 26 )
# rc 1

##command: 
add # add itemIndex

27
# pblSetAdd( 27 )
# rc 1

##command: 
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

7
# pblSetAdd( 7 )
# rc 1

##command: 
add # add itemIndex

9
# pblSetAdd( 9 )
# rc 1

##command: 
add # add itemIndex

10
# pblSetAdd( 10 )
# rc 1

##command: 
add # add itemIndex

11
# pblSetAdd( 11 )
# rc 1

##command: 
add # add itemIndex

14
# pblSetAdd( 14 )
# rc 1

##command: 
add # add itemIndex

19
# pblSetAdd( 19 )
# rc 1

##command: 
add # add itemIndex

20
# pblSetAdd( 20 )
# rc 1

##command: 
add # add itemIndex

24
# pblSetAdd( 24 )
# rc 1

##command: 
add # add itemIndex

25
# pblSetAdd( 25 )
# rc 1

##command: 
add # add itemIndex

4
# pblSetAdd( 4 )
# rc 1

##command: 
add # add itemIndex

5
# pblSetAdd( 5 )
# rc 1

##command: 
add # add itemIndex

22
# pblSetAdd( 22 )
# rc 1

##command: 
add # add itemIndex

6
# pblSetAdd( 6 )
# rc 1

##command: 
add # add itemIndex

13
# pblSetAdd( 13 )
# rc 1

##command: 
add # add itemIndex

16
# pblSetAdd( 16 )
# rc 1

##command: 
add # add itemIndex

18
# pblSetAdd( 18 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

12
# pblSetAdd( 12 )
# rc 1

##command: 
remove # remove itemIndex

2
# pblSetRemoveElement( 2 )
# rc 1

##command: 
remove # remove itemIndex

8
# pblSetRemoveElement( 8 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 26
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 14, hashval 14, 1
# i 15, hashval 15, 0
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 22, hashval 22, 15
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

15
# pblSetRemoveElement( 15 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 25
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 14, hashval 14, 1
# i 15, hashval 15, 0
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 25, hashval 25, 14
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

14
# pblSetRemoveElement( 14 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 24
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 4, hashval 4, 7
# i 5, hashval 5, 6
# i 6, hashval 6, 9
# i 14, hashval 14, 1
# i 15, hashval 15, 0
# i 18, hashval 18, 19
# i 20, hashval 20, 17
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 26, hashval 26, 11
# i 27, hashval 27, 12
# i 29, hashval 29, 10
# i 48, hashval 48, 21
# i 49, hashval 49, 20
# i 50, hashval 50, 23
# i 51, hashval 51, 22
# i 52, hashval 52, 25
# i 53, hashval 53, 24
# i 54, hashval 54, 27
# i 55, hashval 55, 26

##command: 
remove # remove itemIndex

17
# pblSetRemoveElement( 17 )
# rc 1

##command: 
remove # remove itemIndex

21
# pblSetRemoveElement( 21 )
# rc 1

##command: 
remove # remove itemIndex

23
# pblSetRemoveElement( 23 )
# rc 1

##command: 
remove # remove itemIndex

26
# pblSetRemoveElement( 26 )
# rc 1

##command: 
remove # remove itemIndex

27
# pblSetRemoveElement( 27 )
# rc 1

##command: 
remove # remove itemIndex

0
# pblSetRemoveElement( 0 )
# rc 1

##command: 
remove # remove itemIndex

1
# pblSetRemoveElement( 1 )
# rc 1

##command: 
remove # remove itemIndex

3
# pblSetRemoveElement( 3 )
# rc 1

##command: 
remove # remove itemIndex

7
# pblSetRemoveElement( 7 )
# rc 1

##command: 
remove # remove itemIndex

9
# pblSetRemoveElement( 9 )
# rc 1

##command: 
remove # remove itemIndex

10
# pblSetRemoveElement( 10 )
# rc 1

##command: 
remove # remove itemIndex

11
# pblSetRemoveElement( 11 )
# rc 1

##command: 
remove # remove itemIndex

12
# pblSetRemoveElement( 12 )
# rc 1

##command: 
remove # remove itemIndex

19
# pblSetRemoveElement( 19 )
# rc 1

##command: 
remove # remove itemIndex

20
# pblSetRemoveElement( 20 )
# rc 1

##command: 
remove # remove itemIndex

24
# pblSetRemoveElement( 24 )
# rc 1

##command: 
remove # remove itemIndex

25
# pblSetRemoveElement( 25 )
# rc 1

##command: 
remove # remove itemIndex

4
# pblSetRemoveElement( 4 )
# rc 1

##command: 
remove # remove itemIndex

5
# pblSetRemoveElement( 5 )
# rc 1

##command: 
remove # remove itemIndex

22
# pblSetRemoveElement( 22 )
# rc 1

##command: 
remove # remove itemIndex

6
# pblSetRemoveElement( 6 )
# rc 1

##command: 
remove # remove itemIndex

13
# pblSetRemoveElement( 13 )
# rc 1

##command: 
remove # remove itemIndex

16
# pblSetRemoveElement( 16 )
# rc 1

##command: 
remove # remove itemIndex

18
# pblSetRemoveElement( 18 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 0
# capacity 64
# step size 11

##command: 
add # add itemIndex

12
# pblSetAdd( 12 )
# rc 1

##command: 
add # add itemIndex

5
# pblSetAdd( 5 )
# rc 1

##command: 
add # add itemIndex

22
# pblSetAdd( 22 )
# rc 1

##command: 
add # add itemIndex

6
# pblSetAdd( 6 )
# rc 1

##command: 
add # add itemIndex

13
# pblSetAdd( 13 )
# rc 1

##command: 
add # add itemIndex

16
# pblSetAdd( 16 )
# rc 1

##command: 
add # add itemIndex

18
# pblSetAdd( 18 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 7
# capacity 64
# step size 11
# i 2, hashval 2, 5
# i 5, hashval 5, 6
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 27, hashval 27, 12
# i 51, hashval 51, 22

##command: 
remove # remove itemIndex

5
# pblSetRemoveElement( 5 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 6
# capacity 64
# step size 11
# i 5, hashval 5, 6
# i 21, hashval 21, 18
# i 23, hashval 23, 16
# i 24, hashval 24, 13
# i 27, hashval 27, 12
# i 51, hashval 51, 22

##command: 
remove # remove itemIndex

22
# pblSetRemoveElement( 22 )
# rc 1

##command: 
remove # remove itemIndex

6
# pblSetRemoveElement( 6 )
# rc 1

##command: 
remove # remove itemIndex

13
# pblSetRemoveElement( 13 )
# rc 1

##command: 
remove # remove itemIndex

16
# pblSetRemoveElement( 16 )
# rc 1

##command: 
remove # remove itemIndex

18
# pblSetRemoveElement( 18 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 1
# capacity 64
# step size 11
# i 27, hashval 27, 12

##command: 
remove # remove itemIndex

2
# pblSetRemoveElement( 2 )
# rc 0

##command: 
remove # remove itemIndex

12
# pblSetRemoveElement( 12 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 0
# capacity 64
# step size 11

##command: 
removeAll
# pblSetRemoveAll( 1 )
# rc 0

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

3
# pblSetAdd( 3 )
# rc 1

##command: 
add # add itemIndex

4
# pblSetAdd( 4 )
# rc 1

##command: 
add # add itemIndex

5
# pblSetAdd( 5 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 64
# step size 11
# i 0, hashval 0, 3
# i 1, hashval 1, 2
# i 2, hashval 2, 5
# i 3, hashval 3, 4
# i 14, hashval 14, 1

##command: 
removeFirst
# pblSetRemoveFirst( 1 )
# removed first 3

##command: 
removeLast
# pblSetRemoveLast( 1 )
# removed last 1

##command: 
removeFirst
# pblSetRemoveFirst( 1 )
# removed first 2

##command: 
removeLast
# pblSetRemoveLast( 1 )
# removed last 4

##command: 
removeFirst
# pblSetRemoveFirst( 1 )
# removed first 5

##command: 
trim
# pblSetTrimToSize( )
# rc 0

##command: 
print
# pblSetPrint( 1 )
# size 0
# capacity 0
# step size 3

##command: 
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

10
# pblSetAdd( 10 )
# rc 1

##command: 
add # add itemIndex

11
# pblSetAdd( 11 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 1, hashval 1, 2
# i 2, hashval 2, 11
# i 5, hashval 5, 10
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
retainAll
# pblSetClone( 1 )
# pblSetRetainAll( original, clone )
# rc 0
# pblSetRemoveFirst( clone, )
# removed first 2
# pblSetRemoveLast( clone )
# removed last 0
# size 3
# capacity 8
# step size 3
# i 2, hashval 2, 11
# i 5, hashval 5, 10
# i 6, hashval 6, 1
# pblSetRetainAll( 1 )
# rc 1
# size 3
# capacity 8
# step size 3
# i 2, hashval 2, 11
# i 5, hashval 5, 10
# i 6, hashval 6, 1

##command: 
removeAll
# pblSetRemoveAll( 1 )
# rc 1

##command: 
strcmp
# pblSetSetCompareFunction( 1 )
# ok Function was set

##command: 
add # add itemIndex

0
# pblSetAdd( 0 )
# rc 1

##command: 
add # add itemIndex

1
# pblSetAdd( 1 )
# rc 1

##command: 
add # add itemIndex

2
# pblSetAdd( 2 )
# rc 1

##command: 
add # add itemIndex

10
# pblSetAdd( 10 )
# rc 1

##command: 
add # add itemIndex

11
# pblSetAdd( 11 )
# rc 1

##command: 
print
# pblSetPrint( 1 )
# size 5
# capacity 8
# step size 3
# i 1, hashval 1, 2
# i 2, hashval 2, 11
# i 5, hashval 5, 10
# i 6, hashval 6, 1
# i 7, hashval 7, 0

##command: 
quit
