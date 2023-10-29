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


/* Substitute the variable and function names.  */
#define yyparse         FAUSTparse
#define yylex           FAUSTlex
#define yyerror         FAUSTerror
#define yydebug         FAUSTdebug
#define yynerrs         FAUSTnerrs
#define yylval          FAUSTlval
#define yychar          FAUSTchar

/* First part of user prologue.  */
#line 5 "faustparser.y"


#include "global.hh"

#include "tree.hh"
#include "xtended.hh"
#include "boxes.hh"
#include "prim2.hh"
#include "signals.hh"
#include "errormsg.hh"
#include "sourcereader.hh"
#include "doc.hh"
#include "ppbox.hh"

#include <string>
#include <list>

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYMAXDEPTH    100000
    
using namespace std;

extern char*        FAUSTtext;
extern const char*  FAUSTfilename;
extern int          FAUSTlineno;
extern int          FAUSTerr;

int FAUSTlex();

//----------------------------------------------------------
// unquote() : remove enclosing quotes and carriage return 
// characters from string. Returns a Tree 
//----------------------------------------------------------
inline char replaceCR(char c)
{
    return (c!='\n') ? c : ' ';
}

//----------------------------------------------------------
// A definition is accepted if the prefixset is empty or if
// the current float precision is member of the prefix set
//----------------------------------------------------------
inline bool acceptdefinition(int prefixset)
{
    int precisions[] = {0, 1, 2, 4, 8};
    return (prefixset==0) || (prefixset & precisions[gGlobal->gFloatSize]);
}
    
//----------------------------------------------------------
// 'atoi' does not work correctly on Windows with MSVC on values
// greater than 2^31 (= 2147483648)
//----------------------------------------------------------
inline int str2int(const char* str)
{
    int result = 0;
    while (*str != 0) {
        result = result * 10 + *str - '0';
        str++;
    }
    return result;
}

inline Tree unquote(char* str)
{
    size_t size = strlen(str) + 1;
    
    //-----------copy unquoted filename-------------
    char* buf = (char*)alloca(size);
    size_t j=0;

    if (str[0] == '"') {
        // it is a quoted string, we remove the quotes
        for (size_t i=1; j<size-1 && str[i];) {
            buf[j++] = replaceCR(str[i++]);
        }
        // remove last quote
        if (j>0) buf[j-1] = 0;
    } else {
        for (size_t i=0; j<size-1 && str[i];) {
            buf[j++] = replaceCR(str[i++]);
        }
    }
    buf[j] = 0;

    return tree(buf);
    //----------------------------------------------
}


#line 169 "faustparser.cpp"

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

