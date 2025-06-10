#pragma once
#ifndef HW03_H
#define HW03_H
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// �ʼ� ���
// class SimpleVector
// �������: Ÿ�� ������� �����͸� ���� �� �ִ� �迭
// ������: �⺻ ũ�� 10, ���ڸ� �ϳ� �޴� �����ڴ� �ش� ũ���� �迭 ����
// ����Լ�
//	push_back: ���ڷ� ���� ���Ҹ� �� �ڿ� �߰�. �迭�� ũ�Ⱑ �̹� �� �� ��� �ƹ� ���۵� ���� ����
//	pop_back: ������ ���� ����. ������ ���� ������ �ƹ� ���۵� ���� ����
//	size: ���� ���� ���� ��ȯ
//	capacity: ���� ���� �迭 ũ�� ��ȯ

// ���� ���
// ���� ������ ����
// resize: �Է� ���ڰ� ���� �迭 ũ�⺸�� ũ�� �迭 ũ�� ���Ҵ�, ���� ���Ҵ� �״��
// push_back: �迭�� �� á�µ� ���Ұ� �� ���� ��� ũ�⸦ 5��ŭ �ø��� ���ο� ���Ҹ� �߰�
// sortData: ���� ������ ����. STL sort Ȱ��

template <typename T>
class SimpleVector {

public:
	SimpleVector(int capacity = 10) :currentCapacity(capacity) {
		data = new T[currentCapacity];
	};
	~SimpleVector() {
		cout << "�޸� ����" << endl;
		delete[] data;
	};

	// ���� ������
	SimpleVector(const SimpleVector& other) 
		:currentCapacity(other.currentCapacity), currentSize(other.currentSize) {
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
	}
	
	// �������� ����
	void sortData() {
		sort(data, data + currentSize);
	}

	// data ���� ���
	void print() {
		for (int i = 0; i < currentSize; i++) {
			cout << data[i] << ", ";
		}
		cout << endl;
	}
	


	void push_back(const T& val) {

		if (currentSize >= currentCapacity) {
			resize(currentCapacity + 5);
		}
		data[currentSize++] = val;
	}

	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
		}
		else {
			cout << "���� ����" << endl;
		}
	}

	int size() {
		return currentSize;
	}

	int capacity() {
		return currentCapacity;
	}

private:
	T* data;
	int currentSize = 0;
	int currentCapacity;
	void resize(int newCapacity) {
		if (newCapacity > currentCapacity) {
			currentCapacity = newCapacity;
			//T* newArr = SimpleVector(*this).data; //heap �ջ� ����
			T* newArr = new T[currentCapacity];
			for (int i = 0; i < currentSize; i++) {
				newArr[i] = data[i];
			}
			delete[] data;
			data = newArr;
		}
	}
};

#endif // !

