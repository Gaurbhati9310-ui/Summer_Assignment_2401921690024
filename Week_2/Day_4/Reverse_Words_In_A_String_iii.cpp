class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result = "";
        string token = "";
        
        while (ss >> token) {
            reverse(token.begin(), token.end());
            result += token + " ";
        }
        
        return result.substr(0, result.length() - 1); // fix here
    }
};
        //appraoch 1:
    //     int n =s.length();
    //     for(int i=0;i<n;i++){
                

    //         if(s[i]!=' '){
    //             int j=i;
    //             while(j<n && s[j]!=' '){
    //                 j++;
    //             }
    //             reverse(begin(s)+i,begin(s)+j);
    //             i=j-1;
    //         }
        
    //     }
    //     return s;
    // }
// };
