#
# simple makefile to make the pbl library and the test frame
#
AR=      /usr/bin/ar
RANLIB=  /usr/bin/ar ts
IPATH=   -I.
CFLAGS=  -Wall -O3 ${IPATH} -DPBLTEST
CC= gcc

INCLIB    = 

LIB_OBJS  = pblPriorityQueue.o pblHeap.o pblMap.o pblSet.o pblList.o pblCollection.o pblIterator.o pblisam.o pblkf.o pblhash.o pbl.o
THELIB    = libpbl.a

EXE_OBJS1 = pblhttst.o
THEEXE1   = pblhttst

EXE_OBJS2 = pblkftst.o
THEEXE2   = pblkftst

EXE_OBJS3 = pbliftst.o
THEEXE3   = pbliftst

EXE_OBJS4 = pblkfblockprint.o
THEEXE4   = pblkfblockprint

EXE_OBJS5 = pblListTest.o
THEEXE5   = pblListTest

EXE_OBJS6 = pblSetTest.o
THEEXE6   = pblSetTest

EXE_OBJS7 = pblPerform.o
THEEXE7   = pblPerform

EXE_OBJS8 = pblMapTest.o
THEEXE8   = pblMapTest

EXE_OBJS9 = pblPriorityQueueTest.o
THEEXE9   = pblPriorityQueueTest

all: $(THELIB) $(THEEXE1) $(THEEXE2) $(THEEXE3) $(THEEXE4) $(THEEXE5) $(THEEXE6) $(THEEXE7) $(THEEXE8) $(THEEXE9)

$(THELIB):  $(LIB_OBJS)
	$(AR) rc $(THELIB) $?
	$(RANLIB) $(THELIB)

$(THEEXE1):  $(EXE_OBJS1) $(THELIB)
	$(CC) -O2 -o $(THEEXE1) $(EXE_OBJS1) $(THELIB) $(INCLIB)

$(THEEXE2):  $(EXE_OBJS2) $(THELIB)
	$(CC) -O2 -o $(THEEXE2) $(EXE_OBJS2) $(THELIB) $(INCLIB)

$(THEEXE3):  $(EXE_OBJS3) $(THELIB)
	$(CC) -O2 -o $(THEEXE3) $(EXE_OBJS3) $(THELIB) $(INCLIB)

$(THEEXE4):  $(EXE_OBJS4) $(THELIB)
	$(CC) -O2 -o $(THEEXE4) $(EXE_OBJS4) $(THELIB) $(INCLIB)

$(THEEXE5):  $(EXE_OBJS5) $(THELIB)
	$(CC) -O2 -o $(THEEXE5) $(EXE_OBJS5) $(THELIB) $(INCLIB)

$(THEEXE6):  $(EXE_OBJS6) $(THELIB)
	$(CC) -O2 -o $(THEEXE6) $(EXE_OBJS6) $(THELIB) $(INCLIB)

$(THEEXE7):  $(EXE_OBJS7) $(THELIB)
	$(CC) -O2 -o $(THEEXE7) $(EXE_OBJS7) $(THELIB) $(INCLIB)

$(THEEXE8):  $(EXE_OBJS8) $(THELIB)
	$(CC) -O2 -o $(THEEXE8) $(EXE_OBJS8) $(THELIB) $(INCLIB)

$(THEEXE9):  $(EXE_OBJS9) $(THELIB)
	$(CC) -O2 -o $(THEEXE9) $(EXE_OBJS9) $(THELIB) $(INCLIB)

