#define MAX_LIST_SIZE 10
#define MAX_NAME_LENGTH 10
typedef union confnum{
char phone[10];
int ordernum;
}CONFNUM;

typedef struct customer {
char name[MAX_NAME_LENGTH];
int size;
CONFNUM confirm;
int type;
}customer;
extern customer *customers;



void addName(int, struct customer *);
void fulfill(int, struct customer *);
void list(int, struct customer *);
void smallerThan(int, int, struct customer *);
int reSize(int, int, struct customer *);
