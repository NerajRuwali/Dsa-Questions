class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int i = m - 1;        // Last actual element in nums1
        int j = n - 1;        // Last element in nums2
        int k = m + n - 1;    // Last position of nums1
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // Agar nums2 me element bachte ha 
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
}