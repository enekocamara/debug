export module debug.assert;
import debug.break_point;
import debug.utils.formatable;
namespace db{
    export template<Formatable T>
    inline void assert(bool condition, T&& message){
        if (!condition)
            break_point(std::forward<T>(message));
    }
}