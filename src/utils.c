/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <string.h>

char *__republican_strdup(char const *str)
{
	size_t	len;
	char	*res;

	if (str == NULL)
		return (NULL);
	len = strlen(str);
	if (len == 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	strcpy(res, str);
	return (res);
}
