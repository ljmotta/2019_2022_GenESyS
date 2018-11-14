// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

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


// First part of user declarations.

#line 37 "Genesys++-parser.cpp" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "Genesys++-parser.h"

// User implementation prologue.

#line 51 "Genesys++-parser.cpp" // lalr1.cc:415
// Unqualified %code blocks.
#line 34 "Genesys++-parser.yy" // lalr1.cc:416

# include "Genesys++-driver.h"


#line 58 "Genesys++-parser.cpp" // lalr1.cc:416


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 153 "Genesys++-parser.cpp" // lalr1.cc:491

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  genesyspp_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  genesyspp_parser::genesyspp_parser (genesyspp_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  genesyspp_parser::~genesyspp_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  genesyspp_parser::by_state::by_state ()
    : state (empty_state)
  {}

  genesyspp_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  genesyspp_parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  genesyspp_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  genesyspp_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  genesyspp_parser::symbol_number_type
  genesyspp_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  genesyspp_parser::stack_symbol_type::stack_symbol_type ()
  {}

  genesyspp_parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    switch (that.type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // ATRIB
      case 6: // VARI
      case 7: // FORM
      case 8: // QUEUE
      case 9: // RES
      case 10: // oLE
      case 11: // oGE
      case 12: // oEQ
      case 13: // oNE
      case 14: // oAND
      case 15: // oOR
      case 16: // oNOT
      case 17: // fSIN
      case 18: // fCOS
      case 19: // fAINT
      case 20: // fMOD
      case 21: // fINT
      case 22: // fFRAC
      case 23: // fEXPO
      case 24: // fNORM
      case 25: // fUNIF
      case 26: // fWEIB
      case 27: // fLOGN
      case 28: // fGAMM
      case 29: // fERLA
      case 30: // fTRIA
      case 31: // fBETA
      case 32: // fDISC
      case 33: // fTNOW
      case 34: // fTFIN
      case 35: // fNR
      case 36: // fMR
      case 37: // fIRF
      case 38: // fRESSEIZES
      case 39: // fSTATE
      case 40: // fNQ
      case 41: // fFIRSTINQ
      case 42: // fLASTINQ
      case 43: // cIF
      case 44: // cELSE
      case 45: // cFOR
      case 46: // cTO
      case 47: // cDO
      case 48: // ILLEGAL
      case 49: // TESTE
      case 71: // input
      case 72: // programa
      case 73: // expressao
      case 74: // numero
      case 75: // aritmetica
      case 76: // relacional
      case 77: // comando
      case 78: // comandoIF
      case 79: // comandoFOR
      case 80: // funcao
      case 81: // atributo
      case 82: // atribuicao
      case 83: // variavel
      case 84: // formula
      case 85: // funcaoTrig
      case 86: // funcaoArit
      case 87: // funcaoProb
      case 88: // funcaoStrc
      case 89: // funcaoUser
      case 90: // listaparm
      case 91: // illegal
        value.copy< obj_t > (that.value);
        break;

      default:
        break;
    }

  }

  genesyspp_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    switch (that.type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // ATRIB
      case 6: // VARI
      case 7: // FORM
      case 8: // QUEUE
      case 9: // RES
      case 10: // oLE
      case 11: // oGE
      case 12: // oEQ
      case 13: // oNE
      case 14: // oAND
      case 15: // oOR
      case 16: // oNOT
      case 17: // fSIN
      case 18: // fCOS
      case 19: // fAINT
      case 20: // fMOD
      case 21: // fINT
      case 22: // fFRAC
      case 23: // fEXPO
      case 24: // fNORM
      case 25: // fUNIF
      case 26: // fWEIB
      case 27: // fLOGN
      case 28: // fGAMM
      case 29: // fERLA
      case 30: // fTRIA
      case 31: // fBETA
      case 32: // fDISC
      case 33: // fTNOW
      case 34: // fTFIN
      case 35: // fNR
      case 36: // fMR
      case 37: // fIRF
      case 38: // fRESSEIZES
      case 39: // fSTATE
      case 40: // fNQ
      case 41: // fFIRSTINQ
      case 42: // fLASTINQ
      case 43: // cIF
      case 44: // cELSE
      case 45: // cFOR
      case 46: // cTO
      case 47: // cDO
      case 48: // ILLEGAL
      case 49: // TESTE
      case 71: // input
      case 72: // programa
      case 73: // expressao
      case 74: // numero
      case 75: // aritmetica
      case 76: // relacional
      case 77: // comando
      case 78: // comandoIF
      case 79: // comandoFOR
      case 80: // funcao
      case 81: // atributo
      case 82: // atribuicao
      case 83: // variavel
      case 84: // formula
      case 85: // funcaoTrig
      case 86: // funcaoArit
      case 87: // funcaoProb
      case 88: // funcaoStrc
      case 89: // funcaoUser
      case 90: // listaparm
      case 91: // illegal
        value.move< obj_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  genesyspp_parser::stack_symbol_type&
  genesyspp_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // ATRIB
      case 6: // VARI
      case 7: // FORM
      case 8: // QUEUE
      case 9: // RES
      case 10: // oLE
      case 11: // oGE
      case 12: // oEQ
      case 13: // oNE
      case 14: // oAND
      case 15: // oOR
      case 16: // oNOT
      case 17: // fSIN
      case 18: // fCOS
      case 19: // fAINT
      case 20: // fMOD
      case 21: // fINT
      case 22: // fFRAC
      case 23: // fEXPO
      case 24: // fNORM
      case 25: // fUNIF
      case 26: // fWEIB
      case 27: // fLOGN
      case 28: // fGAMM
      case 29: // fERLA
      case 30: // fTRIA
      case 31: // fBETA
      case 32: // fDISC
      case 33: // fTNOW
      case 34: // fTFIN
      case 35: // fNR
      case 36: // fMR
      case 37: // fIRF
      case 38: // fRESSEIZES
      case 39: // fSTATE
      case 40: // fNQ
      case 41: // fFIRSTINQ
      case 42: // fLASTINQ
      case 43: // cIF
      case 44: // cELSE
      case 45: // cFOR
      case 46: // cTO
      case 47: // cDO
      case 48: // ILLEGAL
      case 49: // TESTE
      case 71: // input
      case 72: // programa
      case 73: // expressao
      case 74: // numero
      case 75: // aritmetica
      case 76: // relacional
      case 77: // comando
      case 78: // comandoIF
      case 79: // comandoFOR
      case 80: // funcao
      case 81: // atributo
      case 82: // atribuicao
      case 83: // variavel
      case 84: // formula
      case 85: // funcaoTrig
      case 86: // funcaoArit
      case 87: // funcaoProb
      case 88: // funcaoStrc
      case 89: // funcaoUser
      case 90: // listaparm
      case 91: // illegal
        value.copy< obj_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  genesyspp_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  genesyspp_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  genesyspp_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  genesyspp_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  genesyspp_parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  genesyspp_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  genesyspp_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  genesyspp_parser::debug_level_type
  genesyspp_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  genesyspp_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  genesyspp_parser::state_type
  genesyspp_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  genesyspp_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  genesyspp_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  genesyspp_parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
    #line 27 "Genesys++-parser.yy" // lalr1.cc:746
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.getFile();
}

