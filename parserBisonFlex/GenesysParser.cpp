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
      case 19: // fEXPO
      case 20: // fNORM
      case 21: // fUNIF
      case 22: // fWEIB
      case 23: // fLOGN
      case 24: // fGAMM
      case 25: // fERLA
      case 26: // fTRIA
      case 27: // fBETA
      case 28: // fDISC
      case 29: // fTNOW
      case 30: // fTFIN
      case 31: // cIF
      case 32: // cELSE
      case 33: // cFOR
      case 34: // cTO
      case 35: // cDO
      case 36: // ATRIB
      case 37: // ILLEGAL
      case 38: // RESOURCE
      case 39: // fNR
      case 40: // fMR
      case 41: // fIRF
      case 42: // fRESSEIZES
      case 43: // fSTATE
      case 44: // fSETSUM
      case 45: // QUEUE
      case 46: // fNQ
      case 47: // fFIRSTINQ
      case 48: // fLASTINQ
      case 49: // fSAQUE
      case 50: // fAQUE
      case 51: // SET
      case 52: // fNUMSET
      case 53: // CSTAT
      case 54: // fTAVG
      case 55: // VARI
      case 56: // FORM
      case 74: // input
      case 75: // programa
      case 76: // expressao
      case 77: // numero
      case 78: // aritmetica
      case 79: // relacional
      case 80: // comando
      case 81: // comandoIF
      case 82: // comandoFOR
      case 83: // funcao
      case 84: // funcaoKernel
      case 85: // funcaoTrig
      case 86: // funcaoArit
      case 87: // funcaoProb
      case 88: // funcaoUser
      case 89: // listaparm
      case 90: // illegal
      case 91: // atributo
      case 92: // atribuicao
      case 93: // variavel
      case 94: // formula
      case 95: // funcaoPlugin
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
      case 19: // fEXPO
      case 20: // fNORM
      case 21: // fUNIF
      case 22: // fWEIB
      case 23: // fLOGN
      case 24: // fGAMM
      case 25: // fERLA
      case 26: // fTRIA
      case 27: // fBETA
      case 28: // fDISC
      case 29: // fTNOW
      case 30: // fTFIN
      case 31: // cIF
      case 32: // cELSE
      case 33: // cFOR
      case 34: // cTO
      case 35: // cDO
      case 36: // ATRIB
      case 37: // ILLEGAL
      case 38: // RESOURCE
      case 39: // fNR
      case 40: // fMR
      case 41: // fIRF
      case 42: // fRESSEIZES
      case 43: // fSTATE
      case 44: // fSETSUM
      case 45: // QUEUE
      case 46: // fNQ
      case 47: // fFIRSTINQ
      case 48: // fLASTINQ
      case 49: // fSAQUE
      case 50: // fAQUE
      case 51: // SET
      case 52: // fNUMSET
      case 53: // CSTAT
      case 54: // fTAVG
      case 55: // VARI
      case 56: // FORM
      case 74: // input
      case 75: // programa
      case 76: // expressao
      case 77: // numero
      case 78: // aritmetica
      case 79: // relacional
      case 80: // comando
      case 81: // comandoIF
      case 82: // comandoFOR
      case 83: // funcao
      case 84: // funcaoKernel
      case 85: // funcaoTrig
      case 86: // funcaoArit
      case 87: // funcaoProb
      case 88: // funcaoUser
      case 89: // listaparm
      case 90: // illegal
      case 91: // atributo
      case 92: // atribuicao
      case 93: // variavel
      case 94: // formula
      case 95: // funcaoPlugin
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

