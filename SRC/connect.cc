#include "head/instreem.h"
#define RCVBUFSIZE 32

int connect_server(int margc, vector<string> margv){

	if(margc != 3){
		fprintf(stderr, "connect: argument not support\n");
		return RET_FAILED;
	}
	
	
	int sock;
	struct sockaddr_in serv_addr;
	char message[RCVBUFSIZE];
	char ipaddr[32];
	unsigned int msglen;
	unsigned int port;
	char rcvBuffer[1000];


	strcpy(ipaddr, margv[1].c_str());
	port = atoi(margv[2].c_str());


	if((sock=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		perror("make socket");
		return RET_FAILED;
	}


	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(ipaddr);
	serv_addr.sin_port = htons(port);


	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0){
		perror("connect()");
		return RET_FAILED;
	}

	while(1){
		printf("[%s]@ ", inet_ntoa(serv_addr.sin_addr));
		fgets(message, sizeof(message)-2,stdin);
		message[strlen(message)-1] = '\0';

		if(send(sock, message,sizeof(message),0)<0){
			perror("send()");
			return RET_FAILED;
		}
	
		/*
			if END recv then break this loop
			[todo] make  loop start flag!!
		
		*/
		while(1){
			recv(sock, rcvBuffer, sizeof(rcvBuffer), 0);
			rcvBuffer[strlen(rcvBuffer)] = '\0';
			if(strcmp("END", rcvBuffer)==0){
				break;
			}

			printf("%s\n", rcvBuffer);
		}
		


	}

	return RET_SUCCECC;

}
