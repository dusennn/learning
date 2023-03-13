import java.util.*;

/**
 * 004: 寻找两个正序数组的中位数
 * ❌
 */
public class T004 {
	/**
    1. 先求出两个数组的长度。
    2. 两个数组长度之和/2 代表中位数所在的数组下标，
    因为中位数可能是两位数之和或者一位数，所以把中位数的下标全都放入 set中，便于比较和处理。
    3. 循环两个数组，进行类似归并排序中的合并操作，循环次数满足条件二，即找到了中位数。
     */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        var midIndexs = getMidIndexs(len1, len2);
        var maxMidIndex = Collections.max(midIndexs);

        double mid = 0.0;
        int i1 = 0, i2 = 0, prev = 1;
        while (i1 < len1 && i2 < len2 && i1 + i2 < maxMidIndex + 1) {
            if (midIndexs.contains(i1+i2)) {
                if (prev == 1) {
                    mid += nums1[i1];
                } else {
                    mid += nums2[i2];
                }
            }

            if (nums1[i1] < nums2[i2]) {
                i1++;
                prev = 1;
            } else {
                i2++;
                prev = 2;
            }
        }
        if (midIndexs.contains(i1+i2)) {
            if (prev == 1) {
                mid += nums1[i1 < len1 ? i1:i1-1];
            } else {
                mid += nums2[i2 < len2 ? i2:i2-1];
            }
        }

        while (i1 < len1 && i1 + i2 < maxMidIndex + 1) {
            if (midIndexs.contains(i1 + (i2 < len2 ? i2:i2-1))) {
                mid += nums1[i1];
            }
            i1++;
            prev = 1;
        }

        while (i2 < len2 && i1 + i2 < maxMidIndex + 1) {
            if (midIndexs.contains((i1 < len1 ? i1:i1-1) + i2)) {
                mid += nums1[i2];
            }
            i2++;
            prev = 2;
        }
        
        if (midIndexs.contains(i1+i2)) {
            if (prev == 1) {
                mid += nums1[i1 < len1 ? i1:i1-1];
            } else {
                mid += nums2[i2 < len2 ? i2:i2-1];
            }
        }

        return mid / (double)midIndexs.size();
    }
    
    // 中位数下标的集合
    private Set<Integer> getMidIndexs(int len1, int len2) {
    	double midIndex = ((double)len1 + (double)len2) / 2;
        Set<Integer> set = new HashSet<Integer>();
        if (midIndex % 1 == 0) {
            set.add((int)midIndex);
            set.add((int)midIndex+1);
        } else {
            set.add((int)(midIndex+0.5));
        }

        return set;
    }

    public static void main(String[] args) {
    	int[][] testset1 = {
    		{1,2}
    	};
    	int[][] testset2 = {
    		{3, 4}
    	};

    	var obj = new T004();
    	for (int i = 0; i < testset1.length; i++) {
    		var nums1 = testset1[i];
    		var nums2 = testset2[i];
    		var result = obj.findMedianSortedArrays(nums1, nums2);
    		System.out.printf("nums1:%s, nums2:%s, result:%f\n",
    			Arrays.toString(nums1), Arrays.toString(nums2), result);
    		System.out.println("==================");
    	}
    }
}

