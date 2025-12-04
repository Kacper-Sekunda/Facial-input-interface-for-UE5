#include "TrackerManager.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include <mfapi.h>
#include <mfidl.h>

#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "Misc/FileHelper.h"

void UTrackerManager::LaunchTracker(FString IP, FString Port, FString CameraIndex)
{
	// Directories
	FString PythonExe = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("ThirdParty/Python311/python.exe"));
	FString ScriptPath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("Scripts/tracker.py"));
	FString Args = FString::Printf(TEXT("\"%s\" --ip %s --port %s --camera %s"), *ScriptPath, *IP, *Port, *CameraIndex);

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

TArray<FString> UTrackerManager::ListCameraDevices()
{
	TArray<FString> CameraList;

	IMFAttributes* pAttributes = nullptr;
	MFCreateAttributes(&pAttributes, 1);
	pAttributes->SetGUID(
		MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
		MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
	);

	IMFActivate** devices = nullptr;
	UINT32 count = 0;
	MFEnumDeviceSources(pAttributes, &devices, &count);

	for (UINT32 i = 0; i < count; i++)
	{
		WCHAR* name = nullptr;
		UINT32 nameLength = 0;
		devices[i]->GetAllocatedString(
			MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
			&name,
			&nameLength
		);

		FString DeviceName = FString(name);
		CameraList.Add(DeviceName);
		CoTaskMemFree(name);
		devices[i]->Release();
	}
	CoTaskMemFree(devices);
	pAttributes->Release();

	return CameraList;
}
