#include <cstdio>

const int pr[10] = { 2, 3, 5, 7,11,13,17,19,23,29};
const int cnt[31][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{ 4, 2, 1, 0, 0, 0, 0, 0, 0, 0},
	{ 4, 2, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 7, 2, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 7, 4, 1, 1, 0, 0, 0, 0, 0, 0},
	{ 8, 4, 2, 1, 0, 0, 0, 0, 0, 0},
	{ 8, 4, 2, 1, 1, 0, 0, 0, 0, 0},
	{10, 5, 2, 1, 1, 0, 0, 0, 0, 0},
	{10, 5, 2, 1, 1, 1, 0, 0, 0, 0},
	{11, 5, 2, 2, 1, 1, 0, 0, 0, 0},
	{11, 6, 3, 2, 1, 1, 0, 0, 0, 0},
	{15, 6, 3, 2, 1, 1, 0, 0, 0, 0},
	{15, 6, 3, 2, 1, 1, 1, 0, 0, 0},
	{16, 8, 3, 2, 1, 1, 1, 0, 0, 0},
	{16, 8, 3, 2, 1, 1, 1, 1, 0, 0},
	{18, 8, 4, 2, 1, 1, 1, 1, 0, 0},
	{18, 9, 4, 3, 1, 1, 1, 1, 0, 0},
	{19, 9, 4, 3, 2, 1, 1, 1, 0, 0},
	{19, 9, 4, 3, 2, 1, 1, 1, 1, 0},
	{22,10, 4, 3, 2, 1, 1, 1, 1, 0},
	{22,10, 6, 3, 2, 1, 1, 1, 1, 0},
	{23,10, 6, 3, 2, 2, 1, 1, 1, 0},
	{23,13, 6, 3, 2, 2, 1, 1, 1, 0},
	{25,13, 6, 4, 2, 2, 1, 1, 1, 0},
	{25,13, 6, 4, 2, 2, 1, 1, 1, 1},
	{26,14, 7, 4, 2, 2, 1, 1, 1, 1}
};

int main() {
	int test, cs, n, k, i, temp;
	long long int ret;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		if(k == 0) printf("Case %d: 1\n", cs);
		else if(k == 1) printf("Case %d: %d\n", cs, n*n);
		else if(k > n) printf("Case %d: 0\n", cs);
		else {
			for(i = 0, ret = 1; i < 10; i++) {
				temp = (cnt[n][i]<<1) - cnt[k][i] - (cnt[n-k][i]<<1);
				while(temp--) ret *= pr[i];
			}
			printf("Case %d: %lld\n", cs, ret);
		}
	}
	return 0;
}
