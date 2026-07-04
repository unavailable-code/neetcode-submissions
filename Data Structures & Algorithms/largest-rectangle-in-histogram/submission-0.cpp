class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;     
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {

                int height = heights[st.top()];
                st.pop();

                int leftBoundary;

                if (st.empty())
                    leftBoundary = -1;
                else
                    leftBoundary = st.top();

                int width = i - leftBoundary - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        while (!st.empty()) {

            int height = heights[st.top()];
            st.pop();

            int leftBoundary;

            if (st.empty())
                leftBoundary = -1;
            else
                leftBoundary = st.top();

            int width = heights.size() - leftBoundary - 1;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};