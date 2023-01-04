class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    
   int curr=0,maxi,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            curr+=i*nums[i];
        }
		maxi=curr;
        for(int i=nums.size()-1;i>=0;i--){
            curr=curr+(sum-nums[i])-(nums.size()-1)*nums[i];
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};
