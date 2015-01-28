typedef struct Node node;
typedef struct  linkedList LinkedList;
typedef struct Node *node_ptr;

struct Node {
	int* data;
    node_ptr *next;
};

struct linkedList{
	node_ptr head;
	node_ptr tail;
	int count;
};

LinkedList createList(void);