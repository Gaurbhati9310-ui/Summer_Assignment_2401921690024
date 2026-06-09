class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int k = p.size();

        vector<int> ans;

        if(k > n) return ans;

        vector<int> cntP(26, 0);
        vector<int> cntS(26, 0);

        // first window
        for(int i = 0; i < k; i++) {
            cntP[p[i] - 'a']++;
            cntS[s[i] - 'a']++;
        }

        if(cntP == cntS) {
            ans.push_back(0);
        }

        // slide window
        for(int i = k; i < n; i++) {

            cntS[s[i] - 'a']++;       // add new char
            cntS[s[i - k] - 'a']--;   // remove old char

            if(cntP == cntS) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};
