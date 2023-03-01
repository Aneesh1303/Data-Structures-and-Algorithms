class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int cnt = 0;
        bool flag = true;
        vector<int> temp(n);
        
        for(int i=0; i<n; i++) {
            temp[i] = heights[i];
        }
        
        while(flag) {
            flag = false;
            for(int i=0; i<n-1; i++) {
                if(temp[i] > temp[i+1]) {
                    swap(temp[i], temp[i+1]);
                    flag = true;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(temp[i] != heights[i]) cnt++;
        }
        
        return cnt;
    }
};