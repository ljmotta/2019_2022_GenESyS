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
    #line 32 "bisonparser.yy" // lalr1.cc:741
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
#line 187 "bisonparser.yy" // lalr1.cc:859
    {YYACCEPT;}
#line 756 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 188 "bisonparser.yy" // lalr1.cc:859
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor);}
#line 762 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 190 "bisonparser.yy" // lalr1.cc:859
    { yyerrok; }
#line 768 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 193 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 774 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 196 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 780 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 197 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 786 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 198 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 792 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 199 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 798 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 200 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 804 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 201 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 810 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 202 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 816 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 203 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 822 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 204 "bisonparser.yy" // lalr1.cc:859
    {}
#line 828 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 207 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 834 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 208 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 840 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 211 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 846 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 212 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 852 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 213 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 858 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 214 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 864 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 215 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = pow(yystack_[2].value.as< obj_t > ().valor,yystack_[0].value.as< obj_t > ().valor);}
#line 870 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 216 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = -yystack_[0].value.as< obj_t > ().valor;}
#line 876 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 219 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 882 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 220 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 888 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 221 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 894 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 222 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 900 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 223 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 906 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 224 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 912 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 225 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 918 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 226 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 924 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 233 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor;}
#line 930 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 234 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 936 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 237 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 942 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 238 "bisonparser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 948 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 241 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 954 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 242 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 960 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 243 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 966 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 244 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 972 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 245 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 978 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 246 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 984 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 249 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 990 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 250 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getInfos()->getReplicationLength();}
#line 996 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 253 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor); }
#line 1002 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 254 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); }
#line 1008 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 257 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1014 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 258 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1020 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 259 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1026 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 260 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1032 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 263 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleExponential(yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1038 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 264 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1044 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 265 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleUniform(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Unificada"; }
#line 1050 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 266 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleWeibull(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1056 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 267 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleLogNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1062 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 268 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleGamma(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1068 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 269 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleErlang(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1074 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 270 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleTriangular(yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1080 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 271 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getProbs()->sampleBeta(yystack_[7].value.as< obj_t > ().valor,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1086 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 277 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1092 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 285 "bisonparser.yy" // lalr1.cc:859
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
#line 305 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1119 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 309 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1125 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 310 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 1131 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 313 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1137 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 314 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(std::to_string(yystack_[1].value.as< obj_t > ().valor));}
#line 1143 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 315 "bisonparser.yy" // lalr1.cc:859
    { std::string index(std::to_string(yystack_[3].value.as< obj_t > ().valor)); index.append(","); index.append(std::to_string(yystack_[1].value.as< obj_t > ().valor)); yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 1149 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 319 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Formula*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Formula>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 1155 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 323 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = 0; }
#line 1161 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 328 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1167 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 329 "bisonparser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1173 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 330 "bisonparser.yy" // lalr1.cc:859
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
#line 337 "bisonparser.yy" // lalr1.cc:859
    {   // @TODO: how can I get the "name" of the atributo?
							    yylhs.value.as< obj_t > ().valor = 0;
							}
#line 1193 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 344 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1199 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 345 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1205 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 346 "bisonparser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1211 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 347 "bisonparser.yy" // lalr1.cc:859
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
#line 1233 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 365 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1239 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 366 "bisonparser.yy" // lalr1.cc:859
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
#line 1257 "../GenesysParser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 383 "bisonparser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Set*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Set>(),yystack_[1].value.as< obj_t > ().id))->getElementSet()->size(); }
#line 1263 "../GenesysParser.cpp" // lalr1.cc:859
    break;


