#include <bits/stdc++.h>
using namespace std;
int cube[24], test_cube[24], ans;
bool test() {
	for (int i = 0; i < 24; ++i)
		if (test_cube[i] != test_cube[i - i % 4])
			return false;
	return true;
}
bool rotate1(int times) {
	for (int i = 0; i < times; ++i) {
		int temp = test_cube[12];
		test_cube[12] = test_cube[21];
		test_cube[21] = test_cube[20];
		test_cube[20] = test_cube[17];
		test_cube[17] = test_cube[16];
		test_cube[16] = test_cube[5];
		test_cube[5] = test_cube[4];
		test_cube[4] = test_cube[13];
		test_cube[13] = temp;
	}
	return test();
}
bool rotate2(int times) {
	for (int i = 0; i < times; ++i) {
		int temp = test_cube[2];
		test_cube[2] = test_cube[3];
		test_cube[3] = test_cube[16];
		test_cube[16] = test_cube[18];
		test_cube[18] = test_cube[9];
		test_cube[9] = test_cube[8];
		test_cube[8] = test_cube[15];
		test_cube[15] = test_cube[13];
		test_cube[13] = temp;
	}
	return test();
}
bool rotate3(int times) {
	for (int i = 0; i < times; ++i) {
		int temp = test_cube[6];
		test_cube[6] = test_cube[15];
		test_cube[15] = test_cube[14];
		test_cube[14] = test_cube[23];
		test_cube[23] = test_cube[22];
		test_cube[22] = test_cube[19];
		test_cube[19] = test_cube[18];
		test_cube[18] = test_cube[7];
		test_cube[7] = temp;
	}
	return test();
}
bool rotate4(int times) {
	for (int i = 0; i < times; ++i) {
		int temp = test_cube[4];
		test_cube[4] = test_cube[6];
		test_cube[6] = test_cube[8];
		test_cube[8] = test_cube[10];
		test_cube[10] = test_cube[23];
		test_cube[23] = test_cube[21];
		test_cube[21] = test_cube[0];
		test_cube[0] = test_cube[2];
		test_cube[2] = temp;
	}
	return test();
}
bool rotate5(int times) {
	for (int i = 0; i < times; ++i) {
		int temp = test_cube[7];
		test_cube[7] = test_cube[5];
		test_cube[5] = test_cube[3];
		test_cube[3] = test_cube[1];
		test_cube[1] = test_cube[20];
		test_cube[20] = test_cube[22];
		test_cube[22] = test_cube[11];
		test_cube[11] = test_cube[9];
		test_cube[9] = temp;
	}
	return test();
}
bool rotate6(int times) {
	for (int i = 0; i < times; ++i) {
		int temp = test_cube[1];
		test_cube[1] = test_cube[0];
		test_cube[0] = test_cube[12];
		test_cube[12] = test_cube[14];
		test_cube[14] = test_cube[10];
		test_cube[10] = test_cube[11];
		test_cube[11] = test_cube[19];
		test_cube[19] = test_cube[17];
		test_cube[17] = temp;
	}
	return test();
}
bool rotate(int dir) {
	bool rtn = false;
	for (int i = 0; i < 24; ++i) test_cube[i] = cube[i];
	if (dir == 0) {
		rtn = rotate1(2);
		rtn = rtn || rotate1(4);
	} else if (dir == 1) {
		rtn = rotate2(2);
		rtn = rtn || rotate2(4);
	} else if (dir == 2) {
		rtn = rotate3(2);
		rtn = rtn || rotate3(4);
	} else if (dir == 3) {
		rtn = rotate4(2);
		rtn = rtn || rotate4(4);
	} else if (dir == 4) {
		rtn = rotate5(2);
		rtn = rtn || rotate5(4);
	} else {
		rtn = rotate6(2);
		rtn = rtn || rotate6(4);
	}
	return rtn;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	for (int &i : cube) cin >> i;
	for (int i = 0; i < 6; ++i) ans = ans || rotate(i);
	cout << ans;
	return 0;
}
