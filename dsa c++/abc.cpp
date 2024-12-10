#include<iostream>
#include<stack>

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

int main(){

string infix;
string postfix;
stack<char>s;
cin>>infix;

int i=0;

while(i<infix.size())
{
    char symbol;
    symbol=infix[i];
    i++;
    if(symbol>='a'&& symbol<='z'){
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

return 0;
}