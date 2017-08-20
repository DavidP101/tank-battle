// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"


void UTankTurret::Rotate(float RelativeSpeed)
{

	float ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float YawChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewYaw = RelativeRotation.Yaw + YawChange;
	SetRelativeRotation(FRotator(0, NewYaw, 0));
}

