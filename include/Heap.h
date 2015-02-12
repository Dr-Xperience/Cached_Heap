/****************************************************************************
    Cached_Heap (Linked List implementation of heap with array cache)
    Copyright (C) 2014  Anubhav Arun <dr.xperience@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*****************************************************************************/

#ifndef HEAP_H
#define HEAP_H

#include <list>
#include <iostream>
template <class T,class S=long long>
class Heap
{
    public:
        Heap();
        virtual ~Heap();

        //Accessor

        long long size();

        //Mutator

//        void incrementTotalIndex();

        //Abstract Member Functions

        virtual int pushBack(T value, S compareValue)=0;
        virtual T pop()=0;
        virtual T peek()=0;
        virtual void printHeap()=0;

    protected:

        class Node
        {
        public :
            long long mIndex;
            S mCompareValue;
            T mValue;
            Node *mLeft_Child;
            Node *mRight_Child;
            Node *mParent;

            Node(long long mIndex, T value, S compareValue);
        }*mRoot,*mTempNode,*mCurrNode;

        struct CacheNodeStructure
        {
            int index;
            Node *node;
            Node *left_child;
            Node *right_child;
        }cacheNode;

        std::list<CacheNodeStructure> cache;
        long long mTotalIndex;
    private:

};
#endif // HEAP_H
//#include "Heap.cpp"
