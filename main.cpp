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

#include <iostream>
using namespace std;

#include "MinHeap.h"
#include "MinHeap.cpp"

#include "MaxHeap.h"
#include "MaxHeap.cpp"

// Test crdibility by maually checking against the random numbers and getting the upper limit in terms of processor speed.

#include <cstdlib>
#include <ctime>
#include <limits>
int main()
{
    cout << "Minimum Heap!" << endl;
    cout<< "RAND MAX = " <<  RAND_MAX<<std::endl;
    cout<< "unsigned int numeric limit = "<<std::numeric_limits<unsigned int>::max()<<endl;
//    MinHeap<int> vObject;
//    MinHeap<int> vObject(10,10);
//    MinHeap<int,float> vObject(10,10);
//    MinHeap<int> *vObject = new MinHeap<int>(0,0);
//    MinHeap<int,int> *vObject = new MinHeap<int,int>(0,0);

    /***  code taken from daniweb :: https://www.daniweb.com/software-development/cpp/threads/1769/c-random-numbers
        srand((unsigned)time(0));
        int random_integer;
        int lowest=1, highest=10;
        int range=(highest-lowest)+1;
        for(int index=0; index<20; index++){
            random_integer = lowest+int(range*rand()/(RAND_MAX + 1.0));
            cout << random_integer << endl;
        }
    ******************/

    srand((unsigned)time(0));
    long double random_integer;
    long double lowest=0, highest=RAND_MAX-1;
    long double range=(highest-lowest)+1;
    MinHeap<long double,long double> *vObject;

//    for(unsigned int i=std::numeric_limits<long double>::max()/1000; i<=std::numeric_limits<long double>::max()/1000; i+=5)
//    {
        vObject = new MinHeap<long double,long double>();

        cout<<endl<<endl<<"Heap size = "<<std::numeric_limits<unsigned int>::max()/4000<<endl;

        for(unsigned int index=0; index<std::numeric_limits<unsigned int>::max()/4000; index++)
        {
            random_integer = lowest+ ((long double)(range*rand()/(RAND_MAX + 1.0)));
            vObject->pushBack(random_integer,random_integer);
//            cout<<random_integer<<" ";
        }


        cout<<endl<<"Sorted List :: ";

        while(vObject->size() != 0)
        {
            cout<<vObject->pop()<<" ";

    //        cout<<endl<<"Heap :: \n";
    //        vObject->printHeap();
    //        cout<<endl;
        }

        cout<<endl<<"Heap :: ";
        vObject->printHeap();
        cout<<endl;
        delete vObject;
//    }


    /* *  Experiment Number 1 : Test case 1 , first ever successful test case for min and max heap
        MinHeap<int,float> *vObject = new MinHeap<int,float>();

        vObject->pushBack(7,7);
        vObject->pushBack(3,3);
        vObject->pushBack(2,2);
        vObject->pushBack(14,21);
        vObject->pushBack(4,4);
        vObject->pushBack(1,1);
        vObject->pushBack(6,6);
        vObject->pushBack(7,7);
        vObject->pushBack(1,1);
        vObject->pushBack(9,9);

        cout<<endl<<"Heap :: \n";
        vObject->printHeap();
        cout<<endl;

        cout<<endl<<"Sorted List :: ";

        while(vObject->size() != 0)
        {
            cout<<vObject->pop()<<" ";

    //        cout<<endl<<"Heap :: \n";
    //        vObject->printHeap();
    //        cout<<endl;
        }

        cout<<endl<<"Heap :: ";
        vObject->printHeap();
        cout<<endl;

        // Max Heap

        cout << "Maximum Heap!" << endl;

        MaxHeap<int> vObject1(0,0);

        vObject1.pushBack(7,7);
        vObject1.pushBack(2,2);
        vObject1.pushBack(3,3);
        vObject1.pushBack(4,21);
        vObject1.pushBack(4,4);
        vObject1.pushBack(9,9);
        vObject1.pushBack(1,1);
        vObject1.pushBack(6,6);
        vObject1.pushBack(7,7);
        vObject1.pushBack(1,1);

        cout<<endl<<"Heap :: \n";
        vObject1.printHeap();
        cout<<endl;

        cout<<endl<<"Sorted List :: ";

        while(vObject1.size() != 0)
        {
            cout<<vObject1.pop()<<" ";
        }

        cout<<endl<<"Heap :: ";
        vObject1.printHeap();
        cout<<endl;
    **/

    return EXIT_SUCCESS;
}
