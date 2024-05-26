#include "udt.h"
#include <stdlib.h>
#include <stdio.h>

// Создание очереди - O(1) - константная
udt* udt_create(int capacity) {
	udt* queue = (udt*)malloc(sizeof(udt));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->data = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// Проверка очереди на пустоту - O(1) - константная
bool udt_is_empty(const udt *queue) {
	return (queue->size == 0);
}

// Добавление элемента в очередь - O(1) - константная
void udt_push(udt *queue, int item) {
	if (queue->size == queue->capacity) return;
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->data[queue->rear] = item;
	queue->size = queue->size + 1;
}

// Удаление элемента из очереди - O(1) - константная
void udt_pop(udt *queue) {
	if (udt_is_empty(queue)) return;
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size = queue->size - 1;
}

// Получение элемента из начала очереди - O(1) - константная
int udt_get(const udt* queue) {
	return queue->data[queue->front];
}

// Печать очереди - O(n) - линейная
void udt_print(const udt* queue) {
	int i;
	for (i = 0; i < queue->size; i++) {
		printf("%d ", queue->data[i]);
	}
	printf("\n");
}

// Получение размера очереди - O(1) - константная
int udt_size(const udt *queue) {
	return queue->size;
}

// Удаление очереди - O(1) - константная
void udt_destroy(udt* queue) {
    free(queue->data);
    free(queue);
}

// Вставка элемента в очередь в порядке возрастания - O(n) - линейная
void udt_insert_in_order(udt *queue, int item) {
    if (udt_is_empty(queue)) {
        udt_push(queue, item);
        return;
    }

    int i, j;
    for (i = 0; i < queue->size; i++) {
        if (queue->data[i] > item) {
            for (j = queue->size; j > i; j--) {
                queue->data[j] = queue->data[j-1];
            }
            queue->data[i] = item;
            queue->size++;
            break;
        }
    }

    if (i == queue->size) {
        udt_push(queue, item);
    }
}

// Сортировка очереди методом вставок - O(n^2) - квадратичная for and for in udt_insert_in_order
void udt_insertion_sort(udt *queue) {
    int size = udt_size(queue);
    udt* sorted_queue = udt_create(size);

    for (int i = 0; i < size; i++) {
        int item = udt_get(queue);
        udt_pop(queue);
        udt_insert_in_order(sorted_queue, item);
    }

    for (int i = 0; i < size; i++) {
        int item = udt_get(sorted_queue);
        udt_pop(sorted_queue);
        udt_push(queue, item);
    }

    udt_destroy(sorted_queue);
}