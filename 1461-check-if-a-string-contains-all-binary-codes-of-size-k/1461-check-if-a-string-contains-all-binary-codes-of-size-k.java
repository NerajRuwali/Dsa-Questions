class Solution {
    public boolean hasAllCodes(String s, int k) {
        if (s.length() < k) return false;
        
        HashSet<String> set = new HashSet<>();
        
        for (int i = 0; i <= s.length() - k; i++) {
            String sub = s.substring(i, i + k);
            set.add(sub);
            
            // if combination found early stop kar dena
            if (set.size() == (1 << k)) {
                return true;
            }
        }
        
        return set.size() == (1 << k);
    }
}