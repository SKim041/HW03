#pragma once
#ifndef HW03_H
#define HW03_H
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// 필수 기능
// class SimpleVector
// 멤버변수: 타입 상관없이 데이터를 받을 수 있는 배열
// 생성자: 기본 크기 10, 숫자를 하나 받는 생성자는 해당 크기의 배열 생성
// 멤버함수
//	push_back: 인자로 받은 원소를 맨 뒤에 추가. 배열의 크기가 이미 꽉 찬 경우 아무 동작도 하지 않음
//	pop_back: 마지막 원소 제거. 제거할 원소 없으면 아무 동작도 하지 않음
//	size: 현재 원소 개수 반환
//	capacity: 현재 내부 배열 크기 반환

// 도전 기능
// 복사 생성자 구현
// resize: 입력 인자가 현재 배열 크기보다 크면 배열 크기 재할당, 기존 원소는 그대로
// push_back: 배열이 꽉 찼는데 원소가 더 들어올 경우 크기를 5만큼 늘리고 새로운 원소를 추가
// sortData: 내부 데이터 정렬. STL sort 활용

template <typename T>
class SimpleVector {

public:
	SimpleVector(int capacity = 10) :currentCapacity(capacity) {
		data = new T[currentCapacity];
	};
	~SimpleVector() {
		cout << "메모리 해제" << endl;
		delete[] data;
		data = nullptr;
	};

	//// 연산자 오버로딩
	//T& operator[](int index) {
	//	return data[index];
	//}

	// 복사 생성자
	// 기존의 객체로 복사 생성
	// 얕은 복사를 하여 data의 주소만 가져올 경우 
	// 기존 객체의 data를 delete하면 복사한 객체의 data는 유효하지 않은 주소를 가리키고 
	// 이것을 delete하면 에러 발생
	SimpleVector(const SimpleVector& other) 
		:currentCapacity(other.currentCapacity), currentSize(other.currentSize) {
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
	}
	
	// 오름차순 정렬
	void sortData() {
		sort(data, data + currentSize);
	}

	// data 원소 출력
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
			cout << "원소 없음" << endl;
		}
	}
	// 내부에서 변수를 수정하지 않으면  const  붙이기
	int size() const {
		return currentSize;
	}

	int capacity() const {
		return currentCapacity;
	}

private:
	T* data;
	int currentSize = 0;
	int currentCapacity;
	void resize(int newCapacity) {
		if (newCapacity > currentCapacity) {
			currentCapacity = newCapacity;
			//T* newArr = SimpleVector(*this).data; //heap 손상 에러
			// 임시 객체가 소멸할 때 소멸자가 호출되어 newArr가 가리키는 메모리가 해제됨
			// 이 후 data = newArr;에서 해제된 메모리를 가리키며 힙 손상 발생
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

