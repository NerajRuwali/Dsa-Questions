class Solution {
public:
    bool canConstruct(string ransomeNote, string magazine) {
        unordered_map<char , int>m;

        for(int i = 0 ; i< magazine.size() ; i++){
            m[magazine[i]]++;
        }
        for(int i = 0 ; i < ransomeNote.size() ; i++){
            if(m[ransomeNote[i]] > 0){
                m[ransomeNote[i]]--;
            } else{
                return false;
            }
        }
        return true;
    }
};
        