#include "head/instreem.h"
#include "head/run_commands.h"


int load_project(int margc, vector<string> margv){
	Project PJCT(margv[1].c_str());

	if(!PJCT.exist){
		return RET_FAILED;
	}
	
	
	if(PJCT.check_edit()){
		fprintf(stdout, "%s has edit_src already, load save()\n", PJCT.name.c_str());
		save_project(2, margv);
	}	


	//new
	if(margv[2] == "new"){
		if(margc != 3){
			fprintf(stderr, "load new: argument not support\n");
			return RET_FAILED;
		}
		
		string fullpath = PJCT.edit_path + "edit_src/";
		if(mkdir(fullpath.c_str(), 0775)!=0){
			perror("load new:");
			return RET_FAILED;
		}
		fprintf(stdout, "load new edit_src successful\n");
		return RET_SUCCECC;
	}
	
	//other
	else if(margv[2] == "other"){
		if(margc != 4){
			fprintf(stderr, "load other: argument not support\n");
			return RET_FAILED;
		}
		dcont dc(PJCT.src_path.c_str());

		for(int i=0; i<dc.size; i++){
			if(margv[3]  ==  dc.files[i].name){
				unzip_file(PJCT.src_path.c_str(), margv[3].c_str(), PJCT.edit_path.c_str(), "edit_src");
				fprintf(stdout, "load %s successful\n", margv[3].c_str());
				return RET_SUCCECC;
			}
			
		}
		fprintf(stderr, "load other: src not found\n");
		return RET_FAILED;
		
	}
	

	//late
	else if(margv[2] == "late"){
		if(margc != 3){
			fprintf(stderr, "load late: argument not support\n");
			return RET_FAILED;
		}

		dcont dc(PJCT.src_path.c_str());
		unzip_file(PJCT.src_path.c_str(), dc.files[dc.size-1].name.c_str() , PJCT.edit_path.c_str(), "edit_src");
		fprintf(stdout, "load %s successful\n", "late_src");
		return RET_SUCCECC;

	
	}
	

	//error
	else{
		fprintf(stderr, "load: option mode not found\n");
		return RET_FAILED;
	}

}
