// Without DP
class Solution {
public:
    bool solve(int index, int n, string &s, unordered_set<string> &st){
        if(index == n) return true;

        if(st.find(s.substr(index, n-index)) != st.end()) return true;

        for(int i=index+1; i<=n; i++){
            string item = s.substr(index, i-index);            
            if(st.find(item) != st.end() && solve(i, n, s, st))
                return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();
                
        return solve(0, n, s, st);
    }
};


// With DP
class Solution {
public:
    bool solve(int index, int n, string &s, unordered_set<string> &st, vector<int> &dp){
        if(index == n) return true;

        if (dp[index] != -1) return dp[index];

        if(st.find(s.substr(index, n-index)) != st.end()) return dp[index] = true;

        for(int i=index+1; i<=n; i++){
            string item = s.substr(index, i-index);            
            if(st.find(item) != st.end() && solve(i, n, s, st, dp))
                return dp[index] = true;
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<int> dp(n+1, -1);
                
        return solve(0, n, s, st, dp);
    }
};