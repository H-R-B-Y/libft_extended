#include "ft_alloc_a.h"
#include <stdio.h>
#include <string.h>

// Simple callback that just does some allocations and prints info
int test_callback(void *context)
{
	struct s_alloc_a *alloc = (*(struct s_alloc_a **)context);
	char *str1, *str2, *str3;
	int *numbers;
	
	printf("=== Inside Callback ===\n");
	printf("Total memory: %zu bytes\n", alloc->total_memory);
	printf("Used memory: %zu bytes\n", alloc->used_memory);
	printf("\n");
	
	// Test 1: Allocate a string
	printf("Test 1: Allocating 32 bytes for str1...\n");
	str1 = (char *)ft_alloc_a_checkout(alloc, 32);
	if (str1)
	{
		strcpy(str1, "Hello from stack allocator!");
		printf("str1: %s\n", str1);
		printf("Used memory: %zu bytes\n\n", alloc->used_memory);
	}
	else
		printf("FAILED to allocate str1\n\n");
	
	// Test 2: Allocate another string
	printf("Test 2: Allocating 64 bytes for str2...\n");
	str2 = (char *)ft_alloc_a_checkout(alloc, 64);
	if (str2)
	{
		strcpy(str2, "This is another allocation!");
		printf("str2: %s\n", str2);
		printf("Used memory: %zu bytes\n\n", alloc->used_memory);
	}
	else
		printf("FAILED to allocate str2\n\n");
	
	// Test 3: Allocate array of integers
	printf("Test 3: Allocating 40 bytes for numbers (10 ints)...\n");
	numbers = (int *)ft_alloc_a_checkout(alloc, 40);
	if (numbers)
	{
		for (int i = 0; i < 10; i++)
			numbers[i] = i * 10;
		printf("numbers: ");
		for (int i = 0; i < 10; i++)
			printf("%d ", numbers[i]);
		printf("\n");
		printf("Used memory: %zu bytes\n\n", alloc->used_memory);
	}
	else
		printf("FAILED to allocate numbers\n\n");
	
	// Test 4: Return str2 (middle allocation)
	printf("Test 4: Returning str2...\n");
	ft_alloc_a_checkin(alloc, str2);
	printf("Used memory after checkin: %zu bytes\n\n", alloc->used_memory);
	
	// Test 5: Allocate small string (should reuse freed space)
	printf("Test 5: Allocating 32 bytes for str3 (reuse freed space)...\n");
	str3 = (char *)ft_alloc_a_checkout(alloc, 32);
	if (str3)
	{
		strcpy(str3, "Reused memory!");
		printf("str3: %s\n", str3);
		printf("Used memory: %zu bytes\n\n", alloc->used_memory);
	}
	else
		printf("FAILED to allocate str3\n\n");
	
	// Test 6: Return all allocations
	printf("Test 6: Returning all allocations...\n");
	ft_alloc_a_checkin(alloc, str1);
	ft_alloc_a_checkin(alloc, numbers);
	ft_alloc_a_checkin(alloc, str3);
	printf("Used memory after all checkins: %zu bytes\n", alloc->used_memory);
	printf("(Should be 0 or close to 0 if merging works)\n\n");
	
	printf("=== Callback Complete ===\n");
	return (0);
}

int main(void)
{
	struct s_alloc_a *alloc = NULL;
	int result;
	
	printf("Creating stack-based allocator with 2048 bytes...\n\n");
	
	result = ft_alloc_a_create(2048, &alloc, test_callback, &alloc);
	
	printf("\nBack in main, result: %d\n", result);
	printf("alloc pointer (should be NULL): %p\n", (void *)alloc);
	
	return (0);
}