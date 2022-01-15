/*
Two friends, Dragon and Sloth, are writing a computer science examination series. There are three subjects in this series: DSA, TOC, and DM. Each subject carries 100 marks.

You know the individual scores of both Dragon and Sloth in all 3 subjects. You have to determine who got a better rank.

The rank is decided as follows:

The person with a bigger total score gets a better rank
If the total scores are tied, the person who scored higher in DSA gets a better rank
If the total score and the DSA score are tied, the person who scored higher in TOC gets a better rank
If everything is tied, they get the same rank.
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int dsa1, toc1, dm1, dsa2, toc2, dm2;
        cin>>dsa1>>toc1>>dm1;
        cin>>dsa2>>toc2>>dm2;
        
        int tt1 = dsa1+toc1+dm1;
        int tt2 = dsa2+toc2+dm2;
        
        string d = "Dragon";
        string s = "Sloth";
        
        if(tt1 > tt2){
            cout<<d<<endl;
        }
        else if(tt2 > tt1){
            cout<<s<<endl;
        }
        else if(tt1 == tt2){
            if(dsa1>dsa2){
                cout<<d<<endl;
            }
            else if(dsa2>dsa1){
                cout<<s<<endl;
            }
            else if(dsa1 == dsa2){
                if(toc1>toc2){
                    cout<<d<<endl;
                }
                else if(toc2>toc1){
                    cout<<s<<endl;
                }
                else if(toc1 == toc2){
                    cout<<"tie"<<endl;
                }
            }
        }
    }
    return 0;
}
