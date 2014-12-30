
#include "head/instreem.h"
#define MAXCMDLWN 256


int shell(){
	FILE *fp;
	int arg_number;
	int margc=0;
	char command[MAXCMDLWN];
	string arg_buf;
	vector<string> margv;
	instreem_info INFO;

	if((fp = fopen((INFO.document_root + "command_history.log").c_str() ,"a"))==NULL){
		perror("shell hist:");
		exit(RET_FAILED);
	}


	for(;;){ //start main_loop
		margv.clear();

		printf("[instreem]@ ");
		fgets(command, MAXCMDLWN, stdin);
		command[strlen(command)-1] = '\0';
	
		fprintf(fp, "%s \n", command);
		
		
		for(char* c=command; *c!='\0'; c++){
			if(*c != ' '){
				for(;(*c!=' ')&&(*c!='\0'); c++){
					arg_buf  += *c;
				}
				margv.push_back(arg_buf);
				arg_buf.clear();
			}
		}
		margc = margv.size();

		
		/*	
		//show marg		
		printf("margc: %d \n", margc);
		for(int i=0; i<margc; i++){
			printf("margv[%d]: %s \n", i, margv[i].c_str());
		}
		*/

		if(margc > 0){
			run_command(margc, margv);	
		}


	}//end main_loop

	return RET_SUCCECC;

}
