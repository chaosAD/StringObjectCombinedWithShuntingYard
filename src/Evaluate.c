#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "StringObject.h"
#include "Token.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "Stack.h"
#include "stackForEvaluate.h"
#include "Text.h"
#include "Types.h"
#include "CharSet.h"
#include "ErrorCode.h"
#include "CException.h"


/*
	This function is to push tokens that tokenize from expression to stack 
	
	input  : expression 
	output : none
	return : token 
	Mocking function : 1)initTokenizer(); initialize expression into tokenizer
					   2)getToken();	  get tokens from the tokenizer
					   3)stackPush();   push tokens to number stack or operator stack
					  
*/	

//New evaluate

int evaluate(char *expression){
	String *tokenizer;
	Text *newText;
	Token *token;
	Token *ansToken;
	ErrorCode exception;
	int i;
	int counter=0;
	Number *result;
	
	Stack *numberStack;
	numberStack=createStack();
	Stack *operatorStack;
	operatorStack=createStack();
	
	newText=textNew(expression);
	tokenizer = stringNew(newText);
	
	
	if(expression ==NULL){	
		Throw(ERR_NO_ARGUMENT);
	}
	while((token=getToken(tokenizer))!=NULL){
		
		if(isNumber(token)){
			stackPush(token,numberStack);
		}
		
		else if(isOperator(token))
		{
			if(((Operator*)token)->info->id==OPENING_BRACKET_OP || ((Operator*)token)->info->id==CLOSING_BRACKET_OP)
			{
				tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}
			else
			{
				tryEvaluateOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}	
		}
		counter ++;
	}
	
	if(operatorStack == NULL)
	{
		 operatorPrefixEvaluate(numberStack , (Operator*)token);
	}
	else
	{
		evaluateAllOperatorOnStack(numberStack,operatorStack);
	}
	
	result=(Number*)stackPop(numberStack);
	destroyStack(numberStack);
	
	if(operatorStack !=NULL)
	{
		destroyStack(operatorStack);
	}
	
	printf("Loop needed for each expression to completely evaluate : %d \n",counter);
	return result->value;
	
}
