// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrackerManager.generated.h"

UCLASS(Blueprintable)
class PROJECT_API UTrackerManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tracker")
	void LaunchTracker(FString IP, FString Port, FString CameraIndex);

	UFUNCTION(BlueprintCallable, Category="Tracker")
	void StopTracker();

	UFUNCTION(BlueprintCallable, Category="Tracker")
	static TArray<FString> ListCameraDevices();

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tracker")
	FString IP = "127.0.0.1";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tracker")
	FString Port = "8000";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tracker")
	FString CameraIndex = "0";
	*/
private:
	FProcHandle TrackerHandle;
};
