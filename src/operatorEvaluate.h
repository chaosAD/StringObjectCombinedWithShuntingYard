#ifndef __OPERATOREVALUATE_H__
#define __OPERATOREVALUATE_H__

#include "Stack.h"
#include "Evaluate.h"
#include "Token.h"

//Function declaration
void operatorEvaluate(Stack *numberStack , Operator *opeToken);
void evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);
void operatorPrefixEvaluate(Stack *numberStack , Operator *opeToken1);
void evaluatePrefixOperatorOnStack(Stack *numberStack,Stack *operatorStack);
void executeInfixOperator(Stack *numberStack , Operator *opeToken);
#endif //__OPERATOREVALUATE_H__