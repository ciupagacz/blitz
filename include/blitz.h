// Original Blitz project was created by Ciupaga
// Copyright(C) 2026

#include <stdlib.h>
#include <wchar.h>

#ifndef BLITZ_H
#define BLITZ_H

// Define keyword alternatives to some operators
#define not !
#define and &&
#define or ||

// Define short name for NULL
#define nil NULL

/// Define short name for the end of file
#define eof EOF

// Define short name for size_t type
#define size size_t

// Define shorter integer type names
#define int8 int8_t
#define int16 int16_t
#define int32 int32_t
#define int64 int64_t
#define int128 __int128

// Define shorter unsigned integer type names
#define uint unsigned int
#define uint8 uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
#define uint64 uint64_t
#define uint128 unsigned __int128

// Define short names for unsigned integer types
#define ushort unsigned short
#define ulong unsigned long

// Define short names for diffrent floats
#define float32 float32_t
#define float64 float64_t
#define float128 __float128

// Define short names for chars and wide chars
#define uchar unsigned char
#define lchar wchar_t
#define ulchar unsigned wchar_t

// Define short names for structure and enumeration declarations
#define structure typedef struct
#define enumeration typedef enum

// Define alternative printing names for integers
#ifdef PRIu8
#undef PRIu8
#endif

#define PRIu8 "hhu" // uint8

#ifdef PRId8
#undef PRId8
#endif

#define PRId8 "hhi" // int8

#ifdef PRIu16
#undef PRIu16
#endif

#define PRIu16 "hu" // uint16

#ifdef PRId16
#undef PRId16
#endif

#define PRId16 "hi" // int16

#ifdef PRIu32
#undef PRIu32
#endif

#define PRIu32 "u" // uint (32 bit)

#ifdef PRId32
#undef PRId32
#endif

#define PRId32 "i" // int (32 bit)

#ifdef PRIu64
#undef PRIu64
#endif

#define PRIu64 "lu" // uint64

#ifdef PRId64
#undef PRId64
#endif

#define PRId64 "li" // int64

/*
 * The function uses srand() and setlocale() with the default setting.
 * It allows the user to use and convert long character variables without any
 * encoding issues. It also enables functions that generate random numbers, as
 * without this function they wouldn't function. It should only be used once.
 */
void init();

/*
 * @return 0 on success; eof when something goes wrong
 *
 * The function is an alternative version of the default C function named
 * fflush(). It automatically gives stdout as a parameter. It also returns the same
 * thing as the original function. Use it to quickly refresh the console.
 */
int refresh();

/*
 * @param ptr Pointer to modify; Musn't be nil!
 * @param value What value should be written to the pointer
 * @param count How many values should be written to the pointer
 *
 * @return Pointer, which is given as the first parameter
 *
 * The function is an alternative version of the default C function
 * named memset() and it returns the same thing.
 */
void *mset(void *ptr, int value, size count);

/*
 * @param dest Pointer to modify with the source value; Musn't be nil!
 * @param src Value that should be used; Musn't be nil!
 * @param n Defines how much memory should be copied from one pointer to another
 *
 * @return Pointer, which is given as the first parameter
 *
 * The function is an alternative version of the default C function
 * named memcpy() and it returns the same thing.
 */
void *mcpy(void *dest, const void *src, size n);

/*
 * @param dest Long pointer to modify with the source value; Musn't be nil!
 * @param src Long-sized value that should be used; Musn't be nil!
 * @param n Defines how much memory should be copied from one pointer to another
 *
 * @return Pointer, which is given as the first parameter
 *
 * The function is an alternative version of the default C function
 * named wmemcpy() and it returns the same thing.
 */
void *lmcpy(lchar *dest, const lchar *src, size n);

/*
 * @param csA First string used for comparing; Musn't be nil!
 * @param csB Second string used for comparing; Musn't be nil!
 *
 * @return 0 when identical; != 0 when diffrent
 *
 * The function is an alternative version of the default C function
 * named strcmp() and it returns the same thing.
 */
int cscmp(const char *csA, const char *csB);

/*
 * @param lcsA First long string used for comparing; Musn't be nil!
 * @param lcsB Second long string used for comparing; Musn't be nil!
 *
 * @return 0 when identical; != 0 when diffrent
 *
 * The function is an alternative version of the default C function
 * named wcscmp() and it returns the same thing.
 */
int lcscmp(const lchar *lcsA, const lchar *lcsB);

/*
 * @param cs String, to check its length; Musn't be nil!
 *
 * @return String's length in characters
 *
 * The function is an alternative version of the default C function
 * named strlen() and it returns the same thing.
 */
