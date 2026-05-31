class Solution {
public:

    void solve(int i, vector<int> arr, int target ,vector<int> ds ,vector<vector<int>> &ans) {
    
        if(target == 0 ) {
            ans.push_back(ds);
            return ; 
        }
        for(int k = i ; k < arr.size() ;k ++) {
            
            if(k > i  && arr[k] == arr[k-1] ) continue;
            if(target <arr[i]  )  {
               break; 
            }
            ds.push_back(arr[k]);

            solve(k+1, arr ,target - arr[k], ds , ans);
            ds.pop_back();
        } 
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end()) ;
        
        vector<vector<int >> ans ;
        vector<int> ds;
        solve(0,candidates , target , ds ,ans) ;
        return ans ;
    }
};