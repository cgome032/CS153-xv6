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
	return 0;
}
