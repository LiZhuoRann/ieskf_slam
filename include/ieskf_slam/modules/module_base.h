#pragma once
#include <iostream>
#include <yaml-cpp/yaml.h>

class ModuleBase {
private:
    YAML::Node config_node;
    std::string name;

protected:
    /**
    * @brief Construct a new Module Base object
    * 
    * @param config_path 配置文件路径
    * @param prefix      前缀
    * @param module_name 模块名称 
    */
    ModuleBase(const std::string& config_path, const std::string& prefix, const std::string& module_name = "default") {
        name = module_name;
        if (config_path != "") {
            try {
                config_node = YAML::LoadFile(config_path);
            } catch (YAML::Exception& e) {
                std::cout << e.msg << std::endl;
            }
        }

        if (prefix!="" && config_node[prefix])
            config_node = config_node[prefix];
    }

    template<typename T>
    void readParam(const std::string& key, T& val, T default_val) {
        if(config_node[key]) {
            val = config_node[key].as<T>();
        } else {
            val = default_val;
        }
    }
};