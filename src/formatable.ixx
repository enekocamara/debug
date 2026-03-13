export module debug.utils.formatable;

import <format>;
import <concepts>;

namespace db{
    export template<typename T>
	concept Formatable = requires(T value) {
		std::format("{}", value);
	};
}