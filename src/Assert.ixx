export module debug.assert;
import syris.debug.break_point;
import syris.utils.concepts.formatable;
namespace db{
    export template<Formatable T>
    inline void assert(bool condition, T&& message){
        if (!condition)
            break_point(std::forward<T>(message));
    }
}