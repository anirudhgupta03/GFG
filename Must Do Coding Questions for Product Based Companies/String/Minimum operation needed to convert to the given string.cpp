//https://www.codingninjas.com/codestudio/problems/minimum-cost_630564?leftPanelTab=0
int minCostToGivenString(string str1, string str2)
{
    int n1 = str1.size(), n2 = str2.size();
    
    if(n1 != n2){
        return -1;
    }
    
    int count[256] = {0};
    for(int i = 0; i < n1; i++){
        count[str1[i]]++;
    }
    for(int i = 0; i < n2; i++){
        count[str2[i]]--;
    }
    
    for(int i = 0; i < 256; i++){
        if(count[i] != 0){
            return -1;
        }
    }
    
    int res = 0;
    int i = 0, j = 0;
    
    while(i < n1){
        while(i < n1 && str1[i] != str2[j]){
            i++;
            res++;
        }
        
        if(i < n1){
            i++;
            j++;
        }
    }
    return res;
}
