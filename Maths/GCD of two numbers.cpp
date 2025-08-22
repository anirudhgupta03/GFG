class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if(a > b){
            swap(a, b);
        }
        while(1){
            int rem = b % a;
            if(rem == 0){
                return a;
            }
            b = a;
            a = rem;
        }
        return 1;
    }
};