#line 1267 "../GenesysParser.cpp" // lalr1.cc:859
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


  const signed char genesyspp_parser::yypact_ninf_ = -116;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short int
  genesyspp_parser::yypact_[] =
  {
     205,   -60,  -116,   260,  -116,  -116,  -116,  -116,  -116,  -116,
     -42,   -39,   -38,   -33,   -32,   -31,   -30,    -6,    -5,    -4,
      -3,    -2,    -1,     0,     2,     3,  -116,  -116,    18,   -35,
    -116,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   -55,  -116,   315,   315,  -116,    30,  -116,   997,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,    38,    39,    47,    48,    49,    50,    51,
      52,    54,    59,    61,    62,    57,   315,   604,    53,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   612,   628,   669,   381,   685,   693,   701,
     390,   399,   408,   424,   467,   483,   492,   501,   510,   -50,
     709,   315,   315,    55,    56,    58,    60,    68,    69,    70,
      80,    83,    45,    84,    36,  -116,   726,   -49,   -49,   -49,
     -49,   112,   112,   -40,   -40,    53,   997,    53,   -49,   -49,
    -116,  -116,  -116,   315,  -116,  -116,  -116,   315,   315,   315,
     315,   315,   315,   315,   315,   315,  -116,   315,   315,   766,
     783,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
      78,  -116,   315,  -116,  -116,   795,   803,   823,   860,   880,
     888,   896,   526,   569,   997,   585,   953,   315,   315,    85,
     367,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   315,   315,
     315,   315,   960,   967,  -116,  -116,   980,   594,   997,   997,
     -35,   -35,  -116,   315,    79,  -116,    81,  -116,   990,   315,
     315,  -116,   997,   997
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    66,     0,     5,     6,     1,    17,    18,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    46,     0,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    73,     0,     0,     3,     0,     4,     7,
      15,     8,     9,    16,    33,    34,    11,    42,    40,    39,
      41,    44,    12,    13,    14,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,    28,    30,    31,
      32,    25,    26,    19,    20,    22,    23,    21,    27,    29,
      47,    48,    49,     0,    51,    50,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,    80,    79,    83,    81,    82,    84,    75,    77,    76,
       0,    85,     0,    71,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,     0,    36,     0,     0,     0,
       0,    52,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,    78,    72,     0,     0,    64,    35,
       0,     0,    60,     0,     0,    38,     0,    37,     0,     0,
       0,    61,    68,    69
  };

  const signed char
  genesyspp_parser::yypgoto_[] =
  {
    -116,  -116,  -116,   -41,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   -29,  -115,
     -27,  -116,  -116
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   129,     4,    62,   235,
      63,    64,    65
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
      83,    30,    84,    97,    98,   176,     5,   106,   107,   108,
     109,   110,    66,    96,   177,    67,    68,    42,   108,   109,
     110,    69,    70,    71,    72,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   130,   100,   101,   102,   103,   104,   105,    73,    74,
      75,    76,    77,    78,    79,   144,    80,    81,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    82,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    99,   133,   134,   135,   136,   137,
     179,   180,   106,   107,   108,   109,   110,   111,   112,   139,
     192,   131,   132,   138,   140,   193,   141,   142,   143,   190,
     181,   182,   109,   183,    30,   184,   237,     0,   100,   101,
     102,   103,   195,   185,   186,   187,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   188,   205,   206,   189,   191,
     224,     0,   239,     0,   240,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,     0,     0,     0,   222,   223,   106,   107,
     108,   109,   110,   111,   112,     0,     0,   226,   227,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,     0,     0,     0,     0,   242,   243,
       0,   234,   234,   236,   236,    -2,     1,     0,    -2,    -2,
      -2,     0,     0,     0,     0,     0,     0,     0,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,     0,    -2,     0,
       0,    -2,     2,     0,    -2,    -2,    -2,    -2,    -2,    -2,
       0,    -2,    -2,    -2,    -2,    -2,     0,    -2,    -2,    -2,
       6,     0,    -2,     7,     8,     9,     0,     0,     0,     0,
       0,    -2,    -2,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,     0,     0,    30,     0,     0,    31,
      32,    33,    34,    35,    36,     0,    37,    38,    39,    40,
      41,     0,    42,    43,    44,     0,     0,    45,     7,     8,
       9,     0,     0,     0,     0,     0,    46,    47,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,     0,
       0,    30,     0,     0,    31,    32,    33,    34,    35,    36,
       0,    37,    38,    39,    40,    41,     0,    42,    43,    44,
       0,     0,    45,   100,   101,   102,   103,   104,   105,     0,
       0,     0,    47,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,     0,     0,     0,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     100,   101,   102,   103,   104,   105,   225,   106,   107,   108,
     109,   110,   111,   112,     0,   163,   106,   107,   108,   109,
     110,   111,   112,     0,   167,   106,   107,   108,   109,   110,
     111,   112,     0,   168,   106,   107,   108,   109,   110,   111,
     112,     0,   169,   100,   101,   102,   103,   104,   105,     0,
     106,   107,   108,   109,   110,   111,   112,     0,   170,   100,
     101,   102,   103,   104,   105,     0,     0,     0,   100,   101,
     102,   103,   104,   105,     0,     0,     0,   100,   101,   102,
     103,   104,   105,     0,     0,     0,   100,   101,   102,   103,
     104,   105,     0,   106,   107,   108,   109,   110,   111,   112,
       0,   171,   100,   101,   102,   103,   104,   105,     0,   106,
     107,   108,   109,   110,   111,   112,     0,   172,   106,   107,
     108,   109,   110,   111,   112,     0,   173,   106,   107,   108,
     109,   110,   111,   112,     0,   174,   106,   107,   108,   109,
     110,   111,   112,     0,   175,   100,   101,   102,   103,   104,
     105,     0,   106,   107,   108,   109,   110,   111,   112,     0,
     218,   100,   101,   102,   103,   104,   105,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,     0,     0,   100,   101,
     102,   103,   104,   105,     0,   106,   107,   108,   109,   110,
     111,   112,     0,   219,   100,   101,   102,   103,   104,   105,
       0,   106,   107,   108,   109,   110,   111,   112,     0,   220,
     106,   107,   108,   109,   110,   111,   112,     0,   233,   145,
     106,   107,   108,   109,   110,   111,   112,   160,   106,   107,
     108,   109,   110,   111,   112,   100,   101,   102,   103,   104,
     105,     0,     0,   161,   106,   107,   108,   109,   110,   111,
     112,   100,   101,   102,   103,   104,   105,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,   100,   101,   102,
     103,   104,   105,     0,     0,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   162,   106,   107,   108,   109,   110,
     111,   112,   100,   101,   102,   103,   104,   105,     0,     0,
     164,   106,   107,   108,   109,   110,   111,   112,   165,   106,
     107,   108,   109,   110,   111,   112,   166,   106,   107,   108,
     109,   110,   111,   112,   178,   106,   107,   108,   109,   110,
     111,   112,   100,   101,   102,   103,   104,   105,     0,     0,
       0,   194,   106,   107,   108,   109,   110,   111,   112,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
     207,   100,   101,   102,   103,   104,   105,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,   208,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     211,   106,   107,   108,   109,   110,   111,   112,   212,   106,
     107,   108,   109,   110,   111,   112,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,   213,   106,
     107,   108,   109,   110,   111,   112,   100,   101,   102,   103,
     104,   105,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   214,   106,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,   106,   107,   108,   109,
     110,   111,   112,   216,   106,   107,   108,   109,   110,   111,
     112,   217,   106,   107,   108,   109,   110,   111,   112,   100,
     101,   102,   103,   104,   105,     0,   100,   101,   102,   103,
     104,   105,     0,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   221,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   230,   100,   101,   102,   103,
     104,   105,   231,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   106,   107,   108,   109,
     110,   111,   112,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,   232,   106,   107,   108,   109,
     110,   111,   112,     0,     0,   241,   106,   107,   108,   109,
     110,   111,   112,   106,   107,   108,   109,   110,   111,   112
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      29,    36,    29,    44,    45,    55,    66,    56,    57,    58,
      59,    60,    54,    68,    64,    54,    54,    52,    58,    59,
      60,    54,    54,    54,    54,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     6,     7,     8,     9,    10,    11,    54,    54,
      54,    54,    54,    54,    54,    96,    54,    54,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    38,    38,    38,    38,    38,
     131,   132,    56,    57,    58,    59,    60,    61,    62,    45,
      64,    63,    63,    51,    45,    69,    45,    45,    51,    64,
      55,    55,    59,    55,    36,    55,   231,    -1,     6,     7,
       8,     9,   163,    55,    55,    55,   167,   168,   169,   170,
     171,   172,   173,   174,   175,    55,   177,   178,    55,    55,
      55,    -1,    63,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,   207,   208,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,   218,   219,   220,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,   239,   240,
      -1,   230,   231,   230,   231,     0,     1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
       0,    -1,    57,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    66,    67,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    -1,    -1,    57,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    66,    67,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      -1,    -1,    57,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
       6,     7,     8,     9,    10,    11,    69,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,     6,     7,     8,     9,    10,    11,    -1,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,     6,     7,     8,     9,    10,    11,    -1,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,     6,     7,     8,     9,    10,
      11,    -1,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,     6,     7,     8,     9,    10,    11,
      -1,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    55,
      56,    57,    58,    59,    60,    61,    62,    55,    56,    57,
      58,    59,    60,    61,    62,     6,     7,     8,     9,    10,
      11,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,     6,     7,     8,     9,    10,    11,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    55,    56,
      57,    58,    59,    60,    61,    62,    55,    56,    57,    58,
      59,    60,    61,    62,    55,    56,    57,    58,    59,    60,
      61,    62,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      34,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    55,    56,
      57,    58,    59,    60,    61,    62,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,     6,     7,     8,     9,
      10,    11,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    55,    56,    57,    58,    59,    60,    61,
      62,    55,    56,    57,    58,    59,    60,    61,    62,     6,
       7,     8,     9,    10,    11,    -1,     6,     7,     8,     9,
      10,    11,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    32,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    35,     6,     7,     8,     9,
      10,    11,    35,     6,     7,     8,     9,    10,    11,    56,
      57,    58,    59,    60,    61,    62,    56,    57,    58,    59,
      60,    61,    62,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    56,    57,    58,    59,    60,    61,    62
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    37,    71,    87,    66,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    33,
      36,    39,    40,    41,    42,    43,    44,    46,    47,    48,
      49,    50,    52,    53,    54,    57,    66,    67,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    88,    90,    91,    92,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    88,    90,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    68,    73,    73,    54,
       6,     7,     8,     9,    10,    11,    56,    57,    58,    59,
      60,    61,    62,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    86,
      73,    63,    63,    38,    38,    38,    38,    38,    51,    45,
      45,    45,    45,    51,    73,    55,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      55,    55,    55,    64,    55,    55,    55,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    55,    64,    55,    73,
      73,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      64,    55,    64,    69,    55,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    34,    34,    88,
      73,    55,    55,    55,    55,    55,    55,    55,    64,    64,
      64,    32,    73,    73,    55,    69,    73,    73,    73,    73,
      35,    35,    55,    64,    88,    89,    90,    89,    73,    63,
      63,    55,    73,    73
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
      92,    92,    92,    92,    92,    92
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
       1,     4,     6,     1,     1,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4
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
       0,   186,   186,   187,   188,   189,   190,   193,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   207,   208,   211,
     212,   213,   214,   215,   216,   219,   220,   221,   222,   223,
     224,   225,   226,   229,   230,   233,   234,   237,   238,   241,
     242,   243,   244,   245,   246,   249,   250,   253,   254,   257,
     258,   259,   260,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   277,   281,   282,   285,   305,   309,   310,
     313,   314,   315,   319,   323,   328,   329,   330,   337,   344,
     345,   346,   347,   365,   366,   383
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
#line 1952 "../GenesysParser.cpp" // lalr1.cc:1167
#line 393 "bisonparser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
