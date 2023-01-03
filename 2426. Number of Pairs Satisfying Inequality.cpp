//https://leetcode.com/submissions/detail/870519382/

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;//using less_equal for the multiset
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>v;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            v.push_back(nums1[i]-nums2[i]);
        }
        long long ct = 0;
        pbds x;
        //the equality formed is v[i]<=diff+v[j] where i<j
        map<int,int>m;//had to keep a map because order_of_key in pbds only gives strictly smaller
                      //but i needed equality case as well.
        for(int j = 0; j<n; j++){
            ct+=x.order_of_key(diff+v[j]);//strictly smaller
            ct+=m[diff+v[j]];//equal ones
            x.insert(v[j]);
            m[v[j]]++;
        }
        return ct;
    }
};
