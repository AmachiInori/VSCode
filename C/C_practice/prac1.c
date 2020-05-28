#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE (65535)

int isHWString(char *origin);
int stackEdition(char *origin, int originPos, int originLen, char *stack);
void stackPush(char element, char *stack);
int stackPop(char element, char *stack);
void printResult(int resultValue);

int main(int argc, char const *argv[])
{
	char *originString = (char*)malloc(sizeof(char) * SIZE);
	scanf("%s\n", originString);

	printResult(isHWString(originString));
	getchar();
	getchar();
	return 0;
}

int isHWString(char *origin)
{
	int lengthOfString = strlen(origin);
	char *charStack = (char*)malloc(sizeof(char) * (lengthOfString / 2));
	for (int i = 0; i < lengthOfString / 2; ++i)
	{
		stackPush(origin[i], charStack);
	}
	return stackEdition(origin, (lengthOfString + 1) / 2, lengthOfString, charStack);
}

int stackEdition(char *origin, int originPos, int originLen, char *stack)
{
	if (originPos == originLen)
	{
		return 1;
	}
	if(stackPop(origin[originPos], stack))
	{
		stackEdition(origin, ++originPos, originLen, stack);
	}
	else
	{
		return 0;
	}
}

int stackPop(char element, char *stack)
{
	if (stack[strlen(stack) - 1] == element)
	{
		stack[strlen(stack) - 1] = 0;
		return 1;
	}
	else return 0;
}

void stackPush(char element, char *stack)
{
	stack[strlen(stack)] = element;
	return;
}

void printResult(int resultValue)
{
	if (resultValue) printf("Yes\n");
	else printf("No\n");
	return;
}