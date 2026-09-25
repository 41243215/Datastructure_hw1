#include<iostream>
#include<stack>

using namespace std;

int ackermannRecursive(int m, int n){
    if(m == 0){
        return n+1;
    }
    else if(n == 0){
        return ackermannRecursive(m-1, 1);
    }
    else{
        return ackermannRecursive(m-1, ackermannRecursive(m, n-1));
    }
}

int ackermannIterative(int m,int n){
    stack<int> pending;
    pending.push(m);

    while(!pending.empty()){
        int currentM = pending.top();
        pending.pop();

        if(currentM == 0) n+=1;
        else if(n==0){
            pending.push(currentM - 1);
            n = 1;
        }else{
            pending.push(currentM - 1);
            pending.push(currentM);
            n-=1;
        }
    }
    return n;
}

int main(){
    cout << ackermannRecursive(1,1) << " :Recursive\n";
    cout << ackermannIterative(1,1) << " :Iterative";    
}
