// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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

#line 37 "../GenesysParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "GenesysParser.h"

// User implementation prologue.

#line 51 "../GenesysParser.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 39 "bisonparser.yy" // lalr1.cc:413

# include "Genesys++-driver.h"


#line 58 "../GenesysParser.cpp" // lalr1.cc:413


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
      *yycdebug_ << std::endl;                  \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 144 "../GenesysParser.cpp" // lalr1.cc:479

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
  inline
  genesyspp_parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  genesyspp_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  genesyspp_parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  genesyspp_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  genesyspp_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  genesyspp_parser::symbol_number_type
  genesyspp_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  genesyspp_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  genesyspp_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
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
      case 20: // fEXPO
      case 21: // fNORM
      case 22: // fUNIF
      case 23: // fWEIB
      case 24: // fLOGN
      case 25: // fGAMM
      case 26: // fERLA
      case 27: // fTRIA
      case 28: // fBETA
      case 29: // fDISC
      case 30: // fTNOW
      case 31: // fTFIN
      case 32: // cIF
      case 33: // cELSE
      case 34: // cFOR
      case 35: // cTO
      case 36: // cDO
      case 37: // ATRIB
      case 38: // ILLEGAL
      case 39: // RESOURCE
      case 40: // fNR
      case 41: // fMR
      case 42: // fIRF
      case 43: // fRESSEIZES
      case 44: // fSTATE
      case 45: // fSETSUM
      case 46: // QUEUE
      case 47: // fNQ
      case 48: // fFIRSTINQ
      case 49: // fLASTINQ
      case 50: // fSAQUE
      case 51: // fAQUE
      case 52: // SET
      case 53: // fNUMSET
      case 54: // CSTAT
      case 55: // fTAVG
      case 56: // VARI
      case 57: // FORM
      case 75: // input
      case 76: // programa
      case 77: // expressao
      case 78: // numero
      case 79: // aritmetica
      case 80: // relacional
      case 81: // comando
      case 82: // comandoIF
      case 83: // comandoFOR
      case 84: // funcao
      case 85: // funcaoKernel
      case 86: // funcaoTrig
      case 87: // funcaoArit
      case 88: // funcaoProb
      case 89: // funcaoUser
      case 90: // listaparm
      case 91: // illegal
      case 92: // atributo
      case 93: // atribuicao
      case 94: // variavel
      case 95: // formula
      case 96: // funcaoPlugin
        value.move< obj_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  genesyspp_parser::stack_symbol_type&
  genesyspp_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
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
      case 20: // fEXPO
      case 21: // fNORM
      case 22: // fUNIF
      case 23: // fWEIB
      case 24: // fLOGN
      case 25: // fGAMM
      case 26: // fERLA
      case 27: // fTRIA
      case 28: // fBETA
      case 29: // fDISC
      case 30: // fTNOW
      case 31: // fTFIN
      case 32: // cIF
      case 33: // cELSE
      case 34: // cFOR
      case 35: // cTO
      case 36: // cDO
      case 37: // ATRIB
      case 38: // ILLEGAL
      case 39: // RESOURCE
      case 40: // fNR
      case 41: // fMR
      case 42: // fIRF
      case 43: // fRESSEIZES
      case 44: // fSTATE
      case 45: // fSETSUM
      case 46: // QUEUE
      case 47: // fNQ
      case 48: // fFIRSTINQ
      case 49: // fLASTINQ
      case 50: // fSAQUE
      case 51: // fAQUE
      case 52: // SET
      case 53: // fNUMSET
      case 54: // CSTAT
      case 55: // fTAVG
      case 56: // VARI
      case 57: // FORM
      case 75: // input
      case 76: // programa
      case 77: // expressao
      case 78: // numero
      case 79: // aritmetica
      case 80: // relacional
      case 81: // comando
      case 82: // comandoIF
      case 83: // comandoFOR
      case 84: // funcao
      case 85: // funcaoKernel
      case 86: // funcaoTrig
      case 87: // funcaoArit
      case 88: // funcaoProb
      case 89: // funcaoUser
      case 90: // listaparm
      case 91: // illegal
      case 92: // atributo
      case 93: // atribuicao
      case 94: // variavel
      case 95: // formula
      case 96: // funcaoPlugin
        value.copy< obj_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
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

  inline
  void
  genesyspp_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  genesyspp_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  genesyspp_parser::yypop_ (unsigned int n)
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

  inline genesyspp_parser::state_type
  genesyspp_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  genesyspp_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 32 "bisonparser.yy" // lalr1.cc:741
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.getFile();
}

