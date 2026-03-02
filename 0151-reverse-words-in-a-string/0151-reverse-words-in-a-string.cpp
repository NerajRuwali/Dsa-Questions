class Solution {
public:
    void reverseStr(string &s, int left, int right) {
        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseWords(string s) {
        int n = s.size();
        int index = 0;

        // Remove extra spaces
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                if(index != 0) s[index++] = ' ';
                while(i < n && s[i] != ' ') {
                    s[index++] = s[i++];
                }
            }
        }

        s.resize(index);

        //  Reverse entire string
        reverseStr(s, 0, s.size() - 1);

        //  Reverse each word
        int start = 0;
        for(int i = 0; i <= s.size(); i++) {
            if(i == s.size() || s[i] == ' ') {
                reverseStr(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }
};