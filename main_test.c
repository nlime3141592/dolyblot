int main_test(int argc, char* argv[])
{
    // NOTE: 실행하고 싶은 테스트 함수의 인덱스를 기입하세요.
    int mainIndex = 1;

    // NOTE: 0으로 고정, 수정하지 마세요.
    int index = 0;

    // NOTE: 이 곳에 등록하고 싶은 함수의 함수 포인터를 등록합니다.
    int (*main_test_EntryPoints[10])();

    return main_test_EntryPoints[mainIndex]();
}