#include "faustparser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SPLIT = 3,                      /* SPLIT  */
  YYSYMBOL_MIX = 4,                        /* MIX  */
  YYSYMBOL_SEQ = 5,                        /* SEQ  */
  YYSYMBOL_PAR = 6,                        /* PAR  */
  YYSYMBOL_REC = 7,                        /* REC  */
  YYSYMBOL_LT = 8,                         /* LT  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_ADD = 14,                       /* ADD  */
  YYSYMBOL_SUB = 15,                       /* SUB  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_XOR = 21,                       /* XOR  */
  YYSYMBOL_LSH = 22,                       /* LSH  */
  YYSYMBOL_RSH = 23,                       /* RSH  */
  YYSYMBOL_POWOP = 24,                     /* POWOP  */
  YYSYMBOL_FDELAY = 25,                    /* FDELAY  */
  YYSYMBOL_DELAY1 = 26,                    /* DELAY1  */
  YYSYMBOL_MEM = 27,                       /* MEM  */
  YYSYMBOL_PREFIX = 28,                    /* PREFIX  */
  YYSYMBOL_INTCAST = 29,                   /* INTCAST  */
  YYSYMBOL_FLOATCAST = 30,                 /* FLOATCAST  */
  YYSYMBOL_NOTYPECAST = 31,                /* NOTYPECAST  */
  YYSYMBOL_FFUNCTION = 32,                 /* FFUNCTION  */
  YYSYMBOL_FCONSTANT = 33,                 /* FCONSTANT  */
  YYSYMBOL_FVARIABLE = 34,                 /* FVARIABLE  */
  YYSYMBOL_BUTTON = 35,                    /* BUTTON  */
  YYSYMBOL_CHECKBOX = 36,                  /* CHECKBOX  */
  YYSYMBOL_VSLIDER = 37,                   /* VSLIDER  */
  YYSYMBOL_HSLIDER = 38,                   /* HSLIDER  */
  YYSYMBOL_NENTRY = 39,                    /* NENTRY  */
  YYSYMBOL_VGROUP = 40,                    /* VGROUP  */
  YYSYMBOL_HGROUP = 41,                    /* HGROUP  */
  YYSYMBOL_TGROUP = 42,                    /* TGROUP  */
  YYSYMBOL_HBARGRAPH = 43,                 /* HBARGRAPH  */
  YYSYMBOL_VBARGRAPH = 44,                 /* VBARGRAPH  */
  YYSYMBOL_SOUNDFILE = 45,                 /* SOUNDFILE  */
  YYSYMBOL_ATTACH = 46,                    /* ATTACH  */
  YYSYMBOL_ACOS = 47,                      /* ACOS  */
  YYSYMBOL_ASIN = 48,                      /* ASIN  */
  YYSYMBOL_ATAN = 49,                      /* ATAN  */
  YYSYMBOL_ATAN2 = 50,                     /* ATAN2  */
  YYSYMBOL_COS = 51,                       /* COS  */
  YYSYMBOL_SIN = 52,                       /* SIN  */
  YYSYMBOL_TAN = 53,                       /* TAN  */
  YYSYMBOL_EXP = 54,                       /* EXP  */
  YYSYMBOL_LOG = 55,                       /* LOG  */
  YYSYMBOL_LOG10 = 56,                     /* LOG10  */
  YYSYMBOL_POWFUN = 57,                    /* POWFUN  */
  YYSYMBOL_SQRT = 58,                      /* SQRT  */
  YYSYMBOL_ABS = 59,                       /* ABS  */
  YYSYMBOL_MIN = 60,                       /* MIN  */
  YYSYMBOL_MAX = 61,                       /* MAX  */
  YYSYMBOL_FMOD = 62,                      /* FMOD  */
  YYSYMBOL_REMAINDER = 63,                 /* REMAINDER  */
  YYSYMBOL_FLOOR = 64,                     /* FLOOR  */
  YYSYMBOL_CEIL = 65,                      /* CEIL  */
  YYSYMBOL_RINT = 66,                      /* RINT  */
  YYSYMBOL_ROUND = 67,                     /* ROUND  */
  YYSYMBOL_RDTBL = 68,                     /* RDTBL  */
  YYSYMBOL_RWTBL = 69,                     /* RWTBL  */
  YYSYMBOL_SELECT2 = 70,                   /* SELECT2  */
  YYSYMBOL_SELECT3 = 71,                   /* SELECT3  */
  YYSYMBOL_INT = 72,                       /* INT  */
  YYSYMBOL_FLOAT = 73,                     /* FLOAT  */
  YYSYMBOL_MODULATE = 74,                  /* MODULATE  */
  YYSYMBOL_LAMBDA = 75,                    /* LAMBDA  */
  YYSYMBOL_DOT = 76,                       /* DOT  */
  YYSYMBOL_WIRE = 77,                      /* WIRE  */
  YYSYMBOL_CUT = 78,                       /* CUT  */
  YYSYMBOL_ENDDEF = 79,                    /* ENDDEF  */
  YYSYMBOL_VIRG = 80,                      /* VIRG  */
  YYSYMBOL_LPAR = 81,                      /* LPAR  */
  YYSYMBOL_RPAR = 82,                      /* RPAR  */
  YYSYMBOL_LBRAQ = 83,                     /* LBRAQ  */
  YYSYMBOL_RBRAQ = 84,                     /* RBRAQ  */
  YYSYMBOL_LCROC = 85,                     /* LCROC  */
  YYSYMBOL_RCROC = 86,                     /* RCROC  */
  YYSYMBOL_WITH = 87,                      /* WITH  */
  YYSYMBOL_LETREC = 88,                    /* LETREC  */
  YYSYMBOL_WHERE = 89,                     /* WHERE  */
  YYSYMBOL_DEF = 90,                       /* DEF  */
  YYSYMBOL_IMPORT = 91,                    /* IMPORT  */
  YYSYMBOL_COMPONENT = 92,                 /* COMPONENT  */
  YYSYMBOL_LIBRARY = 93,                   /* LIBRARY  */
  YYSYMBOL_ENVIRONMENT = 94,               /* ENVIRONMENT  */
  YYSYMBOL_WAVEFORM = 95,                  /* WAVEFORM  */
  YYSYMBOL_ROUTE = 96,                     /* ROUTE  */
  YYSYMBOL_ENABLE = 97,                    /* ENABLE  */
  YYSYMBOL_CONTROL = 98,                   /* CONTROL  */
  YYSYMBOL_IPAR = 99,                      /* IPAR  */
  YYSYMBOL_ISEQ = 100,                     /* ISEQ  */
  YYSYMBOL_ISUM = 101,                     /* ISUM  */
  YYSYMBOL_IPROD = 102,                    /* IPROD  */
  YYSYMBOL_INPUTS = 103,                   /* INPUTS  */
  YYSYMBOL_OUTPUTS = 104,                  /* OUTPUTS  */
  YYSYMBOL_STRING = 105,                   /* STRING  */
  YYSYMBOL_FSTRING = 106,                  /* FSTRING  */
  YYSYMBOL_IDENT = 107,                    /* IDENT  */
  YYSYMBOL_EXTRA = 108,                    /* EXTRA  */
  YYSYMBOL_DECLARE = 109,                  /* DECLARE  */
  YYSYMBOL_CASE = 110,                     /* CASE  */
  YYSYMBOL_ARROW = 111,                    /* ARROW  */
  YYSYMBOL_ASSERTBOUNDS = 112,             /* ASSERTBOUNDS  */
  YYSYMBOL_LOWEST = 113,                   /* LOWEST  */
  YYSYMBOL_HIGHEST = 114,                  /* HIGHEST  */
  YYSYMBOL_FLOATMODE = 115,                /* FLOATMODE  */
  YYSYMBOL_DOUBLEMODE = 116,               /* DOUBLEMODE  */
  YYSYMBOL_QUADMODE = 117,                 /* QUADMODE  */
  YYSYMBOL_FIXEDPOINTMODE = 118,           /* FIXEDPOINTMODE  */
  YYSYMBOL_BDOC = 119,                     /* BDOC  */
  YYSYMBOL_EDOC = 120,                     /* EDOC  */
  YYSYMBOL_BEQN = 121,                     /* BEQN  */
  YYSYMBOL_EEQN = 122,                     /* EEQN  */
  YYSYMBOL_BDGM = 123,                     /* BDGM  */
  YYSYMBOL_EDGM = 124,                     /* EDGM  */
  YYSYMBOL_BLST = 125,                     /* BLST  */
  YYSYMBOL_ELST = 126,                     /* ELST  */
  YYSYMBOL_BMETADATA = 127,                /* BMETADATA  */
  YYSYMBOL_EMETADATA = 128,                /* EMETADATA  */
  YYSYMBOL_DOCCHAR = 129,                  /* DOCCHAR  */
  YYSYMBOL_NOTICE = 130,                   /* NOTICE  */
  YYSYMBOL_LISTING = 131,                  /* LISTING  */
  YYSYMBOL_LSTTRUE = 132,                  /* LSTTRUE  */
  YYSYMBOL_LSTFALSE = 133,                 /* LSTFALSE  */
  YYSYMBOL_LSTDEPENDENCIES = 134,          /* LSTDEPENDENCIES  */
  YYSYMBOL_LSTMDOCTAGS = 135,              /* LSTMDOCTAGS  */
  YYSYMBOL_LSTDISTRIBUTED = 136,           /* LSTDISTRIBUTED  */
  YYSYMBOL_LSTEQ = 137,                    /* LSTEQ  */
  YYSYMBOL_LSTQ = 138,                     /* LSTQ  */
  YYSYMBOL_YYACCEPT = 139,                 /* $accept  */
  YYSYMBOL_program = 140,                  /* program  */
  YYSYMBOL_stmtlist = 141,                 /* stmtlist  */
  YYSYMBOL_deflist = 142,                  /* deflist  */
  YYSYMBOL_variantlist = 143,              /* variantlist  */
  YYSYMBOL_variant = 144,                  /* variant  */
  YYSYMBOL_reclist = 145,                  /* reclist  */
  YYSYMBOL_vallist = 146,                  /* vallist  */
  YYSYMBOL_number = 147,                   /* number  */
  YYSYMBOL_statement = 148,                /* statement  */
  YYSYMBOL_doc = 149,                      /* doc  */
  YYSYMBOL_docelem = 150,                  /* docelem  */
  YYSYMBOL_doctxt = 151,                   /* doctxt  */
  YYSYMBOL_doceqn = 152,                   /* doceqn  */
  YYSYMBOL_docdgm = 153,                   /* docdgm  */
  YYSYMBOL_docntc = 154,                   /* docntc  */
  YYSYMBOL_doclst = 155,                   /* doclst  */
  YYSYMBOL_lstattrlist = 156,              /* lstattrlist  */
  YYSYMBOL_lstattrdef = 157,               /* lstattrdef  */
  YYSYMBOL_lstattrval = 158,               /* lstattrval  */
  YYSYMBOL_docmtd = 159,                   /* docmtd  */
  YYSYMBOL_definition = 160,               /* definition  */
  YYSYMBOL_recinition = 161,               /* recinition  */
  YYSYMBOL_defname = 162,                  /* defname  */
  YYSYMBOL_recname = 163,                  /* recname  */
  YYSYMBOL_params = 164,                   /* params  */
  YYSYMBOL_ctrlnames = 165,                /* ctrlnames  */
  YYSYMBOL_expression = 166,               /* expression  */
  YYSYMBOL_infixexp = 167,                 /* infixexp  */
  YYSYMBOL_primitive = 168,                /* primitive  */
  YYSYMBOL_ident = 169,                    /* ident  */
  YYSYMBOL_name = 170,                     /* name  */
  YYSYMBOL_arglist = 171,                  /* arglist  */
  YYSYMBOL_argument = 172,                 /* argument  */
  YYSYMBOL_string = 173,                   /* string  */
  YYSYMBOL_uqstring = 174,                 /* uqstring  */
  YYSYMBOL_fstring = 175,                  /* fstring  */
  YYSYMBOL_fpar = 176,                     /* fpar  */
  YYSYMBOL_fseq = 177,                     /* fseq  */
  YYSYMBOL_fsum = 178,                     /* fsum  */
  YYSYMBOL_fprod = 179,                    /* fprod  */
  YYSYMBOL_finputs = 180,                  /* finputs  */
  YYSYMBOL_foutputs = 181,                 /* foutputs  */
  YYSYMBOL_ffunction = 182,                /* ffunction  */
  YYSYMBOL_fconst = 183,                   /* fconst  */
  YYSYMBOL_fvariable = 184,                /* fvariable  */
  YYSYMBOL_button = 185,                   /* button  */
  YYSYMBOL_checkbox = 186,                 /* checkbox  */
  YYSYMBOL_vslider = 187,                  /* vslider  */
  YYSYMBOL_hslider = 188,                  /* hslider  */
  YYSYMBOL_nentry = 189,                   /* nentry  */
  YYSYMBOL_vgroup = 190,                   /* vgroup  */
  YYSYMBOL_hgroup = 191,                   /* hgroup  */
  YYSYMBOL_tgroup = 192,                   /* tgroup  */
  YYSYMBOL_vbargraph = 193,                /* vbargraph  */
  YYSYMBOL_hbargraph = 194,                /* hbargraph  */
  YYSYMBOL_soundfile = 195,                /* soundfile  */
  YYSYMBOL_signature = 196,                /* signature  */
  YYSYMBOL_fun = 197,                      /* fun  */
  YYSYMBOL_typelist = 198,                 /* typelist  */
  YYSYMBOL_rulelist = 199,                 /* rulelist  */
  YYSYMBOL_rule = 200,                     /* rule  */
  YYSYMBOL_type = 201,                     /* type  */
  YYSYMBOL_argtype = 202                   /* argtype  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   811

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  510

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   393


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   350,   350,   353,   354,   357,   358,   361,   362,   365,
     366,   367,   368,   371,   372,   379,   380,   383,   384,   385,
     386,   387,   388,   391,   392,   393,   394,   395,   398,   399,
     402,   403,   404,   405,   406,   407,   410,   411,   414,   417,
     420,   423,   426,   427,   430,   431,   432,   435,   436,   439,
     442,   443,   444,   447,   448,   451,   454,   457,   458,   461,
     462,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   486,
     487,   488,   490,   491,   493,   494,   495,   496,   497,   498,
     500,   501,   503,   506,   507,   509,   510,   512,   513,   515,
     516,   518,   519,   521,   522,   524,   525,   526,   527,   528,
     529,   531,   532,   533,   535,   536,   538,   539,   540,   541,
     542,   543,   545,   546,   547,   549,   550,   551,   552,   553,
     554,   555,   557,   558,   559,   560,   561,   562,   564,   565,
     566,   568,   569,   571,   572,   573,   574,   576,   577,   579,
     580,   582,   583,   584,   586,   587,   589,   590,   596,   599,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     622,   623,   624,   625,   627,   628,   632,   635,   638,   639,
     642,   643,   644,   645,   646,   649,   652,   655,   656,   661,
     665,   669,   673,   677,   680,   685,   689,   693,   698,   701,
     704,   707,   710,   713,   716,   719,   723,   726,   729,   736,
     737,   738,   739,   741,   742,   743,   744,   747,   750,   751,
     754,   755,   758,   762,   763,   766,   767,   768
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
  "\"end of file\"", "error", "\"invalid token\"", "SPLIT", "MIX", "SEQ",
  "PAR", "REC", "LT", "LE", "EQ", "GT", "GE", "NE", "ADD", "SUB", "OR",
  "MUL", "DIV", "MOD", "AND", "XOR", "LSH", "RSH", "POWOP", "FDELAY",
  "DELAY1", "MEM", "PREFIX", "INTCAST", "FLOATCAST", "NOTYPECAST",
  "FFUNCTION", "FCONSTANT", "FVARIABLE", "BUTTON", "CHECKBOX", "VSLIDER",
  "HSLIDER", "NENTRY", "VGROUP", "HGROUP", "TGROUP", "HBARGRAPH",
  "VBARGRAPH", "SOUNDFILE", "ATTACH", "ACOS", "ASIN", "ATAN", "ATAN2",
  "COS", "SIN", "TAN", "EXP", "LOG", "LOG10", "POWFUN", "SQRT", "ABS",
  "MIN", "MAX", "FMOD", "REMAINDER", "FLOOR", "CEIL", "RINT", "ROUND",
  "RDTBL", "RWTBL", "SELECT2", "SELECT3", "INT", "FLOAT", "MODULATE",
  "LAMBDA", "DOT", "WIRE", "CUT", "ENDDEF", "VIRG", "LPAR", "RPAR",
  "LBRAQ", "RBRAQ", "LCROC", "RCROC", "WITH", "LETREC", "WHERE", "DEF",
  "IMPORT", "COMPONENT", "LIBRARY", "ENVIRONMENT", "WAVEFORM", "ROUTE",
  "ENABLE", "CONTROL", "IPAR", "ISEQ", "ISUM", "IPROD", "INPUTS",
  "OUTPUTS", "STRING", "FSTRING", "IDENT", "EXTRA", "DECLARE", "CASE",
  "ARROW", "ASSERTBOUNDS", "LOWEST", "HIGHEST", "FLOATMODE", "DOUBLEMODE",
  "QUADMODE", "FIXEDPOINTMODE", "BDOC", "EDOC", "BEQN", "EEQN", "BDGM",
  "EDGM", "BLST", "ELST", "BMETADATA", "EMETADATA", "DOCCHAR", "NOTICE",
  "LISTING", "LSTTRUE", "LSTFALSE", "LSTDEPENDENCIES", "LSTMDOCTAGS",
  "LSTDISTRIBUTED", "LSTEQ", "LSTQ", "$accept", "program", "stmtlist",
  "deflist", "variantlist", "variant", "reclist", "vallist", "number",
  "statement", "doc", "docelem", "doctxt", "doceqn", "docdgm", "docntc",
  "doclst", "lstattrlist", "lstattrdef", "lstattrval", "docmtd",
  "definition", "recinition", "defname", "recname", "params", "ctrlnames",
  "expression", "infixexp", "primitive", "ident", "name", "arglist",
  "argument", "string", "uqstring", "fstring", "fpar", "fseq", "fsum",
  "fprod", "finputs", "foutputs", "ffunction", "fconst", "fvariable",
  "button", "checkbox", "vslider", "hslider", "nentry", "vgroup", "hgroup",
  "tgroup", "vbargraph", "hbargraph", "soundfile", "signature", "fun",
  "typelist", "rulelist", "rule", "type", "argtype", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-371)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -371,    57,    81,  -371,    25,    36,    50,  -371,   -16,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,     8,  -371,  -371,
      54,  -371,   -20,   258,   432,   432,  -371,    86,  -371,    69,
     119,  -371,   432,   432,  -371,   -16,  -371,  -371,   109,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
     -32,    94,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,   121,   142,   160,   168,
     190,   211,   217,   219,   223,   237,   242,   248,   279,   285,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,   287,  -371,
    -371,   432,    54,   296,   301,   164,   207,   306,  -371,  -371,
     309,   312,   321,   328,   345,   347,   212,  -371,  -371,  -371,
     676,  -371,  -371,    10,   400,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,    31,   676,   246,   267,  -371,
      17,     6,   265,   302,  -371,  -371,  -371,  -371,  -371,  -371,
     106,   106,   106,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,   232,    39,     9,  -371,    54,    54,
    -371,    85,   432,   232,   232,   232,   232,   432,   432,   355,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   432,  -371,   232,
     432,  -371,   432,   368,   432,   432,   432,   432,   432,   432,
     432,   432,   432,  -371,   380,   423,  -371,  -371,  -371,  -371,
    -371,   371,   374,   375,  -371,  -371,  -371,  -371,   508,   408,
     -16,   -16,   434,   441,   531,   532,   534,   535,   537,   546,
     547,   553,   554,    19,  -371,  -371,    54,   490,   485,   496,
     495,   189,   205,  -371,  -371,    12,  -371,   147,   589,   590,
     592,   593,   158,   209,   432,   -19,  -371,   595,   595,   595,
     595,   595,   595,   686,   686,   686,   218,   218,   218,   218,
     218,   218,   218,   243,   286,  -371,    21,   497,   400,   432,
     400,   400,   107,  -371,   416,   416,   338,   327,  -371,  -371,
    -371,   450,   455,   462,   244,  -371,    32,   616,   617,  -371,
    -371,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     232,   525,  -371,   526,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,    85,  -371,   432,   432,   432,   432,   432,  -371,  -371,
      24,  -371,  -371,  -371,  -371,    30,   214,   540,    13,   283,
     283,   283,  -371,  -371,   619,   408,   140,   244,   244,   710,
     715,   720,   253,   260,   269,   725,   730,    51,  -371,   548,
     432,  -371,    46,   735,   740,   769,   774,   516,  -371,  -371,
    -371,   549,   232,  -371,  -371,  -371,   545,  -371,  -371,   492,
     498,   499,    69,    48,  -371,  -371,  -371,  -371,    26,  -371,
     552,   559,   432,   432,   432,  -371,  -371,  -371,   432,   432,
    -371,   432,   276,   432,  -371,   432,   432,   432,   432,   432,
    -371,  -371,   560,   432,  -371,  -371,  -371,   561,   408,   166,
     323,  -371,  -371,  -371,   779,   784,   789,    56,   577,   310,
    -371,   515,   544,   551,   558,   565,   282,  -371,   570,  -371,
      68,  -371,    27,  -371,   432,   432,   432,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,   408,   277,  -371,
     794,   799,   804,   567,  -371,    73,   432,   432,   432,   307,
    -371,   582,   587,   601,  -371,    74,  -371,  -371,  -371,  -371
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     7,     1,     0,     0,     0,   186,     0,     9,
      10,    11,    12,    28,     8,     4,    26,     0,    55,    52,
       0,   187,     0,    36,     0,     0,   196,     0,   195,     0,
       0,    27,     0,     0,    42,     0,    40,    29,    30,    31,
      32,    33,    34,    35,   116,   117,   120,   118,   119,   121,
     105,   106,   112,   107,   108,   109,   111,   113,   114,   115,
     135,   110,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    93,    94,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,   123,   124,
       0,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     194,    92,   154,     0,   188,   180,   181,   182,   183,   184,
     185,   160,   161,   162,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,    69,     0,     0,    24,
       0,     0,     0,     0,    37,    95,    96,    97,    98,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    23,    25,    38,    39,
      41,     0,     0,     0,    43,    49,   233,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,   156,     0,     0,     0,     0,
       7,     0,     0,    17,    18,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,    84,    85,    88,
      86,    87,    89,    70,    71,    80,    72,    73,    74,    79,
      81,    82,    83,    75,    76,    78,     0,     7,   189,     0,
     191,   192,   190,   193,    66,    67,    65,    64,    68,     5,
      13,     0,     0,     0,     0,   227,     0,     0,     0,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,   163,   164,   165,    19,    20,    21,
      22,     0,   166,     0,     0,     0,     0,     0,   203,   204,
       0,   159,   231,    90,    91,     0,     0,     7,     0,     0,
       0,     0,   197,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
       0,    16,     0,     0,     0,     0,     0,     0,     6,    50,
      61,     0,     0,    62,     5,    14,     0,    47,    48,     0,
       0,     0,     0,     0,   235,   236,   237,   223,     0,   228,
       0,     0,     0,     0,     0,   213,   214,   215,     0,     0,
     218,     0,     0,     0,   167,     0,     0,     0,     0,     0,
      54,    56,     7,     0,    44,    45,    46,     0,     0,     0,
       0,   219,   206,   207,     0,     0,     0,     0,     0,     0,
     158,     0,     0,     0,     0,     0,     0,    63,     0,   205,
       0,   224,     0,   229,     0,     0,     0,   217,   216,   157,
     168,   199,   200,   201,   202,   232,    53,     0,     0,   220,
       0,     0,     0,     0,   225,     0,     0,     0,     0,     0,
     221,     0,     0,     0,   226,     0,   210,   211,   212,   222
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -371,  -371,   452,  -316,     0,  -371,  -371,  -371,   299,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,     5,
    -371,   289,  -371,  -371,  -371,  -371,  -371,    -4,   -25,  -371,
      15,   -18,  -173,  -102,   -28,  -106,    47,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -370,  -249,
    -371,   366,   266,   206
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,   307,   365,    14,   368,   275,   276,    15,
      23,    37,    38,    39,    40,    41,    42,   162,   244,   409,
      43,    16,   405,    17,   406,   263,   186,   155,   130,   131,
     132,    22,   133,   134,    30,    27,   374,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   248,   326,   418,
     285,   286,   249,   419
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     156,   158,     4,   367,    29,   413,   187,   156,   156,   228,
     229,   230,   231,   232,   401,   266,   222,   163,   351,    18,
     228,   229,   230,   231,   232,   340,     5,   222,   160,   161,
     222,     5,   450,   450,   228,   229,   230,   231,   232,   402,
     165,   166,   228,   229,   230,   231,   232,   306,   375,   224,
     225,   226,   433,   227,   224,   225,   226,     3,   227,   224,
     225,   226,   284,   227,   448,   361,   169,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   470,   450,
     450,    -2,   268,   269,   487,    28,   156,    21,   442,    24,
     277,    21,   223,   234,   235,   267,   352,   403,    25,   271,
     272,   341,   404,   363,   234,   235,   397,   185,   451,   489,
     233,   360,   226,   376,   227,    19,     6,   493,   234,   235,
     308,   265,   310,   311,   312,   313,   234,   235,   434,   449,
     239,    20,     7,   430,     8,   246,   247,     7,   477,   238,
       9,    10,    11,    12,    13,     9,    10,    11,    12,   488,
     224,   225,   226,   353,   227,   500,   509,   273,   274,    26,
     342,   228,   229,   230,   231,   232,   167,   168,   157,   414,
     415,   416,   156,   156,    28,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   282,   283,   414,   415,   416,   159,   264,
     472,     7,   170,   156,   156,   156,   156,   156,   278,   279,
     280,   281,   228,   229,   230,   231,   232,   228,   229,   230,
     231,   232,   417,   171,   314,   315,   316,   317,   318,   379,
     380,   381,   327,   328,   305,   385,   386,   387,   164,   495,
     358,   172,   216,   217,   218,   234,   235,   190,   471,   173,
     505,   392,   393,   394,   395,   396,   228,   229,   230,   231,
     232,   347,   348,   228,   229,   230,   231,   232,   217,   218,
       4,   174,   228,   229,   230,   231,   232,   349,   350,   228,
     229,   230,   231,   232,   156,   228,   229,   230,   231,   232,
     191,   359,   175,   399,   219,   199,   234,   235,   176,   220,
     177,   234,   235,   221,   178,   366,   414,   415,   416,   156,
     156,   156,   218,   228,   229,   230,   231,   232,   179,   219,
     454,   455,   456,   180,   220,   236,   457,   458,   221,   181,
     382,   383,   384,   231,   232,   425,   414,   415,   416,     7,
     234,   235,   426,   230,   231,   232,   237,   234,   235,   372,
     373,   427,   414,   415,   416,   388,   234,   235,   460,   494,
     182,   485,   219,   234,   235,   156,   183,   220,   184,   234,
     235,   221,   490,   491,   492,   410,   411,   188,    31,    32,
      18,    33,   189,    34,   447,    35,   432,   192,    36,   504,
     193,   240,   479,   194,   501,   502,   503,   234,   235,   241,
     242,   243,   195,   224,   225,   226,   156,   227,   156,   196,
     156,   156,   156,   156,   156,   407,   408,   441,   156,   228,
     229,   230,   231,   232,   420,   421,   197,   459,   198,   461,
     245,   462,   463,   464,   465,   466,   284,   250,   251,   468,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   309,    62,
      63,    64,    65,   319,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   320,   108,   321,   109,
     110,   322,   323,   111,   324,   325,   329,   112,   228,   229,
     230,   231,   232,   330,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   331,   332,     7,
     333,   334,   126,   335,   127,   128,   129,   228,   229,   230,
     231,   232,   336,   337,   228,   229,   230,   231,   232,   338,
     339,   228,   229,   230,   231,   232,   343,   344,   228,   229,
     230,   231,   232,   228,   229,   230,   231,   232,   345,   346,
     224,   225,   226,   364,   227,   224,   225,   226,   369,   227,
     224,   225,   226,   370,   227,   354,   355,   480,   356,   357,
     371,   389,   234,   235,   224,   225,   226,   390,   227,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   377,   378,   400,   412,   481,   439,   440,   431,
     444,   234,   235,   482,   452,   443,   445,   446,   234,   235,
     483,   453,   270,   469,   467,   234,   235,   484,   499,   486,
     391,   362,   234,   235,   398,     0,   473,   234,   235,   478,
       0,     0,     0,     0,   506,     0,     0,     0,     0,   507,
       0,   219,     0,     0,     0,     0,   220,     0,     0,     0,
     221,     0,     0,   508,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   224,   225,   226,   422,   227,   224,   225,
     226,   423,   227,   224,   225,   226,   424,   227,   224,   225,
     226,   428,   227,   224,   225,   226,   429,   227,   224,   225,
     226,   435,   227,   224,   225,   226,   436,   227,     0,     0,
       0,     0,   219,     0,     0,     0,     0,   220,     0,     0,
       0,   221,   219,     0,     0,     0,     0,   220,     0,     0,
       0,   221,   224,   225,   226,   437,   227,   224,   225,   226,
     438,   227,   224,   225,   226,   474,   227,   224,   225,   226,
     475,   227,   224,   225,   226,   476,   227,   224,   225,   226,
     496,   227,   224,   225,   226,   497,   227,   224,   225,   226,
     498,   227
};

static const yytype_int16 yycheck[] =
{
      25,    29,     2,   319,    22,   375,   112,    32,    33,     3,
       4,     5,     6,     7,     1,     6,     6,    35,     6,     4,
       3,     4,     5,     6,     7,     6,     1,     6,    32,    33,
       6,     1,     6,     6,     3,     4,     5,     6,     7,    26,
      72,    73,     3,     4,     5,     6,     7,   220,    16,     3,
       4,     5,     6,     7,     3,     4,     5,     0,     7,     3,
       4,     5,    81,     7,    16,    84,    51,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   448,     6,
       6,     0,   188,   189,    16,   105,   111,   107,   404,    81,
     192,   107,    82,    87,    88,    86,    84,    84,    90,    14,
      15,    82,    89,    82,    87,    88,    82,   111,    82,    82,
      79,   284,     5,    81,     7,    79,    91,   487,    87,    88,
     222,    82,   224,   225,   226,   227,    87,    88,    82,    81,
     124,    81,   107,    82,   109,    29,    30,   107,    82,   122,
     115,   116,   117,   118,   119,   115,   116,   117,   118,    81,
       3,     4,     5,     6,     7,    82,    82,    72,    73,   105,
     266,     3,     4,     5,     6,     7,    72,    73,    82,    29,
      30,    31,   197,   198,   105,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   197,   198,    29,    30,    31,    79,   184,
     449,   107,    81,   228,   229,   230,   231,   232,   193,   194,
     195,   196,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    82,    81,   228,   229,   230,   231,   232,   331,
     332,   333,   250,   251,   219,   337,   338,   339,   129,   488,
      82,    81,    24,    25,    26,    87,    88,    83,    82,    81,
     499,   353,   354,   355,   356,   357,     3,     4,     5,     6,
       7,    72,    73,     3,     4,     5,     6,     7,    25,    26,
     270,    81,     3,     4,     5,     6,     7,    72,    73,     3,
       4,     5,     6,     7,   309,     3,     4,     5,     6,     7,
      83,    82,    81,    79,    76,    83,    87,    88,    81,    81,
      81,    87,    88,    85,    81,   309,    29,    30,    31,   334,
     335,   336,    26,     3,     4,     5,     6,     7,    81,    76,
     422,   423,   424,    81,    81,    79,   428,   429,    85,    81,
     334,   335,   336,     6,     7,    82,    29,    30,    31,   107,
      87,    88,    82,     5,     6,     7,    79,    87,    88,   105,
     106,    82,    29,    30,    31,   340,    87,    88,    82,    82,
      81,    79,    76,    87,    88,   390,    81,    81,    81,    87,
      88,    85,   474,   475,   476,   370,   371,    81,   120,   121,
     365,   123,    81,   125,   412,   127,   390,    81,   130,    82,
      81,   126,    82,    81,   496,   497,   498,    87,    88,   134,
     135,   136,    81,     3,     4,     5,   431,     7,   433,    81,
     435,   436,   437,   438,   439,   132,   133,   402,   443,     3,
       4,     5,     6,     7,   377,   378,    81,   431,    81,   433,
     128,   435,   436,   437,   438,   439,    81,   171,   172,   443,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    90,    27,
      28,    29,    30,    83,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    83,    75,   137,    77,
      78,   137,   137,    81,     6,   107,    82,    85,     3,     4,
       5,     6,     7,    82,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     6,     6,   107,
       6,     6,   110,     6,   112,   113,   114,     3,     4,     5,
       6,     7,     6,     6,     3,     4,     5,     6,     7,     6,
       6,     3,     4,     5,     6,     7,    76,    82,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    82,    84,
       3,     4,     5,    86,     7,     3,     4,     5,   138,     7,
       3,     4,     5,   138,     7,     6,     6,    82,     6,     6,
     138,    76,    87,    88,     3,     4,     5,    81,     7,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     6,     6,    84,     6,    82,   111,    79,    81,
     138,    87,    88,    82,    82,    90,   138,   138,    87,    88,
      82,    82,   190,    82,    84,    87,    88,    82,    81,    79,
     351,   285,    87,    88,   365,    -1,   450,    87,    88,    82,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    82,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    82,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   140,   141,     0,   143,     1,    91,   107,   109,   115,
     116,   117,   118,   119,   144,   148,   160,   162,   169,    79,
      81,   107,   170,   149,    81,    90,   105,   174,   105,   170,
     173,   120,   121,   123,   125,   127,   130,   150,   151,   152,
     153,   154,   155,   159,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    27,    28,    29,    30,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    75,    77,
      78,    81,    85,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   110,   112,   113,   114,
     167,   168,   169,   171,   172,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   166,   167,    82,   173,    79,
     166,   166,   156,   170,   129,    72,    73,    72,    73,   169,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,   166,   165,   174,    81,    81,
      83,    83,    81,    81,    81,    81,    81,    81,    81,    83,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    76,
      81,    85,     6,    82,     3,     4,     5,     7,     3,     4,
       5,     6,     7,    79,    87,    88,    79,    79,   122,   124,
     126,   134,   135,   136,   157,   128,    29,    30,   196,   201,
     201,   201,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   164,   169,    82,     6,    86,   174,   174,
     141,    14,    15,    72,    73,   146,   147,   172,   169,   169,
     169,   169,   166,   166,    81,   199,   200,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   169,   171,   142,   172,    90,
     172,   172,   172,   172,   166,   166,   166,   166,   166,    83,
      83,   137,   137,   137,     6,   107,   197,   170,   170,    82,
      82,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    82,   174,    76,    82,    82,    84,    72,    73,    72,
      73,     6,    84,     6,     6,     6,     6,     6,    82,    82,
     171,    84,   200,    82,    86,   143,   166,   142,   145,   138,
     138,   138,   105,   106,   175,    16,    81,     6,     6,   172,
     172,   172,   166,   166,   166,   172,   172,   172,   169,    76,
      81,   147,   172,   172,   172,   172,   172,    82,   160,    79,
      84,     1,    26,    84,    89,   161,   163,   132,   133,   158,
     158,   158,     6,   197,    29,    30,    31,    82,   198,   202,
     175,   175,     6,     6,     6,    82,    82,    82,     6,     6,
      82,    81,   166,     6,    82,     6,     6,     6,     6,   111,
      79,   169,   142,    90,   138,   138,   138,   173,    16,    81,
       6,    82,    82,    82,   172,   172,   172,   172,   172,   166,
      82,   166,   166,   166,   166,   166,   166,    84,   166,    82,
     197,    82,   198,   202,     6,     6,     6,    82,    82,    82,
      82,    82,    82,    82,    82,    79,    79,    16,    81,    82,
     172,   172,   172,   197,    82,   198,     6,     6,     6,    81,
      82,   172,   172,   172,    82,   198,    82,    82,    82,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   139,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   150,   150,   150,   150,   151,   151,   152,   153,
     154,   155,   156,   156,   157,   157,   157,   158,   158,   159,
     160,   160,   160,   161,   161,   162,   163,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   170,   171,   171,
     172,   172,   172,   172,   172,   173,   174,   175,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     196,   196,   196,   196,   196,   196,   196,   197,   198,   198,
     199,   199,   200,   201,   201,   202,   202,   202
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     3,     0,     3,     0,     2,     1,
       1,     1,     1,     0,     2,     1,     3,     1,     1,     2,
       2,     2,     2,     5,     4,     5,     1,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     0,     2,     3,     3,
       1,     3,     0,     2,     5,     5,     5,     1,     1,     3,
       7,     4,     2,     4,     2,     1,     2,     1,     3,     1,
       3,     5,     5,     7,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     8,     7,     4,
       1,     1,     1,     4,     4,     4,     4,     6,     8,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     8,
       8,     8,     8,     4,     4,     8,     7,     7,     4,     4,
      12,    12,    12,     6,     6,     6,     8,     8,     6,     5,
       7,     9,    11,     4,     6,     8,    10,     1,     1,     3,
       1,     2,     6,     1,     1,     1,     1,     1
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
  case 2: /* program: stmtlist  */
