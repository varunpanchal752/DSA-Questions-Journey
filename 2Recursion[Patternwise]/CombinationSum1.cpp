class Solution {
public:
    void findCombination(int index, vector<int>& candidates, int target, vector<int> &result, vector<vector<int>>& results){
        if(index == candidates.size()){
            if(target == 0){
                results.push_back(result);
            }
            return;
        }

        if(candidates[index] <= target){
            result.push_back(candidates[index]);
            findCombination(index, candidates, target - candidates[index], result, results);
            result.pop_back();
        }

        findCombination(index+1, candidates, target, result, results);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        findCombination(0, candidates, target, result, results);
        return results;
    }
};