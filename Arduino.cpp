#include <sys/time.h>
#include <unistd.h>

unsigned long millis( void )
{
  /* similar to the micros() function, it returns ms since sketch start up time.
   The underlying counter is a 64 bit value, but the representation of millis
   as unsigned 32-bits means it recycles in ~ 1190 hours.*/

  struct timeval end;

  gettimeofday(&end, NULL);
  return (end.tv_sec * 1000000 + end.tv_usec) / 1000;
}

void delay(unsigned long time)
{
  usleep(time * 1000);
}

/* vi: set et sw=2 sts=2: */
