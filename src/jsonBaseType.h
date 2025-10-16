#ifndef jsonBaseType_h
#define jsonBaseType_h

#include <iostream>

class jsonBaseType {

    public:

        // Distruttore virtuale: ESSENZIALE per cancellare correttamente gli oggetti derivati
        virtual ~jsonBaseType() {} 
        
        /**
         * Method to be implemented by derived classes. It will call << operator to print value in a specific format.
         */
        virtual void oStream(std::ostream& os) const = 0; 

        /**
         * Overloads << operator to write the value to the output stream.
         * Since it is not a class member it cannot be declared as pure virtual and reimplemented:
         * so when << is called on a derived class, the corresponding oStream method is called.
         */
        friend std::ostream& operator<<(std::ostream& s, const jsonBaseType& obj);
};

#endif