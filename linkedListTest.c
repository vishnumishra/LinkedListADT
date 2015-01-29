#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "expr_assert.h"

void test_createList_create_an_empty_linked_list(){
	LinkedList result;
	result = createList();

	assertEqual(result.count,0);
	assertEqual((int)result.head,0);
};
void test_createList_create_an_empty_linked_list_with_initial_element_is_0(){
	LinkedList result;
	result = createList();
	assertEqual(result.count,0);
	assertEqual((int)result.tail,0);
};

void test_create_node_creat_a_node_with_data(){
	Node *result;
	int data = 23;
	result = create_node(&data);
	assertEqual(23,*(int*)result->data);
	assertEqual((int)NULL,(int)result->next);
	free(result);
};

void test_create_node_creat_a_node_with_char_data(){
	Node *result;
	char data = 'a';
	result = create_node(&data);
	assertEqual('a',*(char*)(result->data));
	assertEqual((int)NULL,(int)result->next);
	free(result);
};

void test_create_node_creat_a_node_with_string_data(){
	Node *result;
	char* data = "bakri";
	result = create_node((void*)data);
	assertEqual(*(char*)"bakri",*(char*)result->data);
	assertEqual((int)NULL,(int)result->next);
	free(result);	
};

void test_create_node_creat_a_node_with_structure(){
	Node *result;
	
	Student *std1;
	std1 = malloc(sizeof(Student));
	std1->id = 1;
	std1->eng_score = 23;
	std1->name = "tiwari";
	result = create_node(std1);
	assertEqual(1,(*(Student*)(result->data)).id);
	assertEqual(23,(*(Student*)(result->data)).eng_score);
	assertEqual((int)NULL,(int)result->next);
	free(result);	
};

void test_create_node_creat_a_node_with_data_structure(){
	Node *result;
	Student *std1;
	std1 = malloc(sizeof(Student));
	std1->id = 1;
	std1->eng_score = 23;
	std1->name = "tiwari";
	result = create_node(std1);
	assert(!strcmp("tiwari",(*(Student*)(result->data)).name));
	assertEqual((int)NULL,(int)result->next);
	free(result);	
};

void test_add_to_list_add_element_into_the_list_return_1(){
	int result;
	LinkedList list;
	Node *n1;
	Student *std1 = malloc(sizeof(Student));
	std1->id = 2;
	std1->eng_score = 23;
	std1->name = "badOne";

	list = createList();

	n1 = create_node(std1);
	result = add_to_list(&list,n1);
	assertEqual(1,result);
};

void test_add_to_list_add_element_into_the_list_tail(){
	int result;
	LinkedList list;
	Node *n1;
	Student *std1 = malloc(sizeof(Student));
	std1->id = 2;
	std1->eng_score = 23;
	std1->name = "badOne";

	list = createList();

	n1 = create_node(std1);
	result = add_to_list(&list,n1);

	assertEqual((*(Student*)(list.tail)->data).id, 2);
	assertEqual((*(Student*)(list.tail)->data).eng_score,23);
};

void test_add_to_list_add_element_into_the_list_tail_(){
	int result;
	LinkedList list;
	Node *n1;
	Student *std1 = malloc(sizeof(Student));
	std1->id = 2;
	std1->eng_score = 23;
	std1->name = "badOne";
	list = createList();
	n1 = create_node(std1);
	result = add_to_list(&list,n1);
	assertEqual((*(Student*)(list.tail)->data).id, 2);
	assertEqual(strcmp((*(Student*)(list.tail)->data).name,"badOne"),0);
};

void test_add_to_list_add_element_into_the_list_tail_next_point_to_null(){
	int result1,result2,result3;
	LinkedList list;
	Node *n1,*n2,*n3;
	Student *std1 = malloc(sizeof(Student));
	Student *std2 = malloc(sizeof(Student));
	Student *std3 = malloc(sizeof(Student));

	std1->id = 2;
	std1->eng_score = 23;
	std1->name = "badOne";
	list = createList();
	
	std2->id = 3;
	std2->eng_score = 98;
	std2->name = "goodOne";

	std3->id = 4;
	std3->eng_score = 02;
	std3->name = "cheee...";

	n1 = create_node(std1);
	n2 = create_node(std2);
	n3 = create_node(std3);

	result1 = add_to_list(&list,n1);
	result2 = add_to_list(&list,n2);
	result3 = add_to_list(&list,n3);

	assertEqual((*(Student*)(list.tail)->data).id, 4);
	assertEqual((*(Student*)(list.tail)->data).eng_score, 2);

	assertEqual((int)((Node*)(list.tail))->next,0);
};

// void test_get_first_element_give_the_first_element_of_list(){
// 	LinkedList *result;

// }

