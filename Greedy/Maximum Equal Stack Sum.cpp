//https://www.codingninjas.com/codestudio/problems/maximum-equal-stack-sum_1062571?leftPanelTab=1
//Maximum Equal Stack Sum
int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3) {
    
    vector<int> v1, v2, v3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    
    while(stk1.size()){
       v1.push_back(stk1.top());
       sum1 += stk1.top();
       stk1.pop();
    }
        
    while(stk2.size()){
       v2.push_back(stk2.top());
       sum2 += stk2.top();
       stk2.pop();
    }
        
    while(stk3.size()){
       v3.push_back(stk3.top());
       sum3 += stk3.top();
       stk3.pop();
    }
    
    int p1 = 0, p2 = 0, p3 = 0;
    
    while(p1 < v1.size() && p2 < v2.size() && p3 < v3.size()){
        
        if(sum1 == sum2 && sum2 == sum3){
            return sum1;
        }
        else{
            
            if(sum1 >= sum2 && sum1 >= sum3){
                sum1 -= v1[p1];
                p1++;
            }
            else if(sum2 >= sum1 && sum2 >= sum3){
                sum2 -= v2[p2];
                p2++;
            }
            else{
                sum3 -= v3[p3];
                p3++;
            }
        }
    }
    return 0;
}
