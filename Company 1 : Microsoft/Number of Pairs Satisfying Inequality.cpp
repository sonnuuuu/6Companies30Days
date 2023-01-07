class Solution {
public:
    long long res = 0;
    int dif = 0;
    void merge(vector<int> &nums,int start,int mid,int end){
        vector<int> temp(end - start + 1);
        int i = start; 
        int j = mid + 1;
        int idx = 0;
        
        // Couting the pairs
        while(i <= mid && j <= end){
            if(nums[i] <= dif + nums[j]){      
                res += end - j + 1;      
                i++;
            }
            else j++;
        }
        
        i = start;
        j = mid + 1;
        
        // Merge two sorted array
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]) temp[idx++] = nums[i++];
            else temp[idx++] = nums[j++];
        }
        
        // Merging the sorted array which is left out 
        while(i <= mid)temp[idx++] = nums[i++];
        while(j <= end)temp[idx++] = nums[j++];
        idx = 0;
        
        // Storing Back the array after it is sorted and the pairs are counted
        for(int itr = start; itr <= end ; itr++, idx++)nums[itr] = temp[idx];
        }
            
    void mergeSort(int start, int end, vector<int>&nums){
        if(start >= end)return;
        
        int mid = start + (end - start) / 2;
        mergeSort(start, mid, nums);
        mergeSort(mid + 1, end, nums);
        merge(nums, start, mid, end);
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        dif = diff;
        int n = nums1.size();
        vector<int>nums(n);
        for(int i = 0 ; i < n ; i++)nums[i] = nums1[i] - nums2[i];
        mergeSort(0, n - 1, nums);
        return res;
    }
};
