#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"

template<class Item>
class Sort{
    private:

    public:

        // Insertion Sort
        void insertionSort(LinearList<Item>& A, int low, int high) {
            Item key;
            int j;
            for (int i = low + 1; i < high; i++)
            {
                // Picking up an element for insertion
                key = A.returnListElement(i);
                j = i - 1;

                // Moving larger elements to the right
                while (j >= 0 && A.returnListElement(j) > key) {
                   A[j + 1] = A.returnListElement(j);
                   j = j - 1;
                }

                // Inserting the element in its ordered place
                A[j + 1] = key;
            }
        }

        // Bubble Sort
        void bubbleSort(LinearList<Item>& A, int low, int high) {
            Item temp;
            for (int i = low + 1; i < high; i++) {
                for (int j = low; j < high - i; j++) {
                    // Comparing 2 elements and placing them in order
                    if (A.returnListElement(j) > A.returnListElement(j + 1)) {
                        temp = A.returnListElement(j + 1);
                        A[j + 1] = A.returnListElement(j);
                        A[j] = temp;
                    }
                }
            }
        }

        // Rank Sort
        void rankSort(LinearList<Item>& A, int low, int high) {
            int rank[high];
            LinearList<Item> temp(A.length());
            // Initializing
            for (int i = low; i < high; ++i) {
                rank[i] = 0;
                temp.insert(i,i);
            }
            // Ranking
            for (int j = low + 1; j < high; ++j) {
                for (int i = low; i < j; ++i) {
                    if(A.returnListElement(i) <= A.returnListElement(j)) {
                        rank[j] ++;
                    }else {
                        rank[i] ++;
                    }
                }
            }
            // Placing elements rankwise
            for (int i = low; i < high; ++i) {
                temp[rank[i]] = A.returnListElement(i);
            }
            for (int i = low; i < high; ++i) {
                A[i] = temp.returnListElement(i);
            }
        }

        // Selection Sort
        void selectionSort(LinearList<Item>& A, int low, int high) {
            Item temp;
            int i, j, min_idx;
            for (i = low; i < high-1; i++) {
                // Find the minimum element in unsorted array
                min_idx = i;
                for (j = i+1; j < high; j++){
                    if (A.returnListElement(j) < A.returnListElement(min_idx)) {
                        min_idx = j;
                    }
                }

                // Swap the found minimum element with the first element
                temp = A.returnListElement(i);
                A[i] = A.returnListElement(min_idx);
                A[min_idx] = temp;
            }
        }

        // Quick Sort

        // A utility function to swap two elements
        void swap(int* a, int* b)
        {
            int t = *a;
            *a = *b;
            *b = t;
        }

        /* This function takes last element as pivot, places
           the pivot element at its correct position in sorted
            array, and places all smaller (smaller than pivot)
           to left of pivot and all greater elements to right
           of pivot */
        int partition (LinearList<Item>& A, int low, int high)
        {
            Item pivot = A.returnListElement(high);    // pivot
            int i = (low - 1);  // Index of smaller element

            for (int j = low; j <= high- 1; j++)
            {
                // If current element is smaller than or
                // equal to pivot
                if (A[j] <= pivot)
                {
                    i++;    // increment index of smaller element
                    swap(&A[i], &A[j]);
                }
            }
            swap(&A[i + 1], &A[high]);
            return (i + 1);
        }

        /* The main function that implements QuickSort
         arr[] --> Array to be sorted,
          low  --> Starting index,
          high  --> Ending index */
        void quickSort(LinearList<Item>& A, int low, int high)
        {
            if (low < high)
            {
                /* pi is partitioning index, arr[p] is now
                   at right place */
                int pi = partition(A, low, high);

                // Separately sort elements before
                // partition and after partition
                quickSort(A, low, pi - 1);
                quickSort(A, pi + 1, high);
            }
        }
        // Merge Sort

        void merge(LinearList<Item>& A, int l, int m, int r)
        {
            int i, j, k;
            int n1 = m - l + 1;
            int n2 =  r - m;

            /* create temp arrays */
            Item left[n1], right[n2];

            /* Copy data to temp arrays L[] and R[] */
            for (i = 0; i < n1; i++)
                left[i] = A.returnListElement(l + i);
            for (j = 0; j < n2; j++)
                right[j] = A.returnListElement(m + 1 + j);

            /* Merge the temp arrays back into arr[l..r]*/
            i = 0; // Initial index of first subarray
            j = 0; // Initial index of second subarray
            k = l; // Initial index of merged subarray
            while (i < n1 && j < n2)
            {
                if (left[i] <= right[j])
                {
                    A[k] = left[i];
                    i++;
                }
                else
                {
                    A[k] = right[j];
                    j++;
                }
                k++;
            }

            /* Copy the remaining elements of L[], if there
               are any */
            while (i < n1)
            {
                A[k] = left[i];
                i++;
                k++;
            }

            /* Copy the remaining elements of R[], if there
               are any */
            while (j < n2)
            {
                A[k] = right[j];
                j++;
                k++;
            }
        }

        /* l is for left index and r is right index of the
           sub-array of arr to be sorted */
        void mergeSort(LinearList<Item>& A, int low, int high)
        {
            if (low < high)
            {
                // Same as (l+r)/2, but avoids overflow for
                // large l and h
                int m = low + (high - low) / 2;

                // Sort first and second halves
                mergeSort(A, low, m);
                mergeSort(A, m + 1, high);
                merge(A, low, m, high);
            }
        }

};

#endif