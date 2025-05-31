void generateSum(int ind, int sum, vector<int> &nums, vector<int> &subSets)
{
	if(ind == nums.size()){
		subSets.push_back(sum);
		return;
	}
	generateSum(ind+1, sum+nums[ind], nums, subSets);
	generateSum(ind+1, sum, nums, subSets);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> subSets;	
	generateSum(0, 0, num, subSets);
	sort(subSets.begin(), subSets.end());
	return subSets;
}