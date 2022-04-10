#include "list.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>
unsigned char test_two_words(void)
{
	unsigned char is_success = 1;
	backpack_t current = { 0 };

	printf("Running test \"%s\"...\n", __FUNCTION__);

	if (!(is_success &= !regex_has_two_words(current.color)))
		printf("  Test \"%s\" failed:\n  Expected value: 0\n  Actual value: 1\n String: %s\n",
		       __FUNCTION__, current.color);

	strcpy(current.color, "One");
	if (!(is_success &= !regex_has_two_words(current.color)))
		printf("  Test \"%s\" failed:\n  Expected value: 0\n  Actual value: 1\n String: %s\n",
		       __FUNCTION__,current.color);

	strcpy(current.color, "One two");
	if (!(is_success &= regex_has_two_words(current.color)))
		printf("  Test \"%s\" failed:\n  Expected value: 1\n  Actual value: 0\n String: %s\n",
		       __FUNCTION__,current.color);

	strcpy(current.color, "One two three");
	if (!(is_success &= regex_has_two_words(current.color)))
		printf("  Test \"%s\" failed:\n  Expected value: 1\n  Actual value: 0\n String: %s\n",
		       __FUNCTION__,current.color);

	return is_success;
}

unsigned short int test_sort_by_volume()
{
    printf("Test running [%s] ...\n", __FUNCTION__);
    double start_test = start();
    unsigned short int is_success = 1;
    dllist_t *list = create_dllist();
    backpack_t *tmp = calloc(1, sizeof(backpack_t));
    tmp->volume = 10;
    tmp->laptop_compartment = 1;
    char *appointment = "military";
    char *brand = "adidas";
    char *brand_country = "Ukraine";
    char *color = "blue";
 
    strcpy(tmp->brand_1.country, brand_country);
    strcpy(tmp->brand_1.name, brand);
    strcpy(tmp->color, color);
    strcpy(tmp->appointment, appointment);

    push_dllist(list, tmp);

    tmp->volume = 5;

    push_dllist(list, tmp);

    sort_by_volume_dllist(list);

    if (list->head->data.volume > list->tail->data.volume)
    {
        printf("Test failed -->[%s]\n", __FUNCTION__);
        is_success = 0;
    }
    stop(start_test);
    return is_success;
}
unsigned short int test_push()
{
    printf("Test running [%s] ...\n", __FUNCTION__);
    double start_test = start();
    unsigned short int is_success = 1;
    dllist_t *list = create_dllist();
    backpack_t tmp;
    tmp.volume = 10;
    char *appointment = "military";
    char *brand = "adidas";
    char *brand_country = "Ukraine";
    char *color = "blue";
    char *laptop_comparament = "yes";

    strcpy(tmp.brand_1.country, brand_country);
    strcpy(tmp.brand_1.name, brand);
    strcpy(tmp.color, color);
    tmp.laptop_compartment = 1;
    strcpy(tmp.appointment, appointment);

    push_dllist(list, &tmp);

    if (!(is_success &= list->head->data.volume == 10) || list->size != 1)
    {
        free_dllist(&list);
        printf("Test failed -->[%s]\n", __FUNCTION__);
        stop(start_test);
        return is_success;
    }

    tmp.volume = 11;
    push_dllist(list, &tmp);

    if (!(is_success &= list->head->next->data.volume == 11) || list->size != 2)
    {
        printf("Test failed -->[%s]\n", __FUNCTION__);
    }
    free_dllist(&list);
    stop(start_test);
    return is_success;
}

unsigned short int test_remove()
{
    printf("Test running [%s] ...\n", __FUNCTION__);
    unsigned short int is_success = 1;
    double test_start = start(); 
    dllist_t *list = create_dllist();
    backpack_t tmp;
    tmp.volume = 10;
    char *appointment = "military";
    char *brand = "adidas";
    char *brand_country = "Ukraine";
    char *color = "blue";
    char *laptop_comparament = "yes";

    strcpy(tmp.brand_1.country, brand_country);
    strcpy(tmp.brand_1.name, brand);
    strcpy(tmp.color, color);
    tmp.laptop_compartment = 1;
    strcpy(tmp.appointment, appointment);

    push_dllist(list, &tmp);

    push_dllist(list, &tmp);

    if (!(is_success &= list->size == 2))
    {
        printf("Test failed -->[%s]\n", __FUNCTION__);
        free_dllist(&list);
        stop(test_start);
        return is_success;
    }

    remove_from_dllist(list, 1);
    if (!(is_success &= list->size == 1))
    {
        printf("Test failed -->[%s]\n", __FUNCTION__);
        free_dllist(&list);
        stop(test_start);
        return is_success;
    }

    remove_from_dllist(list, 0);

    if (!(is_success &= list->size == 0))
        printf("Test failed -->[%s]\n", __FUNCTION__);
    
    free_dllist(&list);
    stop(test_start);
    
    return is_success;
}
int main()
{
    time_now();
    
    double start_main = start();

    unsigned short int is_success = 1;

    is_success &= test_push();

    is_success &= test_remove();

    is_success &= test_sort_by_volume();

    is_success &= test_two_words();

    if (is_success)
        printf("All tests are passed!\n");

    stop(start_main);

    return 0;
}