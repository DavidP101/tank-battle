// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


//Called at the beginning of play
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in centimetres

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); //TODO: Don't fire every frame
	}
}

