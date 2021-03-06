#include "strings.h"
#include <assert.h>
#include <string.h>
#include <limits.h>

size_t my_strlen(const char *str)
{
    assert(str != NULL);

    size_t ret = 0;
    while (*str++) {
        ret++;
    }
    return ret;
}


char *my_strcpy(char *to, const char *from)
{
    assert((to != NULL) && (from != NULL));

    char *p = to;

    while ((*from)) {
        *p = *from;
        p++;
        from++;
    }

    return to;
}

char *my_strstr1(const char *haystack, const char *needle)
{
    assert((haystack != NULL) && (needle != NULL));

    char *result = NULL;
    size_t i = 0;
    size_t j = 0;

    for (i = 0 ; i < strlen(haystack); ++i) {
        if (haystack[i] == needle[0]) {
            char match = 1;
            for (j = 1; j < strlen(needle); ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = 0;
                    break;
                }
            }

            if (match) {
                result = (char *)&haystack[i];
                break;
            }
        }
    }

    return result;
}

int my_atoi(const char *str)
{
    assert(str != NULL);

    const char *p = str;

    while ((*p == ' ') || (*p == '\t') || (*p == '\n') || (*p == '\r') ||
            (*p == '\b') || (*p == '\v') || (*p == '\f')) {  // skip empty characters
        p++;
    }

    if ((*p != '+') && (*p != '-') && !((*p >= '0') && (*p <= '9'))) { // start with non-numerical characters
        return 0;
    }

    long result = 0;
    char sign = 1;
    char ch = *p;
    if ((ch == '+') || (ch == '-')) {
        sign = ch;   // keep the sign
    } else {
        result = result * 10 + ch - '0';
    }

    while (ch = *++p) {
        if ((ch >= '0') && (ch <= '9')) {
            if (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 &&
                     (ch - '0') > INT_MAX % 10)) {
                return (sign == '-') ? INT_MIN : INT_MAX;
            }
            result = result * 10 + ch - '0';
        } else {
            break;
        }
    }

    result = (sign == '-') ? -result : result;

    return result;
}

#include <map>
bool has_all_unique_char(const char *str)
{
    assert(str);

    std::map<char, int> charMap;
    for (int i = 0; i < strlen(str); ++i) {
        if (charMap[str[i]] == 0) {
            charMap[str[i]] = 1;
        } else {
            return false;
        }
    }
    return true;
}

char *revert_string(char *str)
{
    assert(str);

    int len = strlen(str);

    for (int i = 0; i < len / 2; ++i) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }

    return str;
}

char *remove_duplicate_char(char *str)
{
    assert(str);

    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (str[i] == str[j]) {
                str[j] = '\0';
            }
        }
    }

    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] != '\0') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    return str;
}

#include <algorithm>
bool is_anagram_string(const char *str1, const char *str2)
{
    return true;
}
