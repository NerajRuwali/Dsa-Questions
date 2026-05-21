class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> st;

        for(int num : arr1){
            string s = to_string(num), t = "";
            
            for(char c : s){
                t += c;
                st.insert(t);
            }
        }

        int result = 0;

        for(int num : arr2){
            string s = to_string(num), t = "";

            for(char c : s){
                t += c;

                if(st.count(t))
                    result = max(result, (int)t.size());
            }
        }

        return result;
    }
};