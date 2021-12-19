/*

CODECHIEF

FOR DIVISION 3

Q1. Two Rooks 
Problem Code: TWOROOKS

Statement:
You are given a standard 8×8 chessboard which has exactly 2 rooks on it and no other pieces. 
The rows are numbered 1 to 8 from bottom to top, and the columns are numbered 1 to 8 from left 
to right. The cell at the intersection of the i-th column and j-th row is denoted (i,j).

Given the initial positions of the rooks in the form of coordinates (X1,Y1) and (X2,Y2), 
you need to tell whether the 2 rooks currently attack each other or not. Assume, each square 
can contain at most one piece.

Rooks can only travel in straight lines along the row or column they are placed at, and can't 
jump over other pieces. For a more detailed explanation of the moves of rooks, along with images, 
please click here.

Input Format
The first line contains T - the number of test cases. Then the test cases follow.
The first line of each test case contain four space-separated integers each X1,Y1,X2,Y2 - (X1,Y1) 
is the position of the first rook and (X2,Y2) is the position of the second rook.

Output Format
For each test case, output on a single line YES (without quotes) if the rooks attack each other, 
and NO otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings YeS, 
YEs, yes and yeS will all be treated as identical).

Constraints
1≤T≤5000
1≤X1,X2,Y1,Y2≤8
(X1,Y1)≠(X2,Y2)

Sample Input 1 
3
1 2 5 2
1 2 1 5
1 1 8 8

Sample Output 1 
YES
YES
NO

Explanation
Test case 1: The two rooks can attack each other by moving along the second column.
Test case 2: The two rooks can attack each other by moving along the first row.
Test case 3: No matter how a rook moves it cannot reach the second rook in one move. 
Hence, they do not attack each other.

*/

//code
#include<iostream>
using namespace std;

int main(){
    
    int t; cin>>t;
    while(t--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        
        if(x1==x2 || y1 == y2){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}


/*

CODECHIEF

FOR DIVISION 3

Problem: Friends Meetup 

Problem Code: FRIMEET

Statement:
Chef and his friend is standing on the X-axis at the points X1 and X2 respectively.
Chef moves one step forward each second (that is he moves to X1+1 after the 1st second, 
X1+2 after the 2nd second, and so on), whereas his friend moves 2 steps forward each 
second (that is he moves to X2+2 after the 1st second, X2+4 after the 2nd second, and so on).

You need to determine if Chef will be able to meet his friend or not. You can assume that Chef 
and his friend both keep on moving for a long indefinite amount of time and also that they 
move simultaneously.

Input Format
The first line contains T - the number of test cases. Then the test cases follow.
The first line of each test case contain two space-separated integers X1 and X2 - the position of 
Chef and his friend at the start respectively.

Output Format
For each test case, output on a single line YES (without quotes) if Chef can meet his friend, 
and NO otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings YeS, 
YEs, yes and yeS will all be treated as identical).

Constraints
1≤T≤105
1≤X1,X2≤109

Sample Input 1 
3
1 1
1 7
7 1

Sample Output 1 
YES
NO
YES

Explanation
Test case 1: Chef and his friend are on the same coordinate initially. Hence, they have already met.
Test case 2: No matter for how long they move Chef and his friend will never meet.
Test case 3: After 6 seconds, Chef and his friend both will be at X=13.

*/

//code
#include<iostream>
using namespace std;

int main(){
    
    int t; cin>>t;
    while(t--){
        
        int x1, x2;
        cin>>x1>>x2;
        
        if(x1 == x2){
            cout<<"Yes"<<endl;
        }
        
        else if(x2 > x1){
            cout<<"No"<<endl;
        }
        
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}