//https://leetcode.com/submissions/detail/869154474/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            g = gcd(g,numsDivide[i]);
        }
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        int ct = 0;
        for(auto i:m){
            if(g % i.first == 0){
                break;
            }
            ct += i.second;
        }
        return ct == nums.size() ? -1 : ct;
    }
};
