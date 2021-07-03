class Solution{
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void solve(int sr, int sc, vector<vector<int>>& image, int newColor, vector<vector<int>> &vis, int oldColor){
        
        image[sr][sc] = newColor;
        vis[sr][sc] = 1;
        
        for(int i = 0; i < 4; i++){
            
            int sro = sr + dx[i], sco = sc + dy[i];
            
            if(sro >= 0 && sro < image.size() && sco >= 0 && sco < image[0].size() && vis[sro][sco] == 0){
                
                if(image[sro][sco] == oldColor){
                    solve(sro,sco,image,newColor,vis,oldColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int m = image.size(), n = image[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int oldColor = image[sr][sc];
        
        solve(sr,sc,image,newColor,vis,oldColor);
        
        return image;
    }
};
