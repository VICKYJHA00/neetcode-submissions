class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char>closedToOpen = {
            {')' , '('},
            {'}' , '{'},
            {']' , '['}
        };

        for(char c : s){
            if(closedToOpen.count(c)){
                if(!stack.empty() && stack.top() == closedToOpen[c]){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
