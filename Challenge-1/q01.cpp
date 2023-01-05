// https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto token : tokens)
        {
            if (token == "+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (token == "-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            }
            else if (token == "*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            }
            else if (token == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            }
            else
            {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};