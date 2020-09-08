#include "queue.h"
#include <algorithm>


template <typename T>
queue<T>::queue() { 
	head = new Node; 
	tail = new Node;
	head->next = tail;
}

template <typename T>
queue<T>::queue(const queue& s) : queue{} {
	for (Node* h{ s.head }; h != nullptr; h = h->next) {
		this->push(h->data);
	}
}

template <typename T>
queue<T>::~queue() {
	Node* help;
	while (head) {
		help = head;
		head = head->next;
		delete help;
	}
}

template <typename T>
void queue<T>::swap(queue& other) {
	std::swap(this->head, other.head);
	std::swap(this->sz, other.sz);
	std::swap(this->tail, other.tail);
}

template <typename T>
typename queue<T>::queue& queue<T>::operator=(const queue& other) {
	queue tmp{ other };
	this->swap(tmp);
	return *this;
}

template <typename T>
void queue<T>::push(const key_type& key) {
	if (sz == 0) head->data = key;
	else if (sz == 1) tail->data = key;
	else {
		tail->next = new Node(key);
		tail = tail->next;
	}
	++sz;
}

template <typename T>
void queue<T>::pop() {
	if (sz == 0) throw std::runtime_error("Stack is empty!");
	Node* help{ head->next };
	delete head;
	head = help;
	--sz;
}

template <typename T>
typename queue<T>::key_type queue<T>::front() const {
	return head->data;
}

template <typename T>
typename queue<T>::key_type queue<T>::back() const {
	return tail->data;
}

template <typename T>
bool queue<T>::empty() const { return sz == 0; }

template <typename T>
size_t queue<T>::size() const { return sz; }

template <typename T>
void swap(queue<T>& l, queue<T>& r) { l.swap(r); }
