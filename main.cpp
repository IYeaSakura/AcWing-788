#include <iostream>

using namespace std;

const int N = 100010;
int tmp[N];

long long mergeSort(int* a, int l, int r) {
	if (l == r) return 0;
	int mid = l + r >> 1;
	long long res = mergeSort(a, l, mid) + mergeSort(a, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) tmp[k++] = a[i++];
		else {
			res += mid + 1 - i;
			tmp[k++] = a[j++];
		}
	}
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= r) tmp[k++] = a[j++];
	for (i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
	return res;
}

int main() {
	int n, a[N];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%lld\n", mergeSort(a, 0, n - 1));
	system("pause");
	return 0;
}
