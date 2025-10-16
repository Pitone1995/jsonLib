#ifndef jsonDataTypes_h
#define jsonDataTypes_h

#include "jsonBaseType.h"

#include <string>

class jsonIntType : public jsonBaseType {
 
    public:
    
        jsonIntType(int v) : _value(v) {}
        
        ~jsonIntType() { std::cout << "\nDistruggo jsonIntType." << std::endl; }
        
        void oStream(std::ostream& os) const override {
            os << _value;
        }

    private:
        
        int _value;
};

class jsonDoubleType : public jsonBaseType {

    public:

        jsonDoubleType(double v) : _value(v) {}
        
        ~jsonDoubleType() { std::cout << "\nDistruggo jsonDoubleType." << std::endl; }
        
        void oStream(std::ostream& os) const override {
            os << _value;
        }

    private:

        double _value;
};

class jsonStringType : public jsonBaseType {

    public:
        
        jsonStringType(const std::string& v) : _value(v) {}

        ~jsonStringType() { std::cout << "\nDistruggo jsonStringType." << std::endl; }

        void oStream(std::ostream& os) const override {
            os << "\"" << _value << "\"";
        }

    private:
        
        std::string _value;
};

#endif