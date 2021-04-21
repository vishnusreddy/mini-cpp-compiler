/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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


#line 123 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "sym.y"

	int ival;
	float fval;
	char cval;
	struct node *ptr;

#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "identifier_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    43,    45,    47,    42,    37,    61,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    60,    62,   123,   125,    59,    40,    41,    44,
      33,   126
};
# endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -23,   -62,   219,   -62,    -2,   -62,   185,   -62,
     -15,   -43,   -62,   -62,   -62,   -18,   -62,   207,   -24,   -62,
     -62,   -22,   -45,   -62,   -62,   -59,   -62,   -62,   -61,   104,
      47,   -62,   -62,     6,   -62,   124,   128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    84,    49,    50,    51,    52,
      11,    54,    55,    56,    57,    12,    19,    20,    59,   102,
     136,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    13,    70,    14,    75,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 96 "sym.y"
        {
cleansymbol();
printsymtable();
return 0;
}
#line 1590 "y.tab.c"
    break;

  case 27:
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
#line 1606 "y.tab.c"
    break;

  case 28:
#line 175 "sym.y"
                       { }
#line 1612 "y.tab.c"
    break;

  case 38:
#line 199 "sym.y"
        {	datatype = (yyvsp[0].ival); }
#line 1618 "y.tab.c"
    break;

  case 39:
#line 200 "sym.y"
        {	datatype = (yyvsp[0].ival); }
#line 1624 "y.tab.c"
    break;

  case 40:
#line 201 "sym.y"
        {	datatype = (yyvsp[0].ival); }
#line 1630 "y.tab.c"
    break;

  case 41:
#line 202 "sym.y"
        {	datatype = (yyvsp[0].ival); }
#line 1636 "y.tab.c"
    break;

  case 44:
#line 213 "sym.y"
                                     {
	if ((yyvsp[-2].ptr)->dtype !=- 1 && (yyvsp[-2].ptr)->scope < scope && (yyvsp[-2].ptr)->valid == 1) {

		struct node *ftp, *nnode;
		nnode = (struct node *)malloc(sizeof(struct node));
		ftp = first;
		while(ftp->link!=NULL){
			ftp = ftp->link;
		}
		addsymbol(nnode,(yyvsp[-2].ptr)->name);
		ftp->link = nnode;
		nnode->link = NULL;
		(yyvsp[-2].ptr) = nnode;

		if (datatype == 0){
			addInt((yyvsp[-2].ptr), 0, (yyvsp[0].fval));
		}

		else if (datatype == 1){
			addFloat((yyvsp[-2].ptr), 1, (yyvsp[0].fval));
		}
		else if (datatype == 2){
			float tempf = (float)(yyvsp[0].fval);
			addChar((yyvsp[-2].ptr), 2, (int)tempf);
		}
		x = datatype;

	}
	else if ((yyvsp[-2].ptr)->dtype != -1) {
		printf("Line:%d: ", line);
		printf("\033[1;31m");
		printf("error: ");
		printf("\033[0m");
		printf("redefinition of \'%s\' \n\n",  (yyvsp[-2].ptr)->name);
	}
	else {
		if (datatype == 0) {
			addInt((yyvsp[-2].ptr), 0, (yyvsp[0].fval));
		}
		else if (datatype == 1){
			addFloat((yyvsp[-2].ptr), 1, (yyvsp[0].fval));
		}
		else if (datatype == 2){
			float tempf = (float)(yyvsp[0].fval);
			addChar((yyvsp[-2].ptr), 2, (int)tempf);
		}
		x = datatype;

	}
}
#line 1691 "y.tab.c"
    break;

  case 45:
