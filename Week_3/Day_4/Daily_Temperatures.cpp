class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //optimal approach:

        int n =temperatures.size();
        stack<int>st;
        vector<int>result(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(st.empty()){
                result[i]= 0;
            }
            else{
                result[i]=st.top()-i;
            }
            st.push(i);
        }
        return result;
    }
};

// brute force:        
//         vector<int>result(n);
//      for(int i =0;i<n;i++){
//         for(int j =i+1;j<n;j++){
//             if(temperatures[j]>temperatures[i]){
//                 result[i]=j-i;
//                 break;
//             }
//         }
//      }
//     return result;
//     }
// };
