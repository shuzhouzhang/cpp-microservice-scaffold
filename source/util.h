/*
    util工具封装
        1.JSON序列化和反序列化
*/
#pragma once
#include<jsoncpp/json/json.h>
#include<iostream>
#include<string>
#include<sstream>  
#include<memory>
#include<optional>
#include"bitelog.h"

namespace biteutil
{
   class JSON{
    public:
        // JSON序列化
        static std::optional<std::string> serialize(const Json::Value& value);

        // JSON反序列化
        static std::optional<Json::Value> unserialize(const std::string& jsonStr);
   };
}