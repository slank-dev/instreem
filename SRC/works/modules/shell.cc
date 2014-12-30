#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#define MAXCMDLWN 256
#define MAXARGS 8
using namespace std;


int shell(){
	int arg_number;
	int margc;
	char command[MAXCMDLWN];
	string arg_buf;
	vector<string> margv;

	for(;;){ //start main_loop
		margv.clear();

		printf(">>> ");
		fgets(command, MAXCMDLWN, stdin);
		command[strlen(command)-1] = '\0';
		
		
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
		printf("margc: %d \n", margc);
		for(int i=0; i<margc; i++){
			printf("margv[%d]: %s \n", i, margv[i].c_str());
		}

		
	}	//end main_loop

}

