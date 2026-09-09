#include <stdio.h>
#include <limits.h>

/**
 * Calculates the number of students required to allocate books 
 * such that no student reads more than 'maxPages' pages.
 * 
 * @param arr Pointer to the array of book pages
 * @param n Number of books
 * @param maxPages The maximum pages a student is allowed to read
 * @return The number of students required
 */
int countStudents(int arr[], int n, int maxPages) {
    int students = 1;
    long long pagesStudent = 0;

    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= maxPages) {
            // Allocate book to the current student
            pagesStudent += arr[i];
        } else {
            // Allocate book to the next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

/**
 * Finds the minimum possible maximum number of pages assigned to a student.
 * 
 * @param arr Pointer to the array of book pages
 * @param n Number of books
 * @param m Number of students
 * @return The minimum possible maximum pages, or -1 if allocation is impossible
 */
int allocateBooks(int arr[], int n, int m) {
    // If there are more students than books, allocation is impossible
    if (m > n) {
        return -1;
    }

    int low = INT_MIN;
    long long high = 0;

    // Determine the search space:
    // low = maximum pages in a single book (a student must read at least this much)
    // high = sum of all pages (one student reads everything)
    for (int i = 0; i < n; i++) {
        if (arr[i] > low) {
            low = arr[i];
        }
        high += arr[i];
    }

    int ans = -1;

    // Apply Binary Search on the range of possible maximum pages
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        int studentsRequired = countStudents(arr, n, mid);

        if (studentsRequired <= m) {
            ans = mid;       // This allocation is possible, record it
            high = mid - 1;  // Try to find a smaller maximum
        } else {
            low = mid + 1;   // The maximum pages are too low, we need more
        }
    }

    return ans;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;

    int result = allocateBooks(arr, n, m);
    if (result != -1) {
        printf("The minimum possible maximum pages is: %d\n", result);
    } else {
        printf("Book allocation is not possible.\n");
    }

    return 0;
}
