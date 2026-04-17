module;
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <string_view>
export module debug_lib.Logger;



namespace db {
    export class Logger {
    public:
        Logger(const Logger& ref) = delete;
        Logger& operator=(const Logger& ref) = delete;

        // Accessors for the underlying spdlog loggers
        static std::shared_ptr<spdlog::logger>& client_logger() {
            static Logger client("Client");
            return client.m_logger;
        };
        static std::shared_ptr<spdlog::logger>& core_logger() {
            static Logger core("Syris");
            return core.m_logger;
        };
        //static std::shared_ptr<spdlog::logger>& client_logger();
        //static std::shared_ptr<spdlog::logger>& core_logger();

        // Simple single-argument logging helpers (avoid variadic forwarding across module boundaries)
        static void core_error(std::string_view msg) { core_logger()->error(msg); }
        static void core_warn(std::string_view msg) { core_logger()->warn(msg); }
        static void core_info(std::string_view msg) { core_logger()->info(msg); }
        static void core_trace(std::string_view msg) { core_logger()->trace(msg); }

        static void client_error(std::string_view msg) { client_logger()->error(msg); }
        static void client_warn(std::string_view msg) { client_logger()->warn(msg); }
        static void client_info(std::string_view msg) { client_logger()->info(msg); }
        static void client_trace(std::string_view msg) { client_logger()->trace(msg); }

    private:
        Logger(std::string name) : m_logger(spdlog::stdout_color_mt(name)) {
            m_logger->set_pattern("%^[%T] %n: %v%$\n");
            m_logger->set_level(spdlog::level::level_enum::trace);
        }
        std::shared_ptr<spdlog::logger> m_logger;
    };
}