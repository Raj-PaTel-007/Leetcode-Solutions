#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        ordered_set st1, st2;
        vector<int> arr1, arr2;
        st1.insert({nums[0], 0});
        arr1.push_back(nums[0]);
        st2.insert({nums[1], 1});
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++) {
            int el = nums[i];

            int le1 = st1.order_of_key({el + 1, -1});
            int le2 = st2.order_of_key({el + 1, -1});

            int cnt1 = st1.size() - le1;
            int cnt2 = st2.size() - le2;

            if(cnt1 > cnt2) {
                st1.insert({el, i});
                arr1.push_back(el);
            }
            else if(cnt1 < cnt2) {
                st2.insert({el, i});
                arr2.push_back(el);
            }
            else {
                if(st1.size() <= st2.size()) {
                    st1.insert({el, i});
                    arr1.push_back(el);
                }
                else {
                    st2.insert({el, i});
                    arr2.push_back(el);
                }
            }
        }

        vector<int> ans;

        for(auto x : arr1) ans.push_back(x);
        for(auto x : arr2) ans.push_back(x);

        return ans;
    }
};