#line 576 "../GenesysParser.cpp" // lalr1.cc:741

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
      case 19: // fEXPO
      case 20: // fNORM
      case 21: // fUNIF
      case 22: // fWEIB
      case 23: // fLOGN
      case 24: // fGAMM
      case 25: // fERLA
      case 26: // fTRIA
      case 27: // fBETA
      case 28: // fDISC
      case 29: // fTNOW
      case 30: // fTFIN
      case 31: // cIF
      case 32: // cELSE
      case 33: // cFOR
      case 34: // cTO
      case 35: // cDO
      case 36: // ATRIB
      case 37: // ILLEGAL
      case 38: // RESOURCE
      case 39: // fNR
      case 40: // fMR
      case 41: // fIRF
      case 42: // fRESSEIZES
      case 43: // fSTATE
      case 44: // fSETSUM
      case 45: // QUEUE
      case 46: // fNQ
      case 47: // fFIRSTINQ
      case 48: // fLASTINQ
      case 49: // fSAQUE
      case 50: // fAQUE
      case 51: // SET
      case 52: // fNUMSET
      case 53: // CSTAT
      case 54: // fTAVG
      case 55: // VARI
      case 56: // FORM
      case 74: // input
      case 75: // programa
      case 76: // expressao
      case 77: // numero
      case 78: // aritmetica
      case 79: // relacional
      case 80: // comando
      case 81: // comandoIF
      case 82: // comandoFOR
      case 83: // funcao
      case 84: // funcaoKernel
      case 85: // funcaoTrig
      case 86: // funcaoArit
      case 87: // funcaoProb
      case 88: // funcaoUser
      case 89: // listaparm
      case 90: // illegal
      case 91: // atributo
      case 92: // atribuicao
      case 93: // variavel
      case 94: // formula
      case 95: // funcaoPlugin
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
#line 194 "bisonparser.yy" // lalr1.cc:859
    {YYACCEPT;}
#line 765 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 195 "bisonparser.yy" // lalr1.cc:859
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor);}
#line 771 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 197 "bisonparser.yy" // lalr1.cc:859
    { yyerrok; }
#line 777 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 200 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 783 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 203 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 789 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 204 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 795 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 205 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 801 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 206 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 807 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 207 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 813 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 208 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 819 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 209 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 825 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 210 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 831 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 212 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 837 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 214 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 843 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 217 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 849 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 218 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 855 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 221 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 861 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 222 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 867 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 223 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 873 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 224 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 879 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 225 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = pow(yystack_[2].value.as< obj_t > ().valor,yystack_[0].value.as< obj_t > ().valor);}
#line 885 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 226 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = -yystack_[0].value.as< obj_t > ().valor;}
#line 891 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 229 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 897 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 230 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 903 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 231 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 909 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 232 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 915 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 233 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 921 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 234 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 927 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 235 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 933 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 236 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 939 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 243 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor;}
#line 945 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 244 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 951 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 247 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 957 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 248 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 963 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 251 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 969 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 252 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 975 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 253 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 981 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 254 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 987 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 255 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 993 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 256 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 999 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 259 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->simulation()->simulatedTime();}
#line 1005 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 260 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->infos()->replicationLength();}
#line 1011 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 263 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor); }
#line 1017 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 264 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); }
#line 1023 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 267 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = round(yystack_[1].value.as< obj_t > ().valor);}
#line 1029 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 268 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1035 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 269 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = trunc(yystack_[1].value.as< obj_t > ().valor);}
#line 1041 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 270 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1047 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 273 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleExponential(yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1053 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 274 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1059 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 275 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleUniform(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Unificada"; }
#line 1065 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 276 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleWeibull(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1071 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 277 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleLogNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1077 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 278 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleGamma(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1083 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 279 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleErlang(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1089 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 280 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleTriangular(yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1095 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 281 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleBeta(yystack_[7].value.as< obj_t > ().valor,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1101 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 287 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1107 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 295 "bisonparser.yy" // lalr1.cc:859
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
#line 1128 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 315 "bisonparser.yy" // lalr1.cc:859
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
#line 1143 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 328 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1149 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 329 "bisonparser.yy" // lalr1.cc:859
    {((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[2].value.as< obj_t > ().id)))->setValue(yystack_[0].value.as< obj_t > ().valor);
						yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1156 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 331 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
									    ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
									    yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1164 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 334 "bisonparser.yy" // lalr1.cc:859
    {std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor)); 
											((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor);
											yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1172 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 337 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor));
													((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[9].value.as< obj_t > ().id)))->setValue(index, yystack_[0].value.as< obj_t > ().valor); 
													yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 1180 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 342 "bisonparser.yy" // lalr1.cc:859
    {   //std::cout << "VARI" << std::endl;
								    yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1187 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 344 "bisonparser.yy" // lalr1.cc:859
    { //std::cout << "VARI[exp]" << std::endl;
								    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
								  yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(index);}
#line 1195 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 347 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor)); 
								  yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 1202 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 349 "bisonparser.yy" // lalr1.cc:859
    { std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as< obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as< obj_t > ().valor));
								      yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->elements()->element(Util::TypeOf<Variable>(), yystack_[7].value.as< obj_t > ().id)))->getValue(index);}
