#include<stdio.h>
#include<stdlib.h>
#include "../../data_structure/linkedList/linkedList.h"


ListNode* add_two_numbers(ListNode *a, ListNode *b);
ListNode* add_two_numbers_optimized(ListNode *a, ListNode *b);
ListNode* add_two_numbers_optimized_2(ListNode *a, ListNode *b);

int main (int argc, char *argv[]){
    ListNode *a ,*b, *c,*d,*e;
    int i,j,r;
    srand(time(NULL));
    
    a = (ListNode *) malloc ( sizeof (ListNode) );
    b = (ListNode *) malloc ( sizeof (ListNode) );
    
    d = a;
    e = b;
    r = rand()%10;
    printf("r: %d\n",r);
    for ( i = 0 ; i < r ; i ++ ){
        j = rand()%10;
        d->val = j;
        if ( i < r-1 ){
            d->next = (ListNode *)malloc( sizeof(ListNode));
            d = d->next;
        }
    }

    r = rand()%10;

    printf("r: %d\n",r);
    for ( i = 0 ; i < r ; i ++ ){
        j = rand()%10;
        e->val = j;
        if ( i < r-1 ) {
            e->next = (ListNode *)malloc( sizeof(ListNode));
            e = e->next;
        }
    }

    d = a; e = b;

    while (d) {
        printf("%d ",d->val);
        d = d->next;
    }
    printf("\n");
    while (e) {
        printf("%d ",e->val);
        e = e->next;
    }
    printf("\n");
    c = add_two_numbers_optimized_2(a,b);

   

    while (c) {
        printf("%d ", c->val);
        c = c->next;
    }

    printf("\n");

    return 0;
}


ListNode* add_two_numbers_optimized_2(ListNode *a, ListNode *b)
{
    ListNode dummy;
    ListNode *dummyPtr;
    unsigned int carry = 0;
    unsigned int sum = 0;
    
    dummy.val = 0;
    dummy.next = NULL;
    dummyPtr = &dummy;

    while ( a || b || carry)
    {
        sum = 0;
        if (a) sum += a->val;
        if (b) sum += b->val;
        if (carry) sum += carry;

        dummyPtr->next = (ListNode *) malloc(sizeof(ListNode));
        dummyPtr = dummyPtr->next;
        dummyPtr->val = sum%10;
        carry = (sum > 9)? 1 : 0;

        if(a) a = a->next;
        if(b) b = b->next;
    }
    dummyPtr->next = NULL;
    return dummy.next;
}

// make a dummy list head to make the algorithm more readible

ListNode* add_two_numbers_optimized(ListNode *a, ListNode *b)
{
    unsigned int carry = 0;
    unsigned int sum = 0;
    ListNode dummy_a;
    ListNode dummy_b;
    ListNode *ret;
    unsigned int i = 0;
    dummy_a.val = 0;
    dummy_b.val = 0;
    dummy_a.next = a;
    dummy_b.next = b;
    a = &dummy_a;
    b = &dummy_b;
    ret = a;


    while (a || b || carry)
    {
        sum = 0;
        if (a) sum += a->val;
        if (b) sum += b->val;
        if (carry) sum+=carry;
        if ( sum > 9 )
        {
            carry = 1;
            a->val = sum % 10;
        }
        else 
        {
            carry = 0;
            a->val = sum;
        }
        printf("round:%d:\nsum = %d\ncarry=%d\n",i+1,sum,carry);   
        
        if ( !a->next && (b->next || carry) ) {
            a->next = (ListNode*)malloc(sizeof(ListNode));
        }
        if ( a ) a = a->next;
        if ( b ) b = b->next;

        i++;
        if (i > 10) break;
    }
    return ret->next;
}



ListNode* add_two_numbers(ListNode *a, ListNode *b){
    unsigned int carry = 0;
    unsigned int lc =0;
    ListNode* c;
    ListNode* d = NULL;
    d = (ListNode *)malloc (sizeof(ListNode)); //list head
    c = d;
    c->next = NULL;

    while(a){
        if (b){
            c->val = a->val + b->val + carry;
            if ( c->val > 9 ){
                carry = 1;
                c->val %= 10;
            }    
            else carry = 0; 
            
            if (a->next){
                c->next = (ListNode *)malloc(sizeof(ListNode));
                c = c->next;
                c->next = NULL;
             }
            else c->next = NULL;

            a = a->next;
            b = b->next;
        }

        else{
            while(a){
                c->val = carry + a->val;
                if(c->val > 9){
                    carry = 1;
                    c->val %= 10;
                }
                else carry = 0;
                if( a->next ){
                    c->next = (ListNode *)malloc(sizeof(ListNode));
                    c = c->next;
                    c->next = NULL;
                }
                a = a->next;
            }
            break;
        }
    }

    while(b){
       c->next = (ListNode *)malloc(sizeof(ListNode));
       c = c->next;
       c->next = NULL;
       c->val = carry + b->val;
       if ( c->val > 9 ){
            carry = 1;
            c->val %= 10;
       }
       else carry = 0;

       b = b->next;
    }


    if (carry){
        c->next = (ListNode *)malloc(sizeof(ListNode));
        c = c->next;
        c->val = carry;
        c->next = NULL;
    }
    

    /*do{
        if ( a && b ){
            c->val = a->val + b->val + carry;
            if ( c->val > 9 ){
                carry = c->val / 10;
                c->val %= 10;
            }
            else carry = 0; // carry is done, put it to zero;
            printf("both a and b have digits\n");
            printf("a:%d\nb:%d\nc:%d\ncarry:%d\n",a->val,b->val,c->val,carry);

            if ( a->next || b->next ) {
                printf("allocate c's next because either a or b has next digit\n");
                c->next = (ListNode *)malloc(sizeof(ListNode));
                c = c->next;
            }
            else c->next = NULL;
            a = a->next;
            b = b->next;
        }

        else if ( a ) {
            printf("only a has digit\n");
            do{
                c->val = a->val + carry;
                if ( c->val > 9 ){
                    carry = c->val / 10;
                    c->val %= 10;
                }
                else carry = 0; // carry is done, put it to zero;
                
                printf("a:%d\nc:%d\ncarry:%d\n",a->val,c->val,carry);
                if( a->next) c->next = (ListNode *)malloc(sizeof(ListNode));
                else c->next = NULL;
                c = c->next;
                a = a->next;
            }while ( a );
        }

        else if ( b ) {
            printf("only b has digit\n");
            do{
               c->val = b->val + carry;
               if ( c->val > 9 ){
                   carry = c->val / 10;
                   c->val %= 10;
               }
               else carry = 0;
               
               printf("b:%d\nc:%d\ncarry:%d\n",b->val,c->val,carry);
               if( b->next) c->next = (ListNode *)malloc(sizeof(ListNode));
               else c->next = NULL;
               c = c->next;
               b = b->next;
            }while( b );
            
        }

        else break;


        lc ++;

        if ( lc > 15 ){
            printf("infinite loop happened\n");
            break;
        }
    } while ( a || b );

    c = d;
    if ( carry ){
        while (c->next) c = c->next;
        c->next = (ListNode *)malloc(sizeof(ListNode));
        c = c->next;
        c->val = carry;
        c->next = NULL;
    }
*/
    return d;

}


