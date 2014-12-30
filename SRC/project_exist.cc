#include "head/instreem.h"


bool project_exist(const char* proname){
	instreem_info INFO;
	dcont dc(INFO.project_root.c_str());
	
	for(int i=0; i<dc.size; i++){
		if(dc.files[i].type > 0)
			if(strcmp(dc.files[i].name.c_str(), proname) == 0)
				return true;
		
	}
	return false;
}
