#include "jsonBaseType.h"

std::ostream& operator<<(std::ostream& os, const jsonBaseType& obj)  {
    
    obj.oStream(os);
    return os;
}