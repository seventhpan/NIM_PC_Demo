#pragma once
#include <string>
#include <map>

#define DEMO_GLOBAL_APP_KEY			"e84f26440a7069797c6341088762755c"
#define DEMO_GLOBAL_TEST_APP_KEY	"255ab2c6ba1a"

class QString
{
public:
	static std::string GetGUID();
	static std::string GetMd5(const std::string& input);
	static void NIMFreeBuf(void *data);
};

class QPath
{
public:
	static std::wstring GetAppPath(); //获取exe所在目录，最后有"\\"
	static std::wstring GetUserAppDataDir(const std::string& app_account);
	static std::wstring GetLocalAppDataDir();
	static std::wstring GetNimAppDataDir(const std::wstring& app_data_dir); // "...Local\\Netease\\Nim\\"
};

class QCommand
{
public:
	static void ParseCommand(const std::wstring &cmd);
	static bool AppStartWidthCommand(const std::wstring &app, const std::wstring &cmd);
	static bool RestartApp(const std::wstring &cmd);
	static std::wstring Get(const std::wstring &key);
	static void Set(const std::wstring &key, const std::wstring &value);
	static void Erase(const std::wstring &key);
private:
	static std::map<std::wstring,std::wstring> key_value_;
};