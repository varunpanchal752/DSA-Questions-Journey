#include <bits/stdc++.h>

void generateStrings(string &str, int index, vector<string> &results){
    if(index == str.size()){
        results.push_back(str);
        return;
    }

    if(str[index] == '?'){
        str[index] = '0';
        generateStrings(str, index+1, results);

        str[index] = '1';
        generateStrings(str, index+1, results);

        str[index] = '?';
    }
    else{
        generateStrings(str, index+1, results);
    }
}

vector<string> binaryStrings(string &str) {
    // Write your code here.
    vector<string> results;
    generateStrings(str, 0, results);
    return results;
}