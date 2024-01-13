/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilator.y"

#include <stdio.h>
int yylex(void);
int yyerror(char* s);
#include <stdlib.h>
#include "tabla.h"
#define MAXNUMBEROFVARIABLES 1024
#define MAXNUMBEROFFUNCTIONS 1024
#define ERR 12312312
struct varTableCell varTable[MAXNUMBEROFVARIABLES];
struct funcTableCell funcTable[MAXNUMBEROFFUNCTIONS];
int nrVar = 0;
int nrFunc = 0;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;



#line 92 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRCPY = 258,                  /* STRCPY  */
    CONST = 259,                   /* CONST  */
    STRCMP = 260,                  /* STRCMP  */
    PRINT = 261,                   /* PRINT  */
    PRINTF = 262,                  /* PRINTF  */
    LIBRARY = 263,                 /* LIBRARY  */
    MAIN = 264,                    /* MAIN  */
    TYPE = 265,                    /* TYPE  */
    NAME = 266,                    /* NAME  */
    VECTOR = 267,                  /* VECTOR  */
    CARACTER = 268,                /* CARACTER  */
    NUMBER = 269,                  /* NUMBER  */
    STRUCT = 270,                  /* STRUCT  */
    ATTRIBUTE = 271,               /* ATTRIBUTE  */
    GT = 272,                      /* GT  */
    LT = 273,                      /* LT  */
    DIF = 274,                     /* DIF  */
    EQUAL = 275,                   /* EQUAL  */
    MULTY = 276,                   /* MULTY  */
    DIV = 277,                     /* DIV  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    IF = 282,                      /* IF  */
    ELSE = 283,                    /* ELSE  */
    FOR = 284,                     /* FOR  */
    WHILE = 285,                   /* WHILE  */
    RETURN = 286                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define STRCPY 258
#define CONST 259
#define STRCMP 260
#define PRINT 261
#define PRINTF 262
#define LIBRARY 263
#define MAIN 264
#define TYPE 265
#define NAME 266
#define VECTOR 267
#define CARACTER 268
#define NUMBER 269
#define STRUCT 270
#define ATTRIBUTE 271
#define GT 272
#define LT 273
#define DIF 274
#define EQUAL 275
#define MULTY 276
#define DIV 277
#define PLUS 278
#define MINUS 279
#define AND 280
#define OR 281
#define IF 282
#define ELSE 283
#define FOR 284
#define WHILE 285
#define RETURN 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "compilator.y"

char strval[2048];
int intval;

