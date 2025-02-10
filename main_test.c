#include "bfile.h"

int main_test_Create()
{
    CreateBFile("./bfile.dat");
    printf("main_test_Create OK.\n");
    return 0;
}

int main_test_OpenAndClose()
{
    BFileRuntime* bFileRuntime = OpenBFile("./bfile.dat");

    printf("addrRootNode == %d\n", bFileRuntime->bFileHeader->addrRootNode);
    printf("degree == %d\n", bFileRuntime->bFileHeader->degree);
    printf("recordLength == %d\n", bFileRuntime->bFileHeader->recordLength);
    printf("keyLength == %d\n", bFileRuntime->bFileHeader->keyLength);
    printf("valueLength == %d\n", bFileRuntime->bFileHeader->valueLength);
    printf("main_test_OpenAndClose OK.\n");

    CloseBFile(bFileRuntime);

    return 0;
}

int main_test(int argc, char* argv[])
{
    // NOTE: 실행하고 싶은 테스트 함수의 인덱스를 기입하세요.
    int mainIndex = 1;

    // NOTE: 0으로 고정, 수정하지 마세요.
    int index = 0;

    // NOTE: 이 곳에 등록하고 싶은 함수의 함수 포인터를 등록합니다.
    int (*main_test_EntryPoints[10])();
    main_test_EntryPoints[index++] = main_test_Create;
    main_test_EntryPoints[index++] = main_test_OpenAndClose;

    return main_test_EntryPoints[mainIndex]();
}