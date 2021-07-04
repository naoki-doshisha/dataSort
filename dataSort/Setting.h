#pragma once

#define CHARBUFF 128
#define BUFFSIZE 1024
#define DATA 2

int readInt(const char* secton, const char* keyword, int defaultValue, const char* filePath);
bool readChar(const char* secton, const char* keyword, const char* defaultValue, char* returnValue, const char* filePath);
double readDouble(const char* secton, const char* keyword, double defaultValue, const char* filePath);
void getCurrentDirectory(char* currentDirectory);
bool writeChar(const char* secton, const char* keyword, const char* returnValue, const char* filePath);
bool writeInt(const char* secton, const char* keyword, int returnValue, const char* filePath);
bool writeDouble(const char* secton, const char* keyword, double returnValue, const char* fliePath);
