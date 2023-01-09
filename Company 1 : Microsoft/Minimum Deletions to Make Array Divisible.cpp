class Solution {
public:

    int calcGCD(vector<int>& numsDivide){
        int n = numsDivide.size();
        int gcd = numsDivide[0];
        for(int i=1; i<n; i++){
            int num = numsDivide[i];
            while(num>0){
                int temp = gcd % num;
                gcd = num;
                num = temp;
            }
        }
        return gcd;
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // Step1: calculate GCD of numsDivide
        int gcd = calcGCD(numsDivide);      

        // Step2: Sort nums array
        sort(nums.begin(), nums.end());

        // Step3: Count elements to delete
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(gcd % nums[i] == 0)
                return count;
            count++;
        }
        
        // Step4: If we dont get any element in nums which divides GCD of numsDivide array simply return -1
        return -1;
    }
