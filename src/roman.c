/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
#include <republican_calendar.h>
#include <string.h>

char *__republican_strdup(char const *str);

static char const __roman_symbol[] = {
	'I', 'V', 'X', 'C', 'D', 'M'
	/* 1, 5,  10,  100, 500, 1 000 */
};

char	*to_roman(int number)
{
	char	tampon[9] = { '\0' };

	if (number < 0 || number > 3999)
		return (NULL);
	if (number == 0)
		return __republican_strdup("nulla");
	(void)__roman_symbol;
	(void)tampon;
	return (NULL);
}