#line 637 "Genesys++-parser.cpp" // lalr1.cc:746

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // ATRIB
      case 6: // VARI
      case 7: // FORM
      case 8: // QUEUE
      case 9: // RES
      case 10: // oLE
      case 11: // oGE
      case 12: // oEQ
      case 13: // oNE
      case 14: // oAND
      case 15: // oOR
      case 16: // oNOT
      case 17: // fSIN
      case 18: // fCOS
      case 19: // fAINT
      case 20: // fMOD
      case 21: // fINT
      case 22: // fFRAC
      case 23: // fEXPO
      case 24: // fNORM
      case 25: // fUNIF
      case 26: // fWEIB
      case 27: // fLOGN
      case 28: // fGAMM
      case 29: // fERLA
      case 30: // fTRIA
      case 31: // fBETA
      case 32: // fDISC
      case 33: // fTNOW
      case 34: // fTFIN
      case 35: // fNR
      case 36: // fMR
      case 37: // fIRF
      case 38: // fRESSEIZES
      case 39: // fSTATE
      case 40: // fNQ
      case 41: // fFIRSTINQ
      case 42: // fLASTINQ
      case 43: // cIF
      case 44: // cELSE
      case 45: // cFOR
      case 46: // cTO
      case 47: // cDO
      case 48: // ILLEGAL
      case 49: // TESTE
      case 71: // input
      case 72: // programa
      case 73: // expressao
      case 74: // numero
      case 75: // aritmetica
      case 76: // relacional
      case 77: // comando
      case 78: // comandoIF
      case 79: // comandoFOR
      case 80: // funcao
      case 81: // atributo
      case 82: // atribuicao
      case 83: // variavel
      case 84: // formula
      case 85: // funcaoTrig
      case 86: // funcaoArit
      case 87: // funcaoProb
      case 88: // funcaoStrc
      case 89: // funcaoUser
      case 90: // listaparm
      case 91: // illegal
        yylhs.value.build< obj_t > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3:
