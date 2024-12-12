#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/**
 * @brief GENERAL NOTES
 *      -----> Do random order 3+ times
 *      -----> Don't search for heap sort first
 */

/**
 * @brief SUMMARY
 * =================================================================
 * ==================== TIME COMPLEXITY SUMMARY ====================
 * ALGORITHMS O(n^2):
 *          -----> Selection Sort
 *          -----> Insertion Sort
 * ALGORITHMS O(nlogn):
 *          -----> Merge Sort
 *          -----> Quick Sort
 *          -----> Heap Sort
 * =================================================================
 * 
 * =================================================================
 * =================== SPACE COMPLEXITY SUMMARY ====================
 * ALGORITHMS O(n):
 *          -----> Merge Sort
 * ALGORITHMS O(logn):
 *          -----> Quick Sort
 * ALGORITHMS O(1):
 *          -----> Selection Sort
 *          -----> Insertion Sort
 *          -----> Heap Sort
 * =================================================================
 * 
 * =================================================================
 * ========================== WHEN TO USE ==========================
 * SELECTION SORT: Very small datasets < 10
 * INSERTION SORT: Nearly sorted datasets, preferably small
 * MERGE     SORT: Stable sorting of large datasets
 *                 And you have no issue with memory usage
 * QUICK     SORT: General-purpose, large datasets
 * HEAP      SORT: Efficient, guaranteed performance
 *                 And you have issues with memory usage
 * =================================================================
 * 
 * =================================================================
 * ========================== LAB SUMMARY ==========================
 * SELECTION SORT: Same number of comparsions for all cases
 * INSERTION SORT: Worst best for O(n) and nearly sorted datasets
 * MERGE     SORT: Same number of movements for all cases
 * QUICK     SORT: Works best for random order
 * HEAP      SORT: Dwar 3leha by elimination b2a
 * =================================================================
 */










/**
 * @brief Selection Sort Algorithm
 * TIME COMPLEXITY:
 * AVERAGE CASE: O(n^2)
 * BEST    CASE: O(n^2)
 * WORST   CASE: O(n^2)
 * =================================================================
 * SPACE COMPLEXITY: O(1)
 * =================================================================
 * WHEN TO USE:
 * -- Works fine with small datasets, very bad with large datasets
 * -- Useful when memory writes are more costly than reads
 * =================================================================
 * SIDE NOTES:
 * -- Complexity is the same for all datasets
 */
void selection_sort(vector<int>& nums) {
    // one big for loop to iterate on each element --> O(n)
    for (int i = 0; i < nums.size() - 1; i++) {
        // find minimum *EVERYTIME* --> O(n)
        int minimum = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[minimum] > nums[j])
                minimum = j;
        }
        // swap minimum with current value
        std::swap(nums[i], nums[minimum]);
    }
}









/**
 * @brief Insertion Sort Algorithm
 * TIME COMPLEXITY:
 * AVERAGE CASE: O(n^2)
 * BEST    CASE: O(n)   --> Already sorted
 * WORST   CASE: O(n^2) --> Reverse order
 * =================================================================
 * SPACE COMPLEXITY: O(1)
 * =================================================================
 * WHEN TO USE:
 * -- Best for small datasets
 * -- Best for nearly sorted dataesets
 * =================================================================
 * SIDE NOTES:
 */
void insertion_sort(vector<int>& nums) {
    // one big for loop to iterate on each element --> O(n)
    for (int i = 1; i < nums.size(); i++) {
        int j = i - 1;
        int temp = nums[i];
        // iterate backwards *UNTIL* finishing --> Worst case O(n), best case O(0)
        while (j >= 0 && nums[j] > temp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}









/**
 * @brief Merge Sort Algorithm
 * TIME COMPLEXITY:
 * AVERAGE CASE: O(nlogn)
 * BEST    CASE: O(nlogn)
 * WORST   CASE: O(nlogn)
 * =================================================================
 * SPACE COMPLEXITY: O(n)
 * =================================================================
 * WHEN TO USE:
 * -- Very stable algorithm, maintains relative order of elements
 * -- A huge drawback when memory is a limiting factor
 * =================================================================
 * SIDE NOTES:
 * -- Complexity is the same for all datasets
 * -- Large space complexity due to creating new arrays
 * -- Stable
 */
void merge_sort(vector<int>& nums) {
    
    // base case
    if (nums.size() <= 1)
        return;
    
    // create two new vectors for left and right, then initialize them
    int middleDiv = nums.size() / 2;
    vector<int> left(middleDiv);
	vector<int> right(nums.size() - middleDiv);
    for (int i = 0; i < middleDiv; i++)
        left[i] = nums[i];
	for (int j = middleDiv; j < nums.size(); j++)
		right[j - middleDiv] = nums[j];
    
    // recursion
    merge_sort(left);
    merge_sort(right);
    
    // merge the two vectors into nums
    int i = 0, l = 0, r = 0;
    while (l < left.size() && r < right.size()) {
        if (left[l] < right[r])
            nums[i++] = left[l++];
        else
            nums[i++] = right[r++];
    }
    while (l < left.size())
        nums[i++] = left[l++];
    while (r < right.size())
        nums[i++] = right[r++];
}









/**
 * @brief Quick Sort Algorithm
 * TIME COMPLEXITY:
 * AVERAGE CASE: O(nlogn)
 * BEST    CASE: O(nlogn)
 * WORST   CASE: O(n^2) ---> if the array is already sorted
 * =================================================================
 * SPACE COMPLEXITY: O(logn) ---> due to recursion
 * =================================================================
 * WHEN TO USE:
 * -- Very efficient for large datasets
 * -- General purpose sorting algorithm
 * =================================================================
 * SIDE NOTES:
 * -- Worst case can be mitigated with good pivot selection
 */
int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (nums[j] < pivot) {
            i++;
            std::swap(nums[i], nums[j]);
        }
    }
    i++;
    std::swap(nums[i], nums[end]);
    return i;
}
void quick_sort_actual(vector<int>& nums, int start, int end) {
    // base case
    if (end <= start)
        return;
    // get pivot
    int pivot = partition(nums, start, end);
    // recursion
    quick_sort_actual(nums, start, pivot - 1);
    quick_sort_actual(nums, pivot + 1, end);
}
void quick_sort_wrapper(vector<int>& nums) {
    quick_sort_actual(nums, 0, nums.size() - 1);
}









