void sort(int arr[10], int low, int high) {
    if (low >= high) {
        return;
    }
    int start = low;
    int end = high;
    int mid = start + (end - start) / 2;
    int pivot = arr[mid];
    
    while (start <= end) {
        while (arr[start] < pivot) {
            start += 1;
        }
        while (arr[end] > pivot) {
            end -= 1;
        }
        if (start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    
    sort(arr, low, end);
    sort(arr, start, high);
}

int main () {
    int n, i, arr[40];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, 0, n - 1);
    
    printf("Elements after performing sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
