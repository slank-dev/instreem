#include <cstdio>	//stdio.h
#include <cstring>	//string.h
#include <cstdlib>	//stdlib.h
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#define RET_SUCCECC  0
#define RET_FAILED	-1

using namespace std;

//main functions prottpe
int shell();
int run_command(int margc, vector<string> margv);

//sub functions prottpe
bool project_exist(const char* project_name);





//class
class Project{
private:
	string name;
	string pjct_path;
	string src_path;
	string edit_path;
	unsigned int pjct_number;
public:

	Project(string pname="test"){
		cout << "constracter of ProjectClass" << endl;
		name = pname;
		pjct_number = 10;
	}

	void info(){
		cout << "name: " << name << endl;
		cout << "num : " << pjct_number << endl;
	}

};


class instreem_info{
private:
	string _project_root;
	string _document_root;
	string _module_root;
public:

	instreem_info(){
		string path = getenv("HOME");
		path += "/.instreemrc";
		FILE *fp;
		char line_buf[256];

		if((fp = fopen(path.c_str(), "r") )==NULL){
			perror("instreemrc open error");
		}else{
			for(char c=fgetc(fp); c!=EOF; c=fgetc(fp)){
				memset(line_buf, 0, sizeof(line_buf));
				for(int i=0; c!='\n'; c=fgetc(fp), i++){
					line_buf[i] = c; 
				}
				
				//scan PROJECT_ROOT
				if(strncmp(line_buf, "PROJECT_ROOT", strlen("PROJECT_ROOT")) == 0){
					_project_root = (line_buf+strlen("PROJECT_ROOT")+1);
				}
				

				//scan DOCUMENT_ROOT
				if(strncmp(line_buf, "DOCUMENT_ROOT", strlen("DOCUMENT_ROOT")) == 0){
					_document_root = (line_buf+strlen("DOCUMENT_ROOT")+1);
				}

				//scan MODULE_ROOT
				if(strncmp(line_buf, "MODULE_ROOT", strlen("MODULE_ROOT")) == 0){
					_module_root = (line_buf+strlen("MODULE_ROOT")+1);
				}

			}


		}//end else

		
	}





	string project_root(){
		return _project_root;
	}
	string document_root(){
		return _document_root;
	}
	string module_root(){
		return _module_root;
	}
};



