#define _XOPEN_SOURCE
#include <time.h>
#include <republican_calendar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/time.c"

static void test_republican_localtime(void **state)
{
	struct tm	tm;
	struct rtm	*rtm;
	time_t		base;

	(void)state;
	/* init */
	strptime("2017-5-15", "%Y-%m-%d", &tm);
	base = mktime(&tm);
	/* run */
	rtm = republican_localtime(&base);
	/* check */
	assert_int_equal(rtm->rtm_year, 225);
	assert_int_equal(rtm->rtm_yday, 236);
	assert_int_equal(rtm->rtm_mon, 8);
}

int	main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_republican_localtime)
	};

	return (cmocka_run_group_tests(tests, NULL, NULL));
}
