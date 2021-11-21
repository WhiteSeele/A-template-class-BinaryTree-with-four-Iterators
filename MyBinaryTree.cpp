#include"MyBinaryTree.h"
#include<iostream>
#include<queue>

template<typename T>
BinTreeNode<T>::BinTreeNode() {
	leftChild = nullptr;
	rightChild = nullptr;
	data = 0;
}

template<typename T>
BinTreeNode<T>::BinTreeNode(T x, BinTreeNode<T>* l , BinTreeNode<T>* r,bool v ) :data(x), leftChild(l), rightChild(r),visited(v){ }

template<typename T>
MyBinaryTree<T>::MyBinaryTree(T value) {
	root = nullptr;
	RefValue = value;
}

template<typename T>
MyBinaryTree<T>::MyBinaryTree(MyBinaryTree<T>& BT) {
	root = Copy(BT.root);
}

template<typename T>
MyBinaryTree<T>::MyBinaryTree(MyBinaryTree<T>& b1, T& item, MyBinaryTree<T>& b2) {
	root->leftChild = b1.root;
	root->rightChild = b2.root;
	root->data = item;
}

template<typename T>
MyBinaryTree<T>::~MyBinaryTree() {
	Destory(root);
}

template<typename T>
BinTreeNode<T>* MyBinaryTree<T>::GetRoot()const {
	return root;
}

template<typename T>
void MyBinaryTree<T>::Linkroot(BinTreeNode<T>* &MBT) {
	root = MBT;
}

template<typename T>
MyBinaryTree<T> MyBinaryTree<T>::LeftSubtree() {
	return (root->leftChild != NULL) ? root->leftChild : NULL;
}

template<typename T>
MyBinaryTree<T> MyBinaryTree<T>::RightSubtree() {
	return (root->rightChild != NULL) ? root->rightChild : NULL;
}

template<typename T>
T MyBinaryTree<T>::RootData() {
	return root->data;
}

template<typename T>
bool MyBinaryTree<T>::IsEmpty() {
	return (root == NULL) ? true:false;
}

template<typename T>
void MyBinaryTree<T>::Destory(BinTreeNode<T>*& subtree) {
	if (subtree != NULL) {
		Destory(subtree->leftChild);
		Destory(subtree->rightChild);
		delete subtree;
	}
}

template<typename T>
void MyBinaryTree<T>::preOrder() {
	preOrder(root);
}

template<typename T>
void MyBinaryTree<T>::inOrder() {
	inOrder(root);
}

template<typename T>
void MyBinaryTree<T>::postOrder() {
	postOrder(root);
}

template<typename T>
void MyBinaryTree<T>::preOrder(BinTreeNode<T>* MST) {
	if (MST) {
		std::cout << MST->data;
		preOrder(MST->leftChild);
		preOrder(MST->rightChild);
	}
}

template<typename T>
void MyBinaryTree<T>::inOrder(BinTreeNode<T>* MST) {
	if (MST) {
		inOrder(MST->leftChild);
		std::cout << MST->data;
		inOrder(MST->rightChild);
	}
}

template<typename T>
void MyBinaryTree<T>::postOrder(BinTreeNode<T>* MST) {
	if (MST) {
		postOrder(MST->leftChild);
		postOrder(MST->rightChild);
		std::cout << MST->data;
	}
}

template<typename T>
void MyBinaryTree<T>::levelOrder() {
	std::queue<BinTreeNode<T>*>Q;
	BinTreeNode<T>* p = root;
	Q.push(p);
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		std::cout << p->data;
		if(p->leftChild!=NULL)
			Q.push(p->leftChild);
		if(p->rightChild!=NULL)
			Q.push(p->rightChild);
	}
}
template<typename T>
BinTreeNode<T>* MyBinaryTree<T>::Copy(BinTreeNode<T>* BS) {
	if (!BS)
		return NULL;
	else
		return new BinTreeNode<T>(BS->data, Copy(BS->leftChild), Copy(BS->rightChild));

}
template<typename T>
void MyBinaryTree<T>::CreatBinTree(BinTreeNode<T>*& subtree){
	T item;
	std::cin>> item;
	if (item != RefValue) {
		subtree = new BinTreeNode<T>(item);
		if (subtree == NULL) {
			std::cerr << "Wrong!" << std::endl;
			exit(1);
		}
		CreatBinTree(subtree->leftChild);
		CreatBinTree(subtree->rightChild);
	}
	else subtree = NULL;
}

template<typename T>
void MyBinaryTree<T>::PrePrint() {
	T* i;
	std::cout << "前序输出：";
	MyBinaryTree<T>::PreorderIterator PRE= PreorderIterator(root);
	while (1) {
		i = PRE.Next();
		if(i)
		std::cout << *i << " ";
		if (!i)
			break;
	}
}

template<typename T>
void MyBinaryTree<T>::InPrint() {
	T* i;
	std::cout << "中序输出：";
	MyBinaryTree<T>::InorderIterator IN= InorderIterator(root);
	while (1) {
		i = IN.Next();
		if (i)
			std::cout << *i << " ";
		if (!i)
			break;
	}
}

template<typename T>
void MyBinaryTree<T>::PostPrint() {
	T* i;
	std::cout << "后序输出：";
	MyBinaryTree<T>::PostorderIterator Pos= PostorderIterator(root);
	while (1) {
		i = Pos.Next();
		if (i)
			std::cout << *i << " ";
		if (!i)
			break;
	}
}

template<typename T>
void MyBinaryTree<T>::LevelPrint() {
	T* i;
	std::cout << "层序输出：";
	MyBinaryTree<T>::LevelorderIterator LOI= LevelorderIterator(root);
	while (1) {
		i = LOI.Next();
		if (i)
			std::cout << *i << " ";
		if (!i)
			break;
	}
}

template<typename T>
int MyBinaryTree<T>::LeavesNum(BinTreeNode<T>* MBT) {
	if (!MBT)
		return 0;
	else if (MBT->leftChild == NULL && MBT->rightChild==NULL)
		return 1;
	else
		return LeavesNum(MBT->leftChild) + LeavesNum(MBT->rightChild);
}

template<typename T>
void MyBinaryTree<T>::Swap(BinTreeNode<T>* MBT) {
	if (!MBT)
		return;
	BinTreeNode<T>* Temp;
	Temp=MBT->rightChild;
	MBT->rightChild = MBT->leftChild;
	MBT->leftChild = Temp;
	Swap(MBT->leftChild);
	Swap(MBT->rightChild);
}

template<typename T>
MyBinaryTree<T>::PreorderIterator::PreorderIterator(BinTreeNode<T>* BST) {
	currentNode = BST; 
}

template<typename T>
MyBinaryTree<T>::InorderIterator::InorderIterator(BinTreeNode<T>* BST) {
	currentNode = BST;
}

template<typename T>
MyBinaryTree<T>::PostorderIterator::PostorderIterator(BinTreeNode<T>* BST) {
	currentNode = BST;
}

template<typename T>
MyBinaryTree<T>::LevelorderIterator::LevelorderIterator(BinTreeNode<T>* BST) {
	currentNode = BST;
}