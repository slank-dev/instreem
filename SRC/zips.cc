#include "head/instreem.h"


void zip_file(const char *s_path,const  char *s_name,const  char *d_path,const  char *d_name){
	char cmd[256];
	char root[256];
	char dest_fullpath_name[256];
	
	printf("source path     : %s \n", s_path);
	printf("source name     : %s \n", s_name);
	printf("destination path: %s \n", d_path);
	printf("destination name: %s \n", d_name);

	getcwd(root, sizeof(root));
	chdir(s_path);
	
	sprintf(cmd, "zip -r %s %s", d_name, s_name);
	sprintf(dest_fullpath_name, "%s%s", d_path, d_name);
	
	system(cmd);

	if(rename(d_name, dest_fullpath_name) == 0){
		printf("zip successful\n");
	}else{
		printf("zip error \n");
	}


	chdir(root);
}


void unzip_file(const char *s_path,const char *s_name,const char *d_path,const char *d_name){
	char cmd[256];
	char root[256];
	char dest_fullpath_name[256];
	
	printf("source path     : %s \n", s_path);
	printf("source name     : %s \n", s_name);
	printf("destination path: %s \n", d_path);
	printf("destination name: %s \n", d_name);


	getcwd(root, sizeof(root));
	chdir(s_path);

	sprintf(cmd, "unzip %s",s_name);
	sprintf(dest_fullpath_name, "%s%s", d_path, d_name);

	system(cmd);

	if(rename(d_name, dest_fullpath_name) == 0){
		printf("unzip successful\n");
	}else{
		printf("unzip error \n");
	}


	chdir(root);
}

