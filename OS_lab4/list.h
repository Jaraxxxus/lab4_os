#define FIASCO -1
#define SUCCESS 0

struct node;
typedef struct node  Node;
struct list;
typedef struct list List;


Node* nodeInit();
void freeNode(Node* currentNode);
int addString(List* list, char* newLine);
void freememory(List* list);
void freeNode(Node* currentNode);
List* createList();
void printList(List* list);
