// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SplineComponent.h"
#include "Components/TimelineComponent.h"
#include "Elevator.generated.h"

UCLASS()
class THIRDPERSON_GAME_API AElevator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* TriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		class UPointLightComponent* Light;

	UPROPERTY(VisibleAnywhere)
		float LightIntensity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USplineComponent* Spline;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UCurveFloat* MovementCurve;

	UFUNCTION(BlueprintCallable)
		void ProcessMovementTimeline(float Value);

	UFUNCTION(BlueprintCallable)
		void MovementTimelineEnd();

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



private:
	FTimeline MovementTimeline;

};
