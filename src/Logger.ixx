export module debug_lib.Logger;
import <spdlog/spdlog.h>;
import <spdlog/sinks/stdout_color_sinks.h>;
import <memory>;
import <format>;
namespace db{
    export class Logger{
        public:
            Logger(const Logger& ref) = delete;
            Logger& operator=(const Logger& ref) = delete;
            static std::shared_ptr<spdlog::logger>& client_logger(){
                static Logger client("Client");
                return client.m_logger;
            };
            static std::shared_ptr<spdlog::logger>& core_logger(){
                static Logger core("Syris");
                return core.m_logger;
            };
        template<typename T>
        static void core_error(T&& error){ core_logger()->error(std::forward<T>(error));}
        static void core_warn(const char* warn){ core_logger()->warn(warn);}
        template<typename T>
        static void core_info(T&& info){ core_logger()->info(std::forward<T>(info));}
        static void core_trace(const char* trace){ core_logger()->trace(trace);}

        template<typename T>
        static void client_error(T&& error){ client_logger()->error(std::forward<T>(error));}
        static void client_warn(const char* warn){ client_logger()->warn(warn);}
        template<typename T>
        static void client_info(T&& info){ client_logger()->info(std::forward<T>(info));}
        static void client_trace(const char* trace){ client_logger()->trace(trace);}
        private:
            Logger(std::string name) : m_logger(spdlog::stdout_color_mt(name)){
                m_logger->set_pattern("%^[%T] %n: %v%$\n");
                m_logger->set_level(spdlog::level::level_enum::trace);
            }
            std::shared_ptr<spdlog::logger> m_logger;
    };
}
