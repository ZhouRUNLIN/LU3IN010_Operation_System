#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char* temp = "";
	char* command = argv[0];
	int p = 0; int i = 1;
	while(i<argc && p==0){
		if((p=fork()) == 0){
			execl("./", "grep", command, argv[i]);
			printf("p:%d i:%d\n",p,i);
			i++;
		}
	}
	if(p != 0) wait(NULL);
	printf("p:%d i:%d\n",p,i);
	return 0;
}