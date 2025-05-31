// Brute
class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr, set<vector<int>>& tempAns, vector<int>& ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                vector<int> sortedDs = ds;
                sort(sortedDs.begin(), sortedDs.end());  // Ensure unique ordering
                tempAns.insert(sortedDs); 
            }
            return;
        }
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind + 1, target - arr[ind], arr, tempAns, ds);
            ds.pop_back();
        }
        findCombination(ind + 1, target, arr, tempAns, ds);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> tempAns;
        vector<int> ds;
        findCombination(0, target, candidates, tempAns, ds);

        // Convert set to vector<vector<int>>
        vector<vector<int>> ans(tempAns.begin(), tempAns.end());
        return ans;
    }
};


// Optimal
class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& combinations, vector<int>& ds) {
        if(target == 0) {
            combinations.push_back(ds); 
            return;
        }

        for(int i=ind; i<arr.size(); i++){
            if(i>ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;

            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, combinations, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> ds;
        findCombination(0, target, candidates, combinations, ds);

        return combinations;
    }
};