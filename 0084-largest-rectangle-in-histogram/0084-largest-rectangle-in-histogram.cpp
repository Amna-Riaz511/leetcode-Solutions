class Solution {
public:

    int largestRectangleArea(vector<int>& height) {
        stack<int>s;
        int n = height.size();
        vector<int>right(n,0);
        vector<int>left(n,0);
        //right one smallest nearest smallest element
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.size()==0)   right[i] =n;
            else{
                right[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        //left one smallest nearest value
        int area =0;
        for(int i=0;i<n;i++){
            while(s.size()>0 && height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.size()==0)  left[i] =-1;
            else{
             left[i] = s.top();
            }
            s.push(i);
            int width = right[i]-left[i]-1;
            int currentarea = height[i]*width;
            area = max(currentarea,area);
        }
        return area;

    }
};