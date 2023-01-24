//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool safe(int row, int col, int n, vector<vector<int>> &m) {
        if(row>=0 && row <n && col>=0&& col<n) {
            if(m[row][col] != 0) {
                return true;   
            }
        }
        
        return false;
    }
    
    void helper(int row, int col, vector<vector<int>> &m, int n, vector<string> &ans, string & temp, vector<vector<bool>> &vis) {
        if(row == n-1 && col == n-1) {
            ans.push_back(temp);
            return;
        }
        vis[row][col] = true;
        
        if(safe(row,col+1,n,m) && !vis[row][col+1]) {
            temp.append("R");
            helper(row,col+1,m,n,ans,temp,vis);
            vis[row][col+1] = false;
            temp.pop_back();
        }
        
        if(safe(row+1, col,n,m) && !vis[row+1][col]) {
            temp.append("D");
            helper(row+1,col,m,n,ans,temp,vis);
            vis[row+1][col] = false;
            temp.pop_back();
        }
        
        if(safe(row, col-1,n,m) && !vis[row][col-1]) {
            temp.append("L");
            helper(row,col-1,m,n,ans,temp,vis);
            vis[row][col-1] = false;
            temp.pop_back();
        }
        
        if(safe(row-1, col,n,m) && !vis[row-1][col]) {
            temp.append("U");
            helper(row-1,col,m,n,ans,temp,vis);
            vis[row-1][col] = false;
            temp.pop_back();
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string temp;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return ans;
        
        vector<vector<bool>> vis(n, vector<bool>(n));
        helper(0, 0, m, n, ans, temp, vis);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends