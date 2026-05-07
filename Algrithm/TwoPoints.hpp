#pragma once
#include <vector>
#include <string>
#include <unordered_set>
//快慢指针(龟兔赛跑)
//链表是否有环检测
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
bool hasCycle(ListNode*head) {
	if (!head) return false;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			return true;
		}
	}
	return false;
}
//2.对撞指针(左右指针)
//求有序数组的两数之和
vector<int> twoSum(vector<int>&numbers, int target) {
	int left = 0;
	int right = numbers.size() - 1;
	while (left < right) {
		int sum = numbers[left] + numbers[right];
		if (sum == target) return { left + 1,right + 1 };//返回1-based索引
		else if (sum < target) {
			++left;
		}
		else {
			--right;
		}
	}
	return {};
}
//3.滑动窗口
//场景:子数组/子串的最值问题
//核心逻辑:维护一个窗口，右指针扩展，左指针收缩
//求无重复字符的最长子串
int lenthofLongestSubString(std::string&s) {
	unordered_set<char> char_set;
	int left = 0;
	int max_len = 0;
	for (int right = 0; right < s.size(); ++right) {
		while (char_set.find(s[right]) != char_set.end()) { //遇到重复收缩窗口
			char_set.erase(s[left]);
			++left;
		}
		char_set.insert(s[right]);
		max_len = std::max(max_len, right - left + 1);
	}
	return max_len;
}

//4.分离指针
//场景：适合合并有序数组、有序链表合并
//合并两个有序数组
vector<int> merge(vector<int>nums1, int m, vector<int>nums2, int n) {
	int p1 = m - 1;
	int p2 = n - 1;
	int p = m + n - 1;
	vector<int> mergeNums(m+n,0);
	while (p1 >= 0 && p2 >= 0) {
		if (nums1[p1] > nums2[p2]) {
			mergeNums[p] = nums1[p1];
			--p1;
		}
		else {
			mergeNums[p] = nums2[p2];
			--p2;
		}
		--p;
	}
	//如果sums1还有剩余
	while (p1 >= 0) {
		mergeNums[p] = nums1[p1];
		--p1;
		--p;
	}
	//如果sums2还有剩余
	while (p2 >= 0) {
		mergeNums[p] = nums2[p2];
		--p2;
		--p;
	}
	return mergeNums;
}

void testTwoPoints() {
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	ListNode* node = nullptr;
	std::vector<int> nodes = { 1,3,5,7,9 };
	for (auto i : nodes) {
		node = new ListNode(i);
		if (!head) {
			head = node;
			tail = head;
		}
		else {
			tail->next = node;
			tail = tail->next;
		}
	}
	bool bret = hasCycle(head);
	cout << "LinkList Cycle before:" << bret << endl;
	tail->next = head;
	bret = hasCycle(head);
	cout << "LinkList Cycle after:" << bret << endl;

	vector<int> arr1 = { 2,4,6,8,10 };
	auto index = twoSum(arr1, 18);
	cout << "arr1 twoSum 18 index:" << index.at(0)<<",last index:"<<index.at(1)<< endl;

	//求无重复字符的最长子串
	std::string str = "adbadbefgadb";
	auto max_len = lenthofLongestSubString(str);
	cout <<"lenthofLongestSubString max:"<< max_len << endl;

	//合并两个有序数组
	vector<int> nums1 = { 1,3,5,7,9,11,13};
	vector<int> nums2 = { 2,4,6,8,10,12 };
	auto mergeNums = merge(nums1,nums1.size(),nums2,nums2.size());
	cout << "nums1>nums2 merge after:";
	for (auto i : mergeNums) {
		cout << i;
	}
	cout << endl;

	nums1 = { 1,3,5,7,9};
	nums2 = { 2,4,6,8,10,12 };
	mergeNums = merge(nums1, nums1.size(), nums2, nums2.size());
	cout << "nums1<nums2 merge after:";
	for (auto i : mergeNums) {
		cout << i;
	}
	cout << endl;
	
}