#line 212 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRCPY = 3,                     /* STRCPY  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_STRCMP = 5,                     /* STRCMP  */
  YYSYMBOL_PRINT = 6,                      /* PRINT  */
  YYSYMBOL_PRINTF = 7,                     /* PRINTF  */
  YYSYMBOL_LIBRARY = 8,                    /* LIBRARY  */
  YYSYMBOL_MAIN = 9,                       /* MAIN  */
  YYSYMBOL_TYPE = 10,                      /* TYPE  */
  YYSYMBOL_NAME = 11,                      /* NAME  */
  YYSYMBOL_VECTOR = 12,                    /* VECTOR  */
  YYSYMBOL_CARACTER = 13,                  /* CARACTER  */
  YYSYMBOL_NUMBER = 14,                    /* NUMBER  */
  YYSYMBOL_STRUCT = 15,                    /* STRUCT  */
  YYSYMBOL_ATTRIBUTE = 16,                 /* ATTRIBUTE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_DIF = 19,                       /* DIF  */
  YYSYMBOL_EQUAL = 20,                     /* EQUAL  */
  YYSYMBOL_MULTY = 21,                     /* MULTY  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_progr = 40,                     /* progr  */
  YYSYMBOL_libraries = 41,                 /* libraries  */
  YYSYMBOL_st = 42,                        /* st  */
  YYSYMBOL_Dec = 43,                       /* Dec  */
  YYSYMBOL_paramlist = 44,                 /* paramlist  */
  YYSYMBOL_parameter = 45,                 /* parameter  */
  YYSYMBOL_FunctionMain = 46,              /* FunctionMain  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_insList = 48,                   /* insList  */
  YYSYMBOL_insControl = 49,                /* insControl  */
  YYSYMBOL_condition = 50,                 /* condition  */
  YYSYMBOL_ins = 51,                       /* ins  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_FunctionDfn = 53,               /* FunctionDfn  */
  YYSYMBOL_callList = 54,                  /* callList  */
  YYSYMBOL_value = 55                      /* value  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,     2,     2,    37,     2,    38,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    48,    49,    52,    53,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    70,
      71,    74,    78,    81,    82,    85,    86,    87,    88,    92,
      93,    94,    95,    99,   100,   101,   102,   103,   104,   105,
     106,   112,   113,   117,   118,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   149,   150,   151,   152,   153,   154,
     155,   158,   159,   160,   161,   162,   163,   164,   171,   189,
     192,   193,   194,   195,   196,   197,   198,   199,   202
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRCPY", "CONST",
  "STRCMP", "PRINT", "PRINTF", "LIBRARY", "MAIN", "TYPE", "NAME", "VECTOR",
  "CARACTER", "NUMBER", "STRUCT", "ATTRIBUTE", "GT", "LT", "DIF", "EQUAL",
  "MULTY", "DIV", "PLUS", "MINUS", "AND", "OR", "IF", "ELSE", "FOR",
  "WHILE", "RETURN", "'('", "')'", "';'", "'{'", "'}'", "','", "'.'",
  "$accept", "progr", "libraries", "st", "Dec", "paramlist", "parameter",
  "FunctionMain", "block", "insList", "insControl", "condition", "ins",
  "Exp", "FunctionDfn", "callList", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      45,  -109,    26,   122,  -109,    96,  -109,    -3,    58,   283,
      48,   223,    75,    63,  -109,    -4,    72,    94,   130,  -109,
     102,  -109,     6,    11,  -109,   284,   196,  -109,  -109,   151,
    -109,    15,  -109,   284,  -109,  -109,    61,  -109,    18,   116,
     160,   165,   173,    14,   201,   211,   221,  -109,   114,  -109,
     237,   244,  -109,    71,    95,  -109,   265,  -109,    38,    57,
      23,   266,    53,   199,   278,   172,   263,   172,   182,  -109,
     256,  -109,   265,  -109,  -109,  -109,   259,   260,   272,   277,
     285,  -109,    23,   258,   286,    49,  -109,   279,  -109,   288,
    -109,  -109,    90,   300,  -109,  -109,  -109,   172,   212,   289,
     222,   238,   290,  -109,   123,   101,   169,   176,   233,   199,
     262,    23,    23,    23,    23,  -109,  -109,   307,   199,  -109,
     297,   243,   232,   172,   172,   172,   172,   172,   172,   292,
     172,   293,   294,   295,    72,   296,   299,   301,   302,   303,
     304,   305,   306,   124,  -109,   311,  -109,   291,   242,  -109,
     136,   308,  -109,  -109,   309,  -109,  -109,  -109,  -109,  -109,
    -109,   198,   287,   196,   202,   196,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,   199,
     310,     9,   196,    73,   137,  -109,   298,   161,  -109,  -109,
     313,   314,   196,   196,    86,   148,  -109,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     4,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     5,
      13,    14,     0,     0,    12,     0,     0,    22,     6,     0,
       2,     0,    18,     0,    21,     9,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,    27,
       0,     0,    15,     0,     0,    10,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,    25,     0,    16,    17,    20,     0,     0,     0,     0,
      67,    66,     0,     0,     0,    67,    78,    44,    43,    70,
      74,    72,     0,     0,    40,    41,    42,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    62,    64,    61,    63,    57,
       0,    71,    75,    73,    56,    54,    39,    33,    34,    35,
      36,    37,    38,     0,     0,     0,    23,    24,    69,    45,
      46,    48,    47,    49,    50,    52,    51,    68,    76,     0,
       0,     0,     0,     0,     0,    55,    29,     0,    31,    77,
       0,     0,     0,     0,     0,     0,    30,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,    17,     2,   -25,   269,  -109,   188,    16,
     -45,   -65,   -48,   -39,  -109,  -108,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     9,    47,    36,    37,    18,    27,    48,
      49,    98,    50,    83,    30,    92,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,   143,   100,    69,   102,    10,    53,    24,    13,    14,
     150,    17,    39,     5,    40,    41,    42,    32,    99,     7,
      43,    34,     5,    87,     8,    34,     4,    10,     7,   101,
      62,    25,   122,     8,    80,    10,    44,    81,    45,    46,
      17,    33,    38,   110,    35,   186,    63,   104,    52,    76,
      54,    77,    64,     1,    57,    82,    17,   155,   157,   158,
     159,   160,   161,   162,    85,   164,    86,    81,    78,    15,
      79,   184,   145,   146,   147,   148,    39,     5,    40,    41,
      42,   109,    19,     7,    43,    82,    22,   117,     8,    39,
       5,    40,    41,    42,    55,    23,     7,    43,    56,     5,
      44,     8,    45,    46,    73,     7,    11,    26,    56,   188,
       8,    12,   135,    44,   136,    45,    46,    39,     5,    40,
      41,    42,   196,   119,     7,    43,     5,   120,    28,     8,
       6,    74,     7,    70,    31,    70,    69,     8,    69,    70,
      29,    44,    69,    45,    46,    68,    70,    70,    58,    69,
      69,    39,     5,    40,    41,    42,   134,   177,     7,    43,
      56,   120,    51,     8,    39,     5,    40,    41,    42,   178,
     189,     7,    43,   120,   120,    44,     8,    45,    46,   181,
     137,   183,   138,    94,   197,    95,    96,   139,    44,   140,
      45,    46,    59,    80,   191,    86,    81,    60,   187,    39,
       5,    40,    41,    42,    97,    61,     7,    43,   194,   195,
      89,     8,    90,    91,    82,   123,   124,   125,   126,   123,
     124,   125,   126,    44,   128,    45,    46,   127,   128,   123,
     124,   125,   126,    65,    20,    21,   182,   127,   128,   123,
     124,   125,   126,    66,   141,   129,   142,   127,   128,   123,
     124,   125,   126,    67,   154,   131,    86,   127,   128,   111,
     112,   113,   114,   111,   112,   156,    39,     5,    40,    41,
      42,    71,   132,     7,    43,    34,    72,    84,     8,   111,
     112,   113,   114,   111,   112,   113,   114,     5,     5,    93,
     103,   115,    16,     7,     7,   144,   105,   106,     8,     8,
     111,   112,   113,   114,   123,   124,   125,   126,   151,   107,
     152,   153,   111,   112,   108,   114,   121,   109,   149,   116,
     118,   185,   168,   130,   133,    75,   190,   163,   165,   169,
     166,   167,   170,   112,   171,   172,   173,   174,   175,   176,
     179,     0,     0,     0,     0,     0,     0,   180,   192,   193
};

static const yytype_int16 yycheck[] =
{
      48,   109,    67,    48,    68,     3,    31,    11,    11,    12,
     118,     9,     3,     4,     5,     6,     7,    11,    66,    10,
      11,    10,     4,    62,    15,    10,     0,    25,    10,    68,
      16,    35,    97,    15,    11,    33,    27,    14,    29,    30,
      38,    35,    25,    82,    33,    36,    32,    72,    33,    11,
      33,    13,    38,     8,    36,    32,    54,   121,   123,   124,
     125,   126,   127,   128,    11,   130,    13,    14,    11,    11,
      13,   179,   111,   112,   113,   114,     3,     4,     5,     6,
       7,    32,    34,    10,    11,    32,    11,    38,    15,     3,
       4,     5,     6,     7,    33,    32,    10,    11,    37,     4,
      27,    15,    29,    30,    33,    10,    10,    35,    37,    36,
      15,    15,    11,    27,    13,    29,    30,     3,     4,     5,
       6,     7,    36,    33,    10,    11,     4,    37,    34,    15,
       8,    36,    10,   181,    32,   183,   181,    15,   183,   187,
      10,    27,   187,    29,    30,    31,   194,   195,    32,   194,
     195,     3,     4,     5,     6,     7,    33,    33,    10,    11,
      37,    37,    11,    15,     3,     4,     5,     6,     7,    33,
      33,    10,    11,    37,    37,    27,    15,    29,    30,   163,
      11,   165,    13,    11,    36,    13,    14,    11,    27,    13,
      29,    30,    32,    11,    33,    13,    14,    32,   182,     3,
       4,     5,     6,     7,    32,    32,    10,    11,   192,   193,
      11,    15,    13,    14,    32,    17,    18,    19,    20,    17,
      18,    19,    20,    27,    26,    29,    30,    25,    26,    17,
      18,    19,    20,    32,    11,    12,    34,    25,    26,    17,
      18,    19,    20,    32,    11,    33,    13,    25,    26,    17,
      18,    19,    20,    32,    11,    33,    13,    25,    26,    21,
      22,    23,    24,    21,    22,    33,     3,     4,     5,     6,
       7,    34,    34,    10,    11,    10,    32,    11,    15,    21,
      22,    23,    24,    21,    22,    23,    24,     4,     4,    11,
      34,    33,     9,    10,    10,    33,    37,    37,    15,    15,
      21,    22,    23,    24,    17,    18,    19,    20,    11,    37,
      13,    14,    21,    22,    37,    24,    16,    32,    11,    33,
      32,    11,   134,    34,    34,    56,    28,    35,    35,    33,
      36,    36,    33,    22,    33,    33,    33,    33,    33,    33,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    38,    35,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    40,    41,     0,     4,     8,    10,    15,    42,
      43,    10,    15,    11,    12,    11,     9,    43,    46,    34,
      11,    12,    11,    32,    11,    35,    35,    47,    34,    10,
      53,    32,    11,    35,    10,    33,    44,    45,    42,     3,
       5,     6,     7,    11,    27,    29,    30,    43,    48,    49,
      51,    11,    33,    44,    42,    33,    37,    36,    32,    32,
      32,    32,    16,    32,    38,    32,    32,    32,    31,    49,
      51,    34,    32,    33,    36,    45,    11,    13,    11,    13,
      11,    14,    32,    52,    11,    11,    13,    52,    55,    11,
      13,    14,    54,    11,    11,    13,    14,    32,    50,    51,
      50,    52,    55,    34,    44,    37,    37,    37,    37,    32,
      52,    21,    22,    23,    24,    33,    33,    38,    32,    33,
      37,    16,    50,    17,    18,    19,    20,    25,    26,    33,
      34,    33,    34,    34,    33,    11,    13,    11,    13,    11,
      13,    11,    13,    54,    33,    52,    52,    52,    52,    11,
      54,    11,    13,    14,    11,    55,    33,    50,    50,    50,
      50,    50,    50,    35,    50,    35,    36,    36,    47,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    32,
      38,    48,    34,    48,    54,    11,    36,    48,    36,    33,
      28,    33,    35,    35,    48,    48,    36,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      44,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     2,     3,     2,     2,     4,
       5,     5,     3,     3,     3,     5,     6,     6,     4,     1,
       3,     1,     2,     6,     6,     2,     3,     1,     2,     7,
      11,     7,    11,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     3,     6,     6,     6,     6,     6,
       6,     6,     6,     4,     5,     7,     5,     5,     1,     4,
       4,     3,     3,     3,     3,     3,     1,     1,     4,     6,
       1,     3,     1,     3,     1,     3,     4,     6,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* progr: libraries st FunctionMain FunctionDfn  */
