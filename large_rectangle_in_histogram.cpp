#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int largestRectangleArea(vector<int>& height) {
    height.push_back(0);
    const int size_h = height.size();
    stack<int> stk;
    int i = 0, max_a = 0;
    while (i < size_h) {
        if (stk.empty() || height[i] >= height[stk.top()]) stk.push(i++);
        else {
            // 保证当前的i比栈顶的高度高
            int h = stk.top();
            stk.pop();
            // i - stk.top() - 1 因为栈顶之后的序列必然是大于当前i以至于被弹出。所以长度为上一个栈顶位置+1直到当前位置
            max_a = max(max_a, height[h] * (stk.empty() ? i : i - stk.top() - 1));
        }
    }
    return max_a;
}

int main(int args, char ** argvs){
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(7);
    test.push_back(8);
    test.push_back(2);
    int max_val = largestRectangleArea(test);
    cout << "max_val:" << max_val << endl;
   
    return 0;
}
