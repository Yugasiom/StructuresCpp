#ifndef COMMON_HPP_INCLUDED

#define COMMON_HPP_INCLUDED


#include <threads.h>


#define  BAD_ALLOC_ERROR 1
#define  CONTAINER_NOT_PROVIDED (BAD_ALLOC_ERROR + 1)
#define  CONTAINER_IS_EMPTY (CONTAINER_NOT_PROVIDED + 1)


extern thread_local int container_error;


#endif   // COMMON_HPP_INCLUDED
