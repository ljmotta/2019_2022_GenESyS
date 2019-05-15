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

#line 37 "../Genesys++-parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "Genesys++-parser.h"

// User implementation prologue.

#line 51 "../Genesys++-parser.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 34 "Genesys++-parser.yy" // lalr1.cc:413

# include "Genesys++-driver.h"


#line 58 "../Genesys++-parser.cpp" // lalr1.cc:413


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
#line 144 "../Genesys++-parser.cpp" // lalr1.cc:479

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
      case 65: // input
      case 66: // programa
      case 67: // expressao
      case 68: // numero
      case 69: // aritmetica
      case 70: // relacional
      case 71: // comando
      case 72: // comandoIF
      case 73: // comandoFOR
      case 74: // funcao
      case 75: // atributo
      case 76: // atribuicao
      case 77: // variavel
      case 78: // formula
      case 79: // funcaoTrig
      case 80: // funcaoArit
      case 81: // funcaoProb
      case 82: // funcaoStrc
      case 83: // funcaoUser
      case 84: // listaparm
      case 85: // illegal
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
      case 65: // input
      case 66: // programa
      case 67: // expressao
      case 68: // numero
      case 69: // aritmetica
      case 70: // relacional
      case 71: // comando
      case 72: // comandoIF
      case 73: // comandoFOR
      case 74: // funcao
      case 75: // atributo
      case 76: // atribuicao
      case 77: // variavel
      case 78: // formula
      case 79: // funcaoTrig
      case 80: // funcaoArit
      case 81: // funcaoProb
      case 82: // funcaoStrc
      case 83: // funcaoUser
      case 84: // listaparm
      case 85: // illegal
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
    #line 27 "Genesys++-parser.yy" // lalr1.cc:741
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.getFile();
}

#line 558 "../Genesys++-parser.cpp" // lalr1.cc:741

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
      case 65: // input
      case 66: // programa
      case 67: // expressao
      case 68: // numero
      case 69: // aritmetica
      case 70: // relacional
      case 71: // comando
      case 72: // comandoIF
      case 73: // comandoFOR
      case 74: // funcao
      case 75: // atributo
      case 76: // atribuicao
      case 77: // variavel
      case 78: // formula
      case 79: // funcaoTrig
      case 80: // funcaoArit
      case 81: // funcaoProb
      case 82: // funcaoStrc
      case 83: // funcaoUser
      case 84: // listaparm
      case 85: // illegal
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
#line 132 "Genesys++-parser.yy" // lalr1.cc:859
    {YYACCEPT;}
#line 738 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 133 "Genesys++-parser.yy" // lalr1.cc:859
    { driver.setResult(yystack_[0].value.as< obj_t > ().valor);}
#line 744 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 135 "Genesys++-parser.yy" // lalr1.cc:859
    { yyerrok; }
#line 750 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 138 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 756 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 141 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 762 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 142 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 768 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 143 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor;}
#line 774 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 144 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 780 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 145 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 786 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 146 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 792 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 147 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 798 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 148 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 804 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 149 "Genesys++-parser.yy" // lalr1.cc:859
    {}
#line 810 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 152 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 816 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 153 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 822 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 156 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor + yystack_[0].value.as< obj_t > ().valor;}
#line 828 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 157 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor - yystack_[0].value.as< obj_t > ().valor;}
#line 834 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 158 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor / yystack_[0].value.as< obj_t > ().valor;}
#line 840 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 159 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor * yystack_[0].value.as< obj_t > ().valor;}
#line 846 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 160 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = -yystack_[0].value.as< obj_t > ().valor;}
#line 852 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 163 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor && (int) yystack_[0].value.as< obj_t > ().valor;}
#line 858 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 164 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[2].value.as< obj_t > ().valor || (int) yystack_[0].value.as< obj_t > ().valor;}
#line 864 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 165 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor < yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 870 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 166 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor <= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 876 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 167 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor > yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 882 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 168 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor >= yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 888 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 169 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor == yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 894 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 170 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != yystack_[0].value.as< obj_t > ().valor ? 1 : 0;}
#line 900 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 177 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[4].value.as< obj_t > ().valor != 0 ? yystack_[2].value.as< obj_t > ().valor : yystack_[0].value.as< obj_t > ().valor;}
#line 906 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 178 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = yystack_[2].value.as< obj_t > ().valor != 0 ? yystack_[0].value.as< obj_t > ().valor : 0;}
#line 912 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 181 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 918 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 182 "Genesys++-parser.yy" // lalr1.cc:859
    {yylhs.value.as< obj_t > ().valor = 0; }
