/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
#include <republican_calendar.h>
#include <stdlib.h>
#include <string.h>

// TODO: Quick'n'dirty. Need to fix it
#define PUSH_TO_BUFF(l) do { \
							buff_size += strlen(l); \
							if (buffer == NULL) { buffer = malloc(((buff_size) + 1) * sizeof(char)); buffer[0] = '\0'; } \
							else { buffer = realloc(buffer, ((buff_size) + 1) * sizeof(char)); } \
							strcat(buffer, l); \
							buffer[buff_size] = '\0'; \
							} while (0)

char *__republican_strdup(char const *str);

static char const *__roman_symbol_huns[] = {
	"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
};
static char const *__roman_symbol_tens[] = {
	"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
};
static char const *__roman_symbol_ones[] = {
	"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};

char	*to_roman(int number)
{
	char	*buffer = NULL;
	size_t	buff_size = 0;

	if (number < 0 || number > 3999)
		return (NULL);
	if (number == 0)
		return __republican_strdup("nulla");
	while (number >= 1000)
	{
		PUSH_TO_BUFF("M");
		number -= 1000;
	}
	if (number >= 100)
	{
		PUSH_TO_BUFF(__roman_symbol_huns[(number/100) - 1]);
		number %= 100;
	}
	if (number >= 10)
	{
		PUSH_TO_BUFF(__roman_symbol_tens[(number/10) - 1]);
		number %= 10;
	}
	if (number < 10 && number > 0)
		PUSH_TO_BUFF(__roman_symbol_ones[(number) - 1]);
	buffer[buff_size] = '\0';
	return (buffer);
}
