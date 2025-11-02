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
	void LaunchTracker();

	UFUNCTION(BlueprintCallable, Category="Tracker")
	void StopTracker();

private:
	FProcHandle TrackerHandle;
};