#line 924 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 185 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 930 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 186 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 936 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 187 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 942 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 188 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 948 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 189 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 954 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 194 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 960 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 198 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 966 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 199 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor; }
#line 972 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 202 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[0].value.as< obj_t > ().id)))->getValue();}
#line 978 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 203 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[3].value.as< obj_t > ().id)))->getValue(std::to_string(yystack_[1].value.as< obj_t > ().valor));}
#line 984 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 204 "Genesys++-parser.yy" // lalr1.cc:859
    { std::string index(std::to_string(yystack_[3].value.as< obj_t > ().valor)); index.append(","); index.append(std::to_string(yystack_[1].value.as< obj_t > ().valor)); yylhs.value.as< obj_t > ().valor = ((Variable*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as< obj_t > ().id)))->getValue(index);}
#line 990 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 208 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[0].value.as< obj_t > ().valor;}
#line 996 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 211 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = sin(yystack_[1].value.as< obj_t > ().valor); }
#line 1002 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 212 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = cos(yystack_[1].value.as< obj_t > ().valor); }
#line 1008 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 215 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1014 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 216 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor - (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1020 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 217 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[1].value.as< obj_t > ().valor;}
#line 1026 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 218 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = (int) yystack_[3].value.as< obj_t > ().valor % (int) yystack_[1].value.as< obj_t > ().valor; }
#line 1032 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 221 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleExponential(yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Exponencial";}
#line 1038 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 222 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Normal"; }
#line 1044 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 223 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleUniform(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Unificada"; }
#line 1050 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 224 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleWeibull(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Weibull"; }
#line 1056 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 225 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleLogNormal(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "LOGNormal"; }
#line 1062 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 226 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleGamma(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Gamma"; }
#line 1068 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 227 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleErlang(yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Erlang"; }
#line 1074 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 228 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleTriangular(yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Triangular"; }
#line 1080 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 229 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getSampler()->sampleBeta(yystack_[7].value.as< obj_t > ().valor,yystack_[5].value.as< obj_t > ().valor,yystack_[3].value.as< obj_t > ().valor,yystack_[1].value.as< obj_t > ().valor); yylhs.value.as< obj_t > ().tipo = "Beta"; }
#line 1086 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 233 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size();}
#line 1092 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 234 "Genesys++-parser.yy" // lalr1.cc:859
    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1098 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 235 "Genesys++-parser.yy" // lalr1.cc:859
    { if (((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->size() > 0){
                                                                    //id da 1a entidade da fila, talvez pegar nome
                                                                    yylhs.value.as< obj_t > ().valor = ((Queue*)(driver.getModel()->getElementManager()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as< obj_t > ().id)))->first()->getEntity()->getId();
                                                                  }else{
                                                                    yylhs.value.as< obj_t > ().valor = 0;
                                                                  }
                                                                }
#line 1110 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 242 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getCapacity();}
#line 1116 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 243 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getNumberBusy();}
#line 1122 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 244 "Genesys++-parser.yy" // lalr1.cc:859
    { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1128 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 245 "Genesys++-parser.yy" // lalr1.cc:859
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
#line 1150 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 263 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = ((Resource*)driver.getModel()->getElementManager()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as< obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1156 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 264 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1162 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 265 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = driver.getModel()->getInfos()->getReplicationLength();}
#line 1168 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 269 "Genesys++-parser.yy" // lalr1.cc:859
    { yylhs.value.as< obj_t > ().valor = yystack_[1].value.as< obj_t > ().valor; }
#line 1174 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 277 "Genesys++-parser.yy" // lalr1.cc:859
    {
                                                                  driver.setResult(-1);
                                                                  if(driver.getThrowsException()){
                                                                    if(yystack_[0].value.as< obj_t > ().valor == 0){
                                                                      throw std::string("Parser error: Literal nao encontrado");
                                                                    }else if(yystack_[0].value.as< obj_t > ().valor == 1){
                                                                      throw std::string("Parser error: Caracter invalido encontrado");
                                                                    }
                                                                  }else{
                                                                    if(yystack_[0].value.as< obj_t > ().valor == 0){
                                                                      driver.setErrorMessage(std::string("Parser error: Literal nao encontrado"));
                                                                    }else if(yystack_[0].value.as< obj_t > ().valor == 1){
                                                                      driver.setErrorMessage(std::string("Parser error: Caracter invalido encontrado"));
                                                                    }
                                                                  }
                                                                }
#line 1195 "../Genesys++-parser.cpp" // lalr1.cc:859
    break;


#line 1199 "../Genesys++-parser.cpp" // lalr1.cc:859
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


  const signed char genesyspp_parser::yypact_ninf_ = -98;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short int
  genesyspp_parser::yypact_[] =
  {
     166,   -46,   -98,   216,   -98,   -98,   -98,   -98,   -98,   -98,
     -45,   -36,   -34,   -32,   -31,   -30,    -6,    -5,    -3,    -2,
      -1,     0,     1,    15,    16,    17,    18,   -98,   -98,    19,
      20,    21,    22,    23,    24,    25,    26,    28,     3,   266,
     266,   -98,    35,   -98,   911,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,    67,    77,    78,    79,
      81,    86,    93,    94,   266,   -98,    36,    46,   507,   -98,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,    27,   554,   561,   568,   309,   575,   582,
     629,   320,   328,   336,   344,   393,   401,   409,   417,   425,
     -48,    54,    55,    56,    58,    59,    60,    61,    63,   636,
     266,   266,   -98,   643,   -47,   -47,   -47,   -47,   917,   917,
     -42,   -42,   -98,   -98,   -47,   -47,   266,   -98,   -98,   -98,
     -98,   266,   -98,   -98,   -98,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   -98,   266,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   266,   654,   701,   -98,    85,   708,
     715,   722,   729,   776,   783,   790,   474,   482,   911,   490,
     803,   266,   266,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   266,   266,   266,   266,   838,   850,   857,   498,   911,
     911,     3,     3,   -98,   266,    57,   -98,    68,   -98,   864,
     266,   266,   -98,   911,   911
  };

  const unsigned char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    79,     0,     5,     6,     1,    17,    18,    12,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     4,     7,    15,     8,     9,    16,    32,
      33,    11,    13,    14,    39,    38,    40,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,    27,    29,    30,    31,    24,    25,
      19,    20,    22,    21,    26,    28,     0,    47,    50,    51,
      52,     0,    54,    53,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,     0,    70,    69,    73,    71,
      72,    66,    68,    67,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
      35,     0,     0,    48,    55,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      34,     0,     0,    63,     0,     0,    37,     0,    36,     0,
       0,     0,    64,    44,    45
  };

  const signed char
  genesyspp_parser::yypgoto_[] =
  {
     -98,   -98,   -98,   -39,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,    89,   -97,   -35,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98
  };

  const short int
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    43,    44,    45,    46,    47,    48,    49,    50,
      51,   215,   216,    52,    53,    54,    55,    56,    57,    58,
     120,     4
  };

  const short int
  genesyspp_parser::yytable_[] =
  {
      88,    89,   164,    87,    97,    98,    99,   100,    85,    10,
     165,    99,   100,    60,     5,    61,    59,    62,    63,    64,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    91,    92,    93,
      94,    95,    96,    65,    66,   129,    67,    68,    69,    70,
      71,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,   121,    84,    97,    98,
      99,   100,   101,   102,    90,   146,   122,   123,   124,   147,
     125,   175,   176,   130,   126,    91,    92,    93,    94,    95,
      96,   127,   128,   131,   166,   167,   168,   178,   169,   170,
     171,   172,   179,   173,   220,   218,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   221,   189,    86,     0,     0,
       0,     0,     0,     0,     0,   190,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,   193,     0,     0,
       0,     0,   205,   206,     0,     0,     0,     0,     0,     0,
       0,     0,   207,   208,   209,   210,    -2,     1,     0,    -2,
      -2,    -2,    -2,     0,     0,   219,   217,   217,     0,     0,
       0,   223,   224,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
       0,    -2,     0,     0,     2,    -2,     6,     0,    -2,     7,
       8,     9,    10,     0,     0,     0,    -2,     0,     0,    -2,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,    38,     0,     0,     0,    39,     0,     0,    40,     7,
       8,     9,    10,     0,     0,     0,    41,     0,     0,    42,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,    38,     0,     0,     0,    39,     0,     0,    40,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,    42,
      91,    92,    93,    94,    95,    96,     0,     0,    91,    92,
      93,    94,    95,    96,     0,     0,    91,    92,    93,    94,
      95,    96,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   151,     0,     0,
       0,    97,    98,    99,   100,   101,   102,     0,   155,    97,
      98,    99,   100,   101,   102,     0,   156,    97,    98,    99,
     100,   101,   102,     0,   157,    97,    98,    99,   100,   101,
     102,     0,   158,    91,    92,    93,    94,    95,    96,     0,
       0,    91,    92,    93,    94,    95,    96,     0,     0,    91,
      92,    93,    94,    95,    96,     0,     0,    91,    92,    93,
      94,    95,    96,     0,     0,    91,    92,    93,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
       0,   159,    97,    98,    99,   100,   101,   102,     0,   160,
      97,    98,    99,   100,   101,   102,     0,   161,    97,    98,
      99,   100,   101,   102,     0,   162,    97,    98,    99,   100,
     101,   102,     0,   163,    91,    92,    93,    94,    95,    96,
       0,     0,    91,    92,    93,    94,    95,    96,     0,     0,
      91,    92,    93,    94,    95,    96,     0,     0,    91,    92,
      93,    94,    95,    96,     0,     0,     0,    91,    92,    93,
      94,    95,    96,     0,     0,    97,    98,    99,   100,   101,
     102,     0,   201,    97,    98,    99,   100,   101,   102,     0,
     202,    97,    98,    99,   100,   101,   102,     0,   203,    97,
      98,    99,   100,   101,   102,     0,   214,   132,    97,    98,
      99,   100,   101,   102,    91,    92,    93,    94,    95,    96,
       0,    91,    92,    93,    94,    95,    96,     0,    91,    92,
      93,    94,    95,    96,     0,    91,    92,    93,    94,    95,
      96,     0,    91,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,   148,    97,    98,    99,   100,   101,
     102,   149,    97,    98,    99,   100,   101,   102,   150,    97,
      98,    99,   100,   101,   102,   152,    97,    98,    99,   100,
     101,   102,   153,    97,    98,    99,   100,   101,   102,    91,
      92,    93,    94,    95,    96,     0,    91,    92,    93,    94,
      95,    96,     0,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
      97,    98,    99,   100,   101,   102,   174,    97,    98,    99,
     100,   101,   102,   177,    97,    98,    99,   100,   101,   102,
     191,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,    91,    92,    93,    94,    95,    96,     0,    91,    92,
      93,    94,    95,    96,     0,    91,    92,    93,    94,    95,
      96,     0,    91,    92,    93,    94,    95,    96,     0,    91,
      92,    93,    94,    95,    96,     0,     0,   192,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   194,    97,
      98,    99,   100,   101,   102,   195,    97,    98,    99,   100,
     101,   102,   196,    97,    98,    99,   100,   101,   102,   197,
      97,    98,    99,   100,   101,   102,    91,    92,    93,    94,
      95,    96,     0,    91,    92,    93,    94,    95,    96,     0,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,     0,   198,    97,    98,    99,
     100,   101,   102,   199,    97,    98,    99,   100,   101,   102,
     200,    97,    98,    99,   100,   101,   102,   204,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      91,    92,    93,    94,    95,    96,     0,    91,    92,    93,
      94,    95,    96,     0,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,   211,     0,     0,     0,    97,
      98,    99,   100,   101,   102,     0,     0,   212,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   213,    97,    98,
      99,   100,   101,   102,   222,    97,    98,    99,   100,   101,
     102,    91,    92,    93,    94,    95,    96,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,    97,    98,
      99,   100,   101,   102
  };

  const short int
  genesyspp_parser::yycheck_[] =
  {
      39,    40,    50,    38,    51,    52,    53,    54,     5,     6,
      58,    53,    54,    49,    60,    49,    61,    49,    49,    49,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    10,    11,    12,
      13,    14,    15,    49,    49,    84,    49,    49,    49,    49,
      49,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,     9,    49,    51,    52,
      53,    54,    55,    56,    49,    58,     9,     9,     9,    62,
       9,   130,   131,    57,     8,    10,    11,    12,    13,    14,
      15,     8,     8,    57,    50,    50,    50,   146,    50,    50,
      50,    50,   151,    50,    57,   212,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    57,   165,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,   202,   203,   204,     0,     1,    -1,     3,
       4,     5,     6,    -1,    -1,   214,   211,   212,    -1,    -1,
      -1,   220,   221,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    -1,    -1,    48,    49,     0,    -1,    52,     3,
       4,     5,     6,    -1,    -1,    -1,    60,    -1,    -1,    63,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,     3,
       4,     5,     6,    -1,    -1,    -1,    60,    -1,    -1,    63,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    63,
      10,    11,    12,    13,    14,    15,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    10,    11,    12,    13,
      14,    15,    -1,    -1,    10,    11,    12,    13,    14,    15,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    -1,    58,    51,
      52,    53,    54,    55,    56,    -1,    58,    51,    52,    53,
      54,    55,    56,    -1,    58,    51,    52,    53,    54,    55,
      56,    -1,    58,    10,    11,    12,    13,    14,    15,    -1,
      -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      -1,    58,    51,    52,    53,    54,    55,    56,    -1,    58,
      51,    52,    53,    54,    55,    56,    -1,    58,    51,    52,
      53,    54,    55,    56,    -1,    58,    51,    52,    53,    54,
      55,    56,    -1,    58,    10,    11,    12,    13,    14,    15,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    51,    52,    53,    54,    55,
      56,    -1,    58,    51,    52,    53,    54,    55,    56,    -1,
      58,    51,    52,    53,    54,    55,    56,    -1,    58,    51,
      52,    53,    54,    55,    56,    -1,    58,    50,    51,    52,
      53,    54,    55,    56,    10,    11,    12,    13,    14,    15,
      -1,    10,    11,    12,    13,    14,    15,    -1,    10,    11,
      12,    13,    14,    15,    -1,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    50,    51,    52,    53,    54,    55,    56,    50,    51,
      52,    53,    54,    55,    56,    50,    51,    52,    53,    54,
      55,    56,    50,    51,    52,    53,    54,    55,    56,    10,
      11,    12,    13,    14,    15,    -1,    10,    11,    12,    13,
      14,    15,    -1,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    50,    51,    52,    53,
      54,    55,    56,    50,    51,    52,    53,    54,    55,    56,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    10,    11,    12,    13,    14,    15,    -1,    10,    11,
      12,    13,    14,    15,    -1,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    50,    51,
      52,    53,    54,    55,    56,    50,    51,    52,    53,    54,
      55,    56,    50,    51,    52,    53,    54,    55,    56,    50,
      51,    52,    53,    54,    55,    56,    10,    11,    12,    13,
      14,    15,    -1,    10,    11,    12,    13,    14,    15,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    50,    51,    52,    53,    54,    55,    56,
      50,    51,    52,    53,    54,    55,    56,    44,    10,    11,
      12,    13,    14,    15,    51,    52,    53,    54,    55,    56,
      10,    11,    12,    13,    14,    15,    -1,    10,    11,    12,
      13,    14,    15,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    50,    51,    52,
      53,    54,    55,    56,    50,    51,    52,    53,    54,    55,
      56,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    51,    52,
      53,    54,    55,    56
  };

  const unsigned char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    48,    65,    85,    60,     0,     3,     4,     5,
       6,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    45,    49,
      52,    60,    63,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    77,    78,    79,    80,    81,    82,    83,    61,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,     5,    75,    77,    67,    67,
      49,    10,    11,    12,    13,    14,    15,    51,    52,    53,
      54,    55,    56,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      84,     9,     9,     9,     9,     9,     8,     8,     8,    67,
      57,    57,    50,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    58,    62,    50,    50,
      50,    58,    50,    50,    50,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    50,    58,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    67,    67,    50,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    46,    46,    62,    50,    50,    50,    50,    50,    50,
      50,    58,    58,    58,    44,    67,    67,    67,    67,    67,
      67,    47,    47,    50,    58,    75,    76,    77,    76,    67,
      57,    57,    50,    67,    67
  };

  const unsigned char
  genesyspp_parser::yyr1_[] =
  {
       0,    64,    65,    65,    65,    65,    65,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    74,    74,    75,    76,    76,    77,    77,    77,    78,
      79,    79,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    84,    84,    85
  };

  const unsigned char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     7,     5,     8,     8,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     4,     6,     1,
       4,     4,     4,     4,     4,     6,     4,     6,     6,     6,
       6,     6,     6,     8,    10,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     1,     4,     5,     3,     1
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
  "ILLEGAL", "\"(\"", "\")\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"<\"",
  "\">\"", "\"=\"", "\",\"", "NEG", "'\\n'", "\"[\"", "\"]\"", "\"USER\"",
  "$accept", "input", "programa", "expressao", "numero", "aritmetica",
  "relacional", "comando", "comandoIF", "comandoFOR", "funcao", "atributo",
  "atribuicao", "variavel", "formula", "funcaoTrig", "funcaoArit",
  "funcaoProb", "funcaoStrc", "funcaoUser", "listaparm", "illegal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  genesyspp_parser::yyrline_[] =
  {
       0,   131,   131,   132,   133,   134,   135,   138,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   152,   153,   156,
     157,   158,   159,   160,   163,   164,   165,   166,   167,   168,
     169,   170,   173,   174,   177,   178,   181,   182,   185,   186,
     187,   188,   189,   194,   198,   199,   202,   203,   204,   208,
     211,   212,   215,   216,   217,   218,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   233,   234,   235,   242,
     243,   244,   245,   263,   264,   265,   269,   273,   274,   277
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
#line 1857 "../Genesys++-parser.cpp" // lalr1.cc:1167
#line 295 "Genesys++-parser.yy" // lalr1.cc:1168

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
