#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//二分法 适合有序数组搜索
template<typename T>
int binarySearch(vector<T>&nums, T target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
template<typename T>
int binarySearchRecursive(vector<T>&nums, T target, int left, int right) {
	if (left > right) return  -1;
	int mid = left + (right - left) / 2;
	if (nums[mid] == target) {
		return mid;
	}
	else if (nums[mid] < target) {
		left = mid + 1;
		return binarySearchRecursive(nums,target,left,right);
	}
	else {
		right = mid - 1;
		return binarySearchRecursive(nums, target, left, right);
	}
}
void binarySearch_test() {
	cout << "binarySearch:" << endl;
	vector<int> arr = { 1,3,5,7,9,11,13,15,17,19};
	int index = binarySearch(arr, 13);
	cout << index <<" "<<arr[index];
	cout << endl;
}
void binarySearchRecursive_test() {
	cout << "binarySearchRecursive:" << endl;
	vector<int> arr = { 1,3,5,7,9,11,13,15,17,19 };
	int index = binarySearchRecursive(arr, 13,0,arr.size()-1);
	cout << index << " " << arr[index];
	cout << endl;
}