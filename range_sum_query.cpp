struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int s, int e) : start(s), end(e), sum(0), left(NULL), right(NULL) {}
};
class NumArray {
private:
    SegmentTreeNode *root;
public:
    NumArray(vector<int> &nums) {
        root = buildTree(0, nums.size() - 1, nums); 
    }
    void update(int i, int val) {
        modify(i, val, root);   
    }

    int sumRange(int i, int j) {
        return query(i, j, root);
    }
    SegmentTreeNode *buildTree(int start, int end, vector<int> &nums) {
        if (start > end) return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(start, mid, nums);
        root->right = buildTree(mid + 1, end, nums);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int query(int start, int end, SegmentTreeNode *root) {
        if (!root) return 0;
        if (root->start == start && root->end == end) return root->sum;
        int mid = (root->start + root->end) / 2;
        if (start > mid) return query(start, end, root->right);
        if (end <= mid) return query(start, end, root->left);
        return query(start, mid, root->left) + query(mid + 1, end, root->right);
    }
    int modify(int i, int val, SegmentTreeNode *root) {
        if (!root) return 0;
        int diff;
        if (root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if (i > mid) {
            diff = modify(i, val, root->right);
        }
        else diff = modify(i, val, root->left);
        root->sum = root->sum + diff;
        return diff;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);