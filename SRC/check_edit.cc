#include "head/instreem.h"

bool check_edit(const char* pname){	
	int flag=0;
	Project PJCT(pname);
	dcont dc(PJCT.edit_path.c_str());

	for(int i=0; i<dc.size; i++){
		if(dc.files[i].type > 0)
			flag++;
	}

	
	if(flag > 0){
		return true;
	}else{
		return false;
	}
}
