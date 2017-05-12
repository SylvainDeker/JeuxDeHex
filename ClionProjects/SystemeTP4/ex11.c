#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int parcourir(const char *path){
    DIR *rep = opendir(path);
    struct dirent *file;
    struct stat pInfos;
    char str[512];
    long int total = 0;
    while((file = readdir(rep)) != NULL){

        if (strcmp(file->d_name, ".") && strcmp(file->d_name, "..")) {
            strcpy(str, path);
            strcat(str, "/");
            strcat(str, file->d_name);
            if(stat(str, &pInfos) == -1){
                perror(str);
                return 2;
            }

            if(S_ISDIR(pInfos.st_mode) != 0){

                printf("\n");
                total = 0;
                parcourir(str);

                printf("%-5s %-21s %8ld\n", "TOTAL :",file->d_name,total);
                printf("\n");
            }else{
                total+=pInfos.st_size;
                printf("%8ld\n",total );
                printf("%-30s",str);
                printf("%-21s %8ld\n",":",pInfos.st_size);
            }
        }
    }
    closedir(rep);
    return(0);
}

int main(int argc, char *argv[]){
    parcourir(".");

}
