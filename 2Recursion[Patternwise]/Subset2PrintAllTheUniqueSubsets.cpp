// Brute
class Solution {
public:
    void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
        if (index == nums.size()) {
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);
        ds.pop_back();
        fun(nums, index + 1, ds, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector < vector < int >> ans;
        set < vector < int >> res;
        vector < int > ds;
        fun(nums, 0, ds, res);
        for (auto it = res.begin(); it != res.end(); it++) {
            ans.push_back( * it);
        }
        return ans;  
    }
};


// Optimal
class Solution {
public:
    void fun(vector < int > & nums, int index, vector < int > &ds, vector < vector < int >> & ans) {
        ans.push_back(ds);

        for(int i=index; i<nums.size(); i++){
            if(i!=index && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            fun(nums, i + 1, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector < vector < int >> ans;
        vector < int > ds;
        sort(nums.begin(), nums.end());
        fun(nums, 0, ds, ans);
        return ans;  
    }
};
