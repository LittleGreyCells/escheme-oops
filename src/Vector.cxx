#include "Node.hxx"
#include "Vector.hxx"
#include "Port.hxx"
#include "Memory.hxx"

namespace scheme
{
   using Memory::nil;
   
   Vector::Vector( int length ) : length(length), data( new Node*[length] )
   {
      for ( int i = 0; i < length; ++i )
         data[i] = nil;
   }

   Vector::~Vector()
   {
      delete[] data;
      data = nullptr;
   }
   
   void Vector::range_check( int index )
   {
      if ( !(0 <= index && index < length) )
	 throw AccessException( "range constraint error");
   }

#if 0
   Node* Vector::vref( int index )
   {
      range_check( index );
      return data[index];
   }

   void Vector::vset( int index, Node* value )
   {
      range_check( index );
      data[index] = value;
   }
#endif

   unsigned Vector::vlen() { return length; }

   void Vector::mark() 
   {
      if ( !ismarked() )
      {
         setmark();
         for ( int i = 0; i < length; ++i )
            data[i]->mark();
      }
   }
   
   void Vector::print( Port* port, int style )
   {
      port->put( "#(" );
      for ( int i = 0; i < length; ++i )
      {
	 if ( i != 0 )
	    port->put( ' ' );
	 data[i]->print( port, style );
      }  
      port->put( ')' );
   }
   
}


