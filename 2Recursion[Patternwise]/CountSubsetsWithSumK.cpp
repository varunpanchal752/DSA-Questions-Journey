#define MODULO 1000000007

int generateSubSequence(int index, int sum, vector<int>& arr, int k)
{
	if(sum>k) return 0;
	if(index == arr.size()){
		if(sum == k){
			return 1;
		}
		else 
			return 0;
	}

	sum += arr[index];
	int include = generateSubSequence(index+1, sum, arr, k) % MODULO;

	sum -= arr[index];
	int exclude = generateSubSequence(index+1, sum, arr, k) % MODULO;

	return (include + exclude) % MODULO;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	return generateSubSequence(0, 0, arr, k);
}
