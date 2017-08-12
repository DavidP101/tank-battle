// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possessing a tank!"));
	}
	else
	{
		ATank* PlayerTank = GetPlayerTank(); //get the player controlled tank i.e. the human player

		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("No player tank found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Player Tank found at position: %s"), *PlayerTank->GetActorLocation().ToString());
		}
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

