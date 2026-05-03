#pragma once

#include <utility>
#include "Breakpoint.hpp"
#include "Formatable.hpp"


namespace db {
    template<db::Formatable T>
    inline void todo(T&& formatable) {
        break_point(std::forward(formatable));
    }
    inline void todo() {
        break_point("TODO");
    }
}
