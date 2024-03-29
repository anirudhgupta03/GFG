class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        long long int ans = 0;
        
        sort(a,a+n);
        
        for(int i = 0; i < n; i++){
            if(a[i] < 0 && k != 0){
                a[i] = -1*a[i];
                k--;
            }
            ans += a[i];
        }
        
        sort(a,a+n);
        
        if(k % 2 == 0){
            return ans;
        }
        else{
            return ans - 2*a[0];
        }
    }
};

//Alter
class Solution{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        long long sum = 0;
        
        sort(a, a + n);
        
        for(int i = 0; i < n; i++){
            
            if(a[i] < 0){
                if(k != 0){
                    sum -= a[i];
                    k--;
                }
                else{
                    sum += a[i];
                }
            }
            else{
                if(k != 0){
                    if(k % 2 != 0){
                        sum -= a[i];
                    }
                    else{
                        sum += a[i];
                    }
                    k = 0;
                }
                else{
                    sum += a[i];
                }
            }
        }
        
        if(k % 2 != 0){
            sum += 2*a[n-1];
        }
        return sum;
    }
};
