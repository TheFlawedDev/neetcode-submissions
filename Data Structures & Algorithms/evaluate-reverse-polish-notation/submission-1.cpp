class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> numStack;  // holds the values to be processed

    for (int i = 0; i < tokens.size(); i++) {
      string value = tokens[i];
      int oP;
      int x;
      int y;

      if (value == "*") {
        x = numStack.top();
        numStack.pop();
        y = numStack.top();
        numStack.pop();
        oP = (y * x);
        numStack.push(oP);
        continue;
        break;
      } else if (value == "/") {
        x = numStack.top();
        numStack.pop();
        y = numStack.top();
        numStack.pop();
        oP = (y / x);
        numStack.push(oP);
        continue;
      }else if (value == "+"){
                x = numStack.top();
        numStack.pop();
        y = numStack.top();
        numStack.pop();
        oP = (y + x);
        numStack.push(oP);
        continue;
      }else if (value == "-"){
                x = numStack.top();
        numStack.pop();
        y = numStack.top();
        numStack.pop();
        oP = (y - x);
        numStack.push(oP);
        continue;
      }
      numStack.push(stoi(value));
    }
    return numStack.top();
  }
};
