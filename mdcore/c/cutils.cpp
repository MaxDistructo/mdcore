#include "mdcore/c/utils.h"

bool open_file(char* filename, FILE*& stream)
{
    stream = fopen(filename, "a+");
    return stream != NULL;
};
bool write_file(FILE* file, char* contents)
{
    int ret = fputs(contents, file);
    return ret > 0;
}
bool write_file(char* filename, char* contents)
{
    FILE* file = nullptr;
    open_file(filename, file);
    if(file == NULL)
    {
        return false;
    }
    int ret = fputs(contents, file);
    fclose(file);
    return ret > 0;
}