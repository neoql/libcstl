/*
 *  The interface of string_t
 *  Copyright (C)  2008,2009,2010,2011  Wangbo
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  Author e-mail: activesys.wb@gmail.com
 *                 activesys@sina.com.cn
 */

#ifndef _CSTL_STRING_H_
#define _CSTL_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

/** include section **/

/** constant declaration and macro section **/

/** data type declaration and struct, union, enum section **/

/** exported global variable declaration section **/

/** exported function prototype section **/
/**
 * Create string container.
 * @param void
 * @return if create string successfully, then return string pointer, else return NULL.
 * @remarks void
 */
extern string_t* create_string(void);

/**
 * Initialize empty string container.
 * @param pstr_string    string container.
 * @return void.
 * @remarks if pstr_string == NULL, then the behavior is undefined. pstr_string muse be created by create_string(),
 *          otherwise the behavior is undefined. the size of string is 0 after initialization.
 */
extern void string_init(string_t* pstr_string);

/**
 * Initialize string with specified character.
 * @param pstr_string       uninitialized string container.
 * @param t_count           character number.
 * @param elem              specificed character.
 * @return void
 * @remarks if pstr_string == NULL, then the behavior is undefined. string container must be created by create_string,
 *          otherwise the behavior is undefined.
 */
extern void string_init_char(string_t* pstr_string, size_t t_count, char c_char);

/**
 * Initialize string container specific c-string.
 * @param pstr_string       string container.
 * @param s_cstr            c-string.
 * @return void.
 * @remarks if pstr_string == NULL or s_cstr == NULL, then the behavior is undefined. pstr_string muse be created by
 *          create_string(), otherwise the behavior is undefined. the c-string is terminated by '\0', and string_size()
 *          is equal to the length of c-string.
 */
extern void string_init_cstr(string_t* pstr_string, const char* s_cstr);

/**
 * Initialize string container specific sub c-string.
 * @param pstr_string      string container.
 * @param s_cstr           c-string.
 * @param t_len            length of sub c-string.
 * @return void.
 * @remarks if pstr_string == NULL or s_cstr == NULL, then the behavior is undefined. pstr_string muse be created by
 *          create_string(), otherwise the behavior is undefined. if t_len is NPOS or greater then the length of c-string,
 *          then use total c-string to initialize string.
 */
extern void string_init_subcstr(string_t* pstr_string, const char* s_cstr, size_t t_len);

/**
 * Initialize string container with an exist string container.
 * @param pstr_dest     destination string container.
 * @param cpstr_src     source string container.
 * @return void.
 * @remarks if pstr_dest == NULL or cpstr_src == NULL, then the behavior is undefined. pstr_dest must be created by
 *          create_string() and cpstr_src must be initialized, otherwise the behavior is undefined. after initialization
 *          the size of pstr_dest is equal to the size of cpstr_src.
 */
extern void string_init_copy(string_t* pstr_dest, const string_t* cpstr_src);

/**
 * Initialize string container with an exist sub string container.
 * @param pstr_dest     destination string container.
 * @param cpstr_src     source string container.
 * @param t_pos         start position of source string.
 * @param t_len         sub string length.
 * @return void.
 * @remarks if pstr_dest == NULL or cpstr_src == NULL, then the behavior is undefined. pstr_dest must be created by
 *          create_string() and cpstr_src must be initialized, otherwise the behavior is undefined. t_pos must be
 *          valid source string position, otherwise the behavior is undefined. if t_len == NPOS or t_pos + t_len >=
 *          the length of source string, then use all remain sub string from t_pos.
 */
extern void string_init_copy_substring(string_t* pstr_dest, const string_t* cpstr_src, size_t t_pos, size_t t_len);

/**
 * Initialize string container with an exist string range.
 * @param pstr_string         destination string container.
 * @param it_begin            the begin iterator of range.
 * @param it_end              the end iterator of range.
 * @return void.
 * @remarks if pstr_string == NULL, then the behavior is undefined. pstr_string must be created by create_string(),
 *          otherwise the behavior is undefined. after initialization the size of pstr_string is equal to the size of range.
 */
