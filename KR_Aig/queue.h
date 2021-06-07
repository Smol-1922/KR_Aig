#ifndef queue_H
#define queue_H
#include <iostream>
#include <string> // подключаем строки
#include <fstream>
class queue
{
private:
	class queueNode {
	public:
		queueNode* next;
		std::string graf;
		queueNode(queueNode* next = nullptr)
		{
			this->next = next;
		};
		queueNode(std::string  graf, queueNode* next = nullptr)
		{
			this->graf = graf;
			this->next = next;
		};
		~queueNode()
		{

		}

	};
public:
	queueNode* head;
	queueNode* tail;
	unsigned int size;
	queue() {
		tail = nullptr;
		head = nullptr;
		size = 0;
	}
	~queue() {
		clear();
	}
	int get_size() {
		return size;
	}
	void clear() {
		while (size != 0)
		{
			pop();
		}
	}
	void push(std::string  graf) {
		if (size == 0) {
			head = new queueNode(graf);
			tail = head;
		}
		else {
			tail->next = new queueNode(graf);
			tail = tail->next;
		}
		size++;
	}
	void pop() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			queueNode* current = head;
			head = head->next;
			delete current;
		}
		size--;
	}
	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}
	std::string  at(unsigned int index)
	{
		if (index >= size) {
			throw "Index is greater than list size";
		}
		else {
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) {
				current = current->next;
				counter++;
			}
			return current->graf;
		}
	}
};
#endif

