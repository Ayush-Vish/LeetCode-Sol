class Solution
{
public:
      int maxWeight(int n, vector<vector<int>> &edges, int k, int t)
      {
            /*
            //Contest solutions: @codingsolnss
            */
            vector<vector<pair<int, int>>> adj(n);
            for (auto &e : edges)
                  adj[e[0]].emplace_back(e[1], e[2]);
            const int NEG = -1;
            vector<vector<int>> dp(k + 1, vector<int>(n, NEG));
            /*
            //Contest solutions: @codingsolnss
            */
            for (int u = 0; u < n; ++u)
                  dp[0][u] = 0;
            for (int steps = 1; steps <= k; ++steps)
            {
                  for (int u = 0; u < n; ++u)
                        if (dp[steps - 1][u] >= 0)
                        {
                              for (auto &[v, w] : adj[u])
                              {
                                    int s = dp[steps - 1][u] + w;
                                    /*
                                    //Contest solutions: @codingsolnss
                                    */
                                    if (s < t)
                                          dp[steps][v] = max(dp[steps][v], s);
                              }
                        }
            }
            /*
            //Contest solutions: @codingsolnss
            */
            int ans = -1;
            for (int u = 0; u < n; ++u)
                  ans = max(ans, dp[k][u]);
            return ans;
      }
};
