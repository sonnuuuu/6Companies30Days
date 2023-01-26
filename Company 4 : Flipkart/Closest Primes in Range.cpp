class Solution {
private:
    bool isPrime(int n){
        if(n < 2) return false;
        if(n == 2) return true;

        for(int i=2;i*i<=n;i++){
            if(n%i == 0) return false;
        }

        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        int num1 = -1,num2 = -1,last = -1,diff = INT_MAX;

        //prime is always odd except 2 so :
        if(left <= 2){
            num1 = 2;
            left = 3;
        } 
        else if(left % 2 == 0) left++;

        for(int i=left;i<=right;i += 2){
            if(isPrime(i)){
                if(num1 == -1) num1 = i;
                else if(num2 == -1){
                    num2 = i;
                    diff = num2 - num1;
                }
                else if(i - last < diff){
                    num1 = last;
                    num2 = i;
                    diff = i - last;
                }
                last = i;
            }
            
            //if diff <= 2 then return because can't be better solution(diff ==1 only for 2 and 3)
            if(diff <= 2) return {num1,num2};
        }
        
        if(num1 == -1 || num2 == -1) return {-1,-1};
        return {num1,num2};
    }
};
