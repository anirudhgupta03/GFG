class Solution{
public:
    int inSequence(int A, int B, int C){
        
        if(C == 0){
            
            if(A == B){
                return 1;
            }
            return 0;
        }
        int a = B - A;
        
        if(a % C != 0){
            return false;
        }
        
        int n = a/C + 1;
        
        if(n <= 0){
            return false;
        }
        return true;
    }
};
