class Solution {
public:
    string decodeString(string s) {

        stack<int> counts;
        stack<string> resultStack;

        string curr = "";
        int num = 0;

        for(char ch : s) {

            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if(ch == '[') {
                counts.push(num);
                resultStack.push(curr);

                num = 0;
                curr = "";
            }

            else if(ch == ']') {

                int repeat = counts.top();
                counts.pop();

                string temp = curr;

                curr = resultStack.top();
                resultStack.pop();

                while(repeat--) {
                    curr += temp;
                }
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};
