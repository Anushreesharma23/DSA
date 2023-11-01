class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int>m;
        for(int i=0; i<=n-2; i++){
            int j = i+1;
            for(j =i+1; j<=n-1; j++){
                if(nums2[i]<nums2[j]){
                    m[nums2[i]]=nums2[j];
                    break;
                }
            }
            if(j==n){
                m[nums2[i]]=-1;
            }
        }
        m[nums2[n-1]]=-1;
        vector<int>result;
        for(int i =0; i<nums1.size();i++){
            int value= nums1[i];
            result.push_back(m[value]);
        }
        return result;
    }
};