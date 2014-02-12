#include <stdio.h>
#include "functionalsafety.h"
#include <stdlib.h>

struct argumentlimit functionlimits[50];//pointer to the first argumentlimits for each function.
struct argumentlimit arg1;
struct argumentlimit arg2;
struct argumentlimit arg3;
struct argumentlimit arg4;

int tolargeerror = 0;
int tosmallerror = 0;
    
void init (int functionnumber){
    tolargeerror = 0;
    tosmallerror = 0;
    
    switch (functionnumber){
    case 0:
        //****** basicmath_small *************    
        arg1.minvalue = 1;
        arg1.maxvalue = 1000;
        arg1.next = &arg2;
         
        arg2.minvalue = 2;
        arg2.maxvalue = 2000;
        arg2.next = &arg3;
        
        arg3.minvalue = 3;
        arg3.maxvalue = 3000;
        arg3.next = &arg4;
        
        arg4.minvalue = 4;
        arg4.maxvalue = 4000;
        arg4.next = NULL;
        
        functionlimits[0] = arg1;
        //************************************
        break;
    default:
        printf("Undefined plausibility check for function %d.\n",functionnumber);
        exit(-1);
        break;
    }
}

void result(){
printf("\n======RESULTS=======\n");
printf("To small errors: %d\n", tosmallerror);
printf("To large errors: %d\n", tolargeerror);
printf("====================\n");
}

int functionalsafety(int (*function)(int,int,int,int), int functionnumber, int arg[]){
    struct argumentlimit arglimits = functionlimits[functionnumber];
    int i = 1;
    do{
        printf("%d < %d < %d\n",arglimits.minvalue, arg[i-1],arglimits.maxvalue);
        if (arg[i-1]<arglimits.minvalue){
            fprintf(stderr, "Argument %d for function number %d is to small.\n", i ,functionnumber);
            tosmallerror++;
        }
        if (arg[i-1]>arglimits.maxvalue){
            fprintf(stderr, "Argument %d for function number %d is to large.\n", i ,functionnumber);
            tolargeerror++;
        }
        i++;
        if (arglimits.next != NULL){
            arglimits = *arglimits.next;
            printf("Change to argument %d\n",i);
            }
        else{
            break;
        }
    }while(1);
    
    if (tosmallerror+tolargeerror > 0){
        return (-1);
    }
    return function(arg[0], arg[1], arg[2], arg[3]);
}
