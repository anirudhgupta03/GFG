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
//Ref1: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
//Ref2: https://www.youtube.com/watch?v=5e63aHK6Q-E
int isCyclicRotation(string &p, string &q) 
{
    string text = p + p;
    string pattern = q;
    
    int n = q.size(), m = text.size();
    int lps[n];
    
    lps[0] = 0;
    
    int j = 0, i = 1;
    
    while(i < n){
        if(q[i] == q[j]){
            lps[i] = j + 1;
            i++;
            j++;
        } 
        else{
            if(j == 0){
                lps[i] = 0;
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    
    int p1 = 0, p2 = 0;
    
    while(p1 < m){
        
        if(text[p1] == pattern[p2]){
            p1++;
            p2++;
            if(p2 == n){
              return 1;
            }
        }
        else{
            if(p2 != 0) p2 = lps[p2 - 1];
            else		p1++;
        }
    }
    return 0;
}
