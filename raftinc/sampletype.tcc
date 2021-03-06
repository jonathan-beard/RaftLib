/**
 * sampletype.tcc - 
 * @author: Jonathan Beard
 * @version: Sat 11 July 2020
 * 
 * Copyright 2020 Jonathan Beard
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef RAFTSAMPLETYPE_TCC
#define RAFTSAMPLETYPE_TCC  1

#include <vector>
#include <string>
#include <ostream>
#include <cstdlib>
#include "ringbuffertypes.hpp"
#include "ringbufferbase.tcc"

#include "units.hpp"

template < class T, Type::RingBufferType type > class SampleType
{
public:

SampleType() : frame_width( 0 )
{
   
}

virtual ~SampleType() = default;

virtual void sample( RingBufferBase< T, type >     &buffer,
                     bool                          &global_blocked ) = 0;
virtual void accept( volatile bool &converged ) = 0;
virtual void setFrameWidth( const double  frame_width )
{
   (this)->frame_width = frame_width;
}

std::ostream&
print( std::ostream &stream )
{
   stream << (this)->printHeader() << ", " << (this)->printData();
   return( stream );
}

protected:
virtual std::string printHeader() = 0;
virtual std::string printData( raft::unit unit = raft::unit::byte )   = 0;

double frame_width;

};

#endif /* END RAFTSAMPLETYPE_TCC */
