// int isEven(void* data){
// 	return *(int*)data%2==0;
// }

// void test_filter_filter_the_element_of_list_1(){
// 	int data1=1,data2=23,data3=32;
// 	LinkedList list = createList(),*result; 
// 	add_to_list(&list,create_node(&data1));
// 	add_to_list(&list,create_node(&data2));

// 	result = filter(list,isEven);
// 	// printf("%d\n", (int)result->head->data); 
// };



// LinkedList * filter(LinkedList list, filterFun *fun){
// 	int i,res;
// 	LinkedList *resList;
// 	Node *n1;
// 	*resList = createList();
// 	for(i=0;i<list.count;i++){
// 		printf(">>>>>>>>>>%d\n",data);
// 		n1 = getNodeAt(list,i);
// 		res = fun((n1)->data);
// 		if(res){
// 			// add_to_list(resList,create_node(&n1->data));
// 		}
// 		free(n1);
// 	}
// 	return resList;
// };
