#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
pid_t parent = getpid(); 
pid_t pid1 = fork();

if (pid1 < 0) 
{
	perror("fork unsuccessful");
}

if (pid1 > 0) 
{
	waitpid(pid1, 0, 0);
	pid_t pid2 = fork();

	if (pid2 == 0)
	{
		execl("B.out", "B.out", 0, NULL);
	}
}

else
{
	if (pid1 == 0) 
	{
		pid_t pid11 = fork();
	}
}
}
