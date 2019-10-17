#include <stdio.h>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
    //  割法 O(log(min(m,n)))
    /*
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)  //保证数组1一定最短
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n +1 长度 索引从0开始

        while (lo <= hi)   //二分
        {
            c1 = (lo + hi) / 2;  //c1是二分的结果
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2]; //在m = n为前提的时才可能发生;
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2) {
                hi = c1 - 1;
            } else if (LMax2 > RMin1) {
                lo = c1 + 1;
            } else {
                break;
            }

        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
    */
    // 先排序后求中值 O(m+n)
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<double> vec;
        double result = 0;
        for (int i = 0, j = 0; (i < m || j < n);) {
            if ((i < m) && ((j >= n) || (nums1[i] <= nums2[j]))) {
                vec.push_back(nums1[i++]);
            }
            if ((j < n) && ((i >= m) || (nums2[j] < nums1[i]))) {
                vec.push_back(nums2[j++]);
            }
        }
        if ((m + n) % 2 == 0) {
            int a = (m + n) >> 1;
            int b = a - 1;
            result = (vec[a] + vec[b]) / 2;
        } else {
            int a = (m + n) >> 1;
            result = vec[a];
        }

        return result;


    }
};


int fun(int argc, char *argv[]) {
    vector<int> nums1 = {2, 3, 3, 6};
    vector<int> nums2 = {1, 4, 4, 5};
//    Solution *solution = new Solution();
//    double ret = solution->findMedianSortedArrays(nums1, nums2);
    Solution solution;
    double ret = solution.findMedianSortedArrays(nums1, nums2);
    cout << ret << endl;
    return 0;
}
