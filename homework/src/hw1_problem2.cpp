#include <iostream>
#include <vector>
using namespace std;

void powerSet(const vector<char>& S, int index, vector<char>& current) {
    if (index == S.size()){                    // 1. 停止條件：所有元素都處理完了
        cout << "{";
        for(size_t i = 0;i < current.size();i++){
            if(i>0) cout << ",";
            cout << current[i];
        }
        cout << "}" << '\n';
        return;
    }

    powerSet(S, index + 1, current);           // 2. 不選 S[index]：往下一個元素走

    current.push_back(S[index]);               // 3. 選 S[index]：先放進 current，再往下一個元素走
    powerSet(S, index + 1, current);

    current.pop_back();                        // 4. 把剛放進去的元素移除，還原 current
}

int main() {
    vector<char> S = {'a', 'b'};
    vector<char> current;

    powerSet(S, 0, current);
}
