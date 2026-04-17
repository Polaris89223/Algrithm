// Algrithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "quickSort.hpp"
#include "mergeSort.hpp"
#include "BSF.hpp"
#include "DSF.hpp"
#include "BinarySearch.hpp"
#include "Tree.hpp"

void selectSort(std::vector<int>&arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i+1; j < n; j++)
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

void bubleSort(std::vector<int>&arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i) {
		bool swaped = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				swaped = true;
			}
		}
		if (!swaped) break;
		for (int i : arr) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<int> arr = { 10,9,8,7,6,5,4,3,2,1};
	std::cout << "quickSort:" << std::endl;
	for (int i : arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	quickSort(arr, 0, arr.size() - 1);


	std::cout << "mergeSort:" << std::endl;
	std::vector<int> arr1 = { 10,9,8,7,6,5,4,3,2,1 };
	for (int i : arr1) {
		std::cout << i << " ";
	}
	std::cout<< std::endl;
	mergeSort(arr1,0, arr1.size()-1);

	std::cout << "selectSort:" << std::endl;
	std::vector<int> arr2 = { 10,9,8,7,6,5,4,3,2,1 };
	for (int i : arr2) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	selectSort(arr2);


	std::cout << "bubbleSort:" << std::endl;
	std::vector<int> arr3 = { 10,9,8,7,6,5,4,3,2,1 };
	for (int i : arr3) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	bubleSort(arr3);

	std::cout << "BFS:" << std::endl;
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	cout << "BFS Search Start: " << endl;
    g.BFS(0);
	cout << endl;

	cout << "DFS Search Start: " << endl;
	dfs_recursive_test();
	dfs_stack_test();
	cout << endl;

	cout << "Binary Search Start: " << endl;
	binarySearch_test();
	binarySearchRecursive_test();
	cout << endl;

	cout << "Tree Search Start:" << endl;
	tree_seach_test();
	cout << endl;
	getchar();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
