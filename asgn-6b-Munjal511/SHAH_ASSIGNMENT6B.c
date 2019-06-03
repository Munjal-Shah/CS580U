#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>

char postfix[] = "";

/*-----------STACK------------*/

struct Stack 
{ 
	int top;
	unsigned capacity; 
	float* array; 
}; 

struct Stack* createStack( unsigned capacity ) 
{ 
	struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
	
	if (!stack)
	{
	    return NULL;
	}
	
	stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = (float*) malloc(stack->capacity * sizeof(float));
	
	if (!stack->array)
	{
	    return NULL;
	}
	
	return stack;
}

int isFull(struct Stack *stack)
{
	return stack->top == stack->capacity-1;
}

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
}
 
int peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
}
 
float pop(struct Stack* stack) 
{ 
	if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
}
 
void push(struct Stack* stack, float item) 
{ 
	if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
}

int Prec(char ch) 
{ 
	switch (ch) 
	{ 
	case '+':
	
	case '-': 
		return 1; 

	case '*':
	
	case '/': 
		return 2; 

	case '^': 
		return 3; 
	} 
	return -1; 
}

int infixToPostfix(char* exp) 
{ 
	int i, k; 

	struct Stack* stack = createStack(strlen(exp)); 
	if(!stack)
	{
		return -1 ;
	}

	for (i = 0, k = -1; exp[i]; ++i) 
	{ 
		if (isdigit(exp[i])) 
		{
			exp[++k] = exp[i]; 
		}
		else if (exp[i] == '(')
		{			
			push(stack, exp[i]); 
		}
		else if (exp[i] == ')') 
		{ 
			while (!isEmpty(stack) && peek(stack) != '(') 
			{
				exp[++k] = pop(stack); 
			}
			pop(stack);
		} 
		else
		{ 
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack))) 
			{
				exp[++k] = pop(stack); 
			}
			push(stack, exp[i]); 
		} 
	} 

	while (!isEmpty(stack)) 
	{
		exp[++k] = pop(stack ); 
	}

	exp[++k] = '\0'; 
	
	for(int i=0; i<100; i++)
	{
		postfix[i] = exp[i];
	}
}

float evaluatePostfix(char *exp)
{
	struct Stack *stack = createStack(strlen(exp));
	int i;
	
	if(!stack)
	{
		return -1;
	}
	
	for(i=0; exp[i]; i++)
	{
		if(isdigit(exp[i]))
		{
			push(stack, exp[i] - '0');
		}
		else
		{
			float val1 = pop(stack);
			float val2 = pop(stack);
			
			switch(exp[i])
			{
				case '+':
					push(stack, val2 + val1);
					break;
				
				case '-':
					push(stack, val2 - val1);
					break;
					
				case '*':
					push(stack, val2 * val1);
					break;
					
				case '/':
					push(stack, val2 / val1);
					break;
			}
		}
	}
	return pop(stack);
}

void main()
{
    char infix[] = "((2+3)*4)*(5+2)*(3+4)";
    /*char infix[] = "";
    printf("Enter infix: ");
    scanf("%s", infix);*/
	printf("%s \n", infix);
	
	infixToPostfix(infix);
	printf("%s \n", postfix);
	
	float output = evaluatePostfix(postfix);
	printf("%f", output);
}