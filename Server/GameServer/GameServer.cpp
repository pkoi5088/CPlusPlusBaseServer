#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <future>
#include "CoreMacro.h"
#include "ThreadManager.h"

CoreGlobal Core;

void ThreadMain() {
	while (true) {
		cout << "Hello! I am Thread.. " << LThreadId << endl;
		this_thread::sleep_for(1s);
	}
}

int main() {
	for (int32 i = 0; i < 5; i++) {
		GThreadManager->Launch(ThreadMain);
	}
	GThreadManager->Join();
}