// HW03.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.

#include "HW03.h"

int main()
{
	// �� �ڵ� ���Ŀ� �� �޸� ������ �����ϴ� �ڵ�
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
