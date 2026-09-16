#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <iostream>
#include <string>
#include <ctime>
#include <format>
#include <utility>
#include <chrono>

class logger {
private:
    std::string name;
    std::string log_file;
    bool log_to_console;
    bool log_to_file;
    bool enable_logging;
    static std::string get_current_time() {
        auto now = std::chrono::system_clock::now();
        char buffer[80];
        
        auto transformed = now.time_since_epoch().count() / 1000000; 
        auto millis = transformed % 1000;

        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
        strftime(buffer, sizeof(buffer), "%H:%M:%S", std::localtime(&now_time_t));
        sprintf(buffer, "%s:%03lld", buffer, (int) millis);

        return std::string(buffer);
    }
    void log(const std::string& level, const std::string& message);

public:
    logger(const std::string& name,
        const std::string&  log_file, const bool& log_to_console, const bool&  log_to_file,
        const bool& enable_logging);

    template<typename... T>
    void info(const std::string& message, T&&... args) {
        log("INFO", std::vformat(message, std::make_format_args(args...)));
    }
    template<typename... T>
    void warn(const std::string& message, T&&... args) {
        log("WARN", std::vformat(message, std::make_format_args(args...)));
    }
    template<typename... T>
    void error(const std::string& message, T&&... args) {
        log("ERROR", std::vformat(message, std::make_format_args(args...)));
    }
};

inline logger& get_logger() {
    static logger instance("main", "engine.log", true, true, true);
    return instance;
}


namespace utils {
    static logger& log = get_logger();
    #define LOG_INFO(message, ...) get_logger().info(message, ##__VA_ARGS__)
    #define LOG_WARN(message, ...) get_logger().warn(message, ##__VA_ARGS__)
    #define LOG_ERROR(message, ...) get_logger().error(message, ##__VA_ARGS__)
}


#endif