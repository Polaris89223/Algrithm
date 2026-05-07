#pragma once
#include <vector>
#include <utility>
#include <iostream>

template<typename T>
void selectSort(std::vector<T>&arr){
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i+1; j< n; j++)
		{
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			std::swap(arr[i], arr[minIndex]);
		}
		for (int i : arr) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}