extern void string_init_copy_range(string_t* pstr_string, string_iterator_t it_begin, string_iterator_t it_end);

/**
 * Destroy string container.
 * @param pstr_string         string container.
 * @return void.
 * @remarks if pstr_string == NULL, then the behavior is undefined. the pstr_string must be initialized or created by
 *          create_string(), otherwise the behavior is undefined.
 */
extern void string_destroy(string_t* pstr_string);

/**
 * Get character string.
 * @param cpstr_string    string container.
 * @return character string.
 * @remarks if cpstr_string == NULL or uninitialized, the behavior is undefined. if cpstr_string is empty, return "".
 */
extern const char* string_c_str(const string_t* cpstr_string);

/**
 * Get character string.
 * @param cpstr_string    string container.
 * @return character string.
 * @remarks if cpstr_string == NULL or uninitialized, the behavior is undefined. if cpstr_string is empty, the behavior is
 *          undefined.
 */
extern const char* string_data(const string_t* cpstr_string);

/**
 * Copy spceificed sub string to buffer.
 * @param cpstr_string        string container.
 * @param s_buffer            buffer.
 * @param t_len               length of sub string.
 * @param t_pos               copy position.
 * @return copy size.
 * @remarks if cpstr_string == NULL or uninitialized, the behavior is undefined. if s_buffer == NULL, the behavior is
 *          undefined. t_pos must be valid position for cpstr_string, otherwise the behavior is undefined. the copy size is
 *          min(t_len, string_size() - t_pos).
 */
extern size_t string_copy(const string_t* cpstr_string, char* s_buffer, size_t t_len, size_t t_pos);

/**
 * Get string character size.
 * @param cpstr_string       string container.
 * @return string character size.
 * @remarks if cpstr_string == NULL, then the behavior is undefined. cpstr_string must be initialized, otherwise the
 *          behavior is undefined.
 */
extern size_t string_size(const string_t* cpstr_string);

/**
 * Get character string length.
 * @param cpstr_string       string container.
 * @return string character string length.
 * @remarks if cpstr_string == NULL, then the behavior is undefined. cpstr_string must be initialized, otherwise the
 *          behavior is undefined. this function is same as string_size().
 */
extern size_t string_length(const string_t* cpstr_string);

/**
 * Test string is empty.
 * @param cpstr_string          string container.
 * @return true if empty, otherwise return false.
 * @remarks if cpstr_string == NULL, then the behavior is undefined. cpstr_string must be initialized, otherwise the
 *          behavior is undefined.
 */
extern bool_t string_empty(const string_t* cpstr_string);

/**
 * Return maximum character number.
 * @param cpstr_string          string container.
 * @return maximum number.
 * @remarks if cpstr_string == NULL, then the behavior is undefined. cpstr_string must be initialized, otherwise the
 *          behavior is undefined. this number is not fixed number.
 */
extern size_t string_max_size(const string_t* cpstr_string);

/**
 * Get string capacity.
 * @param cpstr_string          string container.
 * @return string capacity.
 * @remarks if cpstr_string == NULL, then the behavior is undefined. cpstr_string must be initialized, otherwise the
 *          behavior is undefined.
 */
extern size_t string_capacity(const string_t* cpstr_string);

/**
 * Access string character using subscript.
 * @param cpstr_string          string container.
 * @param t_pos                 subscript.
 * @return pointer to the character.
 * @remarks if cpstr_string == NULL, then the behavior is undefined. the string must be initialized, otherwise the
 *          behavior is undefined. if t_pos >= string_size(cpstr_string), then the behavior is undefined.
 */
extern char* string_at(const string_t* cpstr_string, size_t t_pos);

/**
 * Test the two strings are equal.
 * @param cpstr_first           first string container.
 * @param cpstr_second          second string container.
 * @return if first string equal to second string, then return true, else return false.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. if cpstr_first == cpstr_second, then return true.
 */
