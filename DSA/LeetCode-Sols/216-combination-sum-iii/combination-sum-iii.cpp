class Solution {
public:
    void solve(int  idx , vector<int> arr , int target , vector<int> ds , vector<vector<int>> &ans ,int k) {
       if(target ==0 && ds.size() == k ) {
           ans.push_back(ds);
           return;
       }
       if(idx >= arr.size()) return ;
       if(ds.size() >k) return ;
        for(int i = idx  ;i < arr.size() ;i++) {
            if(arr[i] > target ) break;
            ds.push_back(arr[i]);
            solve(i +1, arr , target -arr[i]  ,ds , ans , k ) ;
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        for(int i=0 ;i < 9 ;i++) {
            arr.push_back(i+1);
        }
        vector<vector<int> > ans ;
        vector<int> ds;
        
        solve(0 ,arr, n  , ds ,ans , k  ) ;
        return ans;

        
    }
};