/*
3. [Brute-force] Given an array of integers, find the length of the Longest 
Increasing Subsequence (LIS) inside the array such that all elements 
of the subsequence are sorted in increasing order. For example, the 
length of LIS for {12, 24, 9, 35, 21, 50, 41, 62, 82} is 6 and LIS is {12, 
24, 35, 50, 62, 82}. Hint: think of it as having ‘n’ values in the list and 
you are trying all subsets of the list similar to trying all 2𝑛 subsets of 
this list. Refer to problem 1.
*/

#include <iostream>
#include <vector>
using namespace std;

std::vector<int> gVect = {12, 24, 9, 35, 21, 50, 41, 62, 82};

void LIS(int index, vector<int> currVect, vector<int>& maxSet) {

    if (index < gVect.size()) {
        LIS(index + 1, currVect, maxSet);
        currVect.push_back(gVect[index]);
        LIS(index + 1, currVect, maxSet);
        //currVect.pop_back();
    } else {
        if (currVect.size() > maxSet.size()) {
            int prev = INT_MIN;
            for (int i = 0; i < currVect.size(); i++) {
                if (currVect[i] < prev)
                    return;
                prev = currVect[i];
            }
            maxSet = currVect;
        }
    }

}


int main() {
    vector<int> max;
    vector<int> emp;
    LIS (0, emp, max);
    for (auto m : max)
        cout << m << endl;
}