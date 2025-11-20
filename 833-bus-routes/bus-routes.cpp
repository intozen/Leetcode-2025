#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();

        // Step 1: Map each stop to the buses that go through it
        unordered_map<int, vector<int>> stopToBuses;
        for (int bus = 0; bus < n; bus++) {
            for (int stop : routes[bus]) {
                stopToBuses[stop].push_back(bus);
            }
        }

        // Step 2: BFS initialization
        queue<pair<int, int>> q; // {current stop, bus count}
        q.push({source, 0});

        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        vector<bool> visitedBus(n, false);

        // Step 3: BFS traversal
        while (!q.empty()) {
            auto [curStop, busesTaken] = q.front();
            q.pop();

            // Explore all buses that pass through this stop
            for (int bus : stopToBuses[curStop]) {
                if (visitedBus[bus]) continue;  // skip already used buses
                visitedBus[bus] = true;

                // Visit all stops of this bus
                for (int nextStop : routes[bus]) {
                    if (nextStop == target) return busesTaken + 1;
                    if (!visitedStops.count(nextStop)) {
                        visitedStops.insert(nextStop);
                        q.push({nextStop, busesTaken + 1});
                    }
                }
            }
        }

        return -1;
    }
};
