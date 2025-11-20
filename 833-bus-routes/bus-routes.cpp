#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();

        unordered_map<int, vector<int>> stopToBuses;
        for (int bus = 0; bus < n; bus++) {
            for (int stop : routes[bus]) {
                stopToBuses[stop].push_back(bus);
            }
        }

      
        queue<pair<int, int>> q;
        q.push({source, 0});

        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        vector<bool> visitedBus(n, false);

        while (!q.empty()) {
            auto [curStop, busesTaken] = q.front();
            q.pop();

            for (int bus : stopToBuses[curStop]) {
                if (visitedBus[bus]) continue;  
                visitedBus[bus] = true;
                
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
