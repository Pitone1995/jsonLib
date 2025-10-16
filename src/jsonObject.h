#ifndef jsonObject_h
#define jsonObject_h

#include <string>
#include <iostream>
#include <map>

/**
 * Forward declarations for jsonProxyObject.
 */
// class jsonBaseType;
// class jsonIntType;
// class jsonDoubleType;
// class jsonStringType;
class jsonObject;

#include "jsonDataTypes.h"

#ifdef NO_BOOST
#include <memory>
// template <typename T>
// using sharedPtr = std::shared_ptr<T>;
typedef std::shared_ptr<jsonObject> shrdJsonObj;
typedef std::shared_ptr<jsonBaseType> shrdJsonBaseType;
typedef std::shared_ptr<jsonIntType> shrdJsonInt;
typedef std::shared_ptr<jsonDoubleType> shrdJsonDouble;
typedef std::shared_ptr<jsonStringType> shrdJsonString;
#else
#include "boost/shared_ptr.hpp"
// template <typename T>
// using sharedPtr = boost::shared_ptr<T>;
typedef boost::shared_ptr<jsonObject> shrdJsonObj;
typedef boost::shared_ptr<jsonBaseType> shrdJsonBaseType;
typedef boost::shared_ptr<jsonIntType> shrdJsonInt;
typedef boost::shared_ptr<jsonDoubleType> shrdJsonDouble;
typedef boost::shared_ptr<jsonStringType> shrdJsonString;
#endif

class jsonProxyObject {

    public:

        /**
         * This class is used to call the overloaded operator [] to add items of different data types.
         */
        jsonProxyObject(jsonObject* parent, const std::string& key) : _parent(parent), _key(key) {}
            
        jsonProxyObject& operator=(int value);

        jsonProxyObject& operator=(double value);

        jsonProxyObject& operator=(const std::string& value);

    private:

        jsonObject* _parent;
        
        const std::string _key;    
};

typedef std::map<std::string, shrdJsonBaseType> jsonData;

class jsonObject {

    public:

        /**
         * This class represents a json object, namely a collection of key-value pairs, separated by ',', enclosed in {}:
         * "jsonObject":{"key_1":value_1,...,"key_n":value_n}
         * This code refers to key-value pairs as json data and they are collected in _jsonData map.
         * 
         * @param name name of the json object.
         */
        jsonObject(const std::string &name) : _name(name) {};

        ~jsonObject() { std::cout << "\nDistruggo jsonObject " << _name << "." << std::endl; };

        /**
         * Overloads [] operator to add json data to the object.
         */
        jsonProxyObject operator[](const std::string &key);

        /**
         * Overloads << operator to write the json object to the output stream.
         */
        friend std::ostream& operator<<(std::ostream& s, const jsonObject& obj);

        /**
         * Maps containing json data of the object.
         */
        jsonData _jsonData;
    
    private:

        /**
         * Name of the json object.
         */
        std::string _name;

        /**
         * Allows proxy access.
         */
        friend class jsonProxyObject;
};

class jsonObj {

    public:

        /**
         * This is a wrapper class for jsonObject and it is used to be more comfortable when calling [] operator:
         * 
         *      jsonObj obj("jsonObj");
         *      obj["key"] = "value";
         * 
         * Otherwise, using jsonObject, it would be:
         * 
         *      jsonObject obj("jsonObject");
         *      (*obj)["key"] = "value";
         * 
         * @param objName name of the json object.
         */
        jsonObj(const std::string &objName) {

            _ptr = shrdJsonObj(new jsonObject(objName));
        };
    
        /**
         * Constructor that accepts shared_ptr.
         */
        jsonObj(shrdJsonObj p) : _ptr(p) {}

        /**
         * Overloads [] operator.
         * 
         * @return jsonProxyObject that manages the insertion in the map.
         */
        jsonProxyObject operator[](const std::string& key) const {

            // Gestione errore o eccezione se il puntatore è nullo
            if (!_ptr) {
                throw std::runtime_error("Puntatore JSON non valido.");
            }

            // Qui avviene la magia: dereferenziamo il puntatore internamente
            // chiamando (*_ptr).operator[], così torno a jsonObject.
            return (*_ptr)[key]; 
        }

        shrdJsonObj getPtr() const {

            return _ptr;
        }

        /**
         * Overloads << operator to write the json object to the output stream.
         */
        friend std::ostream& operator<<(std::ostream& s, const jsonObj& obj);
    
    private:

    shrdJsonObj _ptr;
};

#endif