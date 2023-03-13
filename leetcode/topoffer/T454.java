import java.util.*;

/**
 * 454. 四数相加 II
 */
class T454 {
    /**
    分组 + HashMap：预计算减轻时间复杂度
    0. 定义 count 统计满足条件的数量
    1. 先循环 nums1 和 nums2，计算每两个元素的和，存放在 HashMap 中。
    其中 map.key 是和，map.value 是相同和出现的次数。
    2. 然后循环 nums3 和 nums4，计算每两个元素的和，判断和的负数是否在 HashMap 中。
    如果在，把 count + map.value，否则继续循环
    3. 循环结束，返回 count
     */
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        int count = 0;

        Map<Integer, Integer> map = new HashMap<>();
        for (int n1: nums1) {
            for (int n2: nums2) {
                var sum = n1 + n2;
                map.put(sum, map.getOrDefault(sum, 0) + 1);
            }
        }

        for (int n3: nums3) {
            for (int n4: nums4) {
                var sum = - (n3 + n4);
                count += map.getOrDefault(sum, 0);
            }
        }

        return count;
    }
}
