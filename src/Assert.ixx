export module debug_lib.assert;
import debug_lib.break_point;
import debug_lib.utils.formatable;
namespace db{
    export template<Formatable T>
    inline void assert(bool condition, T&& message){
        if (!condition)
            break_point(std::forward<T>(message));
    }
}