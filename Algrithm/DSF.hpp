#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

template<typename T>
void dfs_recursive(const unordered_map<T, vector<T> >&graph, T node, unordered_set<T>&visited) {
	if (visited.find(node) == visited.end()) {
		cout<< node.data()<<" ";//访问节点
		visited.insert(node);
		auto it = graph.find(node);
		if (it != graph.end()) {
			for (const T& neighbor:it->second) {
				dfs_recursive(graph,neighbor,visited);
			}
		}
	}
}

template <typename T>
void dfs_stack(const unordered_map<T, vector<T> >&graph, T start) {
	unordered_set<T> visited;
	stack<T> stk;
	stk.push(start);
	while (!stk.empty()) {
		T node = stk.top();
		stk.pop();
		//访问过跳过
		if (visited.find(node) != visited.end()) {
			continue;
		}
		cout << node.data() << " ";
		visited.insert(node);
		auto it = graph.find(node);
		if (it != graph.end()) {
			for (auto neighbor = it->second.rbegin(); neighbor != it->second.rend();++neighbor) {
				if (visited.find(*neighbor) == visited.end()) {
					stk.push(*neighbor);
				}
			}
		}
	}
}
void dfs_recursive_test() {
	cout << "dfs_recursive:" << endl;
	unordered_map<string, vector<string>>graphStr = {
		{"H",{"B","C"}},
		{"B",{"G","H"}},
		{"C",{"H","G","F"}},
		{"D",{"E"}},
		{"E",{"D","F"}},
		{"F",{"C","G","E"}},
		{"G",{"B","F","C"}}
	};
	unordered_set<string> visitedStr;
	dfs_recursive<string>(graphStr,"H",visitedStr);
	cout << endl;
}

void dfs_stack_test() {
	cout << "dfs_stack:" << endl;
	unordered_map<string, vector<string>>graphStr = {
		{"H",{"B","C"}},
		{"B",{"G","H"}},
		{"C",{"H","G","F"}},
		{"D",{"E"}},
		{"E",{"D","F"}},
		{"F",{"C","G","E"}},
		{"G",{"B","F","C"}}
	};
	dfs_stack<string>(graphStr, "H");
	cout << endl;
}