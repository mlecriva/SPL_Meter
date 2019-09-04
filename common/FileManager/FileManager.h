#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__
#include <string.h>
#include "FS.h"
#include "SPIFFS.h"

#define FORMAT_SPIFFS_IF_FAILED true

class FileManager
{
public:
    FileManager(fs::FS &fs): _fs(fs){};
    void begin();

    bool mkdir(const char *path) { return _fs.mkdir(path); }
    bool rmdir(const char *path) { return _fs.rmdir(path); }

    void ls(const char *dirname, uint8_t levels);

    void read(const char *path);
    void write(const char *path, const char *message);
    void append(const char *path, const char *message);
    void rename(const char *path1, const char *path2);
    void remove(const char *path);

    String getFileContent(const char *path);
protected:
    fs::FS &_fs;
};

#endif /* __FILEMANAGER_H_ */
