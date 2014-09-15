
#include "leetcode_string.h"

//https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

vector<char> signs= {'+','-','*','/'};

static bool isSign(const char sign){
    for(int i = 0; i < (int)signs.size(); i++){
        if(signs[i] == sign)
            return true;
    }
    return false;
}

static int calculate(int first,int second,const char sign){
    if(sign == '+') return first + second;
    if(sign == '-') return first - second;
    if(sign == '*') return first * second;
    if(sign == '/') return first / second;
    return 0;
}

int evalRPN(vector<string> &tokens) {
    int length = (int)tokens.size();
    if(length == 0) return 0;
    int first,second;
    stack<int> st;
    for(int i = 0; i < length; i ++){
        if(tokens[i].size() == 1 && isSign(tokens[i].c_str()[0])){
            second = st.top();
            st.pop();
            first = st.top();
            st.pop();
            const char p = tokens[i].c_str()[0];
            st.push(calculate(first, second, p));
        }else{
            st.push(atoi(tokens[i].c_str()));
        }
    }
    int res = st.top();
    st.pop();
    return res;
}

void testEvalRPN(){
    vector<string> testSt = {"-1","1","*","-1","+"};
    int res = evalRPN(testSt);
    cout << res << endl;
}