test: $(THEEXE3) $(THEEXE5) $(THEEXE6)
	mkdir -p isamtest/
	rm -f isamtest/0*
	./$(THEEXE3) ISAM0001.TST > /dev/null
	diff ISAM0001.TST pbliftst.log || ( echo test case 1 failed; exit 1 )
	echo passed test case 1
	./$(THEEXE3) ISAM0004.TST > /dev/null
	diff ISAM0004.TST pbliftst.log || ( echo test case 4 failed; exit 1 )
	echo passed test case 4
	./$(THEEXE5) ARRAYLIST0001.TST > /dev/null
	diff ARRAYLIST0001.TST pblListTest.log || ( echo test case7a failed; exit 1 )
	echo passed test case 7a
	./$(THEEXE5) LINKEDLIST0001.TST > /dev/null
	diff LINKEDLIST0001.TST pblListTest.log || ( echo test case7b failed; exit 1 )
	echo passed test case 7b
	./$(THEEXE6) TREESET0001.TST > /dev/null
	diff TREESET0001.TST pblSetTest.log || ( echo test case8a failed; exit 1 )
	echo passed test case 8a
	./$(THEEXE6) HASHSET0001.TST > /dev/null
	diff HASHSET0001.TST pblSetTest.log || ( echo test case8b failed; exit 1 )
	echo passed test case 8b
	rm -f isamtest/0*
	echo
	echo !!! ALL TESTS PASSED SUCCESSFULLY !!!
	echo
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*

test1: $(THEEXE3)
	mkdir -p isamtest/
	rm -f isamtest/0*
	./$(THEEXE3) ISAM0001.TST > /dev/null
	diff ISAM0001.TST pbliftst.log || ( echo test case 1 failed; exit 1 )
	echo passed test case 1
	rm -f isamtest/0*
	echo !!! all tests passed !!!
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*

test2: $(THEEXE3)
	mkdir -p isamtest/
	rm -f isamtest/0*
	./$(THEEXE3) ISAM0002.TST > /dev/null
	diff ISAM0002.TST pbliftst.log || ( echo test case 2 failed; exit 1 )
	echo passed test case 2
	rm -f isamtest/0*
	echo !!! all tests passed !!!
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*


test4: $(THEEXE3)
	mkdir -p isamtest/
	rm -f isamtest/0*
	./$(THEEXE3) ISAM0004.TST > /dev/null
	diff ISAM0004.TST pbliftst.log || ( echo test case 4 failed; exit 1 )
	echo passed test case 4
	rm -f isamtest/0*
	echo !!! all tests passed !!!
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*


test5: $(THEEXE3)
	mkdir -p isamtest/
	rm -f isamtest/0*
	./$(THEEXE3) ISAM0005.TST > /dev/null
	diff ISAM0005.TST pbliftst.log || ( echo test case 5 failed; exit 1 )
	echo passed test case 5
	rm -f isamtest/0*
	echo !!! all tests passed !!!
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*


test6: $(THEEXE3)
	mkdir -p isamtest/
	rm -f isamtest/0*
	./$(THEEXE3) ISAM0006.TST > /dev/null
	diff ISAM0006.TST pbliftst.log || ( echo test case 6 failed; exit 1 )
	echo passed test case 6
	rm -f isamtest/0*
	echo !!! all tests passed !!!
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*

test7: $(THEEXE5)
	mkdir -p isamtest/
	rm -f isamtest/0*
	./$(THEEXE5) ARRAYLIST0001.TST > /dev/null
	diff ARRAYLIST0001.TST pblListTest.log || ( echo test case7a failed; exit 1 )
	echo passed test case 7a
	./$(THEEXE5) LINKEDLIST0001.TST > /dev/null
	diff LINKEDLIST0001.TST pblListTest.log || ( echo test case7b failed; exit 1 )
	echo passed test case 7b
	rm -f isamtest/0*
	echo !!! all tests passed !!!
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*

clean:
	rm -f ${THELIB}  ${LIB_OBJS} core
	rm -f ${THEEXE1} ${EXE_OBJS1}
	rm -f ${THEEXE2} ${EXE_OBJS2}
	rm -f ${THEEXE3} ${EXE_OBJS3}
	rm -f ${THEEXE4} ${EXE_OBJS4}
	rm -f ${THEEXE5} ${EXE_OBJS5}
	rm -f ${THEEXE6} ${EXE_OBJS6}
	rm -f ${THEEXE7} ${EXE_OBJS7}
	rm -f ${THEEXE8} ${EXE_OBJS8}
	rm -f ${THEEXE9} ${EXE_OBJS9}
	rm -f isamtest/0*

