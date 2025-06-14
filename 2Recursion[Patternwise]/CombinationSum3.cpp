// Pick or not pick one
class Solution {
public:
    void generateCombination(int i, int k, int n, int sumTillNow, vector<int>& subSet, vector<vector<int>>& ans){
        if(sumTillNow > n) return;
        if(k == 0){
            if(sumTillNow == n) {
                ans.push_back(subSet);
            }
            return;
        }
        if(i == 10) return;

        // pick
        subSet.push_back(i);
        sumTillNow += i;
        generateCombination(i+1, k-1, n, sumTillNow, subSet, ans);

        // not pick
        subSet.pop_back();
        sumTillNow -= i;
        generateCombination(i+1, k, n, sumTillNow, subSet, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subSet;
        vector<vector<int>> ans;
        generateCombination(1, k, n, 0, subSet, ans);
        return ans;
    }
};


// For loop one - BETTER ONE
class Solution {
public:
    void generateCombination(int i, int k, int n, int sumTillNow, vector<int>& subSet, vector<vector<int>>& ans) {
        if (sumTillNow > n) return;
        if (k == 0) {
            if (sumTillNow == n) {
                ans.push_back(subSet);
            }
            return;
        }

        for (int j = i; j <= 9; ++j) {
            if (sumTillNow + j > n) break;  // Prune unnecessary calls
            subSet.push_back(j);
            generateCombination(j + 1, k - 1, n, sumTillNow + j, subSet, ans);
            subSet.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subSet;
        vector<vector<int>> ans;
        generateCombination(1, k, n, 0, subSet, ans);
        return ans;
    }
};