#line 45 "compilator.y"
                                             {printf("\n\n\n");}
#line 1389 "y.tab.c"
    break;

  case 7: /* Dec: TYPE NAME  */
#line 56 "compilator.y"
                 { int res = addVarTable((yyvsp[-1].strval), (yyvsp[0].strval), nrVar, varTable); if (res == 0) {printf(" "); } else {nrVar++;} }
#line 1395 "y.tab.c"
    break;

  case 10: /* Dec: TYPE NAME '(' paramlist ')'  */
#line 59 "compilator.y"
                                          { addFuncTable((yyvsp[-3].strval), (yyvsp[-4].strval), (yyvsp[-1].strval), nrFunc++,funcTable, 0); }
#line 1401 "y.tab.c"
    break;

  case 19: /* paramlist: parameter  */
#line 70 "compilator.y"
                      { for (int i = 0; i < 2048; i++) { (yyval.strval)[i] = (yyvsp[0].strval)[i];} }
#line 1407 "y.tab.c"
    break;

  case 20: /* paramlist: paramlist ',' parameter  */
#line 71 "compilator.y"
                                           { char s[2048]; strcpy(s, (yyvsp[-2].strval)); strcat(s, " "); strcat(s, (yyvsp[0].strval)); for (int i = 0; i < 2048; i++) { (yyval.strval)[i] = s[i];} }
