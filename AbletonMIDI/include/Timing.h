#pragma once
#include <thread>
#include <chrono>

inline void sleepMs(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}