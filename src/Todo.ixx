export module debug_lib.todo;
import debug_lib.break_point;
import debug_lib.utils.formatable;

namespace db {
    export template<db::Formatable T>
    inline void todo(T&& formatable) {
        break_point(std::forward(formatable));
    }
    export inline void todo() {
        break_point("TODO");
    }
}