#line 1413 "y.tab.c"
    break;

  case 40: /* condition: NAME  */
#line 106 "compilator.y"
                { 
            int pos = posVarTable((yyvsp[0].strval), varTable, nrVar);
            if (pos == -1) {
              printf("La variable %s no fue declarada! Linea: %d\n", (yyvsp[0].strval), yylineno);
            }
         }
#line 1424 "y.tab.c"
    break;

  case 43: /* ins: NAME ATTRIBUTE value  */
#line 117 "compilator.y"
                          { if (setValue((yyvsp[-2].strval), (yyvsp[0].strval), varTable, nrVar) == 1) printf(" "); else printf("Error en la linea %d\n", yylineno); }
#line 1430 "y.tab.c"
    break;

  case 44: /* ins: NAME ATTRIBUTE Exp  */
#line 118 "compilator.y"
                                 { 
                char buff[2048];
                int resultado = (yyvsp[0].intval);
                sprintf(buff, "%d", resultado);
                if (setValue((yyvsp[-2].strval), buff, varTable, nrVar) && (yyvsp[0].intval) != ERR) 
                    printf(" "); 
                else printf("Error en la linea %d\n", yylineno);
            }
#line 1443 "y.tab.c"
    break;

  case 53: /* ins: NAME '(' callList ')'  */
