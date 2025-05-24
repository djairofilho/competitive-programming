#include <bits/stdc++.h>

using namespace std;
#define TAM 200100

const int D = 2;
const int MOD = 1e9+7;
struct Matriz{
    int mat[D][D];
    int * operator[](int i){
        return mat[i];
    }
    Matriz operator*(Matriz oth){
        Matriz res;
        for(int i=0;i<D;i++){
            for(int j=0;j<D;j++){
                res[i][j]=0;
                for(int k=0;k<D;k++){
                    res[i][j] = (res[i][j]+(1LL*mat[i][k]*oth[k][j])%MOD)%MOD;
                }
            }
        }
        return res;
    }
    Matriz exp(long long e){
        Matriz res;
        for(int i=0;i<D;i++){
            for(int j=0;j<D;j++){
                res[i][j]=(i==j);
            }
        }
        Matriz base = *this;
        while(e>0){
            if(e & 1LL)
                res = res*base;
            base = base*base;
            e = e>>1;
        }
        return res;
    }

};

/*
int expRap(int base, int exp,int mod){
    int res=1;
    while(exp>0){
        if(exp&1){
            res = res*base;
        }
        base = base*base;
        exp = exp>>1;
    }
    return res;
}
*/

int main(){
    Matriz A;
    A[0][0]=1;
    A[0][1]=1;
    A[1][0]=1;
    A[1][1]=0;
    /*
    for(int i=2;i<=10;i++){
        Matriz R = A.exp(i-1);
        int ans = R[0][0] + R[0][1];
        cout << ans << "\n";
    } 0 1 1 2 3 5 8 13 21
    */
    long long n;
    cin >> n;
    Matriz R = A.exp(n-1-1);
    int ans = R[0][0] + R[0][1];
    cout << ans << "\n";
}
