struct Node
{
      void *data; //holds data
      struct Node *next;
};

struct stackPointer
{
      struct Node *head;
      int size;
};

int push(struct stackPointer *const sp, const void *data){

      struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

      if(newNode == NULL)  //malloc fails
      {
         return -1;
      }

      newNode->data = (void *) malloc(sp->size);

      if(memcpy(newNode->data, data, sp->size) == NULL)
         return -1;

      newNode->next = sp->head;
      sp->head = newNode;

      return 0;
}

int pop( struct stackPointer *const sp, void *ptr) {

   if(ptr == NULL)
     return -1;


}
int createStack(struct stackPointer **sp, int size);

int main()
{
   return 0;
}
int createStack(struct stackPointer **sp, int size)
{
      if(*sp != NULL)
         return -1;

      *sp = (struct stackPointer *) malloc(sizeof(struct stackPointer));
      (*sp)->size = size;
      (*sp)->head = NULL;
      return 0;
}

foo( struct stackPointer * s ){
   int a = 3;
   push( s, &a );
}

main() {
   struct stackPointer *s;
   createStack( &s, sizeof( int ) );
   foo( s);
   int p;
   p = (int * ) pop( s, &p );
   assert( 3 == *p );
}

