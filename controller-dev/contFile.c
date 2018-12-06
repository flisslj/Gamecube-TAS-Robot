/**
* contFile.c
* Nick Gregerson, Senior Design MSOE
* 12/3/2018
*
*Purpose is to allow for the gathering of files to run and complete tases
*/
#include <stdio.h> 
#include <dirent.h> 

char* getFiles(char* basePath){
	char* files=malloc(300*sizeof(char));
	struct dirent *de;  // Pointer for directory entry 
  
  	// opendir() returns a pointer of DIR type.  
	DIR *dr = opendir(basePath); 
  
   	if (dr == NULL){ 
        	printf("Could not open current directory" ); 
        	return 0; 
    	} 
  	while ((de = readdir(dr)) != NULL){
		printf("%s\n", de->d_name);
		char* ext = strrchr(de->d_name, '.');
		if (strcmp(ext,".iso") == 0||strcmp(ext,".dtm") == 0){
			strcat(files,de->d_name);
			strcat(files,";");
		}
	}
  
    	closedir(dr);
    	return files; 
}

char* getISOS(char* basePath){
	char* files=malloc(300*sizeof(char));
	struct dirent *de;  // Pointer for directory entry 
  
  	// opendir() returns a pointer of DIR type.  
	DIR *dr = opendir(basePath); 
  
   	if (dr == NULL){ 
        	printf("Could not open current directory" ); 
        	return 0; 
    	} 
  	while ((de = readdir(dr)) != NULL){
		printf("%s\n", de->d_name);
		char* ext = strrchr(de->d_name, '.');
		if (strcmp(ext,".iso") == 0){
			strcat(files,de->d_name);
			strcat(files,";");
		}
	}
  
    	closedir(dr);
    	return files; 
}

char* getTASes(char* basePath){
	char* files=malloc(300*sizeof(char));
	struct dirent *de;  // Pointer for directory entry 
  
  	// opendir() returns a pointer of DIR type.  
	DIR *dr = opendir(basePath); 
  
   	if (dr == NULL){ 
        	printf("Could not open current directory" ); 
        	return 0; 
    	} 
  	while ((de = readdir(dr)) != NULL){
		printf("%s\n", de->d_name);
		char* ext = strrchr(de->d_name, '.');
		if (strcmp(ext,".iso") == 0||strcmp(ext,".dtm") == 0){
			strcat(files,de->d_name);
			strcat(files,";");
		}
	}
  
    	closedir(dr);
    	return files; 
}

uint64_t loadTAS(char* filename, uint8_t[] data){
}