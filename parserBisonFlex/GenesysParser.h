// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file ../GenesysParser.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_GENESYSPARSER_H_INCLUDED
# define YY_YY_GENESYSPARSER_H_INCLUDED
// "%code requires" blocks.
#line 9 "bisonparser.yy"

#include <string>
#include <cmath>
#include "obj_t.h"
#include "../Util.h"
//
// include to Plugin header files should be specified by plugins themselves
//
#include "../plugin/Variable.h"
#include "../Attribute.h"
#include "../Queue.h"
#include "../Formula.h"
#include "../Resource.h"
#include "../Set.h"
class genesyspp_driver;


#line 66 "../GenesysParser.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 200 "../GenesysParser.h"




  /// A Bison parser.
  class genesyspp_parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // NUMD
      // NUMH
      // CTEZERO
      // oLE
      // oGE
      // oEQ
      // oNE
      // oAND
      // oOR
      // oNOT
      // fSIN
      // fCOS
      // fROUND
      // fMOD
      // fTRUNC
      // fFRAC
      // fEXP
      // fRND1
      // fEXPO
      // fNORM
      // fUNIF
      // fWEIB
      // fLOGN
      // fGAMM
      // fERLA
      // fTRIA
      // fBETA
      // fDISC
      // fTNOW
      // fTFIN
      // cIF
      // cELSE
      // cFOR
      // cTO
      // cDO
      // ATRIB
      // ILLEGAL
      // RESOURCE
      // fNR
      // fMR
      // fIRF
      // fRESSEIZES
      // fSTATE
      // fSETSUM
      // QUEUE
      // fNQ
      // fFIRSTINQ
      // fLASTINQ
      // fSAQUE
      // fAQUE
      // SET
      // fNUMSET
      // CSTAT
      // fTAVG
      // VARI
      // FORM
      // input
      // programa
      // expressao
      // numero
      // aritmetica
      // relacional
      // comando
      // comandoIF
      // comandoFOR
      // funcao
      // funcaoKernel
      // funcaoTrig
      // funcaoArit
      // funcaoProb
      // funcaoUser
      // listaparm
      // illegal
      // atributo
      // variavel
      // atribuicao
      // formula
      // funcaoPlugin
      char dummy1[sizeof (obj_t)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        NUMD = 258,
        NUMH = 259,
        CTEZERO = 260,
        oLE = 261,
        oGE = 262,
        oEQ = 263,
        oNE = 264,
        oAND = 265,
        oOR = 266,
        oNOT = 267,
        fSIN = 268,
        fCOS = 269,
        fROUND = 270,
        fMOD = 271,
        fTRUNC = 272,
        fFRAC = 273,
        fEXP = 274,
        fRND1 = 275,
        fEXPO = 276,
        fNORM = 277,
        fUNIF = 278,
        fWEIB = 279,
        fLOGN = 280,
        fGAMM = 281,
        fERLA = 282,
        fTRIA = 283,
        fBETA = 284,
        fDISC = 285,
        fTNOW = 286,
        fTFIN = 287,
        cIF = 288,
        cELSE = 289,
        cFOR = 290,
        cTO = 291,
        cDO = 292,
        ATRIB = 293,
        ILLEGAL = 294,
        RESOURCE = 295,
        fNR = 296,
        fMR = 297,
        fIRF = 298,
        fRESSEIZES = 299,
        fSTATE = 300,
        fSETSUM = 301,
        QUEUE = 302,
        fNQ = 303,
        fFIRSTINQ = 304,
        fLASTINQ = 305,
        fSAQUE = 306,
        fAQUE = 307,
        SET = 308,
        fNUMSET = 309,
        CSTAT = 310,
        fTAVG = 311,
        VARI = 312,
        FORM = 313,
        LPAREN = 314,
        RPAREN = 315,
        LBRACKET = 316,
        RBRACKET = 317,
        PLUS = 318,
        MINUS = 319,
        STAR = 320,
        POWER = 321,
        SLASH = 322,
        LESS = 323,
        GREATER = 324,
        ASSIGN = 325,
        COMMA = 326,
        NEG = 327
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, obj_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const obj_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.template destroy< obj_t > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::END || tok == token::LPAREN || tok == token::RPAREN || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::PLUS || tok == token::MINUS || tok == token::STAR || tok == token::POWER || tok == token::SLASH || tok == token::LESS || tok == token::GREATER || tok == token::ASSIGN || tok == token::COMMA || tok == token::NEG || tok == 10 || tok == 328);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::END || tok == token::LPAREN || tok == token::RPAREN || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::PLUS || tok == token::MINUS || tok == token::STAR || tok == token::POWER || tok == token::SLASH || tok == token::LESS || tok == token::GREATER || tok == token::ASSIGN || tok == token::COMMA || tok == token::NEG || tok == 10 || tok == 328);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, obj_t v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::NUMD || tok == token::NUMH || tok == token::CTEZERO || tok == token::oLE || tok == token::oGE || tok == token::oEQ || tok == token::oNE || tok == token::oAND || tok == token::oOR || tok == token::oNOT || tok == token::fSIN || tok == token::fCOS || tok == token::fROUND || tok == token::fMOD || tok == token::fTRUNC || tok == token::fFRAC || tok == token::fEXP || tok == token::fRND1 || tok == token::fEXPO || tok == token::fNORM || tok == token::fUNIF || tok == token::fWEIB || tok == token::fLOGN || tok == token::fGAMM || tok == token::fERLA || tok == token::fTRIA || tok == token::fBETA || tok == token::fDISC || tok == token::fTNOW || tok == token::fTFIN || tok == token::cIF || tok == token::cELSE || tok == token::cFOR || tok == token::cTO || tok == token::cDO || tok == token::ATRIB || tok == token::ILLEGAL || tok == token::RESOURCE || tok == token::fNR || tok == token::fMR || tok == token::fIRF || tok == token::fRESSEIZES || tok == token::fSTATE || tok == token::fSETSUM || tok == token::QUEUE || tok == token::fNQ || tok == token::fFIRSTINQ || tok == token::fLASTINQ || tok == token::fSAQUE || tok == token::fAQUE || tok == token::SET || tok == token::fNUMSET || tok == token::CSTAT || tok == token::fTAVG || tok == token::VARI || tok == token::FORM);
      }
