class Solution {
    public String reverseWords(String s) {
        
        // Remove leading & trailing spaces
        s = s.trim();
        
        // Split by one or more spaces
        String[] words = s.split("\\s+");
        
        // Use StringBuilder to reverse
        StringBuilder result = new StringBuilder();
        
        for (int i = words.length - 1; i >= 0; i--) {
            result.append(words[i]);
            
            if (i != 0) {
                result.append(" ");
            }
        }
        
        return result.toString();
    }
}