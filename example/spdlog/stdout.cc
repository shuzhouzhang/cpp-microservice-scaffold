/*
  标准输出日志
  1.包含头文件<spdlog/spdlog.h>
  2.创建日志对象
  3.设置日志输出等级
  4.设置日志输出格式
  5.输出日志

*/
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include<spdlog/sinks/rotating_file_sink.h>
#include<iostream>
int main(int argc, char* argv[]) {
    // 创建日志对象
    //auto logger = spdlog::stdout_color_mt("stdout_logger");
    //auto logger =spdlog::basic_logger_mt("file_logger","file.dat"); 
    auto logger = spdlog::rotating_logger_mt("file_logger", "rotating.dat", 1024, 3);
    // 设置日志输出等级
    logger->set_level(spdlog::level::info);
    // 设置日志输出格式
    logger->set_pattern("[%H:%M:%S] [%-7l]: %v");
    // 输出日志
    for(int i=0;i<10000;i++){
        logger->info("This is an info message {}",i);
        logger->error("This is an error message {}",i);
    }
    return 0;
}