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

LinkedList createListOf3(){
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
	LinkedList list = createListOf3();
	assertEqual((*(Student*)(list.tail)->data).id, 4);
	assertEqual((*(Student*)(list.tail)->data).eng_score, 2);
	assertEqual((int)((Node*)(list.tail))->next,0);
	free(list.head);
	free(list.tail);
};

void test_add_to_list_add_element_into_the_list_tail_count_shoul_be_the_number_of_element_(){
	LinkedList list = createListOf3();
	assertEqual(strcmp((*(Student*)(list.tail)->data).name, "cheee..."),0);
	assertEqual((list.count), 3);
	free(list.head);
	free(list.tail);
};

void test_get_first_element_give_the_first_element_of_list(){
	LinkedList list = createListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_first_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(data->eng_score,23);
	free(resultElement);
}


void test_get_first_element_give_the_first_element_of_list_string(){
	LinkedList list = createListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_first_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(strcmp(data->name,"badOne"),0);
	free(resultElement);
}

void test_get_last_element_give_the_last_element_of_list(){
	LinkedList list = createListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_last_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(data->eng_score,02);
	free(resultElement);

};

void test_get_first_element_give_the_last_element_of_list_string(){
	LinkedList list = createListOf3();
	Node *resultElement;
	Student *data;
	resultElement = (Node *)get_last_element(list);
	data = (Student *)(resultElement->data);
	assertEqual(strcmp(data->name,"cheee..."),0);
	free(resultElement);
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
	free(n1);
}
void changeString(void* data){
	char* name= "bakri" ;
	strcpy(data, name);
}

void test_traverse_element_traverse_through_all_element_of_list_and_change_string(){
	Node *n1,*n2;
	char name[] = "badOne";
	char name1[] = "cheee";
	Node *result1,*result2;

	LinkedList list = createList();
	n1 = create_node(name);
	add_to_list(&list,n1);
	n2 = create_node(name1);
	add_to_list(&list,n2);
	traverse(list,changeString);
	
	result1 = get_first_element(list);
	result2 = get_last_element(list);

	assertEqual(strcmp((char*)result1->data,"bakri"),0 );
	assertEqual(strcmp((char*)result2->data,"bakri"),0 );
}

void test_getElementAt_give_the_element_of_specific_place(){
	LinkedList list = createListOf3();
	Student *result =  (Student*)getElementAt(list, 0);
	assertEqual(result -> id, 2);
	assertEqual((result)->eng_score ,23);
	assertEqual(strcmp((result)->name,"badOne"),0);
	free(result);
}

void test_getElementAt_give_the_ele_of_specific_place(){
	LinkedList list = createListOf3();
	Student *result =  (Student*)getElementAt(list, 1);
	assertEqual(result -> id, 3);
	assertEqual((result)->eng_score ,98);
	assertEqual(strcmp((result)->name,"goodOne"),0);
	free(result);
}

void test_getElementAt_return_null_when_element_not_present(){
	LinkedList list = createListOf3();
	void *result =  getElementAt(list, 4);
	Student *s1 = (Student*)result;
	assertEqual((int)result ,(int) NULL);
	free(result);
}

void test_indexOf_return_indexOf_element_of_struct(){
	LinkedList list = createListOf3();
	Student *s2; 
	int index;
	s2 = creatStudent(4,02,"cheee...");
	index = indexOf(list,s2 );
	assertEqual(index,2);
};

void test_indexOf_return_indexOf_element(){
	Node *n1,*n2;
	int index,score1 = 5,score2=45;
	Node *result;
	
	LinkedList list = createList();
	n1 = create_node(&score1);
	add_to_list(&list,n1);
	n2 = create_node(&score2);
	add_to_list(&list,n2);

	index = indexOf(list, n2->data);
	assertEqual(index,1);
	free(n1);
	free(n2);
};

void test_deleteElementAt_delete_head_element(){
	LinkedList list = createListOf3();
	Node *n,*n1;
	n1 = deleteElementAt(&list,1);
	assertEqual(list.count,2);
	n = deleteElementAt(&list,1);
	assertEqual(list.count,1);
}

void test_deleteElementAt_delete_head_element_and_assign_next_element_to_head_1(){
	LinkedList list = createListOf3();
	Node *n1 ;
	Student *s1,*s2;

	s1 = getElementAt(list, 0);
	assertEqual((s1)->id, 2);

	n1 = deleteElementAt(&list,0);
	
	s2 = getElementAt(list, 0);
	assertEqual((s2)->id, 3);
	free(n1);
}

void test_deleteElementAt_delete_head_element_and_assign_next_element_to_head_2(){
	LinkedList list = createListOf3();
	Node *n1,*n2,*n3 ;

	n1 = getNodeAt(list, 1);
	assert((int)(n1)->next != (int)(NULL));

	n2 = deleteElementAt(&list,2);
	
	n3 = getNodeAt(list, 1);
	assert((n3)->next == NULL);
	free(n2);
};

void test_deleteElementAt_delete_head_element_and_assign_next_element_to_head_3(){
	LinkedList list = createListOf3();
	Node *n1 ;
	Student *s1,*s2;

	s1 = getElementAt(list, 0);
	assertEqual(strcmp((s1)->name,"badOne"),0);

	n1 = deleteElementAt(&list,0);
	
	s2 = getElementAt(list, 0);
	assertEqual(strcmp((s2)->name,"goodOne"),0);
	free(n1);
}

