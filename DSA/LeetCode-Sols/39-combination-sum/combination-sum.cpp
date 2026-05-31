class Solution {
public:
    void solve(vector<int> arr, int target , vector<int> v, vector<vector<int>> &ans, int  i ) { 
        if(i>=arr.size() ) {
            if(target == 0 ) {
                ans.push_back(v);
                return ;
            }else {
                return;
            }
        }
        if(arr[i] <= target) {
            v.push_back(arr[i]) ;

            solve(arr ,target - arr[i] , v, ans, i );
            v.pop_back();
        }
       
        solve(arr , target  , v,ans , i +1) ;
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int >> ans;
        vector<int> v;
        solve(candidates , target , v, ans , 0 ) ;
        return ans;

    }
};