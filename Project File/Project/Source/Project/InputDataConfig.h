// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "InputDataConfig.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UInputDataConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* Move;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UInputAction* Look;
};
