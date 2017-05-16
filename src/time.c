#include <republican_calendar.h>

static republican_time_t	rtm;

republican_time_t	*republican_localtime(time_t const *timer)
{
	return (republican_localtime_r(timer, &rtm));
}

republican_time_t	*republican_localtime_r(time_t const *__restrict timer,
						republican_time_t *rtp)
{
	struct tm	*tminfo;

	tminfo = localtime(timer);
	rtp->rtm_sec = tminfo->tm_sec;
	rtp->rtm_min = tminfo->tm_min;
	rtp->rtm_hour = tminfo->tm_hour;
	rtp->rtm_isdst = tminfo->tm_isdst;

	rtp->rtm_year = (tminfo->tm_year + 1900) -  1792;
	return (rtp);
}
