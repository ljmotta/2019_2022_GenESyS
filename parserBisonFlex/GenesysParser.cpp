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
#line 35 "bisonparser.yy" // lalr1.cc:413

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
      case 15: // fAINT
      case 16: // fMOD
      case 17: // fINT
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
      case 50: // fNUMSET
      case 51: // SET
      case 52: // VARI
      case 53: // FORM
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
      case 81: // funcaoKernel
      case 82: // funcaoTrig
      case 83: // funcaoArit
      case 84: // funcaoProb
      case 85: // funcaoUser
      case 86: // listaparm
      case 87: // illegal
      case 88: // atributo
      case 89: // atribuicao
      case 90: // variavel
      case 91: // formula
      case 92: // funcaoPlugin
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
      case 15: // fAINT
      case 16: // fMOD
      case 17: // fINT
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
      case 50: // fNUMSET
      case 51: // SET
      case 52: // VARI
      case 53: // FORM
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
      case 81: // funcaoKernel
      case 82: // funcaoTrig
      case 83: // funcaoArit
      case 84: // funcaoProb
      case 85: // funcaoUser
      case 86: // listaparm
      case 87: // illegal
      case 88: // atributo
      case 89: // atribuicao
      case 90: // variavel
      case 91: // formula
      case 92: // funcaoPlugin
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
    #line 28 "bisonparser.yy" // lalr1.cc:741
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.getFile();
}

#line 570 "../GenesysParser.cpp" // lalr1.cc:741

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
      case 15: // fAINT
      case 16: // fMOD
      case 17: // fINT
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
      case 50: // fNUMSET
      case 51: // SET
      case 52: // VARI
      case 53: // FORM
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
      case 81: // funcaoKernel
      case 82: // funcaoTrig
      case 83: // funcaoArit
      case 84: // funcaoProb
      case 85: // funcaoUser
      case 86: // listaparm
      case 87: // illegal
      case 88: // atributo
      case 89: // atribuicao
      case 90: // variavel
      case 91: // formula
      case 92: // funcaoPlugin
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
#line 183 "bisonparser.yy" // lalr1.cc:859
    {YYACCEPT;}
#line 756 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 184 "bisonparser.yy" // lalr1.cc:859
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor);}
#line 762 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 186 "bisonparser.yy" // lalr1.cc:859
    { yyerrok; }
#line 768 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 189 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 774 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 192 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 780 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 193 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 786 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 194 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 792 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 195 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 798 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 196 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 804 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 197 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 810 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 198 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 816 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 199 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 822 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 200 "bisonparser.yy" // lalr1.cc:859
    {}
