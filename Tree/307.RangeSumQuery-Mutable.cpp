#include "../Common.h"


// SEGTREE
class SegmentTreeNode {
private:
    /* data */
public:
    SegmentTreeNode(int start, 
                    int end, 
                    int sum, 
                    SegmentTreeNode *left=nullptr, 
                    SegmentTreeNode *right=nullptr) : 
        start(start),
        end(end),
        sum(sum),
        left(left),
        right(right) {}

    SegmentTreeNode(const SegmentTreeNode&) = delete;
    SegmentTreeNode& operator=(const SegmentTreeNode&) = delete;
    ~SegmentTreeNode() {
        delete left,
        delete right,
        left = right = nullptr;
    }

    int start;
    int end;
    int sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
};


class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_.swap(nums);
        if (!nums_.empty())
            root_.reset(buildTree(0, nums_.size() - 1));
    }
    
    void update(int index, int val) {
        updateTree(root_.get(), index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(root_.get(), left, right);
    }

private:
    vector<int> nums_;
    unique_ptr<SegmentTreeNode> root_;

    SegmentTreeNode *buildTree(int start, int end) {
        if (start == end)
            // leaf node
            return new SegmentTreeNode(start, end, nums_[start]);

        int mid = start + (end - start) / 2;
        SegmentTreeNode *left = buildTree(start, mid);
        SegmentTreeNode *right = buildTree(mid + 1, end);
        return new SegmentTreeNode(start, end, left->sum + right->sum, left, right);
    }

    void updateTree(SegmentTreeNode *node, int idx, int val) {
        if (node->start == idx && node->end == idx) {
            node->sum = val;
            return;
        }

        // 二分查找
        int mid = node->start + (node->end - node->start) / 2;
        if (idx <= mid) {
            updateTree(node->left, idx, val);
        } else {
            updateTree(node->right, idx, val);
        }

        node->sum = node->left->sum + node->right->sum;
    }

    int sumRange(SegmentTreeNode* node, int i, int j) {    
        if (i == node->start && j == node->end)
            return node->sum;

        int mid = node->start + (node->end - node->start) / 2;
        if (j <= mid) {
            return sumRange(node->left, i, j);
        } else if (i > mid) {
            return sumRange(node->right, i, j);
        } else {
            return sumRange(node->left, i, mid) + sumRange(node->right, mid + 1, j);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */