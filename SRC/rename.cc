
#include "head/instreem.h"


int rename_project(int margc, vector<string> margv){
	if(margc != 3){
		fprintf(stderr, "rename_project: argument not support\n");
		return RET_FAILED;
	}else if(!project_exist(margv[1].c_str())){
		fprintf(stderr, "rename_project: project not found \n");
		return RET_FAILED;
	}else if(project_exist(margv[2].c_str())){
		fprintf(stderr, "rename_project: new name one is exist \n");
		return RET_FAILED;
	}



	Project PJCT(margv[1].c_str());
	instreem_info INFO;
	string newname = INFO.project_root + margv[2] + "/";

	if(rename(PJCT.path.c_str() , newname.c_str()) == 0){
		fprintf(stdout, "rename successful \n");
		return RET_SUCCECC;
	}else{
		fprintf(stderr, "rename failed \n");
		return RET_FAILED;
	}


}
