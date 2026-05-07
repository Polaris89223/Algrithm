#pragma once
#include <iostream>
#include <vector>
int partition(std::vector<int>&arr, int low, int high) {
	int pivot = arr[high]; //选择最后一元素作为基准
	int i = low-1;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]); //将基准放到正确位置
	for (int num : arr) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return i + 1; //返回基准索引
}
void quickSort(std::vector<int>&arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high); //获取分区索引
		quickSort(arr, low, pi - 1); //递归排序左边数组
		quickSort(arr, pi + 1, high);//递归排序右边数组
	}
}
