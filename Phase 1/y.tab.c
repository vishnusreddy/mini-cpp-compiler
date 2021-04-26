
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sym.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <limits.h>

	void yyerror(const char*);
	int yylex();
	extern FILE * yyin, *yyout;

	int x=0;
	extern int line;
	int scope = 0;
	int unaryop = -1;
	int assignop = -1;
	int datatype = -1;
	int assigntype = -1;
	int idcheck = -1;
	int check_un = 0;


	struct node{
		char token[20];
		char name[20];
		int dtype;
		int scope;
		int lineno;
		int valid;
		union value{
			float f;
			int i;
			char c;
		}val;

		struct node *link;

	}*first = NULL, *tmp, *crt, *lhs;

	struct node * checksym(char *);
	void addsymbol(struct node *,char *);

	void addInt(struct node *, int, int);
	void addFloat(struct node *, int, float);
	void addChar(struct node *, int, char);
	void addfunc(struct node *t, int, char *);

	void printsymtable();

	struct node * addtosymbol(struct node * n);
	void cleansymbol();



/* Line 189 of yacc.c  */
#line 127 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HASH = 258,
     INCLUDE = 259,
     STDIO = 260,
     STDLIB = 261,
     MATH = 262,
     STRING = 263,
     TIME = 264,
     STRING_LITERAL = 265,
     HEADER_LITERAL = 266,
     PRINT = 267,
     RETURN = 268,
     INTEGER_LITERAL = 269,
     CHARACTER_LITERAL = 270,
     FLOAT_LITERAL = 271,
     IDENTIFIER = 272,
     INC_OPR = 273,
     DEC_OPR = 274,
     LE_OP = 275,
     GE_OP = 276,
     EQ_OP = 277,
     NE_OP = 278,
     MUL_ASSIGN = 279,
     DIV_ASSIGN = 280,
     MOD_ASSIGN = 281,
     ADD_ASSIGN = 282,
     SUB_ASSIGN = 283,
     CHAR = 284,
     INT = 285,
     FLOAT = 286,
     VOID = 287,
     FOR = 288,
     IF = 289,
     ELSE = 290
   };
#endif
/* Tokens.  */
#define HASH 258
#define INCLUDE 259
#define STDIO 260
#define STDLIB 261
#define MATH 262
#define STRING 263
#define TIME 264
#define STRING_LITERAL 265
#define HEADER_LITERAL 266
#define PRINT 267
#define RETURN 268
#define INTEGER_LITERAL 269
#define CHARACTER_LITERAL 270
#define FLOAT_LITERAL 271
#define IDENTIFIER 272
#define INC_OPR 273
#define DEC_OPR 274
#define LE_OP 275
#define GE_OP 276
#define EQ_OP 277
#define NE_OP 278
#define MUL_ASSIGN 279
#define DIV_ASSIGN 280
#define MOD_ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define CHAR 284
#define INT 285
#define FLOAT 286
#define VOID 287
#define FOR 288
#define IF 289
#define ELSE 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 60 "sym.y"

	int ival;
	float fval;
	char cval;
	struct node *ptr;



