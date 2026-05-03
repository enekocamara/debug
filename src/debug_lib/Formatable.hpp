#pragma once
#include <format>
#include <concepts>

namespace db{
    template<typename T>
	concept Formatable = requires(T value) {
		std::format("{}", value);
	};
}