// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveVertically(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO: Prevent Double Speed due to duel control use
}

void UTankMovementComponent::IntendRotate(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO: Prevent Double Speed due to duel control use
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float IntendedVerticalMovement = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveVertically(IntendedVerticalMovement);
	float IntendedSideMovement = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendRotate(IntendedSideMovement);

	//UE_LOG(LogTemp, Warning, TEXT("%s moving %s"), *GetOwner()->GetName(), *MoveVelocity.GetSafeNormal().ToString());
}

