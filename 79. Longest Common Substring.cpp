//https://www.geeksforgeeks.org/longest-common-substring-dp-29/
//100%  test cases passedTotal runtime: 50ms
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.size(), n = B.size();
        
        //padding ahead
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        int ans = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                //dp[i][j]: longest common suffix for A[0...i-1] and B[0...j-1]
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
