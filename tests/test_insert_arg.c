int main(void)
{
    char *str = "arg1 \'arg2 with spaces\' arg3";
    // printf("%d\n", count_carac_arg(&str));
    printf("%s\n", insert_arg(&str));
    printf("%s\n", insert_arg(&str));
    return 0;
}