#line 135 "Genesys++-parser.yy" // lalr1.cc:870
    {YYACCEPT;}
#line 824 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 4:
#line 136 "Genesys++-parser.yy" // lalr1.cc:870
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor); driver.getModel()->getTracer()->trace(Util::TraceLevel::mostDetailed, std::string("Resultado"));}
#line 830 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 6:
#line 138 "Genesys++-parser.yy" // lalr1.cc:870
    { yyerrok; }
#line 836 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 7:
#line 141 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 842 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 8:
#line 144 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 848 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 9:
#line 145 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 854 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 10:
#line 146 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 860 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 11:
#line 147 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 866 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 12:
#line 148 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 872 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 13:
#line 149 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 878 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 14:
#line 150 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 884 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 15:
#line 151 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 890 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 16:
#line 152 "Genesys++-parser.yy" // lalr1.cc:870
    {}
#line 896 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 17:
#line 155 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 902 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 18:
#line 156 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 908 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 19:
#line 159 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 914 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 20:
#line 160 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 920 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 21:
#line 161 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 926 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 22:
#line 162 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 932 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 23:
#line 165 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 938 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 24:
#line 166 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 944 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 25:
#line 167 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 950 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 26:
#line 168 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 956 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 27:
#line 169 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 962 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 28:
#line 170 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 968 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 29:
#line 171 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 974 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 30:
#line 172 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 980 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 33:
#line 179 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor;}
#line 986 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 34:
#line 180 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 992 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 35:
#line 183 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = 0; 																							std::cout << "FOR " << yystack_[4].value.as< obj_t > ().valor << " TO " << yystack_[2].value.as< obj_t > ().valor << " DO " << yystack_[0].value.as< obj_t > ().valor << '\n';}
#line 998 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 36:
#line 184 "Genesys++-parser.yy" // lalr1.cc:870
    {yylhs.value.as< obj_t > ().valor = 0; 																							std::cout << "FOR " << yystack_[4].value.as< obj_t > ().valor << " TO " << yystack_[2].value.as< obj_t > ().valor << " DO " << yystack_[0].value.as< obj_t > ().valor << '\n';}
