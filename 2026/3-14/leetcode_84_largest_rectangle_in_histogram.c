#include <stdio.h>
int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize + 1];
    int top = -1;
    int MAX_ANS = 0;
    for (int i = 0; i <= heightsSize; i ++) {
        int current_height = (i == heightsSize) ? -1 : heights[i];
        while (top >= 0 && heights[stack[top]] > current_height) {
            int height = heights[stack[top --]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            int area = width * height;
            MAX_ANS = (area > MAX_ANS) ? area : MAX_ANS;
        }
        stack[++ top] = i;
    }   
    return MAX_ANS;
}