#line 578 "../GenesysParser.cpp" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

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
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
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
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
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
      case 20: // fEXPO
      case 21: // fNORM
      case 22: // fUNIF
      case 23: // fWEIB
      case 24: // fLOGN
      case 25: // fGAMM
      case 26: // fERLA
      case 27: // fTRIA
      case 28: // fBETA
      case 29: // fDISC
      case 30: // fTNOW
      case 31: // fTFIN
      case 32: // cIF
      case 33: // cELSE
      case 34: // cFOR
      case 35: // cTO
      case 36: // cDO
      case 37: // ATRIB
      case 38: // ILLEGAL
      case 39: // RESOURCE
      case 40: // fNR
      case 41: // fMR
      case 42: // fIRF
      case 43: // fRESSEIZES
      case 44: // fSTATE
      case 45: // fSETSUM
      case 46: // QUEUE
      case 47: // fNQ
      case 48: // fFIRSTINQ
      case 49: // fLASTINQ
      case 50: // fSAQUE
      case 51: // fAQUE
      case 52: // SET
      case 53: // fNUMSET
      case 54: // CSTAT
      case 55: // fTAVG
      case 56: // VARI
      case 57: // FORM
      case 75: // input
      case 76: // programa
      case 77: // expressao
      case 78: // numero
      case 79: // aritmetica
      case 80: // relacional
      case 81: // comando
      case 82: // comandoIF
      case 83: // comandoFOR
      case 84: // funcao
      case 85: // funcaoKernel
      case 86: // funcaoTrig
      case 87: // funcaoArit
      case 88: // funcaoProb
      case 89: // funcaoUser
      case 90: // listaparm
      case 91: // illegal
      case 92: // atributo
      case 93: // atribuicao
      case 94: // variavel
      case 95: // formula
      case 96: // funcaoPlugin
        yylhs.value.build< obj_t > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 195 "bisonparser.yy" // lalr1.cc:859
    {YYACCEPT;}
#line 768 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 196 "bisonparser.yy" // lalr1.cc:859
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor);}
#line 774 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 198 "bisonparser.yy" // lalr1.cc:859
    { yyerrok; }
#line 780 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 201 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 786 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 204 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 792 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 205 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 798 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 206 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 804 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 207 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 810 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 208 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 816 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 209 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 822 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 210 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 828 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 211 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 834 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 213 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 840 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 215 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 846 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 218 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 852 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 219 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 858 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 222 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 864 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 223 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 870 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 224 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 876 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 225 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 882 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 226 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = pow(yystack_[2].value.as< obj_t > ().valor,yystack_[0].value.as< obj_t > ().valor);}
#line 888 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 227 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = exp(yystack_[1].value.as< obj_t > ().valor);}
#line 894 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 228 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = -yystack_[0].value.as< obj_t > ().valor;}
#line 900 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 231 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 906 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 232 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 912 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 233 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 918 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 234 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 924 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 235 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 930 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 236 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 936 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 237 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 942 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 238 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 948 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 245 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor;}
#line 954 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 246 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 960 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 249 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 966 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 250 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 972 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 253 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 978 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 254 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 984 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 255 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 990 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 256 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 996 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 257 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1002 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 258 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1008 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 261 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->simulation()->simulatedTime();}
#line 1014 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 262 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->infos()->replicationLength();}
#line 1020 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 265 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor); }
#line 1026 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 266 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); }
#line 1032 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 269 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = round(yystack_[1].value.as< obj_t > ().valor);}
#line 1038 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 270 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1044 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 271 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = trunc(yystack_[1].value.as< obj_t > ().valor);}
#line 1050 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 272 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1056 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 275 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleExponential(yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1062 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 276 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1068 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 277 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleUniform(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Unificada"; }
#line 1074 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 278 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleWeibull(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1080 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 279 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleLogNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1086 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 280 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleGamma(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1092 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 281 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleErlang(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1098 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 282 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleTriangular(yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1104 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 283 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleBeta(yystack_[7].value.as< obj_t > ().valor,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1110 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 289 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1116 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 297 "bisonparser.yy" // lalr1.cc:859
    {
				  driver.setResult(-1);
				  if(driver.getThrowsException()){
				    if(yystack_[0].value.as< obj_t > ().valor == 0){
				      throw std::string("Literal nao encontrado");
				    }else if(yystack_[0].value.as< obj_t > ().valor == 1){
				      throw std::string("Caracter invalido encontrado");
				    }
				  }else{
				    if(yystack_[0].value.as< obj_t > ().valor == 0){
				      driver.setErrorMessage(std::string("Literal nao encontrado"));
				    }else if(yystack_[0].value.as< obj_t > ().valor == 1){
				      driver.setErrorMessage(std::string("Caracter invalido encontrado"));
				    }
				  }
				}
