#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>

/*
 * merge_range
 * -----------
 * merges two sorted parts of the array:
 *   a[left..mid] and a[mid+1..right]
 * uses tmp as scratch space, then copies back into a.
 */
static void merge_range(std::vector<int>& a,
                        std::vector<int>& tmp,
                        int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else              tmp[k++] = a[j++];
    }

    while (i <= mid)   tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];

    for (int t = left; t <= right; ++t)
        a[t] = tmp[t];
}

/*
 * mergesort
 * ---------
 * sorts a[left..right] using merge sort.
 * base case: 0 or 1 element.
 */
static void mergesort(std::vector<int>& a,
                      std::vector<int>& tmp,
                      int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergesort(a, tmp, left, mid);
    mergesort(a, tmp, mid + 1, right);
    merge_range(a, tmp, left, mid, right);
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <n>\n";
        return 1;
    }

    long long n_ll = std::atoll(argv[1]);
    if (n_ll <= 0) {
        std::cerr << "n must be > 0\n";
        return 1;
    }

    int n = (int)n_ll; 
    std::vector<int> data(n);

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int i = 0; i < n; i++)
        data[i] = dist(rng);

    std::vector<int> tmp(n);

    auto t0 = std::chrono::steady_clock::now();
    mergesort(data, tmp, 0, n - 1);
    auto t1 = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed = t1 - t0;

    std::cout << n << "," << elapsed.count() << "\n";
    return 0;
}
