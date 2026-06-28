class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // opening bracket : push it onto the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // closing bracket : check if it matches the last opened one
            else {
                if (st.empty()) return false; // Closing bracket with nothing opened
                
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')) {
                    st.pop(); // Matches perfectly, remove it
                } else {
                    return false; // Mismatch found
                }
            }
        }
        
        // If the stack is empty, all brackets were properly closed
        return st.empty();
    }
};