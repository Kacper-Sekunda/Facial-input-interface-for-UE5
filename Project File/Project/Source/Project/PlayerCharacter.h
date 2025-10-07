#pragma once

#include "CoreMinimal.h"
#include "InputDataConfig.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	float MouseSensitivity = 0.25f;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputMappingContext* MappingContext;

	class UinputDataConfig;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputDataConfig* InputActions;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
