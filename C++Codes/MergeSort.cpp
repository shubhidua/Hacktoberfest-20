void merge(int a[], int si, int ei)
{
    int final[1000];
    if (si >= ei)
        return;
    int mid = (si + ei) / 2;
    int i = si;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= ei)
    {
        if (a[i] < a[j])
            final[k++] = a[i++];
        else
            final[k++] = a[j++];
    }
    while (i <= mid)
        final[k++] = a[i++];

    while (j <= ei)
        final[k++] = a[j++];

    for (i = si; i <= ei; i++)
    {
        a[i] = final[i - si];
    }
}

void mergesort(int a[], int si, int ei)
{
    if (si >= ei)
        return;
    int mid = (si + ei) / 2;
    mergesort(a, si, mid);
    mergesort(a, mid + 1, ei);
    merge(a, si, ei);
}

void mergeSort(int a[], int n)
{
    mergesort(a, 0, n - 1);
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];    //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }

  mergeSort(arr, n);
   cout << "Array after Sorting: ";
   for(int i=0;i<n;i++)
   {
     cout<<arr[i]<<" ";
   }
}
