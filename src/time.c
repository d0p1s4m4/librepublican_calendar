#include <republican_calendar.h>

static republican_time_t	rtm;

republican_time_t	*republican_localtime(time_t const *timer)
{
	return (republican_localtime_r(timer, &rtm));
}

static inline int __republican_get_correct_year(struct tm const *__restrict current)
{
	if (current->tm_mon < 8 ||
			(current->tm_mday < 22 && current->tm_mon == 8))
		return (current->tm_year);
	return (current->tm_year + 1);
}

static void __republican_get_day_of_year(struct tm const *tm,
					republican_time_t *rtp)
{
	struct tm	first_day;
	struct tm	current;
	double		second;

	current = *tm;
	first_day = *tm;
	if (current.tm_mon < 8 || (current.tm_mday < 22 && current.tm_mon == 8))
		first_day.tm_year -= 1;
	first_day.tm_mday = 22;
	first_day.tm_mon = 8;
	first_day.tm_yday = 265;

	second = difftime(mktime(&current), mktime(&first_day));
	rtp->rtm_yday = (second / (60 * 60 * 24)) + 1;
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

	rtp->rtm_year = (__republican_get_correct_year(tminfo) + 1900) -  1792;
	__republican_get_day_of_year(tminfo, rtp);
	rtp->rtm_mon = (rtp->rtm_yday / 30) + 1;
	return (rtp);
}
