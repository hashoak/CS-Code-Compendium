#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct string_stack
{
    int size;
    char **a;
    int top;
};

struct string_stack* create_string_stack(int n)
{
    struct string_stack* s=malloc(sizeof(struct string_stack));
    s->size=n;
    s->a=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    {
        s->a[i]=(char*)malloc(100*sizeof(char));
    }
    s->top=-1;
    return s;
}

int isEmpty_string(struct string_stack *s)
{
    return s->top==-1;
}

int isFull_string(struct string_stack *s)
{
    return s->top==s->size-1;
}

void push_string(struct string_stack *s, char *x)
{
    if(isFull_string(s))
    {
        printf("Stack overflow.\n");
        return;
    }
    s->top++;
    strcpy(s->a[s->top],x);
    return;
}

char* pop_string(struct string_stack *s)
{
    if(isEmpty_string(s))
    {
        printf("Stack underflow.\n");
        return "~";
    }
    s->top--;
    return s->a[s->top+1];
}

char* peek_string(struct string_stack *s)
{
    if(isEmpty_string(s))
    {
        printf("No elements to peek.\n");
        return "~";
    }
    return s->a[s->top];
}

struct int_stack
{
    int size;
    int *a;
    int top;
};

struct int_stack* create_int_stack(int n)
{
    struct int_stack* s=malloc(sizeof(struct int_stack));
    s->size=n;
    s->a=(int*)malloc(n*sizeof(int));
    s->top=-1;
    return s;
}

int isEmpty_int(struct int_stack *s)
{
    return s->top==-1;
}

int isFull_int(struct int_stack *s)
{
    return s->top==s->size-1;
}

void push_int(struct int_stack *s,int x)
{
    if(isFull_int(s))
    {
        printf("Stack overflow.\n");
        return;
    }
    s->top++;
    s->a[s->top]=x;
    return;
}

int pop_int(struct int_stack *s)
{
    if(isEmpty_int(s))
    {
        printf("Stack underflow.\n");
        return -1;
    }
    s->top--;
    return s->a[s->top+1];
}

int peek_int(struct int_stack *s)
{
    if(isEmpty_int(s))
    {
        printf("No elements to peek.\n");
        return -1;
    }
    return s->a[s->top];
}

int prec(char *c)
{
    if(strcmp(c,"^")==0) return 3;
    if(strcmp(c,"*")==0 || strcmp(c,"/")==0) return 2;
    if(strcmp(c,"+")==0 || strcmp(c,"-")==0) return 1;
    else return 0;
}

char* conv_postfix(char *infix)
{
    char *postfix=(char*)malloc(300*sizeof(char));
    strcpy(postfix,"");
    struct string_stack *mem=create_string_stack(100);
    char *x=(char*)calloc(1,sizeof(char));
    for(int i=0;i<strlen(infix);i++)
    {
        strncpy(x,&infix[i],1);
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z')) strcat(postfix,x);
        else if(infix[i]=='(') push_string(mem,x);
        else if(infix[i]==')')
        {
            while(strcmp(peek_string(mem),"("))
            {
                strcat(postfix,pop_string(mem));
            }
            pop_string(mem);
        }
        else
        {
            while(!isEmpty_string(mem) && prec(x)<prec(peek_string(mem)))
            {
                strcat(postfix,pop_string(mem));
            }
            push_string(mem,x);
        }
    }
    while(!isEmpty_string(mem))
    {
        strcat(postfix,pop_string(mem));
    }
    return postfix;
}

char* reverse(char *s)
{
    int l=strlen(s);
    char t;
    for(int i=0;i<l/2;i++)
    {
        t=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=t;
    }
    for(int i=0;i<l;i++)
    {
        if(s[i]==')') s[i]='(';
        else if(s[i]=='(') s[i]=')';
    }
    return s;
}

char* conv_prefix(char *infix)
{
    char *prefix=(char*)malloc(300*sizeof(char));
    reverse(infix);
    strcpy(prefix,conv_postfix(infix));
    return reverse(prefix);
}

int eval_prefix(char *prefix)
{
    struct int_stack *mem=create_int_stack(100);
    int x,p,m,ans;
    for(int i=strlen(prefix)-1;i>=0;i--)
    {
        p=0,m=1;
        while(i>=0 && prefix[i]!=' ')
        {
            x=prefix[i]-'0';
            if(x>=0 && x<=9) p+=x*m,m*=10;
            i--;
        }
        if(p) push_int(mem,p);
        else
        {
            x+='0';
            if(x=='+') ans=pop_int(mem)+pop_int(mem);
            else if(x=='-') ans=pop_int(mem)-pop_int(mem);
            else if(x=='*') ans=pop_int(mem)*pop_int(mem);
            else if(x=='/') ans=pop_int(mem)/pop_int(mem);
            else if(x=='^') ans=pow(pop_int(mem),pop_int(mem));
            push_int(mem,ans);
        }
    }
    return pop_int(mem);
}

