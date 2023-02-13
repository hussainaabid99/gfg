#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int getCommon(vector<int> &nums1, vector<int> &nums2) // my- 1 using hash map
{
          unordered_set<int> s(nums1.begin(), nums1.end());
          for (auto x : nums2)
          {
                    if (s.find(x) != s.end())
                              return x;
          }
          return -1;
}
//===============================================================
bool search(vector<int> &nums, int target)//2 using binary search
{
          int n = nums.size(), lo = 0, hi = n - 1;
          while (lo <= hi)
          {
                    int mid = lo + (hi - lo) / 2;
                    if (nums[mid] == target)
                              return true;
                    else if (nums[mid] > target)
                              hi = mid - 1;
                    else
                              lo = mid + 1;
          }
          return false;
}

int getCommon1(vector<int> &nums1, vector<int> &nums2)
{
          int n = nums1.size();
          for (int i = 0; i < n; i++)
          {
                    if (search(nums2, nums1[i]))
                              return nums1[i];
          }
          return -1;
}
int main()
{
          return 0;
}