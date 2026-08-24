#include <iostream>
#include <vector>
#include <algorithm> // We include this to use the built-in sort function for our buckets

using namespace std;

// 1. The Main Bucket Sort Logic
void bucketSort(float arr[], int size) {
    // Step A: Create an array of empty buckets
    // We use a vector because it automatically grows if we add multiple items to it
    vector<float> buckets[size];

    // Step B: Put array elements into the correct buckets
    for (int i = 0; i < size; i++) {
        // Multiply by the size to figure out which bucket index to use
        // E.g., if size is 6 and the number is 0.5, 6 * 0.5 = 3. It goes in bucket 3!
        int bucketIndex = size * arr[i]; 
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Step C: Sort each individual bucket
    for (int i = 0; i < size; i++) {
        // We use C++'s built-in sort function to quickly sort the tiny buckets
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Step D: Pour all the sorted buckets back into the original array
    int originalArrayIndex = 0;
    
    // Go through each bucket one by one
    for (int i = 0; i < size; i++) {
        // Go through each item inside that specific bucket
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[originalArrayIndex] = buckets[i][j];
            originalArrayIndex++;
        }
    }
}

// 2. Helper function to print the array
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

// 3. Test the code!
int main() {
    // Bucket sort is famously used for decimal values between 0.0 and 1.0
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    
    // A clever C++ trick to calculate how many items are in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: \n";
    printArray(arr, size);

    bucketSort(arr, size);

    cout << "\nSorted array: \n";
    printArray(arr, size);
    // Output: 0.1234  0.3434  0.565  0.656  0.665  0.897

    return 0;
}