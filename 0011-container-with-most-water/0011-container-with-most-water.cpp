class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxwater = 0;
        while(left<right){
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width*h;
            maxwater = max(area , maxwater);
            if(height[left]<height[right]){
                left++;
            }
            else if(height[left]> height[right]){
                right--;
            }
            else{
                left++;
                right--;
            }
        }
        return maxwater;
    }
};