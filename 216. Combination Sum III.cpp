//https://leetcode.com/submissions/detail/870263510/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        string mask = "000000000";
        for(int i=0;i<k;i++){
            mask[i]='1';
        }
        sort(mask.begin(),mask.end());
        do{
            int sum = 0;
            vector<int>temp;
            for(int i=0;i<9;i++){
                if(mask[i]=='1'){
                    sum+=i+1;
                    temp.push_back(i+1);
                }
            }
            if(sum == n){
                ans.push_back(temp);
            }
        }while(next_permutation(mask.begin(),mask.end()));
        return ans;
    }
};
