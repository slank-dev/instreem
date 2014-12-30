#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct _content{
	string name;
	int number;
	int type;
};

class dcont{
public:
	vector<struct _content> files;
	int size;
	
	void sort_by_number(){
		for(int i=0; i<files.size(); i++){
			for(int j=files.size()-1; j>i; j--){
				if(files[j-1].number > files[j].number)
					swap(files[j-1], files[j]);
			}
		}
	}
	void myls(const char* path){
		DIR *dir;
		if((dir = opendir(path))==NULL){
			perror("myls");
			return;
		}

		files.clear();
		struct _content buf_cont;
		for(struct dirent *dp=readdir(dir); dp!=NULL; dp=readdir(dir)){
			buf_cont.type = dp->d_type;
			buf_cont.name = dp->d_name;
			files.push_back(buf_cont);

			if(*(dp->d_name) == '.')
				files.back().type *= -1;
		}

		char buf_num_str[11];
		for(int i=0; i<files.size(); i++){
			strncpy(buf_num_str, files[i].name.c_str(), 10);
			files[i].number = atoi(buf_num_str);
		}


		sort_by_number();
		size = files.size();
	}

};


