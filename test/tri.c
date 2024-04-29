#include <criterion/criterion.h>
#include <string.h>
#include "ls.h"

Test(try_ascii, test_compare_ascii) {
    // Test when str1 is less than str2
    char str1[] = "apple";
    char str2[] = "banana";
    cr_assert_eq(try_ascii(str1, str2), -1);

    // Test when str1 is greater than str2
    char str3[] = "banana";
    char str4[] = "apple";
    cr_assert_eq(try_ascii(str3, str4), 1);

    // Test when str1 and str2 are equal
    char str5[] = "apple";
    char str6[] = "apple";
    cr_assert_eq(try_ascii(str5, str6), 0);

    // Test when either str1 or str2 is NULL
    char* str7 = NULL;
    cr_assert_eq(try_ascii(str7, str6), 0);
    cr_assert_eq(try_ascii(str5, str7), 0);
}

Test(strtab_sort, test_sort_string_array) {
    // Test sorting an array of strings in ascending order
    char* strtab[] = {"banana", "apple", "cherry", "date", NULL};
    char* sorted[] = {"apple", "banana", "cherry", "date", NULL};
    strtab_sort(strtab);
    for (int i = 0; strtab[i] != NULL; ++i) {
        cr_assert_str_eq(strtab[i], sorted[i]);
    }

    // Test sorting an already sorted array (no change expected)
    char* strtab2[] = {"apple", "banana", "cherry", "date", NULL};
    strtab_sort(strtab2);
    for (int i = 0; strtab2[i] != NULL; ++i) {
        cr_assert_str_eq(strtab2[i], sorted[i]);
    }

    // Test sorting an array of strings in descending order
    char* strtab3[] = {"date", "cherry", "banana", "apple", NULL};
    char* sorted_desc[] = {"apple", "banana", "cherry", "date", NULL};
    strtab_sort(strtab3);
    for (int i = 0; strtab3[i] != NULL; ++i) {
        cr_assert_str_eq(strtab3[i], sorted_desc[i]);
    }

    // Test sorting an array with only one element
    char* strtab4[] = {"apple", NULL};
    strtab_sort(strtab4);
    cr_assert_str_eq(strtab4[0], "apple");
}
