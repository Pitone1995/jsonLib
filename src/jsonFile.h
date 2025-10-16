#ifndef jsonFile_h
#define jsonFile_h

#include <vector>

#include "jsonObject.h"

class jsonFile {

    public:

        /**
         * This class writes a stream of character formatted as a file .json to output stream.
         * json objects can be added, namely a collection of key-value pairs, separated by ',', enclosed in {}:
         * "jsonObject":{"key_1":value_1,...,"key_n":value_n}
         * The objects themselves are separeted by ',' and the content of the file is enclosed into {}:
         * {"jsonObject_1":{...},..."jsonObject_n":{...}}
         */
        jsonFile() {};

        /**
         * It creates a shared pointer of a jsonObject and pushes it into _jsonObjs.
         * 
         * @param objName name of the json object.
         * @return the last element of _jsonObjs, namely the shared pointer just created.
         */
        shrdJsonObj getObj(const std::string &objName);

        /**
         * It extracts the shared_ptr<jsonObject> from a jsonObj and pushes it into _jsonObjs.
         * 
         * @param obj object of class jsonObj.     
         */
        void addObj(const jsonObj& obj);

        /**
         * Overloads << operator to write json file content to the output stream.
         * 
         * Why (can't we be) friend(s)?
         * ref. https://stackoverflow.com/questions/236801/should-operator-be-implemented-as-a-friend-or-as-a-member-function
         * When you use these as stream operators (rather than binary shift) the first parameter is a stream.
         * Since you do not have access to the stream object (its not yours to modify) these can not be member operators they have to be external to the class.
         * Thus they must either be friends of the class or have access to a public method that will do the streaming for you.
         */
        friend std::ostream& operator<<(std::ostream& s, const jsonFile& obj);

    private:

        /**
         * It contains json objects of the file.
         */
        std::vector<shrdJsonObj> _jsonObjs;
};

#endif