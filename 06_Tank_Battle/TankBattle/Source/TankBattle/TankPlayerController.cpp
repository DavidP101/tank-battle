// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing a tank %s"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitResult; //OUT parameter

	if (GetSightRayHitLocation(HitResult))
	{
		GetControlledTank()->AimAt(HitResult);
	}


}

//Raycast through the dot into the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{	
	///Find camera crosshair and pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;

	///Deproject the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, OutHitLocation);	
	}


	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	//To be discarded
	FVector CameraWorldLocation;

	///Deproject the screen position of the crosshair to a world location
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	
	///Parameters for LineTrace
	FHitResult OutHit;
	FVector StartLineLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLineLocation = StartLineLocation + (LookDirection * LineTraceRange);

	///Line trace out into the world, If we hit something return true
	bool HitSomething = GetWorld()->LineTraceSingleByChannel
		(OutHit,
		StartLineLocation, 
		EndLineLocation, 
		ECollisionChannel::ECC_Visibility);

	if (HitSomething)
	{
		OutHitLocation = OutHit.Location;
		return true;
	}
	else
	{
		OutHitLocation = FVector(0);
		return false;
	}
	
}
