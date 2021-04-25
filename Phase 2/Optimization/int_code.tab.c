
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
#line 1 "int_code.y"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h> 
#include "lex.yy.c"
//typedef char* string;
//#define YYSTYPE string
FILE *symtab;
#define STR(VAR) (#VAR)
#define release 1
#define MAXCHILD 10
FILE *syntree;
extern void yyerror(const char *);  /* prints grammar violation message */
extern int yylex(void);
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;

int iasval, itermval, iexpval;
char casval, ctermval, cexpval;
float fasval, ftermval, fexpval;
int cflag=0, iflag=0, fflag=0;
char* tab="  ";
char indent[100]="";
char type[200];
char if_stmt_skip_label[10];
char* integer="INT";
char* floating="float";
char* none = "none";
char* assign = "=";
int expval=0;
int errors = 0;
/*Stack*/

FILE *icgout;



/*Data Structure to store quadruples*/
struct quadruple{
    char statement[30];
    char op[10];
    char arg1[20];
    char arg2[20];
    char res[20];
    int lineno;
    struct quadruple *next;
};
typedef struct quadruple quadruple;

struct quad_list{
    quadruple* head;
};
typedef struct quad_list quad_list;
quad_list* q_list1;

quadruple* create_quadruple(char* statement,char* op, char* arg1, char* arg2, char* res, int lineno) {
    quadruple* new_quadruple = (quadruple*)malloc(sizeof(quadruple));
    strcpy(new_quadruple->statement,statement);
    strcpy(new_quadruple->op,op);
    strcpy(new_quadruple->arg1,arg1);
    strcpy(new_quadruple->arg2,arg2);
    strcpy(new_quadruple->res,res);
    new_quadruple->lineno = lineno;
    
    //printf("Created quadruple record...\n");
    new_quadruple->next=NULL;
    return new_quadruple;
}
void insert_quadruple(quad_list * list, quadruple* q1) {
    quadruple * traverse = list->head;
    if(traverse==NULL) {
        list->head = q1;
    }
    else {
        while (traverse->next !=NULL) {
            traverse = traverse->next;
        }
        traverse->next = q1;
    }
}
char* get_three_add(quadruple* record) {
    char *res = (char *)malloc(sizeof(char)*50);
    if(strcmp(record->statement,"expression") == 0) {
        sprintf(res,"%s = %s %s %s",record->res,record->arg1,record->op,record->arg2);
    }
    else if(strcmp(record->statement,"assignment") == 0){
        sprintf(res,"%s = %s %s",record->res,record->op,record->arg1);   
    }
    else if(strcmp(record->statement,"conditional_goto") == 0){
        sprintf(res,"if %s %s %s goto %s",record->arg1,record->op,record->arg2,record->res);
    }
    else if(strcmp(record->statement,"goto") == 0){
        sprintf(res,"goto %s",record->res);
    }
    else if(strcmp(record->statement,"label") == 0 ){
        sprintf(res,"%s : ",record->res);
    }
    else if(strcmp(record->statement, "unary")==0){
    	sprintf(res, "%s = %s %s", record->res, record->arg1, record->arg2);
    }
    else if(strcmp(record->statement, "condition")==0){
    	sprintf(res, "%s", record->res);
    }
    else if(strcmp(record->statement, "ARR")==0){
    	sprintf(res, "ARR %s = %s", record->res, record->arg1);
    }
    return res;
}

void display_three_add(quad_list *list) {
    quadruple *traverse = list->head;
    while(traverse!=NULL) {
    	printf("%s\n", get_three_add(traverse));
        fprintf(icgout, "%s\n",get_three_add(traverse));

        traverse=traverse->next;
    }
}



int temp_count = 0;
int label_count = 0;
char * create_temp() {
    char *new_temp = (char*)malloc(sizeof(char)*10);
    sprintf(new_temp,"t%d",temp_count);
    temp_count+=1;
    //printf("Created temporary variable : %d",temp_count);
    return new_temp;
}
char * create_label() {
    char *new_label=(char*)malloc(sizeof(char)*10);
    sprintf(new_label,"L%d",label_count);
    label_count+=1;
    return new_label;
}
char * get_previous_temp() {
    //char *new_temp = (char*)malloc(sizeof(char)*10);
    //sprintf(new_temp,"t%d",temp_count-1);
    quadruple * traversal = q_list1->head;
    if(traversal==NULL) return "";
    while(traversal->next!=NULL) {
        traversal=traversal->next;
    }
    return traversal->res;
}

char * get_dtype(char * str) {
    int i=0;
    char* type = (char*)malloc(sizeof(char)*10);
    if(str[0]=='\"') {
        strcpy(type,"STRING");
        return type;
    }
    else if(str[0]=='\'') {
        strcpy(type,"CHAR");
        return type;
    }
    strcpy(type,"INT");
    while(str[i]!='\0' && str[i]>=0 && str[i]<=9) {
        i++;
    }
    if (str[i]=='\0') {
        return type;
    }
    else if (str[i]=='.') {
        strcpy(type,"FLOAT");
        i++;
        while(str[i]!='\0' && str[i]>=0 && str[i]<=9) {
            i++;
        }
        if (str[i]=='\0') {
        return type;
    }
    else {
        strcpy(type,"INVALID");
        return type;
    }
    }
    
}
//end of quadruples code
// Implementation of break and continue
struct construct {
    char start_label[10];
    char stop_label[10];
};

typedef struct construct construct;
construct current_construct;

//end
struct node{
    int nl;
    char name[100];
    char dtype[200];
    int scope;
    int value;
    float fvalue;
    char cvalue;
    char rhs[200];
    char type[100];
    struct node *next;

};
typedef struct node node;
struct list{
    node* head;
};

typedef struct list list1;
struct list* list2 = NULL;

int exists(list1* root, char name[100], int scope){
    if(root == NULL || root->head == NULL){
        return 0;
    }
    node *t2 = root->head;
    while(t2!=NULL){
        if(strcmp(t2->name, name) == 0 && t2->scope == scope){
            
            
            return 1;
        }
        t2 = t2->next;
    }
    t2 = root->head;
    while(t2!=NULL){
    	if(strcmp(t2->name, name)==0){
    		return 1;
    	}
    	t2 = t2->next;
    }
    
    return 0;

}
node* find(list1 *root, char name[200], int scope){
    if(root == NULL || root->head == NULL){
        return NULL;
    }
    node *t2 = root->head;
    while(t2!=NULL){
        if(strcmp(t2->name, name)==0 && t2->scope == scope){return t2;}
        t2 = t2->next;
    }
    t2 = root->head;
    while(t2!=NULL){
    	if(strcmp(t2->name, name)==0){
    		return t2;
    	}
    	t2 = t2->next;
    }
    return t2;

}
node* id_ex;
void insert(list1 *root, int nl, char name[100], char dtype[200], int scope, char rhs[200], char type[100]){
    int out = exists(root, name, scope);
    
    if(out == 0){
    node *temp = (node*)malloc(sizeof(node));
    temp->nl = nl;
    temp->scope = scope;
    strcpy(temp->dtype, dtype);
    strcpy(temp->rhs, rhs);
    strcpy(temp->name, name);
    strcpy(temp->type, type);
    temp->next = NULL;
    if(root->head == NULL){
        root->head = temp;
        return;
    }
    node *t2 = root->head;
    while(t2->next!=NULL){
        t2 = t2->next;
    }
    t2->next = temp;
    return;

}
else{
	errors++;
	printf("Error at line %d: Multiple declarations\n", nl);
}
}

