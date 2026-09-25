# 41243215

作業一 Problem 1

## 解題說明

本題要求實作 Ackermann 函數
寫兩種計算同一個函數的方法：
1. 遞迴函式：按照圖片中的三條規則：m = 0 時回傳 n + 1；n = 0 時算 A(m−1, 1)；其他情況算 A(m−1, A(m, n−1))。
2. 非遞迴演算法：不讓函式自己呼叫自己，利用stack來模擬遞迴的計算過程。

### 解題策略

宣告一個接收兩個整數、回傳整數的函式：int ackermann(int m, int n)。接著使用if/else判斷下列三個情況：
1. m == 0：答案可以直接算出來。這是停止遞迴的條件之一。
2. n == 0：需要呼叫一次 ackermann，但傳入的參數會改變。
3. 其他情況：呼叫兩層。先算 ackermann(m, n - 1)，再把它的結果當成另一個 ackermann 的參數

## 程式實作

以下為主要程式碼：

```cpp
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
```

## 效能分析

1. 時間複雜度：當 $m \ge 2$ 固定時，遞迴版與非遞迴版皆為 $\Theta(A(m,n)^2)$。
2. 空間複雜度：當 $m \ge 1$ 固定時，遞迴版與非遞迴版皆為 $\Theta(A(m,n))$。

其中，$A(m,n)$ 表示 Ackermann 函數的回傳值。

## 測試與驗證

### 測試案例

| 測試案例 | 輸入參數 $(m,n)$ | 預期輸出 | 遞迴實際輸出 | 非遞迴實際輸出 |
| --- | --- | ---: | ---: | ---: |
| 測試一 | $(0,0)$ | 1 | 1 | 1 |
| 測試二 | $(0,3)$ | 4 | 4 | 4 |
| 測試三 | $(1,1)$ | 3 | 3 | 3 |
| 測試四 | $(2,2)$ | 7 | 7 | 7 |
| 測試五 | $(3,1)$ | 13 | 13 | 13 |

### 編譯與執行指令

```powershell
g++ -std=c++17 -o hw1_problem1.exe hw1_problem1.cpp
.\hw1_problem1.exe
```

執行結果：

```text
3 :Recursive
3 :Iterative
```

### 結論

本題以遞迴及堆疊模擬兩種方式實作 Ackermann 函數。五組非負整數測試中，兩個版本的結果一致且符合預期。由於函數計算量成長很快，測試以小數值為主。
