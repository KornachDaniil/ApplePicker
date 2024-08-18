// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ApplePickerGameModeBase.h"
#include "GameFramework/Actor.h"
#include "AppleBase.generated.h"

UCLASS()
class APPLEPICKER_API AAppleBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAppleBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* AppleMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setup)
	float FloorBoundary;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	AApplePickerGameModeBase* CurrentGameMode;
};
