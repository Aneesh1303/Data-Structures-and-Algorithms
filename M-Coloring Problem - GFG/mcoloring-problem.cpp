//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int sv, int color[], int n, bool graph[101][101], int col) {
        for(int k=0; k<n; k++) {
            if(k!=sv && graph[k][sv] == 1 && color[k] == col) return false;
        }
        
        return true;
    }
    
    bool solve(int sv, int color[], int m, int n, bool graph[101][101]) {
        if(sv == n) {
            return true;
        }
        
        for(int i=1; i<=m; i++) {
            if(isSafe(sv, color, n, graph, i)) {
                color[sv] = i;
                if(solve(sv+1, color, m, n, graph)) return true;
                color[sv] = 0;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        
        if(solve(0, color, m, n, graph)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends