/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
#ifndef REPUBLICAN_CALENDAR_H_
# define REPUBLICAN_CALENDAR_H_ 1

# include <time.h>

struct rtm {
	int	rtm_sec;	/* 0 - 61 */
	int	rtm_min;	/* 0 - 59 */
	int	rtm_hour;	/* 0 - 23 */
	int	rtm_mday;	/* 1 - 30 */
	int	rtm_mon;	/* 0 - 11 */
	int	rtm_year;
	int	rtm_dday;	/* 0 - 9 */
	int	rtm_yday;	/* 0 - 365 */
	int	rtm_isdst;
};

typedef struct rtm republican_time_t;

/*
 * localtime.c
 */

republican_time_t	*republican_localtime(time_t const *timer);
republican_time_t	*republican_localtime_r(time_t const *timer,
						republican_time_t *rtp);

/*
 * asctime.c
 */

char			*republican_asctime(republican_time_t const *rtm);

#endif /* !REPUBLICAN_CALENDAR_H_ */
