class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ind(n);
        int finalInd = 0, finalMaxLen = 0;
        ind[0].push_back(nums[0]);
        for(int i = 1; i < n ; i++){
            int maxInd = i, maxLenInd = 0;
            for(int j = 0; j < i ; j++){
                if(nums[j]%nums[i] == 0 || nums[i]%nums[j] == 0){
                    if(ind[j].size() > maxLenInd){
                        maxLenInd = ind[j].size();
                        maxInd = j;
                    }
                }
               }
//Find the maximum length of the index i.e to find the maximum length of the subset 
                if(maxInd != i)
                ind[i] = ind[maxInd];
                ind[i].push_back(nums[i]);
                if(ind[i].size() > finalMaxLen){
                    finalMaxLen = ind[i].size();
                    finalInd = i;
                }
        }
        return ind[finalInd];
    }
};
