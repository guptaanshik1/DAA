# include <stdio.h>

void create(int heap[]) {
    int i, n;
    heap[0] = n;
    for (i = n / 2; i >= 1; i--) {
        adjust(heap, i);
    }
}

void adjust(int heap[], int i) {
    int i, n, j, temp, flag = 1;
    n = heap[0];
    while (2 * i <= n && flag == 1) {
        j = 2 * i;
        if (j + 1 <= n && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[i] > heap[j]) {
            flag = 0
        } else {
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }
    }
}

int main () {
    int heap[30], n, i, temp, last;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &heap[i]);
    }
    heap[0] = n;
    create(heap);
    while (heap[0] > 1) {
        last = heap[0];
        temp = heap[1];
        heap[1] = heap[last];
        heap[last] = temp;
        heap[0]--;
        adjust(heap, 1);
    }
}
