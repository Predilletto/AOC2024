#ifndef ARRAYS_H
#define ARRAYS_H

int linear_search(int elements[], int element, int lenght);
int binary_search(int elements[], int element, int lenght);
void array_to_string(int arr[], int size);
void selection_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void merge_sort(int arr[], int size);
void merge(int arr[], int left[], int right[], int left_size, int right_size);

#endif // ARRAYS_H
