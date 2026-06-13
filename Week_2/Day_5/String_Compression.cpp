class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index=0;
        int i=0;
        while(i<n){
            char curr_char = chars[i];
            int count =0;
            // count duplicate :
            while(i<n && curr_char == chars[i]){
                count++;
                i++;
            }
            // assign the index and count , modify the input
            chars[index]=curr_char;
            index++;
            if(count>1){
                string char_str = to_string(count);
                for(char &ch : char_str){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};
