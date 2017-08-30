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
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Attack)
	void Fire();



private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 5000;
	double LastFireTime = 0;



protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringStatus FiringState = EFiringStatus::Aiming;
};
