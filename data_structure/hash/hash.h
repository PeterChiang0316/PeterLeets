//hash in C for Reference 

typedef struct node{
   char used;
   int key;
   int value;
   struct node* next;
}hashNode; 
// just a dummy type, user can replace their own node, just need to have key element ( used for hash function )


unsigned int hashFunc(unsigned int key);
void addToHashTable(hashNode* tbl, hashNode node, int tblSize);
hashNode* findHash(hashNode* tbl, unsigned int key, int tblSize);

