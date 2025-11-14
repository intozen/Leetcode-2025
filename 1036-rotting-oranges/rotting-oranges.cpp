class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            Same structure you wrote:
            1. Find all 2s → push into queue
            2. BFS level by level
            3. Turn 1s into 2s
            4. If any 1 remains → return -1
            5. Else return minutes
        */

        // Step 1: Collect all initial rotten oranges
        vector<pair<int,int>> positionOfTwos;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){   // FIXED: correct condition
                    positionOfTwos.push_back({i, j});
                }
            }
        }

        queue<pair<int,int>> q;
        for(auto it : positionOfTwos) {
            q.push(it);
        }

        int m = grid.size();
        int n = grid[0].size();

        // visited / distance matrix
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Directions for BFS
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int minutes = 0;

        // Step 2: BFS layer-by-layer
        while(!q.empty()) {

            int size = q.size();        // nodes in this layer
            bool didRot = false;        // tracks if a fresh orange rotted this minute

            while(size--) {
                auto coordinates = q.front();
                q.pop();

                int x = coordinates.first;
                int y = coordinates.second;

                // For each direction
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Valid bounds
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n) {

                        // We rot only fresh oranges
                        if(grid[nx][ny] == 1 && vis[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                            didRot = true;
                        }
                    }
                }
            }

            // only increase minutes if something changed in this layer
            if(didRot) minutes++;
        }

        // Step 3: After BFS, check if any fresh remains
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return minutes;
    }
};
