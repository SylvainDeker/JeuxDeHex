//
// Created by salimcherifi on 27/02/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>

int main(int argc, char *argv[]){
    struct stat Infos;
    if(argc == 1 ){
        struct dirent *InfosDir;
        DIR* dir = opendir(".");

        while((InfosDir=readdir(dir)) != NULL){
            if(stat(InfosDir->d_name,&Infos) == 0){
                printf("%-30s",InfosDir->d_name);
                if(S_ISDIR(Infos.st_mode) != 0){
                    printf("%-20s", " : repertoire");
                }else{
                    printf("%-20s", " : fichier");
                }
                printf("%8ld %-20s",Infos.st_size,"octets");
                printf("%-20s\n",ctime(&Infos.st_mtime));
            }else{
                perror("erreur stat");
                exit(1);
            }
        }
        if(closedir(dir) == -1){
            perror("close dir\n");
            exit(2);
        }
        return 0;
    }else{
        for (int i = 1; i < argc; i++) {
            if(stat(argv[i],&Infos) == 0){
                printf("%-30s",argv[i]);
                if(S_ISDIR(Infos.st_mode) != 0){
                    printf("%-20s", " : repertoire");
                }else{
                    printf("%-20s", " : fichier");
                }
                printf("%8ld %-20s",Infos.st_size,"octets");
                printf("%-20s\n",ctime(&Infos.st_mtime));
            }else{
                perror("erreur stat\n");
                exit(1);
            }
        }
        return 0;
    }



}
