// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScriptBase.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API ALevelScriptBase : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	ALevelScriptBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Camera Setup")
	ACameraActor* Camera;
	
private:
	UPROPERTY()
	APlayerController* Controller;
};
