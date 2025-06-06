class Solution {
public:
    void generateSubStr(int index, string &s, vector<vector<string>> &ans, vector<string> &subAns){
        if(index == s.size()){
            ans.push_back(subAns);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                subAns.push_back(s.substr(index, i-index+1));
                generateSubStr(i+1, s, ans, subAns);
                subAns.pop_back();
            }
        }   
    }

    bool isPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subAns;
        int index=0;
        generateSubStr(index, s, ans, subAns);
        return ans;
    }
};