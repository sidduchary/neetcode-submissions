class Solution {
public:
    int vis[20][20];
    vector<int> drow = {1,0,-1,0};
    vector<int> dcol = {0,-1,0,1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1) {
                    vis[i][j] = -1;
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;
        int cnt=0;
        while(!q.empty() && fresh > 0) {
            int l = q.size();
            cnt++;
            while(l--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0; i<4; i++) {
                    int r = drow[i] +x, c = dcol[i]+y;
                    if(r>=0 && c>=0 && r<n && c<m && 
                    grid[r][c] == 1 && vis[r][c] == -1) {
                        vis[r][c] = 1;
                        q.push({r, c});
                        fresh--;
                    }
                }

            }
        }
        if(fresh == 0) return cnt;
        return -1;
    }
};
