
#include "head/instreem.h"


int view_projects(){
	instreem_info INFO;
	dcont dc(INFO.project_root.c_str());
	
	fprintf(stdout, "-project--------------------------------\n");
	for(int i=0; i<dc.size; i++){
		if(dc.files[i].type > 0)
			fprintf(stdout, "	[*] %s \n", dc.files[i].name.c_str());
	}
	fprintf(stdout, "----------------------------------------\n");

	return RET_SUCCECC;
}

