#ifndef _ARGP_H
#define _ARGP_H

#include <stdio.h>
#include <ctype.h>
#include <errno.h>


typedef int error_t;

#ifdef  __cplusplus
extern "C" {
#endif

struct argp_option
{
  const char *name;
  int key;
  const char *arg;
  int flags;
  const char *doc;
  int group;
};

#define OPTION_ARG_OPTIONAL	0x1
#define OPTION_HIDDEN	       	0x2
#define OPTION_ALIAS		0x4
#define OPTION_DOC		0x8
#define OPTION_NO_USAGE		0x10

struct argp;
struct argp_state;
struct argp_child;

typedef int (*argp_parser_t) (int key, char *arg,
				  struct argp_state *state);

#define ARGP_ERR_UNKNOWN	E2BIG
#define ARGP_KEY_ARG		0
#define ARGP_KEY_ARGS		0x1000006
#define ARGP_KEY_END		0x1000001
#define ARGP_KEY_NO_ARGS	0x1000002
#define ARGP_KEY_INIT		0x1000003
#define ARGP_KEY_FINI		0x1000007
#define ARGP_KEY_SUCCESS	0x1000004
#define ARGP_KEY_ERROR		0x1000005

struct argp
{
  const struct argp_option *options;
  argp_parser_t parser;
  const char *args_doc;
  const char *doc;
  const struct argp_child *children;
  char *(*help_filter) (int __key, const char *__text, void *__input);
  const char *argp_domain;
};

#define ARGP_KEY_HELP_PRE_DOC	0x2000001
#define ARGP_KEY_HELP_POST_DOC	0x2000002
#define ARGP_KEY_HELP_HEADER	0x2000003
#define ARGP_KEY_HELP_EXTRA	0x2000004
#define ARGP_KEY_HELP_DUP_ARGS_NOTE 0x2000005
#define ARGP_KEY_HELP_ARGS_DOC	0x2000006

struct argp_child
{
  const struct argp *argp;
  int flags;
  const char *header;
  int group;
};

struct argp_state
{
  const struct argp *root_argp;
  int argc;
  char **argv;
  int next;
  unsigned flags;
  unsigned arg_num;
  int quoted;
  void *input;
  void **child_inputs;
  void *hook;
  char *name;
  FILE *err_stream;
  FILE *out_stream;
  void *pstate;
};

#define ARGP_PARSE_ARGV0  0x01
#define ARGP_NO_ERRS	0x02
#define ARGP_NO_ARGS	0x04
#define ARGP_IN_ORDER	0x08
#define ARGP_NO_HELP	0x10
#define ARGP_NO_EXIT	0x20
#define ARGP_LONG_ONLY	0x40
#define ARGP_SILENT    (ARGP_NO_EXIT | ARGP_NO_ERRS | ARGP_NO_HELP)

extern int argp_parse (const struct argp *__restrict __argp,
			   int __argc, char **__restrict __argv,
			   unsigned __flags, int *__restrict __arg_index,
			   void *__restrict __input);

extern const char *argp_program_version;

extern void (*argp_program_version_hook) (FILE *__restrict __stream,
					  struct argp_state *__restrict
					  __state);

extern const char *argp_program_bug_address;


#define ARGP_HELP_USAGE		0x01
#define ARGP_HELP_SHORT_USAGE	0x02
#define ARGP_HELP_SEE		0x04
#define ARGP_HELP_LONG		0x08
#define ARGP_HELP_PRE_DOC	0x10
#define ARGP_HELP_POST_DOC	0x20
#define ARGP_HELP_DOC		(ARGP_HELP_PRE_DOC | ARGP_HELP_POST_DOC)
#define ARGP_HELP_BUG_ADDR	0x40
#define ARGP_HELP_LONG_ONLY	0x80
#define ARGP_HELP_EXIT_ERR	0x100
#define ARGP_HELP_EXIT_OK	0x200
#define ARGP_HELP_STD_ERR \
  (ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR)
#define ARGP_HELP_STD_USAGE \
  (ARGP_HELP_SHORT_USAGE | ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR)
#define ARGP_HELP_STD_HELP \
  (ARGP_HELP_SHORT_USAGE | ARGP_HELP_LONG | ARGP_HELP_EXIT_OK \
   | ARGP_HELP_DOC | ARGP_HELP_BUG_ADDR)

extern void argp_help (const struct argp *__restrict __argp,
		       FILE *__restrict __stream,
		       unsigned __flags, char *__restrict __name);
extern void argp_error (const struct argp_state *__restrict __state,
			const char *__restrict __fmt, ...);
extern void argp_failure (const struct argp_state *__restrict __state,
			  int __status, int __errnum,
			  const char *__restrict __fmt, ...);

#ifdef  __cplusplus
}
#endif

#endif /* argp.h */
