#include <iostream>
#include <string.h>
#include "seqLinearList.hpp"
#include "sorting.hpp"
#include "fileReader.hpp"
#include "timer.hpp"

int main() {
    double time ;
    int n, pos, choice;
    string prefix,suffix;

    cout << "Enter the number of elements \n";
    cin >> n;
    // Change the data type here
    int temp;
    Sort<int> s;
    Timer timer;
    LinearList<int> a(n);

    while(1) {
        cout << "\nWhat would you like to do ? \n";
        cout << "1. Enter a new element\n";
        cout << "2. Find an element\n";
        cout << "3. Sort the list\n";
        cout << "4. Erase an element\n";
        cout << "5. Print the list\n";
        cout << "6. Read from file\n";
        cout << "7. Exit\n";
        cout << "(Enter the option number)\n";

        cin >> choice;

        switch(choice) {
            case 1:
                // Entering a new element
                cout << "Enter the element \n";
                cin >> temp;
                if(a.length() < a.maxSize())
                    a.push_back(temp);
                else
                    cout << "Limit Reached !!\n";
                break;

            case 2:
                // Using the find function
                pos = a.find(temp);
                cout << "Enter the position to be queried\n";
                cin >> temp;
                if(pos < sizeof(a) - 24)
                {
                    cout << "\nThe element "<< temp <<" is present at "<< pos <<" position\n";
                }else {
                    cout << "\nThe element "<< temp <<" is not present at "<< pos <<" position\n";
                }
                break;
            // case 3:
            //     // Using the search function
            //     cout << "Enter element to be searched\n";
            //     cin >> temp;
            //     if(a.search(temp))
            //     {
            //         cout << "The element "<< temp <<" is present \n";
            //     }else {
            //         cout << "The element "<< temp <<" is not present \n";
            //     }
            //     break;
            case 3:
                // Using the sort function
                // cout << "Which sort do you wish to perform ?\n";
                // cout << "1. Insertion Sort\n";
                // cout << "2. Rank Sort\n";
                // cout << "3. Bubble Sort\n";
                // cout << "4. Selection Sort\n";
                // cout << "5. Quick Sort\n";
                // cout << "6. Merge Sort\n";
                // cin >> pos;
                //if(pos == 1){
                            readFrom("desc", "100000", a);

                    timer.start();
                    s.insertionSort(a, 0, a.length());
                    timer.stop();
                    time = timer.last_timing();
                    cout << "Ins - Sorting time = "<<time<<" s\n";
                //}
                //else if(pos == 2){
                                    readFrom("desc", "100000", a);

                    timer.start();
                    s.rankSort(a, 0, a.length());
                    timer.stop();
                    time = timer.last_timing();
                cout << "Rank - Sorting time = "<<time<<" s\n";
                //}
                //else if(pos == 3){
                                readFrom("desc", "100000", a);

                    timer.start();
                    s.bubbleSort(a, 0, a.length());
                    timer.stop();
                    time = timer.last_timing();
                cout << "Bubble - Sorting time = "<<time<<" s\n";
                // }
                // else if(pos == 4){
                                readFrom("desc", "100000", a);

                    timer.start();
                    s.selectionSort(a, 0, a.length());
                    timer.stop();
                    time = timer.last_timing();
                cout << "Selection - Sorting time = "<<time<<" s\n";
                // }
                // else if(pos == 5){
                                readFrom("desc", "100000", a);

                    timer.start();
                    s.quickSort(a, 0, a.length() - 1);
                    timer.stop();
                    time = timer.last_timing();
                cout << "Quick - Sorting time = "<<time<<" s\n";
                // }
                // else if(pos == 6){
                                readFrom("desc", "100000", a);

                    timer.start();
                    s.mergeSort(a, 0, a.length() - 1);
                    timer.stop();
                    time = timer.last_timing();
                cout << "Merge - Sorting time = "<<time<<" s\n";
                // }
                // else{
                //     cout << "Invalid Option.\n";
                // }

                // time = timer.last_timing();
                // cout << "Sorting time = "<<time<<" s\n";
                break;
            case 4:
                // Using the delete function
                cout << "Enter the element to be erased\n";
                cin >> temp;
                a.erase(temp);
                break;
            case 5:
                // Printing the list
                for (int i = 0; i < a.length(); ++i)
                {
                    cout << a.returnListElement(i) << " ";
                }
                cout << "\n";
                break;
            case 6:
                // cout << "Enter the file prefix :- \n";
                // cin >> prefix;
                // cout << "Enter the file suffix :- \n";
                // cin >> suffix;
                readFrom("desc", "100000", a);
                break;
            case 7:
                // Calling the destructor and exiting the program
                a.~LinearList();
                if(a.isEmpty())
                {
                    cout << "List has been deleted\n";
                }else {
                    cout << "List has not been deleted\n";
                }
                cout << "\nThank you for using this program ^_^\n";
                return 0;

            default:
                cout << "Something went wrong, lol.\n";
        }
    }

      return 0;
}