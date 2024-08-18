// Fill out your copyright notice in the Description page of Project Settings.


#include "BasketBase.h"

#include "AppleBase.h"
#include "ApplePickerGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABasketBase::ABasketBase()
	:CurrentVelocity(0.0f), TempRelativeLocation(0.0, 0.0, -600)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Paddle1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Paddle1"));

	RootComponent = Root;
	Paddle1->SetupAttachment(RootComponent);

	BasketSpeed = 700.0f;
}

// Called when the game starts or when spawned
void ABasketBase::BeginPlay()
{
	Super::BeginPlay();

	Paddle1->OnComponentHit.AddDynamic(this, &ABasketBase::OnHit);
	
}

void ABasketBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (Cast<AAppleBase>(OtherActor) != nullptr)
	{
		AApplePickerGameModeBase* CurrentGameMode = Cast<AApplePickerGameModeBase>(UGameplayStatics::GetGameMode(this));
		if (CurrentGameMode != nullptr)
		{
			CurrentGameMode->HandleAppleCaught();
			if (CurrentGameMode->GetApplesCaught() >= CurrentGameMode->ApplesToWin)
			{
				UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
			}
		}
		OtherActor->Destroy();
	}
}

void ABasketBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SetActorRelativeLocation(TempRelativeLocation);
}

// Called every frame
void ABasketBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + CurrentVelocity * DeltaTime;
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void ABasketBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ABasketBase::MoveRight);
}

void ABasketBase::MoveRight(float AxisValue)
{
	CurrentVelocity.Y = BasketSpeed * FMath::Clamp(AxisValue, -1.0f, 1.0f);
}

void ABasketBase::HandlePaddleDestruction() const
{
	AApplePickerGameModeBase* CurrentGameMode = Cast<AApplePickerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (CurrentGameMode != nullptr)
	{
		if (CurrentGameMode->GetAppleLost() >= CurrentGameMode->ApplesToGameOver)
		{
			UE_LOG(LogTemp, Warning, TEXT("AppleLost >= 3"));
			UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
		}
	}
}

