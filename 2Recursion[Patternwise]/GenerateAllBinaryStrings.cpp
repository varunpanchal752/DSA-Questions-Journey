#include <iostream>
#include <vector>
using namespace std;

void generateBinaryStrings(int n, string current, vector<string> &result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }

    // Append '0' and recurse
    generateBinaryStrings(n, current + '0', result);

    // Append '1' and recurse
    generateBinaryStrings(n, current + '1', result);
}


int main() {
    int n = 3; // Change this value to generate for different lengths
    vector<string> result;

    generateBinaryStrings(n, "", result);

    cout << "All binary strings of length " << n << ":\n";
    for (const string &str : result) {
        cout << str << "\n";
    }

    return 0;
}
