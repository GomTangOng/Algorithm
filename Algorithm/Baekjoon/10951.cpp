#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int a, b;
	while (cin >> a >> b)					// C++ Version
	{
		cout << a + b << endl;
	}

	//while (scanf("%d %d", &a, &b) != EOF)		// C Version
	//{

	//}

	// scanf("%s", s);	���� �Է� �ޱ�
	// scanf("%[^\n]\n", s);	/n �� ���ڿ� �ޱ�
	// getline(cin, s);
	// fgets()�� �� �ٲޱ��� �Է� �޴´�.

	return 0;
}