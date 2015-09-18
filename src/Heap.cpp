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

#include "Heap.h"

template <class T,class S>
Heap<T,S>::Heap()
{
    //ctor
//    T x,y;
//    Node *a= new Node(x,y);
    mRoot=NULL;
    mTempNode=NULL;
    mCurrNode=NULL;
    mTotalIndex=0;
}

template <class T,class S>
Heap<T,S>::~Heap()
{
    //dtor
}

//Inner Class Constructor

template <class T,class S>
Heap<T,S>::Node::Node(long long index,T value, S compareValue)
{
mLeft_Child=NULL;
mRight_Child=NULL;
this->mParent=nullptr;
this->mIndex=index;
this->mValue=value;
this->mCompareValue=compareValue;
}

//Accessor
template<class T, class S>
long long Heap<T,S>::size()
{
    return mTotalIndex;
}

//Mutators
//template<class T, class S>
//void Heap<T,S>::incrementTotalIndex()
//{
//    ++mTotalIndex;
//}
