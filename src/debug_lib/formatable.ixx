module;
#include <format>
#include <concepts>

export module debug_lib.utils.formatable;


namespace db{
    export template<typename T>
	concept Formatable = requires(T value) {
		std::format("{}", value);
	};
}