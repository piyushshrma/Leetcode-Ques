class Solution {
public:
    // Entry function that calculates the maximum number of invitations.
    int maximumInvitations(vector<int>& favorite) {
        // Determine the maximum between the longest cycle in the graph and
        // the maximum sum of two paths stemming from a mutual favorite pair.
        return max(findMaxCycle(favorite), topologicalSortAndPairSum(favorite));
    }
  
    // Function to find the maximum length of a cycle in the graph.
    int findMaxCycle(vector<int>& favorites) {
        int numStudents = favorites.size();
        vector<bool> visited(numStudents, false);
        int maxCycleLength = 0;
      
        // Iterate through all students.
        for (int i = 0; i < numStudents; ++i) {
            if (visited[i]) continue;
            vector<int> cycle;
            int current = i;
          
            // Identify a cycle starting from student 'i'.
            while (!visited[current]) {
                cycle.push_back(current);
                visited[current] = true;
                current = favorites[current];
            }
          
            // Check if the identified cycle contains 'j' and calculate the cycle's length.
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == current) {
                    maxCycleLength = max(maxCycleLength, (int)cycle.size() - k);
                    break;
                }
            }
        }
        return maxCycleLength;
    }

    // Function to perform topological sort and sum the distances of mutual favorite pairs.
    int topologicalSortAndPairSum(vector<int>& favorites) {
        int numStudents = favorites.size();
        vector<int> inDegree(numStudents, 0);
        vector<int> distance(numStudents, 1);
      
        // Calculate in-degrees of the students.
        for (int fav : favorites) ++inDegree[fav];
      
        queue<int> queue;
      
        // Enqueue students with an in-degree of 0.
        for (int i = 0; i < numStudents; ++i) {
            if (inDegree[i] == 0) queue.push(i);
        }
      
        // Perform topological sort.
        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            distance[favorites[current]] = max(distance[favorites[current]], distance[current] + 1);
          
            // Reduce the in-degree of the current node's favorite and enqueue if it becomes 0.
            if (--inDegree[favorites[current]] == 0) {
                queue.push(favorites[current]);
            }
        }
      
        int pairSum = 0;
        // Calculate the total sum of distances for mutually favorite pairs.
        for (int i = 0; i < numStudents; ++i) {
            if (i == favorites[favorites[i]]) {
                pairSum += distance[i];
            }
        }
        return pairSum;
    }
};