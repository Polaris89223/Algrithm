#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
	int nodeCount;//节点数
	vector<list<int> >adj; //领接表
public:
	Graph(int v):nodeCount(v),adj(v){}
	//添加边(无向图)
	void addEdge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);  //对于有向图删除此句
	}
	//BFS遍历
	void BFS(int start) {
		vector<bool> visited(nodeCount, false);
		queue<int> q;
		visited[start] = true;
		q.push(start);
		while (!q.empty()) {
			int current = q.front();
			q.pop();
			cout << "current:" << current <<endl;
			//遍历所有相邻节点
			for (int neighbor : adj[current]) {
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					q.push(neighbor);
				}
			}
		}
	}
};