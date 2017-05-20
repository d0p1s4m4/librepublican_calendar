/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <republican_calendar.h>

static char const __republican_dday_name[][8] = {
	"Primidi", "Duodi", "Tridi", "Quartidi", "Sextidi", "Octidi", "Nonidi",
	"Décadi"
};

static char const __republican_mon_name[][12] = {
	"Vendémiaire", "Brumaire", "Frimaire", "Nivôse", "Pluviôse", "Ventôse",
	"Germinal", "Floréal", "Prairial", "Messidor", "Thermidor", "Fructidor"
};

char	*republican_asctime(republican_time_t const *rtm)
{
	static char	result[26];

	sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
		__republican_dday_name[rtm->rtm_dday],
		__republican_mon_name[rtm->rtm_mon],
		rtm->rtm_mday,
		rtm->rtm_hour, rtm->rtm_min, rtm->rtm_sec,
		rtm->rtm_year);
	return (result);
}
