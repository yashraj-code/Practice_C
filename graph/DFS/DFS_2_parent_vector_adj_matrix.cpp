#include <iostream>
#include <vector>

using namespace std;

void dfs_new(int node, int parent, const vector<vector<int>>& adjMatrix, vector<int>& parent_list) {
    // Assign parent
    parent_list[node] = parent;
    
    // Iterate over all possible nodes
    for (int child = 0; child < adjMatrix[node].size(); child++) {
        // If there is an edge and the child is not the parent
        if (adjMatrix[node][child] == 1 && child != parent) {
            // Recursively visit the child node
            dfs_new(child, node, adjMatrix, parent_list);
        }
    }
}

int main() {
    int vertices = 11;
    
    // Create an adjacency matrix
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    
    // Adding edges
    adjMatrix[1][2] = adjMatrix[2][1] = 1;
    adjMatrix[2][9] = adjMatrix[9][2] = 1;
    adjMatrix[2][4] = adjMatrix[4][2] = 1;
    adjMatrix[2][5] = adjMatrix[5][2] = 1;
    adjMatrix[5][6] = adjMatrix[6][5] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;
    adjMatrix[3][7] = adjMatrix[7][3] = 1;
    adjMatrix[3][8] = adjMatrix[8][3] = 1;
    adjMatrix[1][10] = adjMatrix[10][1] = 1;

    // Vector to store parent information
    vector<int> parent_list(vertices, -1);
    
    // Start DFS from node 1 (assuming it's the root) with no parent (-1)
    dfs_new(1, -1, adjMatrix, parent_list);
    
    // Printing the parent of nodes
    for (int i = 1; i < parent_list.size(); i++) {
        cout << "Node-> " << i << " parent-> " << parent_list[i] << endl;
    }

    return 0;
}
