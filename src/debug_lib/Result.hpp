#pragma once
#include <string>
#include <source_location>
#include <memory>
#include <optional>
#include <expected>
#include <cstdint>


namespace db {
	struct EmptyOk {};

	struct EmptyErr {};

    class Error {
	public:

		std::string to_string() const {
			return m_message;
		}

		Error() = delete;
		Error(std::string message, uint32_t code = 0, std::source_location location = std::source_location::current());
		Error(std::string mesage, std::unique_ptr<Error> next, uint32_t code = 0, std::source_location location = std::source_location::current());

		// Copyable (permitted because std::expected and other std utilities may copy errors)
		Error(const Error& other) = default;
		Error& operator=(const Error& other) = default;

		// Still movable
		Error(Error&&) = default;
		Error& operator=(Error&&) = default;

	private:
		std::string m_message;
		uint32_t m_code;
		std::source_location m_where = std::source_location::current();
		std::shared_ptr<Error> m_next;

	};

	template<typename Ok, typename Err = Error>
		using Result [[nodiscard]] = std::expected<Ok, Err>;

	[[nodiscard]] auto
		make_error(std::string message, std::optional<Error> error_source = std::nullopt, uint32_t code = 0, std::source_location location = std::source_location::current()) -> Error;
	[[nodiscard]] auto
		error(std::string message, std::optional<Error> error_source = std::nullopt, uint32_t code = 0, std::source_location location = std::source_location::current()) -> std::unexpected<Error>;
}