extern bool_t string_equal(const string_t* cpstr_first, const string_t* cpstr_second);

/**
 * Test the two strings are unequal.
 * @param cpstr_first           first string container.
 * @param cpstr_second          second string container.
 * @return if first string unequal to second string, then return true, else return false.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. if cpstr_first == cpstr_second, then return false.
 */
extern bool_t string_not_equal(const string_t* cpstr_first, const string_t* cpstr_second);

/**
 * Test the first string is less than the second string.
 * @param cpstr_first           first string container.
 * @param cpstr_second          second string container.
 * @return if the first string is less than the second string, then return true, else return false.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. if cpstr_first == cpstr_second, then return false.
 */
extern bool_t string_less(const string_t* cpstr_first, const string_t* cpstr_second);

/**
 * Test the first string is less than or equal to the second string.
 * @param cpstr_first           first string container.
 * @param cpstr_second          second string container.
 * @return if the first string is less than or equal to the second string, then return true, else return false.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. if cpstr_first == cpstr_second, then return true.
 */
extern bool_t string_less_equal(const string_t* cpstr_first, const string_t* cpstr_second);

/**
 * Test the first string is greater than the second string.
 * @param cpstr_first           first string container.
 * @param cpstr_second          second string container.
 * @return if the first string is greater than the second string, then return true, else return false.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. if cpstr_first == cpstr_second, then return false.
 */
extern bool_t string_greater(const string_t* cpstr_first, const string_t* cpstr_second);

/**
 * Test the first string is greater than or equal to the second string.
 * @param cpstr_first           first string container.
 * @param cpstr_second          second string container.
 * @return if the first string is greater than or equal to the second string, then return true, else return false.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. if cpstr_first == cpstr_second, then return true.
 */
extern bool_t string_greater_equal(const string_t* cpstr_first, const string_t* cpstr_second);

/**
 * Test the string is equal to the character string.
 * @param cpstr_string          string container.
 * @param s_cstr                character string.
 * @return if the string is equal to the character string, then return true, else return false.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined.
 */
extern bool_t string_equal_cstr(const string_t* cpstr_string, const char* s_cstr);

/**
 * Test the string is not equal to the character string.
 * @param cpstr_string          string container.
 * @param s_cstr                character string.
 * @return if the string is not equal to the character string, then return true, else return false.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined.
 */
extern bool_t string_not_equal_cstr(const string_t* cpstr_string, const char* s_cstr);

/**
 * Test the string is less than the character string.
 * @param cpstr_string          string container.
 * @param s_cstr                character string.
 * @return if the string is less than the character string, then return true, else return false.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined.
 */
extern bool_t string_less_cstr(const string_t* cpstr_string, const char* s_cstr);

/**
 * Test the string is less than or equal to the character string.
 * @param cpstr_string          string container.
 * @param s_cstr                character string.
 * @return if the string is less than or equal to the character string, then return true, else return false.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined.
 */
extern bool_t string_less_equal_cstr(const string_t* cpstr_string, const char* s_cstr);

/**
 * Test the string is greater than the character string.
 * @param cpstr_string          string container.
 * @param s_cstr                character string.
 * @return if the string is greater than the character string, then return true, else return false.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined.
 */
extern bool_t string_greater_cstr(const string_t* cpstr_string, const char* s_cstr);

/**
 * Test the string is greater than or equal to the character string.
 * @param cpstr_string          string container.
 * @param s_cstr                character string.
 * @return if the string is greater than or equal to the character string, then return true, else return false.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined.
 */
extern bool_t string_greater_equal_cstr(const string_t* cpstr_string, const char* s_cstr);

/**
 * Compare two string.
 * @param cpstr_first           first string container.
 * @param cpstr_second          second string container.
 * @return if the first string is greater than the second string, then return value > 0, else if the first
 *         string is less than the second string, then return value < 0, else return value == 0.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. if cpstr_first == cpstr_second, then return 0.
 */
