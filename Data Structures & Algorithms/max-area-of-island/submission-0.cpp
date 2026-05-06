class Solution {
    
private:
    int noIslands(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &vis,int n,int m) {
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int cnt = 1;

        vector<int> drow = {0,1,0,-1};
        vector<int> dcol = {1,0,-1,0};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first, col = it.second;
            for(int i=0; i<4; i++) {
                int r = row+ drow[i], c = col+ dcol[i];
                if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]== 1) {
                    q.push({r,c});
                    vis[r][c] = 1;
                    cnt++;
                }
            }
        }
        return cnt;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int mxArea = 0 ;
        for(int i = 0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    mxArea = max(mxArea, noIslands(i,j, grid, vis,n,m));
                }
            }
        }
        return mxArea;
    }
};
