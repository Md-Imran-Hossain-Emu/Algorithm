#include <bits/stdc++.h>

using namespace std;

int main()
{
    char x[100], y[100], LCS[100];
    int xlen, ylen, rows, cols, L[100][100], i, r, c;

    cout<<"Enter the first string:";
    cin>>x;
    cout<<"Enter the second string:";
    cin>>y;

    xlen = strlen(x);
    ylen = strlen(y);

    rows = xlen + 1;
    cols = ylen + 1;

    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            L[0][c] = 0;
            L[r][0] = 0;
            if(x[r-1] == y[c-1]){
                L[r][c] = L[r-1][c-1] + 1;
            }
            else{
                L[r][c] = max(L[r-1][c], L[r][c-1]);
            }
        }
    }

    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
           cout<<L[r][c]<<" ";
        }
        cout<<endl;
    }

    cout<<"Length of the Longest common subsequence is: "<<L[xlen][ylen]<<endl;

    r = xlen;
    c = ylen;
    i = L[r][c];

    while(r>0 && c>0){
        if(x[r-1] == y[c-1]){
            LCS[i-1] = x[r-1];
            i--;
            r--;
            c--;
        }
        else if(L[r-1][c] > L[r][c-1]){
            r--;
        }
        else{
            c--;
        }
    }
    cout<<"The longest common subsequence is: "<<LCS;


    return 0;
}
