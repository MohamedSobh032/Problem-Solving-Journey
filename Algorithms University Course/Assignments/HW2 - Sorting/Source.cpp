#include <cmath>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>

/**
 * g++ -O2 Source.cpp
 * python3 runscript.py 100000 data.txt     ---> python3 runscript.py <DATASET_SIZE> <OUTPUT_FILE>
 * ./a.out 2 data.txt out.txt outtime.txt   ---> ./a.out <ALGORITHM> <INPUT_FILE> <SORTED_DATASET_OUTPUT_FILE> <TIME_OUTPUT_FILE>
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
void selection_sort(std::vector<int>& nums) {

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
void insertion_sort(std::vector<int>& nums) {

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
void merge_sort(std::vector<int>& nums) {
    
    // base case
    if (nums.size() <= 1)
        return;
    // create two new vectors for left and right, then initialize them
    int middleDiv = nums.size() / 2;
    std::vector<int> left(middleDiv);
	std::vector<int> right(nums.size() - middleDiv);
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
int partition(std::vector<int>& nums, int start, int end) {

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
void quick_sort_actual(std::vector<int>& nums, int start, int end) {

    // base case
    if (end <= start)
        return;
    // get pivot
    int pivot = partition(nums, start, end);
    // recursion
    quick_sort_actual(nums, start, pivot - 1);
    quick_sort_actual(nums, pivot + 1, end);
}
void quick_sort_wrapper(std::vector<int>& nums) {

    quick_sort_actual(nums, 0, nums.size() - 1);
}

/**
 * @brief Hybrid Sort Algorithm
 * TIME COMPLEXITY:
 * =================================================================
 * SPACE COMPLEXITY:
 * =================================================================
 * WHEN TO USE:
 * =================================================================
 * SIDE NOTES:
 */
void hybrid_sort(std::vector<int>& nums) {

    int n = nums.size();
    // Calculate the number of sorted elements
    int sortedelements = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] <= nums[i + 1])
            sortedelements++;
    }
    // Call the sorting algorithm
    if (sortedelements >= (int)(0.75 * (float)n))
        insertion_sort(nums);
    else
        quick_sort_wrapper(nums);
}

/**
 * @brief Reads file data and added it into a vector
 * 
 * @param fileName filename with relative/absolute path
 * @param nums vector to add the data into it
 */
void readFile(std::string fileName, std::vector<int>& nums) {
    std::ifstream inputFile(fileName);
    std::string temp;
    while (getline(inputFile, temp))
        nums.push_back(stoi(temp));
    inputFile.close();
}

/**
 * @brief Reads one number and put it into a file
 * 
 * @param fileName filename to write into it with relative/absolute path
 * @param num number to put it into the file
 */
void writeFile(std::string fileName, float num) {
    std::ofstream outputFile(fileName);
    outputFile << num << std::endl;
    outputFile.close();
}

/**
 * @brief Reads data of the vector and put it into a file
 * 
 * @param fileName filename to write into it with relative/absolute path
 * @param nums vector that contains the data
 */
void writeFile(std::string fileName, std::vector<int>& nums) {
    std::ofstream outputFile(fileName);
    for (const int& num : nums)
        outputFile << num << std::endl;
    outputFile.close();
}


int main(int argc, char* argv[]) {

    /******************** READ PARAMS ********************/
    int algo = atoi(argv[1]);
    std::string inpfile = argv[2];
    std::string outfile = argv[3];
    std::string outfile_time = argv[4];
    /*****************************************************/

    /**************** READ UNORDERED LIST ****************/
    std::vector<int> nums;
    readFile(inpfile, nums);
    /*****************************************************/

    /************** SORT AND CALCULATE TIME **************/
    auto start = std::chrono::high_resolution_clock::now();
    switch (algo) {
        case 0: selection_sort(nums);     break;
        case 1: insertion_sort(nums);     break;
        case 2: merge_sort(nums);         break;
        case 3: quick_sort_wrapper(nums); break;
        case 4: hybrid_sort(nums);        break;
        default:                          break;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    /*****************************************************/
    
    /**************** WRITE IN THE FILES *****************/
    writeFile(outfile_time, std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000.0);
    writeFile(outfile, nums);
    /*****************************************************/

    return 0;
}