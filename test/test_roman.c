/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <republican_calendar.h>
#include <string.h>
#include <assert.h>

#include "../src/roman.c"

static void test_to_roman_nulla(void)
{
	char	*res;

	/* init */
	/* run */
	res = to_roman(0);

	/* check */
	assert(strcmp(res, "nulla") == 0);

	free(res);
}

static void test_to_roman_limits(void)
{
	assert(to_roman(-666) == NULL);
	assert(to_roman(999999) == NULL);
}

int	main(void)
{
	test_to_roman_nulla();
	test_to_roman_limits();
	return (0);
}
