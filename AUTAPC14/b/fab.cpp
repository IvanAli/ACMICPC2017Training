#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

struct Nodo{
  Nodo *next[62];
  bool end;
  Nodo(){
    memset(next,0,sizeof next);
  }
  int pos(char c){
    if(c >= 'a' && c <= 'z')
      return int(c-'a');
    if(c >= 'A' && c <= 'Z')
      return int(c-'A')+26;
    return int(c-'0')+52;
  }
  pair< Nodo*, bool > insert(int pos){
    if(next[pos] != NULL)
      return {next[pos],false};
    next[pos] = new Nodo;
    return {next[pos],true};
  }
};

Nodo *root = new Nodo, *tmp;
string str;

int main(){
  IO
  cin>>str;
  int len = str.size();
  int cont = 0;
  for(int i = 1; i <= len; ++i){
    for(int j = i+1; j <= len; ++j){
      tmp = root;
      bool fl = false;
      pair< Nodo*, bool > v;
      v = tmp->insert(tmp->pos(str[i-1]));
      tmp = v.fst;
      if(v.snd) fl = true;
      v = tmp->insert(tmp->pos(str[j-1]));
      tmp = v.fst;
      if(v.snd) fl = true;
      int ant = j, aux;
      for(int k = i+j; k <= len; k += aux){
        v = tmp->insert(tmp->pos(str[k-1]));
        tmp = v.fst;
        if(v.snd) fl = true;
        aux = ant;
        ant = k;
      }
      if(!tmp->end){
        fl = true; 
        tmp->end = true;
      }
      if(fl)
        ++cont;
    }
  }
  cout<<cont<<endl;
  return 0;
}