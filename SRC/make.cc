#include "head/instreem.h"


int make_project(int margc, vector<string> margv){
	if(margc != 2){
		fprintf(stderr, "make_project: argument not support \n");
		return RET_FAILED;
	}else if(project_exist(margv[1].c_str())){
		fprintf(stderr, "make_project: this name is exist \n");
		return RET_FAILED;
	}  


	instreem_info INFO;
	string project_fullpath = INFO.project_root + margv[1] + "/";	
	fprintf(stdout, "FULLPATH: %s \n", project_fullpath.c_str());
	
	if(mkdir(project_fullpath.c_str(), 0775) == 0){
		chdir(project_fullpath.c_str());
		mkdir("edit", 0775);
		mkdir("src",  0775);
		mkdir("test", 0775);
	
		fprintf(stdout, "-------------------------------\n");
		fprintf(stdout, "  %s\n", margv[1].c_str());
		fprintf(stdout, "  ├── edit \n");
		fprintf(stdout, "  ├── src \n");
		fprintf(stdout, "  └── test \n");
		fprintf(stdout, "-------------------------------\n");

		fprintf(stdout, "make %s successful \n", margv[1].c_str());
		return RET_SUCCECC;
	}else{
		fprintf(stderr, "make_project: make %s failed \n", margv[1].c_str());
		return RET_FAILED;
	}
}


