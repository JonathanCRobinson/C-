//Jonathan Robinson
//COP2535.0M1
/* C++ Program that will declare two arrays where each will hold the contents of a file (random.txt) of 200 integer values

    * Using the two arrays, call a private member function that uses the bubble sort algorithm to sort one of the arrays in ascending order.
        -The function should count the number of exchanges it makes.
        -Display this value.
    * The program should then call a private member function that uses the selection sort algorithm to sort the other array.
        -It should also count the number of exchanges it makes.
        -Display this value.
    * Next, call a private member function that uses the linear search program to locate the value (869).
        -The function should keep a count of the number of comparisons it makes until it finds the value.
         -Display this value
    * The program then should call a private member function that uses the binary search algorithm to locate the same value.
        -It should also keep count of the numbers of comparisons it makes.
        -Display this value.
    * Use private member functions and variables.
    * Use public member functions for a constructor (where appropriate) and a driver method only.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/****************************************
*	    Sort Class Declaration          *
****************************************/

class Sort {

private:
    int array1[200];    // Array for the first search function
    int array2[200];    // Array for the second search function
    int bubbleExchangeCount,    // Variable to keep the value of amount of swaps the bubble sort does
        selectionExchangeCount; // Variable to keep the value of amount of swaps the Selection sort does

    void bubbleSort(int array[], int size);                 // Function for a basic bubblesort for an array
    void selectionSort(int array[], int size);              // Function for a basic selection sort for an array
    int linearSearch(int array[], int size, int value);     // Linear search function to find a value 
    int binarySearch(int array[], int size, int value);     // Binary search function to find a value
    void getData(int array[]);

public:
    Sort();                         // Basic constructor for the sort class
    void display(int linear, int binary);           // Will display the results of how many swaps each function completed, and how many times a search was made for each function                 
    void swap(int& a, int& b);      // Swap function to be used in the sort functions.
    void driver();                  // Driver function to load the program for the user.

};

/****************************************
*	  Default Constructor Declaration   *
****************************************/
Sort::Sort() {
    int array1[] = { 0 };
    int array2[] = { 0 };
}




/****************************************
*	  BubbleSort function Declaration   *
****************************************/
void Sort::bubbleSort(int array[], int size) {
    bubbleExchangeCount = 0;

    for (int maxElement = size - 1; maxElement > 0; maxElement--) {
        for (int index = 0; index < maxElement; index++) {
            if (array[index] > array[index + 1]) {
                swap(array[index], array[index + 1]);
                bubbleExchangeCount++;
            }
        }
    }
}

/****************************************
*   SelectionSort function Declaration  *
****************************************/
void Sort::selectionSort(int array[], int size) {
    int minIndex,
        minValue;
    
    selectionExchangeCount = 0;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);    
        selectionExchangeCount++;
    }

}

/****************************************
*	LinearSearch function Declaration   *
****************************************/
int Sort::linearSearch(int array[], int size, int value) {
    int index = 0,
        position = -1,
        loops = 0;
    bool found = false;

    while (!found && index < size) {
        if (array[index] == value) {
            found = true;
            position = index;
        }
        index++;
        loops++;
    }
    return loops;
}

/****************************************
*	BinarySearch function Declaration   *
****************************************/
int Sort::binarySearch(int array[], int size, int value) {
    int first = 0,
        last = size - 1,
        middle,
        position = -1,
        loops = 0;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (array[middle] == value) {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
        loops++;
    }
    return loops;
}

/****************************************
*	    Driver function Declaration     *
****************************************/
void Sort::driver() {
    int binary,
        linear;
    getData(array1);
    getData(array2);
    bubbleSort(array1, 200);
    selectionSort(array2, 200);
    linear = linearSearch(array1, 200, 869);
    binary = binarySearch(array2, 200, 869);
    display(linear, binary);

}

/****************************************
*	    Swap function Declaration       *
****************************************/
void Sort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/****************************************
*	  Display Function Declaration      *
****************************************/
void Sort::display(int linear, int binary) {
    cout << "Amount of times bubble sort looped :" << bubbleExchangeCount;
    cout << "\nAmount of times selection sort looped :" << selectionExchangeCount;
    cout << "\nAmount of comparisons linear search made finding 869 :" << linear;
    cout << "\nAmount of comparisons binary search made finding 869 :" << binary << "\n\n";
}

/****************************************
*	            Main                    *
****************************************/
int main()
{
    Sort sort;
    sort.driver();

    return 0;
}