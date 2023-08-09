#ifndef ASSIGNMENT5_ERROR_H
#define ASSIGNMENT5_ERROR_H
#include <exception>

// Class that in inheritance exception class to throw exceptions.
class Error:
        public exception {
public:
    virtual const char* what() const throw() = 0;
};

// Class that in inheritance Error class to throw exception to invalidId.
class ErrorInvalidId:
        public Error {
public:
    virtual const char* what() const throw() {return "Please enter valid id";}
};

// Class that in inheritance Error class to throw exception to invalidName.
class ErrorInvalidName:
        public Error {
public:
    virtual const char* what() const throw() {return "Please enter valid name";}
};

// Class that in inheritance Error class to throw exception to invalidDetails.
class ErrorInvalidDetails:
        public Error {
public:
    virtual const char* what() const throw() {return "Please enter valid details";}
};


#endif //ASSIGNMENT5_ERROR_H