#include "linkedList.h"
#include "expr_assert.h"

void test_createList_create_an_empty_linked_list(){
	LinkedList result;
	result = createList();

	assertEqual((int)result.head,0);
	assertEqual((int)result.tail,0);
	assertEqual(result.count,0);
};

