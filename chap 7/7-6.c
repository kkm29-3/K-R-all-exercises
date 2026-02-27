#include<stdio.h>    
#include<string.h>
#include<stdlib.h>
#define MAXLINE 100
#define PAGE 50
int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];
    int linemo=1;

    if(argc !=3){
        printf("usage: %s file1 file 2\n", argv[0]);
        return 1;
    }
        fp1= fopen(argv[1], "r");
        fp2= fopen(argv[2], "r");

    if(fp1 == NULL || fp2== NULL){
    printf("ERROR");
    return 1;
    }

    while(1){
        char *p1 = fgets(line1, MAXLINE, fp1);
        
        char *p2 = fgets(line2, MAXLINE, fp2);
        
        //both files ended
        if(p1 == NULL && p2 == NULL){
            printf("files are not identical");
            break;
        }

        //one file ended or linear differ
        else if(p1 == NULL || p2 == NULL || strcmp(line1, line2) !=0)
        {
            printf("files differ at line %d\n", linemo);
            printf("files1 : %s", p1? line1: "EOF\n");
            printf("%s", p1 );
            printf("files2 : %s", p2? line2: "EOF\n");
            printf("%s", p2);
        }
    }
    linemo++ ;
    fclose(fp1);
    fclose(fp2);
    
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