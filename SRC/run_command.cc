#include "head/instreem.h"
#include "head/run_commands.h"

int run_command(int margc, vector<string> margv){
	/*
	printf("margc: %d\n", margc);
	for(int i=0; i<margv.size(); i++){
		printf("margv[%d]: %s \n", i, margv[i].c_str());
	}
	*/


	if(strcmp(margv[0].c_str(), "") == 0){
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "help") == 0){
		help();
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "exit") == 0){
		printf("bye.... \n");
		exit(0);
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "view") == 0){
		view_projects();
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "make") == 0){
		make_project(margc, margv);
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "delete") == 0){
		delete_project(margc, margv);
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "rename") == 0){
		rename_project(margc, margv);
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "save") == 0){
		save_project(margc, margv);
		return RET_SUCCECC;
	}
	
	else if(strcmp(margv[0].c_str(), "clear") == 0){
		system("clear");
		return RET_SUCCECC;
	}
	
	else if(strcmp(margv[0].c_str(), "connect") == 0){
		connect_server(margc,margv);
		return RET_SUCCECC;
	}
	
	else if(strcmp(margv[0].c_str(), "load") == 0){
		if(margc < 3){
			fprintf(stderr, "runcmd: argument not support\n");
			return RET_SUCCECC;
		}
		load_project(margc, margv);
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "dsrc") == 0){
		if(margc != 3){
			fprintf(stderr, "info: argument not support\n");
			return RET_FAILED;
		}

		Project PJCT(margv[1].c_str());
		if(PJCT.exist){
			PJCT.dsrc(margv[2].c_str());
		}else		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "dedit") == 0){
		if(margc!=2){
			fprintf(stderr, "dedit: argument not support\n");
			return RET_FAILED;
		}

		Project PJCT(margv[1].c_str());
		PJCT.dedit();
		return RET_SUCCECC;
	}

	else if(strcmp(margv[0].c_str(), "info") == 0){
		if(margc!=2){
			fprintf(stderr, "info: argument not support\n");
			return RET_FAILED;
		}

		Project PJCT(margv[1].c_str());
		if(PJCT.exist){
			PJCT.info();
			return RET_SUCCECC;
		}else	return RET_FAILED;
	}

	else{
		fprintf(stderr, "%s: command not found\n", margv[0].c_str());
	}
}
