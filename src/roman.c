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
