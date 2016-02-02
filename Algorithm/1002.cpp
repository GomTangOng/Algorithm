#include <iostream>
#include <cmath>
using namespace std;

inline int GetDistance(int x1, int y1, int x2, int y2)
{
	return ((x1 - x2) * (x1 - x2) + (y2 - y1) * (y2 - y1));
}


int solution(int x1, int y1, int r1, int x2, int y2, int r2)
{
	int dist       = GetDistance(x1, y1, x2, y2);
	int radian_sum = r1 + r2;
	int radian_minus = abs(r1 - r2);
	if (x1 == x2 && y1 == y2)
	{
		if (r1 == r2) return -1;	// ������ ���̱⿡ ���Ѵ�
		else
		{
			return 0;
		}
	}

 
	if (dist > radian_sum * radian_sum)		// �� ���� ������ �ִ� ���
	{
		return 0;
	}
	else if (dist == radian_sum * radian_sum)	// ����
	{
		return 1;
	}
	else if (dist == radian_minus * radian_minus)  // ����
	{
		return 1;
	}
	else if (dist < radian_minus * radian_minus )	// ���ο��� �ȸ����� ���
	{
		return 0;
	}
	else if (dist < radian_sum * radian_sum)		// �� ���� �� ������ ����� ���
	{
		return 2;
	}
	
	return 2;
}

int main()
{
	int test_case{ 0 };
	int x1, y1, r1, x2, y2, r2;

	cin >> test_case;

	while (test_case--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		cout << solution(x1, y1, r1, x2, y2, r2) << endl;
	}

	return 0;
}