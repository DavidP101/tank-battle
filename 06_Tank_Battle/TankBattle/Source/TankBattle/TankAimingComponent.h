// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enums
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked,
};


//Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

//Holds Parameters for Barrel Properties and Elevate method

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Attack)
	void Fire();
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 5000;
	double LastFireTime = 0;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

private:
	void MoveBarrelTowards(FVector AimDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringStatus FiringState = EFiringStatus::Aiming;
};
