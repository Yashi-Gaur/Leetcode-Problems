class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int h = height.size()-1;
        int area = 0;
        while(l < h)
        {
            if(height[l] >= height[h])
            {
                area = max(area, (h-l)*height[h]);
                h--;
            }
            else
            {
                area = max(area, (h-l)*height[l]);
                l++;
            }
        }
        return area;
    }
};