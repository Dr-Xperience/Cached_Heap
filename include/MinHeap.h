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

#ifndef MINHEAP_H
#define MINHEAP_H

#include "Heap.h"

#include <iostream>
#include <stack>

template <class T, class S = long long>
class MinHeap : public Heap<T,S>
{
    public:
        MinHeap();
        MinHeap(T value, S compareValue);
        virtual ~MinHeap();

        //Defination of the Abstract Member Functions

        virtual int pushBack(T value, S compareValue);
        virtual T pop();
        virtual T peek();
        virtual void printHeap();

    protected:
        int rearrangeHeap(typename Heap<T,S>::Node *);
    private:
};

#endif // MINHEAP_H
//#include "MinHeap.cpp"
