 #include "jsonObject.h"

#include "jsonUtils.h"

#include "jsonDataTypes.h"

/* fare un metodo factory per gli oggetti
operatore = con input template
alla factory passo il template 
??? */

jsonProxyObject& jsonProxyObject::operator=(int value) {
    
    _parent->_jsonData[_key] = shrdJsonInt(new jsonIntType(value));

    return *this;
}

jsonProxyObject& jsonProxyObject::operator=(double value) {

    _parent->_jsonData[_key] = shrdJsonDouble(new jsonDoubleType(value));

    return *this;
}

jsonProxyObject& jsonProxyObject::operator=(const std::string &value) {
    
    _parent->_jsonData[_key] = shrdJsonString(new jsonStringType(value));

    return *this;
}

jsonProxyObject jsonObject::operator[](const std::string &key) {

    return jsonProxyObject(this, key); 
}

std::ostream& operator<<(std::ostream& s, const jsonObject& obj) {

    s << "\"" << obj._name << "\":{";

    jsonData::const_iterator iter;

    for (iter = obj._jsonData.begin(); iter != obj._jsonData.end(); ++iter) {

        s << "\"" << iter->first << "\"" << ":";
        
        if (iter->second) {
            s << *(iter->second); 
        } else {
            // Handle null shared_ptr correctly for JSON
            s << "null"; 
        }

        jsonUtils::putComma(iter, obj._jsonData.end(), s);
    }
    
    s << "}";

    return s;
}

std::ostream& operator<<(std::ostream& s, const jsonObj& obj) {

    s << (*obj.getPtr());

    return s;
}