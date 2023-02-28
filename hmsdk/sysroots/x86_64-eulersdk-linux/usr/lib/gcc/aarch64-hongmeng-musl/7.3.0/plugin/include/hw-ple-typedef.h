#ifndef GCC_HW_PLE_TYPEDEF_H
#define GCC_HW_PLE_TYPEDEF_H

/* Define string length.  */
#define HW_USER_NAME_LENGTH 1024
#define HW_PLE_BYTE_SIZE 8
/* Define max size of ple_map which is used in one function.  */
#define HW_PLE_MAP_MAX_SIZE 200
/* Define max size of ple_var which need to be analyzed in one function.  */
#define HW_PLE_VAR_MAX_SIZE 60

/* Define list to store global variables which need to be analyzed.  */
typedef struct HW_PLE_GLOBAL_VAR_LIST_STRU
{
  char global_var[HW_PLE_VAR_MAX_SIZE][HW_USER_NAME_LENGTH];
  char function_name[HW_USER_NAME_LENGTH];
  unsigned int size;
  struct HW_PLE_GLOBAL_VAR_LIST_STRU *nextFunction;
} HW_PLE_GLOBAL_VAR_LIST;

/* Define map to store relationship between global variables and local
   pointers.  */
typedef struct HW_PLE_MAP_NODE_STRU
{
  char local_pointer[HW_USER_NAME_LENGTH];
  char global_member[HW_USER_NAME_LENGTH];
  char function_name[HW_USER_NAME_LENGTH];
} HW_PLE_MAP_NODE;

typedef struct HW_PLE_MAP_STRU
{
  int num;
  HW_PLE_MAP_NODE map[HW_PLE_MAP_MAX_SIZE];
} HW_PLE_MAP;

#endif
