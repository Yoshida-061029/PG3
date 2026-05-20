#include <stdio.h>
#include <Windows.h>

int RecursivePay(int hour) {
	if (hour == 1) {
		return 100;
	}

	int prev = RecursivePay(hour - 1);

	return prev * 2 - 50;
}

int main() {

	system("chcp 65001 > nul");

	int hours = 10;
	int normalPay = 1072 * hours;
	int totalRecursive = 0;

	for (int i = 1; i <= hours; i++) {

		int pay = RecursivePay(i);

		totalRecursive += pay;

		printf("%d時間目 : %d円\n", i, pay);
	}
	printf("\n通常賃金 : %d円\n", normalPay);
	printf("再帰的賃金 : %d円\n", totalRecursive);

	if (totalRecursive > normalPay) {
		printf("再帰的賃金のほうが高い\n");
	}
	else {
		printf("通常賃金のほうが高い\n");
	}

	return 0;
}