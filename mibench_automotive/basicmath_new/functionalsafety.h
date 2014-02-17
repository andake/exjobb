int functionalsafety(int (*function)(int,int,int,int), int limits, int arg[]);
void init(int functionnumber);
void result();

int tolargeerror;
int tosmallerror;

struct argumentlimit{
    int minvalue;
    int maxvalue;
    struct argumentlimit* next;
};
