class Solution {
public:
    // Parent array for Union-Find structure.
    vector<int> parent;

    // Function to find redundant connection in a graph represented as an edge list.
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Initialize the parent array for Union-Find, with self-pointing indices.
        parent.resize(1010);
        for (int i = 0; i < parent.size(); ++i) parent[i] = i;

        // Iterate over the edges.
        for (auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            // Check if merging two sets creates a cycle (i.e., they have the same parent).
            if (find(nodeA) == find(nodeB)) return edge; // If yes, then current edge is redundant.
            // Union the two sets.
            parent[find(nodeA)] = find(nodeB);
        }
        // If no redundant edge is found (which shouldn't happen), return an empty array.
        return {};
    }

    // Helper function to find the root parent of a node, with path compression.
    int find(int node) {
        if (parent[node] != node) { // Check if node is not its own parent (not root node).
            parent[node] = find(parent[node]); // Recursively find and set the root node.
        }
        return parent[node]; // Return the root node.
    }
};