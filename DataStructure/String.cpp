#include <iostream>
#include <cstring>

using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int Status;
typedef char String[MAXSIZE+1];

Status StrAssign(String s, char* chars){
    if (strlen(chars)>MAXSIZE)
        return ERROR;
    else{
        s[0]=strlen(chars);
        for (int i=1; i<=s[0]; i++)
            s[i]=*(chars+i-1);
        return OK;
    }
}

int Index1(String s, String subs, int pos){
    int i=pos;
    int j=1;
    while (i<=s[0] && j<=subs[0]){
        if (s[i]==subs[j]){
            i++;
            j++;
        }
        else{
            i=i-j+2;
            j=1;
        }
    }
    if (j>subs[0])
        return i-subs[0];
    else
        return 0;
}

void StrPrint(String s){
    for (int i=1; i<=s[0]; i++)
        cout << s[i];
    cout << endl;
}

int main(){
    String s1,s2;
    StrAssign(s1, "abcd1234efgh1234");
    StrAssign(s2, "1234");

    cout << "s1: ";
    StrPrint(s1);
    cout <<"s2: ";
    StrPrint(s2);

    int i=Index1(s1, s2, 6);
    cout << i;

    return 0;
}