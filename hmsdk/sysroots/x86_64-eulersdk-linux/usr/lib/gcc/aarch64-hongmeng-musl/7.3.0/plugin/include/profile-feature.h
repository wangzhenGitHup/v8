/* Generate condition features, and optimizing with condition features.
   Copyright (C) 2013 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_PROFILE_FEATURE_H
#define GCC_PROFILE_FEATURE_H

#include "gcov-io.h"

#define MAX_PATH_LEN    300
#define MAX_NAME_LEN    100

typedef struct _prof_bb_d prof_bb_info;
typedef struct _prof_cond_d prof_cond_info;
typedef struct _prof_func_d prof_func_info;
typedef struct _prof_file_d prof_file_info;
typedef struct _prof_prog_d prof_prog_info;

/* Operand information.  */
typedef struct
{
  char type_name[MAX_NAME_LEN];
  char var_name[MAX_NAME_LEN];
} prof_operand;

/* Basic block information.  */
struct _prof_bb_d
{
  int index;    /* The index of this block.  */
  gcov_type count;  /* Expected number of executions.  */
  int profile_prob; /* Executive probability.  Biased by REG_BR_PROB_BASE.  */
  int guess_prob; /* Estimated probability.  Biased by REG_BR_PROB_BASE.  */
  bool combined;  /* Whether this block is combined.  */
  bool prob_ambiguous;  /* Whether this combined block is ambiguous.  */

  prof_bb_info *next;
};

/* Condition expression information.  */
struct _prof_cond_d
{
  prof_operand lhs;
  prof_operand rhs;
  enum tree_code cmp;   /* Relational operator.  */
  prof_bb_info *first_bb; /* The bb list header.  */
  prof_bb_info *last_bb;  /* The final bb.  */

  prof_cond_info *next;
};

/* Function information.  */
struct _prof_func_d
{
  char name[MAX_NAME_LEN];  /* Function name.  */
  gcov_type count;    /* Expected number of executions.  */
  gcov_type max_bb_count; /* The hottest bb's count.  */

  prof_cond_info *first_cond; /* The cond list header.  */
  prof_cond_info *last_cond;  /* The final cond.  */
  prof_file_info *file;   /* File that contains this function.  */

  prof_func_info *next;
};

/* File information.  */
struct _prof_file_d
{
  char name[MAX_PATH_LEN];  /* File name.  */
  prof_func_info *first_func; /* The func list header.  */
  prof_func_info *last_func;  /* The final func.  */

  prof_file_info *next;
};

/* Program information.  */
struct _prof_prog_d
{
  prof_file_info *first_file; /* The file list header.  */
  prof_file_info *last_file;  /* The final file.  */
};

extern prof_prog_info *g_prof_prog;
extern struct gcov_ctr_summary fake_profile_info;

extern const char * get_cmp_str (enum tree_code code);
extern enum tree_code get_cond_code (const char *str);
extern const char * get_callee_name (const gimple *gs);

extern prof_cond_info * create_prof_cond (void);
extern void init_prof_cond_and_bb (prof_cond_info *cond);
extern bool extract_prof_cond (basic_block bb, prof_cond_info *cond_info,
    int (*edge_guess_prob)(edge e));
extern bool same_prof_cond_p (const prof_cond_info *cond1,
 const prof_cond_info *cond2);
extern prof_cond_info * find_prof_cond (const prof_func_info *func,
 const prof_cond_info *cond);
extern bool add_prof_cond_to_func (prof_func_info *func, prof_cond_info *cond);
extern void free_prof_cond (prof_cond_info *cond);
extern void free_prof_conds (prof_cond_info **first_cond);
extern void free_prof_prog (prof_prog_info *prog);
extern void get_array_type_name (tree type, char *type_name, bool ignore);
extern void deal_constant (tree op, prof_operand *op_info, bool ignore_type);
extern void deal_ssa_name (tree op, prof_operand *op_info, int depth,
 bool ignore_type);
extern void deal_declaration (tree op, prof_operand *op_info, bool ignore_type);
extern void deal_mem_ref (tree op, prof_operand *op_info, int depth,
 bool ignore_type);
extern void deal_array_ref (tree op, prof_operand *op_info, int depth,
 bool ignore_type);
extern void deal_component_ref (tree op, prof_operand *op_info, int depth,
 bool ignore_type);

extern prof_func_info * find_prof_func_in_prog (const char *filename,
 const char *funcname, const prof_prog_info *proginfo);

extern void print_prof_func (const prof_func_info *func, FILE *outfile);
extern bool parse_profile_file (FILE *infile);
extern void compute_inside_counts (const prof_func_info *func_info);

extern void get_curr_filename_and_funcname (const char **filename,
 const char **funcname);

extern FILE * verify_path (const char *pathname, const char *mode);
#endif  /* GCC_PROFILE_FEATURE_H.  */
