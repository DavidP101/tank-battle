// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Called at the beginning of play
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possessing a tank!"));
		return;
	}

	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No player tank found!"));
		return;
	}

}

//Get the player controlled tank i.e. not the AI
ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//TODO Move towards the player

		//TODO Aim towards the player
		AimTowardsTank();

		//TODO Fire when ready
	}
	

}

//Forces AI Tank to aim towards the player tank
void ATankAIController::AimTowardsTank()
{
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

