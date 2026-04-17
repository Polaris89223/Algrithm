#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};

//树搜索算法分为深度优先搜索算法(DFS) 和 广度优先搜索算法 (BFS);
//其中DFS分为前序遍历、中序遍历、后序遍历

//递归
//前序遍历顺序：根节点->左子树->右子树
void preOrder(TreeNode*root) {
	if (nullptr == root) return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void preOrderStack(TreeNode*root) {
	stack<TreeNode*> st;
	if (root) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		st.pop();
		cout << node->val << " ";
		if(node->right) st.push(node->right);
		if (node->left) st.push(node->left);
	}
}
//中序遍历顺序：左子树->根节点->右子树
//递归实现
void inOrder(TreeNode* root) {
	if (nullptr == root) return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}
//迭代实现
void inOrderStack(TreeNode* root) {
	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur || !st.empty()) {
		while (cur) {
			st.push(cur);     //保存根节点
			cur = cur->left; //左子树入栈
		}
		cur = st.top();
		st.pop();
		cout << cur->val << " ";
		cur = cur->right;  //转向右子树
	}
}

//后序遍历:左子树->右子树->根节点
//递归实现
void postOrder(TreeNode*root) {
	if (nullptr == root) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}
//迭代实现
void postOrderStack(TreeNode*root) {
	stack<pair<TreeNode*,bool> > st;
	st.push({root,false});
	while (!st.empty()) {
		auto node = st.top().first;
		auto visited = st.top().second;
		st.pop();
		if (node) {
			if (visited) {
				cout << node->val << " ";
			}
			else {
				st.push({ node,true });
				st.push({ node->right,false });
				st.push({ node->left,false });
			}
		}
	}
}

//广度优先搜索算法BFS
void levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	if (root) q.push(root);
	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop();
		cout << node->val << " ";
		if (node->left) q.push(node->left);
		if (node->right) q.push(node->right);
	}
}

TreeNode* buildTree(vector<int>&nums) {
	if (nums.empty()) return nullptr;
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(nums[0]);
	q.push(root);
	int i = 1;
	while (!q.empty() && i<nums.size()) {
		TreeNode* node = q.front();
		q.pop();

		//处理左子节点
		if (i < nums.size()) {
			node->left = new TreeNode(nums[i]);
			q.push(node->left);
		}
		++i;

		//处理右子树节点
		if (i < nums.size()) {
			node->right = new TreeNode(nums[i]);
			q.push(node->right);
		}
		++i;
	}
	return root;
}
void freeTree(TreeNode*root) {
	if (nullptr == root) return;
	freeTree(root->left);
	freeTree(root->right);
	if (root) {
		cout << "free node:" << root->val << " ";
		delete root;
		root = nullptr;
	}
}
void tree_seach_test() {
	//构造树
	vector<int> treeNode = { 1,2,3,4,5,6,7 };
	TreeNode* root = buildTree(treeNode);
	//前序遍历算法
	cout << "preOrder Start:";
	preOrder(root);
	cout << endl;
	cout << "preOrderStack Start:";
	preOrderStack(root);
	cout << endl;

	//中序遍历算法
	cout << "inOrder Start:";
	inOrder(root);
	cout << endl;
	cout << "inOrderStack Start:";
	inOrderStack(root);
	cout << endl;

	//后序遍历算法
	cout << "postOrder Start:";
	postOrder(root);
	cout << endl;
	cout << "postOrderStack Start:";
	postOrderStack(root);
	cout << endl;

	//广度优先算法
	cout << "BFS  Start:";
	levelOrder(root);
	cout << endl;

	//释放树空间
	freeTree(root);
}