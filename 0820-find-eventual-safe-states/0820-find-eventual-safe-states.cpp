class Solution {
public:
    vector<int> colors; // Color array to mark the states of nodes: 0 = unvisited, 1 = visiting, 2 = safe

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.assign(n, 0); // Initialize all nodes as unvisited
        vector<int> safeNodes; // List to hold the eventual safe nodes

        // Check each node to see if it's eventually safe
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph)) {
                safeNodes.push_back(i); // If it is safe, add it to the list
            }
        }

        return safeNodes; // Return the list of safe nodes
    }

    // Depth-first search to determine if a node is safe
    bool dfs(int nodeIndex, vector<vector<int>>& graph) {
        if (colors[nodeIndex]) {
            // If the node has been visited already, return true only if it's marked as safe
            return colors[nodeIndex] == 2;
        }

        colors[nodeIndex] = 1; // Mark the node as visiting
        for (int neighbor : graph[nodeIndex]) {
            // Explore all the neighbors of the current node
            if (!dfs(neighbor, graph)) {
                // If any neighbor is not safe, the current node is not safe either
                return false;
            }
        }

        colors[nodeIndex] = 2; // Mark the node as safe
        return true; // Return true as the node is safe
    }
};