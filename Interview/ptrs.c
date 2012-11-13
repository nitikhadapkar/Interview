struct car
{
 char color;
 int speed;
  void (*change_gears)(struct car *);
};

struct ford {
  int foo;  
  struct car base;
  int ford_serial_number;
};


int size( struct car * c ) { return c->size; }
void change_gears( struct car * c ) {
  c->change_gears(c);
}


struct car *
make_ford() {
  struct ford * f = (struct ford *) malloc( sizeof( struct ford ));
  car_init( &f->base );
  f->base.change_gears = ford_change_gears;
  f->ford_serial_number = next_ford_serial_number++;
}  


static void
ford_change_gears( struct car * c ) {
   int serial_number = c->ford_serial_number; // does not compile
   int serial_number = * (int *) (c + 1); // works but very sensitive to layout
   struct ford * f = (struct ford *) ((char *) c - (int) & (((struct ford *) 0)->base) );
   if( serial_number < 5000 ) { ... } else { ... }
}

