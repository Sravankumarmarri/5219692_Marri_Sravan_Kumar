char* balancedSums(int arr_c, int* arr) {
    static char res[4];
    long long total_sum = 0, left_sum = 0;


    for (int i = 0; i < arr_c; i++) {
        total_sum += arr[i];
    }

    for (int i = 0; i < arr_c; i++) {
        long long right_sum = total_sum - left_sum - arr[i];
        if (left_sum == right_sum) {
            strcpy(res, "YES");
            return res;
        }
        left_sum += arr[i];
    }

    strcpy(res, "NO");
    return res;
}