#line 350 "faustparser.y"
                                                    { (yyval.exp) = (yyvsp[0].exp); gGlobal->gResult = formatDefinitions((yyval.exp)); }
#line 1779 "faustparser.cpp"
    break;

  case 3: /* stmtlist: %empty  */
#line 353 "faustparser.y"
                                                    { (yyval.exp) = gGlobal->nil; }
#line 1785 "faustparser.cpp"
    break;

  case 4: /* stmtlist: stmtlist variantlist statement  */
#line 354 "faustparser.y"
                                                    { if (acceptdefinition((yyvsp[-1].numvariant))) (yyval.exp) = cons ((yyvsp[0].exp),(yyvsp[-2].exp)); else (yyval.exp)=(yyvsp[-2].exp); }
#line 1791 "faustparser.cpp"
    break;

  case 5: /* deflist: %empty  */
#line 357 "faustparser.y"
                                                    { (yyval.exp) = gGlobal->nil; }
#line 1797 "faustparser.cpp"
    break;

  case 6: /* deflist: deflist variantlist definition  */
#line 358 "faustparser.y"
                                                    { if (acceptdefinition((yyvsp[-1].numvariant))) (yyval.exp) = cons ((yyvsp[0].exp),(yyvsp[-2].exp)); else (yyval.exp)=(yyvsp[-2].exp);}
