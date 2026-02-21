class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int neeraj = 0;
        
        for (int num : nums) {
            if (count == 0) {
                neeraj = num;
            }
            count += (num == neeraj) ? 1 : -1;
        }
        return neeraj;
    }
}
