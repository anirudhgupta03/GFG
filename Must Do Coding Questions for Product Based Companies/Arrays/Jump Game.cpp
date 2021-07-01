class Solution {
  public:
    int canReach(int A[], int N) {
        
        int maxCover = 0;
        
        for(int i = 0; i < N; i++){
            if(i <= maxCover){
                maxCover = max(i+A[i], maxCover);
            }
        }
        
        if(maxCover >= N - 1){
            return 1;
        }
        return 0;
    }
};