#line 1209 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 354 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->elements()->element(Util::TypeOf<Formula>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1215 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 358 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1221 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 363 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1227 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 364 "bisonparser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1233 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 365 "bisonparser.yy" // lalr1.cc:859
    { if (((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
                                                            //id da 1a entidade da fila, talvez pegar nome
                                                            yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->id();
                                                          }else{
                                                            yylhs.value.as< obj_t > ().valor = 0;
                                                          }
                                                        }
#line 1245 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 372 "bisonparser.yy" // lalr1.cc:859
    {   
				 Util::identification queueID = yystack_[3].value.as< obj_t > ().id;
				 Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
				 double sum = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[3].value.as< obj_t > ().id)))->sumAttributesFromWaiting(attrID);
				  yylhs.value.as< obj_t > ().valor = sum;
				}
#line 1256 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 378 "bisonparser.yy" // lalr1.cc:859
    {
				 Util::identification queueID = yystack_[5].value.as< obj_t > ().id;
				 Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
				 double value = ((Queue*)(driver.getModel()->elements()->element(Util::TypeOf<Queue>(), yystack_[5].value.as< obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as< obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
				  yylhs.value.as< obj_t > ().valor = value;
				}
#line 1267 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 388 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1273 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 389 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1279 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 390 "bisonparser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1285 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 391 "bisonparser.yy" // lalr1.cc:859
    {  yylhs.value.as< obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState());
							}
#line 1292 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 394 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->elements()->element(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1298 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 395 "bisonparser.yy" // lalr1.cc:859
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
#line 1316 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 412 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Set*)driver.getModel()->elements()->element(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet()->size(); }
#line 1322 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 418 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1328 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 419 "bisonparser.yy" // lalr1.cc:859
    {
					    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->elements()->element(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as< obj_t > ().id)));
					    double value = cstat->getStatistics()->average();
					    yylhs.value.as< obj_t > ().valor = value;
					}
#line 1338 "../GenesysParser.cpp" // lalr1.cc:859
    break;


