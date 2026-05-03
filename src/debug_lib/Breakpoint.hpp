#pragma once
#include <format>

#include "debug_lib/Formatable.hpp"
#include "debug_lib/Logger.hpp"

namespace db {
    #ifdef DEBUG
    template <Formatable T>
    inline void break_point(T&& msg) {
//        Logger::core_error(std::format("BreakPoint: {}", std::forward<T>(msg)).c_str());
        __debugbreak();
    }
    inline void break_point() {
        Logger::core_error("BreakPoint");
        __debugbreak();
    }
    #else
    template <Formatable T>
    inline void break_point(T&& msg) {
        //Logger::Logger.core_error(std::format("BreakPoint: {}", std::forward(msg)).c_str());
        exit(1111);
    }
    inline void break_point() {
     //   Logger::Logger.core_error("BreakPoint");
        exit(1111);
    }
    #endif
}
