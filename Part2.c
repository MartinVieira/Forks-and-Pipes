#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () 
{
int fd[2];
int x,y = 0;
pid_t pid;

if (pipe(fd) < 0)
{
	perror("pipe error");
}

if ((pid = fork()) < 0)
{
	perror("fork unsuccessful");
}

else if (pid > 0)
{
	printf("Enter a number: \n");
	scanf("%d", &x);
	waitpid(pid,0,0);
	read(fd[0], &y, sizeof(y));
	printf("The sum of the two numbers is %d\n", x+y);
}

else 
{
	sleep(2);
	printf("Enter a number: \n");
	scanf("%d", &y);
	write(fd[1], &y, sizeof(y));
}

exit(0);
}
