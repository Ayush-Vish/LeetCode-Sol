class Solution {
public:
    void solve(int idx , int n ,int k, vector<vector<int>> &ans , vector<int> ds ) {
        
        if(idx > n ) {
            if(ds.size()==k ) {
                ans.push_back(ds) ;
                return ;
            }
            return ;
        }
        ds.push_back(idx);
        solve(idx+ 1 , n , k , ans ,ds ) ;
        ds.pop_back();
        solve(idx + 1 , n ,k  , ans ,ds );

    }

    // solve gives memory linit exceeded 
    
    void sol(int idx, int n , int k , vector<vector<int>> &ans ,vector<int> ds ) {
        if(ds.size() == k ) {
            ans.push_back(ds) ;
            return ;
        }
        for(int i = idx ; i <= n ;i ++) {
            ds.push_back(i); 
            sol(i +1 , n , k , ans , ds);
            ds.pop_back();

        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans ; 
        vector<int> ds;
        sol(1 ,n,k, ans , ds  );
        return ans ;

    }
};