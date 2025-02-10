#include "bfile.h"

int CreateBFile(const char* filename)
{
    BFileHeader bFileHeader;
    FILE* file;

    bFileHeader.addrRootNode = 0;
    bFileHeader.degree = B_DEGREE;
    bFileHeader.recordLength = KEY_LENGTH + VALUE_LENGTH;
    bFileHeader.keyLength = KEY_LENGTH;
    bFileHeader.valueLength = VALUE_LENGTH;

    file = fopen(filename, "wb");
    fwrite((void*)&bFileHeader, sizeof(BFileHeader), 1, file);
    fclose(file);

    return 0;
}

BFileRuntime* OpenBFile(const char* filename)
{
    FILE* file;
    char* bFilePtr;
    BFileRuntime* bFileRuntime;
    BFileHeader* bFileHeader;

    if ((file = fopen(filename, "r+b")) == NULL)
    {
        return NULL;
    }

    bFilePtr = (char*)malloc(sizeof(BFileRuntime) + sizeof(BFileHeader));
    bFileRuntime = (BFileRuntime*)bFilePtr;
    bFilePtr += sizeof(BFileRuntime);
    bFileRuntime->bFileHeader = (BFileHeader*)bFilePtr;
    bFileRuntime->fp = file;

    fread((void*)bFileRuntime->bFileHeader, sizeof(BFileHeader), 1, bFileRuntime->fp);

    return bFileRuntime;
}

int CloseBFile(BFileRuntime* bFile)
{
    fclose(bFile->fp);
    free(bFile);
    return 0;
}