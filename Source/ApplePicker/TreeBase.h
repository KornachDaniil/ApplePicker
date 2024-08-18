// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AppleBase.h"
#include "GameFramework/Actor.h"
#include "TreeBase.generated.h"

UCLASS()
class APPLEPICKER_API ATreeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreeBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* TreeMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float MovementSpeed; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float OuterBoundary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float InnerBoundery;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float ChanceToRedirect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float RedirectTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float FirstDelay; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float SecondsBetweenAppleDrops;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Setup")
	TSubclassOf<AAppleBase> SpawnObj;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	FTimerHandle ChangeDirectionTimer;

	UFUNCTION()
	void ChangeDirection();

	UPROPERTY()
	FTimerHandle AppleSpawnTimer;

	UFUNCTION()
	void SpawnApple() const;
};
