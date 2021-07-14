class Solution{
public:
    int maxLength(string S){
        
        stack<int> ind;
        stack<char> character;
        
        ind.push(-1);
        
        int maxValidLen = 0;
        
        for(int i = 0; i < S.size(); i++){
            
            if(S[i] == '('){
                character.push('(');
                ind.push(i);
            }
            else{
                
                if(character.empty() || character.top() == ')'){
                    character.push(')');
                    ind.push(i);
                }
                else{
                    ind.pop();
                    maxValidLen = max(maxValidLen,i-ind.top());
                    character.pop();
                }
            }
        }
        
        return maxValidLen;
    }
};
