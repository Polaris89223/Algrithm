#pragma once
#include <vector>
#include <utility>
#include <iostream>
template<typename T>
void bubleSort(std::vector<T>&arr) {
	int n = arr.size();
	for (size_t i = 0; i < n-1; i++)
	{
		bool swapped = false;
		for (size_t j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1]) {
				std::swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if (!swapped) break;
		for (int i : arr) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}