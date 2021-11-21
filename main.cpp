#include"MyBinaryTree.h"
#include"MyBinaryTree.cpp"
#include"Iterator.cpp"
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main() {
	MyBinaryTree<int> B1(-1);
	BinTreeNode<int>* root = B1.GetRoot();
	int count = 0;
	B1.CreatBinTree(root);
	B1.Linkroot(root);
	B1.preOrder();
	cout << endl;
	B1.PrePrint();
	cout << endl;
	B1.inOrder();
	cout << endl;
	B1.InPrint();
	cout << endl;
	B1.postOrder();
	cout << endl;
	B1.PostPrint();
	cout << endl;
	B1.levelOrder();
	cout << endl;
	B1.LevelPrint();
	cout << endl;
	cout << "叶子节点数：" << B1.LeavesNum(root);
	cout << endl;
	B1.Swap(root);
	B1.preOrder();
	cout << endl;
	B1.inOrder();
	cout << endl;
	B1.postOrder();
	cout << endl;
	B1.levelOrder();
	cout << endl;
	return 0;
}
