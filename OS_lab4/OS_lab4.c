// OS_LAB4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>   //for LINE_MAX

#define FIASCO -1
#define SUCCESS 0
#define LINE_MAX 512  //для отладки в виндоус, убрать позже
#define END_LINE '\n'

int main() {
	//char line[LINE_MAX];
	char* line = (char*)malloc(sizeof(char) * LINE_MAX);
	const char STOP_READ = '.';
	List* list = createList();
	int idx = 0;

	//выделим память
	if (list == NULL) {
		exit(FIASCO);
	}
	//текущий узел
	//currentNode = head;
	//считываем введенные строки
	printf("Enter lines of text. To end entering, put '.' in the start of line.\n");
	while (fgets(&line[idx], LINE_MAX, stdin) != NULL) {
		int ferr = ferror(stdin); //определение наличия ошибок потока данных
		if (ferr != SUCCESS) {
			perror("detection of data-flow errors");
			freememory(list);
			return FIASCO;
		}



		if (line[idx] == STOP_READ)
			break;
		int i;
		int breakLine = 0;

		for (i = idx; i < LINE_MAX + idx; i++)
		{
			if (line[i] == '\n')
			{
				line[i] = '\0';
				breakLine = 1;
				break;
			}
		}

		if (breakLine) {
			idx = 0;
		}
		else { //перевыделить память

			idx = (int)strnlen(line, idx + LINE_MAX);


			// Перевыделение памяти под строку
			//Эта функция может перемещать блок памяти на новое место,
			//в этом случае функция возвращает указатель на новое место в памяти.
			//Содержание блока памяти сохраняется даже если новый блок имеет
			//меньший размер, чем старый. Отбрасываются только те данные,
			//которые не вместились в новый блок.  Если новое значение size
			//больше старого, то содержимое вновь выделенной памяти будет неопределенным.
			char* tmp = (char*)realloc(line, sizeof(char) * (idx + LINE_MAX));
			if (tmp == NULL) {
				perror("Error on line realloc");
				return FIASCO;
			}
			line = tmp;
			continue;
		}




		if (addString(list, line) == FIASCO) {  //добавим строку в список
			freememory(list);
			break;
		}
	}


	//вывод на экран
	printf("List: \n");
	printList(list);
	//чистим память
	freememory(list);


	return SUCCESS;
}
