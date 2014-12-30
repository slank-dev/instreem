#include "head/instreem.h"


int help(){
	instreem_info INFO;
	fprintf(stdout, "PROJECT_ROOT :%s\n", INFO.project_root.c_str());
	fprintf(stdout, "DOCUMENT_ROOT:%s\n", INFO.document_root.c_str());
	fprintf(stdout, "MODULE_ROOT  :%s\n", INFO.module_root.c_str());
	
	string path = INFO.document_root + "help.txt";


	FILE *fp;
	if((fp = fopen(path.c_str(), "r")) == NULL){
		perror("help command");
		return RET_FAILED;
	}

	for(char c=fgetc(fp); c!=EOF; c=fgetc(fp)){
		putc(c, stdout);
	}

}


