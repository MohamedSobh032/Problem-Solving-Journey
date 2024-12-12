#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <climits>
#include <algorithm>
using namespace std::chrono;
using namespace std;


// GLOBAL VARIABLES
int minprob = INT_MAX;
int maxprob = INT_MIN;
int totalprob = 0;


int gethashKey(string s) {

    int index = 0;
    int len = s.size();
    switch (len) {
    case 0: return 0;
    case 1: index = (39 * (int)s[0]); break;
    case 2: index = (39 * (int)s[0]) + (392 * (int)s[1]); break;
    case 3: index = (39 * (int)s[0]) + (392 * (int)s[1]) + (393 * (int)s[2]); break;
    default: index = (39 * (int)s[0]) + (392 * (int)s[1]) + (393 * (int)s[2]) + (394 * (int)s[3]); break;
    }
    return index % 24000;
}

bool insertItem(vector<string>& hashmap, string s, int& filled) {

    // Check the total elements in the hashmap
    if (filled == 24000)
        return false;
    // Get the hash key
    int index = gethashKey(s);
    // Iterate untill finding an empty location
    // (you know you will find because of the above check)
    while (hashmap[index] != "" && hashmap[index] != "-1")
        index = (index + 1) % 24000;
    // Set the value
    hashmap[index] = s;
    // Add total number of elements and return true
    filled++;
    return true;
}

void insertAll(vector<string>& H, vector<string>& A, int& filled) {

    for (int i = 0; i < 40; i++) {
        // measure time here
        auto start = high_resolution_clock::now();
        for (int j = 0; j < 500; j++) {
            if (!insertItem(H, A[j + (i * 500)], filled))
                cout << "COULD NOT INSERT: " << A[j + i * 500] << endl;
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "DURATION OF CYCLE: " << i << " IS: " << duration.count() / 500.0 << endl;
    }
}

bool deleteItem(vector<string>& hashmap, string s, int& filled) {
    
    // Check the total elements in the hashmap
    if (filled == 0)
        return false;
    // Initialize a counter for the number of probs takens
    int probsTaken = 0;
    // Get the hash key
    int hashValue = gethashKey(s);
    // First condition check to allow rotation in the while loop
    if (hashmap[hashValue] == s) {
        hashmap[hashValue] = "-1";
        minprob = min(minprob, 0);
        maxprob = max(maxprob, 0);
        filled--;
        return true;
    }
    // If failed to find in the first trial, search
    int newIndex = hashValue + 1;
    probsTaken++;
    // Iterate untill finding it
    while (hashmap[newIndex] != s && newIndex != hashValue) {
        newIndex = (newIndex + 1) % 24000;
        probsTaken++;
    }
    // breaking the second condition means not found
    if (newIndex == hashValue)
        return false;
    else {
        filled--;
        hashmap[newIndex] = "-1";
        totalprob += probsTaken;
        minprob = min(minprob, probsTaken);
        maxprob = max(maxprob, probsTaken);
        return true;
    }
}

void deleteSpecificRange(vector<string>& H, vector<string>& A, int& filled, int start, int end) {

    for (int i = start; i < end; i++) {
        if (!deleteItem(H, A[i], filled))
            cout << "COULD NOT DELETE AT CYCLE: " << i << " WITH VALUE: " << A[i] << endl;
    }
}

void printParams() {
    cout << "MAX PROB IN DELETING: " << maxprob << endl;
    cout << "MIN PROB IN DELETING: " << minprob << endl;
    cout << "AVERAGE PROB IN DELEIING: " << totalprob / 1000 << endl;
}

int main() {

    // PARAMS DEFINITION
    int fsize = 20000;
    vector<string> A(fsize);

    // 1. READ THE FILE
    ifstream inputFile("words20K.txt");
    string temp;
    for (int i = 0; i < fsize; i++) {
        inputFile >> temp;
        A[i] = temp;
    }
    inputFile.close();

    int n = 24000;
    vector<string> H(n, "");
    int filled = 0;
    insertAll(H, A, filled);
    deleteSpecificRange(H, A, filled, 14000, 15000);
    printParams();

}