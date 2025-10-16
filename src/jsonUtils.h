#ifndef jsonUtils_h
#define jsonUtils_h

#include <iostream>

class jsonUtils {

    public:

        /**
         * It checks if the next element of the container is not the last: in this case it prints a ','.
         */
        template<typename T>
        static void putComma(T& iter, const T& endIter, std::ostream &s) {

            T nextIter = iter;
            ++nextIter;           
            
            if (nextIter != endIter)
                s << ",";
        }
};

#endif