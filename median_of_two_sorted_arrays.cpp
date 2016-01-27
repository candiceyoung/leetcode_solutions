class Solution {
public:
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int size1 = end1 - start1 + 1;
        int size2 = end2 - start2 + 1;
        if (size1 <= 0 && size2 > 0) return nums2[k - 1];
        else if (size2 <= 0 && size1 > 0) return nums1[k - 1];
        else if (size1 <= 0 && size2 <= 0) return 0;
        if (size1 < size2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if (k == 1) return min(nums1[start1], nums2[start2]);
        int j = min(size2, k / 2);
        int i = k - j;
        if (nums1[start1 + i - 1] > nums2[start2 + j - 1]) {
            return getKth(nums1, start1, end1, nums2, start2 + j, end2, k - j);
        }
        else return getKth(nums1, start1 + i, end1, nums2, start2, end2, k - i);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int k = (size1 + size2) / 2;
        int result = getKth(nums1, 0, size1 - 1, nums2, 0, size2 - 1, k + 1);
        cout << result << endl;
        if ((size1 + size2) % 2 == 0) {
            int revise = getKth(nums1, 0, size1 - 1, nums2, 0, size2 - 1, k);
            cout << revise << endl;
            return (double)(result + (revise - result) * 0.5);
        }
        return (double)result;
    }
};

/*
https://leetcode.com/discuss/41621/very-concise-iterative-solution-with-detailed-explanation
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);
        if (N2 == 0) return ((double)nums1[(N1 - 1) / 2] + (double)nums1[N1 / 2]) / 2;
        
        int low = 0; int high = 2 * N2;
        while (low <= high) {
            int middle2 = (low + high) / 2;
            int middle1 = N1 + N2 - middle2;
            
            double L1 = (middle1 == 0) ? INT_MIN : nums1[(middle1 - 1) / 2];
            double L2 = (middle2 == 0) ? INT_MIN : nums2[(middle2 - 1) / 2];
            double R1 = (middle1 == N1 * 2) ? INT_MAX : nums1[middle1 / 2];
            double R2 = (middle2 == N2 * 2) ? INT_MAX : nums2[middle2 / 2];
            
            if (L1 > R2) low = middle2 + 1;
            else if (L2 > R1) high = middle2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};
*/