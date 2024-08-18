// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BasketBase.h"
#include "GameFramework/GameModeBase.h"
#include "ApplePickerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API AApplePickerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	FORCEINLINE int32 GetAppleLost() const { return AppleLost; }
	FORCEINLINE int32 GetApplesCaught() const { return ApplesCaught; }

	void HandleAppleLost();
	void HandleAppleCaught();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setup)
	int32 ApplesToWin = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setup)
	int32 ApplesToGameOver = 3;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setup)
	float GameStartDelay;
	
private:
	int32 ApplesCaught = 0;
	int32 AppleLost = 0;

	UPROPERTY() 
	ABasketBase* Basket;
};
