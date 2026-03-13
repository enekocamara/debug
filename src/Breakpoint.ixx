export module debug_lib.break_point;
import debug_lib.Logger;
import debug_lib.utils.formatable;
import <format>;
import <iostream>;

namespace db {
    #ifdef DEBUG
    export template <Formatable T>
    inline void break_point(T&& msg) {
        Logger::core_error(std::format("BreakPoint: {}", std::forward<T>(msg)).c_str());
        __debugbreak();
    }
    export inline void break_point() {
        Logger::core_error("BreakPoint");
        __debugbreak();
    }
    #else
    export template <Formatable T>
    inline void break_point(T&& msg) {
        Logger::Logger.core_error(std::format("BreakPoint: {}", std::forward(msg)).c_str());
        exit(1111);
    }
    export inline void break_point() {
        Logger::Logger.core_error("BreakPoint");
        exit(1111);
    }
    #endif
}
