/*
 * Author: Akash Melehtil
 * Last Updated: Oct/24/2014
 */

#ifndef JSON_H
#define JSON_H

#include <string>

class Json {
    public:
    static Json* parse(const std::string&);

    virtual std::string stringify() = 0;
    
    protected:
    static const char* find_next_char(const char*, const char);
    static const char* find_next_non_space_char(const char*);
};

#endif