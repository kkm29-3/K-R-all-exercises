#include<stdio.h>
#include<ctype.h>
#define MAXLEN 500

int getline (char line[], unsigned int max_len);
double atof(char s[]);

int main(){
    char line[MAXLEN];
    getline(line, MAXLEN);
    printf("%s", line);
    printf("%.8f",atof(line));
}

int getline(char line[],unsigned int max_len){

    unsigned int i=0;
    int c;

    while (i<max_len-1 && (c= getchar())!='\n' && c!=EOF){

        line[i]=c;
        ++i;
    }

    if(c=='\n'){
        line[i++]=c;

    }
    line[i]='\0';
    return i;
}

double atof(char s[]){
    double val,power;
    int i,sign;
    int exp_sign= 1;
    int exp_pwr= 0;

    for(i=0;isspace((unsigned char)s[i]);++i)
    ;
    sign = (s[i]=='-')?-1:1;
    if(s[i]=='+' || s[i]== '-'){
        ++i;
    }
    for (val = 0.0; isdigit ((unsigned char)s[i]); ++i){
        val = 10.0 * val + (s[i]-'0');
    }
    if (s[i]=='.'){
        ++i;
    }

    for (power=1.0; isdigit((unsigned char)s[i]);++i){
        val= 10.0*val+ (s[i]-'0');
        power*=10.0;
    }

    //e or E condition
    if(s[i]=='e' || s[i]=='E'){
        ++i;
        if(s[i]=='-'){
            exp_sign= -1;
            ++i;
        }
        else if(s[i]=='+'){
            ++i;
        }

        while(isdigit((unsigned char)s[i])){
            exp_pwr = 10* exp_pwr + s[i]-'0';
            ++i;
        }

        while(exp_pwr>0){
            if(exp_sign==-1){
                power*=10.0;
            }
            else{
                power/=10.0;
            }
            --exp_pwr;
        }

    }
    return sign*val/power;
}
