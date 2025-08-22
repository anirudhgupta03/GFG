// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int sum = 0;
        int tn = n;
        while(tn){
            int digit = tn % 10;
            sum += digit*digit*digit;
            tn /= 10;
        }
        return (sum == n);
    }
};
