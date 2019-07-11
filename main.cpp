#include "Poco/Path.h"
#include "Poco/TemporaryFile.h"
//#include "Poco/File.h" // no longer necessary

#include <iostream>
#include <fstream>

#include <thread>
#include <chrono>

std::string g;

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

Poco::TemporaryFile tmp;
std::string testTempFolder = tmp.tempName();

//testTempFolder = tmp.tempName(); // cannotbe
Poco::File x(testTempFolder);
//x.createDirectories(); // cannotbe

void TearDown() 
{
	Poco::File x(testTempFolder);
	x.remove(true);
}

int main(int argc, char** argv) 
{
    //fileops();

#if 0	
	std::cout << "[" << testTempFolder << "]\n";
	x.createDirectories();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "deleting foler " << testTempFolder << "\n";
	TearDown();
#endif

    std::cout << Poco::Path::temp() << std::endl;

#if 0
    Poco::Path tmpPath(Poco::Path::temp());
    tmpPath.pushDirectory("mytempfolder");

    Poco::File tmpDir(tmpPath);
    tmpDir.createDirectories();

    if (tmpDir.exists()) std::cout << "it exists\n";
    if (tmpDir.isFile()) std::cout << "is file\n";
    if (tmpDir.isDirectory()) std::cout << "is directory\n";
    if (tmpDir.canRead()) std::cout << "canRead\n";
    if (tmpDir.canWrite()) std::cout << "canWrite\n";

    //tmp.keep(); // tell file to persist, otherwise it self-deletes
    std::cout << tmp.path().c_str();
    std::cout << "\n----\n";
    std::ofstream ostr(tmp.path().c_str());
    ostr << "hello, world!" << std::endl;
    ostr.close();
	//tmp.remove(); // can explicitely remove file
#endif    

#if 0
    for (int i = 0;i < 3;i++) {
		/*
		prints out, but does not create it:
			/tmp/tmp1449caaaaa
			/tmp/tmp1449daaaaa
			/tmp/tmp1449eaaaaa
		*/
        std::cout << tmp.tempName() << std::endl;
    }
#endif

#if 0
    Poco::TemporaryFile tmp;
    std::string s = tmp.tempName();
    std::cout << "[" << s << "]\n";
    Poco::File x(s);
    x.createDirectories();
    //x.remove(true); // remove folder recursively!
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
		//testFile.remove(); // can explicitely delete file too, otherwise it persist
    } else {
		// goes here if file already exists
        std::cout << "\nNOT created\n";
    }
#endif

	return 0;
}
