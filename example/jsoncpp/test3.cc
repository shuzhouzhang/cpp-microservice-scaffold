#include<jsoncpp/json/json.h>
#include<iostream>

int main()
{
    std::string str=R"({"name":"jsoncpp","score":[9.5],"version":1.9,"features":["parsing","serialization"]})";
    Json::Value root;
    Json::CharReaderBuilder builder;
    std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    std::string errs;
    bool ret=reader->parse(str.c_str(), str.c_str() + str.size(), &root, &errs);
    if(ret)
    {
        std::cout<<"解析成功"<<std::endl;
        std::cout<<root.toStyledString()<<std::endl;
    }
    else
    {
        std::cout<<"解析失败"<<std::endl;
        std::cout<<errs<<std::endl;
    }
    return 0;
}