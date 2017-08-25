// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"





//Will drive tank in direction of forward vector of track
void UTankTrack::SetThrottle(float Throttle)
{
	
	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