#line 1803 "faustparser.cpp"
    break;

  case 7: /* variantlist: %empty  */
#line 361 "faustparser.y"
                                                    { (yyval.numvariant) = 0; }
#line 1809 "faustparser.cpp"
    break;

  case 8: /* variantlist: variantlist variant  */
#line 362 "faustparser.y"
                                                    { (yyval.numvariant) = (yyvsp[-1].numvariant) | (yyvsp[0].numvariant);}
#line 1815 "faustparser.cpp"
    break;

  case 9: /* variant: FLOATMODE  */
#line 365 "faustparser.y"
                                                    { (yyval.numvariant) = 1;}
#line 1821 "faustparser.cpp"
    break;

  case 10: /* variant: DOUBLEMODE  */
#line 366 "faustparser.y"
                                                    { (yyval.numvariant) = 2;}
#line 1827 "faustparser.cpp"
    break;

  case 11: /* variant: QUADMODE  */
#line 367 "faustparser.y"
                                                    { (yyval.numvariant) = 4;}
#line 1833 "faustparser.cpp"
    break;

  case 12: /* variant: FIXEDPOINTMODE  */
#line 368 "faustparser.y"
                                                    { (yyval.numvariant) = 8;}
#line 1839 "faustparser.cpp"
    break;

  case 13: /* reclist: %empty  */
#line 371 "faustparser.y"
                                                     { (yyval.exp) = gGlobal->nil; }
#line 1845 "faustparser.cpp"
    break;

  case 14: /* reclist: reclist recinition  */
#line 372 "faustparser.y"
                                                     { (yyval.exp) = cons ((yyvsp[0].exp),(yyvsp[-1].exp)); }
#line 1851 "faustparser.cpp"
    break;

  case 15: /* vallist: number  */
#line 379 "faustparser.y"
                                                      { gGlobal->gWaveForm.push_back((yyvsp[0].exp)); }
#line 1857 "faustparser.cpp"
    break;

  case 16: /* vallist: vallist PAR number  */
#line 380 "faustparser.y"
                                                      { gGlobal->gWaveForm.push_back((yyvsp[0].exp)); }
#line 1863 "faustparser.cpp"
    break;

  case 17: /* number: INT  */
#line 383 "faustparser.y"
                                                { (yyval.exp) = boxInt(str2int(FAUSTtext)); }