#line 134 "compilator.y"
                                    {int res; 
                if ((res = checkFunc((yyvsp[-3].strval), (yyvsp[-1].strval), funcTable, varTable, nrFunc, nrVar)) == 1) {  printf(" "); } 
                else { printf("La funcion de la linea %d no es valida. Error: %d\n", yylineno, res); } 
                if (res == 1) { 
                        int pos = -1;
                        for (int i = 0; i < nrFunc; i++) {
                                if (strcmp(funcTable[i].name, (yyvsp[-3].strval)) == 0) {
                                        pos = i;
                                        break;
                                }
                        }
                        if (funcTable[pos].reserved == 1) {
                                printf("%d\n", execReservedFunc(pos,(yyvsp[-1].strval) ,varTable, nrVar, funcTable, nrFunc));
                        }
                } }
#line 1463 "y.tab.c"
    break;

  case 59: /* ins: PRINT '(' Exp ')'  */
#line 154 "compilator.y"
                                { printf("%d\n",(yyvsp[-1].intval)); }
#line 1469 "y.tab.c"
    break;

  case 60: /* ins: PRINTF '(' NAME ')'  */
#line 155 "compilator.y"
                                  { print((yyvsp[-1].strval), varTable, nrVar); printf("\n");}
#line 1475 "y.tab.c"
    break;

  case 61: /* Exp: Exp PLUS Exp  */
#line 158 "compilator.y"
                  { (yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval); }
#line 1481 "y.tab.c"
    break;

  case 62: /* Exp: Exp MULTY Exp  */
#line 159 "compilator.y"
                         { (yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval); }
#line 1487 "y.tab.c"
    break;

  case 63: /* Exp: Exp MINUS Exp  */
#line 160 "compilator.y"
                        { (yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval); }
#line 1493 "y.tab.c"
    break;

  case 64: /* Exp: Exp DIV Exp  */
#line 161 "compilator.y"
                      { (yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval); }
#line 1499 "y.tab.c"
    break;

  case 65: /* Exp: '(' Exp ')'  */
#line 162 "compilator.y"
                      { (yyval.intval) = (yyvsp[-1].intval); }
#line 1505 "y.tab.c"
    break;

  case 66: /* Exp: NUMBER  */
