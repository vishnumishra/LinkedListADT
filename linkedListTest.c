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

Student *creatStudent(int id,int eng_score,char* name){
	Student *std = malloc(sizeof(Student));
	std->id = id;
	std->eng_score = eng_score;
	std->name = name;
	return std;
}

LinkedList creatListOf3(){
	Node *n1,*n2,*n3;
	LinkedList list = createList();
	Student *std1,*std2,*std3;

	std1 = creatStudent(2,23,"badOne");
	std2 = creatStudent(3,98,"goodOne");
	std3 = creatStudent(4,02,"cheee...");

	n1 = create_node(std1);
	n2 = create_node(std2);
	n3 = create_node(std3);

	add_to_list(&list,n1);
	add_to_list(&list,n2);
	add_to_list(&list,n3);
	return list;
};

void test_add_to_list_add_element_into_the_list_tail_next_point_to_null(){
	int result1,result2,result3;
	LinkedList list;
	list = creatListOf3();
	assertEqual((*(Student*)(list.tail)->data).id, 4);
	assertEqual((*(Student*)(list.tail)->data).eng_score, 2);
	assertEqual((int)((Node*)(list.tail))->next,0);
	free(list.head);
	free(list.tail);
};

void test_add_to_list_add_element_into_the_list_tail_count_shoul_be_the_number_of_element_(){
	LinkedList list = creatListOf3();
	assertEqual(strcmp((*(Student*)(list.tail)->data).name, "cheee..."),0);
	assertEqual((list.count), 3);
	free(list.head);
	free(list.tail);
};

void test_get_first_element_give_the_first_element_of_list(){
	LinkedList list = creatListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_first_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(data->eng_score,23);
}

void test_get_first_element_give_the_first_element_of_list_string(){
	LinkedList list = creatListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_first_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(strcmp(data->name,"badOne"),0);
}

void test_get_last_element_give_the_last_element_of_list(){
	LinkedList list = creatListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_last_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(data->eng_score,02);
};

void test_get_first_element_give_the_last_element_of_list_string(){
	LinkedList list = creatListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_last_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(strcmp(data->name,"cheee..."),0);
}

void incrementOne(void* data){
	*(int*)data = (*(int*)data)+1;
}

void test_traverse_element_traverse_through_all_element_of_list(){
	Node *n1;
	int score = 5;
	Node *result;
	
	LinkedList list = createList();
	n1 = create_node(&score);
	add_to_list(&list,n1);
	traverse(list,incrementOne);
	result = get_first_element(list);
	assertEqual(*(int*)result->data,6 );
}
void changeString(void* data){
	char* name= "bakri" ;
	strcpy(data, name);
}

void test_traverse_element_traverse_through_all_element_of_list_and_change_string(){
	Node *n1;
	char name[] = "badOne";
	Node *result;

	LinkedList list = createList();
	n1 = create_node(name);
	add_to_list(&list,n1);
	traverse(list,changeString);
	
	result = get_first_element(list);
	assertEqual(strcmp((char*)result->data,"bakri"),0 );
}



