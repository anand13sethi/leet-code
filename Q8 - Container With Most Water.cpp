/*
Link - https://leetcode.com/problems/container-with-most-water
*/


int maxArea(vector<int>& height) {
    int s = height.size(), max_so_far = 0, h;
    int i = 0, j = s-1;
    while(i < j){
        h = (j-i) * min(height[i], height[j]);
        max_so_far = max(max_so_far, h);
        if(height[i] < height[j])
            i++;
        else
            j--;
    }
    return max_so_far;
}