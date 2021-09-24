//https://www.codingninjas.com/codestudio/problems/check-if-one-string-is-a-rotation-of-another-string_1115683?leftPanelTab=0
//Method - 1
//TLE
void rotate(string &p){
    
    char ch = p[p.size() - 1];
    
    for(int i = p.size() - 1; i >= 1; i--){
        p[i] = p[i-1];
    }
    
    p[0] = ch;
}
int isCyclicRotation(string &p, string &q) 
{
    int n = p.size();
    
    while(n){
        
        if(p == q){
            return true;
        }
        
        rotate(p);
        n--;
    }
    return false;
}

//Method - 2
