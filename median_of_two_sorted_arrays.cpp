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