#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
class queue {
public:
	using key_type = T;

private:

	struct Node {
		key_type data;
		Node* next{ nullptr };
		Node() {}
		Node(key_type d) : data{ d } {}
	};

	size_t sz{ 0 };
	Node* head{ nullptr };
	Node* tail{ nullptr };

public:
	queue();
	queue(const queue& s);
	queue& operator=(const queue& other);
	~queue();
	void push(const key_type& key);
	void pop();
	key_type front() const;
	key_type back() const;
	bool empty() const;
	size_t size() const;
	void swap(queue& other);
};