size cslen(const char *cs);

/*
 * @param lcs Long string, to check its length; Musn't be nil!
 *
 * @return Long string's length in characters
 *
 * The function is an alternative version of the default C function
 * named wcslen() and it returns the same thing.
 */
size lcslen(const lchar *lcs);

/*
 * @param ptr Pointer to remove from the memory
 *
 * The function is an extended version of the default C function named
 * free(). Before it executes itself it firstly checks if given pointer
 * wasn't already removed from the memory. Otherwise it just skips itself.
 */
void clean(void *ptr);

/*
 * @param format String, which'll be printed with other variables; Musn't be nil!
 * @param ... Variables, which are earlier defined in the format
 *
 * @return Printed characters amount
 *
 * The function is an alternative version of the default C function
 * named vprintf() and it returns the same thing.
 */
int print(const char *format, ...);

/*
 * @param format Long string, which'll be printed with other variables; Musn't be nil!
 * @param ... Variables, which are earlier defined in the format
 *
 * @return Printed characters amount
 *
 * The function is an alternative version of the default C function
 * named vwprintf() and it returns the same thing.
 */
int lprint(const lchar *format, ...);

/*
 * @param format String, which'll be printed with other variables; Musn't be nil!
 * @param ... Variables, which are earlier defined in the format
 *
 * @return Printed characters amount
 *
 * The function is an extended version of the default C function named
 * vprintf(). After printing everything to the console it automatically refreshes it.
 * It's very usefull when printing errors (user can see them immediately).
 */
int error(const char *format, ...);

/*
 * @param format Long string, which'll be printed with other variables; Musn't be nil!
 * @param ... Variables, which are earlier defined in the format
 *
 * @return Printed characters amount
 *
 * The function is an extended version of the default C function named
 * vwprintf(). After printing everything to the console it automatically refreshes it.
 * It's very usefull when printing errors (user can see them immediately).
 */
int lerror(const lchar *format, ...);

/*
 * @param format String, which defines loaded variables; Musn't be nil!
 * @param ... Variables, which are earlier defined in the format
 *
 * @return Modified variables amount
 *
 * The function is an alternative version of the default C function
 * named vscanf() and it returns the same thing.
 */
int scan(const char *format, ...);

/*
 * @param format Wide string, which defines loaded variables; Musn't be nil!
 * @param ... Variables, which are earlier defined in the format
 *
 * @return Modified variables amount
 *
 * The function is an alternative version of the default C function
 * named vwscanf() and it returns the same thing.
 */
int lscan(const lchar *format, ...);

/*
 * @param str String, that'll be converted to long characters; Musn't be nil!
 *
 * @return Long string, which contains the original string; nil on error
 *
 * The function converts given string into a long character string. It uses several
 * build-in C functions. It won't function if init() function wasn't used before it!
 */
lchar *cstolcs(const char *str);

/*
 * @param lstr Long string, that'll be converted to normal characters; Musn't be nil!
 *
 * @return String, which contains the original long string; nil on error
 *
 * The function converts given long string into a normal character string. It uses several
 * build-in C functions. It won't function if init() function wasn't used before it!
 */
char *lcstocs(const lchar *lstr);

/*
 * @param str1 First string to be used; Musn't be nil!
 * @param str2 Second string to be used; Musn't be nil!
 *
 * @return String, which contains two merged strings; nil on error
 *
 * The function joins two strings into one and returns it. To do so it uses
 * several build-in C functions.
 */
char *csmerge(const char *str1, const char *str2);

/*
 * @param str1 First long string to be used; Musn't be nil!
 * @param str2 Second long string to be used; Musn't be nil!
 *
 * @return Long string, which contains two merged long strings; nil on error
 *
 * The function joins two long strings into one and returns it. To do so it uses
 * several build-in C functions.
 */
lchar *lcsmerge(const lchar *str1, const lchar *str2);

/*
 * @param min Minimal integer value which can be chosen
 * @param max Maximal integer value which can be chosen
 *
 * @return Random integer value in given range
 *
 * The function generates random number in given range. It uses default C
 * rand() function with several tweaks. It won't function if init() wasn't used.
 */
int randint(int min, int max);

/*
 * @param min Minimal float value which can be chosen
 * @param max Maximal float value which can be chosen
 *
 * @return Random float value in given range
 *
 * The function generates random float in given range. It uses default C
 * rand() function with several tweaks. It won't function if init() wasn't used.
 */
float randfloat(float min, float max);

#endif
