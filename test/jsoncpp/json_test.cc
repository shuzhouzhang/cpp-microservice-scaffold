#include"../../source/util.h"

#include <iostream>

void serializeTest()
{
    Json::Value root;
    root["name"] = "jsoncpp";
    root["score"].append(9.5);
    root["version"] = 1.9;
    root["features"].append("parsing");
    root["features"].append("serialization");

    auto jsonStrOpt = biteutil::JSON::serialize(root);
    if (jsonStrOpt) {
        std::cout << "序列化成功: " << *jsonStrOpt << std::endl;
    } else {
        std::cout << "序列化失败" << std::endl;
    }
}
void unserializeTest()
{
    std::string jsonStr = R"({"name":"jsoncpp","score":[9.5],"version":1.9,"features":["parsing","serialization"]})";
    auto jsonValueOpt = biteutil::JSON::unserialize(jsonStr);
    if (jsonValueOpt) {
        std::cout << "反序列化成功: " << (*jsonValueOpt).toStyledString() << std::endl;
    } else {
        std::cout << "反序列化失败" << std::endl;
    }
}

int main()
{
    serializeTest();
    unserializeTest();

    return 0;
}