#line 163 "compilator.y"
                 { (yyval.intval) = atoi((yyvsp[0].strval)); }
#line 1511 "y.tab.c"
    break;

  case 67: /* Exp: NAME  */
#line 164 "compilator.y"
               { int poz = posVarTable((yyvsp[0].strval), varTable, nrVar); 
                if (poz == -1) { printf("La variable %s no existe! Linea: %d\n", (yyvsp[0].strval), yylineno); (yyval.intval) = ERR;}
                else {
                  if (varTable[poz].initialized == 0) { printf("La variable %s no fue inicializada!\n", (yyvsp[0].strval)); (yyval.intval) = ERR; }
                  if (strcmp(varTable[poz].currentVar.type, "int") != 0) {printf("Error! expresion invalida! Linea: %d\n",yylineno); (yyval.intval) = ERR;}
                  else { (yyval.intval) = *((int *)(varTable[poz].address)); } }
                }
#line 1523 "y.tab.c"
    break;

  case 68: /* Exp: NAME '(' callList ')'  */
#line 171 "compilator.y"
                                {int res; 
                if ((res = checkFunc((yyvsp[-3].strval), (yyvsp[-1].strval), funcTable, varTable, nrFunc, nrVar)) == 1) {  printf(" "); } 
                else { printf("La funcion en la linea %d no es valida. Error: %d\n", yylineno, res); } 
                if (res == 1) { 
                        int pos = -1;
                        for (int i = 0; i < nrFunc; i++) {
                                if (strcmp(funcTable[i].name, (yyvsp[-3].strval)) == 0) {
                                        pos = i;
                                        break;
                                }
                        }
                        if (funcTable[pos].reserved == 1) {
                                (yyval.intval) = execReservedFunc(pos,(yyvsp[-1].strval) ,varTable, nrVar, funcTable, nrFunc);
                        }
                } }
#line 1543 "y.tab.c"
    break;

  case 70: /* callList: NAME  */
#line 192 "compilator.y"
                { for (int i = 0; i < 2048; i++) { (yyval.strval)[i] = (yyvsp[0].strval)[i];} }
#line 1549 "y.tab.c"
    break;

  case 71: /* callList: callList ',' NAME  */
#line 193 "compilator.y"
                                     { char s[2048]; strcpy(s, (yyvsp[-2].strval)); strcat(s, " "); strcat(s , (yyvsp[0].strval));  for (int i = 0; i < 2048; i++) { (yyval.strval)[i] = s[i];}}
#line 1555 "y.tab.c"
    break;

  case 78: /* value: CARACTER  */
#line 202 "compilator.y"
                  { for (int i = 0; i < 2048; i++) { (yyval.strval)[i] = (yyvsp[0].strval)[i];} }
#line 1561 "y.tab.c"
    break;


#line 1565 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 205 "compilator.y"

int yyerror(char * s){

}

int main(int argc, char** argv){

        addFuncTable("maximum", "int", "int int", nrFunc++, funcTable, 1);
        addFuncTable("minimum", "int", "int int", nrFunc++, funcTable, 1);
        yyin=fopen(argv[1],"r");
        yyparse();

        freopen("status.txt", "w", stdout);
        printf("La funcion ha sido declarada en el programa: \n\n");
        for (int i = 0; i < nrFunc; i++) {
                printf("Funcion %d\n", i);
                printf("Nombre: %s\n", funcTable[i].name);
                printf("Tipo de retorno: %s\n", funcTable[i].typeReturn);
                printf("Funcion reservada: %d\n", funcTable[i].reserved);
                for (int j = 0; j < funcTable[i].numberParam; j++) {
                        printf("Tipo de parametro %d: %s\n", j, funcTable[i].typeParam[j]);
                }
                printf("\n");
        }

        printf("\n");

        printf("situacion de las variables declaradas en el programa:\n");
        for (int i = 0; i < nrVar; i++) {
                struct var v;
                v = varTable[i].currentVar;
                printf("Nombre: %s\n", v.name);
                printf("Tipo: %s\n", v.type);
                print(v.name, varTable, nrVar);
                printf("\n");
        }
}
