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
#line 40 "bisonparser.yy" // lalr1.cc:413

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
    #line 33 "bisonparser.yy" // lalr1.cc:741
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.getFile();
}

#line 580 "../GenesysParser.cpp" // lalr1.cc:741

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
#line 197 "bisonparser.yy" // lalr1.cc:859
    {YYACCEPT;}
#line 771 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 198 "bisonparser.yy" // lalr1.cc:859
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor);}
#line 777 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 200 "bisonparser.yy" // lalr1.cc:859
    { yyerrok; }
#line 783 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 203 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 789 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 206 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 795 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 207 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 801 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 208 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 807 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 209 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 813 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 210 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 819 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 211 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 825 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 212 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 831 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 213 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 837 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 215 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 843 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 217 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 849 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 220 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 855 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 221 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 861 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 224 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 867 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 225 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 873 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 226 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 879 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 227 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 885 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 228 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = pow(yystack_[2].value.as< obj_t > ().valor,yystack_[0].value.as< obj_t > ().valor);}
#line 891 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 229 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = exp(yystack_[1].value.as< obj_t > ().valor);}
#line 897 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 230 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = -yystack_[0].value.as< obj_t > ().valor;}
#line 903 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 233 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 909 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 234 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 915 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 235 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 921 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 236 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 927 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 237 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 933 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 238 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 939 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 239 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 945 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 240 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 951 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 243 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 957 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 244 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 963 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 247 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor; }
#line 969 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 248 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 975 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 251 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 981 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 252 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 987 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 255 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 993 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 256 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 999 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 257 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1005 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 258 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1011 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 259 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1017 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 260 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1023 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 263 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->simulation()->simulatedTime();}
#line 1029 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 264 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->infos()->replicationLength();}
#line 1035 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 267 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor); }
#line 1041 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 268 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); }
#line 1047 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 271 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = round(yystack_[1].value.as< obj_t > ().valor);}
#line 1053 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 272 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1059 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 273 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = trunc(yystack_[1].value.as< obj_t > ().valor);}
#line 1065 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 274 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1071 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 277 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleUniform(0.0,1.0); yylhs.value.as< obj_t > ().tipo = "Uniforme"; }
#line 1077 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 278 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleExponential(yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1083 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 279 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1089 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 280 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleUniform(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Uniforme"; }
#line 1095 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 281 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleWeibull(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1101 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 282 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleLogNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1107 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 283 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleGamma(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1113 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 284 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleErlang(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1119 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 285 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleTriangular(yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1125 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 286 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleBeta(yystack_[7].value.as< obj_t > ().valor,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1131 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 292 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1137 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 300 "bisonparser.yy" // lalr1.cc:859
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
#line 1158 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 320 "bisonparser.yy" // lalr1.cc:859
    {  
		    double attributeValue = 0.0;
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->attributeValue(yystack_[0].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1171 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 328 "bisonparser.yy" // lalr1.cc:859
    {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->attributeValue(index, yystack_[3].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1185 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 337 "bisonparser.yy" // lalr1.cc:859
    {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->attributeValue(index, yystack_[5].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1199 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 346 "bisonparser.yy" // lalr1.cc:859
    {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    if (driver.getModel()->simulation()->currentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->simulation()->currentEntity()->attributeValue(index, yystack_[7].value.as< obj_t > ().id);
		    }
		    yylhs.value.as< obj_t > ().valor = attributeValue; 
		}
#line 1213 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 357 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->value();}
#line 1219 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 358 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->value(index); }
#line 1227 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 361 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor)); 
		    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->value(index);}
#line 1235 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 364 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->value(index);}
#line 1243 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 371 "bisonparser.yy" // lalr1.cc:859
    { 
		    driver.getModel()->simulation()->currentEntity()->setAttributeValue("", yystack_[2].value.as< obj_t > ().id, yystack_[0].value.as< obj_t > ().valor);
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1251 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 374 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
		    driver.getModel()->simulation()->currentEntity()->setAttributeValue(index, yystack_[5].value.as< obj_t > ().id, yystack_[0].value.as< obj_t > ().valor);
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1260 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 378 "bisonparser.yy" // lalr1.cc:859
    {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor)); 
		    driver.getModel()->simulation()->currentEntity()->setAttributeValue(index, yystack_[7].value.as< obj_t > ().id, yystack_[0].value.as< obj_t > ().valor); 
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1269 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 382 "bisonparser.yy" // lalr1.cc:859
    {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
		    driver.getModel()->simulation()->currentEntity()->setAttributeValue(index, yystack_[9].value.as< obj_t > ().id, yystack_[0].value.as< obj_t > ().valor);
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1278 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 386 "bisonparser.yy" // lalr1.cc:859
    {
		    ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[2].value.as< obj_t > ().id)))->setValue(yystack_[0].value.as< obj_t > ().valor);
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1286 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 389 "bisonparser.yy" // lalr1.cc:859
    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
		    ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1295 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 393 "bisonparser.yy" // lalr1.cc:859
    {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor)); 
		    ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor);
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1304 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 397 "bisonparser.yy" // lalr1.cc:859
    {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
		    ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[9].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
		    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1313 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 404 "bisonparser.yy" // lalr1.cc:859
    { 
		    yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->elements()->element(Util::TypeOf<Formula>(), yystack_[0].value.as< obj_t > ().id)))->value();}
#line 1320 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 406 "bisonparser.yy" // lalr1.cc:859
    {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->elements()->element(Util::TypeOf<Formula>(), yystack_[3].value.as< obj_t > ().id)))->value(index);}
