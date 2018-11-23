#include<iostream>

#include"dict.h"

#include<string>

using namespace std;



int main() {

	size_t N = hash<string>{}("dd");
	cout << N << endl;
	NativeDict<int> a;
	a.put("a", 21);
	a.put("b", 22);
	a.put("c", 23);
	a.put("d", 24);

	a.get("a") = 12;
	a.put("a", 21);
	cout << a.get("a")<< endl;
	


	return 0;
}