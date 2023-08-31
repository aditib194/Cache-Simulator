#include "lru.h"
#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

void lru_init_queue(Set *set) {
  LRUNode *s = NULL;
  LRUNode **pp = &s;  // place to chain in the next node
  for (int i = 0; i < set->line_count; i++) {
    Line *line = &set->lines[i];
    LRUNode *node = (LRUNode *)(malloc(sizeof(LRUNode)));
    node->line = line;
    node->next = NULL;
    (*pp) = node;
    pp = &((*pp)->next);
  }
  set->lru_queue = s;
}

void lru_init(Cache *cache) {
  Set *sets = cache->sets;
  for (int i = 0; i < cache->set_count; i++) {
    lru_init_queue(&sets[i]);
  }
}

void lru_destroy(Cache *cache) {
  Set *sets = cache->sets;
  for (int i = 0; i < cache->set_count; i++) {
    LRUNode *p = sets[i].lru_queue;
    LRUNode *n = p;
    while (p != NULL) {
      p = p->next;
      free(n);
      n = p;
    }
    sets[i].lru_queue = NULL;
  }
}

void lru_fetch(Set *set, unsigned int tag, LRUResult *result) {
  // TODO:
  // Implement the LRU algorithm to determine which line in
  // the cache should be accessed.
  //
  LRUNode *p = set->lru_queue;
  LRUNode *previous = NULL;
  while(p != NULL) {
    if(p->line->valid == 1 && p->line->tag == tag) {
      result->line = p->line;
      result->access = HIT;
      if(previous != NULL) {
        previous->next = p->next;
        p->next = set->lru_queue;
        set->lru_queue = p;
      }
      return;
    }
    previous = p;
    p = p->next;
  }
  p = set->lru_queue;
  previous = NULL;
  while(p != NULL) {
    if(p->line->valid == 0) {
      result->line = p->line;
      result->line->tag = tag;
      result->line->valid = 1;
      result->access = COLD_MISS;
      if(previous != NULL) {
        previous->next = p->next;
        p->next = set->lru_queue;
        set->lru_queue = p;
      }
      return;
    }
    previous = p;
    p = p->next;
  }
  p = set->lru_queue;
  previous = NULL;
  while(p->next != NULL) {
    p = p->next;
    previous = p;
  }
  result->line = p->line;
  result->access = CONFLICT_MISS;
  if(previous != NULL) {
        previous->next = p->next;
        p->next = NULL;
        set->lru_queue = p;
  }
  /*if(p->line->valid == 0) {
      result->line->tag = tag;
      result->line->valid = 1;
      result->access = COLD_MISS;
      return;
  }
  while(p->next != NULL) {
    if(p->line->valid == 0) {
      result->line->tag = tag;
      result->line->valid = 1;
      result->access = COLD_MISS;
      return;
    }
    p = p->next;
  }
  p = p->next;
  if(p->line->valid == 0) {
      result->line->tag = tag;
      result->line->valid = 1;
      result->access = COLD_MISS;
      return;
    }
  result->line = p->line;
  result->access = CONFLICT_MISS;*/
}
