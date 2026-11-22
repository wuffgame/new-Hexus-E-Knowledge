#include <stdio.h>
#include <stdlib.h>

char *read_file(const char *path) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        printf("Cannot open file: %s\n", path);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size < 0) {
        fclose(file);
        return NULL;
    }
    rewind(file);
    char *buffer = malloc(size + 1);
    if (!buffer) {
        return NULL;
    }
    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);
    return buffer;
}

int main() {
    char *content = read_file("file.he");
    if (content != NULL) {
        printf("File content:\n%s\n", content);
        free(content);
    }
    return 0;
}