#ifndef ErrorCode_H
#define ErrorCode_H

typedef enum{
	ERR_NO_ERROR,//0
	ERR_NUMBER_NOT_WELL_FORMED,//1
	ERR_ILLEGAL_ARGUMENT,//2
	ERR_EMPTY_ARGUMENT,//3
	ERR_NO_ARGUMENT,//4
	ERR_EMPTY_OPERATOR,//5
	ERR_INVALID_OPERATOR,//6
	ERR_UNKNOWN_INFIX_OPERATOR,//7
	ERR_UNKNOWN_PREFIX_OPERATOR,//8
	ERR_CANNOT_CONVERT_TO_PREFIX,//9
	ERR_INVALID_TOKEN_TYPE//10
} ErrorCode;


#endif //ErrorCode_H