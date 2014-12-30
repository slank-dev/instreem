#include <string>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;



class instreem_info{
public:

	string project_root;
	string document_root;
	string module_root;

	instreem_info(){
		string path = getenv("HOME");
		path += "/.instreemrc";
		FILE *fp;
		char line_buf[256];

		if((fp = fopen(path.c_str(), "r") )==NULL){
			perror("instreemrc open error");
		}else{
			for(char c=fgetc(fp); c!=EOF; c=fgetc(fp)){
				memset(line_buf, 0, sizeof(line_buf));
				for(int i=0; c!='\n'; c=fgetc(fp), i++){
					line_buf[i] = c; 
				}
				
				//scan PROJECT_ROOT
				if(strncmp(line_buf, "PROJECT_ROOT", strlen("PROJECT_ROOT")) == 0){
					project_root = (line_buf+strlen("PROJECT_ROOT")+1);
				}
				

				//scan DOCUMENT_ROOT
				if(strncmp(line_buf, "DOCUMENT_ROOT", strlen("DOCUMENT_ROOT")) == 0){
					document_root = (line_buf+strlen("DOCUMENT_ROOT")+1);
				}

				//scan MODULE_ROOT
				if(strncmp(line_buf, "MODULE_ROOT", strlen("MODULE_ROOT")) == 0){
					module_root = (line_buf+strlen("MODULE_ROOT")+1);
				}

			}


		}//end else

	}



};

