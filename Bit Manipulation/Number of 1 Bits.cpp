class Solution {
public:
    int setBits(int N) {
        
        int count = 0;
        
        while(N){
            N = (N & (N - 1));
            count++;
        }
        return count;
    }
};
