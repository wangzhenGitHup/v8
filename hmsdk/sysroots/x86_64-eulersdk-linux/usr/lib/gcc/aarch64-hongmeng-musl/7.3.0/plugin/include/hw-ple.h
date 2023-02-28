#ifndef GCC_HW_PLE_H
#define GCC_HW_PLE_H
#include "tree-pass.h"
#include "hw-ple-typedef.h"

enum ple_chk_types {
  none_dump_or_ple_type = 0, /* Checking nothing.  */
  dump_func_type, /* Checking whether or not in dump function flow.  */
  ple_type, /* Checking whether or not in ple.  */
  both_dump_and_ple_type /* Checking both.  */
};

extern int hw_current_bb_frequency;

extern HW_PLE_GLOBAL_VAR_LIST *g_hw_ple_global_var_list_old;

/* TRUE if in ple state.  */
extern bool is_ple_state (const char *pass_name, tree function);

extern bool in_ple_or_dff_p (const void *pass, unsigned int flag_state,
			     bool pass_state);

/* Return true if in nesting state, otherwise return false.  */
extern bool getNestingFlag ();

/* Set nestingName with value.  */
extern void setNestingName (const char *value);

/* PLE analyze when node is MEM_REF.  */
extern void mem_ref_ple (tree node, FILE *file);

/* PLE analyze when node is COMPONENT_REF.  */
extern void ple_analyzation (tree node, FILE *file);

extern void bit_field_analyze (tree node, FILE *file);

/* Set op1IndexName with the value of node.  */
extern void setOp1IndexName (tree node);

/* Initial op1IndexName to null string.  */
extern void initialOp1IndexName ();

/* Estimate for new function.  */
extern void estimate_for_function (const char *fnname);

/* Dump function relationship into file "dump_func_call.txt", and do not
   remove the content before.  */
extern void dump_function_relationship (const char* caller,
					tree callee);

extern void hw_autople_getRelationship (gassign *gs);

extern void hw_autople_getPHIInfo (tree lhs, tree rhs);

extern void hw_autople_getFunctionCall (tree lhs, tree rhs);

extern void hw_autople_getFunctionArgs (const char *function_name,
					tree sub_fn, tree arg, int argNo);

extern void hw_autople_getFunctionReturn (const char *function_name,
					  tree retVal);
extern HW_PLE_MAP g_hw_ple_map_old;
#endif
