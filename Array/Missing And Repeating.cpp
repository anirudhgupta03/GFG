//Ref: https://www.youtube.com/watch?v=2D0D8HE6uak&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=25
//Method - 1
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long sum1 = 0, sum2 = 0;
        
        for(int num: arr){
            sum1 += (long long)num;
            sum2 += (long long)num*num;
        }
        
        long long sum3 = (n*(n+1))/2;
        long long sum4 = (n*(n + 1)*(2*n + 1))/6;
        
        long long temp1 = sum1 - sum3;
        long long temp2 = sum2 - sum4;
        long long temp3 = temp2/temp1;
        
        return {(temp1 + temp3)/2, (temp3 - temp1)/2};
    }
};

// Method - 2
// 1. (arr[i]) ^ (1^2....^n) = num
// 2. find a difference in the num, first one from the right
// 3. put them into two parts
// 4. take xor of the two parts
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int xor1 = 0, xor2 = 0;
        
        for(int i = 0; i < n; i++){
            xor1 = xor1 ^ arr[i];
            xor2 = xor2 ^ (i + 1);
        }
        
        int num = xor1 ^ xor2;
        int bitPos = 0;
        
        while(1){
            int val = num & (1 << bitPos);
            if(val){
                break;
            }
            bitPos++;
        }
        int val = (1 << bitPos);
        
        int val1 = 0, val2 = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] & val){
                val2 = val2 ^ arr[i];
            }
            else{
                val1 = val1 ^ arr[i];
            }
            if((i + 1) & val){
                val2 = val2 ^ (i + 1);
            }
            else{
                val1 = val1 ^ (i + 1);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(arr[i] == val1){
                return {val1, val2};
            }
            else if(arr[i] == val2){
                return {val2, val1};
            }
        }
    }
};

//Method - 3
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            int eleInd = abs(arr[i]) - 1;
            if(arr[eleInd] < 0){
                res.push_back(abs(arr[i]));
            }
            else{
                arr[eleInd] = -1*(abs(arr[eleInd]));
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
