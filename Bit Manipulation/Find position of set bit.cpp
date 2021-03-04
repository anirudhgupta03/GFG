class Solution{
public:
    int findPosition(int N) {
        
        if((N && !(N & (N-1))) != 1){
            return -1;
        }
        
        return log2(N) + 1;
    }
};
