#define ENABLE_TEST_CODE

#ifdef ENABLE_TEST_CODE
extern int main_test(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    main_test(argc, argv);
}
#else
int main(int argc, char* argv[])
{

    return 0;
}
#endif