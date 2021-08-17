//https://www.codingninjas.com/codestudio/problems/break-the-board_1115781?leftPanelTab=0
//https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
int minimumCost(vector<int> row, vector<int> column, int l, int w)
{
	  sort(row.begin(),row.end(),greater<int>());
    sort(column.begin(),column.end(),greater<int>());
    
    int hcut = 0, vcut = 0;
    
    int p1 = 0, p2 = 0;
    
    int minCost = 0;
    
    while(p1 < row.size() && p2 < column.size()){
        if(row[p1] > column[p2]){
            hcut++;
            minCost += (vcut + 1)*row[p1];
            p1++;
        }
        else{
            vcut++;
            minCost += (hcut + 1)*column[p2];
            p2++;
        }
    }
    while(p1 < row.size()){
        minCost += (vcut + 1)*row[p1];
        p1++;
    }
    while(p2 < column.size()){
        minCost += (hcut + 1)*column[p2];
        p2++;
    }
    return minCost;
}
