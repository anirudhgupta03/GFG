class Solution{
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    void solve(int N, int from, int aux, int to, long long &count){
        
        if(N == 0){
            return;
        }
        
        solve(N-1,from,to,aux,count);
        
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        count++;
        
        solve(N-1,aux,from,to,count);
    }
    long long toh(int N, int from, int to, int aux) {
        
        long long count = 0;
        
        solve(N,from,aux,to,count);
        
        return count;
    }

};
