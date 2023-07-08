    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    typedef struct Node_t node;
    typedef node* Node;
    struct Node_t{
    Node next;
    char data;
    };

    Node newNode(char data){
        Node new=(Node) calloc(1,sizeof(node));
        new->data=data;
        new->next=NULL;
        return new;
    }


    int isEmpty(Node stack){
        return stack==NULL;
    }

    void addFirst(Node* head_add,char data){
    if(*head_add==NULL)  {  *head_add=newNode(data);return; }
    Node next=*head_add;
    *head_add=newNode(data);
    (*(head_add))->next=next;



    }

    void deleteFirst(Node*head_add){

     Node temp=*head_add;
    (*head_add)=(*head_add)->next;
    free(temp);}


    void push(Node * stack_add,char data){
    addFirst(stack_add,data);


    }

    char pop(Node* stack_add){
    if(isEmpty(*stack_add)){ printf("underflow\n"); return '\0' ;}
    char last_elt=(*stack_add)->data;
    deleteFirst(stack_add);
    return last_elt;
    }

    char top(Node * stack_add){if(isEmpty(*stack_add)) return '\0';
    return (*stack_add)->data;
    }

    int PrecedenceDetector(char element){
    if(element=='\0') return -1;
    if(element=='+'||element=='-') return 1;
    if(element=='*'||element=='/') return 2;
    if(element=='^') return 3;
    if(element==')') return 0;


    }

    void generatePrefix(char*str){
    strrev(str);
    char a[100]=":";
    Node stack=NULL;
    int i=0;
    Node output=NULL;
    while(str[i]!='\0'){
    char temp=str[i];
     i++;

    if((temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z'))
    {push(&output,temp);}

    else if(temp==')') push(&stack,temp);else if(temp=='+'||temp=='-'||temp=='*'||temp=='/'|| temp=='^'){
    while(1){
    if(PrecedenceDetector(top(&stack))>PrecedenceDetector(temp)) push(&output,pop(&stack));
    else {push(&stack,temp);break;}
    }
    }
     else if(temp=='('){while(1){
        if(isEmpty(stack)) break;
        if(top(&stack)==')')
        { pop(&stack);break;}
        else push(&output,pop(&stack)) ;

    }
    }


    }
    while(!isEmpty(stack)){

    push(&output,pop(&stack));
    }

    while(!isEmpty(output)) printf("%c",pop(&output));}



    void main(){

    fflush(stdin);
    printf("enter your expression:\n");
    char a[100];

    gets(a);
    printf("The reversed expression is:%s\n",strrev(a));
    strrev(a);

    printf("The prefix code is: ");
    generatePrefix(a);


    }