#line 1342 "../GenesysParser.cpp" // lalr1.cc:859
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


  const short int genesyspp_parser::yypact_ninf_ = -253;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short int
  genesyspp_parser::yypact_[] =
  {
     234,   -62,  -253,   294,  -253,  -253,  -253,  -253,  -253,  -253,
     -44,   -43,   -39,   -38,   -37,   -16,    -4,    -3,    -2,     1,
       2,    18,    19,    20,    21,    22,  -253,  -253,    23,   -33,
    -253,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,  -253,    47,   -52,  -253,   354,   354,  -253,
      49,  -253,  1197,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,    39,  -253,  -253,  -253,  -253,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,    50,    40,    48,
      79,    80,    81,    82,    83,    71,    78,    84,    86,    87,
      88,    73,    72,   354,   354,   741,    62,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   751,   761,   771,   450,   781,   843,   853,   459,
     523,   532,   541,   550,   559,   568,   632,   641,   -54,   863,
     354,   354,   354,    69,    70,    85,    89,    90,    91,    92,
      93,    94,    77,   103,    95,    96,    36,  1197,  -253,   873,
     -13,   -13,   -13,   -13,  1232,  1232,   -53,   -53,    62,  1197,
      62,   -13,   -13,  1197,  -253,  -253,  -253,   354,  -253,  -253,
    -253,   354,   354,   354,   354,   354,   354,   354,   354,   354,
    -253,   354,   354,   104,   888,   935,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,   119,   153,  -253,  -253,   106,
     354,  -253,   950,   964,   974,   984,  1046,  1056,  1066,   650,
     659,  1197,   668,   179,  -253,   354,   354,   354,    99,   107,
     354,   411,  -253,  -253,  -253,  -253,  -253,  -253,  -253,   354,
     354,   354,   354,   421,  1080,  1090,  -253,   122,  1197,   109,
     354,  1128,   677,  1197,  1197,  -253,   354,   -15,   -15,   101,
     354,  1152,  -253,   354,  1160,   -51,    39,  -253,  -253,  -253,
    1197,   113,  1170,  -253,   354,   354,  -253,   431,  1197,   106,
     354,   441,   109,   354,  1190,   113
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    67,     0,     5,     6,     1,    18,    19,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    74,    78,     0,     0,     3,
       0,     4,     7,     8,    12,    13,    10,    34,    35,     9,
      43,    41,    40,    42,    45,    15,    11,    16,    17,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    14,     0,
      29,    31,    32,    33,    26,    27,    20,    21,    23,    24,
      22,    28,    30,    69,    48,    49,    50,     0,    52,    51,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,    86,    85,    89,    87,
      88,    90,    80,    82,    81,     0,     0,    91,    93,    75,
       0,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,    37,    75,     0,     0,     0,     0,     0,
       0,     0,    53,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    71,    76,
       0,     0,     0,    65,    36,    76,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,    39,    38,    84,
      72,    77,     0,    77,     0,     0,    62,     0,    73,     0,
       0,     0,     0,     0,     0,     0
  };

  const short int
  genesyspp_parser::yypgoto_[] =
  {
    -253,  -253,  -253,   -47,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,   -27,  -252,
     131,  -253,  -253
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   138,     4,    65,    66,
      67,    68,    69
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
     105,   106,    88,    30,   190,   267,   268,   103,   274,     5,
     116,   117,   118,    70,    71,   191,   104,   104,    72,    73,
      74,    30,    87,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   139,
     265,    75,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    76,    77,    78,   156,   157,    79,    80,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    81,    82,    83,    84,    85,
      86,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   193,   194,   195,   209,   114,   115,   116,
     117,   118,   119,   120,   102,   210,   107,   121,   141,   140,
     108,   109,   110,   111,   112,   113,   142,   143,   144,   145,
     146,   147,   148,   149,   154,   155,   117,   196,   197,   150,
     212,   151,   152,   153,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   198,   222,   223,   205,   199,   200,   201,
     202,   203,   204,   207,   208,   228,   229,   246,   259,   269,
      89,     0,     0,   231,   224,   114,   115,   116,   117,   118,
     119,   120,   206,   225,   230,     0,   247,   260,   243,   244,
     245,   275,     0,   248,     0,   108,   109,   110,   111,   112,
     113,     0,   251,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,     0,     0,   264,
       0,   242,     0,   270,     0,     0,   272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   278,     0,
     266,   266,     0,   281,    -2,     1,   284,    -2,    -2,    -2,
     114,   115,   116,   117,   118,   119,   120,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,     0,    -2,     0,     0,
      -2,     2,     0,    -2,    -2,    -2,    -2,    -2,    -2,     0,
      -2,    -2,    -2,    -2,    -2,     0,    -2,    -2,    -2,    -2,
      -2,    -2,     0,     0,     6,     0,    -2,     7,     8,     9,
       0,     0,     0,     0,     0,    -2,    -2,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,     0,     0,
      30,     0,     0,    31,    32,    33,    34,    35,    36,     0,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,    48,     7,     8,     9,
       0,     0,     0,     0,     0,    49,    50,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,     0,     0,
      30,     0,     0,    31,    32,    33,    34,    35,    36,     0,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,    48,   108,   109,   110,
     111,   112,   113,     0,     0,     0,    50,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,   108,   109,   110,   111,
     112,   113,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   249,   114,   115,   116,   117,   118,   119,   120,     0,
     250,   255,   114,   115,   116,   117,   118,   119,   120,     0,
     256,   279,   114,   115,   116,   117,   118,   119,   120,     0,
     280,   282,   114,   115,   116,   117,   118,   119,   120,     0,
     283,   114,   115,   116,   117,   118,   119,   120,     0,   177,
     114,   115,   116,   117,   118,   119,   120,     0,   181,   108,
     109,   110,   111,   112,   113,     0,     0,     0,   108,   109,
     110,   111,   112,   113,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,   108,   109,   110,   111,
     112,   113,     0,     0,     0,   108,   109,   110,   111,   112,
     113,     0,     0,     0,   108,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,     0,   182,   114,   115,   116,   117,   118,   119,   120,
       0,   183,   114,   115,   116,   117,   118,   119,   120,     0,
     184,   114,   115,   116,   117,   118,   119,   120,     0,   185,
     114,   115,   116,   117,   118,   119,   120,     0,   186,   114,
     115,   116,   117,   118,   119,   120,     0,   187,   108,   109,
     110,   111,   112,   113,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,   108,   109,   110,   111,
     112,   113,     0,     0,     0,   108,   109,   110,   111,   112,
     113,     0,     0,     0,   108,   109,   110,   111,   112,   113,
       0,     0,     0,   108,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
       0,   188,   114,   115,   116,   117,   118,   119,   120,     0,
     189,   114,   115,   116,   117,   118,   119,   120,     0,   239,
     114,   115,   116,   117,   118,   119,   120,     0,   240,   114,
     115,   116,   117,   118,   119,   120,     0,   241,   114,   115,
     116,   117,   118,   119,   120,     0,   263,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,   158,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   174,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   175,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   176,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   178,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
       0,   179,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   180,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   192,   226,     0,   114,   115,   116,   117,   118,   119,
     120,   211,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   108,   109,   110,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,     0,   227,
     108,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,   232,     0,
       0,   114,   115,   116,   117,   118,   119,   120,     0,     0,
       0,     0,   233,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   234,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   235,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   108,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,     0,     0,   236,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   237,   257,     0,   114,   115,   116,
     117,   118,   119,   120,   238,   258,     0,   114,   115,   116,
     117,   118,   119,   120,   108,   109,   110,   111,   112,   113,
       0,   114,   115,   116,   117,   118,   119,   120,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   108,   109,
     110,   111,   112,   113,     0,     0,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   262,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   108,   109,   110,   111,
     112,   113,     0,   108,   109,   110,   111,   112,   113,     0,
       0,     0,   271,   114,   115,   116,   117,   118,   119,   120,
     273,   114,   115,   116,   117,   118,   119,   120,   276,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   114,   115,   116,   117,   118,   119,   120,   114,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      47,    48,    29,    36,    58,   257,   258,    59,    59,    71,
      63,    64,    65,    57,    57,    69,    68,    68,    57,    57,
      57,    36,    55,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      55,    57,     6,     7,     8,     9,    10,    11,    61,    62,
      63,    64,    65,    57,    57,    57,   103,   104,    57,    57,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,   140,   141,   142,    60,    61,    62,    63,
      64,    65,    66,    67,    57,    69,    57,    68,    68,    59,
       6,     7,     8,     9,    10,    11,    68,    38,    38,    38,
      38,    38,    51,    45,    51,    53,    64,    58,    58,    45,
     177,    45,    45,    45,   181,   182,   183,   184,   185,   186,
     187,   188,   189,    58,   191,   192,    69,    58,    58,    58,
      58,    58,    58,    58,    58,    36,     3,    58,    36,    58,
      29,    -1,    -1,   210,    60,    61,    62,    63,    64,    65,
      66,    67,    69,    69,    68,    -1,    69,    68,   225,   226,
     227,    68,    -1,   230,    -1,     6,     7,     8,     9,    10,
      11,    -1,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    32,    -1,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,    -1,
     257,   258,    -1,   280,     0,     1,   283,     3,     4,     5,
      61,    62,    63,    64,    65,    66,    67,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,     0,    -1,    62,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    71,    72,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    71,    72,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    72,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    58,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    58,    34,    -1,    61,    62,    63,    64,    65,    66,
      67,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,     6,     7,     8,     9,    10,    11,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    58,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    58,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      64,    65,    66,    67,    58,    35,    -1,    61,    62,    63,
      64,    65,    66,    67,    58,    35,    -1,    61,    62,    63,
      64,    65,    66,    67,     6,     7,     8,     9,    10,    11,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,     6,     7,
       8,     9,    10,    11,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      62,    63,    64,    65,    66,    67,     6,     7,     8,     9,
      10,    11,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      60,    61,    62,    63,    64,    65,    66,    67,    58,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    67
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    37,    74,    90,    71,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    33,
      36,    39,    40,    41,    42,    43,    44,    46,    47,    48,
      49,    50,    52,    53,    54,    55,    56,    57,    62,    71,
      72,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    91,    92,    93,    94,    95,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    55,    91,    93,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    59,    68,    76,    76,    57,     6,     7,
       8,     9,    10,    11,    61,    62,    63,    64,    65,    66,
      67,    68,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    89,    76,
      59,    68,    68,    38,    38,    38,    38,    38,    51,    45,
      45,    45,    45,    45,    51,    53,    76,    76,    58,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    58,    58,    58,    69,    58,    58,
      58,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      58,    69,    58,    76,    76,    76,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    69,    69,    58,    58,    60,
      69,    58,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    60,    69,    34,    34,    36,     3,
      68,    76,    58,    58,    58,    58,    58,    58,    58,    69,
      69,    69,    32,    76,    76,    76,    58,    69,    76,    60,
      69,    76,    76,    76,    76,    60,    69,    35,    35,    36,
      68,    76,    58,    69,    76,    55,    91,    92,    92,    58,
      76,    60,    76,    60,    59,    68,    58,    76,    76,    60,
      69,    76,    60,    69,    76,    60
  };

  const unsigned char
  genesyspp_parser::yyr1_[] =
  {
       0,    73,    74,    74,    74,    74,    74,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    89,    89,    90,    91,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95
  };

  const unsigned char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     7,     5,     8,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     6,     4,     6,     6,     6,     6,     6,
       6,     8,    10,     4,     4,     5,     3,     1,     1,     3,
       3,     6,     8,    10,     1,     4,     6,     8,     1,     1,
       4,     4,     4,     6,     8,     4,     4,     4,     4,     4,
       4,     4,     1,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NUMD", "NUMH", "CTEZERO",
  "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNOT", "fSIN", "fCOS",
  "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXPO", "fNORM", "fUNIF", "fWEIB",
  "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA", "fDISC", "fTNOW", "fTFIN",
  "cIF", "cELSE", "cFOR", "cTO", "cDO", "ATRIB", "ILLEGAL", "RESOURCE",
  "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE", "fSETSUM", "QUEUE", "fNQ",
  "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE", "SET", "fNUMSET", "CSTAT",
  "fTAVG", "VARI", "FORM", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"+\"",
  "\"-\"", "\"*\"", "\"^\"", "\"/\"", "\"<\"", "\">\"", "\"=\"", "\",\"",
  "NEG", "'\\n'", "\"USER\"", "$accept", "input", "programa", "expressao",
  "numero", "aritmetica", "relacional", "comando", "comandoIF",
  "comandoFOR", "funcao", "funcaoKernel", "funcaoTrig", "funcaoArit",
  "funcaoProb", "funcaoUser", "listaparm", "illegal", "atributo",
  "atribuicao", "variavel", "formula", "funcaoPlugin", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  genesyspp_parser::yyrline_[] =
  {
       0,   193,   193,   194,   195,   196,   197,   200,   203,   204,
     205,   206,   207,   208,   209,   210,   212,   214,   217,   218,
     221,   222,   223,   224,   225,   226,   229,   230,   231,   232,
     233,   234,   235,   236,   239,   240,   243,   244,   247,   248,
     251,   252,   253,   254,   255,   256,   259,   260,   263,   264,
     267,   268,   269,   270,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   287,   291,   292,   295,   315,   328,
     329,   331,   334,   337,   342,   344,   347,   349,   354,   358,
     363,   364,   365,   372,   378,   388,   389,   390,   391,   394,
     395,   412,   418,   419
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
#line 2090 "../GenesysParser.cpp" // lalr1.cc:1167
#line 433 "bisonparser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
