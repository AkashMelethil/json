/*
 * Author: Akash Melethil
 * Last Updated: Oct/26/2014
 */

#ifndef JSONARRAY_HPP
#define JSONARRAY_HPP

#include "json.hpp"

#include <string>

#include "jsonstring.hpp"
#include "jsonnumber.hpp"
#include "jsonboolean.hpp"
#include "jsonnull.hpp"
//#include "jsonobject.hpp"

class JsonArray : public Json {
    public:
        //JsonArray();
        JsonArray(const char*);
        JsonArray(const std::string&);
        JsonArray(const JsonArray&);
        const JsonArray& operator=(const JsonArray&);
        virtual ~JsonArray();
        
        Json& get(int);
        void set(int, const JsonString&);
        void set(int, const JsonNumber&);
        void set(int, const JsonBoolean&);
        void set(int, const JsonNull&);
        void set(int, const JsonArray&);
        //void set(const JsonObject&);
        /*void push_back(const JsonString&);
        void push_back(const JsonNumber&);
        void push_back(const JsonBoolean&);
        void push_back(const JsonNull&);
        void push_back(const JsonArray&);
        //void push_back(const JsonObject&);
        void insert(int, const JsonString&);
        void insert(int, const JsonNumber&);
        void insert(int, const JsonBoolean&);
        void insert(int, const JsonNull&);
        void insert(int, const JsonArray&);
        //void insert(int, const JsonObject&);
        void remove(int);
        size_t size();
        void resize(int);
        bool is_empty();*/
        virtual std::string stringify();

    private:
        struct ValuePointer {
            int start;
            size_t len;
        };
       
        Json** arr_;
        size_t size_;
        char* str_;
        size_t str_len_;
        size_t str_num_values_;
        ValuePointer* str_value_ptrs_;
        size_t byte_size_;

        void copy(const JsonArray&);
        void destroy();
        void init(const char*);
        void check_index_bounds(int);
        void set(int, Json*);
};

#endif