#include "FileManager.h"
#include <iostream>

using namespace std;

void FileManager::begin()
{
    if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED))
    {
        cout << "SPIFFS Mount Failed" << endl;
        return;
    }
}
void FileManager::ls(const char *dirname, uint8_t levels)
{
    cout << "Listing directory: " << dirname << endl;

    File root = _fs.open(dirname);
    if (!root)
    {
        cout << "- failed to open directory" << endl;
        return;
    }
    if (!root.isDirectory())
    {
        cout << " - not a directory" << endl;
        return;
    }

    File file = root.openNextFile();
    while (file)
    {
        if (file.isDirectory())
        {
            cout << "DIR : ";
            cout << file.name() << endl;
            if (levels)
            {
                this->ls(file.name(), levels - 1);
            }
        }
        else
        {
            cout << "FILE: " ;
            cout << file.name();
            cout << "\tSIZE:";
            cout << file.size() << endl;
        }
        file = root.openNextFile();
    }
}
void FileManager::read(const char *path)
{
    cout << "Reading file: " << path << endl;

    File file = _fs.open(path);
    if (!file || file.isDirectory())
    {
        cout << "- failed to open file for reading" << endl;
        return;
    }

    cout << "- read from file:" << endl;
    while (file.available())
    {
        cout << (char) file.read();
    }
    cout << endl;
}
void FileManager::write(const char *path, const char *message)
{
    cout << "Writing file: " << path << endl;

    File file = _fs.open(path, FILE_WRITE);
    if (!file)
    {
        cout << "- failed to open file for writing" << endl;
        return;
    }

    if (file.print(message))
        cout << "- file written" << endl;
    else
        cout << "- file write failed" << endl;
}
void FileManager::append(const char *path, const char *message)
{
    cout << "Appending to file: " << path << endl;

    File file = _fs.open(path, FILE_APPEND);
    if (!file)
    {
        cout << "- failed to open file for appending" << endl;
        return;
    }

    if (file.print(message))
        cout << "- message appended" << endl;
    else
        cout << "- append failed" << endl;
}
void FileManager::rename(const char *path1, const char *path2)
{
    cout << "Renaming file " << path1 << " to " << path2 << endl;
    if (_fs.rename(path1, path2))
        cout << "- file renamed" << endl;
    else
        cout << "- rename failed" << endl;
}
void FileManager::remove (const char *path)
{
    cout << "Deleting file: " << path << endl;
    if (_fs.remove(path))
        cout << "- file deleted" << endl;
    else
        cout << "- delete failed" << endl;
}

String FileManager::getFileContent(const char *path)
{
    cout << "Getting file content : " << path << endl;

    File file = _fs.open(path);
    String data;
    if (!file || file.isDirectory())
    {
        cout << "- failed to open file for reading" << endl;
    }
    else
    {
        while (file.available())
        {
            data += (char)file.read();
        }
        cout << "OK!"<<endl;
    }

    return data;
}