void test_deleteElementAt_delete_head_element_and_assign_next_element_to_tail_1(){
	LinkedList list = createListOf3();
	Node *n1,*n2,*n3 ;

	n1 = getNodeAt(list, 2);
	n3 = getNodeAt(list, 1);
	assert((int)(n1)->next == (int)(NULL));
	assert((n3)->next != (NULL));
	n2 = deleteElementAt(&list,2);
	assert((n3)->next == NULL);
	free(n3);
};

void test_deleteElementAt_delete_head_element_and_assign_next_element_to_tail_2(){
	LinkedList list = createListOf3();
	Node *n1 = deleteElementAt(&list,2);
	assertEqual(list.count, 2);
	free(n1);
};

void test_deleteElementAt_delete_head_element_and_assign_next_element_1(){
	LinkedList list = createListOf3();
	Node *n1 ;
	Student *s1,*s2;

	s1 = getElementAt(list, 1);
	assertEqual((s1)->id, 3);

	n1 = deleteElementAt(&list,0);
	
	s2 = getElementAt(list, 1);
	assertEqual((s2)->id, 4);
	free(n1);
}

void test_deleteElementAt_delete_head_element_and_assign_next_element_2(){
	LinkedList list = createListOf3();
	Node *n1 ;
	Student *s1,*s2;

	s1 = getElementAt(list, 1);
	assertEqual((s1)->eng_score, 98);

	n1 = deleteElementAt(&list,0);
	
	s2 = getElementAt(list, 1);
	assertEqual((s2)->eng_score, 2);
	free(n1);
};

void test_deleteElementAt_delete_head_element_and_assign_next_element_3(){
	LinkedList list = createListOf3();
	Node *n1 ;
	Student *s1,*s2;

	s1 = getElementAt(list, 1);
	assertEqual(strcmp((s1)->name,"goodOne"),0);

	n1 = deleteElementAt(&list,1);
	
	s2 = getElementAt(list, 1);
	assertEqual(strcmp((s2)->name,"cheee..."),0);
	free(n1);
}

void test_deleteElementAt_delete_head_element_and_assign_next_element_int(){
	LinkedList list = createList();
	int score1 =2,*s1 ,score2 =5,score3 = 45;
	Node *n1,*n2,*n3,*n4;

	n1 = create_node(&score1);
	add_to_list(&list,n1);
	n2 = create_node(&score2);
	add_to_list(&list,n2);
	n3 = create_node(&score3);
	add_to_list(&list,n3);

	s1 = getElementAt(list,1);
	assertEqual(*(int*)s1,5);
	
	n4 = deleteElementAt(&list,1);
	s1 = getElementAt(list,1);
	assertEqual(*(int*)s1,45);
}

void test_deleteElementAt_delete_head_element_and_assign_next_element_float(){
	LinkedList list = createList();
	float score1 =2.25,*s1 ,score2 =5.75,score3 = 45.50;
	Node *n1,*n2,*n3,*n4;

	n1 = create_node(&score1);
	add_to_list(&list,n1);
	n2 = create_node(&score2);
	add_to_list(&list,n2);
	n3 = create_node(&score3);
	add_to_list(&list,n3);

	s1 = getElementAt(list,1);
	assert(*(float*)s1 == 5.75);
	
	n4 = deleteElementAt(&list,1);
	s1 = getElementAt(list,1);
	assert(*(float*)s1 == 45.50);
}

void test_asArray_populate_array_with_list_element_1(){
	void *array[5]; 
	int result;
	LinkedList list = createListOf3();
	result = asArray(list,(void**)&array);
	assertEqual(result,3);
};

void test_asArray_populate_array_with_list_element_2(){
	int *data[5];
	int data1=1,data2=2,result;
	LinkedList list = createList(); 
	add_to_list(&list,create_node(&data1));
	add_to_list(&list,create_node(&data2));

	result = asArray(list,(void**)&data);
	assertEqual(*(data[0]),1);
	assertEqual(*(data[1]),2);
};

void test_asArray_populate_array_with_list_element_3(){
	int *array[5]; 
	int result,id;
	Student *s1;
	LinkedList list = createListOf3();
	result = asArray(list,(void**)&array);
	assertEqual(((Student*)(array[0]))->id,2 );
	assertEqual(((Student*)(array[1]))->id,3 );
	assertEqual(((Student*)(array[2]))->id,4 );
};


void test_asArray_populate_array_with_list_element_4(){
	int *array[5]; 
	int result,id;
	Student *s1;
	LinkedList list = createListOf3();
	result = asArray(list,(void**)&array);
	assertEqual(((Student*)(array[0]))->eng_score,23 );
	assertEqual(((Student*)(array[1]))->eng_score,98);
	assertEqual(((Student*)(array[2]))->eng_score,2);
};

void test_asArray_populate_array_with_list_element_5(){
	int *array[5]; 
	int result,id;
	Student *s1;
	LinkedList list = createListOf3();
	result = asArray(list,(void**)&array);
	assertEqual(strcmp(((Student*)(array[0]))->name,"badOne"),0 );
	assertEqual(strcmp(((Student*)(array[1]))->name,"goodOne"),0 );
	assertEqual(strcmp(((Student*)(array[2]))->name,"cheee..."),0 );
};

int isEven(void* data){
	return *(int*)data%2==0;
}

void test_filter_filter_the_element_of_list_1(){
	int data1=1,data2=32,data3=23,data4=56;
	LinkedList list = createList(),*result; 
	add_to_list(&list,create_node(&data1));
	add_to_list(&list,create_node(&data2));
	add_to_list(&list,create_node(&data3));
	add_to_list(&list,create_node(&data4));
	result = filter(list,isEven);
	assertEqual(*(int*)getElementAt(*result,0), 32);
	assertEqual(*(int*)getElementAt(*result,1), 56);

};






