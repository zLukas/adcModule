#ifndef _BASIC_TYPES_H_
#define _BASIC_TYPES_H_

typedef char* string;
typedef unsigned char uint8;
typedef signed char sinst8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long int32;
typedef unsigned long long uint64;
typedef signed long long sint64;

typedef float float32;



/* get len of array of any type*/
#define len(list, list_type) (sizeof(list)/sizeof(list_type))

#endif
