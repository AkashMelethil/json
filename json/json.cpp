/*
 * Author: Akash Melehtil
 * Last Updated: Oct/24/2014
 */

#include "json.hpp"

#include <ctype.h>

Json::JsonType Json::find_type(const char* str) {
	const char* first_non_space_char = Json::find_next_non_space_char(str);
	switch(*first_non_space_char) {
		case '{':
            return JSONOBJECT;
			break;
		case '"':
            return JSONSTRING;
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		case '-':
            return JSONNUMBER;
			break;
		case 't':
		case 'f':
            return JSONBOOLEAN;
			break;
		case '[':
            return JSONARRAY;
			break;
		case 'n':
            return JSONNULL;
			break;
		default:
			throw("[Error] Invalid JSON string");
	}
}

const char* Json::find_next_char(const char* str, const char to_find) {
   const char* ptr = str;
   while (*ptr != to_find && *ptr != '\0')
       ++ptr;
   return ptr;
}

const char* Json::find_next_non_space_char(const char* str) {
    const char* ptr = str;
    while (isspace(*ptr) && *ptr != '\0')
        ++ptr;
    return ptr;
}

const char* Json::find_next_either_chars(const char* str, const char one, const char two) {
    const char* ptr = str;
    while (*ptr != one && *ptr != two && *ptr != '\0')
        ++ptr;
    return ptr;
}

bool Json::check_contains(const char* big_str, const char* small_str) {
    const char* small_ptr = small_str;
    const char* big_ptr = big_str;
    while (*small_ptr != '\0') {
        if (*small_ptr != *big_ptr) return false;
        ++small_ptr;
        ++big_ptr;
    }
    return true;
}

Json::~Json() {}