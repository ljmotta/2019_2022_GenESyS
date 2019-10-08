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
      case 51: // fNUMSET
      case 52: // SET
      case 53: // VARI
      case 54: // FORM
      case 72: // input
      case 73: // programa
      case 74: // expressao
      case 75: // numero
      case 76: // aritmetica
      case 77: // relacional
      case 78: // comando
      case 79: // comandoIF
      case 80: // comandoFOR
      case 81: // funcao
      case 82: // funcaoKernel
      case 83: // funcaoTrig
      case 84: // funcaoArit
      case 85: // funcaoProb
      case 86: // funcaoUser
      case 87: // listaparm
      case 88: // illegal
      case 89: // atributo
      case 90: // atribuicao
      case 91: // variavel
      case 92: // formula
      case 93: // funcaoPlugin
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
      case 51: // fNUMSET
      case 52: // SET
      case 53: // VARI
      case 54: // FORM
      case 72: // input
      case 73: // programa
      case 74: // expressao
      case 75: // numero
      case 76: // aritmetica
      case 77: // relacional
      case 78: // comando
      case 79: // comandoIF
      case 80: // comandoFOR
      case 81: // funcao
      case 82: // funcaoKernel
      case 83: // funcaoTrig
      case 84: // funcaoArit
      case 85: // funcaoProb
      case 86: // funcaoUser
      case 87: // listaparm
      case 88: // illegal
      case 89: // atributo
      case 90: // atribuicao
      case 91: // variavel
      case 92: // formula
      case 93: // funcaoPlugin
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

#line 572 "../GenesysParser.cpp" // lalr1.cc:741

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
      case 51: // fNUMSET
      case 52: // SET
      case 53: // VARI
      case 54: // FORM
      case 72: // input
      case 73: // programa
      case 74: // expressao
      case 75: // numero
      case 76: // aritmetica
      case 77: // relacional
      case 78: // comando
      case 79: // comandoIF
      case 80: // comandoFOR
      case 81: // funcao
      case 82: // funcaoKernel
      case 83: // funcaoTrig
      case 84: // funcaoArit
      case 85: // funcaoProb
      case 86: // funcaoUser
      case 87: // listaparm
      case 88: // illegal
      case 89: // atributo
      case 90: // atribuicao
      case 91: // variavel
      case 92: // formula
      case 93: // funcaoPlugin
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
#line 188 "bisonparser.yy" // lalr1.cc:859
    {YYACCEPT;}
#line 759 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 189 "bisonparser.yy" // lalr1.cc:859
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor);}
#line 765 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 191 "bisonparser.yy" // lalr1.cc:859
    { yyerrok; }
#line 771 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 194 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 777 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 197 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 783 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 198 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 789 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 199 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 795 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 200 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 801 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 201 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 807 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 202 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 813 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 203 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 819 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 205 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 825 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 207 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 831 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 210 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 837 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 211 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 843 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 214 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 849 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 215 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 855 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 216 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 861 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 217 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 867 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 218 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = pow(yystack_[2].value.as< obj_t > ().valor,yystack_[0].value.as< obj_t > ().valor);}
#line 873 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 219 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = -yystack_[0].value.as< obj_t > ().valor;}
#line 879 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 222 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 885 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 223 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 891 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 224 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 897 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 225 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 903 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 226 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 909 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 227 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 915 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 228 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 921 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 229 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 927 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 236 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor;}
#line 933 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 237 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 939 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 240 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 945 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 241 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 951 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 244 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 957 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 245 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 963 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 246 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 969 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 247 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 975 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 248 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 981 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 249 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 987 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 252 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 993 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 253 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getInfos()->getReplicationLength();}
#line 999 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 256 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor); }
#line 1005 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 257 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); }
#line 1011 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 260 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = round(yystack_[1].value.as< obj_t > ().valor);}
#line 1017 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 261 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1023 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 262 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = trunc(yystack_[1].value.as< obj_t > ().valor);}
#line 1029 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 263 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1035 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 266 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleExponential(yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1041 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 267 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1047 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 268 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleUniform(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Unificada"; }
#line 1053 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 269 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleWeibull(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1059 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 270 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleLogNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1065 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 271 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleGamma(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1071 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 272 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleErlang(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1077 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 273 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleTriangular(yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1083 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 274 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleBeta(yystack_[7].value.as< obj_t > ().valor,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1089 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 280 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1095 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 288 "bisonparser.yy" // lalr1.cc:859
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
#line 1116 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 309 "bisonparser.yy" // lalr1.cc:859
    {  double attributeValue = 0.0;
			    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
				try {
				    // it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
				    attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(yystack_[0].value.as< obj_t > ().valor);
				} catch(...) {
				}
			    }
			    yylhs.value.as< obj_t > ().valor = attributeValue; 
			}
