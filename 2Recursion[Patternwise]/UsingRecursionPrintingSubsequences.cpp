class Solution {
public:
    void generateSubsets(int ind, vector<int>& result, vector<int>& nums, vector<vector<int>> &results) {
        if(ind == nums.size()){
            results.push_back(result);
            return;
        }

        result.push_back(nums[ind]);
        generateSubsets(ind+1, result, nums, results);
        result.pop_back();
        generateSubsets(ind+1, result, nums, results);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        generateSubsets(0, result, nums, results);
        return results;
    }
};