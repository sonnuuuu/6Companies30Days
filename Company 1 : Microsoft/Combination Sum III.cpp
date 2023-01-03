class Solution {
public:
    vector<vector<int>> res;   
    void help(int k,int n,vector<int> &ans,int x){
        if(k==0){
            if(n==0) res.push_back(ans);
            return;
        }
        for(int num=x;num<=9;num++){
            ans.push_back(num);
            help(k-1,n-num,ans,num+1);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        help(k,n,ans,1);
        return res;
    }
};
