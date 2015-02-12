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

#include "MinHeap.h"

#ifdef HEAP_CPP
#include "Heap.cpp"
#endif // HEAP_CPP

#include <cstdlib>
template <class T, class S>
MinHeap<T,S>::MinHeap()
{
    //ctor
}

template <class T, class S>
MinHeap<T,S>::MinHeap(T value,S compareValue)
{
    // parametrised constructor

    // instantiating root Node of MinHeap

    this->mRoot = new typename Heap<T,S>::Node(++this->mTotalIndex,value,compareValue);

    this->mTempNode=this->mRoot;
    //    std::cout<<" Root Assignment Time :: "<<this->mTempNode->mIndex<<" Pointer :: " ;
    //    std::cout<<this->mTempNode->mLeft_Child<<" "<<this->mTempNode->mRight_Child<<std::endl;

    //creating node for cache table;
    this->cacheNode.node=this->mRoot;
    this->cacheNode.left_child=this->mRoot->mLeft_Child;
    this->cacheNode.right_child=this->mRoot->mRight_Child;

    //pushing Root node to cache table;
    this->cache.push_back(this->cacheNode);
}

template <class T, class S>
MinHeap<T,S>::~MinHeap()
{
    //dtor
}

// Defination of Abstract Member Functions

template <class T,class S>
int MinHeap<T,S>::pushBack(T value, S compareValue)
{
    if(this->mRoot == NULL)
    {
        this->mRoot= new typename Heap<T,S>::Node(++this->mTotalIndex,value,compareValue);

        //        std::cout<<" Root Assignment Time Index:: "<<this->mTempNode->mIndex<<" Pointer :: " ;
        //        std::cout<<this->mTempNode->mLeft_Child<<" "<<this->mTempNode->mRight_Child<<std::endl;

        //creating node for cache table;

        this->cacheNode.node=this->mRoot;
        this->cacheNode.left_child=this->mRoot->mLeft_Child;
        this->cacheNode.right_child=this->mRoot->mRight_Child;

        //pushing Root node to cache table;
        this->cache.push_back(this->cacheNode);

    }
    else
    {
        this->mTempNode = new typename Heap<T,S>::Node(++this->mTotalIndex,value,compareValue);

        //        std::cout<<" Assignment Time Index:: "<<this->mTempNode->mIndex<<" Pointer :: " ;
        //        std::cout<<this->mTempNode->mLeft_Child<<" "<<this->mTempNode->mRight_Child<<std::endl;

        //creating node for cache table;

        this->cacheNode.node=this->mTempNode;
        this->cacheNode.left_child=this->mTempNode->mLeft_Child;
        this->cacheNode.right_child=this->mTempNode->mRight_Child;

        //pushing Node to cache table;

        this->cache.push_back(this->cacheNode);

        //adding node to heap

        for(typename std::list<typename Heap<T,S>::CacheNodeStructure>::iterator cacheIterator =  this->cache.begin(); cacheIterator != this->cache.end(); )
        {

            if((*cacheIterator).left_child==NULL)
            {
                (*cacheIterator).node->mLeft_Child=this->mTempNode;
                (*cacheIterator).left_child=this->mTempNode;
                this->mTempNode->mParent=(*cacheIterator).node;
                rearrangeHeap(this->mTempNode);
                break;

            }
            else if((*cacheIterator).right_child==NULL)
            {
                (*cacheIterator).node->mRight_Child=this->mTempNode;
                (*cacheIterator).right_child=this->mTempNode;
                this->mTempNode->mParent=(*cacheIterator).node;
                rearrangeHeap(this->mTempNode);
                break;
            }
            else
            {
                cacheIterator=this->cache.erase(cacheIterator);
                continue;
            }

            cacheIterator ++;
        }

    }

    return 0;
}