int eval_postfix(char *postfix)
{
    struct int_stack *mem=create_int_stack(100);
    int l=strlen(postfix),x,p,ans;
    for(int i=0;i<l;i++)
    {
        p=0;
        while(i<l && postfix[i]!=' ')
        {
            x=postfix[i]-'0';
            if(x>=0 && x<=9) p=p*10+x;
            i++;
        }
        if(p) push_int(mem,p);
        else
        {
            x+='0';
            if(x=='+') ans=pop_int(mem)+pop_int(mem);
            else if(x=='-') ans=pop_int(mem)-pop_int(mem);
            else if(x=='*') ans=pop_int(mem)*pop_int(mem);
            else if(x=='/') ans=pop_int(mem)/pop_int(mem);
            else if(x=='^') ans=pow(pop_int(mem),pop_int(mem));
            push_int(mem,ans);
        }
    }
    return pop_int(mem);
}

char* conv_pre_to_infix(char* prefix)       // Converts postfix expression to infix expression
{
    struct string_stack *mem=create_string_stack(100);
    char *p=(char*)malloc(100*sizeof(char));
    char *ans=(char*)malloc(100*sizeof(char));
    char *x=(char*)malloc(100*sizeof(char));
    char *y=(char*)malloc(100*sizeof(char));
    for(int i=strlen(prefix)-1;i>=0;i--)
    {
        strcpy(p,"");
        strcpy(x,"");
        while(i>=0 && prefix[i]!=' ')
        {
            strncpy(x,&prefix[i],1);
            if(x[0]>='0' && x[0]<='9') strcpy(p,strcat(x,p));
            i--;
        }
        if(strcmp(p,"")) push_string(mem,p);
        else
        {
            if(strcmp(x,"+")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"-")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"*")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"/")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"^")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            if(i<0) return ans;
            strcpy(y,"(");
            push_string(mem,strcat(y,strcat(ans,")")));
        }
    }
    return pop_string(mem);
}

char* conv_post_to_infix(char* postfix)     // Converts postfix expression to infix expression
{
    struct string_stack *mem=create_string_stack(100);
    char *p=(char*)malloc(100*sizeof(char));
    char *ans=(char*)malloc(100*sizeof(char));
    char *x=(char*)malloc(100*sizeof(char));
    char *y=(char*)malloc(100*sizeof(char));
    int l=strlen(postfix);
    for(int i=0;i<l;i++)
    {
        strcpy(p,"");
        strcpy(x,"");
        while(i<l && postfix[i]!=' ')
        {
            strncpy(x,&postfix[i],1);
            if(x[0]>='0' && x[0]<='9') strcat(p,x);
            i++;
        }
        if(strcmp(p,"")) push_string(mem,p);
        else
        {
            if(strcmp(x,"+")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"-")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"*")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"/")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            else if(strcmp(x,"^")==0) strcpy(ans,strcat(strcat(pop_string(mem),x),pop_string(mem)));
            if(i==l) return ans;
            strcpy(y,"(");
            push_string(mem,strcat(y,strcat(ans,")")));
        }
    }
    return pop_string(mem);
}

int main()
{
    char *infix=(char*)malloc(300*sizeof(char));
    printf("Arithmetic expression: ");
    scanf("%s",infix);
    // Polish-Prefix, Reverse polish-Postfix
    char *polish=(char*)malloc(300*sizeof(char));
    char *reverse_polish=(char*)malloc(300*sizeof(char));
    strcpy(reverse_polish,conv_postfix(infix));
    printf("Reverse Polish notation: %s\n",reverse_polish);
    strcpy(polish,conv_prefix(infix));
    printf("Polish notation: %s\n",polish);
    scanf("%c");
    
    int ans;
    printf("\nPolish notation with values: ");
    scanf("%[^\n]%*c",polish);
    strcpy(infix,conv_pre_to_infix(polish));                    // Innovativeness: Converts prefix to infix
    printf("In form of Arithmetic expression: %s\n",infix);     // and displays it before evaluation.
    ans=eval_prefix(polish);
    printf("Polish notation evaluation: %d\n",ans);

    printf("\nReverse Polish notation with values: ");
    scanf("%[^\n]%*c",reverse_polish);
    strcpy(infix,conv_post_to_infix(reverse_polish));           // Innovativeness: Converts postfix to infix
    printf("In form of Arithmetic expression: %s\n",infix);     // and displays it before evaluation.
    ans=eval_postfix(reverse_polish);
    printf("Reverse Polish notation evaluation: %d\n",ans);
    return 0;
}