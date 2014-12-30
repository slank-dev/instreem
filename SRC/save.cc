#include "head/instreem.h"

int save_project(int margc, vector<string> margv){
	Project PJCT(margv[1].c_str());
	
	if(margc != 2){
		fprintf(stderr, "save: argument not support\n");
		return RET_FAILED;
	}else if(!PJCT.check_edit()){
		fprintf(stderr, "save: edit src not found\n");
		return RET_FAILED;
	}
	
	
	char time[16];
	string add_name;
	string dname;
	string buf;



	printf("ADD NAME?(Yes/No): ");
	cin >> buf;
	if(buf=="Yes"){
		printf("input add_name: ");
		cin >> add_name;
	}

	get_time(time);
	dname = (string)time + "-" + add_name + ".zip";
	
	zip_file(PJCT.edit_path.c_str(), "edit_src", PJCT.src_path.c_str(), dname.c_str());

	printf("DELETE NOW EDIT?(Yes/No): ");
	cin >> add_name;
	if(add_name=="Yes"){
		PJCT.dedit();
	}


	return RET_SUCCECC;
}
