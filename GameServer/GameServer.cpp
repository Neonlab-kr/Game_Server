#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>

void HelloThread(int32 num) {
	cout << num << endl;
}

int main()
{
	vector < std::thread > v;//std::thread타입 벡터 선언

	for (int32 i = 0;i < 10;i++)
		v.push_back(std::thread(HelloThread, i));//엔트리 포인트, 스레드 생성후 해당 함수 실행, 콤마를 통해 인자 전달

	for (int32 i = 0;i < 10;i++)
		if (v[i].joinable())//id가 0인지 여부를 확인함 즉 동작중인 스레드인지를 확인.
			v[i].join();//t 스레드가 종료될때까지 대기, 없다면 스레드보다 Main스레드가 먼저 종료되면서 에러 발생

	//std::thread t2(HelloThread_2,10);//선언과 동시에 스레드 객체 생성
	//t.detach();//std::thread 객체에서 실제 스레드를 분리(이 경우 주 스레드에서 독립적으로 분리,허나 해당 스레드의 정보를 가져올 수 없어 사용 잘 안함)
	//get_id();//각 스레드마다 부여되는 고유한 id
	//hardware_concurrency();//CPU 코어 개수?(추출할 수 없다면 0)

	cout << "Hello Main" << endl;
}