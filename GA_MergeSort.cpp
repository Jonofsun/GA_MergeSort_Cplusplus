#include <iostream>
#include <vector>
/*
Jonathan Reed
1/31/24
*/
void MergeSortArray(std::vector<int>& arr);
void Merge(std::vector<int>& arr, std::vector<int>& leftSubarray, std::vector<int>& rightSubarray);
void PrintArray(const std::vector<int>& arr);

int main() {
    std::vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 }; // C++ doesn't have a built-in array type like C#. Instead, std::vector is used, which is a dynamic array and supports similar operations.
    /*Merge Sort has a time complexity, making it very efficient for sorting large datasets. However, it's worth noting that it requires O(n) and additional space for the left and right subarrays.*/
    std::cout << "Original Array:\n"; 
    PrintArray(arr);

    MergeSortArray(arr);

    std::cout << "\nSorted Array:\n";
    PrintArray(arr);
    /*Initializes an integer array.
    Prints the original array.
    Calls the MergeSortArray method to sort the array.
    Prints the sorted array.*/
    return 0;
}

void MergeSortArray(std::vector<int>& arr) {
    int arrayLength = arr.size();
    /*Divides the array into two halves (left and right subarrays).
    Recursively sorts both halves.
    Merges the sorted halves back into the original array.
    It also has print statements for debugging or illustrative purposes, showing the process of dividing the array, sorting the subarrays, and merging them.*/
    if (arrayLength <= 1) {
        std::cout << "Base case reached: Array is already sorted or empty.\n";
        return;
    }

    int middleIndex = arrayLength / 2;
    std::vector<int> leftSubarray(arr.begin(), arr.begin() + middleIndex);
    std::vector<int> rightSubarray(arr.begin() + middleIndex, arr.end());

    std::cout << "Left Subarray:\n";
    PrintArray(leftSubarray);
    std::cout << "Right Subarray:\n";
    PrintArray(rightSubarray);

    std::cout << "Sorting left subarray:\n";
    MergeSortArray(leftSubarray);
    std::cout << "Sorting right subarray:\n";
    MergeSortArray(rightSubarray);

    std::cout << "Merging sorted subarrays:\n";
    Merge(arr, leftSubarray, rightSubarray);
}

void Merge(std::vector<int>& arr, std::vector<int>& leftSubarray, std::vector<int>& rightSubarray) {
    int leftLength = leftSubarray.size();
    int rightLength = rightSubarray.size();
    int i = 0, j = 0, k = 0;
    /*Merges two sorted subarrays (leftSubarray and rightSubarray) into the original array (arr) in sorted order.
    It ensures that after merging, the arr is sorted between the indices where the left and right subarrays were originally placed.*/
    while (i < leftLength && j < rightLength) {
        if (leftSubarray[i] <= rightSubarray[j]) {
            arr[k] = leftSubarray[i];
            i++;
        } else {
            arr[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    while (i < leftLength) {
        arr[k] = leftSubarray[i];
        i++;
        k++;
    }

    while (j < rightLength) {
        arr[k] = rightSubarray[j];
        j++;
        k++;
    }
    /*Initialization of the left and right subarrays is done using the range constructor of std::vector.*/
}

void PrintArray(const std::vector<int>& arr) {
    for (int item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    /*The range-based for loop in PrintArray (for (int item : arr)) is a convenient way to iterate over elements in C++.*/
}
