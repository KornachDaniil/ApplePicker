// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelScriptBase.h"

#include "Camera/CameraActor.h"

ALevelScriptBase::ALevelScriptBase()
{
	Controller = nullptr;

	Camera = nullptr;
}

void ALevelScriptBase::BeginPlay()
{
	Super::BeginPlay();
	
	Controller = GetWorld()->GetFirstPlayerController();

	if (Controller)
	{
		Controller->SetViewTarget(Camera);
	}
	
}