#line 1328 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 409 "bisonparser.yy" // lalr1.cc:859
    {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->elements()->element(Util::TypeOf<Formula>(), yystack_[5].value.as< obj_t > ().id)))->value(index);}
#line 1336 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 412 "bisonparser.yy" // lalr1.cc:859
    {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
		    yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->elements()->element(Util::TypeOf<Formula>(), yystack_[7].value.as< obj_t > ().id)))->value(index);}
#line 1344 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 418 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1350 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 423 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1356 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 424 "bisonparser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1362 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 425 "bisonparser.yy" // lalr1.cc:859
    { 
		    if (((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
			//id da 1a entidade da fila, talvez pegar nome
			yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->id();
		    }else{
			yylhs.value.as< obj_t > ().valor = 0;
		    }
		}
#line 1375 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 433 "bisonparser.yy" // lalr1.cc:859
    {   
		     Util::identification queueID = yystack_[3].value.as< obj_t > ().id;
		     Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
		     double sum = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[3].value.as< obj_t > ().id)))->sumAttributesFromWaiting(attrID);
		      yylhs.value.as< obj_t > ().valor = sum;
		}
#line 1386 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 439 "bisonparser.yy" // lalr1.cc:859
    {
		     Util::identification queueID = yystack_[5].value.as< obj_t > ().id;
		     Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
		     double value = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[5].value.as< obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as< obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
		      yylhs.value.as< obj_t > ().valor = value;
		}
#line 1397 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 449 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1403 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 450 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1409 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 451 "bisonparser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1415 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 99:
#line 452 "bisonparser.yy" // lalr1.cc:859
    {  yylhs.value.as< obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState()); }
#line 1421 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 454 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1427 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 455 "bisonparser.yy" // lalr1.cc:859
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
#line 1446 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 473 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Set*)driver.getModel()->elements()->element(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet()->size(); }
#line 1452 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 479 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1458 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 480 "bisonparser.yy" // lalr1.cc:859
    {
		    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->elements()->element(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as< obj_t > ().id)));
		    double value = cstat->getStatistics()->average();
		    yylhs.value.as< obj_t > ().valor = value;
		}
#line 1468 "../GenesysParser.cpp" // lalr1.cc:859
    break;


