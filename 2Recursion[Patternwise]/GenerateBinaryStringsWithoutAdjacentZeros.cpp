class Solution {
public:
    void generateAllValidStrings(int n, string output, char lastChar, vector<string> & result){
        if(n == 0) {
            result.push_back(output);
            return;
        }

        generateAllValidStrings(n-1, output + '1', '1', result);

        if(lastChar != '0'){
            generateAllValidStrings(n-1, output + '0', '0', result);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> result;
        generateAllValidStrings(n, "", '1', result);
        return result;
    }
};