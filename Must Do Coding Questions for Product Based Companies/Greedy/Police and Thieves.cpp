class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
          vector<int> police, thief;
          
          for(int i = 0; i < n; i++){
              if(arr[i] == 'P'){
                  police.push_back(i);
              }
              else{
                  thief.push_back(i);
              }
          }
          
          int i = 0, j = 0, ans = 0;
          
          while(i < police.size() && j < thief.size()){
              if(abs(police[i] - thief[j]) <= k){
                  ans++;
                  i++;
                  j++;
              }
              else if(police[i] > thief[j]){
                  j++;
              }
              else{
                  i++;
              }
          }
          return ans;
    }
};