extern int string_compare(const string_t* cpstr_first, const string_t* cpstr_second);

/**
 * Compare the first sub string and the second string.
 * @param cpstr_first           first string container.
 * @param t_pos                 substring begin position.
 * @param t_len                 substring length.
 * @param cpstr_second          second string container.
 * @return if the first sub string is greater than the second string, then return value > 0, else if the first
 *         sub string is less than the second string, then return value < 0, else return value == 0.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. t_pos must be valid position for the first string container,
 *          otherwise the behavior is undefined. if t_len >= string_size(cpstr_first) - t_pos, then all remain sub string
 *          is in use.
 */
extern int string_compare_substring_string(
    const string_t* cpstr_first, size_t t_firstpos, size_t t_firstlen, const string_t* cpstr_second);

/**
 * Compare two sub strings.
 * @param cpstr_first           first string container.
 * @param t_firstpos            first substring begin position.
 * @param t_firstlen            first substring length.
 * @param cpstr_second          second string container.
 * @param t_secondpos           second substring begin position.
 * @param t_secondlen           second substring length.
 * @return if the first sub string is greater than the second sub string, then return value > 0, else if the first
 *         sub string is less than the second sub string, then return value < 0, else return value == 0.
 * @remarks if cpstr_first == NULL or cpstr_second == NULL, then the behavior is undefined. the two strings must be
 *          initialized, otherwise the behavior is undefined. t_firstpos must be valid position for the first string
 *          container and the t_secondpos must be valie position for the second string container, otherwise the behavior
 *          is undefined. if t_firstlen >= string_size(cpstr_first) - t_firstpos, then all first remain sub string is in
 *          use, if t_secondlen >= string_size(cpstr_second) = t_secondpos, then all second remain sub string is in use.
 */
extern int string_compare_substring_substring(
    const string_t* cpstr_first, size_t t_firstpos, size_t t_firstlen,
    const string_t* cpstr_second, size_t t_secondpos, size_t t_secondlen);

/**
 * Compare the string and the character string.
 * @param cpstr_string          string container.
 * @param s_cstr                character string.
 * @return if the string is greater than the character string, then return value > 0, else if the string is less than
 *         the character string, then return value < 0, else return value == 0.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined.
 */
extern int string_compare_cstr(const string_t* cpstr_string, const char* s_cstr);

/**
 * Compare the sub string and the character string.
 * @param cpstr_string          string container.
 * @param t_pos                 substring begin position.
 * @param t_len                 substring length.
 * @param s_cstr                character string.
 * @return if the sub string is greater than the character string, then return value > 0, else if the sub string is
 *         less than the character string, then return value < 0, else return value == 0.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined. t_pos must be valid position for the first string container,
 *          otherwise the behavior is undefined. if t_len >= string_size(cpstr_first) - t_pos, then all remain sub string
 *          is in use.
 */
extern int string_compare_substring_cstr(
    const string_t* cpstr_string, size_t t_stringpos, size_t t_stringlen, const char* s_cstr);

/**
 * Compare the sub string and the sub character string.
 * @param cpstr_string          string container.
 * @param t_pos                 substring begin position.
 * @param t_len                 substring length.
 * @param s_cstr                character string.
 * @param t_valuelen            sub character string length.
 * @return if the sub string is greater than the sub character string, then return value > 0, else if the sub string is
 *         less than the sub character string, then return value < 0, else return value == 0.
 * @remarks if cpstr_string == NULL or s_cstr == NULL, then the behavior is undefined. the string must be
 *          initialized, otherwise the behavior is undefined. t_pos must be valid position for the first string container,
 *          otherwise the behavior is undefined. if t_len >= string_size(cpstr_first) - t_pos, then all remain sub string
 *          is in use. if t_valuelen >= the length of s_cstr, then all character string is in use.
 */
extern int string_compare_substring_subcstr(
    const string_t* cpstr_string, size_t t_stringpos, size_t t_stringlen, const char* s_cstr, size_t t_len);

