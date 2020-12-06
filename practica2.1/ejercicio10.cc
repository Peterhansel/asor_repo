#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>

int main(){
	struct passwd *info;
	printf("UID Real: %zu\n",getuid());
	printf("UID Efectivo: %zu\n", geteuid());
	info=getpwuid(getuid());
	printf("Username: %s\n",info->pw_name);
        printf("Home directory: %s\n",info->pw_dir);
        printf("User Info: %s\n",info->pw_gecos);
	return 0;
}
