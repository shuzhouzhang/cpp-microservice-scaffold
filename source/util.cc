#include"util.h"
#include"bitelog.h"
namespace biteutil
{
    // 这里可以添加其他工具函数的实现
     // JSON序列化
         std::optional<std::string> JSON::serialize(const Json::Value& value) {
            Json::StreamWriterBuilder builder;
            builder["indentation"] = ""; // 去掉缩进和换行
            std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
            std::ostringstream ss;
            int ret=writer->write(value, &ss);
            if (ret != 0) {
                ERR("Failed to serialize JSON");
                return std::nullopt; // 序列化失败
            }
            return ss.str();
        }

        // JSON反序列化
         std::optional<Json::Value> JSON::unserialize(const std::string& jsonStr) {
            Json::Value value;
            Json::CharReaderBuilder builder;
            std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
            std::string errs;
            std::istringstream iss(jsonStr);
            bool ret=reader->parse(jsonStr.c_str(), jsonStr.c_str() + jsonStr.size(), &value, &errs);
            if (!ret) {
                ERR("{}Failed to unserialize JSON:{} " ,jsonStr, errs);
                return std::nullopt; // 反序列化失败
            }
            return value;
        }
}