#line 264 "sym.y"
            {
	if((yyvsp[0].ptr)->dtype !=- 1 && (yyvsp[0].ptr)->scope < scope && (yyvsp[0].ptr)->valid == 1){
		struct node *ftp, *nnode;
		nnode = (struct node *)malloc(sizeof(struct node));
		ftp = first;
		while(ftp->link!=NULL){
			ftp = ftp->link;
		}
		addsymbol(nnode,(yyvsp[0].ptr)->name);
		ftp->link = nnode;
		nnode->link = NULL;
		(yyvsp[0].ptr) = nnode;

		if (datatype == 0){
			addInt((yyvsp[0].ptr), 0, INT_MIN);
		}
		else if(datatype == 1){
			addFloat((yyvsp[0].ptr), 1, INT_MIN);
		}
		else if(datatype == 2){
			addChar((yyvsp[0].ptr), 2, '-');

		}
		x = datatype;

	}
	else if((yyvsp[0].ptr)->dtype !=- 1 ){
		printf("Line:%d: ", line);

	}
	else{
		if (datatype == 0){
			addInt((yyvsp[0].ptr), 0, INT_MIN);
		}
		else if(datatype == 1){
			addFloat((yyvsp[0].ptr), 1, INT_MIN);
		}
		else if(datatype == 2){
			addChar((yyvsp[0].ptr), 2, '-');
		}
		x = datatype;
	}
}
#line 1739 "y.tab.c"
    break;

  case 46:
#line 311 "sym.y"
                        {(yyval.fval) = (yyvsp[0].fval);}
#line 1745 "y.tab.c"
    break;

  case 47:
#line 312 "sym.y"
                        {crt = lhs;}
#line 1751 "y.tab.c"
    break;

  case 48:
