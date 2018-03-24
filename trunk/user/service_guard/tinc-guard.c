
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>
#include <stdint.h>
#include <syslog.h>
#include <ctype.h>

#include <shutils.h>

#define CHECK_INTERVAL 90

int main(int argc, char *argv[])
{

	signal(SIGPIPE, SIG_IGN);
	signal(SIGALRM, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
//	signal(SIGCHLD, chld_reap);

//printf("%d\n", argc);

	if(argc == 1) {
		if (daemon(1, 1) == -1) {
			syslog(LOG_ERR, "daemon: %m");
			return 0;
		}
	}

	sleep(10);

	while (1) {
//printf("%s:%d et0macaddr=%s\n", __FUNCTION__, __LINE__, nvram_safe_get("et0macaddr"));
		if(pids("tincd") <= 0) {
			eval("restart_tinc");
		}

		sleep(CHECK_INTERVAL);
	}

	return 0;
}
