
void merge_sort_impl(std::vector<int>& a, std::vector<int>& temp,std::size_t left, std::size_t right) {
    if (right - left <= 1)
        return;

    const std::size_t mid = left + (right - left) / 2;

    merge_sort_impl(a, temp, left, mid);
    merge_sort_impl(a, temp, mid, right);

    std::size_t i = left, j = mid, k = left;

    // Scalanie dwóch posortowanych po³ówek.
    while (i < mid && j < right) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i < mid)
        temp[k++] = a[i++];

    while (j < right)
        temp[k++] = a[j++];

    for (std::size_t p = left; p < right; ++p)
        a[p] = temp[p];
}

void merge_sort(std::vector<int>& a) {
    std::vector<int> temp(a.size());
    merge_sort_impl(a, temp, 0, a.size());
}