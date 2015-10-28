/*
 AvlDictionary.cs - C# implementation of an AVL tree based generic IDictionary<TKey,TValue> interface.

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

 $Log: AvlDictionary.cs,v $
 Revision 1.2  2012/12/11 00:42:34  peter
 Removed some warnings

 Revision 1.1  2009/11/26 18:56:32  peter
 Initial


 */

using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace Com.Mission_Base.Pbl
{
    /// <summary>
    /// AvlDictionary&lt;TKey,TValue&gt; is an implementation of the generic IDictionary&lt;TKey,TValue&gt; interface based on an AVL-tree.
    /// The AvlDictionary&lt;TKey,TValue&gt; represents a collection of key/value pairs that are sorted on the key.
    /// </summary>
    /// <typeparam name="TKey">
    /// The type of keys in the dictionary.
    /// </typeparam>
    /// <typeparam name="TValue">
    /// The type of values in the dictionary.
    /// </typeparam>
    [Serializable]
    [ComVisible(false)]
    [DebuggerDisplay("Count = {Count}")]
    public class AvlDictionary<TKey, TValue> :
        IDictionary<TKey, TValue>,
        ICollection
        where TKey : IComparable<TKey>
    {
        /// <summary>
        /// Provides the common base functionality of all Enumerators used with an AvlDictionary&lt;TKey,TValue&gt;.
        /// </summary>
        public class AvlDictionaryBaseEnumerator
        {
            private readonly AvlDictionary<TKey, TValue> _avlDictionary;
            private AvlTreeNode _node;
            private bool _isExhausted;
            private readonly long _changeCounter;

            /// <summary>
            /// Creates a new enumerator of the AvlDictionary&lt;TKey,TValue&gt;.
            /// </summary>
            /// <param name="dictionary">
            /// The AvlDictionary&lt;TKey,TValue&gt; the enumerator is created for.
            /// </param>

            protected AvlDictionaryBaseEnumerator(AvlDictionary<TKey, TValue> dictionary)
            {
                _avlDictionary = dictionary;
                _changeCounter = dictionary._changeCounter;
                _node = null;
                _isExhausted = _avlDictionary._rootNode == null;
            }

            /// <summary>
            /// Tests whether the enumerator is properly postioned.
            /// </summary>
            /// <returns>
            /// true if the enumerator is postioned; otherwise, false.
            /// </returns>

            protected bool IsPositioned
            {
                get { return !_isExhausted && null != _node; }
            }

            /// <summary>
            /// Gets the element at the current position of the enumerator.
            /// </summary>
            /// <returns>
            /// The KeyValuePair&lt;TKey, TValue&gt; in the AvlDictionary&lt;TKey,TValue&gt; at the current position of the enumerator.
            /// </returns>

            protected KeyValuePair<TKey, TValue> CurrentPair
            {
                get
                {
                    if (!_isExhausted && null != _node)
                    {
                        return _node.Pair;
                    }
                    return new KeyValuePair<TKey, TValue>(default(TKey), default(TValue));
                }
            }

            /// <summary>
            /// Gets the key at the current position of the enumerator.
            /// </summary>
            /// <returns>
            /// The key in the AvlDictionary&lt;TKey,TValue&gt;.KeyCollection at the current position of the enumerator.
            /// </returns>

            protected TKey CurrentKey
            {
                get
                {
                    if (!_isExhausted && null != _node)
                    {
                        return _node.Pair.Key;
                    }
                    return default(TKey);
                }
            }

            /// <summary>
            /// Gets the value at the current position of the enumerator.
            /// </summary>
            /// <returns>
            /// The value in the AvlDictionary&lt;TKey,TValue&gt;.ValueCollection at the current position of the enumerator.
            /// </returns>

            protected TValue CurrentValue
            {
                get
                {
                    if (!_isExhausted && null != _node)
                    {
                        return _node.Pair.Value;
                    }
                    return default(TValue);
                }
            }

            /// <summary>
            /// Advances the enumerator to the next element of the AvlDictionary&lt;TKey,TValue&gt;.
            /// </summary>
            /// <returns>
            /// true if the enumerator was successfully advanced to the next element; false
            //  if the enumerator has passed the end of the collection.
            /// </returns>
            /// <exception cref="System.InvalidOperationException">
            /// The AvlDictionary was modified after the enumerator was created.
            /// </exception>    
            public bool MoveNext()
            {
                if (_changeCounter != _avlDictionary._changeCounter)
                {
                    throw new InvalidOperationException("The AvlDictionary was modified after the enumerator was created.");
                }
                if (_isExhausted)
                {
                    return false;
                }
                if (null == _avlDictionary._rootNode)
                {
                    _isExhausted = true;
                    return false;
                }

                AvlTreeNode next = null == _node ? _avlDictionary._rootNode.PblTreeNodeFirst() : _node.PblTreeNodeNext();
                if (null == next)
                {
                    _isExhausted = true;
                    return false;
                }
                _node = next;

                return true;
            }

            /// <summary>
            /// Resets the enumerator of the AvlDictionary&lt;TKey,TValue&gt;.
            /// </summary>

            public void Reset()
            {
                _node = null;
                _isExhausted = _avlDictionary._rootNode == null;
            }

            #region IDisposable Member

            /// <summary>
            /// Disposes the enumerator of the AvlDictionary&lt;TKey,TValue&gt;.
            /// </summary>

            public void Dispose()
            {
            }

            #endregion
        }

        /// <summary>
        /// Enumerates the elements of an AvlDictionary&lt;TKey,TValue&gt;.
        /// </summary>
        public sealed class Enumerator : AvlDictionaryBaseEnumerator, IEnumerator<KeyValuePair<TKey, TValue>>
        {
            /// <summary>
            /// Creates a new enumerator of the AvlDictionary&lt;TKey,TValue&gt;.
            /// </summary>
            /// <param name="dictionary">
            /// The AvlDictionary&lt;TKey,TValue&gt; the enumerator is created for.
            /// </param>

            public Enumerator(AvlDictionary<TKey, TValue> dictionary)
                : base(dictionary)
            {
            }

            #region IEnumerator<KeyValuePair<TKey,TValue>> Member

            /// <summary>
            /// Gets the element at the current position of the enumerator.
            /// </summary>
            /// <returns>
            /// The KeyValuePair&lt;TKey, TValue&gt; in the AvlDictionary&lt;TKey,TValue&gt; at the current position of the enumerator.
            /// </returns>

            public KeyValuePair<TKey, TValue> Current
            {
                get { return CurrentPair; }
            }

            #endregion

            #region IEnumerator Member

            /// <summary>
            /// Gets the element at the current position of the enumerator.
            /// </summary>
            /// <returns>
            /// The KeyValuePair&lt;TKey, TValue&gt; in the AvlDictionary&lt;TKey,TValue&gt; at the current position of the enumerator.
            /// </returns>
            /// <exception cref="System.InvalidOperationException">
            /// The enumerator is not positioned.
            /// </exception>    

            object IEnumerator.Current
            {
                get
                {
                    if (!IsPositioned)
                    {
                        throw new InvalidOperationException("The enumerator is not positioned.");
                    }
                    return CurrentPair;
                }
            }

            #endregion
        }

        /// <summary>
        /// The actual AVL-tree code. It was lifted from the C implementation in pblSet.c.
        /// </summary>
        [Serializable]
        private sealed class AvlTreeNode
        {
            internal KeyValuePair<TKey, TValue> Pair;
            internal AvlTreeNode Prev;
            internal AvlTreeNode Next;
            internal AvlTreeNode Parent;
            private int _balance;

            private AvlTreeNode(KeyValuePair<TKey, TValue> pair)
            {
                Pair = pair;
                Prev = null;
                Next = null;
                Parent = null;
                _balance = 0;
            }

            /*
             * Returns the first node in the tree defined by the node.
             * 
             * @return AvlTreeNode node: The first node in the sub tree.
             */
            internal AvlTreeNode PblTreeNodeFirst()
            {
                AvlTreeNode node = this;
                while (node.Prev != null)
                {
                    node = node.Prev;
                }
                return node;
            }

            /*
             * Returns the next node after the node.
             *
             * @return AvlTreeNode node: The next node, may be null.
             */
            internal AvlTreeNode PblTreeNodeNext()
            {
                AvlTreeNode node = this;
                if (node.Next != null)
                {
                    return node.Next.PblTreeNodeFirst();
                }
                else
                {
                    AvlTreeNode child = node;

                    while ((node = node.Parent) != null)
                    {
                        if (child == node.Prev)
                        {
                            return node;
                        }
                        child = node;
                    }
                }

                return null;
            }

            /*
             * Methods for setting node pointers and maintaining the parentNode pointer
             */
            private void PblAvlTreeSetLeft(AvlTreeNode referenceNode)
            {
                if (Prev != referenceNode)
                {
                    if ((Prev = referenceNode) != null) { Prev.Parent = this; }
                }
            }

            private void PblAvlTreeSetRight(AvlTreeNode referenceNode)
            {
                if (Next != referenceNode)
                {
                    if ((Next = referenceNode) != null) { Next.Parent = this; }
                }
            }


            /*
             * Inserts a new tree node into a tree set
             *
             * @return AvlTreeNode retPtr != null: The subtree p after the insert.
             * @return AvlTreeNode retPtr == null: An error, see pbl_errno:
             *
             * <BR>PBL_ERROR_OUT_OF_MEMORY - Out of memory.
             */
            static internal AvlTreeNode PblTreeNodeInsert(
            AvlTreeNode parentNode,              /** The parent node node to insert to   */
            TKey key,                            /** The key to insert                   */
            TValue value,                        /** The value to insert                 */
            out int heightChanged,               /** Set if the tree height changed      */
            out AvlTreeNode node,                /** For returning the node added        */
            out bool nodeAdded                   /** Flag showing whether node was added */
            )
            {
                AvlTreeNode p1;
                AvlTreeNode p2;

                if (null == parentNode)
                {
                    /*
                     * Element is not in the tree yet, insert it.
                     */
                    heightChanged = 1;
                    node = new AvlTreeNode(new KeyValuePair<TKey, TValue>(key, value));
                    nodeAdded = true;
                    return node;
                }

                heightChanged = 0;
                nodeAdded = false;

                int compareResult = key.CompareTo(parentNode.Pair.Key);
                if (compareResult == 0)
                {
                    /*
                     * Element already in tree
                     */
                    node = parentNode;
                    return parentNode;
                }

                if (compareResult < 0)
                {
                    /*
                     * Insert into left sub tree
                     */
                    p1 = PblTreeNodeInsert(parentNode.Prev, key, value, out heightChanged, out node, out nodeAdded);

                    parentNode.PblAvlTreeSetLeft(p1);

                    if (0 == heightChanged)
                    {
                        return parentNode;
                    }

                    /*
                     * Left sub tree increased in height
                     */
                    if (parentNode._balance == 1)
                    {
                        parentNode._balance = 0;
                        heightChanged = 0;
                        return parentNode;
                    }

                    if (parentNode._balance == 0)
                    {
                        parentNode._balance = -1;
                        return parentNode;
                    }

                    /*
                     * Balancing needed
                     */
                    p1 = parentNode.Prev;

                    if (p1._balance == -1)
                    {
                        /*
                         * Simple LL rotation
                         */
                        parentNode.PblAvlTreeSetLeft(p1.Next);

                        p1.PblAvlTreeSetRight(parentNode);
                        parentNode._balance = 0;

                        parentNode = p1;
                        parentNode._balance = 0;
                        heightChanged = 0;
                        return parentNode;
                    }

                    /*
                     * double LR rotation
                     */
                    p2 = p1.Next;

                    p1.PblAvlTreeSetRight(p2.Prev);

                    p2.PblAvlTreeSetLeft(p1);

                    parentNode.PblAvlTreeSetLeft(p2.Next);

                    p2.PblAvlTreeSetRight(parentNode);

                    parentNode._balance = p2._balance == -1 ? 1 : 0;

                    if (p2._balance == 1)
                    {
                        p1._balance = -1;
                    }
                    else
                    {
                        p1._balance = 0;
                    }
                    parentNode = p2;
                    parentNode._balance = 0;
                    heightChanged = 0;
                    return parentNode;
                }

                /*
                 * Insert into right sub tree
                 */
                p1 = PblTreeNodeInsert(parentNode.Next, key, value, out heightChanged, out node, out nodeAdded);

                parentNode.PblAvlTreeSetRight(p1);

                if (0 == heightChanged)
                {
                    return parentNode;
                }

                /*
                 * Right sub tree increased in height
                 */
                if (parentNode._balance == -1)
                {
                    parentNode._balance = 0;
                    heightChanged = 0;
                    return parentNode;
                }

                if (parentNode._balance == 0)
                {
                    parentNode._balance = 1;
                    return parentNode;
                }

                /*
                 * Balancing needed
                 */
                p1 = parentNode.Next;

                if (p1._balance == 1)
                {
                    /*
                     * Simple RR rotation
                     */
                    parentNode.PblAvlTreeSetRight(p1.Prev);

                    p1.PblAvlTreeSetLeft(parentNode);
                    parentNode._balance = 0;

                    parentNode = p1;
                    parentNode._balance = 0;
                    heightChanged = 0;
                    return parentNode;
                }

                /*
                 * double RL rotation
                 */
                p2 = p1.Prev;

                p1.PblAvlTreeSetLeft(p2.Next);

                p2.PblAvlTreeSetRight(p1);

                parentNode.PblAvlTreeSetRight(p2.Prev);

                p2.PblAvlTreeSetLeft(parentNode);

                if (p2._balance == 1)
                {
                    parentNode._balance = -1;
                }
                else
                {
                    parentNode._balance = 0;
                }

                p1._balance = p2._balance == -1 ? 1 : 0;
                parentNode = p2;
                parentNode._balance = 0;
                heightChanged = 0;
                return parentNode;
            }


            /*
             * Balances an AVL tree.
             *
             * Used if left sub tree decreased in size.
             *
             * @return PblTreeNode * retPtr: The subtree p after the balance.
             *
             */
            private AvlTreeNode PblTreeNodeBalanceLeft(
            out int heightChanged                     /** Set if the tree height changed */
            )
            {
                heightChanged = 1;

                if (_balance == -1)
                {
                    _balance = 0;
                    return this;
                }

                if (_balance == 0)
                {
                    _balance = 1;
                    heightChanged = 0;
                    return this;
                }

                /*
                 * Balancing needed
                 */
                AvlTreeNode p1 = Next;
                int b1 = p1._balance;

                if (b1 >= 0)
                {
                    /*
                     * Simple RR rotation
                     */
                    PblAvlTreeSetRight(p1.Prev);

                    p1.PblAvlTreeSetLeft(this);

                    if (b1 == 0)
                    {
                        _balance = 1;
                        p1._balance = -1;
                        heightChanged = 0;
                    }
                    else
                    {
                        _balance = 0;
                        p1._balance = 0;
                    }
                    return p1;
                }

                /*
                 * double RL rotation
                 */
                AvlTreeNode p2 = p1.Prev;
                int b2 = p2._balance;

                p1.PblAvlTreeSetLeft(p2.Next);

                p2.PblAvlTreeSetRight(p1);

                PblAvlTreeSetRight(p2.Prev);

                p2.PblAvlTreeSetLeft(this);

                if (b2 == 1)
                {
                    _balance = -1;
                }
                else
                {
                    _balance = 0;
                }

                p1._balance = b2 == -1 ? 1 : 0;

                p2._balance = 0;
                return p2;
            }

            /*
             * Balances an AVL tree.
             *
             * Used if right sub tree decreased in size.
             *
             * @return PblTreeNode * retPtr: The subtree p after the balance.
             *
             */
            private AvlTreeNode PblTreeNodeBalanceRight(
            out int heightChanged                     /** Set if the tree height changed */
            )
            {
                heightChanged = 1;

                if (_balance == 1)
                {
                    _balance = 0;
                    return this;
                }

                if (_balance == 0)
                {
                    _balance = -1;
                    heightChanged = 0;
                    return this;
                }

                /*
                 * Balancing needed
                 */
                AvlTreeNode p1 = Prev;
                int b1 = p1._balance;

                if (b1 <= 0)
                {
                    /*
                     * Simple LL rotation
                     */
                    PblAvlTreeSetLeft(p1.Next);

                    p1.PblAvlTreeSetRight(this);

                    if (b1 == 0)
                    {
                        _balance = -1;
                        p1._balance = 1;
                        heightChanged = 0;
                    }
                    else
                    {
                        _balance = 0;
                        p1._balance = 0;
                    }
                    return p1;
                }

                /*
                 * double LR rotation
                 */
                AvlTreeNode p2 = p1.Next;
                int b2 = p2._balance;

                p1.PblAvlTreeSetRight(p2.Prev);

                p2.PblAvlTreeSetLeft(p1);

                PblAvlTreeSetLeft(p2.Next);

                p2.PblAvlTreeSetRight(this);

                _balance = b2 == -1 ? 1 : 0;

                if (b2 == 1)
                {
                    p1._balance = -1;
                }
                else
                {
                    p1._balance = 0;
                }

                p2._balance = 0;
                return p2;
            }

            /*
             * Helper function for AVL tree remove.
             *
             * @return PblTreeNode * retPtr: The subtree p after the remove.
             */
            private AvlTreeNode PblTreeNodeRemove2(
            AvlTreeNode q,
            out int heightChanged,
            out bool nodeRemoved
            )
            {
                AvlTreeNode r = this;
                AvlTreeNode p;

                if (null != r.Next)
                {
                    p = r.Next.PblTreeNodeRemove2(q, out heightChanged, out nodeRemoved);
                    r.PblAvlTreeSetRight(p);
                    if (0 != heightChanged)
                    {
                        r = r.PblTreeNodeBalanceRight(out heightChanged);
                    }
                    return r;
                }

                q.Pair = r.Pair;
                p = r.Prev;

                heightChanged = 1;
                nodeRemoved = true;

                return p;
            }


            /*
             * Removes a tree node from a tree set
             *
             * @return PblTreeNode * retPtr: The subtree p after the remove.
             */
            internal AvlTreeNode PblTreeNodeRemove(
            TKey key,                               /** The element to remove            */
            out int heightChanged,               /** Set if the tree height changed   */
            out bool nodeRemoved                 /** Showing whether node was removed */
            )
            {
                AvlTreeNode p = this;
                AvlTreeNode q = null;

                heightChanged = 0;
                nodeRemoved = false;

                int compareResult = key.CompareTo(p.Pair.Key);

                if (compareResult < 0)
                {
                    if (null != p.Prev)
                    {
                        q = p.Prev.PblTreeNodeRemove(key, out heightChanged, out nodeRemoved);
                    }
                    p.PblAvlTreeSetLeft(q);

                    if (0 != heightChanged)
                    {
                        p = p.PblTreeNodeBalanceLeft(out heightChanged);
                    }
                    return p;
                }

                if (compareResult > 0)
                {
                    if (null != p.Next)
                    {
                        q = p.Next.PblTreeNodeRemove(key, out heightChanged, out nodeRemoved);
                    }
                    p.PblAvlTreeSetRight(q);

                    if (0 != heightChanged)
                    {
                        p = p.PblTreeNodeBalanceRight(out heightChanged);
                    }
                    return p;
                }

                /*
                 * p is the node that needs to be removed!
                 */
                q = p;

                if (null == q.Next)
                {
                    p = q.Prev;
                    heightChanged = 1;

                    nodeRemoved = true;
                }
                else if (null == q.Prev)
                {
                    p = q.Next;
                    heightChanged = 1;

                    nodeRemoved = true;
                }
                else
                {
                    /*
                     * Replace q with is biggest predecessor and remove that
                     */
                    AvlTreeNode p1 = q.Prev.PblTreeNodeRemove2(q, out heightChanged, out nodeRemoved);
                    q.PblAvlTreeSetLeft(p1);

                    if (0 != heightChanged)
                    {
                        p = p.PblTreeNodeBalanceLeft(out heightChanged);
                    }
                }

                return p;
            }
        }

        /// <summary>
        /// Represents the collection of keys in an AvlDictionary&lt;TKey,TValue&gt;. 
        /// This class cannot be inherited.
        /// </summary>
        [Serializable]
        public sealed class KeyCollection : ICollection<TKey>, ICollection
        {
            /// <summary>
            /// Enumerates the elements of an AvlDictionary&lt;TKey,TValue&gt;.KeyCollection. 
            /// This class cannot be inherited.
            /// </summary>

            public sealed class CollectionEnumerator : AvlDictionaryBaseEnumerator, IEnumerator<TKey>
            {
                /// <summary>
                /// Creates a new enumerator of the AvlDictionary&lt;TKey,TValue&gt;.KeyCollection.
                /// </summary>
                /// <param name="dictionary">
                /// The AvlDictionary&lt;TKey,TValue&gt; the enumerator is created for.
                /// </param>

                public CollectionEnumerator(AvlDictionary<TKey, TValue> dictionary)
                    : base(dictionary)
                {
                }

                #region IEnumerator<TKey> Member

                /// <summary>
                /// Gets the key at the current position of the enumerator.
                /// </summary>
                /// <returns>
                /// The key in the AvlDictionary&lt;TKey,TValue&gt;.KeyCollection at the current position of the enumerator.
                /// </returns>

                public TKey Current
                {
                    get
                    {
                        return CurrentKey;
                    }
                }

                #endregion


                #region IEnumerator Member

                /// <summary>
                /// Gets the key at the current position of the enumerator.
                /// </summary>
                /// <returns>
                /// The key in the AvlDictionary&lt;TKey,TValue&gt;.KeyCollection at the current position of the enumerator.
                /// </returns>

                object IEnumerator.Current
                {
                    get
                    {
                        return CurrentKey;
                    }
                }

                #endregion
            }

            private readonly AvlDictionary<TKey, TValue> _avlDictionary;

            internal KeyCollection(AvlDictionary<TKey, TValue> avlDictionary)
            {
                _avlDictionary = avlDictionary;
            }

            #region ICollection<TKey> Member

            /// <summary>
            /// Because the KeyCollection is read only, this method always throws a System.NotSupportedException.
            /// </summary>
            /// <exception cref="System.NotSupportedException">
            /// The AvlDictionary.KeyCollection is read-only.
            /// </exception>    

            public void Add(TKey item)
            {
                throw new NotSupportedException("The AvlDictionary.KeyCollection is read-only.");
            }

            /// <summary>
            /// Because the KeyCollection is read only, this method always throws a System.NotSupportedException.
            /// </summary>
            /// <exception cref="System.NotSupportedException">
            /// The AvlDictionary.KeyCollection is read-only.
            /// </exception>    

            public void Clear()
            {
                throw new NotSupportedException("The AvlDictionary.KeyCollection is read-only.");
            }

            /// <summary>
            /// Determines whether the AvlDictionary.KeyCollection contains a specific item.
            /// </summary>
            /// <param name="item">
            /// The TKey to locate in the AvlDictionary.KeyCollection.
            /// </param>
            /// <remarks>
            /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.KeyCollection.
            /// </remarks>
            /// <returns>
            /// true if item is found in the AvlDictionary.KeyCollection; otherwise, false.
            /// </returns>

            public bool Contains(TKey item)
            {
                return _avlDictionary.ContainsKey(item);
            }

            /// <summary>
            /// Copies the elements of the AvlDictionary.KeyCollection to an existing 
            /// one-dimensional TKey[], starting at the specified array index.
            /// </summary>
            /// <param name="array">
            /// The one-dimensional TKey[] that is the destination of the elements
            /// copied from AvlDictionary.KeyCollection.
            /// The array must have zero-based indexing.
            /// </param>
            /// <param name="index">
            /// The zero-based index in array at which copying begins.
            /// </param>
            /// <exception cref="System.ArgumentNullException">
            /// array is null.
            /// </exception>    
            /// <exception cref="System.ArgumentOutOfRangeException">
            /// index is less than zero.
            /// </exception>    
            /// <exception cref="System.ArgumentException">
            /// index is equal to or greater than the length of array.  -or- The number of
            /// elements in the source AvlDictionary.KeyCollection
            /// is greater than the available space from index to the end of the destination
            /// array.
            /// </exception>    

            public void CopyTo(TKey[] array, int index)
            {
                if (array == null)
                {
                    throw new ArgumentNullException("array");
                }
                if (index < 0)
                {
                    throw new ArgumentOutOfRangeException("index", "index is less than zero.");
                }
                if (index >= array.Length)
                {
                    throw new ArgumentException("index is equal to or greater than the length of array.");
                }

                if (_avlDictionary.Size == 0)
                {
                    return;
                }

                if (index + _avlDictionary.Size > array.Length)
                {
                    throw new ArgumentException("number of elements in the source AvlDictionary.KeyCollection is greater than the available space from index to the end of the destination array.");
                }

                IEnumerator<TKey> en = GetEnumerator();
                for (int i = 0; en.MoveNext(); i++)
                {
                    array[i + index] = en.Current;
                }
            }

            /// <summary>
            /// Gets the number of elements contained in the AvlDictionary.
            /// </summary>
            /// <returns>
            /// The number of elements contained in the AvlDictionary.
            /// Retrieving the value of this property is an O(1) operation.
            /// </returns>

            public int Count
            {
                get { return _avlDictionary.Count; }
            }

            /// <summary>
            /// Gets a value indicating whether the AvlDictionary.KeyCollection is read-only.
            /// </summary>
            /// <returns>
            /// true.
            /// </returns>

            public bool IsReadOnly
            {
                get { return true; }
            }

            /// <summary>
            /// Because the KeyCollection is read only, this method always throws a System.NotSupportedException.
            /// </summary>
            /// <exception cref="System.NotSupportedException">
            /// The AvlDictionary.KeyCollection is read-only.
            /// </exception>    

            public bool Remove(TKey item)
            {
                throw new NotSupportedException("The AvlDictionary.KeyCollection is read-only.");
            }

            #endregion

            #region IEnumerable<TKey> Member

            /// <summary>
            /// Returns an enumerator that iterates through the AvlDictionary.KeyCollection.
            /// </summary>
            /// <returns>
            /// An IEnumerator&lt;TKey&gt; enumerator for the AvlDictionary.KeyCollection.
            /// </returns>

            public IEnumerator<TKey> GetEnumerator()
            {
                return new CollectionEnumerator(_avlDictionary);
            }

            #endregion

            #region IEnumerable Member

            /// <summary>
            /// Returns an enumerator that iterates through the AvlDictionary.KeyCollection.
            /// </summary>
            /// <returns>
            /// An IEnumerator&lt;TKey&gt; enumerator for the AvlDictionary.KeyCollection.
            /// </returns>

            IEnumerator IEnumerable.GetEnumerator()
            {
                return new CollectionEnumerator(_avlDictionary);
            }

            #endregion

            #region ICollection Member

            /// <summary>
            /// Copies the elements of the AvlDictionary.KeyCollection to an existing 
            /// one-dimensional Array, starting at the specified array index.
            /// </summary>
            /// <param name="array">
            /// The one-dimensional Array that is the destination of the elements
            /// copied from AvlDictionary.KeyCollection.
            /// The array must have zero-based indexing.
            /// </param>
            /// <param name="index">
            /// The zero-based index in array at which copying begins.
            /// </param>
            /// <exception cref="System.ArgumentNullException">
            /// array is null.
            /// </exception>    
            /// <exception cref="System.ArgumentOutOfRangeException">
            /// index is less than zero.
            /// </exception>    
            /// <exception cref="System.ArgumentException">
            /// index is equal to or greater than the length of array.  -or- The number of
            /// elements in the source AvlDictionary.KeyCollection
            /// is greater than the available space from index to the end of the destination
            /// array.
            /// </exception>    

            public void CopyTo(Array array, int index)
            {
                if (array == null)
                {
                    throw new ArgumentNullException("array");
                }
                if (index < 0)
                {
                    throw new ArgumentOutOfRangeException("index", "index is less than zero.");
                }
                if (index >= array.Length)
                {
                    throw new ArgumentException("index is equal to or greater than the length of array.");
                }

                if (Count == 0)
                {
                    return;
                }

                if (index + Count > array.Length)
                {
                    throw new ArgumentException("number of elements in the source AvlDictionary.KeyCollection is greater than the available space from index to the end of the destination array.");
                }

                IEnumerator<TKey> en = GetEnumerator();
                for (int i = 0; en.MoveNext(); i++)
                {
                    array.SetValue(en.Current, i + index);
                }
            }

            /// <summary>
            /// Gets a value indicating whether access to the AvlDictionary.KeyCollection is synchronized (thread safe).
            /// </summary>
            /// <returns>
            /// false.
            /// </returns>

            public bool IsSynchronized
            {
                get { return false; }
            }

            /// <summary>
            /// Gets an object that can be used to synchronize access to the AvlDictionary.
            /// </summary>
            /// <returns>
            /// An object that can be used to synchronize access to the AvlDictionary.
            /// </returns>

            public object SyncRoot
            {
                get { return _avlDictionary._lock; }
            }

            #endregion
        }

        /// <summary>
        /// Represents the collection of values in an AvlDictionary&lt;TKey,TValue&gt;. 
        /// This class cannot be inherited.
        /// </summary>
        [Serializable]
        public sealed class ValueCollection : ICollection<TValue>, ICollection
        {
            /// <summary>
            /// Enumerates the elements of an AvlDictionary&lt;TKey,TValue&gt;.ValueCollection. 
            /// This class cannot be inherited.
            /// </summary>
            public sealed class CollectionEnumerator : AvlDictionaryBaseEnumerator, IEnumerator<TValue>
            {
                /// <summary>
                /// Creates a new enumerator of the AvlDictionary&lt;TKey,TValue&gt;.ValueCollection.
                /// </summary>
                /// <param name="dictionary">
                /// The AvlDictionary&lt;TKey,TValue&gt; the enumerator is created for.
                /// </param>

                public CollectionEnumerator(AvlDictionary<TKey, TValue> dictionary)
                    : base(dictionary)
                {
                }

                #region IEnumerator<TKey> Member

                /// <summary>
                /// Gets the value at the current position of the enumerator.
                /// </summary>
                /// <returns>
                /// The value in the AvlDictionary&lt;TKey,TValue&gt;.ValueCollection at the current position of the enumerator.
                /// </returns>

                public TValue Current
                {
                    get
                    {
                        return CurrentValue;
                    }
                }

                #endregion

                #region IEnumerator Member

                /// <summary>
                /// Gets the value at the current position of the enumerator.
                /// </summary>
                /// <returns>
                /// The value in the AvlDictionary&lt;TKey,TValue&gt;.ValueCollection at the current position of the enumerator.
                /// </returns>

                object IEnumerator.Current
                {
                    get
                    {
                        return CurrentValue;
                    }
                }

                #endregion
            }

            private readonly AvlDictionary<TKey, TValue> _avlDictionary;

            internal ValueCollection(AvlDictionary<TKey, TValue> avlDictionary)
            {
                _avlDictionary = avlDictionary;
            }

            #region ICollection<TValue> Member

            /// <summary>
            /// Because the ValueCollection is read only, this method always throws a System.NotSupportedException.
            /// </summary>
            /// <exception cref="System.NotSupportedException">
            /// The AvlDictionary.ValueCollection is read-only.
            /// </exception>    

            public void Add(TValue item)
            {
                throw new NotSupportedException("The AvlDictionary.ValueCollection is read-only.");
            }

            /// <summary>
            /// Because the ValueCollection is read only, this method always throws a System.NotSupportedException.
            /// </summary>
            /// <exception cref="System.NotSupportedException">
            /// The AvlDictionary.ValueCollection is read-only.
            /// </exception>    

            public void Clear()
            {
                throw new NotSupportedException("The AvlDictionary.ValueCollection is read-only.");
            }

            /// <summary>
            /// Determines whether the AvlDictionary.ValueCollection contains a specific value.
            /// </summary>
            /// <param name="item">
            /// The TValue to locate in the AvlDictionary.ValueCollection.
            /// </param>
            /// <remarks>
            /// This method is an O(N) operation, where N is the number of elements in the AvlDictionary.ValueCollection.
            /// </remarks>
            /// <returns>
            /// true if item is found in the AvlDictionary.ValueCollection; otherwise, false.
            /// </returns>

            public bool Contains(TValue item)
            {
                if (_avlDictionary.Size == 0)
                {
                    return false;
                }

                if (item == null)
                {
                    for (IEnumerator<TValue> en = GetEnumerator(); en.MoveNext(); )
                    {
                        if (null == en.Current)
                        {
                            return true;
                        }
                    }
                }
                else
                {
                    for (IEnumerator<TValue> en = GetEnumerator(); en.MoveNext(); )
                    {
                        if (item.Equals(en.Current))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }

            /// <summary>
            /// Copies the elements of the AvlDictionary.ValueCollection to an existing 
            /// one-dimensional TValue[], starting at the specified array index.
            /// </summary>
            /// <param name="array">
            /// The one-dimensional TValue[] that is the destination of the elements
            /// copied from AvlDictionary.ValueCollection.
            /// The array must have zero-based indexing.
            /// </param>
            /// <param name="index">
            /// The zero-based index in array at which copying begins.
            /// </param>
            /// <exception cref="System.ArgumentNullException">
            /// array is null.
            /// </exception>    
            /// <exception cref="System.ArgumentOutOfRangeException">
            /// index is less than zero.
            /// </exception>    
            /// <exception cref="System.ArgumentException">
            /// index is equal to or greater than the length of array.  -or- The number of
            /// elements in the source AvlDictionary.ValueCollection
            /// is greater than the available space from index to the end of the destination
            /// array.
            /// </exception>    

            public void CopyTo(TValue[] array, int index)
            {
                if (array == null)
                {
                    throw new ArgumentNullException("array");
                }
                if (index < 0)
                {
                    throw new ArgumentOutOfRangeException("index", "index is less than zero.");
                }
                if (index >= array.Length)
                {
                    throw new ArgumentException("index is equal to or greater than the length of array.");
                }

                if (_avlDictionary.Size == 0)
                {
                    return;
                }

                if (index + _avlDictionary.Size > array.Length)
                {
                    throw new ArgumentException("number of elements in the source AvlDictionary.ValueCollection is greater than the available space from index to the end of the destination array.");
                }

                IEnumerator<TValue> en = GetEnumerator();
                for (int i = 0; en.MoveNext(); i++)
                {
                    array[i + index] = en.Current;
                }
            }

            /// <summary>
            /// Gets the number of elements contained in the AvlDictionary.
            /// </summary>
            /// <returns>
            /// The number of elements contained in the AvlDictionary.
            /// Retrieving the value of this property is an O(1) operation.
            /// </returns>

            public int Count
            {
                get { return _avlDictionary.Count; }
            }

            /// <summary>
            /// Gets a value indicating whether the AvlDictionary.ValueCollection is read-only.
            /// </summary>
            /// <returns>
            /// true.
            /// </returns>

            public bool IsReadOnly
            {
                get { return true; }
            }

            /// <summary>
            /// Because the ValueCollection is read only, this method always throws a System.NotSupportedException.
            /// </summary>
            /// <exception cref="System.NotSupportedException">
            /// The AvlDictionary.ValueCollection is read-only.
            /// </exception>    

            public bool Remove(TValue item)
            {
                throw new NotSupportedException("The AvlDictionary.ValueCollection is read-only.");
            }

            #endregion

            #region IEnumerable<TValue> Member

            /// <summary>
            /// Returns an enumerator that iterates through the AvlDictionary.ValueCollection.
            /// </summary>
            /// <returns>
            /// An IEnumerator&lt;TValue&gt; enumerator for the AvlDictionary.ValueCollection.
            /// </returns>

            public IEnumerator<TValue> GetEnumerator()
            {
                return new CollectionEnumerator(_avlDictionary);
            }

            #endregion

            #region IEnumerable Member

            /// <summary>
            /// Returns an enumerator that iterates through the AvlDictionary.ValueCollection.
            /// </summary>
            /// <returns>
            /// An IEnumerator&lt;TValue&gt; enumerator for the AvlDictionary.ValueCollection.
            /// </returns>

            IEnumerator IEnumerable.GetEnumerator()
            {
                return new CollectionEnumerator(_avlDictionary);
            }

            #endregion

            #region ICollection Member

            /// <summary>
            /// Copies the elements of the AvlDictionary.ValueCollection to an existing 
            /// one-dimensional Array, starting at the specified array index.
            /// </summary>
            /// <param name="array">
            /// The one-dimensional Array that is the destination of the elements
            /// copied from AvlDictionary.ValueCollection.
            /// The array must have zero-based indexing.
            /// </param>
            /// <param name="index">
            /// The zero-based index in array at which copying begins.
            /// </param>
            /// <exception cref="System.ArgumentNullException">
            /// array is null.
            /// </exception>    
            /// <exception cref="System.ArgumentOutOfRangeException">
            /// index is less than zero.
            /// </exception>    
            /// <exception cref="System.ArgumentException">
            /// index is equal to or greater than the length of array.  -or- The number of
            /// elements in the source AvlDictionary.ValueCollection
            /// is greater than the available space from index to the end of the destination
            /// array.
            /// </exception>    

            public void CopyTo(Array array, int index)
            {
                if (array == null)
                {
                    throw new ArgumentNullException("array");
                }
                if (index < 0)
                {
                    throw new ArgumentOutOfRangeException("index", "index is less than zero.");
                }
                if (index >= array.Length)
                {
                    throw new ArgumentException("index is equal to or greater than the length of array.");
                }

                if (Count == 0)
                {
                    return;
                }

                if (index + Count > array.Length)
                {
                    throw new ArgumentException("number of elements in the source AvlDictionary.ValueCollection is greater than the available space from index to the end of the destination array.");
                }

                IEnumerator<TValue> en = GetEnumerator();
                for (int i = 0; en.MoveNext(); i++)
                {
                    array.SetValue(en.Current, i + index);
                }
            }

            /// <summary>
            /// Gets a value indicating whether access to the AvlDictionary.ValueCollection is synchronized (thread safe).
            /// </summary>
            /// <returns>
            /// false.
            /// </returns>

            public bool IsSynchronized
            {
                get { return false; }
            }

            /// <summary>
            /// Gets an object that can be used to synchronize access to the AvlDictionary.
            /// </summary>
            /// <returns>
            /// An object that can be used to synchronize access to the AvlDictionary.
            /// </returns>

            public object SyncRoot
            {
                get { return _avlDictionary._lock; }
            }

            #endregion
        }

        private AvlTreeNode _rootNode;

        private long _changeCounter;

        private readonly object _lock;

        private int Size { get; set; }

        private readonly KeyCollection _keys;

        private readonly ValueCollection _values;

        private AvlTreeNode FindNode(TKey key)
        {
            if (Size == 0)
            {
                return null;
            }

            AvlTreeNode node = _rootNode;

            while (node != null)
            {
                int compareResult = key.CompareTo(node.Pair.Key);
                if (compareResult == 0)
                {
                    return node;
                }

                node = compareResult < 0 ? node.Prev : node.Next;
            }
            return null;
        }

        private AvlTreeNode AddNode(TKey key, TValue value, out bool nodeAdded)
        {
            if (key == null)
            {
                throw new ArgumentNullException("key");
            }

            if (IsReadOnly)
            {
                throw new NotSupportedException("The AvlDictionary is read-only.");
            }

            int heightChanged;
            AvlTreeNode node;

            AvlTreeNode insertResult = AvlTreeNode.PblTreeNodeInsert(_rootNode, key, value, out heightChanged, out node, out nodeAdded);
            if (!nodeAdded)
            {
                return node;
            }

            Size += 1;
            _changeCounter++;

            /*
             * Remember the tree after the insert
             */
            insertResult.Parent = null;
            _rootNode = insertResult;
            return node;
        }

        /// <summary>
        /// Initializes a new instance of the AvlDictionary&lt;TKey,TValue&gt; class that is empty.
        /// </summary>
        public AvlDictionary()
        {
            _changeCounter = 0;
            _lock = new object();
            _keys = new KeyCollection(this);
            _values = new ValueCollection(this);
        }

        /// <summary>
        /// Initializes a new instance of the AvlDictionary&lt;TKey,TValue&gt;
        /// class that contains elements copied from the specified System.Collections.Generic.IDictionary&lt;TKey,TValue&gt;.
        /// </summary>
        /// <param name="dictionary">
        /// The System.Collections.Generic.IDictionary&lt;TKey,TValue&gt; whose elements are
        /// copied to the new AvlDictionary&lt;TKey,TValue&gt;.
        /// </param>
        /// <remarks>
        /// This method is an O(N * log N) operation, where N is dictionary.Count.
        /// </remarks>
        /// <exception cref="System.ArgumentNullException">
        /// dictionary is null.
        /// </exception>       
        /// <exception cref="System.ArgumentException">
        /// dictionary contains one or more duplicate keys.
        /// </exception>       
        public AvlDictionary(IEnumerable<KeyValuePair<TKey, TValue>> dictionary)
            : this()
        {
            if (null == dictionary)
            {
                throw new ArgumentNullException("dictionary");
            }

            for (IEnumerator<KeyValuePair<TKey, TValue>> en = dictionary.GetEnumerator(); en.MoveNext(); )
            {
                Add(en.Current);
            }
        }

        #region IDictionary<TKey,TValue> Member

        /// <summary>
        /// Adds the specified key and value to the AvlDictionary.
        /// </summary>
        /// <param name="key">
        /// The key of the element to add.
        /// </param>
        /// <param name="value">
        /// The value of the element to add. The value can be null for reference types.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <exception cref="System.ArgumentNullException">
        /// key is null.
        /// </exception>       
        /// <exception cref="System.ArgumentException">
        /// An element with the same key already exists in the AvlDictionary.
        /// </exception>       
        public void Add(TKey key, TValue value)
        {
            bool nodeAdded;
            AddNode(key, value, out nodeAdded);
            if (!nodeAdded)
            {
                throw new ArgumentException(string.Format("An element with the same key '{0}' already exists in the AvlDictionary.", key));
            }
        }

        /// <summary>
        /// Determines whether the AvlDictionary contains the specified key.
        /// </summary>
        /// <param name="key">
        /// The key to locate in the AvlDictionary.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <returns>
        /// true if the AvlDictionary contains an element with the specified key; otherwise, false.
        /// </returns>
        /// <exception cref="System.ArgumentNullException">
        /// key is null.
        /// </exception>    
        public bool ContainsKey(TKey key)
        {
            return FindNode(key) != null;
        }

        /// <summary>
        /// Gets a collection containing the keys in the AvlDictionary.
        /// </summary>
        /// <returns>
        /// An ICollection&lt;TKey&gt; containing the keys in the AvlDictionary.
        /// </returns>

        public ICollection<TKey> Keys
        {
            get { return _keys; }
        }

        /// <summary>
        /// Removes the value with the specified key from the AvlDictionary.
        /// </summary>
        /// <param name="key">
        /// The key of the element to remove.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <returns>
        /// true if the element is successfully found and removed; otherwise, false.
        /// This method returns false if key is not found in the AvlDictionary.
        /// </returns>
        /// <exception cref="System.ArgumentNullException">
        /// key is null.
        /// </exception>    
        /// <exception cref="System.NotSupportedException">
        /// "The AvlDictionary is read-only."
        /// </exception>    
        public bool Remove(TKey key)
        {
            if (key == null)
            {
                throw new ArgumentNullException("key");
            }

            if (IsReadOnly)
            {
                throw new NotSupportedException("The AvlDictionary is read-only.");
            }

            if (null == _rootNode)
            {
                return false;
            }

            int heightChanged;
            bool nodeRemoved;

            AvlTreeNode removeResult = _rootNode.PblTreeNodeRemove(key, out heightChanged, out nodeRemoved);
            if (nodeRemoved)
            {
                Size -= 1;
                _changeCounter++;

                /*
                 * Remember the tree after the removal
                 */
                if (removeResult != null)
                {
                    removeResult.Parent = null;
                }
                _rootNode = removeResult;
            }

            return nodeRemoved;
        }

        /// <summary>
        /// Gets the value associated with the specified key.
        /// </summary>
        /// <param name="key">
        /// The key of the value to get.
        /// </param>
        /// <param name="value">
        /// When this method returns, contains the value associated with the specified
        /// key, if the key is found; otherwise, the default value for the type of the
        /// value parameter. This parameter is passed uninitialized.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <returns>
        /// true if the AvlDictionary contains an
        /// element with the specified key; otherwise, false.
        /// </returns>
        /// <exception cref="System.ArgumentNullException">
        /// key is null.
        /// </exception>    
        public bool TryGetValue(TKey key, out TValue value)
        {
            if (key == null)
            {
                throw new ArgumentNullException("key");
            }

            AvlTreeNode node = FindNode(key);
            if (node == null)
            {
                value = default(TValue);
                return false;
            }

            value = node.Pair.Value;
            return true;
        }

        /// <summary>
        /// Gets a collection containing the values in the AvlDictionary.
        /// </summary>
        /// <returns>
        /// An ICollection&lt;TValue&gt; containing the values in the AvlDictionary.
        /// </returns>
        public ICollection<TValue> Values
        {
            get { return _values; }
        }

        /// <summary>
        /// Gets or sets the value associated with the specified key.
        /// </summary>
        /// <param name="key">
        /// The key of the value to get or set.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <returns>
        /// The value associated with the specified key. If the specified key is not
        /// found, a get operation throws a System.Collections.Generic.KeyNotFoundException,
        /// and a set operation creates a new element with the specified key.
        /// </returns>
        /// <exception cref="System.ArgumentNullException">
        /// key is null.
        /// </exception>    
        /// <exception cref="System.Collections.Generic.KeyNotFoundException">
        /// The property is retrieved and key does not exist in the collection.
        /// </exception>    
        /// <exception cref="NotSupportedException">
        /// The property is set and the AvlDictionary is read-only.
        /// </exception>    
        public TValue this[TKey key]
        {
            get
            {
                TValue value;
                if (TryGetValue(key, out value))
                {
                    return value;
                }
                throw new KeyNotFoundException("key does not exist in the collection.");
            }
            set
            {
                if (IsReadOnly)
                {
                    throw new NotSupportedException("The AvlDictionary is read-only.");
                }

                bool nodeAdded;
                AvlTreeNode node = AddNode(key, value, out nodeAdded);
                if (!nodeAdded)
                {
                    if (null == value)
                    {
                        if (null != node.Pair.Value)
                        {
                            node.Pair = new KeyValuePair<TKey, TValue>(key, value);
                        }
                    }
                    else
                    {
                        if (!value.Equals(node.Pair.Value))
                        {
                            node.Pair = new KeyValuePair<TKey, TValue>(key, value);
                        }
                    }
                }
            }
        }

        #endregion

        #region ICollection<KeyValuePair<TKey,TValue>> Member

        /// <summary>
        /// Adds a KeyValuePair&lt;TKey,TValue&gt; to the AvlDictionary.
        /// </summary>
        /// <param name="item">
        /// The KeyValuePair&lt;TKey,TValue&gt; to add to the AvlDictionary.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <exception cref="System.NotSupportedException">
        /// The AvlDictionary is read-only.
        /// </exception>    
        /// <exception cref="System.ArgumentException">
        /// An element with the same key already exists in the AvlDictionary.
        /// </exception>    
        public void Add(KeyValuePair<TKey, TValue> item)
        {
            bool nodeAdded;
            AvlTreeNode node = AddNode(item.Key, item.Value, out nodeAdded);
            if (!nodeAdded)
            {
                throw new ArgumentException(string.Format("An element with the same key '{0}' already exists in the AvlDictionary.", item.Key));
            }
            node.Pair = item;
        }

        /// <summary>
        /// Removes all keys and values from the AvlDictionary.
        /// </summary>
        /// <exception cref="System.NotSupportedException">
        /// The AvlDictionary is read-only.
        /// </exception>    
        public void Clear()
        {
            if (IsReadOnly)
            {
                throw new NotSupportedException("The AvlDictionary is read-only.");
            }

            _rootNode = null;
            Size = 0;
        }

        /// <summary>
        /// Determines whether the AvlDictionary contains a specific KeyValuePair&lt;TKey,TValue&gt;.
        /// </summary>
        /// <param name="item">
        /// The KeyValuePair&lt;TKey,TValue&gt; to locate in the AvlDictionary.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <returns>
        /// true if item is found in the AvlDictionary; otherwise, false.
        /// </returns>
        public bool Contains(KeyValuePair<TKey, TValue> item)
        {
            AvlTreeNode node = FindNode(item.Key);
            if (node == null)
            {
                return false;
            }
            return item.Equals(node.Pair);
        }

        /// <summary>
        /// Copies the elements of the AvlDictionary to an existing 
        /// one-dimensional KeyValuePair&lt;TKey,TValue&gt;[], starting at the specified array index.
        /// </summary>
        /// <param name="array">
        /// The one-dimensional KeyValuePair&lt;TKey,TValue&gt;[] that is the destination of the elements
        /// copied from AvlDictionary.
        /// The array must have zero-based indexing.
        /// </param>
        /// <param name="index">
        /// The zero-based index in array at which copying begins.
        /// </param>
        /// <exception cref="System.ArgumentNullException">
        /// array is null.
        /// </exception>    
        /// <exception cref="System.ArgumentOutOfRangeException">
        /// index is less than zero.
        /// </exception>    
        /// <exception cref="System.ArgumentException">
        /// index is equal to or greater than the length of array.  -or- The number of
        /// elements in the source AvlDictionary
        /// is greater than the available space from index to the end of the destination
        /// array.
        /// </exception>    
        public void CopyTo(KeyValuePair<TKey, TValue>[] array, int index)
        {
            if (array == null)
            {
                throw new ArgumentNullException("array");
            }
            if (index < 0)
            {
                throw new ArgumentOutOfRangeException("index", "index is less than zero.");
            }
            if (index >= array.Length)
            {
                throw new ArgumentException("index is equal to or greater than the length of array.");
            }

            if (Size == 0)
            {
                return;
            }

            if (index + Size > array.Length)
            {
                throw new ArgumentException("number of elements in the source AvlDictionary is greater than the available space from index to the end of the destination array.");
            }

            IEnumerator<KeyValuePair<TKey, TValue>> en = GetEnumerator();
            for (int i = 0; en.MoveNext(); i++)
            {
                array[i + index] = en.Current;
            }
        }

        /// <summary>
        /// Gets the number of elements contained in the AvlDictionary.
        /// </summary>
        /// <returns>
        /// The number of elements contained in the AvlDictionary.
        /// Retrieving the value of this property is an O(1) operation.
        /// </returns>
        public int Count
        {
            get { return Size; }
        }

        /// <summary>
        /// Gets a value indicating whether the AvlDictionary is read-only.
        /// </summary>
        /// <returns>
        /// false.
        /// </returns>
        public bool IsReadOnly
        {
            get { return false; }
        }

        /// <summary>
        /// Removes the first occurrence of a specific KeyValuePair&lt;TKey,TValue&gt; from the AvlDictionary.
        /// </summary>
        /// <param name="item">
        /// The KeyValuePair&lt;TKey,TValue&gt; to remove from the AvlDictionary.
        /// </param>
        /// <remarks>
        /// This method is an O(log N) operation, where N is the number of elements in the AvlDictionary.
        /// </remarks>
        /// <returns>
        /// true if item was successfully removed from the AvlDictionary;
        /// otherwise, false. This method also returns false if item is not found in
        /// the original AvlDictionary.
        /// </returns>
        /// <exception cref="System.NotSupportedException">
        /// The AvlDictionary is read-only.
        /// </exception>    
        public bool Remove(KeyValuePair<TKey, TValue> item)
        {
            if (IsReadOnly)
            {
                throw new NotSupportedException("The AvlDictionary is read-only.");
            }

            AvlTreeNode node = FindNode(item.Key);
            if (node == null)
            {
                return false;
            }
            if (item.Equals(node.Pair))
            {
                Remove(item.Key);
                return true;
            }
            return false;
        }

        #endregion

        #region IEnumerable<KeyValuePair<TKey,TValue>> Member

        /// <summary>
        /// Returns an enumerator that iterates through the AvlDictionary.
        /// </summary>
        /// <returns>
        /// An IEnumerator&lt;KeyValuePair&lt;TKey, TValue&gt;&gt; enumerator for the AvlDictionary.
        /// </returns>
        public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator()
        {
            return new Enumerator(this);
        }

        #endregion

        #region IEnumerable Member

        /// <summary>
        /// Returns an enumerator that iterates through the AvlDictionary.
        /// </summary>
        /// <returns>
        /// An IEnumerator enumerator for the AvlDictionary.
        /// </returns>
        IEnumerator IEnumerable.GetEnumerator()
        {
            return new Enumerator(this);
        }

        #endregion

        #region ICollection Member

        /// <summary>
        /// Copies the elements of the elements of the AvlDictionary to an System.Array, starting at a particular System.Array index.
        /// </summary>
        /// <param name="array">
        /// The one-dimensional System.Array that is the destination of the elements
        /// copied from AvlDictionary. The System.Array must have zero-based
        /// indexing.
        /// </param>
        /// <param name="index">
        /// The zero-based index in array at which copying begins.
        /// </param>
        /// <exception cref="System.ArgumentNullException">
        /// array is null.
        /// </exception>    
        /// <exception cref="System.ArgumentOutOfRangeException">
        /// index is less than zero.
        /// </exception>    
        /// <exception cref="System.ArgumentException">
        /// array is multidimensional.  -or- index is equal to or greater than the length
        /// of array.  -or- The number of elements in the source AvlDictionary
        /// is greater than the available space from index to the end of the destination
        /// array.
        /// </exception>    
        public void CopyTo(Array array, int index)
        {
            if (array == null)
            {
                throw new ArgumentNullException("array");
            }
            if (index < 0)
            {
                throw new ArgumentOutOfRangeException("index", "index is less than zero.");
            }
            if (index >= array.Length)
            {
                throw new ArgumentException("index is equal to or greater than the length of array.");
            }

            if (Size == 0)
            {
                return;
            }

            if (index + Size > array.Length)
            {
                throw new ArgumentException("number of elements in the source AvlDictionary is greater than the available space from index to the end of the destination array.");
            }

            IEnumerator<KeyValuePair<TKey, TValue>> en = GetEnumerator();
            for (int i = 0; en.MoveNext(); i++)
            {
                array.SetValue(en.Current, i + index);
            }
        }

        /// <summary>
        /// Gets a value indicating whether access to the AvlDictionary is synchronized (thread safe).
        /// </summary>
        /// <returns>
        /// false.
        /// </returns>
        public bool IsSynchronized
        {
            get { return false; }
        }

        /// <summary>
        /// Gets an object that can be used to synchronize access to the AvlDictionary.
        /// </summary>
        /// <returns>
        /// An object that can be used to synchronize access to the AvlDictionary.
        /// </returns>
        public object SyncRoot
        {
            get { return _lock; }
        }

        #endregion
    }
}
