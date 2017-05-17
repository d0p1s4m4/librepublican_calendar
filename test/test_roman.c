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

int	main(void)
{
	test_to_roman_nulla();
	return (0);
}