#line 1004 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 37:
#line 187 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1010 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 38:
#line 188 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1016 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 39:
#line 189 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1022 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 40:
#line 190 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1028 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 41:
#line 191 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1034 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 42:
#line 196 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1040 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 43:
#line 200 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1046 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 44:
#line 201 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1052 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 45:
#line 204 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1058 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 46:
#line 205 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(std::to_string(yystack_[1].value.as< obj_t > ().valor));}
#line 1064 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 47:
#line 206 "Genesys++-parser.yy" // lalr1.cc:870
    { std::string index(std::to_string(yystack_[3].value.as< obj_t > ().valor)); index.append(","); index.append(std::to_string(yystack_[1].value.as< obj_t > ().valor)); yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 1070 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 48:
#line 210 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1076 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 49:
#line 213 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor);                                         std::cout << "Sin(" << yystack_[1].value.as< obj_t > ().valor << "):" << yylhs.value.as< obj_t > ().valor << '\n';}
#line 1082 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 50:
#line 214 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); 																				std::cout << "Cos(" << yystack_[1].value.as< obj_t > ().valor << "):" << yylhs.value.as< obj_t > ().valor << '\n';}
#line 1088 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 51:
#line 217 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1094 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 52:
#line 218 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1100 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 53:
#line 219 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1106 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 54:
#line 220 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1112 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 55:
#line 223 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().exponential(0,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1118 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 56:
#line 224 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().normal(0,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1124 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 57:
#line 225 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().uniform(0,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Unificada"; }
#line 1130 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 58:
#line 226 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().weibull(0,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1136 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 59:
#line 227 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().logNormal(0,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1142 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 60:
#line 228 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().gamma(0,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1148 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 61:
#line 229 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().erlang(0,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1154 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 62:
#line 230 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().triangular(0,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1160 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 63:
#line 231 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getProbs().beta(0,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1166 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 65:
#line 235 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1172 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 66:
#line 236 "Genesys++-parser.yy" // lalr1.cc:870
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1178 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 67:
#line 237 "Genesys++-parser.yy" // lalr1.cc:870
    { if (((Queue*)(driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
                                                                    yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->getId();
                                                                  }else{
                                                                    yylhs.value.as< obj_t > ().valor = 0;
                                                                  }
                                                                }
#line 1189 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 68:
#line 243 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1195 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 69:
#line 244 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1201 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 70:
#line 245 "Genesys++-parser.yy" // lalr1.cc:870
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1207 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 71:
#line 246 "Genesys++-parser.yy" // lalr1.cc:870
    {  switch(((Resource*)driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState()){
                                                                    case Resource::ResourceState::IDLE:
                                                                      yylhs.value.as< obj_t > ().valor = -1;
                                                                      break;
                                                                    case Resource::ResourceState::BUSY:
                                                                      yylhs.value.as< obj_t > ().valor = -2;
                                                                      break;
                                                                    case Resource::ResourceState::FAILED:
                                                                      yylhs.value.as< obj_t > ().valor = -4;
                                                                      break;
                                                                    case Resource::ResourceState::INACTIVE:
                                                                      yylhs.value.as< obj_t > ().valor = -3;
                                                                    default:
                                                                      yylhs.value.as< obj_t > ().valor = -5;
                                                                      break;
                                                                  }
                                                                }
#line 1229 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 72:
#line 264 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getInfraManager()->getInfrastructure(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1235 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 73:
#line 265 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1241 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 74:
#line 266 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getInfos()->getReplicationLength();}
#line 1247 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 75:
#line 270 "Genesys++-parser.yy" // lalr1.cc:870
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1253 "Genesys++-parser.cpp" // lalr1.cc:870
    break;

  case 78:
#line 278 "Genesys++-parser.yy" // lalr1.cc:870
    {
                                                                  driver.setResult(-1);
                                                                  if(driver.getThrowsException()){
                                                                    if(yystack_[0].value.as< obj_t > ().valor == 0){
                                                                      //throw std::string("Literal nao encontrado");
                                                                    }else if(yystack_[0].value.as< obj_t > ().valor == 1){
                                                                      //throw std::string("Caracter invalido encontrado");
                                                                    }
                                                                  }else{
                                                                    if(yystack_[0].value.as< obj_t > ().valor == 0){
                                                                      driver.setErrorMessage(std::string("Literal nao encontrado"));
                                                                    }else if(yystack_[0].value.as< obj_t > ().valor == 1){
                                                                      driver.setErrorMessage(std::string("Caracter invalido encontrado"));
                                                                    }
                                                                  }
                                                                }
#line 1274 "Genesys++-parser.cpp" // lalr1.cc:870
    break;


#line 1278 "Genesys++-parser.cpp" // lalr1.cc:870
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  genesyspp_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  genesyspp_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char genesyspp_parser::yypact_ninf_ = -81;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short
  genesyspp_parser::yypact_[] =
  {
     164,   -63,   -81,   217,   -81,   -81,   -81,   -81,   -81,   -81,
     -54,   -36,   -35,   -34,   -33,   -32,    -8,    -7,    -5,    -4,
      -3,    -2,    12,    13,    14,    15,    16,   -81,   -81,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     6,   270,
     -81,    27,   -81,   825,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,    67,    75,    77,    78,    79,
      83,    84,    98,   270,   -81,    35,    49,   495,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,    26,   502,   509,   557,   311,   564,   571,   578,   319,
     330,   338,   346,   396,   404,   412,   420,   428,   -49,    57,
      58,    60,    61,    62,    72,    74,    76,   585,   270,   270,
     -81,   592,   -48,   -48,   -48,   -48,    91,    91,   825,   -48,
     825,   825,   825,   825,   270,   -81,   -81,   -81,   -81,   270,
     -81,   -81,   -81,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   -81,   270,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   270,   640,   652,   -81,    85,   659,   666,   714,
     721,   728,   735,   742,   478,   749,   825,   486,   797,   270,
     270,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   270,
     -81,   270,   270,   808,   819,   832,   825,   825,     6,     6,
     -81,    68,   -81,    70,   -81,   270,   270,   825,   825
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    78,     0,     5,     6,     1,    17,    18,    12,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     4,     7,    15,     8,     9,    16,    31,    32,
      11,    13,    14,    38,    37,    39,    40,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,    26,    28,    29,    30,    23,    24,    19,    20,
      22,    21,    25,    27,     0,    46,    49,    50,    51,     0,
      53,    52,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,     0,    69,    68,    72,    70,    71,    65,
      67,    66,     0,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,    34,     0,
       0,    47,    54,    56,    57,    58,    59,    60,    61,     0,
      63,     0,     0,     0,     0,     0,    76,    33,     0,     0,
      62,     0,    36,     0,    35,     0,     0,    43,    44
  };

  const signed char
  genesyspp_parser::yypgoto_[] =
  {
     -81,   -81,   -81,   -39,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,    92,   -80,   -37,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81
  };

  const short
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   211,   212,    51,    52,    53,    54,    55,    56,    57,
     118,     4
  };

  const short
  genesyspp_parser::yytable_[] =
  {
      87,    86,   162,     5,    95,    96,    97,    98,    99,   100,
     163,    84,    10,    58,    59,    60,    61,    62,    63,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    89,    90,    91,    92,
      93,    94,    64,    65,   127,    66,    67,    68,    69,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,   119,    88,    95,    96,
      97,    98,    99,   100,   120,   144,   121,   122,   123,   173,
     174,   124,   125,   128,   145,    89,    90,    91,    92,    93,
      94,    89,    90,    91,    92,   176,   126,   129,   164,   165,
     177,   166,   167,   168,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   169,   187,   170,   215,   171,   216,   214,
      85,     0,     0,   188,     0,     0,     0,    95,    96,    97,
      98,    99,   100,    95,    96,    97,    98,    99,   100,     0,
     203,   204,     0,   191,     0,     0,     0,     0,     0,     0,
     205,     0,   206,   207,    -2,     1,     0,    -2,    -2,    -2,
      -2,   213,   213,     0,     0,     0,   217,   218,     0,     0,
       0,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,     0,    -2,
       0,     0,     2,     0,    -2,     0,     0,     6,     0,     0,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
      -2,     0,     0,    -2,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     0,    38,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,    40,     0,     0,    41,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     0,    38,     0,     0,     0,     0,
      39,    89,    90,    91,    92,    93,    94,     0,     0,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,    41,
      89,    90,    91,    92,    93,    94,     0,     0,    89,    90,
      91,    92,    93,    94,     0,     0,    89,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,    99,   100,     0,
     149,    95,    96,    97,    98,    99,   100,     0,   153,     0,
       0,     0,    95,    96,    97,    98,    99,   100,     0,   154,
      95,    96,    97,    98,    99,   100,     0,   155,    95,    96,
      97,    98,    99,   100,     0,   156,    89,    90,    91,    92,
      93,    94,     0,     0,    89,    90,    91,    92,    93,    94,
       0,     0,    89,    90,    91,    92,    93,    94,     0,     0,
      89,    90,    91,    92,    93,    94,     0,     0,    89,    90,
      91,    92,    93,    94,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,     0,   157,    95,    96,    97,    98,
      99,   100,     0,   158,    95,    96,    97,    98,    99,   100,
       0,   159,    95,    96,    97,    98,    99,   100,     0,   160,
      95,    96,    97,    98,    99,   100,     0,   161,    89,    90,
      91,    92,    93,    94,     0,     0,    89,    90,    91,    92,
      93,    94,     0,     0,     0,    89,    90,    91,    92,    93,
      94,     0,    89,    90,    91,    92,    93,    94,     0,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,     0,   199,    95,    96,
      97,    98,    99,   100,     0,   201,   130,    95,    96,    97,
      98,    99,   100,   146,    95,    96,    97,    98,    99,   100,
     147,    95,    96,    97,    98,    99,   100,    89,    90,    91,
      92,    93,    94,     0,    89,    90,    91,    92,    93,    94,
       0,    89,    90,    91,    92,    93,    94,     0,    89,    90,
      91,    92,    93,    94,     0,    89,    90,    91,    92,    93,
      94,     0,    89,    90,    91,    92,    93,    94,   148,    95,
      96,    97,    98,    99,   100,   150,    95,    96,    97,    98,
      99,   100,   151,    95,    96,    97,    98,    99,   100,   152,
      95,    96,    97,    98,    99,   100,   172,    95,    96,    97,
      98,    99,   100,   175,    95,    96,    97,    98,    99,   100,
      89,    90,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,    93,    94,     0,    89,
      90,    91,    92,    93,    94,     0,    89,    90,    91,    92,
      93,    94,     0,     0,     0,     0,   189,     0,     0,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   190,     0,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     192,    95,    96,    97,    98,    99,   100,   193,    95,    96,
      97,    98,    99,   100,    89,    90,    91,    92,    93,    94,
       0,    89,    90,    91,    92,    93,    94,     0,    89,    90,
      91,    92,    93,    94,     0,    89,    90,    91,    92,    93,
      94,     0,    89,    90,    91,    92,    93,    94,     0,    89,
      90,    91,    92,    93,    94,   194,    95,    96,    97,    98,
      99,   100,   195,    95,    96,    97,    98,    99,   100,   196,
      95,    96,    97,    98,    99,   100,   197,    95,    96,    97,
      98,    99,   100,   198,    95,    96,    97,    98,    99,   100,
     200,    95,    96,    97,    98,    99,   100,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,    89,    90,
      91,    92,    93,    94,     0,     0,     0,     0,     0,    89,
      90,    91,    92,    93,    94,    89,    90,    91,    92,    93,
      94,   202,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,   208,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   209,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,    95,    96,    97,
      98,    99,   100,   210,    95,    96,    97,    98,    99,   100
  };

  const short
  genesyspp_parser::yycheck_[] =
  {
      39,    38,    51,    66,    52,    53,    54,    55,    56,    57,
      59,     5,     6,    67,    50,    50,    50,    50,    50,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    10,    11,    12,    13,
      14,    15,    50,    50,    83,    50,    50,    50,    50,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,     9,    50,    52,    53,
      54,    55,    56,    57,     9,    59,     9,     9,     9,   128,
     129,     8,     8,    58,    68,    10,    11,    12,    13,    14,
      15,    10,    11,    12,    13,   144,     8,    58,    51,    51,
     149,    51,    51,    51,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    51,   163,    51,    58,    51,    58,   209,
      38,    -1,    -1,   172,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    52,    53,    54,    55,    56,    57,    -1,
     189,   190,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,     0,     1,    -1,     3,     4,     5,
       6,   208,   209,    -1,    -1,    -1,   215,   216,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
      -1,    -1,    48,    -1,    50,    -1,    -1,     0,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    69,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    69,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      50,    10,    11,    12,    13,    14,    15,    -1,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    69,
      10,    11,    12,    13,    14,    15,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    10,    11,    12,    13,
      14,    15,    -1,    52,    53,    54,    55,    56,    57,    -1,
      59,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    59,
      52,    53,    54,    55,    56,    57,    -1,    59,    52,    53,
      54,    55,    56,    57,    -1,    59,    10,    11,    12,    13,
      14,    15,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,    59,    52,    53,    54,    55,
      56,    57,    -1,    59,    52,    53,    54,    55,    56,    57,
      -1,    59,    52,    53,    54,    55,    56,    57,    -1,    59,
      52,    53,    54,    55,    56,    57,    -1,    59,    10,    11,
      12,    13,    14,    15,    -1,    -1,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    -1,    59,    52,    53,
      54,    55,    56,    57,    -1,    59,    51,    52,    53,    54,
      55,    56,    57,    51,    52,    53,    54,    55,    56,    57,
      51,    52,    53,    54,    55,    56,    57,    10,    11,    12,
      13,    14,    15,    -1,    10,    11,    12,    13,    14,    15,
      -1,    10,    11,    12,    13,    14,    15,    -1,    10,    11,
      12,    13,    14,    15,    -1,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    51,    52,
      53,    54,    55,    56,    57,    51,    52,    53,    54,    55,
      56,    57,    51,    52,    53,    54,    55,    56,    57,    51,
      52,    53,    54,    55,    56,    57,    51,    52,    53,    54,
      55,    56,    57,    51,    52,    53,    54,    55,    56,    57,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    10,
      11,    12,    13,    14,    15,    -1,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    46,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      51,    52,    53,    54,    55,    56,    57,    51,    52,    53,
      54,    55,    56,    57,    10,    11,    12,    13,    14,    15,
      -1,    10,    11,    12,    13,    14,    15,    -1,    10,    11,
      12,    13,    14,    15,    -1,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    10,
      11,    12,    13,    14,    15,    51,    52,    53,    54,    55,
      56,    57,    51,    52,    53,    54,    55,    56,    57,    51,
      52,    53,    54,    55,    56,    57,    51,    52,    53,    54,
      55,    56,    57,    51,    52,    53,    54,    55,    56,    57,
      51,    52,    53,    54,    55,    56,    57,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    10,    11,    12,    13,    14,
      15,    44,    10,    11,    12,    13,    14,    15,    -1,    52,
      53,    54,    55,    56,    57,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    47,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    52,    53,    54,
      55,    56,    57,    51,    52,    53,    54,    55,    56,    57
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    48,    71,    91,    66,     0,     3,     4,     5,
       6,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    45,    50,
      66,    69,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    83,    84,    85,    86,    87,    88,    89,    67,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,     5,    81,    83,    73,    50,    10,
      11,    12,    13,    14,    15,    52,    53,    54,    55,    56,
      57,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    90,     9,
       9,     9,     9,     9,     8,     8,     8,    73,    58,    58,
      51,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    59,    68,    51,    51,    51,    59,
      51,    51,    51,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    51,    59,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    73,    73,    51,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    46,
      46,    68,    51,    51,    51,    51,    51,    51,    51,    59,
      51,    59,    44,    73,    73,    73,    73,    73,    47,    47,
      51,    81,    82,    83,    82,    58,    58,    73,    73
  };

  const unsigned char
  genesyspp_parser::yyr1_[] =
  {
       0,    70,    71,    71,    71,    71,    71,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    81,    82,    82,    83,    83,    83,    84,    85,
      85,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    91
  };

  const unsigned char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     7,     5,     8,     8,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     4,     6,     1,     4,
       4,     4,     4,     4,     6,     4,     6,     6,     6,     6,
       6,     6,     8,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     4,     5,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NUMD", "NUMH", "ATRIB",
  "VARI", "FORM", "QUEUE", "RES", "oLE", "oGE", "oEQ", "oNE", "oAND",
  "oOR", "oNOT", "fSIN", "fCOS", "fAINT", "fMOD", "fINT", "fFRAC", "fEXPO",
  "fNORM", "fUNIF", "fWEIB", "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA",
  "fDISC", "fTNOW", "fTFIN", "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE",
  "fNQ", "fFIRSTINQ", "fLASTINQ", "cIF", "cELSE", "cFOR", "cTO", "cDO",
  "ILLEGAL", "TESTE", "\"(\"", "\")\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"<\"", "\">\"", "\"=\"", "\",\"", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'\\n'", "\"[\"", "\"]\"", "\"USER\"", "$accept", "input",
  "programa", "expressao", "numero", "aritmetica", "relacional", "comando",
  "comandoIF", "comandoFOR", "funcao", "atributo", "atribuicao",
  "variavel", "formula", "funcaoTrig", "funcaoArit", "funcaoProb",
  "funcaoStrc", "funcaoUser", "listaparm", "illegal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  genesyspp_parser::yyrline_[] =
  {
       0,   134,   134,   135,   136,   137,   138,   141,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   155,   156,   159,
     160,   161,   162,   165,   166,   167,   168,   169,   170,   171,
     172,   175,   176,   179,   180,   183,   184,   187,   188,   189,
     190,   191,   196,   200,   201,   204,   205,   206,   210,   213,
     214,   217,   218,   219,   220,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   235,   236,   237,   243,   244,
     245,   246,   264,   265,   266,   270,   274,   275,   278
  };

  // Print the state stack on the debug stream.
  void
  genesyspp_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  genesyspp_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1919 "Genesys++-parser.cpp" // lalr1.cc:1181
#line 296 "Genesys++-parser.yy" // lalr1.cc:1182

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
