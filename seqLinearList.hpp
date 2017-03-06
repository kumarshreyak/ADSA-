#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

template<class Item>
class LinearList {
    private:
        // Stores the maximum no. of elements the list can have
        int MaxSize;
        // The array used to retrieve the list's elements
        Item *element;
        // The no. of elements present in the list
        int len;
    public:

        // Default constructor
        LinearList() {
            element =  NULL;
            MaxSize = 0;
        }

        // Parameterized constructor
        LinearList(const int& MaxListSize) {
            element = new Item[MaxListSize];
            //element = (Item *) malloc((Item)MaxListSize);
            MaxSize = MaxListSize;
            len = 0;
        }

        // Constuctor with size and default value as input
        LinearList(const int& isize, const Item& ival) {
            element = new Item[isize];
            element = ival;
            MaxSize = isize;
            len = (int) sizeof(ival) / (int)sizeof(Item);
        }

        // Destructor
        ~LinearList() {
            MaxSize = 0;
            len = 0;
            delete [] element;
            element = NULL;
        }

        // Operator function which returns the reference to the queried element
        inline Item& operator[](const int& i) {
            return element[i];
        }

        // Return the element in the list at position k
        inline Item& at(const int& k) {
            return element[k];
        }

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        void push_back(const Item& item) {
            len ++;
            element[len - 1] = item;
        }

        // Checks if the list is empty
        bool isEmpty() {
            return len == 0;
        }

        // Returns the number of elements present in the list
        int  length() {
            return len;
        }

        // Returns the max. number of elements the list can accomodate
        int maxSize() {
            return MaxSize;
        }

        // Returns the capacity of the LinearList
        unsigned int capacity() {
            return MaxSize * (int)sizeof(Item);
        }

        // Fills all the elements with a default value
        void fill(const Item& item) {
            for (int i = 0; i < MaxSize; ++i)
            {
                item[i] = 0;
            }
        }

        // Resizes the LinearList
        void resize(const int& n) {
            Item *newElement;
            newElement = new Item[n];

            for (int i = 0; i < len; ++i)
            {
                newElement[i] = element[i];
            }

            //delete [] element;
            element = new Item[n];
            for (int i = 0; i < len; ++i)
            {
                element[i] = newElement[i];
            }
            MaxSize = n;
            len = 0;
        }

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        int find(Item& x) {
            for (int i = 0; i < len; ++i)
            {
                if(element[i] == x) {
                    return i;
                }
            }
            return (int)sizeof(element);
        }

        // Remove all occurences of an item in the list
        void erase(const Item& item) {
            int check[len] = {0}, j = 0;

            for (int i = 0; i < len; ++i)
            {
                if(element[i] == item)
                {
                    check[i] = 1;
                }
            }

            Item *newElement;
            newElement = new Item[MaxSize];

            for (int i = 0; i < len; ++i)
            {
                if(check[i] == 0) {
                    newElement[j] = element[i];
                    j++;
                }

            }

            element = newElement;
        }

        // Remove the item in the list at position pos
        void erase_pos(const int& pos) {
            for (int i = pos + 1; i < len; ++i)
            {
                element[i - 1] = element[i];
            }
        }

        // Returns the list's element
        Item  returnListElement(const int k) {
            return element[k];
        }

        // Assigns a new value to the position and deletes the previous elements
        // void  deleteElement(const int k, Item& x) {
        //     element[k] = x;
        // }

        /* The Real delete function
        void  deleteElement(const int k) {
            for (int i = k; i < len - 1; ++i)
            {
                element[k] = element[k + 1];
            }
            len --;
        }*/

        // Inserts the element after the specified position
        void  insert(const int  k, Item& x) {
            len++;
            Item temp1,temp2;
            temp2 = x;
            if(k >= len) {
                element[len - 1] = x;
            }else {
                for (int i = k; i < len; ++i)
                {
                    temp1 = element[k];
                    element[k] = temp2;
                    temp2 = temp1;
                }
            }
        }

};





#endif