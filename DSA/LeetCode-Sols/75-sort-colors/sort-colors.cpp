class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one =0 ;
        int zero= 0 ;
        int two =0 ;
        for(int i=0 ;i< nums.size() ;i++){
            if(nums[i] == 1){
                one ++;

            } 
            else if(nums[i] == 0){
                zero ++;

            }else{
                two++;

            }
        }
        int k =0 ;
        
        for(int  i= 0 ;k!= zero;i++){
            nums[i]=0;
            k++;

            
        }
        for(int i= k ; one-- ;i++){
            nums[i] = 1;
            k++;

        }
        for(int i=k ;two-- ; i++){
            nums[i] =2;
            k++;
            
        }



    }
};