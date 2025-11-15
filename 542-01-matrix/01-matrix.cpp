class Solution {
public:
    // int bfs(vector<vector<int>> mat, int i , int j) {
    //     int m = mat.size();
    //     int n = mat[0].size();
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     vector<vector<int>>vis(m, vector<int>(n,-1));
    //     int cnt = 0;
    //     while(!q.empty()) {
    //         auto [x,y] = q.front();
    //         q.pop();
    //         vis[x][y] = 0;
    //         vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    //         for(auto it : directions) {
    //             int k = x + it.first;
    //             int p = y + it.second;
    //             if (k >= 0 && k < m && p >= 0 && p < n &&
    //                     vis[k][p] == -1) {
    //                         vis[k][p] = 0;
    //                        if(mat[k][p] == 1) {
    //                         cnt++;
    //                        }
    //                        else return cnt;
    //             }
                
    //         }
    //     }
    //     return 0;
    // }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       
       if (mat.empty() || mat[0].empty())
            return {};
        int m = mat.size();
        int n = mat[0].size();
         int mx = m * n;
         
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    mat[i][j] = mx;
                }
                else q.push({i,j});
            }
        }
        vector<pair<int,int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            for(auto it: directions) {
                int r = x+it.first;
                int c = y+it.second;
                if(r>=0&&r<m && c>=0 && c<n && mat[r][c] > mat[x][y]+1) {
                    q.push({r,c});
                    mat[r][c] = mat[x][y] + 1;
                }
            }
        }
        return mat;
    }
};