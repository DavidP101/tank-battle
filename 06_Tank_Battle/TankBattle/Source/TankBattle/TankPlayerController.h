// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair(); //Line trace through crosshair so we can fire the barrel correctly.
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f; //Reach of the Line Trace
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5; //50% x-axis
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33; //33% in from y-axis
};
