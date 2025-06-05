class Solution {
public:
    void generateCombination(int index, string &output, string &digits, vector<string> & ans, vector<string>& mapping) {
        if(index == digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0; i<value.size(); i++){
            output.push_back(value[i]);
            generateCombination(index+1, output, digits, ans, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        int index = 0;
        string output = "";
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        generateCombination(index, output, digits, ans, mapping);
        return ans;
    }
};