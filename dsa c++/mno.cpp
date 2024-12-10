#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
bool prcd(char x, char y){
    if(x=='^'|| x=='*'||x=='/'||x=='%'){
        if(y=='^') return false;
        return true;
    }
    else{
        if(x=='+'||x=='-'){
            if(y=='+'||y=='-') return true;
            return false;
        }
    }
}


void infixToPostfix(string infix){
    
string postfix;
stack<char>s;
int i=0;

while(i<infix.size())
{
    char symbol;
    symbol=infix[i];
    i++;
    if((symbol>='a'&& symbol<='z')||(symbol>='0'&&symbol<='9')||(symbol>='A'&& symbol<='Z')){
        postfix+=symbol;
    }
    else{
        while(!s.empty()&& prcd(s.top(),symbol)){
            char x=s.top();
            s.pop();
            postfix+=x;
        }
        s.push(symbol);
    }
}

while(!s.empty()){
    char x=s.top();
    s.pop();
    postfix+=x;
}
cout<<postfix;


}



void infixToPrefix(string infix){
    
string prefix;
stack<char>s;
int i=0;

while(i<infix.size())
{
    char symbol;
    reverse(infix.begin(),infix.end());
    symbol=infix[i];
    i++;

    if((symbol>='a'&& symbol<='z')||(symbol>='0'&&symbol<='9')||(symbol>='A'&& symbol<='Z')){
        prefix+=symbol;
    }
    else{
        while(!s.empty() && !prcd(symbol,s.top())){
            char x=s.top();
            s.pop();
            prefix+=x;
        }
        s.push(symbol);
    }
}

while(!s.empty()){
    char x=s.top();
    s.pop();
    prefix+=x;
}

reverse(prefix.begin(),prefix.end());
cout<<prefix;

}



int main(){

string infix;
cin>>infix;

infixToPostfix(infix);
cout<<endl;
infixToPrefix(infix);

return 0;
}