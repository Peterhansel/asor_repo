#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){
	mode_t lastmask;
	lastmask = umask(0027);
	int file = open(argv[1],O_CREAT,0666);
	if(file == -1){
		perror("open error");
	}
	umask(cmask);
	return 0;
}
