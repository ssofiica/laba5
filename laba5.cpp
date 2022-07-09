#include <iostream>
#include "MyVector.h"
#include "MySet.h"
using namespace std;

int main()
{
	system("chcp 65001");
	MyVector<char*> v((char*)"Hello!");
	v.add_element((char*)"Привет!");
	v.add_element((char*)"Привет!");
	v.add_element((char*)"Привет!");
	v.add_element((char*)"Привет!");
	v.add_element((char*)"Привет!");
	cout << "Вектор v: " << v << endl;
	v.add_element((char*)"Привет!");
	v.add_element((char*)"Привет!");
	v.add_element((char*)"Привет!");
	cout << "Вектор v: " << v << endl;
	MyVector<char*> v1 = v;
	cout << "Вектор v1: " << v1 << endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v1.delete_element(0);
	cout << "Вектор v1: " << v1 << endl;
	MySet<char*> s((char*)"Yes"), s1, s2;
	s.add_element((char*)"Привет!");
	s.add_element((char*)"No");
	cout << "Множество s: " << s << endl;
	char str[] = "Hello!";
	s.add_element(str);
	s1.add_element((char*)"Cat");
	s1.add_element((char*)"No");
	s1.add_element((char*)"Привет!");
	cout << "Множество s1: " << s1 << endl;
	s2 = s1 - s;
	cout << "Множество s2=s1-s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = s - s1;
	cout << "Множество s2=s-s1: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = s1 + s;
	cout << "Множество s2=s1+s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = s1 * s;
	cout << "Множество s2=s1*s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	MySet<char*> s3 = s2;
	cout << "Множество s3=s2: " << s3 << endl;
	if (s3 == s2)
		cout << "Множество s3=s2\n";
	else
		cout << "Множество s3!=s2\n";
	if (s3 == s1)
		cout << "Множество s3=s1\n";
	else
		cout << "Множество s3!=s1\n";
	if (s1 == s3)
		cout << "Множество s1=s3\n";
	else
		cout << "Множество s1!=s3\n";
	return 0;
}