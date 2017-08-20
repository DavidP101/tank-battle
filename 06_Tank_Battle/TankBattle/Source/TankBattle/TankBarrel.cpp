// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame
	//Given a max elevation speed, and the frame time

	float ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}


