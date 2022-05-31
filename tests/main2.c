int foo(int prev, int i) {
	return prev + i;
}
int main() {
	int a = 0;
	for (int i = 0; i < 10; ++i) {
		a = foo(a, i);
	}
	return a;
}
