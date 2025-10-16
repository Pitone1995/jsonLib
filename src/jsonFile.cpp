#include "jsonFile.h"

#include "jsonUtils.h"

shrdJsonObj jsonFile::getObj(const std::string &objName) {

    shrdJsonObj obj(new jsonObject(objName));

    _jsonObjs.push_back(obj);

    return obj;
}

void jsonFile::addObj(const jsonObj& obj) {

    _jsonObjs.push_back(obj.getPtr());
}

std::ostream& operator<<(std::ostream& s, const jsonFile& obj) {

    s << "{";

    std::vector<shrdJsonObj>::const_iterator iter;

    for (iter = obj._jsonObjs.begin(); iter != obj._jsonObjs.end(); ++iter) {

        s << *(*iter);
        
        jsonUtils::putComma(iter, obj._jsonObjs.end(), s);
    }
    
    s << "}";

    return s;
}