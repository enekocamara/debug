export module debug.todo;
import debug.break_point;
import debug.utils.formatable;

namespace db {
    export template<db::Formatable T>
    inline void todo(T&& formatable) {
        break_point(std::forward(formatable));
    }
    export inline void todo() {
        break_point("TODO");
    }
}
