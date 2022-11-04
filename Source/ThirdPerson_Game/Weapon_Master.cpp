// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Master.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AWeapon_Master::AWeapon_Master()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//instantiate default values -- can be edited in child classes, as needed
	int AmountOfDamage = 0;

	AWeapon_Master::CanDealDamage = true;

	//Weapon Colors include Generic, Red, Blueand Green
	AWeapon_Master::WeaponType = FName(TEXT("Generic"));

	HitCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Hit Capsule"));
	RootComponent = HitCapsule;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Weapon Effect"));
	WeaponEffect->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWeapon_Master::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon_Master::AttachWeaponToPlayer()
{
}

void AWeapon_Master::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AWeapon_Master::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}



