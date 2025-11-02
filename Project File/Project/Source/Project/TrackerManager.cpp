#include "TrackerManager.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "Misc/FileHelper.h"

void UTrackerManager::LaunchTracker()
{
	// Directories
	FString PythonExe = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("ThirdParty/Python311/python.exe"));
	FString ScriptPath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("Scripts/tracker.py"));
	FString Args = FString::Printf(TEXT("\"%s\" --ip 127.0.0.1 --port 8000"), *ScriptPath);

	UE_LOG(LogTemp, Display, TEXT("Launching tracker: %s %s"), *PythonExe, *Args);
	UE_LOG(LogTemp, Log, TEXT("Packaged path: %s"), *FPaths::ProjectDir());

	TrackerHandle = FPlatformProcess::CreateProc(
		*PythonExe,
		*Args,
		true,
		false,
		false,
		nullptr,
		0,
		nullptr,
		nullptr
	);

	if (TrackerHandle.IsValid())
	{
		UE_LOG(LogTemp, Display, TEXT("Tracker launched"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Launch failed"));
	}
}

void UTrackerManager::StopTracker()
{
	if (TrackerHandle.IsValid())
	{
		FPlatformProcess::TerminateProc(TrackerHandle, true);
		FPlatformProcess::CloseProc(TrackerHandle);
		UE_LOG(LogTemp, Display, TEXT("Tracker process terminated"));
		TrackerHandle.Reset();
	}
}
