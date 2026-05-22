    #include <jsoncpp/json/json.h>
    #include <iostream>


int main()
{
    Json::Value root;
    root["name"] = "jsoncpp";
    root["score"].append(9.5);
    root["version"] = 1.9;
    root["features"] = Json::arrayValue;
    root["features"].append("parsing");
    root["features"].append("serialization");

    std::cout << root.toStyledString() << std::endl;

    return 0;

}