#line 1131 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 322 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1137 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 323 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1143 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 326 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1149 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 327 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(std::to_string(yystack_[1].value.as< obj_t > ().valor));}
#line 1155 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 328 "bisonparser.yy" // lalr1.cc:859
    { std::string index(std::to_string(yystack_[3].value.as< obj_t > ().valor)); index.append(","); index.append(std::to_string(yystack_[1].value.as< obj_t > ().valor)); yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 1161 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 332 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Formula>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1167 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 336 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1173 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 341 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1179 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 342 "bisonparser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1185 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 343 "bisonparser.yy" // lalr1.cc:859
    { if (((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
                                                            //id da 1a entidade da fila, talvez pegar nome
                                                            yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->getId();
                                                          }else{
                                                            yylhs.value.as< obj_t > ().valor = 0;
                                                          }
                                                        }
#line 1197 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 350 "bisonparser.yy" // lalr1.cc:859
    {   
				 Util::identification queueID = yystack_[3].value.as< obj_t > ().id;
				 Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
				 double sum = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[3].value.as< obj_t > ().id)))->sumAttributesFromWaiting(attrID);
				  yylhs.value.as< obj_t > ().valor = sum;
				}
#line 1208 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 356 "bisonparser.yy" // lalr1.cc:859
    {
				 Util::identification queueID = yystack_[5].value.as< obj_t > ().id;
				 Util::identification attrID = yystack_[1].value.as< obj_t > ().id;
				 double value = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[5].value.as< obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as< obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
				  yylhs.value.as< obj_t > ().valor = value;
				}
#line 1219 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 366 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1225 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 367 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1231 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 368 "bisonparser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1237 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 369 "bisonparser.yy" // lalr1.cc:859
    {  yylhs.value.as< obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState());
							}
