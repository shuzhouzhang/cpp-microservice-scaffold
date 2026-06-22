/*
    序列化和反序列化
         1.编写接口描述，进行数据结构描述
         2.对proto文件进行编译，生成对应的代码
         3.包含头文件
         4.使用生成的代码进行序列化和反序列化
            bool SerializeToString(std::string* output) const;
            bool parseFromString(const std::string& data);
 */

#include<google/protobuf/util/json_util.h>
#include"person.pb.h"


void unserialize(const std::string& data)
{
    person::Person person;
    bool ret=person.ParseFromString(data);
    if(!ret)
    {
        std::cout<<"反序列化失败"<<std::endl;
        return;
    }
    std::cout<<"name:"<<person.name()<<std::endl;
    std::cout<<"age:"<<person.age()<<std::endl;
    std::cout<<"gender  :"<<person.gender()<<std::endl;
}

void json2pb_test(){
    std::string json_str = R"({"name":"张三","age":18,"gender":"MALE"})";
    person::Person person;
    auto ret=google::protobuf::util::JsonStringToMessage(json_str, &person);
    if(!ret.ok())
    {
        std::cout<<"json转pb失败"<<std::endl;
        return;
    }
    std::cout<<"name:"<<person.name()<<std::endl;
    std::cout<<"age:"<<person.age()<<std::endl;
    std::cout<<"gender  :"<<person.gender()<<std::endl;
}

int main()
{
    person::Person person;
    person.set_name("张三");
    person.set_age(18);
    std::string serialized_data;
    person.SerializeToString(&serialized_data);
    unserialize(serialized_data);

    json2pb_test();
    return 0;
}
