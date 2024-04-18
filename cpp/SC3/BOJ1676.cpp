#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

	int N;
	int mul5 = 0;	// 5의 배수
	int mul25 = 0;	// 25의 배수
	int mul125 = 0;	// 125의 배수

	cin >> N;

	mul5 = N / 5;
	mul25 = N / 25;
	mul125 = N / 125;

	cout << mul5 + mul25 + mul125 << '\n';

	return 0;
}