#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "lib/forum.h"
#include "lib/queue.h"

void lethread_info(struct LeThread *lethread) {
	printf("id=%llu author_id=%llu: %s\n", lethread->id, lethread->author_id, lethread->topic);
	printf("creator=%llu first_message_id=%llu next_message_id=%llu\n", lethread->author_id, lethread->first_message_id, lethread->next_message_id);
}

void lethread_message_history(struct LeThread *lethread) {
	struct QueueNode *node;
	struct LeMessage *message;
	
	node = lethread->messages->first;
	
	printf("==== History ====\n");
	while (node != NULL) {
		message = (struct LeMessage *)node->data;
		printf("#%llu: %s\n", message->author_id, message->text);
		node = node->next;
	}
	printf("=================\n");
}
 
int main() {
	struct stat st = {0};
	struct LeMessage *message;

	uint64_t lethread_id = rand_uint64_t() % 0xffffffff;
	struct LeThread *lethread = lethread_create("Test Topic", lethread_id);
	uint64_t author_id = 0;
	char *text = malloc(1024);
	size_t length = 1023;

	/* create dir if it doesn't exist */
	if (stat(".data/", &st) == -1) {
		mkdir(".data/", 0770);
	}

	for (size_t i = 0; i < 5; i++) {
		lethread_info(lethread);
		printf("author_id text:\n > ");
		
		scanf("%llu ", &author_id);
		getline(&text, &length, stdin);
		text[strlen(text) - 1] = 0;
		
		message = lemessage_create(lethread, author_id, text);
		lemessage_save(lethread, message);
		lethread_save(lethread);
		lethread_message_history(lethread);
	}

	puts("Done, saving to file, deleting object...");
	lethread_delete(lethread);

	puts("Trying to load the saved lethread...");

	lethread = (struct LeThread *)malloc(sizeof(struct LeThread));
	lethread_load(lethread, lethread_id);
	lemessages_load(lethread);
	lethread_info(lethread);
	lethread_message_history(lethread);
	lethread_delete(lethread);

	puts("Done!");

	return 0;
}