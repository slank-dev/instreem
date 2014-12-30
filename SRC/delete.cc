
#include "head/instreem.h"


int delete_project(int margc, vector<string> margv){		//not complite !!! make load_project();
	if(margc != 2){
		fprintf(stderr, "delete_project: argument not support\n");
		return RET_FAILED;
	}else if(!project_exist(margv[1].c_str())){
		fprintf(stderr, "delete_project: project not found \n");
		return RET_FAILED;
	}

	char buf[8];
	fprintf(stdout, "Really delete ?(Yes/No) ");
	scanf("%5s", buf);
	
	if(strcmp(buf, "Yes") == 0){
		instreem_info INFO;
		Project PJCT(margv[1].c_str());
		
		string buf_cmd = "perl  " +  INFO.module_root + "rmtree.pl" + "  " + PJCT.path; 
		system(buf_cmd.c_str());
		fprintf(stdout, "delete %s successful\n", margv[1].c_str());
		return RET_SUCCECC;
	}else{
		fprintf(stderr, "delete %s failed\n", margv[1].c_str());
		return RET_FAILED;
	}
}

