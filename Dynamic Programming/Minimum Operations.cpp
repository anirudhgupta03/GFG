  public:
    int minOperation(int n)
    {
        int count = 0;
        while(n){
            if(n % 2 == 0){
                n /= 2;
                count++;
            }
            else{
                n -= 1;
                count++;
            }
        }
        return count;
    }
};
