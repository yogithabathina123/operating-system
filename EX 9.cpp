
#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SHM_SIZE 1024

int main(void)
{
    HANDLE hMapFile;
    char *shm_ptr;

    /* Create shared memory */
    hMapFile = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        SHM_SIZE,
        "MySharedMemory"
    );

    if (hMapFile == NULL)
    {
        printf("Error creating shared memory: %lu\n", GetLastError());
        return 1;
    }

    /* Map shared memory */
    shm_ptr = (char *)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SHM_SIZE
    );

    if (shm_ptr == NULL)
    {
        printf("Error mapping shared memory: %lu\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    
    strcpy(shm_ptr, "Hello, Shared Memory!!");

    printf("Data Written To Shared Memory: %s\n", shm_ptr);

    
    if (!UnmapViewOfFile(shm_ptr))
    {
        printf("Error unmapping shared memory: %lu\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

  
    CloseHandle(hMapFile);

    printf("Shared memory detached successfully.\n");

    return 0;
}


