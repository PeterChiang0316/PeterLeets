#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

unsigned int hashFunc(unsigned int key)
{
    return ((key << 26) >>19) + 0xCAFE5566 %1343077;
}

void addToHashTable(hashNode* tbl, hashNode node, int tblSize)
{
  unsigned int index = hashFunc(node.key) % tblSize;
  hashNode* hptr= &tbl[index];
    if( !hptr->used )
    {
        *(hptr) = node;
    }
    else
    {
        while( hptr->next )
        {
            hptr = hptr->next;
        }
        hptr->next = (hashNode *) malloc( sizeof(hashNode) );
        hptr = hptr->next;
        (*hptr) = node;
    }
}


hashNode* findHash(hashNode* tbl, unsigned int key, int tblSize)
{
    unsigned int index = hashFunc(key) % tblSize;
    hashNode* hptr = &tbl[index];
    if (hptr->used)
    {

        if (hptr->key == key)
        {//hit
            return hptr;
        }
        else{
            while (hptr->next)
            {
                hptr = hptr->next;
                if (hptr->key == key) return hptr; //hit
            }
            return NULL;
        }
    }
    else{
        return NULL;
    }
    return NULL; //code shouldn't reach here anyway
}
