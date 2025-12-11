// Libraries
#include <windows.h>
#include <iostream>
#include <thread>

// Create Event
HANDLE g_event;

// Test Func
void Test() {
    std::cout << "Thread >> Sleeping..." << std::endl;
    DWORD waitResult = WaitForSingleObject(g_event, INFINITE);
    if (waitResult == WAIT_OBJECT_0) {
        std::cout << "Thread >> Wake Up!" << std::endl;
    }
}

// Main Func
int main() {
    g_event = CreateEvent(NULL, FALSE, FALSE, NULL);
    std::thread t(Test);
    Sleep(3000);
    std::cout << "Main >> Thread Wake Up!" << std::endl;
    SetEvent(g_event);
    t.join();
    CloseHandle(g_event);
    return 0;
}