# Republican Calendar

[![Coverage Status](https://coveralls.io/repos/github/d0p1s4m4/librepublican_calendar/badge.svg)](https://coveralls.io/github/d0p1s4m4/librepublican_calendar)
[![Build Status](https://travis-ci.org/d0p1s4m4/librepublican_calendar.svg?branch=master)](https://travis-ci.org/d0p1s4m4/librepublican_calendar)
[![Build status](https://ci.appveyor.com/api/projects/status/r45xd98vg0h5gpg7?svg=true)](https://ci.appveyor.com/project/d0p1s4m4/librepublican-calendar)

# Usage

```c
#include <republican_calendar.h>
#include <stdio.h>

int main(void)
{
  struct rtm  rtm;
  time_t t;

  time(&t);
  republican_localtime_r(&t, &rtm);
  printf("Nous sommes le %d/%d de l'An %d\n", rtm.rtm_mday, rtm.rtm_mon, rtm.rtm_year);
  return (0);
}
```

# Credit

inspired by: https://github.com/cobaltway/calendrier-republicain
