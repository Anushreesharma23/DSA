/*11. Container With Most Water. Medium.
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r){
            int h = min(height[l], height[r]);
            maxArea= max(maxArea,h*(r-l));
                if(height[l]<height[r]){
                    l++;
                }
                else{
                    r--;
                }
        }
        return maxArea;
    }
};