/* Line 214 of yacc.c  */
#line 242 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 254 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    18,     2,     2,
      47,    48,    17,    14,    49,    15,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
      42,    19,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,    51,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    12,    17,    19,    21,    24,    26,
      28,    30,    32,    34,    36,    38,    41,    45,    47,    50,
      52,    54,    57,    60,    63,    68,    75,    79,    81,    83,
      85,    87,    89,    96,   104,   111,   119,   125,   128,   130,
     132,   134,   136,   138,   142,   146,   148,   150,   151,   156,
     158,   160,   162,   164,   166,   168,   170,   173,   175,   179,
     181,   183,   185,   187,   191,   193,   196,   199,   201,   204,
     206,   208,   210,   212,   214,   216,   218,   222,   226,   228,
     232,   236,   240,   244,   246,   250,   254,   256,   260,   264,
     268,   272,   275,   280,   284,   286,   291,   296,   300,   302,
     306,   309,   311,   313
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,     3,     4,    42,    57,    43,
      54,    -1,     3,     4,    11,    54,    -1,    55,    -1,    56,
      -1,    55,    56,    -1,    62,    -1,    83,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    44,    45,
      -1,    44,    59,    45,    -1,    60,    -1,    59,    60,    -1,
      62,    -1,    63,    -1,    84,    46,    -1,    13,    73,    -1,
      61,    46,    -1,    12,    47,    10,    48,    -1,    12,    47,
      10,    49,    74,    48,    -1,    67,    68,    46,    -1,    58,
      -1,    73,    -1,    64,    -1,    65,    -1,    66,    -1,    39,
      47,    73,    73,    48,    63,    -1,    39,    47,    73,    73,
      74,    48,    63,    -1,    39,    47,    62,    73,    48,    63,
      -1,    39,    47,    62,    73,    74,    48,    63,    -1,    40,
      47,    80,    48,    63,    -1,    41,    63,    -1,    38,    -1,
      35,    -1,    36,    -1,    37,    -1,    69,    -1,    68,    49,
      69,    -1,    23,    19,    70,    -1,    23,    -1,    79,    -1,
      -1,    77,    71,    72,    70,    -1,    19,    -1,    33,    -1,
      34,    -1,    30,    -1,    31,    -1,    32,    -1,    46,    -1,
      74,    46,    -1,    70,    -1,    74,    49,    70,    -1,    23,
      -1,    20,    -1,    22,    -1,    21,    -1,    47,    74,    48,
      -1,    75,    -1,    76,    24,    -1,    76,    25,    -1,    76,
      -1,    78,    77,    -1,    14,    -1,    15,    -1,    50,    -1,
      51,    -1,    24,    -1,    25,    -1,    80,    -1,    79,    28,
      80,    -1,    79,    29,    80,    -1,    81,    -1,    80,    42,
      81,    -1,    80,    43,    81,    -1,    80,    26,    81,    -1,
      80,    27,    81,    -1,    82,    -1,    81,    14,    82,    -1,
      81,    15,    82,    -1,    77,    -1,    82,    17,    77,    -1,
      82,    16,    77,    -1,    82,    18,    77,    -1,    67,    85,
      58,    -1,    85,    58,    -1,    85,    47,    88,    48,    -1,
      85,    47,    48,    -1,    23,    -1,    85,    47,    86,    48,
      -1,    85,    47,    88,    48,    -1,    85,    47,    48,    -1,
      87,    -1,    86,    49,    87,    -1,    67,    23,    -1,    67,
      -1,    23,    -1,    88,    49,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   104,   105,   106,   111,   112,   117,   118,
     123,   124,   125,   126,   127,   132,   133,   138,   139,   144,
     145,   146,   147,   148,   153,   154,   159,   164,   175,   176,
     177,   178,   183,   184,   185,   186,   190,   194,   199,   200,
     201,   202,   207,   208,   213,   264,   311,   312,   312,   488,
     489,   490,   491,   492,   493,   498,   499,   504,   505,   510,
     536,   540,   554,   568,   575,   576,   577,   582,   583,   604,
     605,   606,   607,   608,   609,   614,   615,   621,   631,   632,
     640,   648,   656,   668,   669,   670,   675,   676,   677,   678,
     683,   700,   722,   723,   728,   729,   730,   731,   736,   737,
     742,   743,   748,   749
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "STDIO", "STDLIB",
  "MATH", "STRING", "TIME", "STRING_LITERAL", "HEADER_LITERAL", "PRINT",
  "RETURN", "'+'", "'-'", "'/'", "'*'", "'%'", "'='", "INTEGER_LITERAL",
  "CHARACTER_LITERAL", "FLOAT_LITERAL", "IDENTIFIER", "INC_OPR", "DEC_OPR",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "CHAR", "INT", "FLOAT", "VOID",
  "FOR", "IF", "ELSE", "'<'", "'>'", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'!'", "'~'", "$accept", "S", "program", "translation_unit",
  "ext_dec", "libraries", "compound_statement", "block_item_list",
  "block_item", "printstat", "declaration", "statement",
  "iteration_statement", "if_statement", "else_statement",
  "type_specifier", "init_declarator_list", "init_declarator",
  "assignment_expression", "$@1", "assignment_operator",
  "expression_statement", "expression", "primary_expression",
  "postfix_expression", "unary_expression", "unary_operator",
  "equality_expression", "relational_expression", "additive_expression",
  "multiplicative_expression", "function_definition", "function_call",
  "declarator", "parameter_list", "parameter_declaration",
  "identifier_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    43,    45,    47,    42,    37,    61,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    60,    62,   123,   125,    59,    40,    41,    44,
      33,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    61,    61,    62,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    65,    66,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    71,    70,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    79,    79,    79,    80,    80,
      80,    80,    80,    81,    81,    81,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    86,    86,
      87,    87,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     4,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       1,     2,     2,     2,     4,     6,     3,     1,     1,     1,
       1,     1,     6,     7,     6,     7,     5,     2,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     2,     4,     3,     1,     4,     4,     3,     1,     3,
       2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    94,    39,    40,    41,    38,     0,     2,     5,
       6,     8,     0,     9,     0,     0,     1,     7,    45,     0,
      42,     0,     0,     0,    91,     0,     0,     0,    26,     0,
      90,     0,     0,    69,    70,    60,    62,    61,    59,    73,
      74,     0,     0,     0,    15,    55,     0,    71,    72,    27,
       0,    17,     0,    19,    20,    29,    30,    31,     0,    57,
      28,     0,    64,    67,    86,     0,    46,    75,    78,    83,
       0,     0,   102,    97,   101,     0,    98,     0,     4,    10,
      11,    12,    13,    14,     0,    59,    44,    45,    43,     0,
      22,     0,     0,    37,     0,    16,    18,    23,    56,     0,
      65,    66,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,   100,    95,     0,
      96,     0,     0,     0,     0,     0,    86,     0,    63,    58,
      49,    52,    53,    54,    50,    51,     0,    76,    77,    81,
      82,    79,    80,    84,    85,    88,    87,    89,    93,     0,
      99,   103,     3,    24,     0,     0,     0,     0,    48,    92,
       0,     0,     0,     0,     0,    36,    25,    34,     0,    32,
       0,    35,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    84,    49,    50,    51,    52,
      11,    54,    55,    56,    57,    12,    19,    20,    59,   102,
     136,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    13,    70,    14,    75,    76,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int16 yypact[] =
{
      69,    23,   -62,   -62,   -62,   -62,   -62,    40,   -62,   272,
     -62,   -62,    19,   -62,   -27,    -3,   -62,   -62,   -10,    -8,
     -62,   -27,   109,   -12,   -62,    69,    72,   255,   -62,    65,
     -62,    44,   202,   -62,   -62,   -62,   -62,   -62,    53,   -62,
     -62,    61,    66,    43,   -62,   -62,   255,   -62,   -62,   -62,
     149,   -62,    73,   -62,   -62,   -62,   -62,   -62,    65,   -62,
     -62,    25,   -62,    -9,   146,   255,    -7,   -13,    71,    79,
      82,    70,   -62,   -62,   114,    67,   -62,    87,   -62,   -62,
     -62,   -62,   -62,   -62,    27,   -62,   -62,   156,   -62,   142,
     -62,   183,   255,   -62,    94,   -62,   -62,   -62,   -62,   255,
     -62,   -62,   266,   -62,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   -62,   103,   -62,   -62,    24,
     -62,   145,    69,   118,   202,   202,   -62,   246,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   255,   -13,   -13,    71,
      71,    71,    71,    79,    79,   -62,   -62,   -62,   136,   133,
     -62,   -62,   -62,   -62,   255,   217,   236,    43,   -62,   162,
     143,    43,   153,    43,   166,   -62,   -62,   -62,    43,   -62,
      43,   -62,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -23,   -62,   219,   -62,    -2,   -62,   185,   -62,
     -15,   -43,   -62,   -62,   -62,   -18,   -62,   207,   -24,   -62,
     -62,   -22,   -45,   -62,   -62,   -59,   -62,   -62,   -61,   104,
      47,   -62,   -62,     6,   -62,   124,   128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -98
static const yytype_int16 yytable[] =
{
      93,    94,    78,    86,    58,    74,   103,    53,    25,    27,
      90,    72,    24,   106,   107,   100,   101,    22,    21,    30,
      23,   104,   105,     3,     4,     5,     6,    15,    71,   108,
     109,   127,    58,   126,   -94,    53,    73,   -94,    28,    26,
      16,    29,    18,   137,   138,   126,   126,   126,   126,   126,
     126,   126,   126,   145,   146,   147,    71,    33,    34,     3,
       4,     5,     6,    35,    36,    37,    85,    39,    40,   125,
     122,    98,     1,    58,    99,   129,   124,    79,    80,    81,
      82,    83,    41,    42,    43,   110,   111,    22,    87,    45,
      46,    89,     2,    47,    48,   112,   113,   114,    74,   152,
     -94,    74,   155,   156,     3,     4,     5,     6,    91,   160,
     162,   164,   158,    92,   165,   118,   119,   116,   167,    97,
     169,    31,    32,    33,    34,   171,    72,   172,   115,    35,
      36,    37,    38,    39,    40,   120,   121,   117,     3,     4,
       5,     6,   128,    99,     3,     4,     5,     6,    41,    42,
      43,   148,   123,    22,    44,    45,    46,   143,   144,    47,
      48,    31,    32,    33,    34,   -47,   153,   154,   151,    35,
      36,    37,    38,    39,    40,    27,   -47,   -47,   -47,   -47,
     -47,   159,   121,   -97,     3,     4,     5,     6,    41,    42,
      43,   166,    99,    22,    95,    45,    46,    33,    34,    47,
      48,   168,    99,    35,    36,    37,    85,    39,    40,   -96,
     139,   140,   141,   142,   170,    99,    33,    34,     3,     4,
       5,     6,    35,    36,    37,    85,    39,    40,    17,    45,
      46,    33,    34,    47,    48,    96,    88,    35,    36,    37,
      85,    39,    40,   150,   149,     0,     0,     0,    45,    46,
      33,    34,    47,    48,     0,     0,    35,    36,    37,    85,
      39,    40,     0,     0,    46,   161,     0,    47,    48,    33,
      34,     0,   106,   107,     0,    35,    36,    37,    85,    39,
      40,     0,     0,    46,   163,   130,    47,    48,   108,   109,
       0,     0,     0,     0,   157,     2,   131,   132,   133,   134,
     135,     0,    46,     0,     0,    47,    48,     3,     4,     5,
       6
};

static const yytype_int16 yycheck[] =
{
      43,    46,    25,    27,    22,    23,    65,    22,    11,    19,
      32,    23,    14,    26,    27,    24,    25,    44,    12,    21,
      47,    28,    29,    35,    36,    37,    38,     4,    22,    42,
      43,    92,    50,    92,    44,    50,    48,    47,    46,    42,
       0,    49,    23,   104,   105,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    50,    14,    15,    35,
      36,    37,    38,    20,    21,    22,    23,    24,    25,    91,
      43,    46,     3,    91,    49,    99,    91,     5,     6,     7,
       8,     9,    39,    40,    41,    14,    15,    44,    23,    46,
      47,    47,    23,    50,    51,    16,    17,    18,   116,   122,
      47,   119,   124,   125,    35,    36,    37,    38,    47,   154,
     155,   156,   136,    47,   157,    48,    49,    47,   161,    46,
     163,    12,    13,    14,    15,   168,    23,   170,    46,    20,
      21,    22,    23,    24,    25,    48,    49,    23,    35,    36,
      37,    38,    48,    49,    35,    36,    37,    38,    39,    40,
      41,    48,    10,    44,    45,    46,    47,   110,   111,    50,
      51,    12,    13,    14,    15,    19,    48,    49,    23,    20,
      21,    22,    23,    24,    25,    19,    30,    31,    32,    33,
      34,    48,    49,    47,    35,    36,    37,    38,    39,    40,
      41,    48,    49,    44,    45,    46,    47,    14,    15,    50,
      51,    48,    49,    20,    21,    22,    23,    24,    25,    47,
     106,   107,   108,   109,    48,    49,    14,    15,    35,    36,
      37,    38,    20,    21,    22,    23,    24,    25,     9,    46,
      47,    14,    15,    50,    51,    50,    29,    20,    21,    22,
      23,    24,    25,   119,   116,    -1,    -1,    -1,    46,    47,
      14,    15,    50,    51,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    47,    48,    -1,    50,    51,    14,
      15,    -1,    26,    27,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    47,    48,    19,    50,    51,    42,    43,
      -1,    -1,    -1,    -1,    48,    23,    30,    31,    32,    33,
      34,    -1,    47,    -1,    -1,    50,    51,    35,    36,    37,
      38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    23,    35,    36,    37,    38,    53,    54,    55,
      56,    62,    67,    83,    85,     4,     0,    56,    23,    68,
      69,    85,    44,    47,    58,    11,    42,    19,    46,    49,
      58,    12,    13,    14,    15,    20,    21,    22,    23,    24,
      25,    39,    40,    41,    45,    46,    47,    50,    51,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    70,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      84,    85,    23,    48,    67,    86,    87,    88,    54,     5,
       6,     7,     8,     9,    57,    23,    70,    23,    69,    47,
      73,    47,    47,    63,    74,    45,    60,    46,    46,    49,
      24,    25,    71,    77,    28,    29,    26,    27,    42,    43,
      14,    15,    16,    17,    18,    46,    47,    23,    48,    49,
      48,    49,    43,    10,    62,    73,    77,    80,    48,    70,
      19,    30,    31,    32,    33,    34,    72,    80,    80,    81,
      81,    81,    81,    82,    82,    77,    77,    77,    48,    88,
      87,    23,    54,    48,    49,    73,    73,    48,    70,    48,
      74,    48,    74,    48,    74,    63,    48,    63,    48,    63,
      48,    63,    63
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 96 "sym.y"
    {
cleansymbol();
printsymtable();
return 0;
}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 164 "sym.y"
    {
				struct node *ftp;
				ftp = first;
				while(ftp!=NULL){
					if(ftp->scope == scope && ftp->valid == 1){
						ftp->valid = 0;
					}
					ftp=ftp->link;
				}
				scope--;
			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 175 "sym.y"
    { }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 199 "sym.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 200 "sym.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 201 "sym.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 202 "sym.y"
    {	datatype = (yyvsp[(1) - (1)].ival); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 213 "sym.y"
    {
	if ((yyvsp[(1) - (3)].ptr)->dtype !=- 1 && (yyvsp[(1) - (3)].ptr)->scope < scope && (yyvsp[(1) - (3)].ptr)->valid == 1) {

		struct node *ftp, *nnode;
		nnode = (struct node *)malloc(sizeof(struct node));
		ftp = first;
		while(ftp->link!=NULL){
			ftp = ftp->link;
		}
		addsymbol(nnode,(yyvsp[(1) - (3)].ptr)->name);
		ftp->link = nnode;
		nnode->link = NULL;
		(yyvsp[(1) - (3)].ptr) = nnode;

		if (datatype == 0){
			addInt((yyvsp[(1) - (3)].ptr), 0, (yyvsp[(3) - (3)].fval));
		}

		else if (datatype == 1){
			addFloat((yyvsp[(1) - (3)].ptr), 1, (yyvsp[(3) - (3)].fval));
		}
		else if (datatype == 2){
			float tempf = (float)(yyvsp[(3) - (3)].fval);
			addChar((yyvsp[(1) - (3)].ptr), 2, (int)tempf);
		}
		x = datatype;

	}
	else if ((yyvsp[(1) - (3)].ptr)->dtype != -1) {
		printf("Line:%d: ", line);
		printf("\033[1;31m");
		printf("error: ");
		printf("\033[0m");
		printf("redefinition of \'%s\' \n\n",  (yyvsp[(1) - (3)].ptr)->name);
	}
	else {
		if (datatype == 0) {
			addInt((yyvsp[(1) - (3)].ptr), 0, (yyvsp[(3) - (3)].fval));
		}
		else if (datatype == 1){
			addFloat((yyvsp[(1) - (3)].ptr), 1, (yyvsp[(3) - (3)].fval));
		}
		else if (datatype == 2){
			float tempf = (float)(yyvsp[(3) - (3)].fval);
			addChar((yyvsp[(1) - (3)].ptr), 2, (int)tempf);
		}
		x = datatype;

	}
}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 264 "sym.y"
    {
	if((yyvsp[(1) - (1)].ptr)->dtype !=- 1 && (yyvsp[(1) - (1)].ptr)->scope < scope && (yyvsp[(1) - (1)].ptr)->valid == 1){
		struct node *ftp, *nnode;
		nnode = (struct node *)malloc(sizeof(struct node));
		ftp = first;
		while(ftp->link!=NULL){
			ftp = ftp->link;
		}
		addsymbol(nnode,(yyvsp[(1) - (1)].ptr)->name);
		ftp->link = nnode;
		nnode->link = NULL;
		(yyvsp[(1) - (1)].ptr) = nnode;

		if (datatype == 0){
			addInt((yyvsp[(1) - (1)].ptr), 0, INT_MIN);
		}
		else if(datatype == 1){
			addFloat((yyvsp[(1) - (1)].ptr), 1, INT_MIN);
		}
		else if(datatype == 2){
			addChar((yyvsp[(1) - (1)].ptr), 2, '-');

		}
		x = datatype;

	}
	else if((yyvsp[(1) - (1)].ptr)->dtype !=- 1 ){
		printf("Line:%d: ", line);

	}
	else{
		if (datatype == 0){
			addInt((yyvsp[(1) - (1)].ptr), 0, INT_MIN);
		}
		else if(datatype == 1){
			addFloat((yyvsp[(1) - (1)].ptr), 1, INT_MIN);
		}
		else if(datatype == 2){
			addChar((yyvsp[(1) - (1)].ptr), 2, '-');
		}
		x = datatype;
	}
}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 311 "sym.y"
    {(yyval.fval) = (yyvsp[(1) - (1)].fval);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 312 "sym.y"
    {crt = lhs;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 312 "sym.y"
    {
	switch(assignop){
		case 0: if(idcheck == 1){
					if(crt->dtype == 0){
						if(assigntype == 1){
							printf("Line:%d: ", line);

						}
						crt->val.i = (int)(yyvsp[(4) - (4)].fval);

					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
					}
						crt->val.c = (char)((int)(yyvsp[(4) - (4)].fval));
					}
				}
				else{
					printf("We'll see later\n");
				}
				crt = NULL;
				break;

		case 1: if(idcheck == 1){
					if(crt->dtype == 0){
						if(assigntype == 1){
							printf("Line:%d: ", line);
						}
						crt->val.i = (int)(yyvsp[(1) - (4)].fval) + (int)(yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);                 									}
						crt->val.f = (yyvsp[(1) - (4)].fval)+ (yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
						}
						crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) + (int)(yyvsp[(4) - (4)].fval));
					}
				}
				else{
					printf("We'll see later\n");
				}
				crt = NULL;
				break;

		case 2:	if(idcheck == 1){
					if(crt->dtype == 0){
						if(assigntype == 1){
							printf("Line:%d: ", line);
						}
						crt->val.i = (int)(yyvsp[(1) - (4)].fval) - (int)(yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[(1) - (4)].fval) - (yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
					}
						crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) - (int)(yyvsp[(4) - (4)].fval));
					}
				}
				else{
					printf("We'll see later\n");
				}
				crt = NULL;
				break;

		case 3:	if(idcheck == 1){
					if(crt->dtype == 0){
						if(assigntype == 1){
							printf("Line:%d: ", line);

					}
						crt->val.i = (int)(yyvsp[(1) - (4)].fval) * (int)(yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[(1) - (4)].fval) * (yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);

						}
						crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) * (int)(yyvsp[(4) - (4)].fval));
					}
				}
				else{
					printf("We'll see later\n");
				}
				crt = NULL;
				break;

		case 4:	if(idcheck == 1){
					if(crt->dtype == 0){
						if(assigntype == 1){
							printf("Line:%d: ", line);

						}
						crt->val.i = (int)(yyvsp[(1) - (4)].fval) / (int)(yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[(1) - (4)].fval) / (yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);

					}
						crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) / (int)(yyvsp[(4) - (4)].fval));
					}
				}
				else{
					printf("We'll see later\n");
				}
				crt = NULL;
				break;

		case 5:	if(idcheck == 1){
					if(crt->dtype == 0){
						if(assigntype == 1){
							printf("Line:%d: ", line);
						}
						crt->val.i = (int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);
					}
						crt->val.f = (int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
							}
						crt->val.c = (char)((int)(yyvsp[(1) - (4)].fval) % (int)(yyvsp[(4) - (4)].fval));
					}
				}
				else{
					printf("We'll see later\n");
				}
				crt = NULL;
				break;


	}
	assignop = -1;
	assigntype = -1;
}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 488 "sym.y"
    {	assignop = 0;	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 489 "sym.y"
    {	assignop = 1;	}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 490 "sym.y"
    {	assignop = 2;	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 491 "sym.y"
    {	assignop = 3;	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 492 "sym.y"
    {	assignop = 4;	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 493 "sym.y"
    {	assignop = 5;	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 498 "sym.y"
    { }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 499 "sym.y"
    { }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 504 "sym.y"
    { }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 505 "sym.y"
    { }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 510 "sym.y"
    {
	idcheck = 1;
	lhs = (yyvsp[(1) - (1)].ptr);

	if((yyvsp[(1) - (1)].ptr)->dtype == -1 && check_un == 0){

		printf("Line:%d: ", line);
		printf("\033[1;31m");
		printf("error: ");
		printf("\033[0m");
		printf("use of undeclared identifier \'%s\' \n\n", (yyvsp[(1) - (1)].ptr)->name);
		check_un = 0;
	}
	else if((yyvsp[(1) - (1)].ptr)->dtype == 0){
		(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.i;
		assigntype = 0;
	}
	else if((yyvsp[(1) - (1)].ptr)->dtype == 1){
		(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.f;
		assigntype = 1;
	}
	else if((yyvsp[(1) - (1)].ptr)->dtype == 2){
		(yyval.fval) = (yyvsp[(1) - (1)].ptr)->val.c;
		assigntype = 2;
	}
}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 536 "sym.y"
    {
	(yyval.fval) = (yyvsp[(1) - (1)].ival);
	assigntype = 0;
}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 540 "sym.y"
    {
	assigntype = 1;
	if(datatype == 1){
		(yyval.fval) = (yyvsp[(1) - (1)].fval);
	}
	else if(datatype == 0){

		(yyval.fval) = (int)(yyvsp[(1) - (1)].fval);
	}
	else if(datatype == 2){

		(yyval.fval) = (int)(yyvsp[(1) - (1)].fval);
	}
}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 554 "sym.y"
    {
	assigntype = 2;
	if(datatype == 2){
		int tempc = (int)(yyvsp[(1) - (1)].cval);
		(yyval.fval) =  (float)tempc;
	}
	else if(datatype == 0){
		(yyval.fval) = (int)(yyvsp[(1) - (1)].cval);
	}
	else if(datatype == 1){

		(yyval.fval) = (int)(yyvsp[(1) - (1)].cval);
	}
}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 568 "sym.y"
    {
	(yyval.fval) = (yyvsp[(2) - (3)].fval);
}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 575 "sym.y"
    {(yyval.fval) = (yyvsp[(1) - (1)].fval);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 576 "sym.y"
    {(yyvsp[(1) - (2)].fval)++; (yyval.fval) = (yyvsp[(1) - (2)].fval);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 577 "sym.y"
    {(yyvsp[(1) - (2)].fval)--; (yyval.fval) = (yyvsp[(1) - (2)].fval);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 582 "sym.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].fval); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 583 "sym.y"
    {
	switch(unaryop){
		case 1:	(yyval.fval) = (yyvsp[(2) - (2)].fval);
				break;
		case 2:	(yyval.fval) = -(yyvsp[(2) - (2)].fval);
				break;
		case 3:	(yyval.fval) = !(yyvsp[(2) - (2)].fval);
				break;
		case 4:	(yyval.fval) = ~((int)(yyvsp[(2) - (2)].fval));
				break;
		case 5:	(yyval.fval) = ++(yyvsp[(2) - (2)].fval);
				break;
		case 6:	(yyval.fval) = --(yyvsp[(2) - (2)].fval);
				break;
	}
	unaryop = -1;
}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 604 "sym.y"
    {	unaryop = 1; }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 605 "sym.y"
    {	unaryop = 2; }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 606 "sym.y"
    {	unaryop = 3; }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 607 "sym.y"
    {	unaryop = 4; }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 608 "sym.y"
    {	unaryop = 5; }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 609 "sym.y"
    {	unaryop = 6; }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 614 "sym.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 615 "sym.y"
    {
	if((yyvsp[(1) - (3)].fval) == (yyvsp[(3) - (3)].fval))
		(yyval.fval) = 1;
	else
		(yyval.fval) = 0;
}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 621 "sym.y"
    {
	if((yyvsp[(1) - (3)].fval) != (yyvsp[(3) - (3)].fval))
		(yyval.fval) = 1;
	else
		(yyval.fval) = 0;
}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 631 "sym.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 633 "sym.y"
    {
		if((yyvsp[(1) - (3)].fval) < (yyvsp[(3) - (3)].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 641 "sym.y"
    {
		if((yyvsp[(1) - (3)].fval) > (yyvsp[(3) - (3)].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 649 "sym.y"
    {
		if((yyvsp[(1) - (3)].fval) <= (yyvsp[(3) - (3)].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 657 "sym.y"
    {
		if((yyvsp[(1) - (3)].fval) >= (yyvsp[(3) - (3)].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 668 "sym.y"
    {	(yyval.fval) = (yyvsp[(1) - (1)].fval);	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 684 "sym.y"
    {
		struct node *ftp;
		ftp = first;
		while(ftp!=NULL){
			if(ftp->scope == scope && ftp->valid == 1){
				ftp->valid = 0;
			}
			else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
				ftp->valid = 0;
			}

			ftp=ftp->link;
		}
		scope--;

	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 701 "sym.y"
    {
		printf("Line:%d: ", line);

		struct node *ftp;
		ftp = first;
		while(ftp!=NULL){
			if(ftp->scope == scope && ftp->valid == 1){
				ftp->valid = 0;
			}
			else if(strcmp(ftp->token, "param") == 0 && ftp->valid == 1){
				ftp->valid = 0;
			}

			ftp=ftp->link;
		}
		scope--;
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 728 "sym.y"
    { addfunc((yyvsp[(1) - (1)].ptr), datatype, "function"); }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 729 "sym.y"
    { }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 730 "sym.y"
    { }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 731 "sym.y"
    { }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 736 "sym.y"
    { }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 737 "sym.y"
    { }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 742 "sym.y"
    { addfunc((yyvsp[(2) - (2)].ptr), datatype, "param"); }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 743 "sym.y"
    { }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 748 "sym.y"
    { }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 749 "sym.y"
    {	}
    break;



/* Line 1455 of yacc.c  */
#line 2473 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 753 "sym.y"



void yyerror(const char *str){
	fflush(stdout);
	printf("Line:%d: ", line);
	printf("\033[1;31m");
	printf("error: ");
	printf("\033[0m");
	printf("%s\n", str);
}


int main(){
	yyout = fopen("output.c", "w");
	printf("\n");
	yyparse();


	fclose(yyout);
	return 0;
}


void addInt(struct node *t,int type,int val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = val;
        strcpy(t->token, "identifier");
    }
}


void addFloat(struct node *t,int type,float val) {
    if(t->dtype == -1) {
        t->dtype = type;
        t->val.f = (float)val;
        strcpy(t->token, "identifier");
    }
}


void addChar(struct node *t,int type, char val) {
   	if(t->dtype == -1) {
   	    t->dtype = type;
   	    t->val.c = (char)val;
   	    strcpy(t->token, "identifier");
   	}
}


struct node * addtosymbol(struct node * n){
	if(first == NULL){
		first = n;
	}
	else{
		struct  node * ftp = first;
		while(ftp->link !=NULL) {
			ftp = ftp->link;
		}
		ftp->link = n;
	}
	return n;
}


struct node * checksym(char *vname) {
	struct node *ftp;
	struct node *rp;
	struct node *nnode;
	struct node *same;

	if(first == NULL) {
		nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);
	    first = nnode;
	}
	else {
	    ftp = first;
	    while(ftp!=NULL) {

	        if(strcmp(vname,ftp->name) == 0){
	            if(ftp->scope > scope && ftp->valid == 1) {
					same = ftp;
	            	return same;
	            }
	            else if(ftp->scope == scope && ftp->valid == 1){
	            	same = ftp;
	            	return same;
	            }
	            else if(ftp->scope < scope && ftp->valid == 1){
	         		check_un = 1;	//no error

	         		same = ftp;
	            	return same;

	            }
	          	else if(ftp->scope > scope && ftp->valid == 0){
	          		check_un = 0;	//undeclared
	          	}

	        }
	        rp = ftp;
	        ftp = ftp->link;
	    }
	    nnode = (struct node *)malloc(sizeof(struct node));
		addsymbol(nnode,vname);

	    rp->link = nnode;
	}
	return nnode;
}


void addsymbol(struct node *tp, char *vname) {
    strcpy(tp->name,vname);
    tp->dtype = -1;
    tp->link = NULL;
    tp->scope = scope;
    tp->valid = 1;
    tp->lineno = line;
}


void cleansymbol(){
	struct node** pp = &first;
    while (*pp) {

        struct node* entry = *pp;

        if (entry->dtype == -1  ) {
            *pp = entry->link;
            free(entry);
        }
        else if(strcmp(entry->name,"main")== 0 && strcmp(entry->token, "function")==0){	//remove main entry from symbol table
        	//*pp = entry->link;
            free(entry);
        }
        // Else move to next
        else
            pp = &(entry->link);
    }
}

void addfunc(struct node *t,int type, char *s){
	if(t->dtype == -1) {
        t->dtype = type;
        t->val.i = 0;
        strcpy(t->token, s);
    }
}


void printsymtable(){
	struct node *ftp;
    ftp=first;
    printf("\n\nSymbol Table\n\n");
	printf("   Symbol\t\tName\t  Type\t      Scope\t   Line Number\t       Value \n");
	printf("------------------------------------------------------------------------------------\n");

    while(ftp!=NULL) {
        char data_type[10];
        if(ftp->dtype==0)
        	strcpy(data_type,"int");
        if(ftp->dtype==1)
        	strcpy(data_type,"float");
        if(ftp->dtype==2)
        	strcpy(data_type,"char");
        if(ftp->dtype==3)
        	strcpy(data_type,"void");

        printf("%11s\t%12s\t%6s\t\t%d\t\t%d\t\t",ftp->token, ftp->name, data_type, ftp->scope, ftp->lineno);

        if(ftp->dtype == 0){
        	if(ftp->val.i == INT_MIN)
        		printf("-\n");
        	else
           		printf("%d\n",ftp->val.i);
        }
        else if(ftp->dtype == 1){
        	if(ftp->val.f == INT_MIN)
        		printf("-\n");
        	else
           		printf("%f\n",ftp->val.f);
       	}
        else if(ftp->dtype == 2){
            printf("%c\n",ftp->val.c);
        }
        else if(strcmp(ftp->token, "function")==0){
        	printf("-\n");
        }
        else{
	        printf("-	Delete it\n");
	    }
        ftp=ftp->link;
    }
    printf("\n\n\n");
}

