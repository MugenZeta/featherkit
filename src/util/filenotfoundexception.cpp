#include <featherkit/util/filenotfoundexception.h>

namespace fku
{
    FileNotFoundException::FileNotFoundException():runtime_error("File not found")
    {
    }

    FileNotFoundException::FileNotFoundException(std::string msg):runtime_error(msg.c_str())
    {
    }
}