
#define FT_INCLUDE_ALL
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**/
// Simple string hash function (djb2)
unsigned int string_hash(const void *key) {
	const char *str = (const char *)key;
	unsigned int hash = 5381;
	int c;
	
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return hash;
}

// String comparison function
int string_compare(const void *a, const void *b) {
	return strcmp((const char *)a, (const char *)b);
}

int main ()
{
	t_hashmap	myhash;

	myhash = hm_create(string_hash, string_compare);
	hm_add_value(&myhash, "Harvey", "Breeze");
	hm_add_value(&myhash, "Wolf", "Cat");
	hm_add_value(&myhash, "Tiger", "Cat");
	hm_add_value(&myhash, "Monty", "Dog");

	ft_printf("Value of Harvey: %s\n", hm_get_value(&myhash, "Harvey"));
	ft_printf("Value of Wolf: %s\n", hm_get_value(&myhash, "Wolf"));
	ft_printf("Value of Tiger: %s\n", hm_get_value(&myhash, "Tiger"));
	ft_printf("Value of Monty: %s\n", hm_get_value(&myhash, "Monty"));
	ft_printf("Value of Bass: %s\n", hm_get_value(&myhash, "Bass"));
	hm_destroy(&myhash);
}