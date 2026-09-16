#include "utils.h"
#include <fstream>

logger::logger(const std::string& name,
    const std::string&  log_file, const bool& log_to_console, const bool& log_to_file,
    const bool& enable_logging) {
    this->name = name;
    this->log_file = log_file;
    this->log_to_console = log_to_console;
    this->log_to_file = log_to_file;
    this->enable_logging = enable_logging;
}

void logger::log(const std::string& level, const std::string& message) {
    if (!this->enable_logging) {
        return;
    }

    std::string log_message = "[" + get_current_time() + "][" + this->name + "][" + level + "]: " + message;

    if (this->log_to_console) {
        std::cout << log_message << std::endl;
    }

    if (this->log_to_file) {
        if (!this->log_file.empty()) {
            std::ofstream ofs(this->log_file, std::ios_base::app);
            if (ofs.is_open()) {
                ofs << log_message << std::endl;
                ofs.close();
            } else {
                std::cerr << "Failed to open log file: " << this->log_file <<  "creating log file..." << std::endl;
                std::ofstream create_ofs(this->log_file);
                if (create_ofs.is_open()) {
                    create_ofs << log_message << std::endl;
                    create_ofs.close();
                }else {
                    std::cerr << "Failed to create log file: " << this->log_file << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
}
