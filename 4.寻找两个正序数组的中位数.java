//核心是将问题转化为找到第k小的元素
//用二分法如果k/2位置的元素小于另一个array中的k/2位置的元素，那么这个元素往前可以全部排除掉。

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1 = nums1.length;
        int length2 = nums2.length;
        int totalLength = length1 + length2;
        if (totalLength % 2 == 1){
            int midIndex = totalLength / 2;
            double median = getKthElement(nums1, nums2, midIndex + 1); //如果一共七个就找第四小的
            return median;
        }
        else {
            int midIndex1 = totalLength/2 - 1;
            int midIndex2 = totalLength/2;
            double median = (getKthElement(nums1, nums2, midIndex1 + 1) + getKthElement(nums1, nums2, midIndex2 + 1))/2.0;
            return median;
        }
    }
    public int getKthElement(int[] nums1, int[] nums2, int k){
    int length1 = nums1.length;
    int length2 = nums2.length;
    int index1 = 0;
    int index2 = 0;
    int KthElement = 0;

    while (true) {
        //! 边界情况
        if (index1 == length1){
            return nums2[index2 + k - 1]; // 这里记得减1， 因为第四小的是在第三位的元素，index2指的是已经被删除的元素后面的那个位置
        }
        if (index2 == length2){
            return nums1[index1 + k - 1];
        }
        if (k == 1){
            return Math.min(nums1[index1],nums2[index2]);
        }

        // normal situation
        int half = k / 2;
        int newIndex1 = Math.min(index1 + half, length1) - 1; // 这里真的细节
        int newIndex2 = Math.min(index2 + half, length2) - 1;
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2){
            k -= newIndex1 - index1 + 1; //这里注意加1
            index1 = newIndex1 + 1;
        }
        else {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}
}