/*
 * Substring function.
 */
extern string_t* string_substr(const string_t* cpstr_string, size_t t_pos, size_t t_len);

/*
 * Connect operation functions.
 */
extern void string_connect(string_t* pstr_string, const string_t* cpstr_string_src);
extern void string_connect_cstr(string_t* pstr_string, const char* s_cstr);
extern void string_connect_char(string_t* pstr_string, char c_char);

/*
 * Find operation functions.
 */
/* Find functions. */
extern size_t string_find(
    const string_t* cpstr_string, const string_t* cpstr_string_find, size_t t_pos);
extern size_t string_find_cstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos);
extern size_t string_find_subcstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos, size_t t_len);
extern size_t string_find_char(
    const string_t* cpstr_string, char c_char, size_t t_pos);
/* Rfind functions. */
extern size_t string_rfind(
    const string_t* cpstr_string, const string_t* cpstr_string_find, size_t t_pos);
extern size_t string_rfind_cstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos);
extern size_t string_rfind_subcstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos, size_t t_len);
extern size_t string_rfind_char(
    const string_t* cpstr_string, char c_char, size_t t_pos);
/* Find first of functions. */
extern size_t string_find_first_of(
    const string_t* cpstr_string, const string_t* cpstr_string_find, size_t t_pos);
extern size_t string_find_first_of_cstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos);
extern size_t string_find_first_of_subcstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos, size_t t_len);
extern size_t string_find_first_of_char(
    const string_t* cpstr_string, char c_char, size_t t_pos);
/* Find first not of functions. */
extern size_t string_find_first_not_of(
    const string_t* cpstr_string, const string_t* cpstr_string_find, size_t t_pos);
extern size_t string_find_first_not_of_cstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos);
extern size_t string_find_first_not_of_subcstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos, size_t t_len);
extern size_t string_find_first_not_of_char(
    const string_t* cpstr_string, char c_char, size_t t_pos);
/* Find last of functions. */
extern size_t string_find_last_of(
    const string_t* cpstr_string, const string_t* cpstr_string_find, size_t t_pos);
extern size_t string_find_last_of_cstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos);
extern size_t string_find_last_of_subcstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos, size_t t_len);
extern size_t string_find_last_of_char(
    const string_t* cpstr_string, char c_char, size_t t_pos);
/* Find last not of functions. */
extern size_t string_find_last_not_of(
    const string_t* cpstr_string, const string_t* cpstr_string_find, size_t t_pos);
extern size_t string_find_last_not_of_cstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos);
extern size_t string_find_last_not_of_subcstr(
    const string_t* cpstr_string, const char* s_cstr, size_t t_pos, size_t t_len);
extern size_t string_find_last_not_of_char(
    const string_t* cpstr_string, char c_char, size_t t_pos);

/*
 * Iterator support functions.
 */
extern string_iterator_t string_begin(const string_t* cpstr_string);
extern string_iterator_t string_end(const string_t* cpstr_string);
/* private functions. */
extern string_reverse_iterator_t string_rbegin(const string_t* cpstr_string);
extern string_reverse_iterator_t string_rend(const string_t* cpstr_string);

/*
 * Erase all characters in string.
 */
extern void string_clear(string_t* pstr_string);

/*
 * Swap the contents of two strings.
 */
extern void string_swap(string_t* pstr_first, string_t* pstr_second);

/*
 * Reserve and Resize operation functions.
 */
extern void string_reserve(string_t* pstr_string, size_t t_reservesize);
extern void string_resize(string_t* pstr_string, size_t t_resize, char c_char);

/*
 * Append a single character to string_t.
 */
extern void string_push_back(string_t* pstr_string, char c_char);

/*
 * Assign operator functions.
 */
extern void string_assign(string_t* pstr_string, const string_t* cpstr_string_assign);
extern void string_assign_substring(
    string_t* pstr_string, const string_t* cpstr_string_assign, size_t t_pos, size_t t_len);
