//------------------------------------------------------------------------------
/* GRAMMAR
 * =======
 * Calculation:
 *      Statement
 *      Help
 *      Print
 *      Quit
 *      Calculation Statement
 *
 * Statement:
 *      Declaration
 *      Expression
 *
 * Declaration:
 *      "let" Name "=" Expression
 *
 * Expression:
 *      Term
 *      Expression + Term
 *      Expression - Term
 *
 * Term:
 *      Secondary
 *      Term * Secondary
 *      Term / Secondary
 *      Term % Secondary
 *
 * Secondary:
 *      Primary
 *      Number !
 *
 * Primary:
 *      Number
 *      ( Expression )
 *      - Primary
 *      + Primary
 *      Variable value
 *
 * Number:
 *      floating-point-literal
 *
 * Input comes from cin through the Token_stream called ts
 */
//------------------------------------------------------------------------------