#else
      symbol_type (int tok, const obj_t& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::NUMD || tok == token::NUMH || tok == token::CTEZERO || tok == token::oLE || tok == token::oGE || tok == token::oEQ || tok == token::oNE || tok == token::oAND || tok == token::oOR || tok == token::oNOT || tok == token::fSIN || tok == token::fCOS || tok == token::fROUND || tok == token::fMOD || tok == token::fTRUNC || tok == token::fFRAC || tok == token::fEXP || tok == token::fRND1 || tok == token::fEXPO || tok == token::fNORM || tok == token::fUNIF || tok == token::fWEIB || tok == token::fLOGN || tok == token::fGAMM || tok == token::fERLA || tok == token::fTRIA || tok == token::fBETA || tok == token::fDISC || tok == token::fTNOW || tok == token::fTFIN || tok == token::cIF || tok == token::cELSE || tok == token::cFOR || tok == token::cTO || tok == token::cDO || tok == token::ATRIB || tok == token::ILLEGAL || tok == token::RESOURCE || tok == token::fNR || tok == token::fMR || tok == token::fIRF || tok == token::fRESSEIZES || tok == token::fSTATE || tok == token::fSETSUM || tok == token::QUEUE || tok == token::fNQ || tok == token::fFIRSTINQ || tok == token::fLASTINQ || tok == token::fSAQUE || tok == token::fAQUE || tok == token::SET || tok == token::fNUMSET || tok == token::CSTAT || tok == token::fTAVG || tok == token::VARI || tok == token::FORM);
      }
