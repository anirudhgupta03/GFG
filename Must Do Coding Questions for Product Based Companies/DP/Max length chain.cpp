/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool cmp(struct val p1, struct val p2){
    return p1.second < p2.second;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,cmp);
    
    int end = p[0].second, count = 1;
    
    for(int i = 1; i < n; i++){
        if(p[i].first > end){
            count++;
            end = p[i].second;
        }
    }
    return count;
}
