/*
* Alpha Entity List Adjuster
* Copyright (c) 2014 ThirteenAG <>
* Licensed under the MIT License (http://opensource.org/licenses/MIT)
*/
#include "LimitAdjuster.h"

auto CVisibilityPlugins__Shutdown = (int *(__cdecl *)()) 0x582870;
auto CVisibilityPlugins__Initialise = (int *(__cdecl *)()) 0x5828A0;

auto CVisibilityPlugins__Shutdown3 = (int *(__cdecl *)()) 0x527EA0;
auto CVisibilityPlugins__Initialise3 = (int *(__cdecl *)()) 0x527E50;

class AlphaEntityListIII : public SimpleAdjuster
{
public:
	const char* GetLimitName() { return GetGVM().IsIII() ? "AlphaEntityListSize" : nullptr; }
	void ChangeLimit(int, const std::string& value)
	{
		injector::WriteMemory(0x527E6B + 1, std::stoi(value), true);
		if (*(DWORD*)0x943098 == 0x4CBEBC20)
		{
			int* Shutdown = CVisibilityPlugins__Shutdown3();
			int* Initialise = CVisibilityPlugins__Initialise3();
		}
	}

} AlphaEntityListIII;

class AlphaEntityListVC : public SimpleAdjuster
{
public:
	const char* GetLimitName() { return GetGVM().IsVC() ? "AlphaEntityListSize" : nullptr; }
	void ChangeLimit(int, const std::string& value) 
		{
			injector::WriteMemory(0x5828DB+1, std::stoi(value), true); 
			
			if (*(DWORD*)0x97F30C == 0x4CBEBC20)
			{
				int* Shutdown = CVisibilityPlugins__Shutdown();
				int* Initialise = CVisibilityPlugins__Initialise();
			}
		}

} AlphaEntityListVC;

class AlphaEntityListSA : public SimpleAdjuster
{
public:
	const char* GetLimitName() { return GetGVM().IsSA() ? "AlphaEntityListSize" : nullptr; }

	void ChangeLimit(int, const std::string& value)
	{
		injector::WriteMemory(0x733B05, std::stoi(value), true);
		injector::WriteMemory(0x733B55, std::stoi(value), true);
	}
} AlphaEntityListSA;