#line 828 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 203 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 834 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 204 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 840 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 207 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 846 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 208 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 852 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 209 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 858 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 210 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 864 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 211 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = pow(yystack_[2].value.as< obj_t > ().valor,yystack_[0].value.as< obj_t > ().valor);}
#line 870 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 212 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = -yystack_[0].value.as< obj_t > ().valor;}
#line 876 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 215 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 882 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 216 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 888 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 217 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 894 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 218 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 900 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 219 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 906 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 220 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 912 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 221 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 918 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 222 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 924 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 229 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor;}
#line 930 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 230 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 936 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 233 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 942 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 234 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 948 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 237 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 954 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 238 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 960 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 239 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 966 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 240 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 972 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 241 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 978 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 242 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 984 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 245 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 990 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 246 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getInfos()->getReplicationLength();}
#line 996 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 249 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor); }
#line 1002 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 250 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); }
#line 1008 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 253 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1014 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 254 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1020 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 255 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1026 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 256 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1032 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 259 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleExponential(yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1038 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 260 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1044 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 261 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleUniform(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Unificada"; }
#line 1050 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 262 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleWeibull(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1056 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 263 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleLogNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1062 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 264 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleGamma(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1068 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 265 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleErlang(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1074 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 266 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleTriangular(yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1080 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 267 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleBeta(yystack_[7].value.as< obj_t > ().valor,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1086 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 273 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1092 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 281 "bisonparser.yy" // lalr1.cc:859
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
#line 1113 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 301 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1119 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 305 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1125 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 306 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1131 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 309 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1137 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 310 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(std::to_string(yystack_[1].value.as< obj_t > ().valor));}
#line 1143 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 311 "bisonparser.yy" // lalr1.cc:859
    { std::string index(std::to_string(yystack_[3].value.as< obj_t > ().valor)); index.append(","); index.append(std::to_string(yystack_[1].value.as< obj_t > ().valor)); yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 1149 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 315 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Formula>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1155 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 319 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1161 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 324 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1167 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 325 "bisonparser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1173 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 326 "bisonparser.yy" // lalr1.cc:859
    { if (((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
                                                                    //id da 1a entidade da fila, talvez pegar nome
                                                                    yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->getId();
                                                                  }else{
                                                                    yylhs.value.as< obj_t > ().valor = 0;
                                                                  }
                                                                }
#line 1185 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 336 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1191 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 337 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1197 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 338 "bisonparser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1203 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 339 "bisonparser.yy" // lalr1.cc:859
    {  switch(((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState()){
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
#line 1225 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 357 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1231 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 358 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1237 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 363 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1243 "../GenesysParser.cpp" // lalr1.cc:859
    break;


#line 1247 "../GenesysParser.cpp" // lalr1.cc:859
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
     199,   -60,   -83,   254,   -83,   -83,   -83,   -83,   -83,   -83,
     -42,   -41,   -39,   -38,   -36,   -34,    -3,    -2,    -1,     1,
       2,    24,    25,    26,    27,    28,   -83,   -83,    29,   -35,
     -83,    30,    31,    32,    33,    34,    37,    45,    47,    48,
      49,    44,   -83,   309,   309,   -83,    50,   -83,   976,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   -44,    51,    75,    77,    78,    79,    80,    68,
      76,    88,    91,    71,   309,   589,    64,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   646,   654,   662,   361,   670,   678,   686,   371,   380,
     389,   398,   457,   466,   475,   484,   493,   -50,   743,   309,
     309,    82,    83,    84,    85,    86,    87,    89,    90,    92,
      94,    36,   -83,   751,   -49,   -49,   -49,   -49,    15,    15,
     -10,   -10,    64,   976,    64,   -49,   -49,   -83,   -83,   -83,
     309,   -83,   -83,   -83,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   -83,   309,   309,   758,   815,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   309,   -83,
     -83,   772,   780,   837,   845,   853,   872,   880,   552,   561,
     976,   570,   911,   309,   309,   100,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   309,   309,   309,   309,   939,   946,   -83,
     954,   579,   976,   976,   -35,   -35,   -83,   309,   102,   -83,
     103,   -83,   969,   309,   309,   -83,   976,   976
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    66,     0,     5,     6,     1,    17,    18,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    46,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    73,     0,     0,     3,     0,     4,     7,    15,
       8,     9,    16,    33,    34,    11,    42,    40,    39,    41,
      44,    12,    13,    14,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,    28,    30,    31,    32,    25,    26,
      19,    20,    22,    23,    21,    27,    29,    47,    48,    49,
       0,    51,    50,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    79,    78,
      82,    80,    81,    83,    75,    77,    76,    84,     0,    71,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,    36,     0,     0,     0,    52,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,    72,
       0,     0,    64,    35,     0,     0,    60,     0,     0,    38,
       0,    37,     0,     0,     0,    61,    68,    69
  };

  const signed char
  genesyspp_parser::yypgoto_[] =
  {
     -83,   -83,   -83,   -40,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -29,   -82,
     -27,   -83,   -83
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,   127,     4,    61,   229,
      62,    63,    64
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
      82,    30,    83,    95,    96,   173,     5,   104,   105,   106,
     107,   108,    65,    66,   174,    67,    68,    41,    69,   129,
      70,    98,    99,   100,   101,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   128,    98,    99,   100,   101,   102,   103,   106,   107,
     108,    71,    72,    73,   141,    74,    75,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   104,   105,   106,   107,   108,   109,   110,    76,    77,
      78,    79,    80,    81,    84,    85,    86,    87,    88,   176,
     177,    89,   104,   105,   106,   107,   108,   109,   110,    90,
     188,    91,    92,    93,    97,   189,    98,    99,   100,   101,
     102,   103,    94,   131,   130,   132,   133,   134,   135,   136,
     191,   137,   140,   107,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   138,   201,   202,   139,   178,   179,   180,
     181,   182,   183,   231,   184,   185,     0,   186,   205,   187,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   217,   218,   233,   234,     0,     0,   219,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,     0,     0,
       0,     0,     0,   236,   237,   228,   228,   230,   230,    -2,
       1,     0,    -2,    -2,    -2,     0,     0,     0,     0,     0,
       0,     0,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,     0,    -2,     0,     0,    -2,     2,     0,    -2,    -2,
      -2,    -2,    -2,    -2,     0,    -2,    -2,    -2,     0,    -2,
       0,    -2,    -2,    -2,     6,     0,    -2,     7,     8,     9,
       0,     0,     0,     0,     0,    -2,    -2,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,     0,     0,
      30,     0,     0,    31,    32,    33,    34,    35,    36,     0,
      37,    38,    39,     0,    40,     0,    41,    42,    43,     0,
       0,    44,     7,     8,     9,     0,     0,     0,     0,     0,
      45,    46,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,     0,     0,    30,     0,     0,    31,    32,
      33,    34,    35,    36,     0,    37,    38,    39,     0,    40,
       0,    41,    42,    43,     0,     0,    44,    98,    99,   100,
     101,   102,   103,     0,     0,     0,    46,    98,    99,   100,
     101,   102,   103,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,     0,   160,     0,   104,   105,   106,
     107,   108,   109,   110,     0,   164,   104,   105,   106,   107,
     108,   109,   110,     0,   165,   104,   105,   106,   107,   108,
     109,   110,     0,   166,   104,   105,   106,   107,   108,   109,
     110,     0,   167,    98,    99,   100,   101,   102,   103,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,     0,
       0,    98,    99,   100,   101,   102,   103,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
       0,   168,   104,   105,   106,   107,   108,   109,   110,     0,
     169,   104,   105,   106,   107,   108,   109,   110,     0,   170,
     104,   105,   106,   107,   108,   109,   110,     0,   171,   104,
     105,   106,   107,   108,   109,   110,     0,   172,    98,    99,
     100,   101,   102,   103,     0,     0,     0,    98,    99,   100,
     101,   102,   103,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,     0,   213,   104,   105,   106,
     107,   108,   109,   110,     0,   214,   104,   105,   106,   107,
     108,   109,   110,     0,   215,   104,   105,   106,   107,   108,
     109,   110,     0,   227,   142,   104,   105,   106,   107,   108,
     109,   110,    98,    99,   100,   101,   102,   103,     0,     0,
      98,    99,   100,   101,   102,   103,     0,     0,    98,    99,
     100,   101,   102,   103,     0,     0,    98,    99,   100,   101,
     102,   103,     0,     0,    98,    99,   100,   101,   102,   103,
       0,     0,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   157,   104,   105,   106,   107,   108,   109,   110,   158,
     104,   105,   106,   107,   108,   109,   110,   159,   104,   105,
     106,   107,   108,   109,   110,   161,   104,   105,   106,   107,
     108,   109,   110,   162,   104,   105,   106,   107,   108,   109,
     110,   163,   104,   105,   106,   107,   108,   109,   110,    98,
      99,   100,   101,   102,   103,     0,     0,    98,    99,   100,
     101,   102,   103,     0,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,     0,    98,    99,   100,   101,
     102,   103,   203,     0,     0,     0,     0,     0,   175,   104,
     105,   106,   107,   108,   109,   110,   190,   104,   105,   106,
     107,   108,   109,   110,   104,   105,   106,   107,   108,   109,
     110,    98,    99,   100,   101,   102,   103,   206,   104,   105,
     106,   107,   108,   109,   110,   207,   104,   105,   106,   107,
     108,   109,   110,    98,    99,   100,   101,   102,   103,   204,
       0,    98,    99,   100,   101,   102,   103,     0,     0,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,    98,    99,
     100,   101,   102,   103,     0,     0,    98,    99,   100,   101,
     102,   103,   208,   104,   105,   106,   107,   108,   109,   110,
     209,   104,   105,   106,   107,   108,   109,   110,   210,   104,
     105,   106,   107,   108,   109,   110,     0,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,   211,   104,   105,
     106,   107,   108,   109,   110,   212,   104,   105,   106,   107,
     108,   109,   110,   216,     0,    98,    99,   100,   101,   102,
     103,     0,    98,    99,   100,   101,   102,   103,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   224,    98,    99,   100,   101,   102,
     103,   225,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   104,   105,   106,   107,   108,   109,   110,   226,
     104,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   235,   104,   105,   106,   107,   108,
     109,   110,   104,   105,   106,   107,   108,   109,   110
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      29,    36,    29,    43,    44,    55,    66,    56,    57,    58,
      59,    60,    54,    54,    64,    54,    54,    52,    54,    63,
      54,     6,     7,     8,     9,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     6,     7,     8,     9,    10,    11,    58,    59,
      60,    54,    54,    54,    94,    54,    54,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    56,    57,    58,    59,    60,    61,    62,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,   129,
     130,    54,    56,    57,    58,    59,    60,    61,    62,    54,
      64,    54,    54,    54,    54,    69,     6,     7,     8,     9,
      10,    11,    68,    38,    63,    38,    38,    38,    38,    51,
     160,    45,    51,    59,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    45,   174,   175,    45,    55,    55,    55,
      55,    55,    55,   225,    55,    55,    -1,    55,   188,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,   203,   204,    63,    63,    -1,    -1,    69,
      -1,    -1,    -1,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,   233,   234,   224,   225,   224,   225,     0,
       1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    48,    -1,    50,
      -1,    52,    53,    54,     0,    -1,    57,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    66,    67,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    50,    -1,    52,    53,    54,    -1,
      -1,    57,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      66,    67,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    48,    -1,    50,
      -1,    52,    53,    54,    -1,    -1,    57,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    67,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    -1,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    55,    56,    57,    58,    59,    60,
      61,    62,     6,     7,     8,     9,    10,    11,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    55,
      56,    57,    58,    59,    60,    61,    62,    55,    56,    57,
      58,    59,    60,    61,    62,    55,    56,    57,    58,    59,
      60,    61,    62,    55,    56,    57,    58,    59,    60,    61,
      62,    55,    56,    57,    58,    59,    60,    61,    62,     6,
       7,     8,     9,    10,    11,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,     6,     7,     8,     9,
      10,    11,    34,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    55,    56,    57,    58,
      59,    60,    61,    62,    56,    57,    58,    59,    60,    61,
      62,     6,     7,     8,     9,    10,    11,    55,    56,    57,
      58,    59,    60,    61,    62,    55,    56,    57,    58,    59,
      60,    61,    62,     6,     7,     8,     9,    10,    11,    34,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,     6,     7,
       8,     9,    10,    11,    -1,    -1,     6,     7,     8,     9,
      10,    11,    55,    56,    57,    58,    59,    60,    61,    62,
      55,    56,    57,    58,    59,    60,    61,    62,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    55,    56,    57,    58,    59,
      60,    61,    62,    32,    -1,     6,     7,     8,     9,    10,
      11,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    56,    57,    58,
      59,    60,    61,    62,    35,     6,     7,     8,     9,    10,
      11,    35,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    56,    57,    58,    59,    60,    61,    62,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    56,    57,    58,    59,    60,    61,    62
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    37,    71,    87,    66,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    33,
      36,    39,    40,    41,    42,    43,    44,    46,    47,    48,
      50,    52,    53,    54,    57,    66,    67,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    88,    90,    91,    92,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    88,    90,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    68,    73,    73,    54,     6,     7,
       8,     9,    10,    11,    56,    57,    58,    59,    60,    61,
      62,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    86,    73,    63,
      63,    38,    38,    38,    38,    38,    51,    45,    45,    45,
      51,    73,    55,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    55,    55,    55,
      64,    55,    55,    55,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    55,    64,    55,    73,    73,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    64,    69,
      55,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    34,    34,    73,    55,    55,    55,    55,
      55,    55,    55,    64,    64,    64,    32,    73,    73,    69,
      73,    73,    73,    73,    35,    35,    55,    64,    88,    89,
      90,    89,    73,    63,    63,    55,    73,    73
  };

  const unsigned char
  genesyspp_parser::yyr1_[] =
  {
       0,    70,    71,    71,    71,    71,    71,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    86,    86,    87,    88,    89,    89,
      90,    90,    90,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92
  };

  const unsigned char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     7,     5,     8,     8,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     6,     4,     6,     6,     6,     6,     6,     6,
       8,    10,     4,     4,     5,     3,     1,     1,     3,     3,
       1,     4,     6,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NUMD", "NUMH", "CTEZERO",
  "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNOT", "fSIN", "fCOS",
  "fAINT", "fMOD", "fINT", "fFRAC", "fEXPO", "fNORM", "fUNIF", "fWEIB",
  "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA", "fDISC", "fTNOW", "fTFIN",
  "cIF", "cELSE", "cFOR", "cTO", "cDO", "ATRIB", "ILLEGAL", "RESOURCE",
  "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE", "fSETSUM", "QUEUE", "fNQ",
  "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fNUMSET", "SET", "VARI", "FORM",
  "\"(\"", "\")\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"", "\"<\"",
  "\">\"", "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"", "\"[\"", "\"]\"",
  "$accept", "input", "programa", "expressao", "numero", "aritmetica",
  "relacional", "comando", "comandoIF", "comandoFOR", "funcao",
  "funcaoKernel", "funcaoTrig", "funcaoArit", "funcaoProb", "funcaoUser",
  "listaparm", "illegal", "atributo", "atribuicao", "variavel", "formula",
  "funcaoPlugin", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  genesyspp_parser::yyrline_[] =
  {
       0,   182,   182,   183,   184,   185,   186,   189,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   203,   204,   207,
     208,   209,   210,   211,   212,   215,   216,   217,   218,   219,
     220,   221,   222,   225,   226,   229,   230,   233,   234,   237,
     238,   239,   240,   241,   242,   245,   246,   249,   250,   253,
     254,   255,   256,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   273,   277,   278,   281,   301,   305,   306,
     309,   310,   311,   315,   319,   324,   325,   326,   336,   337,
     338,   339,   357,   358,   363
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
#line 1925 "../GenesysParser.cpp" // lalr1.cc:1167
#line 368 "bisonparser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