void update(list1 *root, char name[100], int scope,  char rhs[200]){
    node *t2 = root->head;
    if(find(root, name, scope) == NULL){
        return;
    }
    while(strcmp(t2->name, name)!=0){
        t2 = t2->next;
    }
    strcpy(t2->rhs, rhs);
    
    return;
}

void print(node *head){
    // printf("1\n");
    node *temp = head;
    printf("___________________________________________________________________\n");
    fprintf(symtab, "___________________________________________________________________\n");
    printf("|Line      |Name      |Scope     |value     |id_type   |datatype  |\n");
    fprintf(symtab, "|Line      |Name      |Scope     |value     |id_type   |datatype  |\n");
    printf("-------------------------------------------------------------------\n");
    fprintf(symtab, "-------------------------------------------------------------------\n");
    while(temp!=NULL){

        printf("|%-10d|%-10s|%-10d|%-10s|%-10s|%-10s|\n", temp->nl, temp->name, temp->scope, temp->rhs, temp->type, temp->dtype);
        fprintf(symtab, "|%-10d|%-10s|%-10d|%-10s|%-10s|%-10s|\n", temp->nl, temp->name, temp->scope, temp->rhs, temp->type, temp->dtype);      	
        temp=temp->next;
    }

    printf("-------------------------------------------------------------------\n");
    fprintf(symtab, "-------------------------------------------------------------------\n");
}

void reset_scope(list1 *root, int current_scope) {
    if(root == NULL || root->head == NULL){
        return;
    }
    node *t2 = root->head;
    while (t2!=NULL) {
        if(t2->scope > current_scope) {
            t2->scope=-1;
        }
        t2=t2->next;
    }
}

struct expression_details{
    //int value;
    char type[200];
};
typedef struct expression_details exp_det;
exp_det det1;


/* Line 189 of yacc.c  */
#line 419 "int_code.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 345 "int_code.y"





/* Line 209 of yacc.c  */
#line 449 "int_code.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     RETURN = 261,
     VOID = 262,
     INT = 263,
     FLOAT = 264,
     CHAR = 265,
     FOR = 266,
     BREAK = 267,
     CONTINUE = 268,
     INC_OP = 269,
     DEC_OP = 270,
     PLUS = 271,
     MINUS = 272,
     STAR = 273,
     SLASH = 274,
     LT = 275,
     LTEQ = 276,
     GT = 277,
     GTEQ = 278,
     EQ = 279,
     NEQ = 280,
     ASSIGN = 281,
     SEMI = 282,
     COMMA = 283,
     LPAREN = 284,
     RPAREN = 285,
     LSQUAR = 286,
     RSQUAR = 287,
     LBRACE = 288,
     RBRACE = 289,
     LCOMMENT = 290,
     RCOMMENT = 291,
     ID = 292,
     NUM = 293,
     FLT = 294,
     CHR = 295,
     LETTER = 296,
     DIGIT = 297,
     NONTOKEN = 298,
     ERROR = 299,
     ENDFILE = 300,
     NL = 301,
     ENDL = 302,
     STR = 303,
     INSERTION = 304,
     EXTRACTION = 305,
     CIN = 306,
     COUT = 307,
     CLASS = 308,
     PREPROC = 309,
     NEW = 310,
     THEN = 311,
     LOWER_THAN_IF = 312
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 348 "int_code.y"

	char chr;
	int integer;
	float ft;
	char *str;



