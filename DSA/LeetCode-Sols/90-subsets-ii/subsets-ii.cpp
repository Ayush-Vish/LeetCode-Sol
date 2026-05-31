class Solution {
public:
    void solve(int idx , vector<int > &arr , vector<vector<int>> &ans , vector<int> ds ) {
        if(idx> arr.size()) {
            return ;
        }
        
            ans.push_back(ds);


        for(int i =idx ;i< arr.size() ;i++) {
            if(i != idx && arr[i] == arr[i-1]) {
                continue;
            } 
            ds.push_back(arr[i]);
            solve(i +1 , arr, ans ,ds ) ;
            ds.pop_back();
        }

    }
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds ;
        sort(nums.begin() , nums.end());
        solve(0,nums, ans, ds);
        return ans;
    }
};