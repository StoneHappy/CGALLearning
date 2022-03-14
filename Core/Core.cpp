#include "Core.h"

#ifdef TEST_DATA_DIR
extern const std::filesystem::path g_DataPath = TEST_DATA_DIR;
#else
extern const std::filesystem::path g_DataPath = "Assert";
#endif