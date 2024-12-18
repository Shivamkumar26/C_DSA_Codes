class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size(), n = nums1.size();
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i=m-1; i>=0; i--) {
            while(st.size() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(st.size()) mp[nums2[i]] = st.top();
            else {
                mp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            res[i] = mp[nums1[i]];
        } 
        return res;
    }
};

/*


4

3 4 -1 -1

*/