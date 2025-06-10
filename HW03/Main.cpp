// HW03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include "HW03.h"

int main()
{
	int capacity = 11;
	SimpleVector<char> sv(capacity);
	cout << "Current Capacity: " << sv.capacity() << endl;
	for (int i = capacity+1; i > 0; i--) {
		sv.push_back(i+64);
	}
	sv.print();
	sv.sortData();
	sv.print();
	cout << "Current Capacity: " << sv.capacity() << endl;
	cout <<"Current Size: " << sv.size() << endl;

	sv.pop_back();	
	sv.print();
	cout << "Current Size: " << sv.size() << endl;
	sv.pop_back();
	sv.print();
	cout << "Current Size: " << sv.size() << endl;

	return 0;
}
