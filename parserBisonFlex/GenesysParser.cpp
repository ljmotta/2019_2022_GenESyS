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
    {  
		    double attributeValue = 0.0;
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->getAttributeValue(yystack_[0].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1150 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 325 "bisonparser.yy" // lalr1.cc:859
    {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->getAttributeValue(index, yystack_[3].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1164 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 334 "bisonparser.yy" // lalr1.cc:859
    {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->getAttributeValue(index, yystack_[5].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1178 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 343 "bisonparser.yy" // lalr1.cc:859
    {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->getAttributeValue(index, yystack_[7].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1192 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 355 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1198 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 356 "bisonparser.yy" // lalr1.cc:859
    {((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[2].value.as< obj_t > ().id)))->setValue(yystack_[0].value.as< obj_t > ().valor);
						yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1205 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 358 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
									    ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
									    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1213 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 361 "bisonparser.yy" // lalr1.cc:859
    {std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor)); 
											((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor);
											yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1221 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 364 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
													((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[9].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
													yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1229 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 369 "bisonparser.yy" // lalr1.cc:859
    {   //std::cout << "VARI" << std::endl;
								    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1236 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 371 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(index); }
#line 1244 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 374 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor)); 
		    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 1252 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 377 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->getValue(index);}
#line 1260 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 383 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->elements()->element(Util::TypeOf<Formula>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1266 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 387 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1272 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 392 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1278 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 393 "bisonparser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1284 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 394 "bisonparser.yy" // lalr1.cc:859
    { 
		    if (((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
			//id da 1a entidade da fila, talvez pegar nome
			yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->id();
		      }else{
			yylhs.value.as< obj_t > ().valor = 0;
		      }
		}
#line 1297 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 402 "bisonparser.yy" // lalr1.cc:859
    {   
		     Util::identification queueID = yystack_[3].value.as< obj_t > ().id;
		     Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
		     double sum = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[3].value.as< obj_t > ().id)))->sumAttributesFromWaiting(attrID);
		      yylhs.value.as< obj_t > ().valor = sum;
		    }
#line 1308 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 408 "bisonparser.yy" // lalr1.cc:859
    {
		     Util::identification queueID = yystack_[5].value.as< obj_t > ().id;
		     Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
		     double value = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[5].value.as< obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as< obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
		      yylhs.value.as< obj_t > ().valor = value;
		    }
#line 1319 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 418 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1325 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 419 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1331 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 420 "bisonparser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1337 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 421 "bisonparser.yy" // lalr1.cc:859
    {  yylhs.value.as< obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState());
							}
#line 1344 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 424 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1350 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 425 "bisonparser.yy" // lalr1.cc:859
    {
		    unsigned int count=0;
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
#line 1369 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 443 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Set*)driver.getModel()->elements()->element(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet()->size(); }
#line 1375 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 449 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1381 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 450 "bisonparser.yy" // lalr1.cc:859
    {
					    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->elements()->element(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as< obj_t > ().id)));
					    double value = cstat->getStatistics()->average();
					    yylhs.value.as< obj_t > ().valor = value;
					}
#line 1391 "../GenesysParser.cpp" // lalr1.cc:859
    break;


#line 1395 "../GenesysParser.cpp" // lalr1.cc:859
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


  const short int genesyspp_parser::yypact_ninf_ = -264;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short int
  genesyspp_parser::yypact_[] =
  {
     246,   -63,  -264,   307,  -264,  -264,  -264,  -264,  -264,  -264,
     -45,   -44,   -40,   -39,   -38,   -16,    -2,    -1,     2,     3,
      19,    20,    21,    22,    23,    24,    25,  -264,  -264,    26,
     -35,   -17,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    41,  -264,    50,   -53,  -264,   368,   368,
    -264,    52,  -264,  1302,  -264,  -264,  -264,  -264,  -264,  -264,
    -264,  -264,  -264,  -264,  -264,  -264,    42,  -264,  -264,  -264,
    -264,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,    53,
      43,    45,   368,    76,    83,    84,    85,    86,    74,    81,
      82,    87,    89,    90,    77,    78,   368,   368,   779,    65,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   789,   799,   862,   540,   872,
     882,   892,   902,   549,   558,   567,   576,   641,   650,   659,
     668,   677,   -55,   965,   368,   368,   368,    39,    72,    79,
      92,    93,    94,    95,    97,    98,    99,    67,    91,   100,
     101,   110,  1302,  -264,   975,   -11,   -11,   -11,   -11,   190,
     190,   -54,   -54,    65,  1302,    65,   -11,   -11,  1302,  -264,
    -264,  -264,   368,  -264,  -264,  -264,  -264,   368,   368,   368,
     368,   368,   368,   368,   368,   368,  -264,   368,   368,   426,
     982,   990,  -264,   368,  -264,  -264,  -264,  -264,  -264,  -264,
    -264,  -264,  -264,   111,   159,  -264,  -264,    96,   368,  -264,
    1000,  1012,  1075,  1085,  1095,  1105,  1115,   686,   751,  1302,
     760,  1122,  -264,   368,   368,   368,   436,   104,   109,   368,
     446,  -264,  -264,  -264,  -264,  -264,  -264,  -264,   368,   368,
     368,   368,   456,  1185,  1192,  -264,   368,  -264,   127,  1302,
     112,   368,  1202,   769,  1302,  1302,  -264,   368,   -15,   -15,
    1216,   107,   368,  1224,  -264,   368,  1232,   -52,    42,  -264,
    -264,  -264,  -264,  1302,   113,  1265,  -264,   368,   368,  -264,
     466,  1302,    96,   368,   531,   112,   368,  1295,   113
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    68,     0,     5,     6,     1,    18,    19,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    48,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,    78,    82,     0,     0,
       3,     0,     4,     7,     8,    12,    13,    10,    35,    36,
       9,    44,    42,    41,    43,    46,    15,    11,    16,    17,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    14,     0,    30,    32,    33,    34,    27,
      28,    20,    21,    23,    24,    22,    29,    31,    73,    49,
      50,    51,     0,    53,    52,    25,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,    70,     0,    90,    89,    93,    91,    92,    94,
      84,    86,    85,     0,     0,    95,    97,    79,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    38,    79,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     0,     0,     0,     0,    71,     0,    87,     0,    75,
      80,     0,     0,     0,    66,    37,    80,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,    40,
      39,    72,    88,    76,    81,     0,    81,     0,     0,    63,
       0,    77,     0,     0,     0,     0,     0,     0,     0
  };

  const short int
  genesyspp_parser::yypgoto_[] =
  {
    -264,  -264,  -264,   -48,  -264,  -264,  -264,  -264,  -264,  -264,
    -264,  -264,  -264,  -264,  -264,  -264,  -264,  -264,   -27,  -263,
     137,  -264,  -264
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   142,     4,    66,    67,
      68,    69,    70
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
     108,   109,    31,    90,   196,   279,   280,   106,   287,     5,
     119,   120,   121,    71,    72,   197,   107,   107,    73,    74,
      75,    89,    31,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     143,   277,    76,    92,   147,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    77,    78,   161,   162,
      79,    80,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    81,    82,    83,
      84,    85,    86,    87,    88,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   199,   200,   201,   104,
     202,   117,   118,   119,   120,   121,   122,   123,   105,   203,
     110,   124,   145,   144,   146,   148,   111,   112,   113,   114,
     115,   116,   149,   150,   151,   152,   153,   154,   155,   159,
     120,   204,   160,   156,   220,   157,   158,   213,   205,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   237,   230,
     231,   206,   207,   208,   209,   236,   210,   211,   212,   215,
     216,   214,   238,   257,   271,   239,   282,    91,     0,     0,
     240,   217,   117,   118,   119,   120,   121,   122,   123,   258,
     218,   272,   288,     0,     0,   252,   253,   254,     0,     0,
       0,   259,     0,     0,     0,     0,   111,   112,   113,   114,
     262,   263,   264,   265,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   273,     0,     0,     0,     0,     0,   276,
       0,     0,     0,     0,   283,     0,     0,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     291,   278,   278,     0,     0,   294,    -2,     1,   297,    -2,
      -2,    -2,   117,   118,   119,   120,   121,   122,   123,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,     0,
      -2,     0,     0,    -2,     2,     0,    -2,    -2,    -2,    -2,
      -2,    -2,     0,    -2,    -2,    -2,    -2,    -2,     0,    -2,
      -2,    -2,    -2,    -2,    -2,     0,     0,     6,     0,    -2,
       7,     8,     9,     0,     0,     0,     0,     0,    -2,    -2,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,     0,     0,    31,     0,     0,    32,    33,    34,
      35,    36,    37,     0,    38,    39,    40,    41,    42,     0,
      43,    44,    45,    46,    47,    48,     0,     0,     0,     0,
      49,     7,     8,     9,     0,     0,     0,     0,     0,    50,
      51,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,     0,     0,    31,     0,     0,    32,    33,
      34,    35,    36,    37,     0,    38,    39,    40,    41,    42,
       0,    43,    44,    45,    46,    47,    48,     0,     0,     0,
       0,    49,   111,   112,   113,   114,   115,   116,     0,     0,
       0,    51,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,   117,   118,
     119,   120,   121,   122,   123,     0,   233,   255,   117,   118,
     119,   120,   121,   122,   123,     0,   256,   260,   117,   118,
     119,   120,   121,   122,   123,     0,   261,   266,   117,   118,
     119,   120,   121,   122,   123,     0,   267,   292,   117,   118,
     119,   120,   121,   122,   123,     0,   293,   111,   112,   113,
     114,   115,   116,     0,     0,     0,   111,   112,   113,   114,
     115,   116,     0,     0,     0,   111,   112,   113,   114,   115,
     116,     0,     0,     0,   111,   112,   113,   114,   115,   116,
       0,     0,     0,   111,   112,   113,   114,   115,   116,     0,
       0,     0,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   295,   117,   118,   119,   120,   121,   122,   123,
       0,   296,   117,   118,   119,   120,   121,   122,   123,     0,
     182,   117,   118,   119,   120,   121,   122,   123,     0,   187,
     117,   118,   119,   120,   121,   122,   123,     0,   188,   117,
     118,   119,   120,   121,   122,   123,     0,   189,   117,   118,
     119,   120,   121,   122,   123,     0,   190,   111,   112,   113,
     114,   115,   116,     0,     0,     0,   111,   112,   113,   114,
     115,   116,     0,     0,     0,   111,   112,   113,   114,   115,
     116,     0,     0,     0,   111,   112,   113,   114,   115,   116,
       0,     0,     0,   111,   112,   113,   114,   115,   116,     0,
       0,     0,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
       0,   191,   117,   118,   119,   120,   121,   122,   123,     0,
     192,   117,   118,   119,   120,   121,   122,   123,     0,   193,
     117,   118,   119,   120,   121,   122,   123,     0,   194,   117,
     118,   119,   120,   121,   122,   123,     0,   195,   117,   118,
     119,   120,   121,   122,   123,     0,   248,   111,   112,   113,
     114,   115,   116,     0,     0,     0,   111,   112,   113,   114,
     115,   116,     0,     0,     0,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,     0,     0,   117,   118,   119,   120,   121,   122,   123,
       0,   249,   117,   118,   119,   120,   121,   122,   123,     0,
     250,   117,   118,   119,   120,   121,   122,   123,   163,   275,
       0,   117,   118,   119,   120,   121,   122,   123,   179,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   180,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,   181,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   183,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   184,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   185,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   186,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,     0,   111,   112,
     113,   114,   115,   116,     0,     0,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,   234,   111,   112,
     113,   114,   115,   116,   198,   235,     0,   117,   118,   119,
     120,   121,   122,   123,   219,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   117,   118,   119,   120,   121,   122,
     123,     0,   117,   118,   119,   120,   121,   122,   123,   241,
       0,     0,   117,   118,   119,   120,   121,   122,   123,     0,
       0,   242,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,     0,   111,   112,
     113,   114,   115,   116,   243,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   244,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   245,   251,     0,   117,   118,   119,
     120,   121,   122,   123,   246,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   247,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   117,   118,   119,   120,   121,   122,
     123,   111,   112,   113,   114,   115,   116,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,   268,   111,   112,   113,   114,   115,   116,   269,     0,
     111,   112,   113,   114,   115,   116,     0,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   117,   118,   119,   120,   121,   122,
     123,   274,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   111,   112,   113,   114,   115,   116,   281,   117,   118,
     119,   120,   121,   122,   123,   284,   117,   118,   119,   120,
     121,   122,   123,   286,   117,   118,   119,   120,   121,   122,
     123,   111,   112,   113,   114,   115,   116,     0,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   289,     0,     0,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   298,   117,   118,   119,
     120,   121,   122,   123,   117,   118,   119,   120,   121,   122,
     123
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      48,    49,    37,    30,    59,   268,   269,    60,    60,    72,
      64,    65,    66,    58,    58,    70,    69,    69,    58,    58,
      58,    56,    37,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    56,    58,    60,    92,     6,     7,     8,     9,    10,
      11,    62,    63,    64,    65,    66,    58,    58,   106,   107,
      58,    58,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   144,   145,   146,    58,
      61,    62,    63,    64,    65,    66,    67,    68,    58,    70,
      58,    69,    69,    60,    69,    39,     6,     7,     8,     9,
      10,    11,    39,    39,    39,    39,    52,    46,    46,    52,
      65,    59,    54,    46,   182,    46,    46,    70,    59,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    37,   197,
     198,    59,    59,    59,    59,   203,    59,    59,    59,    59,
      59,    70,     3,    59,    37,    69,    59,    30,    -1,    -1,
     218,    61,    62,    63,    64,    65,    66,    67,    68,    70,
      70,    69,    69,    -1,    -1,   233,   234,   235,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,
      -1,    -1,    -1,    -1,   272,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
     288,   268,   269,    -1,    -1,   293,     0,     1,   296,     3,
       4,     5,    62,    63,    64,    65,    66,    67,    68,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,     0,    -1,    63,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    72,    73,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    72,
      73,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    73,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    62,    63,    64,    65,    66,    67,    68,    59,    70,
      -1,    62,    63,    64,    65,    66,    67,    68,    59,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    59,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    35,     6,     7,
       8,     9,    10,    11,    59,    35,    -1,    62,    63,    64,
      65,    66,    67,    68,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    62,    63,    64,    65,    66,    67,
      68,    -1,    62,    63,    64,    65,    66,    67,    68,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    59,    33,    -1,    62,    63,    64,
      65,    66,    67,    68,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    62,    63,    64,    65,    66,    67,
      68,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,     6,     7,     8,     9,    10,    11,    36,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    62,    63,    64,    65,    66,    67,
      68,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,     6,     7,     8,     9,    10,    11,    61,    62,    63,
      64,    65,    66,    67,    68,    61,    62,    63,    64,    65,
      66,    67,    68,    61,    62,    63,    64,    65,    66,    67,
      68,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      92,    94,    60,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    60,    69,    77,    77,
      58,     6,     7,     8,     9,    10,    11,    62,    63,    64,
      65,    66,    67,    68,    69,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    90,    77,    60,    69,    69,    77,    39,    39,
      39,    39,    39,    52,    46,    46,    46,    46,    46,    52,
      54,    77,    77,    59,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    59,
      59,    59,    70,    59,    59,    59,    59,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    59,    70,    59,    77,
      77,    77,    61,    70,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    70,    70,    59,    59,    61,    70,    59,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    61,    70,    35,    35,    77,    37,     3,    69,
      77,    59,    59,    59,    59,    59,    59,    59,    70,    70,
      70,    33,    77,    77,    77,    61,    70,    59,    70,    77,
      61,    70,    77,    77,    77,    77,    61,    70,    36,    36,
      77,    37,    69,    77,    59,    70,    77,    56,    92,    93,
      93,    61,    59,    77,    61,    77,    61,    60,    69,    59,
      77,    77,    61,    70,    77,    61,    70,    77,    61
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
      92,    92,    92,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96
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
       4,     6,     8,     3,     3,     6,     8,    10,     1,     4,
       6,     8,     1,     1,     4,     4,     4,     6,     8,     4,
       4,     4,     4,     4,     4,     4,     1,     4
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
     325,   334,   343,   355,   356,   358,   361,   364,   369,   371,
     374,   377,   383,   387,   392,   393,   394,   402,   408,   418,
     419,   420,   421,   424,   425,   443,   449,   450
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
#line 2162 "../GenesysParser.cpp" // lalr1.cc:1167
#line 464 "bisonparser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
