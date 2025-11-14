class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;   // will store all rotten oranges
        int fresh = 0;            // count of all fresh oranges

        // Step 1: find all rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If no fresh oranges → no time needed
        if (fresh == 0) return 0;

        // Directions: down, up, right, left
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int minutes = 0;

        // Step 2: BFS (multi-source)
        while (!q.empty()) {

            int size = q.size();         // how many to process this minute
            bool rotted = false;         // track if any orange got rotten now

            while (size--) {

                pair<int,int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                // Check all 4 directions
                for (auto &d : dirs) {

                    int nx = x + d[0];
                    int ny = y + d[1];

                    // --- EASY IF STATEMENTS START HERE ---

                    // Step A: boundary checks
                    if (nx < 0) continue;
                    if (nx >= m) continue;
                    if (ny < 0) continue;
                    if (ny >= n) continue;

                    // Step B: check if fresh orange
                    if (grid[nx][ny] == 1) {

                        // Step C: rot this fresh orange
                        grid[nx][ny] = 2;

                        // Step D: decrease number of fresh oranges
                        fresh--;

                        // Step E: push to queue (it will rot others next minute)
                        q.push({nx, ny});

                        // Step F: something changed in this minute
                        rotted = true;
                    }
                }
            }

            // Only increase time if at least one orange rotted this minute
            if (rotted) minutes++;
        }

        // Step 3: If fresh oranges remain → impossible
        if (fresh > 0) return -1;

        return minutes;
    }
};
