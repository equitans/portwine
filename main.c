#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>

int singleScan (char * ip[15], char * port[10]);

// Validation Arguments in command line.
void validateArgs (int argc, char * argv[]){
	
	for (int i = 1; i < argc; i++){
		if (strcmp("singlescan", argv[i]) == 0){
			printf("single scan\n");
			singleScan(argv[3], argv[4]);
		} else if (strcmp("masscan", argv[i]) == 0){
			printf("MASSCAN!!!\n");
		}
		else {
			printf("Invalid ARgs\n");
		}
	}
}

int main (int argc, char * argv[]){

	if (argc > 1) validateArgs(argc, argv);
	
	return 0;
}

int singleScan (char * ip[15], char * port[10]){
	int sock;
	struct sockaddr_in addr;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0){
		printf("Socket: connect, error.");
		exit(0);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(**port);
	addr.sin_addr.s_addr = htonl(**ip);
	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
		printf("Connect: struct, error.");
		exit(1);
	}




}