/**
 * @brief Heap Sort Algorithm
 * TIME COMPLEXITY:
 * AVERAGE CASE: O(nlogn)
 * BEST    CASE: O(nlogn)
 * WORST   CASE: O(nlogn)
 * =================================================================
 * SPACE COMPLEXITY: O(1)
 * =================================================================
 * WHEN TO USE:
 * -- Very efficient for large datasets
 * -- Overhead in implementation complexity
 * =================================================================
 * SIDE NOTES:
 * -- Not stable
 * -- Might be slower than quick or merge sort
 */
void heapify(vector<int>& nums, int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && nums[left] > nums[largest])
        largest = left;
    if (right < n && nums[right] > nums[largest])
        largest = right;
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        std::swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}
void heap_sort(vector<int>& nums) {

    int n = nums.size();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        std::swap(nums[0], nums[i]);
        // Heapify root element to get highest element at root again
        heapify(nums, i, 0);
    }
}











int main() {
    
    vector<int> nums = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };

    selection_sort(nums);
    insertion_sort(nums);
    merge_sort(nums);
    quick_sort_wrapper(nums);
    heap_sort(nums);

    for (const int& num : nums)
        std::cout << num << " ";
    std::cout << endl;

    return 0;
}



#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#include <chrono>
#include <string>
#include <climits>
void readFile(vector<string>& A, string fileName, int n) {
    ifstream inputFile(fileName);
    string temp;
    for (int i = 0; i < n; i++) {
        inputFile >> temp;
        A[i] = temp;
    }
    inputFile.close();
}

int hashFunction(string key) {
    int length = key.size(), index;
    if (length == 1) {
        index = 39 * (int)key[0];
    }
    else if (length == 2)
    {
        index = 39 * (int)key[0] + 392 * (int)key[1];
    }
    else if (length == 3) {
        index = 39 * int(key[0]) + 392 * int(key[1]) + 393 * int(key[2]);
    }
    else {
        index = 39 * int(key[0]) + 392 * int(key[1]) + 393 * int(key[2]) + 394 * int(key[3]);
    }
    return index % 24000;
}

bool insert(vector<string>& H, string key, int& filledSize) {
    if (H.size() == filledSize) {
        cout << "Hashtable is full!";
        return false;
    }
    int index = hashFunction(key);
    if (H[index] == "" || H[index] == "-1") {
        H[index] = key;
        //cout<<"Successful Insertion"<<endl;
        filledSize++;
        return true;
    }
    int probingIndex = index;
    index++;
    while (H[index] != "" && H[index] != "-1") {
        index = (index + 1) % 24000;
    }
    //cout<<"Successful Insertion"<<endl;
    H[index] = key;
    filledSize++;
    return true;
}

bool deleteK(vector<string>& H, string key, int& filledSize, int& probeNumber) {
    if (filledSize == 0) {
        cout << "Hashtable is empty!" << endl;
    }
    int index = hashFunction(key);
    if (H[index] == key) {
        filledSize--;
        //cout<<"Deleted Successfully!"<<endl;
        H[index] = "-1";
        return true;
    }
    int startIndex = index;
    index++;
    probeNumber++;
    while (H[index] != key && index != startIndex) {
        index = (index + 1) % 24000;
        probeNumber++;
    }
    if (index == startIndex) {
        cout << "Key not Found!" << endl;
        return false;
    }
    else {
        filledSize--;
        //cout<<"Deleted Successfully!"<<endl;
        H[index] = "-1";
        return true;
    }
}

int main() {
    vector<string> A(20000);
    readFile(A, "words20k.txt", 20000);

    vector<string> H(24000, "");
    int filledSize = 0;
    for (int i = 0; i < A.size() / 500; i++) {
        auto start = chrono::high_resolution_clock::now();
        for (int j = i * 500; j < (i + 1) * 500; j++) {
            insert(H, A[j], filledSize);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Average insertion time from " << i * 500 << " to " << (i + 1) * 500 << " is: " << duration.count() / 500 << endl;
    }
    int minProbes = INT_MAX, maxProbes = INT_MIN, totalProbes;
    for (int i = 14000; i < 14999; i++) {
        int probeNumber = 0;
        deleteK(H, A[i], filledSize, probeNumber);
        maxProbes = max(probeNumber, maxProbes);
        minProbes = min(probeNumber, minProbes);
        totalProbes += probeNumber;
    }
    cout << "minimum probes: " << minProbes << endl;
    cout << "Max probes: " << maxProbes << endl;
    cout << "Average Probes: " << (float)totalProbes / 1000 << endl;

    return 0;
}