/* Line 214 of yacc.c  */
#line 532 "int_code.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 544 "int_code.tab.c"

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNRULES -- Number of states.  */
#define YYNSTATES  247

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    16,    21,    23,    26,
      28,    30,    37,    41,    45,    47,    50,    54,    58,    60,
      65,    68,    74,    76,    80,    84,    90,    98,   101,   105,
     110,   112,   114,   116,   118,   120,   123,   126,   131,   136,
     138,   140,   143,   147,   149,   152,   154,   156,   158,   160,
     162,   164,   166,   168,   170,   172,   174,   176,   178,   180,
     182,   186,   189,   193,   198,   203,   205,   207,   209,   211,
     214,   215,   216,   225,   226,   227,   237,   240,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   258,   259,   267,
     270,   274,   276,   278,   279,   280,   281,   294,   296,   301,
     304,   307,   310,   313,   317,   321,   323,   326,   329,   331,
     334,   337,   339,   343,   345,   347,   349,   351,   353,   355,
     357,   361,   365,   368,   371,   373,   375,   379,   383,   388,
     393,   397,   399,   401,   403,   405,   407,   411,   416,   418
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    61,    -1,    60,    61,    -1,
      60,    54,    20,    37,    22,    -1,    54,    20,    37,    22,
      -1,    62,    -1,    60,    62,    -1,    63,    -1,    70,    -1,
      71,    37,    33,    61,    34,    27,    -1,    71,    67,    27,
      -1,    71,    66,    27,    -1,    68,    -1,     1,    27,    -1,
      33,    65,    34,    -1,    38,    28,    65,    -1,    38,    -1,
      37,    31,    38,    32,    -1,    18,    37,    -1,    37,    31,
      32,    26,    64,    -1,    37,    -1,    37,    26,    97,    -1,
      67,    28,    37,    -1,    67,    28,    37,    26,    97,    -1,
      37,    37,    26,    55,    37,    29,    30,    -1,    29,    30,
      -1,    29,    73,    30,    -1,    71,    37,    69,    74,    -1,
       8,    -1,     7,    -1,     9,    -1,    10,    -1,    53,    -1,
       8,    37,    -1,     9,    37,    -1,    72,    28,     8,    37,
      -1,    72,    28,     9,    37,    -1,    72,    -1,     7,    -1,
      33,    34,    -1,    33,    75,    34,    -1,    76,    -1,    75,
      76,    -1,    63,    -1,    77,    -1,    85,    -1,    74,    -1,
      86,    -1,    93,    -1,    96,    -1,    98,    -1,    80,    -1,
      78,    -1,    79,    -1,    12,    -1,    13,    -1,    81,    -1,
      83,    -1,    52,    82,    27,    -1,    49,    84,    -1,    49,
      84,    82,    -1,    49,    84,    49,    47,    -1,    51,    50,
      37,    27,    -1,    38,    -1,    48,    -1,    37,    -1,    27,
      -1,    97,    27,    -1,    -1,    -1,     3,    29,    97,    30,
      87,    77,    88,    89,    -1,    -1,    -1,     4,     3,    29,
      97,    30,    90,    77,    91,    89,    -1,     4,    92,    -1,
      -1,    85,    -1,    74,    -1,    93,    -1,    96,    -1,    98,
      -1,    80,    -1,    78,    -1,    79,    -1,    -1,    -1,     5,
      94,    29,    97,    30,    95,    77,    -1,     6,    27,    -1,
       6,    97,    27,    -1,   104,    -1,   107,    -1,    -1,    -1,
      -1,    11,    99,    29,   102,    27,   100,   107,    27,   103,
      30,   101,    77,    -1,   104,    -1,    71,    37,    26,    97,
      -1,    14,    37,    -1,    15,    37,    -1,    37,    14,    -1,
      37,    15,    -1,    37,    26,    97,    -1,   111,    26,    97,
      -1,   105,    -1,    14,    37,    -1,    15,    37,    -1,   106,
      -1,    37,    14,    -1,    37,    15,    -1,   109,    -1,   109,
     108,   109,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,   110,    -1,   109,    16,   109,
      -1,   109,    17,   109,    -1,    16,   109,    -1,    17,   109,
      -1,   112,    -1,   111,    -1,   110,    18,   110,    -1,   110,
      19,   110,    -1,    37,    31,    38,    32,    -1,    37,    31,
      37,    32,    -1,    29,    97,    30,    -1,    37,    -1,   113,
      -1,    38,    -1,    39,    -1,    48,    -1,    37,    29,    30,
      -1,    37,    29,   114,    30,    -1,    97,    -1,    97,    28,
     114,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   382,   382,   385,   386,   387,   388,   389,   390,   394,
     395,   398,   400,   402,   403,   404,   407,   410,   411,   414,
     415,   416,   421,   427,   444,   451,   472,   498,   499,   503,
     507,   508,   509,   510,   511,   515,   516,   517,   518,   523,
     524,   528,   529,   533,   534,   538,   539,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   555,   567,   579,   580,
     582,   584,   585,   586,   589,   616,   617,   618,   634,   635,
     640,   658,   640,   673,   691,   673,   698,   701,   705,   706,
     707,   708,   709,   710,   711,   712,   716,   724,   716,   751,
     752,   756,   757,   761,   761,   770,   761,   807,   808,   821,
     834,   848,   862,   878,   895,   921,   924,   956,   988,   992,
    1021,  1058,  1059,  1068,  1069,  1070,  1071,  1072,  1073,  1077,
    1079,  1093,  1107,  1108,  1112,  1115,  1116,  1131,  1148,  1166,
    1195,  1196,  1210,  1213,  1217,  1221,  1226,  1227,  1231,  1232
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "RETURN", "VOID",
  "INT", "FLOAT", "CHAR", "FOR", "BREAK", "CONTINUE", "INC_OP", "DEC_OP",
  "PLUS", "MINUS", "STAR", "SLASH", "LT", "LTEQ", "GT", "GTEQ", "EQ",
  "NEQ", "ASSIGN", "SEMI", "COMMA", "LPAREN", "RPAREN", "LSQUAR", "RSQUAR",
  "LBRACE", "RBRACE", "LCOMMENT", "RCOMMENT", "ID", "NUM", "FLT", "CHR",
  "LETTER", "DIGIT", "NONTOKEN", "ERROR", "ENDFILE", "NL", "ENDL", "STR",
  "INSERTION", "EXTRACTION", "CIN", "COUT", "CLASS", "PREPROC", "NEW",
  "THEN", "LOWER_THAN_IF", "$accept", "atree", "program",
  "external_declaration", "class_declaration", "var_declaration",
  "array_init", "comma_list", "array_dec", "init_declarator_list",
  "object_dec", "declarator", "fun_declaration", "declaration_specifiers",
  "params_list", "params", "compound_stmt", "block_item_list",
  "block_item", "statement", "break_stmt", "continue_stmt",
  "stream_constructs", "cout_cascade", "cascade_out", "cin", "op",
  "expression_stmt", "if_stmt", "@1", "$@2", "else_if", "@3", "$@4",
  "else_body", "while_stmt", "@5", "@6", "return_stmt", "expression",
  "for_stmt", "$@7", "@8", "@9", "for_initialiser", "for_update",
  "assignment_expression", "unary_expression", "postfix_expression",
  "simple_expression", "relop", "additive_expression", "term",
  "arrayindex", "factor", "call", "args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    63,    63,    63,    63,    64,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    68,    69,    69,    70,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    79,    80,    80,
      81,    82,    82,    82,    83,    84,    84,    84,    85,    85,
      87,    88,    86,    90,    91,    89,    89,    89,    92,    92,
      92,    92,    92,    92,    92,    92,    94,    95,    93,    96,
      96,    97,    97,    99,   100,   101,    98,   102,   102,   103,
     103,   103,   103,   104,   104,   104,   105,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   110,   110,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     4,     1,     2,     1,
       1,     6,     3,     3,     1,     2,     3,     3,     1,     4,
       2,     5,     1,     3,     3,     5,     7,     2,     3,     4,
       1,     1,     1,     1,     1,     2,     2,     4,     4,     1,
       1,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     4,     4,     1,     1,     1,     1,     2,
       0,     0,     8,     0,     0,     9,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     7,     2,
       3,     1,     1,     0,     0,     0,    12,     1,     4,     2,
       2,     2,     2,     3,     3,     1,     2,     2,     1,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     2,     1,     1,     3,     3,     4,     4,
       3,     1,     1,     1,     1,     1,     3,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    31,    30,    32,    33,     0,    34,     0,     0,
       0,     3,     7,     9,    14,    10,     0,    15,     0,     0,
       1,     0,     4,     8,     0,    22,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,    13,    12,     0,
       0,     6,     0,     0,     0,     0,     0,     0,   131,   133,
     134,   135,    23,    91,   105,   108,    92,   111,   119,   125,
     124,   132,    40,     0,     0,    27,    39,     0,     0,     0,
       0,     0,     0,    29,    24,     0,     5,   106,   107,   131,
     122,   125,   123,     0,   109,   110,     0,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,     0,     0,     0,
       0,    35,    36,     0,    28,     0,    19,     0,    22,     0,
      86,     0,    93,    56,    57,    68,    41,   131,     0,     0,
      45,     0,    48,     0,    43,    46,    54,    55,    53,    58,
      59,    47,    49,    50,    51,     0,    52,     0,     0,   130,
     103,   136,   138,     0,     0,     0,   120,   121,   112,   126,
     127,   104,     0,     0,     0,    21,    11,     0,     0,    89,
       0,     0,     0,     0,     0,    22,    42,    44,    69,    25,
      26,     0,   137,   129,   128,    37,    38,    18,     0,     0,
       0,    90,     0,     0,    67,    65,    66,    61,    60,   139,
       0,    16,    70,     0,     0,     0,     0,    97,     0,    64,
       0,    62,    17,     0,    87,     0,    94,    63,    71,     0,
       0,     0,    77,    88,    98,     0,     0,    72,     0,     0,
      79,    84,    85,    83,    78,    76,    80,    81,    82,     0,
       0,     0,     0,     0,    99,   100,   101,   102,    95,     0,
       0,    73,    96,     0,    74,    77,    75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,   155,   178,    26,    27,
      14,    36,    15,    16,    66,    67,   122,   123,   124,   125,
     126,   127,   128,   129,   164,   130,   187,   131,   132,   203,
     212,   217,   243,   245,   225,   133,   158,   209,   134,   135,
     136,   161,   211,   240,   196,   232,    53,    54,    55,    56,
      97,    57,    58,    59,    60,    61,   143
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
      13,    11,  -113,  -113,  -113,  -113,    16,  -113,    20,    61,
       9,  -113,  -113,  -113,  -113,  -113,   -12,  -113,    63,    40,
    -113,    67,  -113,  -113,    64,   143,   110,    43,    98,   137,
     103,  -113,   238,    35,     3,    23,   132,  -113,  -113,   130,
     131,  -113,   149,   138,   140,   113,   113,   238,   195,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,   314,    91,   153,
    -113,  -113,  -113,   146,   160,  -113,   170,   169,   174,   172,
     171,     8,   179,  -113,   181,   182,  -113,  -113,  -113,    -2,
    -113,  -113,  -113,   185,  -113,  -113,   238,    97,    66,   113,
     113,  -113,  -113,  -113,  -113,  -113,  -113,   113,   125,   125,
     238,  -113,  -113,   107,  -113,   189,  -113,   201,   194,   200,
    -113,   281,  -113,  -113,  -113,  -113,  -113,   129,   184,   187,
    -113,    51,  -113,   232,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,   223,  -113,   238,   221,  -113,
    -113,  -113,   228,   227,   226,   230,  -113,  -113,   102,  -113,
    -113,  -113,   231,   235,   222,  -113,  -113,   238,   234,  -113,
     237,   244,   241,    -1,   247,    47,  -113,  -113,  -113,  -113,
    -113,   238,  -113,  -113,  -113,  -113,  -113,   266,   265,   270,
     238,  -113,    85,   274,  -113,  -113,  -113,   253,  -113,  -113,
     222,  -113,  -113,   277,   188,   267,   279,  -113,   153,  -113,
     109,  -113,  -113,    69,  -113,   285,  -113,  -113,  -113,    69,
     238,   113,   308,  -113,  -113,   289,   276,  -113,    -3,   288,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   284,
     286,   118,   292,   238,  -113,  -113,  -113,  -113,  -113,   295,
      69,  -113,  -113,    69,  -113,   308,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,    -7,   316,   -59,  -113,   142,  -113,  -113,
    -113,  -113,  -113,   -33,  -113,  -113,   -35,  -113,   210,  -112,
     124,   126,   127,  -113,   154,  -113,  -113,   128,  -113,  -113,
    -113,   100,  -113,  -113,  -113,   133,  -113,  -113,   134,   -32,
     135,  -113,  -113,  -113,  -113,  -113,   164,  -113,  -113,   136,
    -113,   -38,    25,   -41,  -113,  -113,   177
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      52,    73,    71,    22,    81,    81,    24,    80,    82,    -2,
       1,   229,   230,   120,     1,    83,     2,     3,     4,     5,
       2,     3,     4,     5,     1,    25,    24,    87,    70,    88,
       2,     3,     4,     5,   231,    68,   184,   185,    17,   121,
      19,    69,    62,    63,    64,   108,     6,   186,    81,    81,
       6,   146,   147,    18,   140,   142,    81,    81,    81,   148,
       6,    20,     7,    21,   120,    65,     7,     8,   151,    24,
      38,    39,   109,    32,   110,   111,     7,    29,    34,   160,
     112,   113,   114,    43,    44,    45,    46,    30,   165,    28,
     121,   208,     2,     3,     4,     5,   115,   213,    47,    43,
      44,    31,    72,   144,   145,   169,    48,    49,    50,    98,
      99,    43,    44,    45,    46,   152,   153,    51,    89,    90,
     118,   119,   194,   149,   150,   179,    47,   141,   242,    45,
      46,   244,   236,   237,    48,    49,    50,    37,     7,   142,
      42,   198,    47,    84,    85,    51,   184,   185,   193,   195,
      79,    49,    50,    40,    47,    86,   207,   186,    87,    41,
      88,    51,    79,    49,    50,    72,    18,    74,    75,    32,
      81,    76,    33,    51,    34,    77,    35,    78,   214,   100,
       1,   220,   109,   101,   110,   111,     2,     3,     4,     5,
     112,   113,   114,    43,    44,    45,    46,   102,   103,   104,
     105,   239,    84,    85,   106,   107,   115,   137,    47,    84,
      85,   138,    72,   116,    86,   139,   117,    49,    50,    88,
      32,    86,   154,    33,    87,    34,    88,    51,   156,   157,
     118,   119,     7,     1,   162,   109,   163,   110,   111,     2,
       3,     4,     5,   112,   113,   114,    43,    44,    45,    46,
     168,   170,    43,    44,    45,    46,   171,   172,   173,   115,
     177,    47,   174,   180,   181,    72,   166,    47,   175,   117,
      49,    50,   176,   182,   188,    48,    49,    50,   183,   219,
      51,   110,   111,   118,   119,     7,    51,   112,   113,   114,
      43,    44,    45,    46,   190,    43,    44,    45,    46,   191,
     192,   199,   200,   115,   205,    47,   206,   204,   159,    72,
      47,   210,   216,    48,    49,    50,   218,   233,    48,    49,
      50,   234,   238,   235,    51,   241,    23,   118,   119,    51,
      89,    90,   202,   167,    91,    92,    93,    94,    95,    96,
     221,   201,   222,   223,   224,   246,   197,   215,   189,   226,
     227,   228
};

