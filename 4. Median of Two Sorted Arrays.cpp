#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //first swap nums1 and nums2 to make sure A is shorter
        vector<int>* A;
        vector<int>* B;
        if (nums1.size() > nums2.size()) {
            A = &nums2;
            B = &nums1;
        }
        else {
            A = &nums1;
            B = &nums2;
        }

        int len1 = A->size();
        int len2 = B->size();
        int total_len = len1 + len2;
        int half = total_len / 2;
        int l = 0;
        int r = len1 - 1;
        int m_1 = 0;//middle index of nums1
        int m_2 = 0;//middle index of nums2 
        int left_1 = 0, right_1 = 0, left_2 = 0, right_2 = 0;//to make sure the value is within the bound
        while (true) {
            m_1 = (l + r) / 2;
            if (r < l) m_1--; //incase the A is nullptr ex.[], [1, 2]
            m_2 = half - m_1 - 2;
            if (m_1 < 0) left_1 = -INT_MAX; else left_1 = (*A)[m_1];
            if (m_2 < 0) left_2 = -INT_MAX; else left_2 = (*B)[m_2];
            if (m_1 + 2 > len1) right_1 = INT_MAX; else right_1 = (*A)[m_1 + 1];
            if (m_2 + 2 > len2) right_2 = INT_MAX; else right_2 = (*B)[m_2 + 1];
            if (left_1>right_2) r = m_1 - 1;
            else if (left_2>right_1) l = m_1 + 1;
            else {
                if (total_len % 2) return double(min(right_1, right_2));//odd len
                else return double((max(left_1, left_2) +
                    min(right_1, right_2))) / 2;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {};
    vector<int>nums2 = { 1 };
    solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}

