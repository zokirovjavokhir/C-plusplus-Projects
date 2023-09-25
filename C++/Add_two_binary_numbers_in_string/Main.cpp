#include <iostream>

using namespace std;


string add_bin_str(const string& x, const string& y) {
    int i = x.length() - 1;
    int j = y.length() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
		int sum = carry;

	if (i >= 0) {
	sum += x[i] - '0';
	i--;
}

	if (j >= 0) {
	sum += y[j] - '0';
	j--;
}

	result = char('0' + sum % 2) + result;
	carry = sum / 2;
}

	return result;
}

int main() {
    string x, y;

    cout << "";
    cin >> x;

    cout << "";
    cin >> y;

    string sum = add_bin_str(x, y);

    cout << "x=y=" << sum << endl;

    return 0;
}