#endif
    };

    /// Build a parser object.
    genesyspp_parser (genesyspp_driver& driver_yyarg);
    virtual ~genesyspp_parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMD (obj_t v, location_type l)
      {
        return symbol_type (token::NUMD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMD (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::NUMD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMH (obj_t v, location_type l)
      {
        return symbol_type (token::NUMH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMH (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::NUMH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CTEZERO (obj_t v, location_type l)
      {
        return symbol_type (token::CTEZERO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CTEZERO (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::CTEZERO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_oLE (obj_t v, location_type l)
      {
        return symbol_type (token::oLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_oLE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::oLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_oGE (obj_t v, location_type l)
      {
        return symbol_type (token::oGE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_oGE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::oGE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_oEQ (obj_t v, location_type l)
      {
        return symbol_type (token::oEQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_oEQ (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::oEQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_oNE (obj_t v, location_type l)
      {
        return symbol_type (token::oNE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_oNE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::oNE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_oAND (obj_t v, location_type l)
      {
        return symbol_type (token::oAND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_oAND (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::oAND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_oOR (obj_t v, location_type l)
      {
        return symbol_type (token::oOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_oOR (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::oOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_oNOT (obj_t v, location_type l)
      {
        return symbol_type (token::oNOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_oNOT (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::oNOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fSIN (obj_t v, location_type l)
      {
        return symbol_type (token::fSIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fSIN (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fSIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fCOS (obj_t v, location_type l)
      {
        return symbol_type (token::fCOS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fCOS (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fCOS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fROUND (obj_t v, location_type l)
      {
        return symbol_type (token::fROUND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fROUND (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fROUND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fMOD (obj_t v, location_type l)
      {
        return symbol_type (token::fMOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fMOD (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fMOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fTRUNC (obj_t v, location_type l)
      {
        return symbol_type (token::fTRUNC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fTRUNC (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fTRUNC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fFRAC (obj_t v, location_type l)
      {
        return symbol_type (token::fFRAC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fFRAC (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fFRAC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fEXP (obj_t v, location_type l)
      {
        return symbol_type (token::fEXP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fEXP (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fEXP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fRND1 (obj_t v, location_type l)
      {
        return symbol_type (token::fRND1, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fRND1 (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fRND1, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fEXPO (obj_t v, location_type l)
      {
        return symbol_type (token::fEXPO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fEXPO (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fEXPO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fNORM (obj_t v, location_type l)
      {
        return symbol_type (token::fNORM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fNORM (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fNORM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fUNIF (obj_t v, location_type l)
      {
        return symbol_type (token::fUNIF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fUNIF (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fUNIF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fWEIB (obj_t v, location_type l)
      {
        return symbol_type (token::fWEIB, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fWEIB (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fWEIB, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fLOGN (obj_t v, location_type l)
      {
        return symbol_type (token::fLOGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fLOGN (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fLOGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fGAMM (obj_t v, location_type l)
      {
        return symbol_type (token::fGAMM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fGAMM (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fGAMM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fERLA (obj_t v, location_type l)
      {
        return symbol_type (token::fERLA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fERLA (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fERLA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fTRIA (obj_t v, location_type l)
      {
        return symbol_type (token::fTRIA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fTRIA (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fTRIA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fBETA (obj_t v, location_type l)
      {
        return symbol_type (token::fBETA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fBETA (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fBETA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fDISC (obj_t v, location_type l)
      {
        return symbol_type (token::fDISC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fDISC (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fDISC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fTNOW (obj_t v, location_type l)
      {
        return symbol_type (token::fTNOW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fTNOW (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fTNOW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fTFIN (obj_t v, location_type l)
      {
        return symbol_type (token::fTFIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fTFIN (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fTFIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_cIF (obj_t v, location_type l)
      {
        return symbol_type (token::cIF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_cIF (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::cIF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_cELSE (obj_t v, location_type l)
      {
        return symbol_type (token::cELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_cELSE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::cELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_cFOR (obj_t v, location_type l)
      {
        return symbol_type (token::cFOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_cFOR (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::cFOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_cTO (obj_t v, location_type l)
      {
        return symbol_type (token::cTO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_cTO (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::cTO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_cDO (obj_t v, location_type l)
      {
        return symbol_type (token::cDO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_cDO (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::cDO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATRIB (obj_t v, location_type l)
      {
        return symbol_type (token::ATRIB, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ATRIB (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::ATRIB, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ILLEGAL (obj_t v, location_type l)
      {
        return symbol_type (token::ILLEGAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ILLEGAL (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::ILLEGAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESOURCE (obj_t v, location_type l)
      {
        return symbol_type (token::RESOURCE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RESOURCE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::RESOURCE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fNR (obj_t v, location_type l)
      {
        return symbol_type (token::fNR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fNR (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fNR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fMR (obj_t v, location_type l)
      {
        return symbol_type (token::fMR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fMR (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fMR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fIRF (obj_t v, location_type l)
      {
        return symbol_type (token::fIRF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fIRF (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fIRF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fRESSEIZES (obj_t v, location_type l)
      {
        return symbol_type (token::fRESSEIZES, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fRESSEIZES (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fRESSEIZES, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fSTATE (obj_t v, location_type l)
      {
        return symbol_type (token::fSTATE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fSTATE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fSTATE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fSETSUM (obj_t v, location_type l)
      {
        return symbol_type (token::fSETSUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fSETSUM (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fSETSUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUEUE (obj_t v, location_type l)
      {
        return symbol_type (token::QUEUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_QUEUE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::QUEUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fNQ (obj_t v, location_type l)
      {
        return symbol_type (token::fNQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fNQ (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fNQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fFIRSTINQ (obj_t v, location_type l)
      {
        return symbol_type (token::fFIRSTINQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fFIRSTINQ (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fFIRSTINQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fLASTINQ (obj_t v, location_type l)
      {
        return symbol_type (token::fLASTINQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fLASTINQ (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fLASTINQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fSAQUE (obj_t v, location_type l)
      {
        return symbol_type (token::fSAQUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fSAQUE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fSAQUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fAQUE (obj_t v, location_type l)
      {
        return symbol_type (token::fAQUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fAQUE (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fAQUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SET (obj_t v, location_type l)
      {
        return symbol_type (token::SET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SET (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::SET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fNUMSET (obj_t v, location_type l)
      {
        return symbol_type (token::fNUMSET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fNUMSET (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fNUMSET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CSTAT (obj_t v, location_type l)
      {
        return symbol_type (token::CSTAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CSTAT (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::CSTAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_fTAVG (obj_t v, location_type l)
      {
        return symbol_type (token::fTAVG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_fTAVG (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::fTAVG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VARI (obj_t v, location_type l)
      {
        return symbol_type (token::VARI, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VARI (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::VARI, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORM (obj_t v, location_type l)
      {
        return symbol_type (token::FORM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FORM (const obj_t& v, const location_type& l)
      {
        return symbol_type (token::FORM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (location_type l)
      {
        return symbol_type (token::LBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const location_type& l)
      {
        return symbol_type (token::LBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (location_type l)
      {
        return symbol_type (token::RBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const location_type& l)
      {
        return symbol_type (token::RBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POWER (location_type l)
      {
        return symbol_type (token::POWER, std::move (l));
      }
#else
      static
      symbol_type
      make_POWER (const location_type& l)
      {
        return symbol_type (token::POWER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (location_type l)
      {
        return symbol_type (token::LESS, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const location_type& l)
      {
        return symbol_type (token::LESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (location_type l)
      {
        return symbol_type (token::GREATER, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const location_type& l)
      {
        return symbol_type (token::GREATER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif


  private:
    /// This class is not copyable.
    genesyspp_parser (const genesyspp_parser&);
    genesyspp_parser& operator= (const genesyspp_parser&);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 1570,     ///< Last index in yytable_.
      yynnts_ = 23,  ///< Number of nonterminal symbols.
      yyfinal_ = 6, ///< Termination state number.
      yyntokens_ = 75  ///< Number of tokens.
    };


    // User arguments.
    genesyspp_driver& driver;
  };

  inline
  genesyspp_parser::token_number_type
  genesyspp_parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      73,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    74
    };
    const int user_token_number_max_ = 328;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  genesyspp_parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.move< obj_t > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  genesyspp_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.copy< obj_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  genesyspp_parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  genesyspp_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.move< obj_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  genesyspp_parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  genesyspp_parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  genesyspp_parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  genesyspp_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  genesyspp_parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  genesyspp_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  genesyspp_parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 2687 "../GenesysParser.h"





#endif // !YY_YY_GENESYSPARSER_H_INCLUDED