#line 312 "sym.y"
                                                                               {
	switch(assignop){
		case 0: if(idcheck == 1){
					if(crt->dtype == 0){
						if(assigntype == 1){
							printf("Line:%d: ", line);

						}
						crt->val.i = (int)(yyvsp[0].fval);

					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[0].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
					}
						crt->val.c = (char)((int)(yyvsp[0].fval));
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
						crt->val.i = (int)(yyvsp[-3].fval) + (int)(yyvsp[0].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);                 									}
						crt->val.f = (yyvsp[-3].fval)+ (yyvsp[0].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
						}
						crt->val.c = (char)((int)(yyvsp[-3].fval) + (int)(yyvsp[0].fval));
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
						crt->val.i = (int)(yyvsp[-3].fval) - (int)(yyvsp[0].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[-3].fval) - (yyvsp[0].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
					}
						crt->val.c = (char)((int)(yyvsp[-3].fval) - (int)(yyvsp[0].fval));
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
						crt->val.i = (int)(yyvsp[-3].fval) * (int)(yyvsp[0].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[-3].fval) * (yyvsp[0].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);

						}
						crt->val.c = (char)((int)(yyvsp[-3].fval) * (int)(yyvsp[0].fval));
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
						crt->val.i = (int)(yyvsp[-3].fval) / (int)(yyvsp[0].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);

						}
						crt->val.f = (yyvsp[-3].fval) / (yyvsp[0].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);

					}
						crt->val.c = (char)((int)(yyvsp[-3].fval) / (int)(yyvsp[0].fval));
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
						crt->val.i = (int)(yyvsp[-3].fval) % (int)(yyvsp[0].fval);
					}
					else if(crt->dtype == 1){
						if(assigntype == 2){
							printf("Line:%d: ", line);
					}
						crt->val.f = (int)(yyvsp[-3].fval) % (int)(yyvsp[0].fval);
					}
					else if(crt->dtype == 2){
						if(assigntype == 1){
							printf("Line:%d: ", line);
							}
						crt->val.c = (char)((int)(yyvsp[-3].fval) % (int)(yyvsp[0].fval));
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
#line 1928 "y.tab.c"
    break;

  case 49:
#line 488 "sym.y"
        {	assignop = 0;	}
#line 1934 "y.tab.c"
    break;

  case 50:
#line 489 "sym.y"
                {	assignop = 1;	}
#line 1940 "y.tab.c"
    break;

  case 51:
#line 490 "sym.y"
                {	assignop = 2;	}
#line 1946 "y.tab.c"
    break;

  case 52:
#line 491 "sym.y"
                {	assignop = 3;	}
#line 1952 "y.tab.c"
    break;

  case 53:
#line 492 "sym.y"
                {	assignop = 4;	}
#line 1958 "y.tab.c"
    break;

  case 54:
#line 493 "sym.y"
                {	assignop = 5;	}
#line 1964 "y.tab.c"
    break;

  case 55:
#line 498 "sym.y"
   { }
#line 1970 "y.tab.c"
    break;

  case 56:
#line 499 "sym.y"
                 { }
#line 1976 "y.tab.c"
    break;

  case 57:
#line 504 "sym.y"
                     { }
#line 1982 "y.tab.c"
    break;

  case 58:
#line 505 "sym.y"
                                       { }
#line 1988 "y.tab.c"
    break;

  case 59:
#line 510 "sym.y"
           {
	idcheck = 1;
	lhs = (yyvsp[0].ptr);

	if((yyvsp[0].ptr)->dtype == -1 && check_un == 0){

		printf("Line:%d: ", line);
		printf("\033[1;31m");
		printf("error: ");
		printf("\033[0m");
		printf("use of undeclared identifier \'%s\' \n\n", (yyvsp[0].ptr)->name);
		check_un = 0;
	}
	else if((yyvsp[0].ptr)->dtype == 0){
		(yyval.fval) = (yyvsp[0].ptr)->val.i;
		assigntype = 0;
	}
	else if((yyvsp[0].ptr)->dtype == 1){
		(yyval.fval) = (yyvsp[0].ptr)->val.f;
		assigntype = 1;
	}
	else if((yyvsp[0].ptr)->dtype == 2){
		(yyval.fval) = (yyvsp[0].ptr)->val.c;
		assigntype = 2;
	}
}
#line 2019 "y.tab.c"
    break;

  case 60:
#line 536 "sym.y"
                 {
	(yyval.fval) = (yyvsp[0].ival);
	assigntype = 0;
}
#line 2028 "y.tab.c"
    break;

  case 61:
#line 540 "sym.y"
               {
	assigntype = 1;
	if(datatype == 1){
		(yyval.fval) = (yyvsp[0].fval);
	}
	else if(datatype == 0){

		(yyval.fval) = (int)(yyvsp[0].fval);
	}
	else if(datatype == 2){

		(yyval.fval) = (int)(yyvsp[0].fval);
	}
}
#line 2047 "y.tab.c"
    break;

  case 62:
#line 554 "sym.y"
                   {
	assigntype = 2;
	if(datatype == 2){
		int tempc = (int)(yyvsp[0].cval);
		(yyval.fval) =  (float)tempc;
	}
	else if(datatype == 0){
		(yyval.fval) = (int)(yyvsp[0].cval);
	}
	else if(datatype == 1){

		(yyval.fval) = (int)(yyvsp[0].cval);
	}
}
#line 2066 "y.tab.c"
    break;

  case 63:
#line 568 "sym.y"
                    {
	(yyval.fval) = (yyvsp[-1].fval);
}
#line 2074 "y.tab.c"
    break;

  case 64:
#line 575 "sym.y"
                        {(yyval.fval) = (yyvsp[0].fval);}
#line 2080 "y.tab.c"
    break;

  case 65:
#line 576 "sym.y"
                            {(yyvsp[-1].fval)++; (yyval.fval) = (yyvsp[-1].fval);}
#line 2086 "y.tab.c"
    break;

  case 66:
#line 577 "sym.y"
                             {(yyvsp[-1].fval)--; (yyval.fval) = (yyvsp[-1].fval);}
#line 2092 "y.tab.c"
    break;

  case 67:
#line 582 "sym.y"
                        { (yyval.fval) = (yyvsp[0].fval); }
#line 2098 "y.tab.c"
    break;

  case 68:
#line 583 "sym.y"
                                  {
	switch(unaryop){
		case 1:	(yyval.fval) = (yyvsp[0].fval);
				break;
		case 2:	(yyval.fval) = -(yyvsp[0].fval);
				break;
		case 3:	(yyval.fval) = !(yyvsp[0].fval);
				break;
		case 4:	(yyval.fval) = ~((int)(yyvsp[0].fval));
				break;
		case 5:	(yyval.fval) = ++(yyvsp[0].fval);
				break;
		case 6:	(yyval.fval) = --(yyvsp[0].fval);
				break;
	}
	unaryop = -1;
}
#line 2120 "y.tab.c"
    break;

  case 69:
#line 604 "sym.y"
    {	unaryop = 1; }
#line 2126 "y.tab.c"
    break;

  case 70:
#line 605 "sym.y"
      {	unaryop = 2; }
#line 2132 "y.tab.c"
    break;

  case 71:
#line 606 "sym.y"
      {	unaryop = 3; }
#line 2138 "y.tab.c"
    break;

  case 72:
#line 607 "sym.y"
      {	unaryop = 4; }
#line 2144 "y.tab.c"
    break;

  case 73:
#line 608 "sym.y"
          {	unaryop = 5; }
#line 2150 "y.tab.c"
    break;

  case 74:
#line 609 "sym.y"
          {	unaryop = 6; }
#line 2156 "y.tab.c"
    break;

  case 75:
#line 614 "sym.y"
                      {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2162 "y.tab.c"
    break;

  case 76:
#line 615 "sym.y"
                                                  {
	if((yyvsp[-2].fval) == (yyvsp[0].fval))
		(yyval.fval) = 1;
	else
		(yyval.fval) = 0;
}
#line 2173 "y.tab.c"
    break;

  case 77:
#line 621 "sym.y"
                                                  {
	if((yyvsp[-2].fval) != (yyvsp[0].fval))
		(yyval.fval) = 1;
	else
		(yyval.fval) = 0;
}
#line 2184 "y.tab.c"
    break;

  case 78:
#line 631 "sym.y"
                        {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2190 "y.tab.c"
    break;

  case 79:
#line 633 "sym.y"
        {
		if((yyvsp[-2].fval) < (yyvsp[0].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
#line 2202 "y.tab.c"
    break;

  case 80:
#line 641 "sym.y"
        {
		if((yyvsp[-2].fval) > (yyvsp[0].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
#line 2214 "y.tab.c"
    break;

  case 81:
#line 649 "sym.y"
        {
		if((yyvsp[-2].fval) <= (yyvsp[0].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
#line 2226 "y.tab.c"
    break;

  case 82:
#line 657 "sym.y"
        {
		if((yyvsp[-2].fval) >= (yyvsp[0].fval))
			(yyval.fval) = 1;
		else
			(yyval.fval) = 0;

	}
#line 2238 "y.tab.c"
    break;

  case 83:
#line 668 "sym.y"
                                {	(yyval.fval) = (yyvsp[0].fval);	}
#line 2244 "y.tab.c"
    break;

  case 90:
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
#line 2265 "y.tab.c"
    break;

  case 91:
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
#line 2287 "y.tab.c"
    break;

  case 94:
#line 728 "sym.y"
          { addfunc((yyvsp[0].ptr), datatype, "function"); }
#line 2293 "y.tab.c"
    break;

  case 95:
#line 729 "sym.y"
                                        { }
#line 2299 "y.tab.c"
    break;

  case 96:
#line 730 "sym.y"
                                    { }
#line 2305 "y.tab.c"
    break;

  case 97:
#line 731 "sym.y"
                     { }
#line 2311 "y.tab.c"
    break;

  case 98:
#line 736 "sym.y"
                     { }
#line 2317 "y.tab.c"
    break;

  case 99:
#line 737 "sym.y"
                                                { }
#line 2323 "y.tab.c"
    break;

  case 100:
#line 742 "sym.y"
                         { addfunc((yyvsp[0].ptr), datatype, "param"); }
#line 2329 "y.tab.c"
    break;

  case 101:
#line 743 "sym.y"
                { }
#line 2335 "y.tab.c"
    break;

  case 102:
#line 748 "sym.y"
                { }
#line 2341 "y.tab.c"
    break;

  case 103:
#line 749 "sym.y"
                                 {	}
#line 2347 "y.tab.c"
    break;


#line 2351 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
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
        	*pp = entry->link;
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
