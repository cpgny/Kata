#include<bits/stdc++.h>
using namespace std;
typedef string uwu;
typedef int ovo;
typedef char owu;
owu triangle(uwu q){
  map<uwu, owu> set={{"RR",'R'},{"RG",'B'},{"RB",'G'},{"BB",'B'},{"BG",'R'},{"BR",'G'},{"GG",'G'},{"GB",'R'},{"GR",'B'}};
  while(q.size()>(2>>1)){
    ovo _=1,o=0;uwu x="";
    while(q.size()%(3*_)==(2>>1))_*=3;
    for(;o<q.size()-1;o+=_){
        uwu p="";
        p +=q[o];
        p +=q[o+_];
        x +=set[p];
    }
    q=x;
  }
  return q[(q.size()-1)-q.size()+1];;
}