template <class T, class S>
T MinHeap<T,S>::pop()
{
    T returnValue;
    if(this->mRoot != NULL)
    {
        returnValue = this->mRoot->mValue;
        this->mTempNode = this->mRoot;
    }
    else
    {
        throw std::exception::exception("Heap is Empty");
        return NULL;
    }


    while(1)
    {
        if(this->mTempNode->mLeft_Child != NULL && this->mTempNode->mRight_Child != NULL)
        {
            if(this->mTempNode->mLeft_Child->mCompareValue < this->mTempNode->mRight_Child->mCompareValue)
            {
                this->mTempNode->mValue=this->mTempNode->mLeft_Child->mValue;
                this->mTempNode->mCompareValue= this->mTempNode->mLeft_Child->mCompareValue;
                this->mTempNode=this->mTempNode->mLeft_Child;
            }
            else
            {
                this->mTempNode->mValue=this->mTempNode->mRight_Child->mValue;
                this->mTempNode->mCompareValue= this->mTempNode->mRight_Child->mCompareValue;
                this->mTempNode=this->mTempNode->mRight_Child;
            }
        }
        else if (this->mTempNode->mLeft_Child != NULL )
        {
            this->mTempNode->mValue=this->mTempNode->mLeft_Child->mValue;
            this->mTempNode->mCompareValue= this->mTempNode->mLeft_Child->mCompareValue;
            this->mTempNode=this->mTempNode->mLeft_Child;
        }
        else
        {
            break;
        }

        //        std::cout<<"\n\n Shift Up "<<std::endl;
    }

        //    std::cout<<"\n\n out of shift up, list size ::  "<<this->cache.size()<<std::endl;

    for(typename std::list<typename Heap<T,S>::CacheNodeStructure>::iterator cacheIterator =  this->cache.begin() ; cacheIterator != this->cache.end(); cacheIterator++ )
    {
        if( this->mTempNode->mIndex < (*cacheIterator).node->mIndex )
        {
            this->mTempNode->mValue=(*cacheIterator).node->mValue;
            this->mTempNode->mCompareValue=(*cacheIterator).node->mCompareValue;
            rearrangeHeap(this->mTempNode);
            this->mTempNode=(*cacheIterator).node;
        }
        //        std::cout<<"\n\n for loop "<<std::endl;
    }

    if((*(--this->cache.end())).node->mParent != NULL)
    {

        if( (*(--this->cache.end())).node->mParent->mLeft_Child ==  (*(--this->cache.end())).node )
        {
            (*(--this->cache.end())).node->mParent->mLeft_Child = NULL;
        }
        else
        {
            (*(--this->cache.end())).node->mParent->mRight_Child = NULL;
        }

        if(this->cache.front().node->mIndex != (*(--this->cache.end())).node->mParent->mIndex)
        {
            //creating node for cache table;

            this->cacheNode.node=(*(--this->cache.end())).node->mParent;
            this->cacheNode.left_child=(*(--this->cache.end())).node->mParent->mLeft_Child;
            this->cacheNode.right_child=(*(--this->cache.end())).node->mParent->mRight_Child;

            //pushing Node to cache table;

            this->cache.push_front(this->cacheNode);

        }

    }
    else
    {
        this->mRoot=NULL;
    }



    delete( (*(--this->cache.end())).node );
    this->cache.pop_back();
    this->mTotalIndex--;

    return returnValue;
}

template <class T, class S>
T MinHeap<T,S>::peek()
{
    return this->mRoot->mValue;
}


template <class T, class S>
void MinHeap<T,S>::printHeap()
{
    if(this->mRoot == NULL)
    {
        std::cout<<"\n ::Heap EMPTY :: "<<std::endl;
        return;
    }
    typename std::stack<typename Heap<T,S>::Node*> vStack;

    this->mCurrNode= this->mRoot;

    vStack.push(this->mCurrNode);


    while(vStack.empty() == false)
    {
        while( this->mCurrNode->mLeft_Child != NULL || this -> mCurrNode->mRight_Child != NULL )
        {
            std::cout<<" Index :: "<<this->mCurrNode->mIndex<<" value "<<this->mCurrNode->mValue <<std::endl;

            this->mCurrNode=this->mCurrNode->mLeft_Child;
            vStack.push(this->mCurrNode);
        //            std::cout<<"\n\n Left Iteration "<<std::endl;
        }

        if(this->mCurrNode->mLeft_Child == NULL || this -> mCurrNode->mRight_Child == NULL)
        {
            std::cout<<" Index :: "<<this->mCurrNode->mIndex<<" value "<<this->mCurrNode->mValue << std::endl;
        }
        vStack.pop();

        if(vStack.empty() == false)
        {
            if(vStack.top()->mRight_Child == NULL)
            {
                while ( vStack.top()->mRight_Child == NULL)
                {
                    vStack.pop();
                    if(vStack.empty() == true)
                        break;
                }
            }
        }

        if(vStack.empty() == false)
        {
            this->mCurrNode = vStack.top()->mRight_Child;

            vStack.pop();
            vStack.push(this->mCurrNode);

        }

    }

}

//Defination of protected non Abstract Member Functions

template <class T, class S>
int MinHeap<T,S>::rearrangeHeap(typename Heap<T,S>::Node * node)
{

    T tempT;
    S tempS;

    while(node->mParent != NULL)
    {
        if(node->mCompareValue < node->mParent->mCompareValue)
        {
            tempT= node->mValue;
            tempS= node->mCompareValue;

            node->mValue=node->mParent->mValue;
            node->mCompareValue = node->mParent->mCompareValue;

            node->mParent->mValue = tempT;
            node->mParent->mCompareValue = tempS;

        }



        node = node -> mParent;

    }
    return 0;
}
