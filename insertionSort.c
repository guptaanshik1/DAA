# include <stdio.h>

void sort (int arr[10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int key = arr[i];
        j = i - 1;
        
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

int main () {
    int n, i, arr[40];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    
    printf("Elements after performing sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
