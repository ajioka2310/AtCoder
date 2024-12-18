#include<bits/stdc++.h>
using namespace std;

char conv(char c){
  if (0<=c-'a'&&c-'a'<=25){
    return 'A'+(c-'a');
  }
  else {
    return 'a'+(c-'A');
  }
}

int main(){
  char a = 'a';
  char A = 'A';
  char z = 'z';
  char Z = 'Z';

  cout << a-'a' << endl;
  cout << A-'a' << endl;
  cout << z-'a' << endl;
  cout << Z-'a' << endl;
  char c = 'c';
  char C = 'C';

  cout << conv(c) << endl;
  cout << conv(C) << endl;

}
