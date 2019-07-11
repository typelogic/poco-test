//#include "Poco/File.h"
//#include "Poco/Path.h"
#include "Poco/TemporaryFile.h"
#include <iostream>
#include <fstream>

#include <thread>
#include <chrono>

std::string g;

int addnum(int,int);

void fileops()
{
    const std::string filePath = "/tmp/test.file";
    Poco::File testFile(filePath);


    bool bIsFile = testFile.isFile();
    bool bReadable = testFile.canRead();
    bool bWriteable = testFile.canWrite();


	if (bIsFile) std::cout << "it is a file\n";
	if (bReadable) std::cout << "file is readable\n";
	if (bWriteable) std::cout << "file is writeable\n";

    if (testFile.exists()) std::cout << "file exists\n";

    testFile.remove();
}

void ff() 
{
    Poco::File x(g);
    x.remove(true);
}

int main(int argc, char** argv) 
{
    //fileops();

    //std::cout << Poco::Path::temp();
#if 0
    Poco::Path tmpPath(Poco::Path::temp());
    tmpPath.pushDirectory("mytempfolder");

    Poco::File tmpDir(tmpPath);
    tmpDir.createDirectories();

    if (tmpDir.exists()) std::cout << "dir exists\n";
    if (tmpDir.isFile()) std::cout << "is file\n";
    if (tmpDir.isDirectory()) std::cout << "is directory\n";
    if (tmpDir.canRead()) std::cout << "canRead\n";
    if (tmpDir.canWrite()) std::cout << "canWrite\n";
#endif

#if 0
    tmp.keep();
    std::cout << tmp.path().c_str();
    std::cout << "\n----\n";
    std::ofstream ostr(tmp.path().c_str());
    ostr << "hello, world!" << std::endl;
    ostr.close();
#endif    

#if 0
    for (int i = 0;i < 10;i++) {
        std::cout << tmp.tempName() << std::endl;
    }
#endif

#if 0
    Poco::TemporaryFile tmp;
    std::string s = tmp.tempName();
    std::cout << "[" << s << "]\n";
    Poco::File x(s);
    x.createDirectories();
    //x.remove(true);
    g = s;

    //ff();
#endif

#if 0
    std::string a = "/tmp/";
    std::string b = a + "testfile.dat";
    std::cout << b;
#endif

#if 0
    const std::string filePath = "/tmp/test.file";
    Poco::File testFile(filePath);

    if (testFile.createFile()) {
        std::cout << "\ncreated\n";
    } else {
        std::cout << "\nNOT created\n";
    }
#endif

    std::cout << addnum(3,4);

	return 0;
}
