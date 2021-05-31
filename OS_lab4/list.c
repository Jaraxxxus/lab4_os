#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>




struct node {
	char* value;  //строка
	Node* next; //сосед
};

struct list {
	Node* head;
	Node* tail;
};



Node* nodeInit() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		perror("can`t create node");
		return NULL;
	}
	head->next = NULL;
	head->value = NULL;

	return head;
}

void freeNode(Node* currentNode) {
	free(currentNode->value);
	free(currentNode);
}

List* createList() {
	List* newList = (List*)malloc(sizeof(List));
	if (newList == NULL) {
		perror("List creation error");
		return NULL;
	}
	newList->head = NULL;
	newList->tail = NULL;
	return newList;
}


int addString(List *list, char* newLine) {
	Node* newNode = NULL;
	if (list == NULL) {
		perror(" List is NULL");
		return FIASCO;
	}

	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		perror("can`t create newNode");
		return FIASCO;
	}

	newNode->value = (char*)malloc((strlen(newLine) + 1) * sizeof(char));

	if (newNode->value == NULL) {
		perror("can`t create newNode->value");
		return FIASCO;
	}

	//strcpy(newNode->value, newLine);
	strncpy(newNode->value, newLine, strlen(newLine) + 1);
	//strcpy_s(newNode->value, strlen(newLine) + 1, newLine);
	newNode->next = NULL;
	if (list->head == NULL) {
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		list->tail->next = newNode;
		list->tail = newNode;
	}
	return(SUCCESS);
}

void freememory(List* list) {
	if (list == NULL) {
		return;
	}
	Node* nxtNode = NULL;
	if (list->head == NULL) {
		free(list);
		return;
	}
	Node* curNode = list->head->next;
	while (curNode != NULL) {
		nxtNode = curNode->next;
		freeNode(curNode);
		curNode = nxtNode;
	}
	free(list->head);
	free(list);
}

void printList(List* list) {
	if (list == NULL) return;
	Node* i = list->head;
	for (Node* i = list->head; i != NULL; i = i->next) {
		puts(i->value);
	}
	
	
}