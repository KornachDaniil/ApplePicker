// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasketBase.generated.h"

UCLASS()
class APPLEPICKER_API ABasketBase : public APawn
{
	GENERATED_BODY()

	FVector CurrentVelocity;
public:
	// Sets default values for this pawn's properties
	ABasketBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Paddle1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setup)
	float BasketSpeed;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse
		, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setup)
	FVector TempRelativeLocation;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnConstruction(const FTransform& Transform) override;
	
	UFUNCTION()
	void MoveRight(float AxisValue);


	UFUNCTION()
	void HandlePaddleDestruction() const;
};
