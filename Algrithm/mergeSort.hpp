#pragma once
#include <vector>
#include <iostream>

//合并(left,mid)和(mid+1，right)两个区间
void merge(std::vector<int>&arr, int left, int mid, int right) {
	std::vector<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right) { //两两比较，谁小放谁
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];  //如果左边区间剩余，直接放
	while (j <= right) temp[k++] = arr[j++]; //如果右边区间剩余，直接放
	//输出合并后的子数组
	for (int p = 0; p < k; ++p) {
		arr[left + p] = temp[p];  //将合并以后的数据，赋值数组arr
		std::cout << temp[p] <<" ";
	}
	std::cout << std::endl;
}
void mergeSort(std::vector<int>&arr, int left, int right) {
	if (left >= right) {
		std::cout << arr[left]<< std::endl;
		return;
	}
	int mid = left + (right - left) / 2; //防溢出写法
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}
