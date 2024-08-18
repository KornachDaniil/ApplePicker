// Copyright Epic Games, Inc. All Rights Reserved.


#include "ApplePickerGameModeBase.h"

#include "Kismet/GameplayStatics.h"

void AApplePickerGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	Basket = Cast<ABasketBase>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AApplePickerGameModeBase::HandleAppleLost()
{
	AppleLost += 1;
	UE_LOG(LogTemp, Warning, TEXT("Apple Lost: "));
	UE_LOG(LogTemp, Warning, TEXT("%d"), AppleLost);

	Basket->HandlePaddleDestruction();
}

void AApplePickerGameModeBase::HandleAppleCaught()
{
	UE_LOG(LogTemp, Warning, TEXT("Apple Caught: "));
	UE_LOG(LogTemp, Warning, TEXT("%d"), ApplesCaught);

	ApplesCaught += 1;
}