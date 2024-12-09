#include "/home/prettyletto/Projects/AOC2024/lib/arrays/arrays.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int binary_search_fixed(int elements[], int element, int lenght) {
  int low = 0;
  int high = lenght - 1;
  do {

    int middle = (low + high) / 2;
    if (elements[middle] == element) {
      return middle;
    } else if (element < elements[middle]) {
      high = middle - 1;
    } else if (element > elements[middle]) {
      low = middle + 1;
    }
  } while (low <= high);

  return -1;
}
int get_file_size(FILE *fp) {
  char line[255];
  int count_lines = 0;
  while (fgets(line, 255, fp)) {
    count_lines++;
  }
  return count_lines;
}

int count_equals(int arr[], int index, int size) {
  int element = arr[index];
  int sum = 1;
  int left_index = index - 1;
  int right_index = index + 1;
  while (left_index >= 0) {
    if (arr[left_index] != element) {
      break;
    }
    sum++;
    left_index--;
  }
  while (right_index < size) {
    if (arr[right_index] != element) {
      break;
    }
    sum++;
    right_index++;
  }
  return sum;
}

void q2(int arr1[], int arr2[], int size) {
  int looking = arr1[0];
  long sum = 0;
  for (int i = 0; i < size; i++) {
    looking = arr1[i];
    int found = binary_search_fixed(arr2, looking, size);
    int founded = count_equals(arr2, found, size);
    if (found >= 0) {
      sum = sum + (looking * founded);
    }
  }
  printf("%ld\n", sum);
}

void populate_arrays(char *line, int *num1, int *num2) {
  sscanf(line, "%d %d", num1, num2);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <file_location>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Failed to open the file %s\n", argv[1]);
    return 2;
  }
  char line[255];
  int capacity = get_file_size(file);
  rewind(file);
  int column1[capacity];
  int column2[capacity];
  int i = 0;
  while (fgets(line, 255, file)) {
    populate_arrays(line, &column1[i], &column2[i]);
    i++;
  }
  merge_sort(column1, capacity);
  merge_sort(column2, capacity);
  int sum = 0;
  for (int i = 0; i < capacity; i++) {
    sum += column1[i] > column2[i] ? column1[i] - column2[i]
                                   : column2[i] - column1[i];
  }
  q2(column1, column2, capacity);
  fclose(file);
}
