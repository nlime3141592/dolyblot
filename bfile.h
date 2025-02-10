#pragma once

#include <stdio.h>
#include <stdlib.h>

#define B_DEGREE 4
#define KEY_LENGTH 256
#define VALUE_LENGTH sizeof(int)

struct _BNodeEntry
{
    int addrRecordBegin;
    int addrKeyBegin;
    int keyLength;
};

struct _BNode
{
    struct _BNodeEntry entries[B_DEGREE - 1];
    int children[B_DEGREE];
};

struct _BFileHeader
{
    int addrRootNode;
    int degree;
    int recordLength;
    int keyLength;
    int valueLength;
};

struct _BFileRuntime
{
    struct _BFileHeader* bFileHeader;
    FILE* fp;
};

typedef struct _BNodeEntry BNodeEntry;
typedef struct _BNode BNode;
typedef struct _BFileHeader BFileHeader;
typedef struct _BFileRuntime BFileRuntime;

int CreateBFile(const char* filename);
BFileRuntime* OpenBFile(const char* filename);
int CloseBFile(BFileRuntime* bFile);