#line 1869 "faustparser.cpp"
    break;

  case 18: /* number: FLOAT  */
#line 384 "faustparser.y"
                                                { (yyval.exp) = boxReal(atof(FAUSTtext)); }
#line 1875 "faustparser.cpp"
    break;

  case 19: /* number: ADD INT  */
#line 385 "faustparser.y"
                                                { (yyval.exp) = boxInt(str2int(FAUSTtext)); }
#line 1881 "faustparser.cpp"
    break;

  case 20: /* number: ADD FLOAT  */
#line 386 "faustparser.y"
                                                { (yyval.exp) = boxReal(atof(FAUSTtext)); }
#line 1887 "faustparser.cpp"
    break;

  case 21: /* number: SUB INT  */
#line 387 "faustparser.y"
                                                { (yyval.exp) = boxInt(-str2int(FAUSTtext)); }
#line 1893 "faustparser.cpp"
    break;

  case 22: /* number: SUB FLOAT  */
#line 388 "faustparser.y"
                                                { (yyval.exp) = boxReal(-atof(FAUSTtext)); }
#line 1899 "faustparser.cpp"
    break;

  case 23: /* statement: IMPORT LPAR uqstring RPAR ENDDEF  */
#line 391 "faustparser.y"
                                                             { (yyval.exp) = importFile((yyvsp[-2].exp)); }
#line 1905 "faustparser.cpp"
    break;

  case 24: /* statement: DECLARE name string ENDDEF  */
#line 392 "faustparser.y"
                                                             { declareMetadata((yyvsp[-2].exp),(yyvsp[-1].exp)); (yyval.exp) = gGlobal->nil; }
#line 1911 "faustparser.cpp"
    break;

  case 25: /* statement: DECLARE name name string ENDDEF  */
#line 393 "faustparser.y"
                                                             { declareDefinitionMetadata((yyvsp[-3].exp),(yyvsp[-2].exp),(yyvsp[-1].exp)); (yyval.exp) = gGlobal->nil; }
#line 1917 "faustparser.cpp"
    break;

  case 26: /* statement: definition  */
#line 394 "faustparser.y"
                                                             { (yyval.exp) = (yyvsp[0].exp); }
#line 1923 "faustparser.cpp"
    break;

  case 27: /* statement: BDOC doc EDOC  */
#line 395 "faustparser.y"
                                                             { declareDoc((yyvsp[-1].exp)); (yyval.exp) = gGlobal->nil; /* cerr << "Yacc : doc : " << *$2 << endl; */ }
#line 1929 "faustparser.cpp"
    break;

  case 28: /* doc: %empty  */
#line 398 "faustparser.y"
                                                            { (yyval.exp) = gGlobal->nil; }
#line 1935 "faustparser.cpp"
    break;

  case 29: /* doc: doc docelem  */
#line 399 "faustparser.y"
                                                            { (yyval.exp) = cons ((yyvsp[0].exp),(yyvsp[-1].exp)); }
#line 1941 "faustparser.cpp"
    break;

  case 30: /* docelem: doctxt  */
#line 402 "faustparser.y"
                                                            { (yyval.exp) = docTxt((yyvsp[0].cppstr)->c_str()); delete (yyvsp[0].cppstr); }
#line 1947 "faustparser.cpp"
    break;

  case 31: /* docelem: doceqn  */
#line 403 "faustparser.y"
                                                            { (yyval.exp) = docEqn((yyvsp[0].exp)); }
#line 1953 "faustparser.cpp"
    break;

  case 32: /* docelem: docdgm  */
#line 404 "faustparser.y"
                                                            { (yyval.exp) = docDgm((yyvsp[0].exp)); }
#line 1959 "faustparser.cpp"
    break;

  case 33: /* docelem: docntc  */
#line 405 "faustparser.y"
                                                            { (yyval.exp) = docNtc(); }
#line 1965 "faustparser.cpp"
    break;

  case 34: /* docelem: doclst  */
#line 406 "faustparser.y"
                                                            { (yyval.exp) = docLst(); }
#line 1971 "faustparser.cpp"
    break;

  case 35: /* docelem: docmtd  */
#line 407 "faustparser.y"
                                                            { (yyval.exp) = docMtd((yyvsp[0].exp)); }
#line 1977 "faustparser.cpp"
    break;

  case 36: /* doctxt: %empty  */
#line 410 "faustparser.y"
                                                           { (yyval.cppstr) = new string(); }
#line 1983 "faustparser.cpp"
    break;

  case 37: /* doctxt: doctxt DOCCHAR  */
#line 411 "faustparser.y"
                                                           { (yyval.cppstr) = &((yyvsp[-1].cppstr)->append(FAUSTtext)); }
#line 1989 "faustparser.cpp"
    break;

  case 38: /* doceqn: BEQN expression EEQN  */
#line 414 "faustparser.y"
                                                                { (yyval.exp) = (yyvsp[-1].exp); }
#line 1995 "faustparser.cpp"
    break;

  case 39: /* docdgm: BDGM expression EDGM  */
#line 417 "faustparser.y"
                                                                { (yyval.exp) = (yyvsp[-1].exp); }
#line 2001 "faustparser.cpp"
    break;

  case 40: /* docntc: NOTICE  */
#line 420 "faustparser.y"
                                                        { }
#line 2007 "faustparser.cpp"
    break;

  case 41: /* doclst: BLST lstattrlist ELST  */
#line 423 "faustparser.y"
                                                        { }
#line 2013 "faustparser.cpp"
    break;

  case 42: /* lstattrlist: %empty  */
#line 426 "faustparser.y"
                                                        { }
#line 2019 "faustparser.cpp"
    break;

  case 43: /* lstattrlist: lstattrlist lstattrdef  */
#line 427 "faustparser.y"
                                                        { }
#line 2025 "faustparser.cpp"
    break;

  case 44: /* lstattrdef: LSTDEPENDENCIES LSTEQ LSTQ lstattrval LSTQ  */
#line 430 "faustparser.y"
                                                                { gGlobal->gLstDependenciesSwitch = (yyvsp[-1].b); }
#line 2031 "faustparser.cpp"
    break;

  case 45: /* lstattrdef: LSTMDOCTAGS LSTEQ LSTQ lstattrval LSTQ  */
#line 431 "faustparser.y"
                                                                { gGlobal->gStripDocSwitch = (yyvsp[-1].b); gGlobal->gStripDocSwitch==true ? gGlobal->gStripDocSwitch=false : gGlobal->gStripDocSwitch=true; }
#line 2037 "faustparser.cpp"
    break;

  case 46: /* lstattrdef: LSTDISTRIBUTED LSTEQ LSTQ lstattrval LSTQ  */
#line 432 "faustparser.y"
                                                                { gGlobal->gLstDistributedSwitch = (yyvsp[-1].b); }
#line 2043 "faustparser.cpp"
    break;

  case 47: /* lstattrval: LSTTRUE  */
#line 435 "faustparser.y"
                                                         { (yyval.b) = true; }
#line 2049 "faustparser.cpp"
    break;

  case 48: /* lstattrval: LSTFALSE  */
#line 436 "faustparser.y"
                                                          { (yyval.b) = false; }
#line 2055 "faustparser.cpp"
    break;

  case 49: /* docmtd: BMETADATA name EMETADATA  */
#line 439 "faustparser.y"
                                                          { (yyval.exp) = (yyvsp[-1].exp); }
#line 2061 "faustparser.cpp"
    break;

  case 50: /* definition: defname LPAR arglist RPAR DEF expression ENDDEF  */
#line 442 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-6].exp),cons((yyvsp[-4].exp),(yyvsp[-1].exp))); setDefProp((yyvsp[-6].exp), FAUSTfilename, FAUSTlineno); }
#line 2067 "faustparser.cpp"
    break;

  case 51: /* definition: defname DEF expression ENDDEF  */
#line 443 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-3].exp),cons(gGlobal->nil,(yyvsp[-1].exp)));  setDefProp((yyvsp[-3].exp), FAUSTfilename, FAUSTlineno); }
#line 2073 "faustparser.cpp"
    break;

  case 52: /* definition: error ENDDEF  */
#line 444 "faustparser.y"
                                                                   { (yyval.exp) = gGlobal->nil; FAUSTerr++; }
#line 2079 "faustparser.cpp"
    break;

  case 53: /* recinition: recname DEF expression ENDDEF  */
#line 447 "faustparser.y"
                                                              { (yyval.exp) = cons((yyvsp[-3].exp),cons(gGlobal->nil,(yyvsp[-1].exp))); setDefProp((yyvsp[-3].exp), FAUSTfilename, FAUSTlineno); }
#line 2085 "faustparser.cpp"
    break;

  case 54: /* recinition: error ENDDEF  */
#line 448 "faustparser.y"
                                                              { (yyval.exp) = gGlobal->nil; FAUSTerr++; }
#line 2091 "faustparser.cpp"
    break;

  case 55: /* defname: ident  */
#line 451 "faustparser.y"
                                                        { (yyval.exp)=(yyvsp[0].exp); }
#line 2097 "faustparser.cpp"
    break;

  case 56: /* recname: DELAY1 ident  */
#line 454 "faustparser.y"
                                                        { (yyval.exp)=(yyvsp[0].exp); }
#line 2103 "faustparser.cpp"
    break;

  case 57: /* params: ident  */
#line 457 "faustparser.y"
                                                          { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 2109 "faustparser.cpp"
    break;

  case 58: /* params: params PAR ident  */
#line 458 "faustparser.y"
                                                          { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-2].exp)); }
#line 2115 "faustparser.cpp"
    break;

  case 59: /* ctrlnames: uqstring  */
#line 461 "faustparser.y"
                                                          { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 2121 "faustparser.cpp"
    break;

  case 60: /* ctrlnames: ctrlnames PAR uqstring  */
#line 462 "faustparser.y"
                                                          { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-2].exp)); }
#line 2127 "faustparser.cpp"
    break;

  case 61: /* expression: expression WITH LBRAQ deflist RBRAQ  */
#line 465 "faustparser.y"
                                                          { (yyval.exp) = boxWithLocalDef((yyvsp[-4].exp),formatDefinitions((yyvsp[-1].exp))); }
#line 2133 "faustparser.cpp"
    break;

  case 62: /* expression: expression LETREC LBRAQ reclist RBRAQ  */
#line 466 "faustparser.y"
                                                          { (yyval.exp) = boxWithRecDef((yyvsp[-4].exp),formatDefinitions((yyvsp[-1].exp)), gGlobal->nil); }
#line 2139 "faustparser.cpp"
    break;

  case 63: /* expression: expression LETREC LBRAQ reclist WHERE deflist RBRAQ  */
#line 467 "faustparser.y"
                                                                         { (yyval.exp) = boxWithRecDef((yyvsp[-6].exp),formatDefinitions((yyvsp[-3].exp)),formatDefinitions((yyvsp[-1].exp))); }
#line 2145 "faustparser.cpp"
    break;

  case 64: /* expression: expression PAR expression  */
