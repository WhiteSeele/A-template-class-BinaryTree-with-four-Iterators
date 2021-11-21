#pragma once
#ifndef MYBINARYTREE_H
#define MYBINARYTREE_H

#include<iostream>
#include<queue>
#include<stack>

template<typename T>
struct BinTreeNode {
	T data;
	BinTreeNode<T>* leftChild, * rightChild;
	bool visited;
	BinTreeNode();
	BinTreeNode(T x, BinTreeNode<T>* l=NULL , BinTreeNode<T>* r=NULL,bool v=false);
};

template<typename T>
class MyBinaryTree {
public:
	MyBinaryTree(T value);
	MyBinaryTree(MyBinaryTree<T>& BT); 
	MyBinaryTree(MyBinaryTree<T>& b1, T& item, MyBinaryTree<T>& b2);  //Creat a binary tree whose left subtree is b1,right subtree is b2,and whose root contains item.
	~MyBinaryTree();
	BinTreeNode<T>* GetRoot()const;
	void Linkroot(BinTreeNode<T>*& MBT);
	MyBinaryTree<T> LeftSubtree(); //return the leftsubtree of *this;
	MyBinaryTree<T> RightSubtree(); // return the rightsubtree of *this;
	T RootData(); //return the data in the root node.
	bool IsEmpty();
	void preOrder(); //ǰ�����
	void inOrder(); //�������
	void postOrder(); //�������
	void levelOrder(); //�������
	void CreatBinTree(BinTreeNode<T>*& subTree); //ǰ����������
	int LeavesNum(BinTreeNode<T>* MBT); //����Ҷ�����Ŀ�ĺ���
	void Swap(BinTreeNode<T>* MBT);  //������������������
	void PrePrint(); //ǰ�����
	void InPrint();  //�������
	void PostPrint();  //�������
	void LevelPrint(); //�������
public:
	class PreorderIterator {
	public:
		PreorderIterator(BinTreeNode<T>*);
		T* Next();
		std::stack<BinTreeNode<T>*> S;
		BinTreeNode<T>* currentNode;
	};
	class InorderIterator {
	public:
		InorderIterator(BinTreeNode<T>*);
		T* Next(); 
		std::stack<BinTreeNode<T>*> S;
		BinTreeNode<T>* currentNode;
	};
	class PostorderIterator {
	public:
		PostorderIterator(BinTreeNode<T>*);
		T* Next();
		std::stack<BinTreeNode<T>*> S;
		BinTreeNode<T>* currentNode;
	};
	class LevelorderIterator {
	public:
		LevelorderIterator(BinTreeNode<T>* BST);
		T* Next();
		std::queue<BinTreeNode<T>*> Q;
		BinTreeNode<T>* currentNode;
	};
private:
	BinTreeNode<T>* root; 
	T RefValue; //����ʱ��������ֹͣ�ı�־��
	void Destory(BinTreeNode<T>*& subtree);
	void preOrder(BinTreeNode<T>* MST);
	void inOrder(BinTreeNode<T>* MST);
	void postOrder(BinTreeNode<T>* MST);
	BinTreeNode<T>* Copy(BinTreeNode<T>* MST);
};

#endif