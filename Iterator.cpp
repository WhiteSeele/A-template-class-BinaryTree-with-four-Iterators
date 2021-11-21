#include"MyBinaryTree.h"

using namespace std;

template<typename T>
T* MyBinaryTree<T>::PreorderIterator::Next() {
	T& temp = currentNode->data;
	if (currentNode) {
		if (currentNode->rightChild)
			S.push(currentNode->rightChild);
		if (currentNode->leftChild)
			S.push(currentNode->leftChild);

	}
	if (!currentNode)
		return NULL;
	if (!S.empty()) {
		currentNode = S.top();
		S.pop();
	}
	else {
		currentNode = NULL;
	}
	return &temp;
}

template<typename T>
T* MyBinaryTree<T>::InorderIterator::Next() {
	while (currentNode) {
		S.push(currentNode);
		currentNode = currentNode->leftChild;
	}
	if (S.empty())
		return 0;
	currentNode = S.top();
	S.pop();
	T& temp = currentNode->data;
	currentNode = currentNode->rightChild;
	return &temp;
}

template<typename T>
T* MyBinaryTree<T>::PostorderIterator::Next() {
	while (currentNode) {
		if (!currentNode->visited) {
			S.push(currentNode);
			currentNode->visited = true;
		}
		if (currentNode->rightChild && !currentNode->rightChild->visited) {
			S.push(currentNode->rightChild);
			currentNode->rightChild->visited = true;
		}
		if (currentNode->leftChild && !currentNode->leftChild->visited) {
			currentNode = currentNode->leftChild;
			continue;
		}
		currentNode = currentNode->rightChild;
	}
	if (S.empty())
		return 0;
	currentNode = S.top();
	S.pop();
	T& temp = currentNode->data;
	return &temp;
}


template<typename T>
T* MyBinaryTree<T>::LevelorderIterator::Next() {
	T& temp = currentNode->data;
	if (currentNode) {
		if (currentNode->leftChild) 
			Q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			Q.push(currentNode->rightChild);
	}
	if (!currentNode)
		return 0;
	if (!Q.empty()) {
		currentNode = Q.front();
		Q.pop();
	}
	else
		currentNode = NULL;
	return &temp;
}