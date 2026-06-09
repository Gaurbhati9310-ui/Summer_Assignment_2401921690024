class Solution {
public:
// approach3:
// sliding window:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        // first window
        for(int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if(cnt1 == cnt2) return true;

        // sliding window
        for(int i = n; i < m; i++) {

            cnt2[s2[i] - 'a']++;       // add new char
            cnt2[s2[i - n] - 'a']--;   // remove old char

            if(cnt1 == cnt2) {
                return true;
            }
        }

        return false;
    }
};
// approach 2 :
// bool checkInclusion(string s1, string s2){
    
//      sort(s1.begin(),s1.end());
//      int n = s1.length();
//      int m = s2.length();
//      if(n>m){
//         return false;
//      }
//      for(int i=0;i<m;i++){
//         string temp = s2.substr(i,n);
//         sort (temp.begin(), temp.end());
//         if(temp==s1){
//             return true;
//         }
//      }
//      return false;
// }
// };
// approach1 : brute force 
// vector<string> permutation(string s1) {
//     vector<string> ans;

//     sort(s1.begin(), s1.end());

//     do {
//         ans.push_back(s1);
//     } while (next_permutation(s1.begin(), s1.end()));

//     return ans;
// }
//     bool checkInclusion(string s1, string s2) {
//         vector<string>per = permutation(s1);
//         for(auto &p : per){
//             if(s2.find(p) != string::npos){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