static const yytype_uint8 yycheck[] =
{
      32,    36,    35,    10,    45,    46,    18,    45,    46,     0,
       1,    14,    15,    72,     1,    47,     7,     8,     9,    10,
       7,     8,     9,    10,     1,    37,    18,    29,    35,    31,
       7,     8,     9,    10,    37,    32,    37,    38,    27,    72,
      20,    38,     7,     8,     9,    37,    37,    48,    89,    90,
      37,    89,    90,    37,    86,    87,    97,    98,    99,    97,
      37,     0,    53,    54,   123,    30,    53,    54,   100,    18,
      27,    28,     3,    26,     5,     6,    53,    37,    31,   111,
      11,    12,    13,    14,    15,    16,    17,    20,    37,    26,
     123,   203,     7,     8,     9,    10,    27,   209,    29,    14,
      15,    37,    33,    37,    38,   137,    37,    38,    39,    18,
      19,    14,    15,    16,    17,     8,     9,    48,    16,    17,
      51,    52,    37,    98,    99,   157,    29,    30,   240,    16,
      17,   243,    14,    15,    37,    38,    39,    27,    53,   171,
      37,   182,    29,    14,    15,    48,    37,    38,   180,   182,
      37,    38,    39,    55,    29,    26,    47,    48,    29,    22,
      31,    48,    37,    38,    39,    33,    37,    37,    37,    26,
     211,    22,    29,    48,    31,    37,    33,    37,   210,    26,
       1,   216,     3,    37,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    37,    28,    30,
      26,   233,    14,    15,    32,    34,    27,    26,    29,    14,
      15,    29,    33,    34,    26,    30,    37,    38,    39,    31,
      26,    26,    33,    29,    29,    31,    31,    48,    27,    29,
      51,    52,    53,     1,    50,     3,    49,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      27,    30,    14,    15,    16,    17,    28,    30,    32,    27,
      38,    29,    32,    29,    27,    33,    34,    29,    37,    37,
      38,    39,    37,    29,    27,    37,    38,    39,    37,     3,
      48,     5,     6,    51,    52,    53,    48,    11,    12,    13,
      14,    15,    16,    17,    28,    14,    15,    16,    17,    34,
      30,    27,    49,    27,    37,    29,    27,    30,    27,    33,
      29,    26,     4,    37,    38,    39,    27,    29,    37,    38,
      39,    37,    30,    37,    48,    30,    10,    51,    52,    48,
      16,    17,   190,   123,    20,    21,    22,    23,    24,    25,
     216,   187,   216,   216,   216,   245,   182,   211,   171,   216,
     216,   216
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,     9,    10,    37,    53,    54,    59,
      60,    61,    62,    63,    68,    70,    71,    27,    37,    20,
       0,    54,    61,    62,    18,    37,    66,    67,    26,    37,
      20,    37,    26,    29,    31,    33,    69,    27,    27,    28,
      55,    22,    37,    14,    15,    16,    17,    29,    37,    38,
      39,    48,    97,   104,   105,   106,   107,   109,   110,   111,
     112,   113,     7,     8,     9,    30,    72,    73,    32,    38,
      61,    71,    33,    74,    37,    37,    22,    37,    37,    37,
     109,   111,   109,    97,    14,    15,    26,    29,    31,    16,
      17,    20,    21,    22,    23,    24,    25,   108,    18,    19,
      26,    37,    37,    28,    30,    26,    32,    34,    37,     3,
       5,     6,    11,    12,    13,    27,    34,    37,    51,    52,
      63,    71,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    85,    86,    93,    96,    97,    98,    26,    29,    30,
      97,    30,    97,   114,    37,    38,   109,   109,   109,   110,
     110,    97,     8,     9,    33,    64,    27,    29,    94,    27,
      97,    99,    50,    49,    82,    37,    34,    76,    27,    97,
      30,    28,    30,    32,    32,    37,    37,    38,    65,    97,
      29,    27,    29,    37,    37,    38,    48,    84,    27,   114,
      28,    34,    30,    97,    37,    71,   102,   104,   111,    27,
      49,    82,    65,    87,    30,    37,    27,    47,    77,    95,
      26,   100,    88,    77,    97,   107,     4,    89,    27,     3,
      74,    78,    79,    80,    85,    92,    93,    96,    98,    14,
      15,    37,   103,    29,    37,    37,    14,    15,    30,    97,
     101,    30,    77,    90,    77,    91,    89
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
#line 382 "int_code.y"
    {display_three_add(q_list1);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 385 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 386 "int_code.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 387 "int_code.y"
    {printf("%s\n", (yyvsp[(4) - (5)].str));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 388 "int_code.y"
    {printf("%s\n", (yyvsp[(3) - (4)].str));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 389 "int_code.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 390 "int_code.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 394 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 395 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 398 "int_code.y"
    {insert(list2, yylineno, (yyvsp[(2) - (6)].str), "class", scope, " ", "class");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 401 "int_code.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 402 "int_code.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 403 "int_code.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 404 "int_code.y"
    {yyerrok;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 407 "int_code.y"
    {(yyval.str)=(yyvsp[(2) - (3)].str);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 410 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (3)].str);strcat((yyval.str),",");strcat((yyval.str),(yyvsp[(3) - (3)].str));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 411 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 414 "int_code.y"
    {insert(list2, yylineno, (yyvsp[(1) - (4)].str), type, scope, " ", "ARRAY");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 415 "int_code.y"
    {insert(list2, yylineno, (yyvsp[(2) - (2)].str), type, scope, " ", "PTR");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 416 "int_code.y"
    { insert(list2, yylineno, (yyvsp[(1) - (5)].str), "int" , scope, (yyvsp[(5) - (5)].str), "ARRAY");
    									   quadruple * new_record = create_quadruple("ARR","",(yyvsp[(5) - (5)].str),"",(yyvsp[(1) - (5)].str), yylineno);
                            			   insert_quadruple(q_list1,new_record);  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 421 "int_code.y"
    {	id_ex = find(list2, (yyvsp[(1) - (1)].str), scope+1);
    		if(id_ex !=NULL){
    			printf("Error on line %d, multiple definitions\n", yylineno);
    		}
    		else
    		insert(list2, yylineno, (yyvsp[(1) - (1)].str), type, scope, " ", "IDENT");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 427 "int_code.y"
    {
    						id_ex = find(list2, (yyvsp[(1) - (3)].str), scope+1);
    						if(id_ex !=NULL){
    							printf("Error on line %d, multiple definitions\n", yylineno);
    						}
    						else{
                            char arg1[10];
                            sprintf(arg1,"%s",(yyvsp[(3) - (3)].str));
    						quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(1) - (3)].str), yylineno);
                            insert_quadruple(q_list1,new_record); 
                            insert(list2, yylineno, (yyvsp[(1) - (3)].str), type, scope, " ", "IDENT");
                            update(list2, (yyvsp[(1) - (3)].str), scope, (yyvsp[(3) - (3)].str));
                            iflag = 0;
                            fflag = 0;
                            cflag = 0; 
                            }
                        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 444 "int_code.y"
    { id_ex = find(list2, (yyvsp[(3) - (3)].str), scope+1);
    								  if(id_ex !=NULL){
    									printf("Error on line %d, multiple definitions\n", yylineno);
    								}				
    								else
    									insert(list2, yylineno, (yyvsp[(3) - (3)].str), type, scope, " ", "IDENT"); 
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 451 "int_code.y"
    {
    						id_ex = find(list2, (yyvsp[(3) - (5)].str), scope+1);
    					    if(id_ex !=NULL){
    							printf("Error on line %d, multiple definitions\n", yylineno);
    						}
    						else{				
                            char arg1[10];
                            sprintf(arg1,"%s",(yyvsp[(5) - (5)].str));
    						quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(3) - (5)].str), yylineno);
                            insert_quadruple(q_list1,new_record); 
                            insert(list2, yylineno, (yyvsp[(3) - (5)].str), type, scope, " ", "IDENT");
                            update(list2, (yyvsp[(3) - (5)].str), scope, (yyvsp[(5) - (5)].str));
                            iflag = 0;
                            fflag = 0;
                            cflag = 0; 
                            }
                        ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 472 "int_code.y"
    {id_ex = find(list2, (yyvsp[(1) - (7)].str), scope+1);
										 if(id_ex == NULL){
										 	printf("Error in Line %d, %s is not a data type\n", yylineno, (yyvsp[(1) - (7)].str));

										 }
										 else if(strcmp(id_ex->dtype, "class")!=0){
										 	printf("Error in line %d, %s is not a defined type\n", yylineno, (yyvsp[(1) - (7)].str));
										 }
										 else if(strcmp((yyvsp[(1) - (7)].str), (yyvsp[(5) - (7)].str))!=0){
										 	id_ex = find(list2, (yyvsp[(5) - (7)].str), scope+1);
										 	if(id_ex == NULL){
										 		printf("Error in line %d, Unknown identifier\n", yylineno);
										 	}
										 	else if(strcmp(id_ex->dtype, "class")!=0){
										 		printf("Error in line %d, identifier is not a class type\n", yylineno);
										 	}
										 }
										 
										 else if(find(list2, (yyvsp[(2) - (7)].str), scope+1)!=NULL){
										 	printf("Error in line %d, multiple definitions not allowed\n");
										 }
										 else{
										 	insert(list2, yylineno, (yyvsp[(2) - (7)].str), (yyvsp[(1) - (7)].str), scope, " ", "object");
										 }
										 ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 498 "int_code.y"
    {;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 499 "int_code.y"
    {;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 503 "int_code.y"
    {insert(list2, yylineno, (yyvsp[(2) - (4)].str), type, scope, " ", "FUNCT");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 507 "int_code.y"
    {(yyval.str)=integer; strcpy(type, "int");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 508 "int_code.y"
    {(yyval.str)="VOID"; strcpy(type, "void");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 509 "int_code.y"
    {(yyval.str)="float"; strcpy(type, "float");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 510 "int_code.y"
    {(yyval.str)="char"; strcpy(type, "char");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 511 "int_code.y"
    {(yyval.str)="class"; strcpy(type, "class");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 515 "int_code.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 516 "int_code.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 517 "int_code.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 518 "int_code.y"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 523 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 524 "int_code.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 528 "int_code.y"
    {(yyval.str) = "$";;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 529 "int_code.y"
    {(yyval.str) = (yyvsp[(2) - (3)].str); reset_scope(list2,scope);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 533 "int_code.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 534 "int_code.y"
    {(yyval.str) = (yyvsp[(2) - (2)].str);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 538 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 539 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 543 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 544 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 545 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 546 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 547 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 548 "int_code.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 549 "int_code.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 550 "int_code.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 551 "int_code.y"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 555 "int_code.y"
    {
        if (strcmp(current_construct.stop_label,"") !=0) {
            quadruple* new_record;
            new_record = create_quadruple("goto","","","",current_construct.stop_label, yylineno);
            insert_quadruple(q_list1,new_record);
        } else {
            errors++;
            printf("Error in Line %d : Wrong Usage of statement \"break\"...\n", yylineno);
        }
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 567 "int_code.y"
    {
        if (strcmp(current_construct.start_label,"") !=0) {
            quadruple* new_record;
            new_record = create_quadruple("goto","","","",current_construct.start_label, yylineno);
            insert_quadruple(q_list1,new_record);
        } else {
            errors++;
            printf("Error in Line %d : Wrong Usage of statement \"continue\"...\n", yylineno);
        }
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 579 "int_code.y"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 580 "int_code.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 584 "int_code.y"
    {if(errors==0) printf("%s", (yyvsp[(2) - (2)].str));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 585 "int_code.y"
    {if(errors==0) printf("%s", (yyvsp[(2) - (3)].str));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 586 "int_code.y"
    {if(errors==0) printf("%s\n", (yyvsp[(2) - (4)].str));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 589 "int_code.y"
    {
					id_ex = find(list2, (yyvsp[(3) - (4)].str), scope);
					if(id_ex == NULL){
						printf("Error in Line %d : Usage before Declaration\n", yylineno);
						errors++;
					}
					else{
						int a;
						char b;
						float c;
						if(strcmp(id_ex->dtype, "int") == 0){

							scanf("%d", &a);
							id_ex->value = a;
						}
						if(strcmp(id_ex->dtype, "float") == 0){
							scanf("%f", &c);
							id_ex->fvalue = c;
						}
						if(strcmp(id_ex->dtype, "char")==0){
							scanf("%c", &b);
							id_ex->cvalue = b;
						}
					}
					;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 616 "int_code.y"
    {(yyval.str) = yylval.str;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 617 "int_code.y"
    {(yyval.str) = yylval.str;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 618 "int_code.y"
    {
		id_ex = find(list2, (yyvsp[(1) - (1)].str), scope);
		if(id_ex == NULL){
			printf("Error in Line %d : Usage before Declaration\n", yylineno);
			errors++;
		}
		else{
			if(strcmp(id_ex->dtype, "int") == 0) (yyval.integer) = id_ex->value;
			if(strcmp(id_ex->dtype, "float") == 0) (yyval.ft) = id_ex->fvalue;
			if(strcmp(id_ex->dtype, "char") == 0) (yyval.chr) = id_ex->cvalue;

		}

	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 634 "int_code.y"
    {;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 635 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (2)].str);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 640 "int_code.y"
    {
    	quadruple* new_record;
    	
        //Insert Condition
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10],true_label[10],false_label[10];
        sprintf(statement_type,"conditional_goto");
        strcpy(arg1,(yyvsp[(3) - (4)].str));
        
        strcpy(true_label,create_label());
        new_record = create_quadruple(statement_type,arg1,"","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        sprintf(statement_type,"goto");
        strcpy(false_label,create_label());
        new_record = create_quadruple(statement_type,"","","",false_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        (yyval.str)=false_label;
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 658 "int_code.y"
    {
        quadruple* new_record;
        strcpy(if_stmt_skip_label,create_label());
        new_record = create_quadruple("goto","","","",if_stmt_skip_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",(yyvsp[(5) - (6)].str), yylineno);
        insert_quadruple(q_list1,new_record);   
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 665 "int_code.y"
    {
        quadruple* new_record;
        new_record = create_quadruple("label","","","",if_stmt_skip_label, yylineno);
        insert_quadruple(q_list1,new_record);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 673 "int_code.y"
    {
        
        quadruple* new_record;
        //Insert Condition
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10],true_label[10],false_label[10];
        sprintf(statement_type,"conditional_goto");
        strcpy(arg1,(yyvsp[(4) - (5)].str));
        strcpy(true_label,create_label());

        new_record = create_quadruple(statement_type,arg1,"","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        sprintf(statement_type,"goto");
        strcpy(false_label,create_label());
        new_record = create_quadruple(statement_type,"","","",false_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        (yyval.str)=false_label;
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 691 "int_code.y"
    {
        quadruple* new_record;
        new_record = create_quadruple("goto","","","",if_stmt_skip_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",(yyvsp[(6) - (7)].str), yylineno);
        insert_quadruple(q_list1,new_record);   
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 697 "int_code.y"
    {;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 698 "int_code.y"
    {
        //printf("else\n");
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 701 "int_code.y"
    {;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 705 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 706 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 707 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 708 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 709 "int_code.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 710 "int_code.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 711 "int_code.y"
    {;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 712 "int_code.y"
    {;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 716 "int_code.y"
    {
        quadruple* new_record;
        char while_label[10];
        strcpy(while_label,create_label());
        new_record = create_quadruple("label","","","",while_label, yylineno);
        insert_quadruple(q_list1,new_record);
        strcpy(current_construct.start_label,while_label);
        (yyval.str)=while_label;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 724 "int_code.y"
    {
        quadruple* new_record;
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10],true_label[10],false_label[10];
        sprintf(statement_type,"conditional_goto");
        strcpy(arg1,(yyvsp[(4) - (5)].str));
        strcpy(true_label,create_label());
        new_record = create_quadruple(statement_type,arg1,"","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        sprintf(statement_type,"goto");
        strcpy(false_label,create_label());
        new_record = create_quadruple(statement_type,"","","",false_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        strcpy(current_construct.stop_label,false_label);
        new_record = create_quadruple("label","","","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        (yyval.str)=false_label;
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 740 "int_code.y"
    {
        quadruple* new_record = create_quadruple("goto","","","",(yyvsp[(2) - (7)].str), yylineno);
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",(yyvsp[(6) - (7)].str), yylineno);
        insert_quadruple(q_list1,new_record);
        strcpy(current_construct.start_label,"");
        strcpy(current_construct.stop_label,"");
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 751 "int_code.y"
    {;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 752 "int_code.y"
    {;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 756 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 757 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 761 "int_code.y"
    {scope++;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 761 "int_code.y"
    {
        quadruple* new_record;
        char for_label[10];
        strcpy(for_label,create_label());
        new_record = create_quadruple("label","","","",for_label, yylineno);
        insert_quadruple(q_list1,new_record);
        strcpy(current_construct.start_label,for_label);
        (yyval.str)=for_label;
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 770 "int_code.y"
    { 
        quadruple* new_record;
        char break_label[10],body_label[10];
        strcpy(body_label,create_label());
        strcpy(break_label,create_label());
        new_record = create_quadruple("conditional_goto",(yyvsp[(7) - (10)].str),"","",body_label, yylineno);
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("goto","","","",break_label, yylineno);
        insert_quadruple(q_list1,new_record); 
        new_record = create_quadruple("label","","","",body_label, yylineno);
        insert_quadruple(q_list1,new_record);
        strcpy(current_construct.stop_label,break_label);
        (yyval.str)=break_label;
        scope--;
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 784 "int_code.y"
    {
        char update_stmt[20],iterable[20],operator[5],update_value[20],for_label[10];
        strcpy(update_stmt,(yyvsp[(9) - (12)].str));
        strcpy(iterable,strtok(update_stmt, " "));
        strcpy(operator,strtok(NULL," "));
        strcpy(update_value,strtok(NULL," "));
        id_ex = find(list2, iterable, scope+1);
        update(list2, id_ex->name,scope+1,update_stmt);
        quadruple* new_record;
        new_record = create_quadruple("expression",operator,iterable,update_value,iterable, yylineno);
        insert_quadruple(q_list1,new_record);
        strcpy(for_label,(yyvsp[(6) - (12)].str));
        new_record = create_quadruple("goto","","","",for_label, yylineno);
        insert_quadruple(q_list1,new_record); 
        char break_label[10];
        strcpy(break_label,(yyvsp[(11) - (12)].str));
        new_record = create_quadruple("label","","","",break_label, yylineno);
        insert_quadruple(q_list1,new_record); 
        strcpy(current_construct.start_label,"");
        strcpy(current_construct.stop_label,"");
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 807 "int_code.y"
    {;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 808 "int_code.y"
    {
                            char arg1[10];
                            sprintf(arg1,"%s",(yyvsp[(4) - (4)].str));
    						quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(2) - (4)].str), yylineno);
                            insert_quadruple(q_list1,new_record); 
                            insert(list2, yylineno, (yyvsp[(2) - (4)].str), type, scope, " ", "IDENT");
                            update(list2, (yyvsp[(2) - (4)].str), scope, (yyvsp[(4) - (4)].str));
                            iflag = 0;
                            fflag = 0;
                            cflag = 0;
                            ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 821 "int_code.y"
    { 
                    id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                    if(id_ex==NULL){
                        printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                        errors++;
                        }
                    else {                        
                        char increement[20];
                        strcpy(increement,id_ex->name);
                        strcat(increement," + 1");
                        (yyval.str) = increement;
                    }          
                ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 834 "int_code.y"
    { 
                    id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                    if(id_ex==NULL){
                        printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                        errors++;
                        }
                    else {
                        
                        char decreement[20];
                        strcpy(decreement,id_ex->name);
                        strcat(decreement," - 1");
                        (yyval.str) = decreement;
                    }          
                ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 848 "int_code.y"
    { 
                    id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                    if(id_ex==NULL){
                        printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                        errors++;
                        }
                    else {
                        
                        char increement[20];
                        strcpy(increement,id_ex->name);
                        strcat(increement," + 1");
                        (yyval.str) = increement;
                    }          
                ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 862 "int_code.y"
    { 
                    id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                    if(id_ex==NULL){
                        printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                        errors++;
                        }
                    else {
                        char decreement[20];
                        strcpy(decreement,id_ex->name);
                        strcat(decreement," - 1");
                        (yyval.str) = decreement;
                    }          
                ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 878 "int_code.y"
    {
                            char arg1[10],previous_temp[10];
                            strcpy(previous_temp,get_previous_temp()); 
                            sprintf(arg1,"%s",(yyvsp[(3) - (3)].str));
    						quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(1) - (3)].str), yylineno);
                            insert_quadruple(q_list1,new_record); 
                            int ex = exists(list2,(yyvsp[(1) - (3)].str), scope); 
                            if(ex == 0) {printf("Error in Line %d : Assignment before Declaration\n", yylineno); errors++;}
                            id_ex = find(list2, (yyvsp[(1) - (3)].str), scope);
                            update(list2, (yyvsp[(1) - (3)].str), scope, (yyvsp[(3) - (3)].str));
                            iflag = 0;
                            cflag = 0;
                            fflag = 0;
                            

                        ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 895 "int_code.y"
    {
    								char arg1[10], previous_temp[10];
    								strcpy(previous_temp,get_previous_temp()); 
                            		sprintf(arg1,"%s",(yyvsp[(3) - (3)].str));
    								quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(1) - (3)].str), yylineno);
                            		insert_quadruple(q_list1,new_record); 
                            		char id[200];
                            		strcpy(id, "");
                            		int tempcount = 0;
                            		char lhs[200];
                            		strcpy(lhs, (yyvsp[(1) - (3)].str));
                            		while(lhs[tempcount]!='['){
                            			id[tempcount] = lhs[tempcount];
                            			tempcount++;
                            			
                            		}
                            		id[tempcount] = '\0';
                            		int ex = exists(list2,id, scope); 
                            		if(ex == 0) {printf("Error in Line %d : Assignment before Declaration\n", yylineno); errors++;}
                            		id_ex = find(list2, id, scope);
                            		update(list2, id, scope, (yyvsp[(3) - (3)].str));
                            		iflag = 0;
                            		cflag = 0;
                            		fflag = 0;

    					;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 921 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 924 "int_code.y"
    { 
                 id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;
                    }
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{
                    	quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"+",(yyvsp[(2) - (2)].str),"1",(yyvsp[(2) - (2)].str), yylineno); 
        				insert_quadruple(q_list1,new_record);
        				//char te[20];
        				//strcpy(te, "++");
        				//strcat(te, $2);
        				//insert(list2, yylineno, temp,"TEMP", scope, te, "TEMP");
                        char increement[20];
                        strcpy(increement,id_ex->name);
                        strcat(increement,"+1");
        				update(list2, id_ex->name,scope,increement);
                        (yyval.str) = id_ex->rhs;
                        
                    }
                    }
                ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 956 "int_code.y"
    {
                 id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;}
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{
                    	quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"-",(yyvsp[(2) - (2)].str),"1",(yyvsp[(2) - (2)].str), yylineno); 
        				insert_quadruple(q_list1,new_record);
        				char te[20];
        				strcpy(te, "--");
        				strcat(te, (yyvsp[(2) - (2)].str));
        				
        				//insert(list2, yylineno, temp,"TEMP", scope, te, "TEMP");
                        char decreement[20];
                        strcpy(decreement,id_ex->name);
                        strcat(decreement,"+1");
        				update(list2, id_ex->name,scope,decreement);
                        (yyval.str) = id_ex->rhs;                        
                    }
                    }

                ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 988 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 992 "int_code.y"
    {
                 id_ex = find(list2, (yyvsp[(1) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;
                    }
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{
                        quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"+",(yyvsp[(1) - (2)].str),"1",(yyvsp[(1) - (2)].str), yylineno); 
        				insert_quadruple(q_list1,new_record);
        				strcat((yyvsp[(1) - (2)].str), "++");
        				char increement[20];
                        strcpy(increement,id_ex->name);
                        strcat(increement,"+1");
        				//insert(list2, yylineno, temp,"TEMP", scope, $1, "TEMP");
                        (yyval.str) = id_ex->rhs;
        				update(list2, id_ex->name,scope,increement);
                    }
                    }
                ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1021 "int_code.y"
    {
                 id_ex = find(list2, (yyvsp[(1) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;

                    }
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{

                    	quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"-",(yyvsp[(1) - (2)].str),"1",(yyvsp[(1) - (2)].str), yylineno);  
        				insert_quadruple(q_list1,new_record);
        				strcat((yyvsp[(1) - (2)].str), "--");
        				char decreement[20];
                        strcpy(decreement,id_ex->name);
                        strcat(decreement,"+1");
        				//insert(list2, yylineno, temp,"TEMP", scope, $1, "TEMP");
        				(yyval.str) = id_ex->rhs;
        				update(list2, id_ex->name, scope,decreement);
                    }
                        
                    }
                    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1058 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1059 "int_code.y"
    {
    			
				strcat((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
				strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
				(yyval.str) = (yyvsp[(1) - (3)].str);                        
    		;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1068 "int_code.y"
    {(yyval.str) = "<";;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1069 "int_code.y"
    {(yyval.str) = "<=";;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1070 "int_code.y"
    {(yyval.str) = ">";;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1071 "int_code.y"
    {(yyval.str) = ">=";;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1072 "int_code.y"
    {(yyval.str) = "==";;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1073 "int_code.y"
    {(yyval.str) = "!=";;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1077 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);
        ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1079 "int_code.y"
    {        
        quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"+",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        strcat((yyvsp[(1) - (3)].str), "+");
        strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
        (yyval.str) = temp;
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1093 "int_code.y"
    {
    	quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"-",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        strcat((yyvsp[(1) - (3)].str), "-");
        strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
        (yyval.str) = temp;
    	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1107 "int_code.y"
    {(yyval.str) = (yyvsp[(2) - (2)].str);;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1108 "int_code.y"
    {char temp[20];strcpy(temp,"-");strcat(temp,(yyvsp[(2) - (2)].str));(yyval.str) = temp;;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1112 "int_code.y"
    {
              (yyval.str) = (yyvsp[(1) - (1)].str);
            ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1115 "int_code.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1116 "int_code.y"
    {
    	quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"*",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        
    	strcat((yyvsp[(1) - (3)].str), "*");
    	strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    	insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
    	(yyval.str) = temp;
		;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1131 "int_code.y"
    {
    	quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"/",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        
    	strcat((yyvsp[(1) - (3)].str), "/");
    	strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    	insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
    	(yyval.str) = temp;
		;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1148 "int_code.y"
    {
					char lhs[200];
					strcpy(lhs, "");
					strcat(lhs, (yyvsp[(1) - (4)].str));
					strcat(lhs, "[");
					strcat(lhs, (yyvsp[(3) - (4)].str));
					strcat(lhs, "]");
					id_ex = find(list2, (yyvsp[(1) - (4)].str), scope);
					if(id_ex == NULL){
						printf("Error on %d, Assignment RHS not declared\n", yylineno);
            			errors++;
            			(yyval.str) = "$";
					}
					else{
						(yyval.str) = lhs;
						strcpy(det1.type, id_ex->dtype);
					}
					;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1166 "int_code.y"
    {
					char lhs[200];
					strcpy(lhs, "");
					strcat(lhs, (yyvsp[(1) - (4)].str));
					strcat(lhs, "[");
					strcat(lhs, (yyvsp[(3) - (4)].str));
					strcat(lhs, "]");
					id_ex = find(list2, (yyvsp[(3) - (4)].str), scope);
					if(id_ex == NULL){
						printf("Error on %d, Usage before declaration\n", yylineno);
						errors++;
						(yyval.str) = "$";
					}
					else{
					id_ex = find(list2, (yyvsp[(1) - (4)].str), scope);
					if(id_ex == NULL){
						printf("Error on %d, Assignment RHS not declared\n", yylineno);
            			errors++;
            			(yyval.str) = "$";
					}

					else{
						(yyval.str) = lhs;
						strcpy(det1.type, id_ex->dtype);
					}
					}
					;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1195 "int_code.y"
    {(yyval.str)=(yyvsp[(2) - (3)].str); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1196 "int_code.y"
    {
    	  if(yylineno == 1){
    	  	(yyval.str) = (yyvsp[(1) - (1)].str);
    	  }	
    	  else{
          id_ex = find(list2, (yyvsp[(1) - (1)].str), scope);
          if(id_ex == NULL){
            printf("Error on %d, Assignment RHS not declared\n", yylineno);
            errors++;
            (yyval.str) = "$";}
          else{
          	(yyval.str) = (yyvsp[(1) - (1)].str);
            strcpy(det1.type,id_ex->dtype);            
          }};}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1210 "int_code.y"
    {
        (yyval.str)=(yyvsp[(1) - (1)].str);
        ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1213 "int_code.y"
    { 
           (yyval.str) = yylval.str;
           strcpy(det1.type,"int");
           ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1217 "int_code.y"
    {
        (yyval.str) = yylval.str;
        strcpy(det1.type,"float");
    	;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1221 "int_code.y"
    {(yyval.str) = yylval.str;strcpy(det1.type,"string");;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1226 "int_code.y"
    {;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1227 "int_code.y"
    {;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1231 "int_code.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1232 "int_code.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 3553 "int_code.tab.c"
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
#line 1235 "int_code.y"

#include <stdio.h>
int
main(argc, argv)
int argc;
char** argv;
{
//syntree = fopen("syntree.txt", "w");
FILE *fp = fopen("tokens.txt", "w");
icgout = fopen("icg.txt", "w");
symtab = fopen("symtab.txt", "w");
fclose(fp);
if (argc > 1)
{
    FILE *file;
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "failed open");
        exit(1);
    }
    yyin=file;
    //printf("success open %s\n", argv[1]);
}
else
{
    printf("no input file\n");
    exit(1);
}
list2 = (struct list*)malloc(sizeof(struct list));
list2->head = NULL;
q_list1 = (quad_list*)malloc(sizeof(quad_list));
q_list1->head = NULL;
yyparse();  
print(list2->head);
// fclose(syntree);

if(errors>0){
	printf("%d Errors Found\n", errors);
} else {
    //display_three_add(q_list1);
}
fclose(icgout);
fclose(symtab);
return 0; 
} 

void yyerror(const char *s)
{
	fflush(stdout);
	errors++;
	fprintf(stderr, "Error: %s on line number %d\n", s, yylineno);
}




