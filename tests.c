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

void exittest() {
	printf(stdout, "exittest started\n");
	int pid;
	if ((pid = fork()) == 0) {
		// in child
		
		printf(stdout, "hello from child\nexiting child with status: %d\n", 1);
		exit(2);
	}
	else {
		// in parent
		printf(stdout, "hello from parent\n");
		
		int exitStatus;
		int childpid = wait(&exitStatus);
		
		if (childpid > 0) {
			if (exitStatus >= 0) {
				printf(stdout, "exit status of child pid %d: %d\n", childpid, exitStatus);
			}
			else {
				printf(stdout, "Error in pid %d; no exit status\n", childpid);
				exit(0);
			}
		}
		else {
			printf(stdout, "error: process had no children\n");
		}
		
		exit(0);
		
	}
}

void waittest(void) {
	//int pid;
	
	printf(stdout, "waittest started\n");
	
}

void waitpidtest(void) {
	//int i, pid;
	
	printf(stdout, "waitpidtest started\n");
	
}

int main() {
	printf(stdout, "in tests.c main function\n");
	
	exittest();
	
	exit(0);
}
