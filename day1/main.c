#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr = fopen("input.txt","r");
    if(fptr == NULL){
        perror("error opening input.txt");
        return (-1);
    }
    int bufferSize = 100;
    char str[bufferSize];
    int sum = 0;
    while(fgets(str,bufferSize,fptr)!=NULL){
        printf("\n%s",str);
        int a = -1; 
        int b = -1;
        for(int i = 0;i<strlen(str);i++){
            int ascii = (int)str[i];
//            printf("buffer %c %d",ascii,ascii);
            if(ascii <= 57 && ascii >= 48){
                if(a==-1){
                    a = ascii;
                }else{
                    b = ascii;
                }
//                printf("%c %i\n",str[i],i);
            }
        }
        if(a==-1 && b==-1){
            perror("did not see that coming");
            return (-1);
        }
        if(b==-1){
            sprintf(str,"%c%c",a,a);
            int val = atoi(str);
            sum+=val;
            //printf("atoi: %d", val);
            //printf("%c%c",a,a);

        }else{
            sprintf(str,"%c%c",a,b);
            int val = atoi(str);
            sum+=val;
            printf("adding: %d\n", val);
            //printf("%c%c",a,b);
        }
    }
    printf("%d",sum);
    return 0;
}