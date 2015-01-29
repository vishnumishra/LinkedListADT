typedef struct  node Node;
typedef struct  linkedList LinkedList;
typedef struct  node *node_ptr ;
typedef void (travFun)(void*data);
struct node {
	void* data;
    node_ptr next;
};

typedef struct student{
	int id;
	int eng_score;
    char* name;
	
}Student;

struct linkedList{
	node_ptr head;
	node_ptr tail;
	int count;
};

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);	
void *get_last_element(LinkedList list);
void traverse(LinkedList, travFun*);
