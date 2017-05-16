#define _XOPEN_SOURCE
#include <time.h>
#include <republican_calendar.h>
#include <assert.h>

#include "../src/time.c"

static void test_republican_localtime(void)
{
	struct tm	tm;
	struct rtm	*rtm;
	time_t		base;

	/* init */
	strptime("2017-5-15 18:31:01", "%Y-%m-%d  %H:%M:%S", &tm);
	base = mktime(&tm);
	/* run */
	rtm = republican_localtime(&base);
	/* check */
	assert(rtm->rtm_year == 225);
	assert(rtm->rtm_yday == 236);
	assert(rtm->rtm_mon == 8);
	assert(rtm->rtm_mday == 27);
	assert(rtm->rtm_dday == 7);
}

int	main(void)
{
	test_republican_localtime();
	return (0);
}
