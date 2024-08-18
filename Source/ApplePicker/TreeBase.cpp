// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeBase.h"

// Sets default values
ATreeBase::ATreeBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TreeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TreeMeshComponent"));

	RootComponent = TreeMeshComponent;

	MovementSpeed = 550.0f;

	OuterBoundary = 900.0f;

	InnerBoundery = 600.0f;

	ChanceToRedirect = 0.4f;

	RedirectTime = 1.0f;

	FirstDelay = 2.5f;

	SecondsBetweenAppleDrops = 1.0f;
}

// Called when the game starts or when spawned
void ATreeBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(ChangeDirectionTimer, this, &ATreeBase::ChangeDirection, RedirectTime,
		true, FirstDelay);

	GetWorld()->GetTimerManager().SetTimer(AppleSpawnTimer, this, &ATreeBase::SpawnApple, SecondsBetweenAppleDrops,
		true, 2.0f);
	
}

// Called every frame
void ATreeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector TempLocation = GetActorLocation();

	if(TempLocation.Y <= -OuterBoundary)
	{
		MovementSpeed = FMath::Abs(MovementSpeed);
	}
	else if(TempLocation.Y >= OuterBoundary)
	{
		MovementSpeed = -(FMath::Abs(MovementSpeed));
	}
	
	TempLocation.Y += MovementSpeed * DeltaTime;
	SetActorLocation(TempLocation);
}

void ATreeBase::ChangeDirection()
{
	FVector TempPosition = GetActorLocation();
	if (TempPosition.Y <= InnerBoundery && TempPosition.Y >= -InnerBoundery)
	{
		if(FMath::FRand() <= ChanceToRedirect)
		{
			MovementSpeed = MovementSpeed * -1;
		}
	}
}

void ATreeBase::SpawnApple() const
{
	FVector SpawnLoc = GetActorLocation();
	FRotator SpawnRot = GetActorRotation();

	if (FMath::FRand() <= 0.5f)
	{
		SpawnLoc.Y += 150.0f;		
	}
	else
	{
		SpawnLoc.Y -= 150.0f;
	}

	GetWorld()->SpawnActor<AAppleBase>(SpawnObj, SpawnLoc, SpawnRot);
}

