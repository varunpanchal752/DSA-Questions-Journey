#include <bits/stdc++.h> 

bool generateSubSequence(int index, int sum, vector<int>& arr, int k)
{
	if(sum>k) return false;
	if(index == arr.size()){
		if(sum == k){
			return true;
		}
		else 
			return false;
	}

	sum += arr[index];
	if(generateSubSequence(index+1, sum, arr, k) == true) return true;

	sum -= arr[index];
	if(generateSubSequence(index+1, sum, arr, k) == true) return true;

	return false;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	return generateSubSequence(0, 0, arr, k);
}