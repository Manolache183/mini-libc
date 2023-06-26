/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	size_t dest_size = strlen(destination);
	size_t source_size = strlen(source);

	size_t i = 0;
	for (; i <= source_size; i++)
		destination[i] = source[i];

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t dest_size = strlen(destination);
	size_t source_size = strlen(source);

	size_t i = 0;
	for (; i < len && i < source_size; i++)
		destination[i] = source[i];

	while (i < len) {
		destination[i] = '\0';
		i++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	size_t dest_size = strlen(destination);

	strcpy(destination + dest_size, source);

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t dest_size = strlen(destination);
	size_t source_size = strlen(source);

	strncpy(destination + dest_size, source, len);

	if (len < source_size)
		destination[dest_size + len] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	size_t s1 = strlen(str1) + 1;
	size_t s2 = strlen(str2) + 1;

	size_t s = s1 < s2 ? s1 : s2;
	return strncmp(str1, str2, s);
	
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t size1 = strlen(str1);
	size_t size2 = strlen(str2);

	for (size_t i = 0; i < len && i <= size1 && i <= size2; i++)
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] > str2[i])
			return 1;
	
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	for (size_t i = 0; ; i++) {
		if (str[i] == c)
			return str + i;
		else if (str[i] == '\0')
			break;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	size_t len = strlen(str);

	for (int i = len - 1; i >= 0; i--)
		if (str[i] == c)
			return str + i;

	return NULL;
}

char *strstr(const char *str1, const char *str2)
{
	size_t size1 = strlen(str1);
	size_t size2 = strlen(str2);

	size_t j = 0;

	for (size_t i = 0; i + size2 - j < size1; i++) {
		if (str1[i] == str2[j]) {
			j++;
			if (j == size2)
				return str1 + i - j + 1;
		} else {
			j = 0;
			i -= j;
		}
	}

	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	int size1 = strlen(str1);
	int size2 = strlen(str2);

	int j = size2;

	for (int i = size1 - 1; i - size2 + j >= 0; i--) {
		if (str1[i] == str2[j - 1]) {
			j--;
			if (j == 0)
				return str1 + i;
		} else {
			j = size2;
			i += size2 - j;
		}
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest_it = destination;
	char *source_it = source;

	for (size_t i = 0; i < num; i++)
		dest_it[i] = source_it[i];

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest_it = destination;
	char *source_it = source;

	char intermediate[num];

	for (size_t i = 0; i < num; i++)
		intermediate[i] = source_it[i];

	for (size_t i = 0; i < num; i++)
		dest_it[i] = intermediate[i];

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *it1 = ptr1;
	char *it2 = ptr2;

	for (size_t i = 0; i < num; i++)
		if (it1[i] < it2[i])
			return -1;
		else if (it1[i] > it2[i])
			return 1;
	
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *it = source;
	unsigned char c = value;

	for (size_t i = 0; i < num; i++) {
		it[i] = c;
	}

	return source;
}
