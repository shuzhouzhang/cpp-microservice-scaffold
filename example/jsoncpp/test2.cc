#include<jsoncpp/json/json.h>
#include<iostream>

int main()
{
    Json::Value root;
    root["name"] = "jsoncpp";
    root["version"] = 1.9;
    root["features"] = Json::arrayValue;
    root["features"].append("parsing");
    root["features"].append("serialization");

    //实例化Json::StreamWriterBuilder对象
    //通过建造者模式创建Json::StreamWriter对象
    //进行序列化
    Json::StreamWriterBuilder builder; 
    std::unique_ptr<Json::StreamWriter> swp(builder.newStreamWriter());
    std::stringstream ss;
    int ret=swp->write(root, &ss);
    if(ret==0)
    {
        std::cout<<"序列化成功"<<std::endl;
    }
    else
    {
        std::cout<<"序列化失败"<<std::endl;
    }
    std::string str = ss.str();
    std::cout<<str<<std::endl;
    return 0;
}