class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int neeraj = 0;
        
        for (int num : nums) {
            if (count == 0) {
                neeraj = num;
            }
            if (num == neeraj) {
    count += 1; 
} else {
    count -= 1;  
}

        }
        return neeraj;
    }
}