#line 1472 "../GenesysParser.cpp" // lalr1.cc:859
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


  const short int genesyspp_parser::yypact_ninf_ = -282;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short int
  genesyspp_parser::yypact_[] =
  {
     281,   -62,  -282,   343,  -282,  -282,  -282,  -282,  -282,  -282,
     -47,   -46,   -45,   -39,   -15,    -6,    -5,  -282,    -4,     4,
       5,    25,    26,    27,    28,    29,    30,    31,  -282,  -282,
      32,   -36,   -54,    33,    34,    35,    36,    37,    38,    43,
      52,    61,    62,    69,    70,  -282,    71,   -53,    72,   405,
     405,  -282,    73,  -282,  1501,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
      74,    75,    64,    67,   405,   405,    91,    99,   100,   101,
     102,   103,   105,   108,   110,   111,   112,   109,   106,   405,
     405,   405,   937,    97,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   947,   957,
     967,   696,  1031,  1041,  1051,  1061,   705,   714,   723,   732,
     741,   807,   816,   825,   834,   -56,  1071,   405,   405,   405,
     405,    41,  1501,   104,   107,   113,   114,   126,   128,   129,
     130,   131,    94,    95,   133,   138,   116,  1501,   464,  -282,
    1135,    16,    16,    16,    16,    50,    50,   -24,   -24,    97,
    1501,    97,    16,    16,  -282,  -282,  -282,   405,  -282,  -282,
    -282,  -282,   405,   405,   405,   405,   405,   405,   405,   405,
     405,  -282,   405,   405,   474,   484,  1142,  1149,    98,   405,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,   132,
     166,  -282,  -282,   134,   405,  -282,   405,  -282,  1159,  1173,
    1183,  1247,  1257,  1267,  1277,   843,   852,  1501,   918,  1284,
    -282,   405,  -282,   405,   405,   405,   405,   494,   139,   135,
     405,   504,   514,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
     405,   405,   405,   405,   580,   590,  1291,  1355,  1501,   137,
     405,  -282,   162,  1501,   140,   405,  -282,   405,  1365,   927,
    1501,    16,  -282,   405,  -282,   405,   -35,   -35,   405,  1373,
     142,   405,  1387,  1395,  -282,   405,  1403,  1437,   -52,   -51,
    -282,  -282,  1501,   145,  -282,  1501,   146,  -282,  1467,  -282,
    -282,   405,   405,   405,   405,  -282,   600,   610,  1501,  1501,
      98,   405,   134,   405,   620,   630,   137,   405,   140,   405,
    1475,  1483,   145,   146
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    69,     0,     5,     6,     1,    18,    19,    90,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,    74,    86,     0,
       0,     3,     0,     4,     7,     8,    12,    13,    10,    35,
      36,     9,    44,    42,    41,    43,    46,    15,    16,    11,
      17,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    14,
       0,    30,    32,    33,    34,    27,    28,    20,    21,    23,
      24,    22,    29,    31,    49,    50,    51,     0,    53,    52,
      25,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,    71,     0,
      97,    96,   100,    98,    99,   101,    91,    93,    92,     0,
       0,   102,   104,    75,     0,    87,     0,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,    38,
      71,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    72,
       0,    94,     0,    83,    76,     0,    88,     0,     0,     0,
      67,    37,    72,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
      40,    39,    80,    73,    95,    84,    77,    89,     0,    73,
      77,     0,     0,     0,     0,    64,     0,     0,    81,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
  };

  const short int
  genesyspp_parser::yypgoto_[] =
  {
    -282,  -282,  -282,   -49,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,   141,   172,
    -281,  -282,  -282
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,   145,     4,    67,    68,
      69,    70,    71
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
     112,   113,    90,   298,   201,   300,   301,    94,   109,   311,
     312,     5,    72,    73,    74,   202,    95,   110,    95,   110,
      75,    91,   299,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     146,   123,   124,   125,    76,   151,   152,   115,   116,   117,
     118,   119,   120,    77,    78,    79,   115,   116,   117,   118,
     166,   167,   168,    80,    81,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   121,
     122,   123,   124,   125,    82,    83,    84,    85,    86,    87,
      88,    89,    96,    97,    98,    99,   100,   101,   204,   205,
     206,   207,   102,   208,   121,   122,   123,   124,   125,   126,
     127,   103,   209,   121,   122,   123,   124,   125,   126,   127,
     104,   105,   115,   116,   117,   118,   119,   120,   106,   107,
     108,   153,   114,   111,   149,   147,   148,   150,   228,   154,
     155,   156,   157,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   159,   238,   239,   160,   158,   161,   162,   163,
     247,   165,   164,   124,   210,   219,   220,   211,   246,   249,
     248,     0,    92,   212,   213,   251,     0,   252,   223,   121,
     122,   123,   124,   125,   126,   127,   214,   224,   215,   216,
     217,   218,   264,   221,   265,   266,   267,   268,   222,   271,
     290,   273,   304,    93,   250,     0,   272,   288,     0,     0,
     291,   278,   279,   280,   281,   313,   314,     0,     0,     0,
       0,   289,     0,     0,     0,     0,   292,     0,   293,     0,
       0,     0,     0,     0,   296,     0,   297,     0,     0,   302,
       0,     0,   305,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   316,   317,   318,   319,     0,     0,     0,     0,
       0,     0,   324,     0,   325,     0,     0,     0,   330,     0,
     331,    -2,     1,     0,    -2,    -2,    -2,     0,     0,     0,
       0,     0,     0,     0,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,     0,    -2,     0,     0,    -2,
       2,     0,    -2,    -2,    -2,    -2,    -2,    -2,     0,    -2,
      -2,    -2,    -2,    -2,     0,    -2,    -2,    -2,    -2,    -2,
      -2,     0,     0,     6,     0,    -2,     7,     8,     9,     0,
       0,     0,     0,     0,    -2,    -2,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,     0,
       0,    32,     0,     0,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,     0,     0,     0,     0,    50,     7,     8,
       9,     0,     0,     0,     0,     0,    51,    52,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,     0,     0,    32,     0,     0,    33,    34,    35,    36,
      37,    38,     0,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,     0,     0,     0,     0,    50,
     115,   116,   117,   118,   119,   120,     0,     0,     0,    52,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   225,   121,   122,   123,
     124,   125,   126,   127,     0,   226,   240,   121,   122,   123,
     124,   125,   126,   127,     0,   241,   242,   121,   122,   123,
     124,   125,   126,   127,     0,   243,   269,   121,   122,   123,
     124,   125,   126,   127,     0,   270,   274,   121,   122,   123,
     124,   125,   126,   127,     0,   275,   276,   121,   122,   123,
     124,   125,   126,   127,     0,   277,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   282,   121,   122,   123,   124,   125,   126,   127,
       0,   283,   284,   121,   122,   123,   124,   125,   126,   127,
       0,   285,   320,   121,   122,   123,   124,   125,   126,   127,
       0,   321,   322,   121,   122,   123,   124,   125,   126,   127,
       0,   323,   326,   121,   122,   123,   124,   125,   126,   127,
       0,   327,   328,   121,   122,   123,   124,   125,   126,   127,
       0,   329,   115,   116,   117,   118,   119,   120,     0,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,   115,   116,
     117,   118,   119,   120,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,   125,   126,   127,     0,   187,   121,   122,
     123,   124,   125,   126,   127,     0,   192,   121,   122,   123,
     124,   125,   126,   127,     0,   193,   121,   122,   123,   124,
     125,   126,   127,     0,   194,   121,   122,   123,   124,   125,
     126,   127,     0,   195,   121,   122,   123,   124,   125,   126,
     127,     0,   196,   115,   116,   117,   118,   119,   120,     0,
       0,     0,   115,   116,   117,   118,   119,   120,     0,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   126,   127,     0,   197,   121,
     122,   123,   124,   125,   126,   127,     0,   198,   121,   122,
     123,   124,   125,   126,   127,     0,   199,   121,   122,   123,
     124,   125,   126,   127,     0,   200,   121,   122,   123,   124,
     125,   126,   127,     0,   260,   121,   122,   123,   124,   125,
     126,   127,     0,   261,   115,   116,   117,   118,   119,   120,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,   121,   122,   123,   124,   125,   126,   127,     0,   262,
     121,   122,   123,   124,   125,   126,   127,   169,   295,     0,
     121,   122,   123,   124,   125,   126,   127,   184,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   185,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   186,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   189,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   190,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   191,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   203,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   115,   116,   117,   118,   119,   120,     0,   115,   116,
     117,   118,   119,   120,     0,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,   244,   115,
     116,   117,   118,   119,   120,   245,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   227,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   121,   122,   123,   124,   125,
     126,   127,   121,   122,   123,   124,   125,   126,   127,   253,
       0,     0,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,   254,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   255,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
     115,   116,   117,   118,   119,   120,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   256,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   257,   263,     0,
     121,   122,   123,   124,   125,   126,   127,   258,   286,     0,
     121,   122,   123,   124,   125,   126,   127,   259,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   121,   122,   123,
     124,   125,   126,   127,   121,   122,   123,   124,   125,   126,
     127,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,   287,   115,   116,   117,   118,   119,   120,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   294,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   303,   121,   122,   123,   124,
     125,   126,   127,   115,   116,   117,   118,   119,   120,   306,
     121,   122,   123,   124,   125,   126,   127,   307,   121,   122,
     123,   124,   125,   126,   127,   309,   121,   122,   123,   124,
     125,   126,   127,   115,   116,   117,   118,   119,   120,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,   310,
     121,   122,   123,   124,   125,   126,   127,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   332,   121,   122,
     123,   124,   125,   126,   127,   333,   121,   122,   123,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,   126,
     127
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      49,    50,    38,    38,    60,   286,   287,    61,    61,    61,
      61,    73,    59,    59,    59,    71,    70,    70,    70,    70,
      59,    57,    57,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    65,    66,    67,    59,    94,    95,     6,     7,     8,
       9,    10,    11,    59,    59,    59,     6,     7,     8,     9,
     109,   110,   111,    59,    59,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    63,
      64,    65,    66,    67,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,   147,   148,
     149,   150,    59,    62,    63,    64,    65,    66,    67,    68,
      69,    59,    71,    63,    64,    65,    66,    67,    68,    69,
      59,    59,     6,     7,     8,     9,    10,    11,    59,    59,
      59,    40,    59,    61,    70,    61,    61,    70,   187,    40,
      40,    40,    40,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    47,   202,   203,    47,    53,    47,    47,    47,
     209,    55,    53,    66,    60,    71,    71,    60,    70,     3,
      38,    -1,    31,    60,    60,   224,    -1,   226,    62,    63,
      64,    65,    66,    67,    68,    69,    60,    71,    60,    60,
      60,    60,   241,    60,   243,   244,   245,   246,    60,    60,
      38,   250,    60,    31,    70,    -1,    71,    70,    -1,    -1,
      70,   260,   261,   262,   263,    70,    70,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,   275,    -1,   277,    -1,
      -1,    -1,    -1,    -1,   283,    -1,   285,    -1,    -1,   288,
      -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,   313,   314,    -1,    -1,    -1,    -1,
      -1,    -1,   321,    -1,   323,    -1,    -1,    -1,   327,    -1,
     329,     0,     1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    -1,    -1,     0,    -1,    64,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    73,    74,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    73,    74,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    74,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      63,    64,    65,    66,    67,    68,    69,    60,    71,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,     6,
       7,     8,     9,    10,    11,    36,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    60,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    63,    64,    65,    66,    67,
      68,    69,    63,    64,    65,    66,    67,    68,    69,    60,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    60,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
       6,     7,     8,     9,    10,    11,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    34,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    37,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    63,    64,    65,
      66,    67,    68,    69,    63,    64,    65,    66,    67,    68,
      69,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,     6,     7,     8,     9,    10,    11,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    60,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    62,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    62,
      63,    64,    65,    66,    67,    68,    69,    62,    63,    64,
      65,    66,    67,    68,    69,    62,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    62,    63,    64,
      65,    66,    67,    68,    69,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    39,    76,    92,    73,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    35,    38,    41,    42,    43,    44,    45,    46,    48,
      49,    50,    51,    52,    54,    55,    56,    57,    58,    59,
      64,    73,    74,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    93,    94,    95,
      96,    97,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      38,    57,    93,    94,    61,    70,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    61,
      70,    61,    78,    78,    59,     6,     7,     8,     9,    10,
      11,    63,    64,    65,    66,    67,    68,    69,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    91,    78,    61,    61,    70,
      70,    78,    78,    40,    40,    40,    40,    40,    53,    47,
      47,    47,    47,    47,    53,    55,    78,    78,    78,    60,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    60,    60,    60,    71,    60,    60,
      60,    60,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    60,    71,    60,    78,    78,    78,    78,    62,    71,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    71,
      71,    60,    60,    62,    71,    62,    71,    60,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      62,    71,    62,    71,    36,    36,    70,    78,    38,     3,
      70,    78,    78,    60,    60,    60,    60,    60,    60,    60,
      71,    71,    71,    34,    78,    78,    78,    78,    78,    62,
      71,    60,    71,    78,    62,    71,    62,    71,    78,    78,
      78,    78,    62,    71,    62,    71,    37,    37,    70,    78,
      38,    70,    78,    78,    60,    71,    78,    78,    38,    57,
      95,    95,    78,    62,    60,    78,    62,    62,    78,    62,
      62,    61,    61,    70,    70,    60,    78,    78,    78,    78,
      62,    71,    62,    71,    78,    78,    62,    71,    62,    71,
      78,    78,    62,    62
  };

  const unsigned char
  genesyspp_parser::yyr1_[] =
  {
       0,    75,    76,    76,    76,    76,    76,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    91,    91,    92,
      93,    93,    93,    93,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97
  };

  const unsigned char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     7,     5,     8,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     6,     1,     4,     6,     6,     6,
       6,     6,     6,     8,    10,     4,     4,     5,     3,     1,
       1,     4,     6,     8,     1,     4,     6,     8,     3,     6,
       8,    10,     3,     6,     8,    10,     1,     4,     6,     8,
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
  "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXP", "fRND1", "fEXPO", "fNORM",
  "fUNIF", "fWEIB", "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA", "fDISC",
  "fTNOW", "fTFIN", "cIF", "cELSE", "cFOR", "cTO", "cDO", "ATRIB",
  "ILLEGAL", "RESOURCE", "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE",
  "fSETSUM", "QUEUE", "fNQ", "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE",
  "SET", "fNUMSET", "CSTAT", "fTAVG", "VARI", "FORM", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"", "\"<\"",
  "\">\"", "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"", "$accept",
  "input", "programa", "expressao", "numero", "aritmetica", "relacional",
  "comando", "comandoIF", "comandoFOR", "funcao", "funcaoKernel",
  "funcaoTrig", "funcaoArit", "funcaoProb", "funcaoUser", "listaparm",
  "illegal", "atributo", "variavel", "atribuicao", "formula",
  "funcaoPlugin", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  genesyspp_parser::yyrline_[] =
  {
       0,   196,   196,   197,   198,   199,   200,   203,   206,   207,
     208,   209,   210,   211,   212,   213,   215,   217,   220,   221,
     224,   225,   226,   227,   228,   229,   230,   233,   234,   235,
     236,   237,   238,   239,   240,   243,   244,   247,   248,   251,
     252,   255,   256,   257,   258,   259,   260,   263,   264,   267,
     268,   271,   272,   273,   274,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   292,   296,   297,   300,
     320,   328,   337,   346,   357,   358,   361,   364,   371,   374,
     378,   382,   386,   389,   393,   397,   404,   406,   409,   412,
     418,   423,   424,   425,   433,   439,   449,   450,   451,   452,
     454,   455,   473,   479,   480
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
#line 2295 "../GenesysParser.cpp" // lalr1.cc:1167
#line 494 "bisonparser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
