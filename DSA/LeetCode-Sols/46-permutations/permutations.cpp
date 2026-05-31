class Solution {
    int n;
     vector<vector<int>> ans;//outer ans
     void solve(vector<int> nums, vector<int> v){
         if(v.size()==n){
             ans.push_back(v);
             return;
         }
         for(int i=0; i<nums.size(); i++){
             int x=nums[i];
             v.push_back(x);
             nums.erase(nums.begin()+i);
             solve(nums,v);
             v.pop_back();
            nums.insert(nums.begin()+i, x);
         }
     }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v; n=nums.size();
        solve(nums,v);
        return ans;
    }
};