#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>


int main(int argc, char *argv[]){
	openlog("my_writer", 0,  LOG_USER);

	if (argc < 3) {
		syslog(LOG_ERR, "args missing dude");
		closelog();
		return 1;
	}

	int fd = open(argv[1], O_WRONLY | O_TRUNC);
	if (fd == -1) {
		syslog(LOG_ERR, "unable to open file, dude");
		closelog();
		return 1;
	}

	ssize_t nr;
	nr = write(fd, argv[2], strlen(argv[2]));
	if (nr < 0) {
		syslog(LOG_ERR, "unable to write to a file, dude");
		closelog();
		close(fd);
		return 1;
	}
	
	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
	fsync(fd);
	close(fd);
	closelog();

	return 0;

}
