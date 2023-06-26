// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void *malloc(size_t size)
{
	if (size == 0)
		return NULL;
	
	void *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	if (start == MAP_FAILED)
		return NULL;

	size_t mem_size = mem_list_num_items();
	
	if (mem_size == 0)
		mem_list_init();
	
	if (mem_list_add(start, size) == 0)
		return start;
	else
		return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
	
	if (total_size == 0)
		return NULL;
	
	void *r = malloc(total_size);
	if (r == NULL)
		return NULL;

	memset(r, 0, total_size);

	return r;
}

void free(void *ptr)
{
	struct mem_list *node = mem_list_find(ptr);

	if (node == NULL)
		return;

	int r = munmap(node->start, node->len);
	
	if (r == -1)
		return;

	r = mem_list_del(node->start);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
		return NULL;
	
	if (size == 0) {
		free(ptr);
		return NULL;
	}

	void *loc = malloc(size);
	if (loc == NULL)
		return NULL;
	
	memcpy(loc, ptr, size);

	free(ptr);

	return loc;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (ptr == NULL || (nmemb > __SIZE_MAX__ / nmemb))
		return NULL;
	
	return realloc(ptr, nmemb * size);
}
