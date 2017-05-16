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
republican_time_t	*republican_localtime_r(time_t const *timer,
						republican_time_t *rtp);

#endif /* !REPUBLICAN_CALENDAR_H_ */
