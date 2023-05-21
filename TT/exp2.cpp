// Two lists are to be maintained containing integer values. The values are not stored in continuous memory locations. 
// Let one list be 7->1->5 and another list be 5->9->2. 
// Create a third list such that the third list contains the sum of the first two list i.e 517+295 =812  and save it as 2->1>8.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print(list <int> l){
    list <int> :: iterator it;
    for(it = l.begin(); it != l.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    list <int> l1, l2, l3;
    l1.push_back(7);
    l1.push_back(1);
    l1.push_back(5);
    l2.push_back(5);
    l2.push_back(9);
    l2.push_back(2);

    int suml1 = 0, suml2 = 0, temp1 = 1, temp2 = 1;

    for( auto a : l1){
        suml1 += a*temp1;
        temp1 *= 10;
    }
    for( auto a : l2){
        suml2 += a*temp2;
        temp2 *= 10;
    }

    int sum3 = suml1 + suml2;
    while(sum3 != 0){
        int temp = sum3 % 10;
        l3.push_back(temp);
        sum3 /= 10;
    }

    print(l3);

    return 0;
}