#line 1244 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 372 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1250 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 373 "bisonparser.yy" // lalr1.cc:859
    {   unsigned int count=0;
							    Resource* res;
							    List<ModelElement*>* setList = ((Set*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet(); 
							    for (std::list<ModelElement*>::iterator it = setList->getList()->begin(); it!=setList->getList()->end(); it++) {
								res = dynamic_cast<Resource*>(*it);
								if (res != nullptr) {
								    if (res->getResourceState()==Resource::ResourceState::BUSY) {
									count++;
								    }
								}
							    }
							    yylhs.value.as< obj_t > ().valor = count; 
							}
#line 1268 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 390 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Set*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet()->size(); }
#line 1274 "../GenesysParser.cpp" // lalr1.cc:859
    break;


#line 1278 "../GenesysParser.cpp" // lalr1.cc:859
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


  const signed char genesyspp_parser::yypact_ninf_ = -83;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short int
  genesyspp_parser::yypact_[] =
  {
     199,   -61,   -83,   255,   -83,   -83,   -83,   -83,   -83,   -83,
     -43,   -36,   -34,   -33,   -32,   -31,    -7,    -6,    -5,    -4,
      -3,    -2,    -1,     0,     2,     3,   -83,   -83,    18,   -35,
     -83,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   -56,   -83,   311,   311,   -83,    31,   -83,
     967,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,    38,    39,   -18,    49,    50,    51,
      52,    48,    59,    60,    68,    69,    70,    64,   311,   134,
      57,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   594,   602,   610,   364,   668,
     676,   684,   374,   383,   392,   401,   461,   470,   479,   488,
     497,   -51,   692,   311,   311,    62,    63,    65,    66,    67,
      71,    81,    90,    91,    55,    61,    92,    36,   -83,   700,
     -50,   -50,   -50,   -50,   974,   974,   -44,   -44,    57,   967,
      57,   -50,   -50,   -83,   -83,   -83,   311,   -83,   -83,   -83,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   -83,
     311,   311,   758,   765,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,    89,   146,   -83,   311,   -83,   -83,   773,
     787,   795,   803,   831,   861,   869,   506,   566,   967,   575,
     901,   311,   311,    94,    86,   101,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   311,   311,   311,   311,   930,   937,   -83,
     116,   -83,   893,   584,   967,   967,   -35,   -35,    97,   -83,
     311,    93,   -83,   102,   -83,   -83,   960,   311,   311,   -83,
     967,   967
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    66,     0,     5,     6,     1,    17,    18,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    46,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    73,     0,     0,     3,     0,     4,
       7,     8,    11,    12,    10,    33,    34,     9,    42,    40,
      39,    41,    44,    14,    15,    16,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
      28,    30,    31,    32,    25,    26,    19,    20,    22,    23,
      21,    27,    29,    47,    48,    49,     0,    51,    50,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,    81,    80,    84,    82,    83,    85,
      75,    77,    76,     0,     0,    86,     0,    71,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
      36,     0,     0,     0,     0,     0,    52,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,    78,
       0,    72,     0,     0,    64,    35,     0,     0,     0,    60,
       0,     0,    38,     0,    37,    79,     0,     0,     0,    61,
      68,    69
  };

  const signed char
  genesyspp_parser::yypgoto_[] =
  {
     -83,   -83,   -83,   -42,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -29,   -82,
     -27,   -83,   -83
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   131,     4,    63,   242,
      64,    65,    66
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
      84,    30,    85,    99,   100,   179,     5,   108,   109,   110,
     111,   112,    67,    98,   180,   110,   111,   112,    43,    68,
     135,    69,    70,    71,    72,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   132,   102,   103,   104,   105,   106,   107,    73,    74,
      75,    76,    77,    78,    79,    80,   147,    81,    82,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    83,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   101,   136,   137,   138,
     139,   182,   183,   108,   109,   110,   111,   112,   113,   114,
     140,   196,   133,   134,   141,   142,   197,   102,   103,   104,
     105,   106,   107,   143,   144,   145,   146,   111,   184,   185,
     193,   186,   187,   188,   199,   213,   194,   189,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   190,   209,   210,
     102,   103,   104,   105,   106,   107,   191,   192,   195,   214,
     229,   230,   238,   245,   215,   244,     0,   247,   108,   109,
     110,   111,   112,   113,   114,     0,   248,     0,     0,   227,
     228,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   233,   234,   235,     0,     0,     0,     0,     0,
     148,   108,   109,   110,   111,   112,   113,   114,   246,    -2,
       1,     0,    -2,    -2,    -2,   250,   251,   241,   241,   243,
     243,     0,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,     0,    -2,     0,     0,    -2,     2,     0,    -2,    -2,
      -2,    -2,    -2,    -2,     0,    -2,    -2,    -2,    -2,    -2,
      -2,     0,    -2,    -2,    -2,     6,     0,    -2,     7,     8,
       9,     0,     0,     0,     0,     0,    -2,    -2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,     0,
       0,    30,     0,     0,    31,    32,    33,    34,    35,    36,
       0,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,     0,     0,    46,     7,     8,     9,     0,     0,     0,
       0,     0,    47,    48,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,     0,     0,    30,     0,     0,
      31,    32,    33,    34,    35,    36,     0,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,     0,     0,    46,
     102,   103,   104,   105,   106,   107,     0,     0,     0,    48,
     102,   103,   104,   105,   106,   107,     0,     0,     0,   102,
     103,   104,   105,   106,   107,     0,     0,     0,   102,   103,
     104,   105,   106,   107,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,     0,   166,
       0,   108,   109,   110,   111,   112,   113,   114,     0,   170,
     108,   109,   110,   111,   112,   113,   114,     0,   171,   108,
     109,   110,   111,   112,   113,   114,     0,   172,   108,   109,
     110,   111,   112,   113,   114,     0,   173,   102,   103,   104,
     105,   106,   107,     0,     0,     0,   102,   103,   104,   105,
     106,   107,     0,     0,     0,   102,   103,   104,   105,   106,
     107,     0,     0,     0,   102,   103,   104,   105,   106,   107,
       0,     0,     0,   102,   103,   104,   105,   106,   107,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,   174,   108,   109,   110,
     111,   112,   113,   114,     0,   175,   108,   109,   110,   111,
     112,   113,   114,     0,   176,   108,   109,   110,   111,   112,
     113,   114,     0,   177,   108,   109,   110,   111,   112,   113,
     114,     0,   178,   108,   109,   110,   111,   112,   113,   114,
       0,   223,   102,   103,   104,   105,   106,   107,     0,     0,
       0,   102,   103,   104,   105,   106,   107,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,     0,   102,   103,
     104,   105,   106,   107,     0,     0,   102,   103,   104,   105,
     106,   107,     0,   108,   109,   110,   111,   112,   113,   114,
       0,   224,   108,   109,   110,   111,   112,   113,   114,     0,
     225,   108,   109,   110,   111,   112,   113,   114,     0,   240,
     163,   108,   109,   110,   111,   112,   113,   114,   164,   108,
     109,   110,   111,   112,   113,   114,   165,   108,   109,   110,
     111,   112,   113,   114,   102,   103,   104,   105,   106,   107,
       0,     0,   102,   103,   104,   105,   106,   107,     0,     0,
     102,   103,   104,   105,   106,   107,     0,     0,   102,   103,
     104,   105,   106,   107,     0,     0,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   108,   109,   110,   111,   112,
     113,   114,   168,   108,   109,   110,   111,   112,   113,   114,
     169,   108,   109,   110,   111,   112,   113,   114,   181,   108,
     109,   110,   111,   112,   113,   114,   198,   108,   109,   110,
     111,   112,   113,   114,   102,   103,   104,   105,   106,   107,
       0,   102,   103,   104,   105,   106,   107,     0,     0,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,   211,   102,   103,   104,   105,   106,   107,   212,
       0,   102,   103,   104,   105,   106,   107,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   108,   109,   110,   111,   112,   113,   114,   216,
     108,   109,   110,   111,   112,   113,   114,   102,   103,   104,
     105,   106,   107,   217,   108,   109,   110,   111,   112,   113,
     114,   218,   108,   109,   110,   111,   112,   113,   114,   219,
     108,   109,   110,   111,   112,   113,   114,   102,   103,   104,
     105,   106,   107,     0,     0,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   220,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,     0,     0,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   221,   108,   109,
     110,   111,   112,   113,   114,   222,   108,   109,   110,   111,
     112,   113,   114,   226,     0,     0,   102,   103,   104,   105,
     106,   107,     0,   102,   103,   104,   105,   106,   107,   239,
     108,   109,   110,   111,   112,   113,   114,     0,   108,   109,
     110,   111,   112,   113,   114,   236,   102,   103,   104,   105,
     106,   107,   237,   102,   103,   104,   105,   106,   107,     0,
     102,   103,   104,   105,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,   108,   109,   110,
     111,   112,   113,   114,   108,   109,   110,   111,   112,   113,
     114,   108,   109,   110,   111,   112,   113,   114
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      29,    36,    29,    45,    46,    56,    67,    57,    58,    59,
      60,    61,    55,    69,    65,    59,    60,    61,    53,    55,
      38,    55,    55,    55,    55,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     6,     7,     8,     9,    10,    11,    55,    55,
      55,    55,    55,    55,    55,    55,    98,    55,    55,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    38,    38,    38,
      38,   133,   134,    57,    58,    59,    60,    61,    62,    63,
      52,    65,    64,    64,    45,    45,    70,     6,     7,     8,
       9,    10,    11,    45,    45,    45,    52,    60,    56,    56,
      65,    56,    56,    56,   166,    36,    65,    56,   170,   171,
     172,   173,   174,   175,   176,   177,   178,    56,   180,   181,
       6,     7,     8,     9,    10,    11,    56,    56,    56,     3,
      56,    65,    36,    56,   196,   237,    -1,    64,    57,    58,
      59,    60,    61,    62,    63,    -1,    64,    -1,    -1,   211,
     212,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,   240,     0,
       1,    -1,     3,     4,     5,   247,   248,   236,   237,   236,
     237,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,     0,    -1,    58,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    67,    68,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    -1,    -1,    58,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    67,    68,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    -1,    -1,    58,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    68,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      56,    57,    58,    59,    60,    61,    62,    63,    56,    57,
      58,    59,    60,    61,    62,    63,    56,    57,    58,    59,
      60,    61,    62,    63,     6,     7,     8,     9,    10,    11,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    56,    57,    58,    59,    60,    61,    62,    63,
      56,    57,    58,    59,    60,    61,    62,    63,    56,    57,
      58,    59,    60,    61,    62,    63,    56,    57,    58,    59,
      60,    61,    62,    63,     6,     7,     8,     9,    10,    11,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,     6,     7,     8,     9,    10,    11,    34,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    57,    58,    59,    60,    61,
      62,    63,    57,    58,    59,    60,    61,    62,    63,    56,
      57,    58,    59,    60,    61,    62,    63,     6,     7,     8,
       9,    10,    11,    56,    57,    58,    59,    60,    61,    62,
      63,    56,    57,    58,    59,    60,    61,    62,    63,    56,
      57,    58,    59,    60,    61,    62,    63,     6,     7,     8,
       9,    10,    11,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    56,    57,    58,    59,    60,
      61,    62,    63,    32,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,     6,     7,     8,     9,    10,    11,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    57,    58,
      59,    60,    61,    62,    63,    35,     6,     7,     8,     9,
      10,    11,    35,     6,     7,     8,     9,    10,    11,    -1,
       6,     7,     8,     9,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    57,    58,    59,    60,    61,    62,
      63,    57,    58,    59,    60,    61,    62,    63
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    37,    72,    88,    67,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    33,
      36,    39,    40,    41,    42,    43,    44,    46,    47,    48,
      49,    50,    51,    53,    54,    55,    58,    67,    68,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    89,    91,    92,    93,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    89,    91,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    69,    74,
      74,    55,     6,     7,     8,     9,    10,    11,    57,    58,
      59,    60,    61,    62,    63,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    87,    74,    64,    64,    38,    38,    38,    38,    38,
      52,    45,    45,    45,    45,    45,    52,    74,    56,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    56,    56,    56,    65,    56,    56,    56,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    56,
      65,    56,    74,    74,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    65,    65,    56,    65,    70,    56,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    34,    34,    36,     3,    74,    56,    56,    56,    56,
      56,    56,    56,    65,    65,    65,    32,    74,    74,    56,
      65,    70,    74,    74,    74,    74,    35,    35,    36,    56,
      65,    89,    90,    91,    90,    56,    74,    64,    64,    56,
      74,    74
  };

  const unsigned char
  genesyspp_parser::yyr1_[] =
  {
       0,    71,    72,    72,    72,    72,    72,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    87,    87,    88,    89,    90,    90,
      91,    91,    91,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93
  };

  const unsigned char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     7,     5,     8,     8,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     6,     4,     6,     6,     6,     6,     6,     6,
       8,    10,     4,     4,     5,     3,     1,     1,     3,     3,
       1,     4,     6,     1,     1,     4,     4,     4,     6,     8,
       4,     4,     4,     4,     4,     4,     4
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
  "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE", "fNUMSET", "SET", "VARI",
  "FORM", "\"(\"", "\")\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"",
  "\"<\"", "\">\"", "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"", "\"[\"",
  "\"]\"", "$accept", "input", "programa", "expressao", "numero",
  "aritmetica", "relacional", "comando", "comandoIF", "comandoFOR",
  "funcao", "funcaoKernel", "funcaoTrig", "funcaoArit", "funcaoProb",
  "funcaoUser", "listaparm", "illegal", "atributo", "atribuicao",
  "variavel", "formula", "funcaoPlugin", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  genesyspp_parser::yyrline_[] =
  {
       0,   187,   187,   188,   189,   190,   191,   194,   197,   198,
     199,   200,   201,   202,   203,   205,   207,   210,   211,   214,
     215,   216,   217,   218,   219,   222,   223,   224,   225,   226,
     227,   228,   229,   232,   233,   236,   237,   240,   241,   244,
     245,   246,   247,   248,   249,   252,   253,   256,   257,   260,
     261,   262,   263,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   280,   284,   285,   288,   309,   322,   323,
     326,   327,   328,   332,   336,   341,   342,   343,   350,   356,
     366,   367,   368,   369,   372,   373,   390
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
#line 1962 "../GenesysParser.cpp" // lalr1.cc:1167
#line 400 "bisonparser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
