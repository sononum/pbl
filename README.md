## Peter Graf’s Free GPL Open Source Software

</center>
<a name="top"></a>

* * * * *

All software published here is published under the [The GNU General
Public License][] or the [The GNU Lesser General Public License][]

<dl>
<dt>
### PBL - The Program Base Library

PBL is an GPL open source C library of functions that can be used in a C
or C++ project. PBL is highly portable and compiles warning free on
Linux gcc, MAC OS X and Windows Microsoft Visual C++ 2010 Express
Edition.
The code of the PBL library includes the following modules:

[**PBL BASE**][] - Some base functions, see **pbl\_\*** functions,

[**PBL COLLECTION**][] - An open source C implementation of a collection
used by the list and set implementations.

[**PBL LIST**][] - An open source C implementation of array lists and
linked lists similar to the [Java List][] interface, see **pblList\***
functions,

<ul>
[][**PBL LIST**]
<li>
**pblArrayList**</a>: — C array list, C-ArrayList, array list in C,
ArrayList in C, List in C
Open source C resizable-array implementation equivalent to the [Java
ArrayList][] class.

Implements most optional list operations, and permits all elements,
including NULL. In addition to implementing the List operations, this
module provides methods to manipulate the size of the array that is used
internally to store the list.

The size, isEmpty, get, set, iterator, and listIterator operations run
in constant time. The add operation runs in amortized constant time,
that is, adding n elements requires O(n) time. All of the other
operations run in linear time (roughly speaking). The constant factor is
low compared to that for the LinkedList implementation.

Each pblArrayList instance has a capacity. The capacity is the size of
the array used to store the elements in the list. It is always at least
as large as the list size. As elements are added to an ArrayList, its
capacity grows automatically. The details of the growth policy are not
specified beyond the fact that adding an element has constant amortized
time cost.

<p>
An application can increase the capacity of an ArrayList instance before
adding a large number of elements using the ensureCapacity operation.
This may reduce the amount of incremental reallocation.
<li>
[**pblLinkedList**][**PBL LIST**]: — C linked list, C-LinkedList, linked
list in C, LinkedList in C, List in C
Open source C linked list implementation equivalent to the [Java
LinkedList][] class.

Implements most optional list operations, and permits all elements
(including null). In addition to implementing the List operations, this
module provides uniformly named methods to get, remove and insert an
element at the beginning and end of the list. These operations allow
linked lists to be used as a stack, queue, or double-ended queue
(deque).

The module implements the Queue operations, providing first-in-first-out
queue operations for add, poll, etc. Other stack and deque operations
could be easily recast in terms of the standard list operations.

<p>
All of the operations perform as could be expected for a doubly-linked
list. Operations that index into the list will traverse the list from
the beginning or the end, whichever is closer to the specified index.
<li>
[**pblIterator**][]: — C list iterator, C-ListIterator, list iterator in
C, ListIterator in C
Open source C Iterator implementation equivalent to the [Java
ListIterator][] interface.

An iterator for lists that allows the programmer to traverse the list in
either direction, modify the list during iteration, and obtain the
iterator’s current position in the list. A ListIterator has no current
element; its cursor position always lies between the element that would
be returned by a call to previous() and the element that would be
returned by a call to next(). In a li TRUNCATED! Please download pandoc
if you want to convert large files.

  [Mission Base]: http://www.mission-base.com/index-images/mb240.gif
  [![Mission Base][]]: http://www.mission-base.com/
  [The GNU General Public License]: http://www.gnu.org/licenses/licenses.html#GPL
  [The GNU Lesser General Public License]: http://www.gnu.org/licenses/licenses.html#LGPL
  [**PBL BASE**]: pbl/doc/base.html
  [**PBL COLLECTION**]: pbl/doc/collection.html
  [**PBL LIST**]: pbl/doc/list.html
  [Java List]: http://java.sun.com/j2se/1.5.0/docs/api/java/util/List.html
  [Java ArrayList]: http://java.sun.com/j2se/1.5.0/docs/api/java/util/ArrayList.html
  [Java LinkedList]: http://java.sun.com/j2se/1.5.0/docs/api/java/util/LinkedList.html
  [**pblIterator**]: pbl/doc/iterator.html
  [Java ListIterator]: http://java.sun.com/j2se/1.5.0/docs/api/java/util/ListIterator.html