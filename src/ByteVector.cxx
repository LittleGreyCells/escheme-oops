#include "Node.hxx"
#include "ByteVector.hxx"
#include "Port.hxx"

namespace scheme
{
   ByteVector::~ByteVector()
   {
      length = 0;
      delete[] data;
      data = nullptr;
   }

   ByteVector::ByteVector( int length ) : length(length), data( new byte[length] )
   {
      for ( int i = 0; i < length; ++i )
         data[i] = 0;
   }
      
   void ByteVector::print( Port* port, int )
   {
      port->put( id("ByteVector") );
   }
   
}


