#ifndef REPUBLICAN_CALENDAR_H_
# define REPUBLICAN_CALENDAR_H_ 1

# include <time.h>

struct rtm {
	int	rtm_sec;
	int	rtm_min;
	int	rtm_hour;
	int	rtm_mday;
	int	rtm_mon;
	int	rtm_year;
	int	rtm_dday;
	int	rtm_yday;
	int	rtm_isdst;
};

typedef struct rtm republican_time_t;

/*
 * time.c
 */

republican_time_t	*republican_localtime(time_t const *timer);
republican_time_t	*republican_localtime_r(time_t const *__restrict timer,
						republican_time_t *rtp);
republican_time_t	*to_republican(struct tm const *__restrict info);

#endif /* !REPUBLICAN_CALENDAR_H_ */
