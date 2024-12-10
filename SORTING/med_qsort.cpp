#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void t(const std::vector<int>& a) {
    for (int x : a) std::cout << x << " ";
    std::cout << std::endl;
}

void s(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int m(std::vector<int>& a, int l, int h) {
    int mid = (l + h) / 2;
    if (a[l] > a[mid]) s(a[l], a[mid]);
    if (a[l] > a[h]) s(a[l], a[h]);
    if (a[mid] > a[h]) s(a[mid], a[h]);
    s(a[mid], a[h]);
    return a[h];
}

int p(std::vector<int>& a, int l, int h) {
    int pivot = m(a, l, h);
    int i = l - 1;
    for (int j = l; j < h; ++j) {
        if (a[j] <= pivot) s(a[++i], a[j]);
    }
    s(a[i + 1], a[h]);
    return i + 1;
}

void q(std::vector<int>& a, int l, int h) {
    if (l < h) {
        int pi = p(a, l, h);
        q(a, l, pi - 1);
        q(a, pi + 1, h);
    }
}

int main() {
    std::srand(std::time(0));
    std::vector<int> a(100);
    for (int& x : a) x = std::rand() % 900 + 100;
    std::cout << "Original array:" << std::endl;
    t(a);
    q(a, 0, a.size() - 1);
    std::cout << "Sorted array:" << std::endl;
    t(a);
    return 0;
}
