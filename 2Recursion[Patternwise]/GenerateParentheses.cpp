class Solution {
public:
    void validParenthesis(int n, int open, string curr, vector<string> &results){
        if(curr.length() == 2 * n) {
            results.push_back(curr);
            return;
        }

        if(open < n) validParenthesis(n, open + 1, curr + '(', results);
        if(curr.length() - open < open) validParenthesis(n, open, curr + ')', results);        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        validParenthesis(n, 0, "", results);
        return results;
    }
};