class Solution {
public:
    int jump(vector<int>& A) {
        // wirte your code here
        int size = A.size();
        if (size == 0) return 0;
        int left = 0, right = 0;
        int i = 0;
        while (right < size - 1) {
            int temp = right;
            for (int j = left; j <= temp; ++j) {
                if (j + A[j] > right) right = j + A[j];
            }
            left = temp + 1;
            i++;
        }
        return i;
    }
};