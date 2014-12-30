#include "insteem.h"
#include "dcont.h"
#include "run_commands.h"

class project{
public:
	string name;
	string root_path;
	string edit_path;
	string src_path;
	string test_path;
	
	project(const char* buf_name){
		name = buf_name;
		root_path = INFO.project_root() + name + "/";
		edit_path = INFO.project_root() + name + "/edit/";
		src_path  = INFO.project_root() + name + "/src/";
		test_path = INFO.project_root() + name + "/test/";
	}
}


int load_project(const char* project_name){
	
}

int main(int argc, char **argv){}
