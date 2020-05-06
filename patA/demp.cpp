#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int> > ans;
    void DFS(int idx, vector<int> tmp, int sum, int k) {
        if (k == 3 && sum == 0) {
        	cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl;
            ans.push_back(tmp);
            return;
        }
        if (k >= 3 || idx >= n)
            return;
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i-1])
                continue;
            tmp.push_back(nums[i]);
            DFS(i+1, tmp, sum+nums[i], k+1);
            tmp.pop_back();
        }
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->n = nums.size();    
        vector<int> tmp;
        DFS(0, tmp, 0, 0);
        return ans;
    }
};

int main() {
	Solution s;
	vector<int> nums;
	int n, t;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>t;
		nums.push_back(t);
	}
	s.threeSum(nums);
	return 0;
}