#line 468 "faustparser.y"
                                                         { (yyval.exp) = boxPar((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2151 "faustparser.cpp"
    break;

  case 65: /* expression: expression SEQ expression  */
#line 469 "faustparser.y"
                                                         { (yyval.exp) = boxSeq((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2157 "faustparser.cpp"
    break;

  case 66: /* expression: expression SPLIT expression  */
#line 470 "faustparser.y"
                                                         { (yyval.exp) = boxSplit((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2163 "faustparser.cpp"
    break;

  case 67: /* expression: expression MIX expression  */
#line 471 "faustparser.y"
                                                         { (yyval.exp) = boxMerge((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2169 "faustparser.cpp"
    break;

  case 68: /* expression: expression REC expression  */
#line 472 "faustparser.y"
                                                         { (yyval.exp) = boxRec((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2175 "faustparser.cpp"
    break;

  case 69: /* expression: infixexp  */
#line 473 "faustparser.y"
                                                         { (yyval.exp) = (yyvsp[0].exp); }
#line 2181 "faustparser.cpp"
    break;

  case 70: /* infixexp: infixexp ADD infixexp  */
#line 476 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigAdd)); }
#line 2187 "faustparser.cpp"
    break;

  case 71: /* infixexp: infixexp SUB infixexp  */
#line 477 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigSub)); }
#line 2193 "faustparser.cpp"
    break;

  case 72: /* infixexp: infixexp MUL infixexp  */
#line 478 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigMul)); }
#line 2199 "faustparser.cpp"
    break;

  case 73: /* infixexp: infixexp DIV infixexp  */
#line 479 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigDiv)); }
#line 2205 "faustparser.cpp"
    break;

  case 74: /* infixexp: infixexp MOD infixexp  */
#line 480 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigRem)); }
#line 2211 "faustparser.cpp"
    break;

  case 75: /* infixexp: infixexp POWOP infixexp  */
#line 481 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),gGlobal->gPowPrim->box()); }
#line 2217 "faustparser.cpp"
    break;

  case 76: /* infixexp: infixexp FDELAY infixexp  */
#line 482 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigDelay)); }
#line 2223 "faustparser.cpp"
    break;

  case 77: /* infixexp: infixexp DELAY1  */
#line 483 "faustparser.y"
                                            { (yyval.exp) = boxSeq((yyvsp[-1].exp),boxPrim1(sigDelay1)); }
#line 2229 "faustparser.cpp"
    break;

  case 78: /* infixexp: infixexp DOT ident  */
#line 484 "faustparser.y"
                                            { (yyval.exp) = boxAccess((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2235 "faustparser.cpp"
    break;

  case 79: /* infixexp: infixexp AND infixexp  */
#line 486 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigAND)); }
#line 2241 "faustparser.cpp"
    break;

  case 80: /* infixexp: infixexp OR infixexp  */
#line 487 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigOR)); }
#line 2247 "faustparser.cpp"
    break;

  case 81: /* infixexp: infixexp XOR infixexp  */
#line 488 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigXOR)); }
#line 2253 "faustparser.cpp"
    break;

  case 82: /* infixexp: infixexp LSH infixexp  */
#line 490 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigLeftShift)); }
#line 2259 "faustparser.cpp"
    break;

  case 83: /* infixexp: infixexp RSH infixexp  */
#line 491 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigARightShift)); }
#line 2265 "faustparser.cpp"
    break;

  case 84: /* infixexp: infixexp LT infixexp  */
#line 493 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigLT)); }
#line 2271 "faustparser.cpp"
    break;

  case 85: /* infixexp: infixexp LE infixexp  */
#line 494 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigLE)); }
#line 2277 "faustparser.cpp"
    break;

  case 86: /* infixexp: infixexp GT infixexp  */
#line 495 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigGT)); }
#line 2283 "faustparser.cpp"
    break;

  case 87: /* infixexp: infixexp GE infixexp  */
#line 496 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigGE)); }
#line 2289 "faustparser.cpp"
    break;

  case 88: /* infixexp: infixexp EQ infixexp  */
#line 497 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigEQ)); }
#line 2295 "faustparser.cpp"
    break;

  case 89: /* infixexp: infixexp NE infixexp  */
#line 498 "faustparser.y"
                                            { (yyval.exp) = boxSeq(boxPar((yyvsp[-2].exp),(yyvsp[0].exp)),boxPrim2(sigNE)); }
#line 2301 "faustparser.cpp"
    break;

  case 90: /* infixexp: infixexp LPAR arglist RPAR  */
#line 500 "faustparser.y"
                                                   { (yyval.exp) = buildBoxAppl((yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 2307 "faustparser.cpp"
    break;

  case 91: /* infixexp: infixexp LCROC deflist RCROC  */
#line 501 "faustparser.y"
                                                   { (yyval.exp) = boxModifLocalDef((yyvsp[-3].exp),formatDefinitions((yyvsp[-1].exp))); }
#line 2313 "faustparser.cpp"
    break;

  case 92: /* infixexp: primitive  */
#line 503 "faustparser.y"
                                                   { (yyval.exp) = (yyvsp[0].exp); }
#line 2319 "faustparser.cpp"
    break;

  case 93: /* primitive: INT  */
#line 506 "faustparser.y"
                                                { (yyval.exp) = boxInt(str2int(FAUSTtext)); }
#line 2325 "faustparser.cpp"
    break;

  case 94: /* primitive: FLOAT  */
#line 507 "faustparser.y"
                                                { (yyval.exp) = boxReal(atof(FAUSTtext)); }
#line 2331 "faustparser.cpp"
    break;

  case 95: /* primitive: ADD INT  */
#line 509 "faustparser.y"
                                                { (yyval.exp) = boxInt (str2int(FAUSTtext)); }
#line 2337 "faustparser.cpp"
    break;

  case 96: /* primitive: ADD FLOAT  */
#line 510 "faustparser.y"
                                                { (yyval.exp) = boxReal(atof(FAUSTtext)); }
#line 2343 "faustparser.cpp"
    break;

  case 97: /* primitive: SUB INT  */
#line 512 "faustparser.y"
                                                { (yyval.exp) = boxInt ( -str2int(FAUSTtext) ); }
#line 2349 "faustparser.cpp"
    break;

  case 98: /* primitive: SUB FLOAT  */
#line 513 "faustparser.y"
                                                { (yyval.exp) = boxReal( -atof(FAUSTtext) ); }
#line 2355 "faustparser.cpp"
    break;

  case 99: /* primitive: WIRE  */
#line 515 "faustparser.y"
                                                { (yyval.exp) = boxWire(); }
#line 2361 "faustparser.cpp"
    break;

  case 100: /* primitive: CUT  */
#line 516 "faustparser.y"
                                                { (yyval.exp) = boxCut(); }
#line 2367 "faustparser.cpp"
    break;

  case 101: /* primitive: MEM  */
#line 518 "faustparser.y"
                                                { (yyval.exp) = boxPrim1(sigDelay1); }
#line 2373 "faustparser.cpp"
    break;

  case 102: /* primitive: PREFIX  */
#line 519 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigPrefix); }
#line 2379 "faustparser.cpp"
    break;

  case 103: /* primitive: INTCAST  */
#line 521 "faustparser.y"
                                                { (yyval.exp) = boxPrim1(sigIntCast); }
#line 2385 "faustparser.cpp"
    break;

  case 104: /* primitive: FLOATCAST  */
#line 522 "faustparser.y"
                                                { (yyval.exp) = boxPrim1(sigFloatCast); }
#line 2391 "faustparser.cpp"
    break;

  case 105: /* primitive: ADD  */
#line 524 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigAdd); }
#line 2397 "faustparser.cpp"
    break;

  case 106: /* primitive: SUB  */
#line 525 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigSub); }
#line 2403 "faustparser.cpp"
    break;

  case 107: /* primitive: MUL  */
#line 526 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigMul); }
#line 2409 "faustparser.cpp"
    break;

  case 108: /* primitive: DIV  */
#line 527 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigDiv); }
#line 2415 "faustparser.cpp"
    break;

  case 109: /* primitive: MOD  */
#line 528 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigRem); }
#line 2421 "faustparser.cpp"
    break;

  case 110: /* primitive: FDELAY  */
#line 529 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigDelay); }
#line 2427 "faustparser.cpp"
    break;

  case 111: /* primitive: AND  */
#line 531 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigAND); }
#line 2433 "faustparser.cpp"
    break;

  case 112: /* primitive: OR  */
#line 532 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigOR); }
#line 2439 "faustparser.cpp"
    break;

  case 113: /* primitive: XOR  */
#line 533 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigXOR); }
#line 2445 "faustparser.cpp"
    break;

  case 114: /* primitive: LSH  */
#line 535 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigLeftShift); }
#line 2451 "faustparser.cpp"
    break;

  case 115: /* primitive: RSH  */
#line 536 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigARightShift); }
#line 2457 "faustparser.cpp"
    break;

  case 116: /* primitive: LT  */
#line 538 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigLT); }
#line 2463 "faustparser.cpp"
    break;

  case 117: /* primitive: LE  */
#line 539 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigLE); }
#line 2469 "faustparser.cpp"
    break;

  case 118: /* primitive: GT  */
#line 540 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigGT); }
#line 2475 "faustparser.cpp"
    break;

  case 119: /* primitive: GE  */
#line 541 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigGE); }
#line 2481 "faustparser.cpp"
    break;

  case 120: /* primitive: EQ  */
#line 542 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigEQ); }
#line 2487 "faustparser.cpp"
    break;

  case 121: /* primitive: NE  */
#line 543 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigNE); }
#line 2493 "faustparser.cpp"
    break;

  case 122: /* primitive: ATTACH  */
#line 545 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigAttach); }
#line 2499 "faustparser.cpp"
    break;

  case 123: /* primitive: ENABLE  */
#line 546 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigEnable); }
#line 2505 "faustparser.cpp"
    break;

  case 124: /* primitive: CONTROL  */
#line 547 "faustparser.y"
                                                { (yyval.exp) = boxPrim2(sigControl); }
#line 2511 "faustparser.cpp"
    break;

  case 125: /* primitive: ACOS  */
#line 549 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gAcosPrim->box(); }
#line 2517 "faustparser.cpp"
    break;

  case 126: /* primitive: ASIN  */
#line 550 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gAsinPrim->box(); }
#line 2523 "faustparser.cpp"
    break;

  case 127: /* primitive: ATAN  */
#line 551 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gAtanPrim->box(); }
#line 2529 "faustparser.cpp"
    break;

  case 128: /* primitive: ATAN2  */
#line 552 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gAtan2Prim->box(); }
#line 2535 "faustparser.cpp"
    break;

  case 129: /* primitive: COS  */
#line 553 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gCosPrim->box(); }
#line 2541 "faustparser.cpp"
    break;

  case 130: /* primitive: SIN  */
#line 554 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gSinPrim->box(); }
#line 2547 "faustparser.cpp"
    break;

  case 131: /* primitive: TAN  */
#line 555 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gTanPrim->box(); }
#line 2553 "faustparser.cpp"
    break;

  case 132: /* primitive: EXP  */
#line 557 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gExpPrim->box(); }
#line 2559 "faustparser.cpp"
    break;

  case 133: /* primitive: LOG  */
#line 558 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gLogPrim->box(); }
#line 2565 "faustparser.cpp"
    break;

  case 134: /* primitive: LOG10  */
#line 559 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gLog10Prim->box(); }
#line 2571 "faustparser.cpp"
    break;

  case 135: /* primitive: POWOP  */
#line 560 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gPowPrim->box(); }
#line 2577 "faustparser.cpp"
    break;

  case 136: /* primitive: POWFUN  */
#line 561 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gPowPrim->box(); }
#line 2583 "faustparser.cpp"
    break;

  case 137: /* primitive: SQRT  */
#line 562 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gSqrtPrim->box(); }
#line 2589 "faustparser.cpp"
    break;

  case 138: /* primitive: ABS  */
#line 564 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gAbsPrim->box(); }
#line 2595 "faustparser.cpp"
    break;

  case 139: /* primitive: MIN  */
#line 565 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gMinPrim->box(); }
#line 2601 "faustparser.cpp"
    break;

  case 140: /* primitive: MAX  */
#line 566 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gMaxPrim->box(); }
#line 2607 "faustparser.cpp"
    break;

  case 141: /* primitive: FMOD  */
#line 568 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gFmodPrim->box(); }
#line 2613 "faustparser.cpp"
    break;

  case 142: /* primitive: REMAINDER  */
#line 569 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gRemainderPrim->box(); }
#line 2619 "faustparser.cpp"
    break;

  case 143: /* primitive: FLOOR  */
#line 571 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gFloorPrim->box(); }
#line 2625 "faustparser.cpp"
    break;

  case 144: /* primitive: CEIL  */
#line 572 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gCeilPrim->box(); }
#line 2631 "faustparser.cpp"
    break;

  case 145: /* primitive: RINT  */
#line 573 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gRintPrim->box(); }
#line 2637 "faustparser.cpp"
    break;

  case 146: /* primitive: ROUND  */
#line 574 "faustparser.y"
                                                 { (yyval.exp) = gGlobal->gRoundPrim->box(); }
#line 2643 "faustparser.cpp"
    break;

  case 147: /* primitive: RDTBL  */
#line 576 "faustparser.y"
                                                 { (yyval.exp) = boxPrim3(sigReadOnlyTable); }
#line 2649 "faustparser.cpp"
    break;

  case 148: /* primitive: RWTBL  */
#line 577 "faustparser.y"
                                                 { (yyval.exp) = boxPrim5(sigWriteReadTable); }
#line 2655 "faustparser.cpp"
    break;

  case 149: /* primitive: SELECT2  */
#line 579 "faustparser.y"
                                                 { (yyval.exp) = boxPrim3(sigSelect2); }
#line 2661 "faustparser.cpp"
    break;

  case 150: /* primitive: SELECT3  */
#line 580 "faustparser.y"
                                                 { (yyval.exp) = boxPrim4(sigSelect3); }
#line 2667 "faustparser.cpp"
    break;

  case 151: /* primitive: ASSERTBOUNDS  */
#line 582 "faustparser.y"
                                                 { (yyval.exp) = boxPrim3(sigAssertBounds);}
#line 2673 "faustparser.cpp"
    break;

  case 152: /* primitive: LOWEST  */
#line 583 "faustparser.y"
                                                 { (yyval.exp) = boxPrim1(sigLowest);}
#line 2679 "faustparser.cpp"
    break;

  case 153: /* primitive: HIGHEST  */
#line 584 "faustparser.y"
                                                 { (yyval.exp) = boxPrim1(sigHighest);}
#line 2685 "faustparser.cpp"
    break;

  case 154: /* primitive: ident  */
#line 586 "faustparser.y"
                                                 { (yyval.exp) = (yyvsp[0].exp);  setUseProp((yyvsp[0].exp), FAUSTfilename, FAUSTlineno);}
#line 2691 "faustparser.cpp"
    break;

  case 155: /* primitive: SUB ident  */
#line 587 "faustparser.y"
                                                 { (yyval.exp) = boxSeq(boxPar(boxInt(0),(yyvsp[0].exp)),boxPrim2(sigSub)); }
#line 2697 "faustparser.cpp"
    break;

  case 156: /* primitive: LPAR expression RPAR  */
#line 589 "faustparser.y"
                                                  { (yyval.exp) = (yyvsp[-1].exp); }
#line 2703 "faustparser.cpp"
    break;

  case 157: /* primitive: LAMBDA LPAR params RPAR DOT LPAR expression RPAR  */
#line 591 "faustparser.y"
                                                  { (yyval.exp) = buildBoxAbstr((yyvsp[-5].exp),(yyvsp[-1].exp)); }
#line 2709 "faustparser.cpp"
    break;

  case 158: /* primitive: LCROC ctrlnames RCROC DOT LPAR expression RPAR  */
#line 597 "faustparser.y"
                                                  { (yyval.exp) = buildBoxModulation((yyvsp[-5].exp),(yyvsp[-1].exp)); }
#line 2715 "faustparser.cpp"
    break;

  case 159: /* primitive: CASE LBRAQ rulelist RBRAQ  */
#line 599 "faustparser.y"
                                                { (yyval.exp) = boxCase(checkRulelist((yyvsp[-1].exp))); }
#line 2721 "faustparser.cpp"
    break;

  case 160: /* primitive: ffunction  */
#line 601 "faustparser.y"
                                                { (yyval.exp) = boxFFun((yyvsp[0].exp)); }
#line 2727 "faustparser.cpp"
    break;

  case 161: /* primitive: fconst  */
#line 602 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2733 "faustparser.cpp"
    break;

  case 162: /* primitive: fvariable  */
#line 603 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2739 "faustparser.cpp"
    break;

  case 163: /* primitive: COMPONENT LPAR uqstring RPAR  */
#line 604 "faustparser.y"
                                                { (yyval.exp) = boxComponent((yyvsp[-1].exp)); }
#line 2745 "faustparser.cpp"
    break;

  case 164: /* primitive: LIBRARY LPAR uqstring RPAR  */
#line 605 "faustparser.y"
                                                { (yyval.exp) = boxLibrary((yyvsp[-1].exp)); }
#line 2751 "faustparser.cpp"
    break;

  case 165: /* primitive: ENVIRONMENT LBRAQ stmtlist RBRAQ  */
#line 606 "faustparser.y"
                                                   { (yyval.exp) = boxWithLocalDef(boxEnvironment(),formatDefinitions((yyvsp[-1].exp))); }
#line 2757 "faustparser.cpp"
    break;

  case 166: /* primitive: WAVEFORM LBRAQ vallist RBRAQ  */
#line 607 "faustparser.y"
                                                   { (yyval.exp) = boxWaveform(gGlobal->gWaveForm); gGlobal->gWaveForm.clear(); }
#line 2763 "faustparser.cpp"
    break;

  case 167: /* primitive: ROUTE LPAR argument PAR argument RPAR  */
#line 608 "faustparser.y"
                                                              { (yyval.exp) = boxRoute((yyvsp[-3].exp), (yyvsp[-1].exp), boxPar(boxInt(0),boxInt(0))); }
#line 2769 "faustparser.cpp"
    break;

  case 168: /* primitive: ROUTE LPAR argument PAR argument PAR expression RPAR  */
#line 609 "faustparser.y"
                                                                             { (yyval.exp) = boxRoute((yyvsp[-5].exp), (yyvsp[-3].exp), (yyvsp[-1].exp)); }
#line 2775 "faustparser.cpp"
    break;

  case 169: /* primitive: button  */
#line 610 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2781 "faustparser.cpp"
    break;

  case 170: /* primitive: checkbox  */
#line 611 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2787 "faustparser.cpp"
    break;

  case 171: /* primitive: vslider  */
#line 612 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2793 "faustparser.cpp"
    break;

  case 172: /* primitive: hslider  */
#line 613 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2799 "faustparser.cpp"
    break;

  case 173: /* primitive: nentry  */
#line 614 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2805 "faustparser.cpp"
    break;

  case 174: /* primitive: vgroup  */
#line 615 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2811 "faustparser.cpp"
    break;

  case 175: /* primitive: hgroup  */
#line 616 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2817 "faustparser.cpp"
    break;

  case 176: /* primitive: tgroup  */
#line 617 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2823 "faustparser.cpp"
    break;

  case 177: /* primitive: vbargraph  */
#line 618 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2829 "faustparser.cpp"
    break;

  case 178: /* primitive: hbargraph  */
#line 619 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2835 "faustparser.cpp"
    break;

  case 179: /* primitive: soundfile  */
#line 620 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2841 "faustparser.cpp"
    break;

  case 180: /* primitive: fpar  */
#line 622 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2847 "faustparser.cpp"
    break;

  case 181: /* primitive: fseq  */
#line 623 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2853 "faustparser.cpp"
    break;

  case 182: /* primitive: fsum  */
#line 624 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2859 "faustparser.cpp"
    break;

  case 183: /* primitive: fprod  */
#line 625 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2865 "faustparser.cpp"
    break;

  case 184: /* primitive: finputs  */
#line 627 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2871 "faustparser.cpp"
    break;

  case 185: /* primitive: foutputs  */
#line 628 "faustparser.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2877 "faustparser.cpp"
    break;

  case 186: /* ident: IDENT  */
#line 632 "faustparser.y"
                                                { (yyval.exp) = boxIdent(FAUSTtext); setUseProp((yyval.exp), FAUSTfilename, FAUSTlineno);  }
#line 2883 "faustparser.cpp"
    break;

  case 187: /* name: IDENT  */
#line 635 "faustparser.y"
                                                { (yyval.exp) = tree(FAUSTtext); setUseProp((yyval.exp), FAUSTfilename, FAUSTlineno);  }
#line 2889 "faustparser.cpp"
    break;

  case 188: /* arglist: argument  */
#line 638 "faustparser.y"
                                                { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 2895 "faustparser.cpp"
    break;

  case 189: /* arglist: arglist PAR argument  */
#line 639 "faustparser.y"
                                                { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-2].exp)); }
#line 2901 "faustparser.cpp"
    break;

  case 190: /* argument: argument SEQ argument  */
#line 642 "faustparser.y"
                                                 { (yyval.exp) = boxSeq((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2907 "faustparser.cpp"
    break;

  case 191: /* argument: argument SPLIT argument  */
#line 643 "faustparser.y"
                                                 { (yyval.exp) = boxSplit((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2913 "faustparser.cpp"
    break;

  case 192: /* argument: argument MIX argument  */
#line 644 "faustparser.y"
                                                 { (yyval.exp) = boxMerge((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2919 "faustparser.cpp"
    break;

  case 193: /* argument: argument REC argument  */
#line 645 "faustparser.y"
                                                 { (yyval.exp) = boxRec((yyvsp[-2].exp),(yyvsp[0].exp)); }
#line 2925 "faustparser.cpp"
    break;

  case 194: /* argument: infixexp  */
#line 646 "faustparser.y"
                                                 { (yyval.exp) = (yyvsp[0].exp); }
#line 2931 "faustparser.cpp"
    break;

  case 195: /* string: STRING  */
#line 649 "faustparser.y"
                                                 { (yyval.exp) = tree(FAUSTtext); }
#line 2937 "faustparser.cpp"
    break;

  case 196: /* uqstring: STRING  */
#line 652 "faustparser.y"
                                                 { (yyval.exp) = unquote(FAUSTtext); }
#line 2943 "faustparser.cpp"
    break;

  case 197: /* fstring: STRING  */
#line 655 "faustparser.y"
                                                 { (yyval.exp) = tree(FAUSTtext); }
#line 2949 "faustparser.cpp"
    break;

  case 198: /* fstring: FSTRING  */
#line 656 "faustparser.y"
                                                 { (yyval.exp) = tree(FAUSTtext); }
#line 2955 "faustparser.cpp"
    break;

  case 199: /* fpar: IPAR LPAR ident PAR argument PAR expression RPAR  */
#line 662 "faustparser.y"
                                                { (yyval.exp) = boxIPar((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 2961 "faustparser.cpp"
    break;

  case 200: /* fseq: ISEQ LPAR ident PAR argument PAR expression RPAR  */
#line 666 "faustparser.y"
                                                { (yyval.exp) = boxISeq((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 2967 "faustparser.cpp"
    break;

  case 201: /* fsum: ISUM LPAR ident PAR argument PAR expression RPAR  */
#line 670 "faustparser.y"
                                                { (yyval.exp) = boxISum((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 2973 "faustparser.cpp"
    break;

  case 202: /* fprod: IPROD LPAR ident PAR argument PAR expression RPAR  */
#line 674 "faustparser.y"
                                                { (yyval.exp) = boxIProd((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 2979 "faustparser.cpp"
    break;

  case 203: /* finputs: INPUTS LPAR expression RPAR  */
#line 677 "faustparser.y"
                                              { (yyval.exp) = boxInputs((yyvsp[-1].exp)); }
#line 2985 "faustparser.cpp"
    break;

  case 204: /* foutputs: OUTPUTS LPAR expression RPAR  */
#line 680 "faustparser.y"
                                               { (yyval.exp) = boxOutputs((yyvsp[-1].exp)); }
#line 2991 "faustparser.cpp"
    break;

  case 205: /* ffunction: FFUNCTION LPAR signature PAR fstring PAR string RPAR  */
#line 686 "faustparser.y"
                                                { (yyval.exp) = ffunction((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 2997 "faustparser.cpp"
    break;

  case 206: /* fconst: FCONSTANT LPAR type name PAR fstring RPAR  */
#line 690 "faustparser.y"
                                                { (yyval.exp) = boxFConst((yyvsp[-4].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3003 "faustparser.cpp"
    break;

  case 207: /* fvariable: FVARIABLE LPAR type name PAR fstring RPAR  */
#line 694 "faustparser.y"
                                                { (yyval.exp) = boxFVar((yyvsp[-4].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3009 "faustparser.cpp"
    break;

  case 208: /* button: BUTTON LPAR uqstring RPAR  */
#line 698 "faustparser.y"
                                                 { (yyval.exp) = boxButton((yyvsp[-1].exp)); }
#line 3015 "faustparser.cpp"
    break;

  case 209: /* checkbox: CHECKBOX LPAR uqstring RPAR  */
#line 701 "faustparser.y"
                                                 { (yyval.exp) = boxCheckbox((yyvsp[-1].exp)); }
#line 3021 "faustparser.cpp"
    break;

  case 210: /* vslider: VSLIDER LPAR uqstring PAR argument PAR argument PAR argument PAR argument RPAR  */
#line 705 "faustparser.y"
                                                { (yyval.exp) = boxVSlider((yyvsp[-9].exp),(yyvsp[-7].exp),(yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3027 "faustparser.cpp"
    break;

  case 211: /* hslider: HSLIDER LPAR uqstring PAR argument PAR argument PAR argument PAR argument RPAR  */
#line 708 "faustparser.y"
                                                { (yyval.exp) = boxHSlider((yyvsp[-9].exp),(yyvsp[-7].exp),(yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3033 "faustparser.cpp"
    break;

  case 212: /* nentry: NENTRY LPAR uqstring PAR argument PAR argument PAR argument PAR argument RPAR  */
#line 711 "faustparser.y"
                                                { (yyval.exp) = boxNumEntry((yyvsp[-9].exp),(yyvsp[-7].exp),(yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3039 "faustparser.cpp"
    break;

  case 213: /* vgroup: VGROUP LPAR uqstring PAR expression RPAR  */
#line 714 "faustparser.y"
                                                { (yyval.exp) = boxVGroup((yyvsp[-3].exp), (yyvsp[-1].exp)); }
#line 3045 "faustparser.cpp"
    break;

  case 214: /* hgroup: HGROUP LPAR uqstring PAR expression RPAR  */
#line 717 "faustparser.y"
                                                { (yyval.exp) = boxHGroup((yyvsp[-3].exp), (yyvsp[-1].exp)); }
#line 3051 "faustparser.cpp"
    break;

  case 215: /* tgroup: TGROUP LPAR uqstring PAR expression RPAR  */
#line 720 "faustparser.y"
                                                { (yyval.exp) = boxTGroup((yyvsp[-3].exp), (yyvsp[-1].exp)); }
#line 3057 "faustparser.cpp"
    break;

  case 216: /* vbargraph: VBARGRAPH LPAR uqstring PAR argument PAR argument RPAR  */
#line 724 "faustparser.y"
                                                { (yyval.exp) = boxVBargraph((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3063 "faustparser.cpp"
    break;

  case 217: /* hbargraph: HBARGRAPH LPAR uqstring PAR argument PAR argument RPAR  */
#line 727 "faustparser.y"
                                                { (yyval.exp) = boxHBargraph((yyvsp[-5].exp),(yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3069 "faustparser.cpp"
    break;

  case 218: /* soundfile: SOUNDFILE LPAR uqstring PAR argument RPAR  */
#line 730 "faustparser.y"
                                                { (yyval.exp) = boxSoundfile((yyvsp[-3].exp),(yyvsp[-1].exp)); }
#line 3075 "faustparser.cpp"
    break;

  case 219: /* signature: type fun LPAR typelist RPAR  */
#line 736 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-4].exp),cons(cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),gGlobal->nil)))), (yyvsp[-1].exp))); }
#line 3081 "faustparser.cpp"
    break;

  case 220: /* signature: type fun OR fun LPAR typelist RPAR  */
#line 737 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-6].exp),cons(cons((yyvsp[-5].exp),cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),gGlobal->nil)))), (yyvsp[-1].exp))); }
#line 3087 "faustparser.cpp"
    break;

  case 221: /* signature: type fun OR fun OR fun LPAR typelist RPAR  */
#line 738 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-8].exp),cons(cons((yyvsp[-7].exp),cons((yyvsp[-5].exp),cons((yyvsp[-3].exp),cons((yyvsp[-3].exp),gGlobal->nil)))), (yyvsp[-1].exp))); }
#line 3093 "faustparser.cpp"
    break;

  case 222: /* signature: type fun OR fun OR fun OR fun LPAR typelist RPAR  */
#line 739 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-10].exp),cons(cons((yyvsp[-9].exp),cons((yyvsp[-7].exp),cons((yyvsp[-5].exp),cons((yyvsp[-3].exp),gGlobal->nil)))), (yyvsp[-1].exp))); }
#line 3099 "faustparser.cpp"
    break;

  case 223: /* signature: type fun LPAR RPAR  */
#line 741 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-3].exp),cons(cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),gGlobal->nil)))), gGlobal->nil)); }
#line 3105 "faustparser.cpp"
    break;

  case 224: /* signature: type fun OR fun LPAR RPAR  */
#line 742 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-5].exp),cons(cons((yyvsp[-4].exp),cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),gGlobal->nil)))), gGlobal->nil)); }
#line 3111 "faustparser.cpp"
    break;

  case 225: /* signature: type fun OR fun OR fun LPAR RPAR  */
#line 743 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-7].exp),cons(cons((yyvsp[-6].exp),cons((yyvsp[-4].exp),cons((yyvsp[-2].exp),cons((yyvsp[-2].exp),gGlobal->nil)))), gGlobal->nil)); }
#line 3117 "faustparser.cpp"
    break;

  case 226: /* signature: type fun OR fun OR fun OR fun LPAR RPAR  */
#line 744 "faustparser.y"
                                                                   { (yyval.exp) = cons((yyvsp[-9].exp),cons(cons((yyvsp[-8].exp),cons((yyvsp[-6].exp),cons((yyvsp[-4].exp),cons((yyvsp[-2].exp),gGlobal->nil)))), gGlobal->nil)); }
#line 3123 "faustparser.cpp"
    break;

  case 227: /* fun: IDENT  */
#line 747 "faustparser.y"
                                                { (yyval.exp) = tree(FAUSTtext); }
#line 3129 "faustparser.cpp"
    break;

  case 228: /* typelist: argtype  */
#line 750 "faustparser.y"
                                                { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 3135 "faustparser.cpp"
    break;

  case 229: /* typelist: typelist PAR argtype  */
#line 751 "faustparser.y"
                                                { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-2].exp)); }
#line 3141 "faustparser.cpp"
    break;

  case 230: /* rulelist: rule  */
#line 754 "faustparser.y"
                                                { (yyval.exp) = cons((yyvsp[0].exp),gGlobal->nil); }
#line 3147 "faustparser.cpp"
    break;

  case 231: /* rulelist: rulelist rule  */
#line 755 "faustparser.y"
                                                { (yyval.exp) = cons((yyvsp[0].exp),(yyvsp[-1].exp)); }
#line 3153 "faustparser.cpp"
    break;

  case 232: /* rule: LPAR arglist RPAR ARROW expression ENDDEF  */
#line 759 "faustparser.y"
                                                { (yyval.exp) = cons((yyvsp[-4].exp),(yyvsp[-1].exp)); }
#line 3159 "faustparser.cpp"
    break;

  case 233: /* type: INTCAST  */
#line 762 "faustparser.y"
                                                { (yyval.exp) = tree(0); }
#line 3165 "faustparser.cpp"
    break;

  case 234: /* type: FLOATCAST  */
#line 763 "faustparser.y"
                                                { (yyval.exp) = tree(1); }
#line 3171 "faustparser.cpp"
    break;

  case 235: /* argtype: INTCAST  */
#line 766 "faustparser.y"
                                                { (yyval.exp) = tree(0); }
#line 3177 "faustparser.cpp"
    break;

  case 236: /* argtype: FLOATCAST  */
#line 767 "faustparser.y"
                                                { (yyval.exp) = tree(1); }
#line 3183 "faustparser.cpp"
    break;

  case 237: /* argtype: NOTYPECAST  */
#line 768 "faustparser.y"
                                                { (yyval.exp) = tree(2); }
#line 3189 "faustparser.cpp"
    break;


#line 3193 "faustparser.cpp"

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

#line 771 "faustparser.y"

