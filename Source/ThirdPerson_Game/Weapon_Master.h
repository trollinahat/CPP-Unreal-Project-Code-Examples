// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Weapon_Master.generated.h"

UCLASS()
class THIRDPERSON_GAME_API AWeapon_Master : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon_Master();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	//amount of damage dealt by the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		int AmountofDamage;

	//can the weapon deal damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		bool CanDealDamage;

	//WeaponType
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		FName WeaponType;

	//Weapon Mesh Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		class UStaticMeshComponent* WeaponMesh;

	//Weapon Hit Capsule
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		class UCapsuleComponent* HitCapsule;

	//Weapon Particle Effect (not used on all weapons)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		class UParticleSystemComponent* WeaponEffect;

	//Function to attach weapon to player
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void AttachWeaponToPlayer();

	//Declare Overlap Begin Function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Declare Overlap End Function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
