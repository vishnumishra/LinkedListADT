#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


LinkedList createList(void){
	LinkedList new_list;
	new_list.tail = NULL;
	new_list.head = NULL;
	new_list.count = 0;
	return new_list;
};

Node* create_node(void *data){
	Node *new_node = malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
};

int add_to_list(LinkedList *list,Node *n1){
	if(list->head == NULL){
		list->head = n1;
		list->tail = n1;
	}
	else{
		list->tail->next = n1;
		list->tail = n1;
	}
	list->count++;
	return 1;
};

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
};

void traverse(LinkedList list,travFun *fun){
	while(list.head != NULL){
		fun(list.head->data);
		list.head = list.head->next;
	}
};

void * getElementAt(LinkedList list,int index ){
	int i,count=0;
	node_ptr element = list.head;
	if(index > list.count-1) return NULL;
	while(count <= index ){
		if(count == index){
			return (element)->data;
		}
		element = (element)->next;
		count++;
	}
	return NULL;
}

int indexOf(LinkedList list, void * data){
	int i,index=0;
	node_ptr element = list.head;
	while(element != NULL){
		if(memcmp(element->data,data,sizeof(data))==0){
			return index;
		}
		element = (element)->next;
		index++;
	}
	return -1;
}

void * getNodeAt(LinkedList list,int index ){
	int i,count=0;
	node_ptr element = list.head;
	if(index > list.count-1) return NULL;
	while(count <= index ){
		if(count == index){
			return (element);
		}
		element = (element)->next;
		count++;
	}
	return NULL;
}

void *deleteHead(LinkedList *list,int index){
	Node *previous;
	previous = list->head;
	list->head = list->head->next;
	list->count--;
	return previous->data;
};

void*deleteTail(LinkedList *list,int index){
	Node *previous,*tailElement;
	previous = getNodeAt(*list, index-1);
	tailElement = list->tail;
	list->tail = previous;
	(list->tail)->next = NULL;
	list->count--;
	return tailElement;
};

void* deleteMiddle(LinkedList *list,int index){
	Node *previous,*next,*deleted = getNodeAt(*list, index);;
	previous = getNodeAt(*list,index-1);
	deleted = getNodeAt(*list, index);
	next = getNodeAt(*list,index+1);
	(previous)->next = next;
	list->count--;
	return deleted;
}

void * deleteElementAt(LinkedList *list,int index){
	Node *previous,*tailElement,*next;
	if(index > list->count && index < 0) return NULL;
	if(index ==0)return deleteHead(list, index);
	if(index == list->count-1)return deleteTail(list, index);
	return deleteMiddle(list,index);
};

int asArray(LinkedList list, void **array){
	int added=0,i;
	Node *element = list.head;
	for(i=0;i<list.count;i++){
		array[i] = (void*)element->data;
		added++;
		element = element->next;  
	}
	return added;
};

LinkedList * filter(LinkedList list, filterFun *fun){
	int i,res;
	LinkedList *resList = calloc(sizeof(LinkedList),1);
	Node *n1;
	
	for(i=0;i<list.count;i++){
		n1 = getNodeAt(list,i);
		res = fun(n1->data);
		if(res){
			add_to_list(resList,create_node(n1->data));
		}
	}
	return resList;
};


