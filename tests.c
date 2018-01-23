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
		exit(1);
	}
	else {
		// in parent
		printf(stdout, "hello from parent\n");
		
		int exitStatus = -1;
		int childpid = wait(&exitStatus);
		
		if (childpid > 0) {
			if (exitStatus >= 0) {
				printf(stdout, "exit status of pid %d: %d\n", pid, exitStatus);
			}
			else {
				printf(stdout, "Error in pid %d; no exit status\n", pid);
				exit(0);
			}
		}
		else {
			printf(stdout, "error: no return value, child process not found\n");
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