extern void string_assign_cstr(string_t* pstr_string, const char* s_cstr);
extern void string_assign_subcstr(string_t* pstr_string, const char* s_cstr, size_t t_len);
extern void string_assign_char(string_t* pstr_string, size_t t_count, char c_char);
extern void string_assign_range(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end);

/*
 * Append operation functions.
 */
extern void string_append(string_t* pstr_string, const string_t* cpstr_string_append);
extern void string_append_substring(
    string_t* pstr_string, const string_t* cpstr_string_append, size_t t_pos, size_t t_len);
extern void string_append_cstr(string_t* pstr_string, const char* s_cstr);
extern void string_append_subcstr(
    string_t* pstr_string, const char* s_cstr, size_t t_len);
extern void string_append_char(string_t* pstr_string, size_t t_count, char c_char);
extern void string_append_range(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end);

/*
 * Insert operation functions.
 */
extern string_iterator_t string_insert(
    string_t* pstr_string, string_iterator_t t_pos, char c_char);
extern string_iterator_t string_insert_n(
    string_t* pstr_string, string_iterator_t t_pos, size_t t_count, char c_char);
extern void string_insert_string(
    string_t* pstr_string, size_t t_pos, const string_t* cpstr_string_insert);
extern void string_insert_substring(
    string_t* pstr_string, size_t t_pos, const string_t* cpstr_string_insert,
    size_t t_startpos, size_t t_len);
extern void string_insert_cstr(
    string_t* pstr_string, size_t t_pos, const char* s_cstr);
extern void string_insert_subcstr(
    string_t* pstr_string, size_t t_pos, const char* s_cstr, size_t t_len);
extern void string_insert_char(
    string_t* pstr_string, size_t t_pos, size_t t_count, char c_char);
extern void string_insert_range(
    string_t* pstr_string, string_iterator_t t_pos,
    string_iterator_t t_begin, string_iterator_t t_end);

/*
 * Erase operation functions.
 */
extern string_iterator_t string_erase(string_t* pstr_string, string_iterator_t t_pos);
extern string_iterator_t string_erase_range(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end);
extern void string_erase_substring(string_t* pstr_string, size_t t_pos, size_t t_len);

/*
 * Replace operation functions.
 */
extern void string_replace(
    string_t* pstr_string, size_t t_pos, size_t t_len, const string_t* cpstr_string_replace);
extern void string_replace_substring(
    string_t* pstr_string, size_t t_pos, size_t t_len, const string_t* cpstr_string_replace,
    size_t t_position, size_t t_length);
extern void string_replace_cstr(
    string_t* pstr_string, size_t t_pos, size_t t_len, const char* s_cstr);
extern void string_replace_subcstr(
    string_t* pstr_string, size_t t_pos, size_t t_len, const char* s_cstr, size_t t_length);
extern void string_replace_char(
    string_t* pstr_string, size_t t_pos, size_t t_len, size_t t_count, char c_char);
extern void string_range_replace(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end,
    const string_t* cpstr_string_replace);
extern void string_range_replace_substring(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end,
    const string_t* cpstr_string_replace, size_t t_pos, size_t t_len);
extern void string_range_replace_cstr(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end,
    const char* s_cstr);
extern void string_range_replace_subcstr(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end,
    const char* s_cstr, size_t t_len);
extern void string_range_replace_char(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end,
    size_t t_count, char c_char);
extern void string_replace_range(
    string_t* pstr_string, string_iterator_t t_begin, string_iterator_t t_end,
    string_iterator_t t_first, string_iterator_t t_last);

/*
 * I/O operation.
 */
extern void string_output(const string_t* cpstr_string, FILE* fp_stream);
extern void string_input(string_t* pstr_string, FILE* fp_stream);
extern bool_t string_getline(string_t* pstr_string, FILE* fp_stream);
extern bool_t string_getline_delimiter(
    string_t* pstr_string, FILE* fp_stream, char c_delimiter);

#ifdef __cplusplus
}
#endif

#endif /* _CSTL_STRING_H_ */
/** eof **/

