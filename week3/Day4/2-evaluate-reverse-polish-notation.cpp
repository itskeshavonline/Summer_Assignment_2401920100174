class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& t : tokens) {
            
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int num2 = st.top(); st.pop(); // First pop is the right side
                int num1 = st.top(); st.pop(); // Second pop is the left side
                
                if (t == "+") st.push(num1 + num2);
                else if (t == "-") st.push(num1 - num2);
                else if (t == "*") st.push(num1 * num2);
                else if (t == "/") st.push(num1 / num2);
            } 
            else {
                // converting number string to an integer and push
                st.push(stoi(t));
            }
        }
        
        // The final remaining number is our total result
        return st.top();
    }
};