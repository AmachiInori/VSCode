#pragma once
#ifndef __CHAIN_DRAW_H__
#define __CHAIN_DRAW_H__
#include "vectorDraw.h"

template<class node, class element>
class chainDraw{
private:
	unsigned int windowHeight = 720;
	unsigned int windowLength = 960;
	unsigned int left = 96;
	unsigned int up = 120;
	unsigned int right = 864;
	unsigned int down = 600;
	element (*value)(node*);
	node* (*next)(node*);
	node* head;
	vector<element> data;
	bool isHeadVaild = false; //表示头节点存实际数据

	bool _checkNextAndCircle();
	void _chainToVector();
public:
	chainDraw(unsigned int length, unsigned int height, node* _head, element(*_value)(node*), node*(*_next)(node*));
	void invalidHead() { isHeadVaild = false;  }
};

template<class node, class element>
chainDraw<node, element>::chainDraw(unsigned int length, unsigned int height, node* _head, element(*_value)(node*), node*(*_next)(node*))
: windowHeight(height), windowLength(length), head(_head), value(_value), next(_next) {
	data.clear();
	left = windowLength / 10;
	right = left * 9;
	up = windowHeight / 6;
	down = up * 5;
	if (!_checkNextAndCircle()) throw("invalid chain");
}

template<class node, class element>
bool chainDraw<node, element>::_checkNextAndCircle() {
	node *slow = head, *fast = head;
	while (fast != nullptr) {
		fast = next(fast);
		if (fast != nullptr) = next(fast);
		slow = next(slow);
		if (fast == slow || next(fast) == slow) 
			return false;
	}
	return true;
}

template<class node, class element>
void chainDraw<node, element>::_chainToVector() {
	data.clear();
	node* str = head;
	while (str != nullptr) {
		data.push_back(value(str));
		str = next(str);
	}
	if (!isHeadVaild) data.erase(data.begin());
}
#endif