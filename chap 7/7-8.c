#include<stdio.h>   
#include<stdlib.h>
#define PAGE 50 //after that starts with new page

void print_file(FILE *fp, char * filename);

int main(int argc, char *argv[])
{
    FILE *fp;
    if(argc == 1){
        fprintf(stderr, "usage: %s file1 file2 ...\n", argv[0]);
        exit(1);
    }
    for(int i=1; i< argc; i++){
        fp = fopen(argv[i], "r");
        if(fp == NULL){
            fprintf(stderr, " cant open %s\n", argv[i]);
            continue;
        }
        print_file(fp, argv[i]);
        fclose(fp);
    }
}

void print_file(FILE *fp, char * filename){
    int line_count = 0;
    int page=1;
    int c;
    printf("\n\n -- %s--- page %d -- \n\n", filename, page);
    while((c= fgetc(fp)) !=EOF){
        putchar(c);
        if(c == '\n'){
            line_count ++;
        } 
        if(line_count >= PAGE){
            page++ ;
            line_count=0;
            printf("\n\n -- %s--- page %d -- \n\n", filename, page);
        }
    }
}


