#define MAX_LIST_SIZE 10
#define MAX_NAME_LENGTH 10
void addName(void);
void fulfill(void);
void list(void);
void smallerThan(int);

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
extern customer customers[MAX_LIST_SIZE];