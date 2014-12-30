#include <time.h>

void get_time(char *str){
	time_t t;
	struct tm *t_inf;

	t = time(NULL);
	t_inf = localtime(&t);
	strftime(str, 16, "%y%m%d%H%M", t_inf);
}