#line 1137 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 317 "bisonparser.yy" // lalr1.cc:859
    {  double attributeValue = 0.0;
			    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
				try {
				    // it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
				    attributeValue = driver.getModel()->simulation()->currentEntity()->getAttributeValue(yystack_[0].value.as< obj_t > ().valor);
				} catch(...) {
				}
			    }
			    yylhs.value.as< obj_t > ().valor = attributeValue; 
			}
#line 1152 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 330 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1158 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 331 "bisonparser.yy" // lalr1.cc:859
    {((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[2].value.as< obj_t > ().id)))->setValue(yystack_[0].value.as< obj_t > ().valor);
						yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1165 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 333 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
									    ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
									    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1173 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 336 "bisonparser.yy" // lalr1.cc:859
    {std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor)); 
											((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor);
											yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1181 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 339 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
													((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[9].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
													yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1189 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 344 "bisonparser.yy" // lalr1.cc:859
    {   //std::cout << "VARI" << std::endl;
								    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1196 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 346 "bisonparser.yy" // lalr1.cc:859
    { //std::cout << "VARI[exp]" << std::endl;
								    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
								  yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(index);}
#line 1204 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 349 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor)); 
								  yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 1211 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 351 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
								      yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->getValue(index);}
#line 1218 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 356 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->elements()->element(Util::TypeOf<Formula>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1224 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 360 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1230 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 365 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1236 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 366 "bisonparser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1242 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 367 "bisonparser.yy" // lalr1.cc:859
    { if (((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
                                                            //id da 1a entidade da fila, talvez pegar nome
                                                            yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->id();
                                                          }else{
                                                            yylhs.value.as< obj_t > ().valor = 0;
                                                          }
                                                        }
#line 1254 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 374 "bisonparser.yy" // lalr1.cc:859
    {   
				 Util::identification queueID = yystack_[3].value.as< obj_t > ().id;
				 Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
				 double sum = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[3].value.as< obj_t > ().id)))->sumAttributesFromWaiting(attrID);
				  yylhs.value.as< obj_t > ().valor = sum;
				}
#line 1265 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 380 "bisonparser.yy" // lalr1.cc:859
    {
				 Util::identification queueID = yystack_[5].value.as< obj_t > ().id;
				 Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
				 double value = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[5].value.as< obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as< obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
				  yylhs.value.as< obj_t > ().valor = value;
				}
#line 1276 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 390 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1282 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 391 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1288 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 392 "bisonparser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1294 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 393 "bisonparser.yy" // lalr1.cc:859
    {  yylhs.value.as< obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState());
							}
#line 1301 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 396 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1307 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 397 "bisonparser.yy" // lalr1.cc:859
    {   unsigned int count=0;
							    Resource* res;
							    List<ModelElement*>* setList = ((Set*)driver.getModel()->elements()->element(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet(); 
							    for (std::list<ModelElement*>::iterator it = setList->list()->begin(); it!=setList->list()->end(); it++) {
								res = dynamic_cast<Resource*>(*it);
								if (res != nullptr) {
								    if (res->getResourceState()==Resource::ResourceState::BUSY) {
									count++;
								    }
								}
							    }
							    yylhs.value.as< obj_t > ().valor = count; 
							}
#line 1325 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 414 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Set*)driver.getModel()->elements()->element(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet()->size(); }
#line 1331 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 420 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1337 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 421 "bisonparser.yy" // lalr1.cc:859
    {
					    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->elements()->element(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as< obj_t > ().id)));
					    double value = cstat->getStatistics()->average();
					    yylhs.value.as< obj_t > ().valor = value;
					}
#line 1347 "../GenesysParser.cpp" // lalr1.cc:859
    break;


#line 1351 "../GenesysParser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
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
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  genesyspp_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
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
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
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


  const short int genesyspp_parser::yypact_ninf_ = -257;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short int
  genesyspp_parser::yypact_[] =
  {
     237,   -63,  -257,   298,  -257,  -257,  -257,  -257,  -257,  -257,
     -45,   -44,   -40,   -39,   -38,   -37,   -16,    -4,    -3,    -2,
       1,    18,    19,    20,    21,    22,    23,  -257,  -257,    24,
     -34,  -257,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,  -257,    48,   -53,  -257,   359,   359,
    -257,    50,  -257,  1222,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,    40,  -257,  -257,  -257,
    -257,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,    51,
      41,    49,    80,    81,    82,    83,    84,    72,    79,    85,
      87,    88,    89,    74,    73,   359,   359,   750,    63,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   760,   770,   780,   456,   790,   853,
     863,   873,   465,   530,   539,   548,   557,   566,   575,   640,
     649,   -55,   883,   359,   359,   359,    70,    71,    77,    90,
      91,    92,    93,    94,    95,    76,    86,    96,    98,    37,
    1222,  -257,   893,   -13,   -13,   -13,   -13,  1201,  1201,   -54,
     -54,    63,  1222,    63,   -13,   -13,  1222,  -257,  -257,  -257,
     359,  -257,  -257,  -257,  -257,   359,   359,   359,   359,   359,
     359,   359,   359,   359,  -257,   359,   359,   106,   956,   963,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,   121,
     156,  -257,  -257,   108,   359,  -257,   973,   986,   996,  1006,
    1069,  1079,  1089,   658,   667,  1222,   676,   181,  -257,   359,
     359,   359,   101,   105,   359,   417,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,   359,   359,   359,   359,   427,  1103,  1113,
    -257,   124,  1222,   109,   359,  1152,   685,  1222,  1222,  -257,
     359,     4,     4,   103,   359,  1176,  -257,   359,  1184,   -52,
      40,  -257,  -257,  -257,  1222,   110,  1194,  -257,   359,   359,
    -257,   437,  1222,   108,   359,   447,   109,   359,  1215,   110
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    68,     0,     5,     6,     1,    18,    19,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    48,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,    75,    79,     0,     0,
       3,     0,     4,     7,     8,    12,    13,    10,    35,    36,
       9,    44,    42,    41,    43,    46,    15,    11,    16,    17,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    14,     0,    30,    32,    33,    34,    27,    28,    20,
      21,    23,    24,    22,    29,    31,    70,    49,    50,    51,
       0,    53,    52,    25,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,     0,     0,     0,     0,
      87,    86,    90,    88,    89,    91,    81,    83,    82,     0,
       0,    92,    94,    76,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    38,    76,     0,
       0,     0,     0,     0,     0,     0,    54,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
      84,     0,    72,    77,     0,     0,     0,    66,    37,    77,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,    40,    39,    85,    73,    78,     0,    78,     0,     0,
      63,     0,    74,     0,     0,     0,     0,     0,     0,     0
  };

  const short int
  genesyspp_parser::yypgoto_[] =
  {
    -257,  -257,  -257,   -48,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,   -28,  -256,
     133,  -257,  -257
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   141,     4,    66,    67,
      68,    69,    70
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
     107,   108,    90,    31,   194,   271,   272,   105,   278,     5,
     118,   119,   120,    71,    72,   195,   106,   106,    73,    74,
      75,    76,    89,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     142,    31,    77,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    78,    79,    80,   159,   160,    81,
     269,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    82,    83,    84,    85,
      86,    87,    88,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   197,   198,   199,   213,   116,
     117,   118,   119,   120,   121,   122,   104,   214,   109,   123,
     144,   143,   110,   111,   112,   113,   114,   115,   145,   146,
     147,   148,   149,   150,   151,   152,   157,   158,   119,   200,
     201,   153,   216,   154,   155,   156,   202,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   209,   226,   227,   203,
     204,   205,   206,   207,   208,   211,   210,   212,   232,   233,
     250,   263,   273,    91,     0,     0,   235,   228,   116,   117,
     118,   119,   120,   121,   122,   251,   229,   234,   264,   279,
       0,   247,   248,   249,     0,     0,   252,   110,   111,   112,
     113,   114,   115,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,   268,     0,   246,     0,   274,     0,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,   282,     0,   270,   270,     0,   285,    -2,     1,   288,
      -2,    -2,    -2,   116,   117,   118,   119,   120,   121,   122,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
       0,    -2,     0,     0,    -2,     2,     0,    -2,    -2,    -2,
      -2,    -2,    -2,     0,    -2,    -2,    -2,    -2,    -2,     0,
      -2,    -2,    -2,    -2,    -2,    -2,     0,     0,     6,     0,
      -2,     7,     8,     9,     0,     0,     0,     0,     0,    -2,
      -2,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,     0,     0,    31,     0,     0,    32,    33,
      34,    35,    36,    37,     0,    38,    39,    40,    41,    42,
       0,    43,    44,    45,    46,    47,    48,     0,     0,     0,
       0,    49,     7,     8,     9,     0,     0,     0,     0,     0,
      50,    51,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,     0,     0,    31,     0,     0,    32,
      33,    34,    35,    36,    37,     0,    38,    39,    40,    41,
      42,     0,    43,    44,    45,    46,    47,    48,     0,     0,
       0,     0,    49,   110,   111,   112,   113,   114,   115,     0,
       0,     0,    51,   110,   111,   112,   113,   114,   115,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     0,   253,   116,
     117,   118,   119,   120,   121,   122,     0,   254,   259,   116,
     117,   118,   119,   120,   121,   122,     0,   260,   283,   116,
     117,   118,   119,   120,   121,   122,     0,   284,   286,   116,
     117,   118,   119,   120,   121,   122,     0,   287,   116,   117,
     118,   119,   120,   121,   122,     0,   180,   116,   117,   118,
     119,   120,   121,   122,     0,   185,   110,   111,   112,   113,
     114,   115,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,     0,     0,   110,   111,   112,   113,   114,   115,
       0,     0,     0,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,     0,
     186,   116,   117,   118,   119,   120,   121,   122,     0,   187,
     116,   117,   118,   119,   120,   121,   122,     0,   188,   116,
     117,   118,   119,   120,   121,   122,     0,   189,   116,   117,
     118,   119,   120,   121,   122,     0,   190,   116,   117,   118,
     119,   120,   121,   122,     0,   191,   110,   111,   112,   113,
     114,   115,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,     0,     0,   110,   111,   112,   113,   114,   115,
       0,     0,     0,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,     0,
     192,   116,   117,   118,   119,   120,   121,   122,     0,   193,
     116,   117,   118,   119,   120,   121,   122,     0,   243,   116,
     117,   118,   119,   120,   121,   122,     0,   244,   116,   117,
     118,   119,   120,   121,   122,     0,   245,   116,   117,   118,
     119,   120,   121,   122,     0,   267,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   177,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   178,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   179,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   181,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,   182,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   183,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   184,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   196,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   215,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   110,   111,   112,   113,   114,   115,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,   230,   110,   111,   112,   113,   114,   115,   231,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   116,   117,   118,   119,   120,
     121,   122,   236,     0,     0,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   237,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   238,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   239,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,     0,     0,   240,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   241,   261,
       0,   116,   117,   118,   119,   120,   121,   122,   242,   262,
       0,   116,   117,   118,   119,   120,   121,   122,   110,   111,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   110,   111,   112,   113,   114,   115,     0,     0,
     110,   111,   112,   113,   114,   115,     0,     0,     0,     0,
     110,   111,   112,   113,   114,   115,     0,   110,   111,   112,
     113,   266,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   110,   111,   112,   113,   114,   115,     0,   110,   111,
     112,   113,   114,   115,     0,     0,     0,   275,   116,   117,
     118,   119,   120,   121,   122,   277,   116,   117,   118,   119,
     120,   121,   122,   280,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,   289,   116,   117,   118,
     119,   120,   121,   122,   116,   117,   118,   119,   120,   121,
     122
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      48,    49,    30,    37,    59,   261,   262,    60,    60,    72,
      64,    65,    66,    58,    58,    70,    69,    69,    58,    58,
      58,    58,    56,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    37,    58,     6,     7,     8,     9,    10,    11,    62,
      63,    64,    65,    66,    58,    58,    58,   105,   106,    58,
      56,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,   143,   144,   145,    61,    62,
      63,    64,    65,    66,    67,    68,    58,    70,    58,    69,
      69,    60,     6,     7,     8,     9,    10,    11,    69,    39,
      39,    39,    39,    39,    52,    46,    52,    54,    65,    59,
      59,    46,   180,    46,    46,    46,    59,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    70,   195,   196,    59,
      59,    59,    59,    59,    59,    59,    70,    59,    37,     3,
      59,    37,    59,    30,    -1,    -1,   214,    61,    62,    63,
      64,    65,    66,    67,    68,    70,    70,    69,    69,    69,
      -1,   229,   230,   231,    -1,    -1,   234,     6,     7,     8,
       9,    10,    11,    -1,    -1,   243,   244,   245,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    33,    -1,   264,    -1,    -1,   267,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     278,   279,    -1,   261,   262,    -1,   284,     0,     1,   287,
       3,     4,     5,    62,    63,    64,    65,    66,    67,    68,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    -1,    -1,     0,    -1,
      63,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    72,
      73,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      72,    73,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    -1,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    73,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,     6,     7,     8,     9,    10,    11,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    35,     6,     7,     8,     9,    10,    11,    35,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    62,    63,
      64,    65,    66,    67,    68,    62,    63,    64,    65,    66,
      67,    68,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    59,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    59,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    59,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    59,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    59,    36,
      -1,    62,    63,    64,    65,    66,    67,    68,    59,    36,
      -1,    62,    63,    64,    65,    66,    67,    68,     6,     7,
       8,     9,    10,    11,    -1,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,     6,     7,     8,     9,    10,    11,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,     6,     7,     8,
       9,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    61,    62,    63,    64,    65,
      66,    67,    68,    59,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    62,    63,    64,    65,    66,    67,
      68
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    38,    75,    91,    72,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      34,    37,    40,    41,    42,    43,    44,    45,    47,    48,
      49,    50,    51,    53,    54,    55,    56,    57,    58,    63,
      72,    73,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    92,    93,    94,    95,
      96,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    56,
      92,    94,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    60,    69,    77,    77,    58,
       6,     7,     8,     9,    10,    11,    62,    63,    64,    65,
      66,    67,    68,    69,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    90,    77,    60,    69,    69,    39,    39,    39,    39,
      39,    52,    46,    46,    46,    46,    46,    52,    54,    77,
      77,    59,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    59,    59,    59,
      70,    59,    59,    59,    59,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    59,    70,    59,    77,    77,    77,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    70,
      70,    59,    59,    61,    70,    59,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    61,    70,
      35,    35,    37,     3,    69,    77,    59,    59,    59,    59,
      59,    59,    59,    70,    70,    70,    33,    77,    77,    77,
      59,    70,    77,    61,    70,    77,    77,    77,    77,    61,
      70,    36,    36,    37,    69,    77,    59,    70,    77,    56,
      92,    93,    93,    59,    77,    61,    77,    61,    60,    69,
      59,    77,    77,    61,    70,    77,    61,    70,    77,    61
  };

  const unsigned char
  genesyspp_parser::yyr1_[] =
  {
       0,    74,    75,    75,    75,    75,    75,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    91,    92,
      93,    93,    93,    93,    93,    94,    94,    94,    94,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96
  };

  const unsigned char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     7,     5,     8,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     6,     4,     6,     6,     6,     6,
       6,     6,     8,    10,     4,     4,     5,     3,     1,     1,
       3,     3,     6,     8,    10,     1,     4,     6,     8,     1,
       1,     4,     4,     4,     6,     8,     4,     4,     4,     4,
       4,     4,     4,     1,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NUMD", "NUMH", "CTEZERO",
  "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNOT", "fSIN", "fCOS",
  "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXP", "fEXPO", "fNORM", "fUNIF",
  "fWEIB", "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA", "fDISC", "fTNOW",
  "fTFIN", "cIF", "cELSE", "cFOR", "cTO", "cDO", "ATRIB", "ILLEGAL",
  "RESOURCE", "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE", "fSETSUM",
  "QUEUE", "fNQ", "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE", "SET",
  "fNUMSET", "CSTAT", "fTAVG", "VARI", "FORM", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"", "\"<\"", "\">\"",
  "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"", "$accept", "input",
  "programa", "expressao", "numero", "aritmetica", "relacional", "comando",
  "comandoIF", "comandoFOR", "funcao", "funcaoKernel", "funcaoTrig",
  "funcaoArit", "funcaoProb", "funcaoUser", "listaparm", "illegal",
  "atributo", "atribuicao", "variavel", "formula", "funcaoPlugin", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  genesyspp_parser::yyrline_[] =
  {
       0,   194,   194,   195,   196,   197,   198,   201,   204,   205,
     206,   207,   208,   209,   210,   211,   213,   215,   218,   219,
     222,   223,   224,   225,   226,   227,   228,   231,   232,   233,
     234,   235,   236,   237,   238,   241,   242,   245,   246,   249,
     250,   253,   254,   255,   256,   257,   258,   261,   262,   265,
     266,   269,   270,   271,   272,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   289,   293,   294,   297,   317,
     330,   331,   333,   336,   339,   344,   346,   349,   351,   356,
     360,   365,   366,   367,   374,   380,   390,   391,   392,   393,
     396,   397,   414,   420,   421
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
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  genesyspp_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 2099 "../GenesysParser.cpp" // lalr1.cc:1167
#line 435 "bisonparser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
