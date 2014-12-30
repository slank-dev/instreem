#include <cstdio>	//stdio.h
#include <cstring>	//string.h
#include <cstdlib>	//stdlib.h
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#include "info.h"
#include "dcont.h"
#include "client.h"

#define RET_SUCCECC  0
#define RET_FAILED	-1

using namespace std;

//main functions prottpe
int shell();
int run_command(int margc, vector<string> margv);

//sub functions prottpe
bool project_exist(const char* project_name);
//bool check_edit(const char* pname);
void get_time(char *str);
void zip_file(const char*,const  char*,const  char*,const  char*);
void unzip_file(const char*,const  char*,const  char*,const  char*);


//class
class Project{
public:
	string name;
	string path;
	string edit_path;
	string src_path;
	string test_path;
	bool exist;
	Project(const char* pname){
		path = "/";
		edit_path = "/";
		src_path = "/";
		test_path = "/";


		if(project_exist(pname)){
			exist = true;
		}else{
			fprintf(stderr, "class Project: project not found\n");
			exist = false;
			return;
		}

		
		instreem_info INFO;

		name = pname;
		path = INFO.project_root + name + "/";
		edit_path    = INFO.project_root + name + "/edit/";
		src_path     = INFO.project_root + name + "/src/";
		test_path    = INFO.project_root + name + "/test/";

	}
	void info(){
	
		dcont dc(src_path.c_str());

		fprintf(stdout, "NAME: %s\n", name.c_str());
		fprintf(stdout, "PATH: %s\n", path.c_str());
		fprintf(stdout, "SRC : \n");

		for(int i=0; i<dc.size; i++){
			if(dc.files[i].type > 0)
				fprintf(stdout, "	[*] %s\n", dc.files[i].name.c_str());
		}
		if(dc.size <= 2)
			fprintf(stdout, "	no src\n");
			
		fprintf(stdout, "EDIT NOW: ");
		if(check_edit())				printf("YES\n");
		else							printf("NO\n");

	}
	
	bool check_edit(){	
		int flag=0;
		dcont dc(edit_path.c_str());

		for(int i=0; i<dc.size; i++){
			if(dc.files[i].type > 0)
				flag++;
		}

		if(flag > 0)	return true;
		else			return false;
	}

	int dedit(){
		char buf[8];
		string command;
		instreem_info INFO;

		fprintf(stdout, "really delete edit_src?(Yes/No): ");
		scanf("%s", buf);
		if(strcmp(buf, "Yes") == 0){
			command = "perl " + INFO.module_root + "rmtree.pl " + edit_path + "edit_src/";
			system(command.c_str());
			fprintf(stdout, "delete edit_src of %s successful\n", name.c_str());
			return RET_SUCCECC;
		}else{
			fprintf(stdout, "delete failed\n");
			return RET_FAILED;
		}
	}

	int dsrc(const char* srcname){
		string buf;
		string command;
		instreem_info INFO;
		dcont dc(src_path.c_str());
		
		for(int i=0; i<dc.size; i++){
			if(dc.files[i].name == srcname){
				fprintf(stdout, "really delete src?(Yes/No): ");
				cin >> buf;
				if(buf=="Yes"){
					command = INFO.module_root + "rmtree.pl " + src_path + (string)srcname;
					system(command.c_str());
					fprintf(stdout, "dsrc successful\n");
					return RET_SUCCECC;
				}else{
					fprintf(stderr, "dsrc cancelled\n");
					return RET_FAILED;
				}
			}
		
		}
		fprintf(stderr, "dsrc: src not found\n");
		return RET_FAILED;
	}


};



