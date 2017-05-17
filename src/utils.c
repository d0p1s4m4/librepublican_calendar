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
