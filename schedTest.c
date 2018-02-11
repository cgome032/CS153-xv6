// Test file
#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h" // printf()
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int stdout = 1;

int main() {
	//printf(stdout, "in tests.c main function\n");
	
	//exittest();
	printf(stdout, "Testing scheduling priority function\n");
	int pid1,pid2,pid3;

	if ((pid1 = fork())==0){
		// First Child
		setpriority((int)getpid(),0);
	 	printf(stdout, "This is the first child created, pid(%d)\n",(int)getpid());
		while(1){
			printf(stdout, "A");
		}
        	exit(0); // First child exits
        }
        else if ((pid2 = fork())==0){
        	// Second Child
		setpriority((int)getpid(),15);
        	printf(stdout, "This is the second child created, pid(%d)\n", (int)getpid());
		while(1){
			printf(stdout, "B");
		}
        	exit(0); // Second child exits
	}
	else if ((pid3=fork())==0){
		// Third Child
		setpriority((int)getpid(),25);
		printf(stdout, "This is the third child created, pid(%d)\n", (int)getpid());
		while(1){
			printf(stdout, "C");
		}
		exit(0);
	}
	int status1, status2, status3;
	waitpid(pid1,&status1,0);
	waitpid(pid2,&status2,0);
	waitpid(pid3,&status3,0);
	
	exit(0);
}
