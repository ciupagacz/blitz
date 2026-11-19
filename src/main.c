// Original Blitz project was created by Ciupaga
// Copyright(C) 2026

#include "../include/blitz.h"

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

void init() {
	// Set default locale and setup random numbers
	setlocale(LC_ALL, "");
	srand((unsigned)time(NULL));
}

// Return fflush() return value
int refresh() { return fflush(stdout); }

void *mset(void *ptr, int value, size count) {
	// Return memset() return value
	return memset(ptr, value, count);
}

void *mcpy(void *dest, const void *src, size n) {
	// Return memcpy() return value
	return memcpy(dest, src, n);
}

void *lmcpy(lchar *dest, const lchar *src, size n) {
	// Return wmemcpy() return value
	return wmemcpy(dest, src, n);
}

int cscmp(const char *csA, const char *csB) {
	// Return strcmp() return value
	return strcmp(csA, csB);
}

int lcscmp(const lchar *lcsA, const lchar *lcsB) {
	// Return wcscmp() return value
	return wcscmp(lcsA, lcsB);
}

// Return strlen() return value
size cslen(const char *cs) { return strlen(cs); }
// Return wcslen() return value
size lcslen(const lchar *lcs) { return wcslen(lcs); }

// Remove pointer if it exists
void clean(void *ptr) { if(ptr) free(ptr); }

int print(const char *format, ...) {
	// Create and load argument list
	va_list args;
	va_start(args, format);

	// Use vprintf() and save its return value
	int value = vprintf(format, args);

	// Destroy arguments and return downloaded value
	va_end(args);
	return value;
}

int lprint(const lchar *format, ...) {
	// Create and load argument list
	va_list args;
	va_start(args, format);

	// Use vwprintf() and save its return value
	int value = vwprintf(format, args);

	// Destroy arguments and return downloaded value
	va_end(args);
	return value;
}

int error(const char *format, ...) {
	// Create and load argument list
	va_list args;
	va_start(args, format);

	// Use vprintf() and save its return value
	int value = vprintf(format, args);

	// Destroy arguments, refresh the console and return downloaded value
	va_end(args);
	fflush(stdout);
	return value;
}

int lerror(const lchar *format, ...) {
	// Create and load argument list
	va_list args;
	va_start(args, format);

	// Use vwprintf() and save its return value
	int value = vwprintf(format, args);

	// Destroy arguments, refresh the console and return downloaded value
	va_end(args);
	fflush(stdout);
	return value;
}

int scan(const char *format, ...) {
	// Create and load argument list
	va_list args;
	va_start(args, format);

	// Use vscanf() and save its return value
	int value = vscanf(format, args);

	// Destroy arguments and return downloaded value
	va_end(args);
	return value;
}

int lscan(const lchar *format, ...) {
	// Create and load argument list
	va_list args;
	va_start(args, format);

	// Use vwscanf() and save its return value
	int value = vwscanf(format, args);

	// Destroy arguments and return downloaded value
	va_end(args);
	return value;
}

lchar *cstolcs(const char *str) {
	if(not str) return nil;

	// Create state and source and assign their values
	mbstate_t state = { 0 };
	const char *src = str;

	// Check if string has proper length
	size len = mbsrtowcs(nil, &src, 0, &state);
	if(len == (size) - 1) return nil;

	// Create and try to allocate output
	lchar *output = malloc((len + 1) * sizeof *output);
	if(not output) return nil;

	// Reset state and source to their original values
	state = (mbstate_t){ 0 };
	src = str;

	// Try to do the converting part
	if(mbsrtowcs(output, &src, len + 1, &state) == (size) - 1) {
		// Remove output from the memory and exit
		free(output);
		return nil;
	}

	// Return converted long string
	return output;
}

char *lcstocs(const lchar *lstr) {
	if(not lstr) return nil;

	// Create state and source and assign their values
	mbstate_t state = { 0 };
	const lchar *src = lstr;

	// Check if long string has proper length
	size len = wcsrtombs(nil, &src, 0, &state);
	if(len == (size) - 1) return nil;

	// Create and try to allocate output
	char *output = malloc(len + 1);
	if(not output) return nil;

	// Reset state and source to their original values
	state = (mbstate_t){ 0 };
	src = lstr;

	// Try to do the converting part
	if(wcsrtombs(output, &src, len + 1, &state) == (size) - 1) {
		// Remove output from the memory and exit
		free(output);
		return nil;
	}

	return output;
}

char *csmerge(const char *str1, const char *str2) {
	if(not str1 or not str2) return nil;

	// Create and try to allocate the return string
	char *merged = malloc(strlen(str1) + strlen(str2) + 1);
	if(not merged) return nil;

	// Merge two strings into the return one
	memcpy(merged, str1, strlen(str1));
	memcpy(merged + strlen(str1), str2, strlen(str2) + 1);

	return merged;
}

lchar *lcsmerge(const lchar *str1, const lchar *str2) {
	if(not str1 or not str2) return nil;

	// Check if long strings aren't taking too much memory
	if(wcslen(str1) > (size) - 1 - wcslen(str2) - 1) return nil;

	// Create and try to allocate the return long string
	lchar *merged =
		malloc((wcslen(str1) + wcslen(str2) + 1) * sizeof *merged);
	if(not merged) return nil;

	// Merge two long strings into the return one
	wmemcpy(merged, str1, wcslen(str1));
	wmemcpy(merged + wcslen(str1), str2, wcslen(str2) + 1);

	return merged;
}

int randint(int min, int max) {
	// Return random integer value in given range
	return min + rand() % (max - min + 1);
}

float randfloat(float min, float max) {
	// Return random float value in given range
	return min + (max - min) * ((float)rand() / RAND_MAX);
}
