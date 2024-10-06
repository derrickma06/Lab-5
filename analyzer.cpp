#include <iostream>
#include <string>
#include <vector>
#include "StringData.h"
using namespace std;

int linearSearch(vector<string> container, string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<string> container, string element) {
    if (container.empty()) {
        return -1;
    }
    int idx = container.size()/2;
    if (container[idx] == element) {
        return idx;
    }
    if (container[idx] < element) {
        int res = binarySearch(vector<string>(container.begin() + idx + 1, container.end()), element);
        return (res != -1) ? res + idx + 1 : -1;
    }
    if (container[idx] > element) {
        return binarySearch(vector<string>(container.begin(), container.begin()+idx), element);
    }
    return -1;
}


int main() {
    vector<string> search = {"thtft", "not_here", "mzzzz", "aaaaa", "zzzzz"};
    vector<string> data = getStringData();

    for (const string& e : search){
        long long linStart = systemTimeNanoseconds();
        int linIndex = linearSearch(data, e);
        long long linEnd = systemTimeNanoseconds();
        cout << "\nLinear index: " << linIndex << "\n";
        cout << "Linear time: " << (linEnd - linStart) << " milliseconds\n";

        long long binStart = systemTimeNanoseconds();
        int binIndex = binarySearch(data, e);
        long long binEnd = systemTimeNanoseconds();
        cout << "Binary index: " << binIndex << "\n";
        cout << "Binary time: " << (binEnd - binStart) << " milliseconds\n";
    }
    return 0;
}
  