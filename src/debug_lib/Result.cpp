module;

#include <string>
#include <optional>
#include <memory>
#include <source_location>
#include <expected>

module debug_lib.result;

namespace db {
	auto make_error(std::string message, std::optional<Error> error_source, uint32_t code, std::source_location location) -> Error {
		if (error_source.has_value()) {
			return Error(
				std::move(message),
				std::make_unique<Error>(std::move(error_source.value())),
				code,
				location
			);
		}
		else
			return Error( std::move(message), nullptr, code, location);
	}

	auto error(std::string message, std::optional<Error> error_source, uint32_t code, std::source_location location) -> std::unexpected<Error> {
		if (error_source.has_value()) {
           // construct the Error in-place inside std::unexpected to avoid overload resolution issues
			return std::unexpected<Error>(std::in_place,
					std::move(message),
					std::make_unique<Error>(std::move(error_source.value())),
					code,
					location);
		}
		else
            return std::unexpected<Error>(std::in_place, std::move(message), std::unique_ptr<Error>(nullptr), code, location);

	}
   Error::Error(std::string message, uint32_t code, std::source_location location)
		: m_message(std::move(message)), m_code(code), m_where(location), m_next(nullptr) {
	}

	Error::Error(std::string mesage, std::unique_ptr<Error> next, uint32_t code, std::source_location location)
		: m_message(std::move(mesage)), m_code(code), m_where(location), m_next(std::move(next)) {
	}
}
