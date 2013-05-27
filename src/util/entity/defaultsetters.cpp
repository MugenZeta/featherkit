#include <framework/util/entity/defaultsetters.h>

namespace windgale
{
    void floatSetter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity)
    {
        float val = std::stof(arguments[0]);

        entity.lock()->setAttribute(attribute, val);
    }
    void doubleSetter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity)
    {
        double val = std::stod(arguments[0]);

        entity.lock()->setAttribute(attribute, val);
    }
    void int32Setter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity)
    {
        int32_t val = std::stoi(arguments[0]);

        entity.lock()->setAttribute(attribute, val);
    }
    void uint32Setter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity)
    {
        uint32_t val = std::stoul(arguments[0]);

        entity.lock()->setAttribute(attribute, val);
    }
    void boolSetter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity)
    {
        bool val = arguments[0] == "false";

        entity.lock()->setAttribute(attribute, val);
    }
    void byteSetter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity)
    {
        uint8_t val = std::stoi(arguments[0]);

        entity.lock()->setAttribute(attribute, val);
    }
    void idSetter(std::string attribute, std::vector<std::string>& arguments, windgale::WeakEntityPtr entity)
    {
        if(arguments[0] == "#ID#")
        {
            entity.lock()->setAttribute(attribute, entity.lock()->getId());
        }
        else
        {
            throw DefaultSetterException("ERROR! id default setter expects #ID# as value!\n");
        }
    }
}