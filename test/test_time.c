/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
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
	assert(rtm->rtm_mon == (8 - 1));
	assert(rtm->rtm_mday == 26);
	assert(rtm->rtm_dday == (6 - 1));
}

int	main(void)
{
	test_republican_localtime();
	return (0);
}
