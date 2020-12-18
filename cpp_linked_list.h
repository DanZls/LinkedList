#pragma once

template<typename T>
class LinkedList{
	struct Node{
		T value;
		Node* next = nullptr;
		Node(T vl, Node* node){
			value = vl;
			next = node;
		}
	};
	Node* head = nullptr;
public:
	Node* GetHead(){
		return head;
	}
	void PushFront(T value){
		Node* prev_head = head;
		head = new Node(value, prev_head);
	}
	void InsertAfter(Node* node, T value){
		if(node == nullptr) PushFront(value);
		else node->next = new Node(value, node->next);
	}
	void PopFront(){
		if(head != nullptr){
			Node* prev_head = head;
			head = head->next;
			delete prev_head;
		}
	}
	void RemoveAfter(Node* node){
		if(node->next != nullptr){
			Node* node1 = node->next;
			node->next = node->next->next;
			delete node1;
		}
	}
	~LinkedList(){
		Node* node = head;
		while(node != nullptr){
			Node* node1 = node->next;
			delete node;
			node = node1;
		}
	}
};
