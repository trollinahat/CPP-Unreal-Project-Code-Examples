// Fill out your copyright notice in the Description page of Project Settings.

#include "Elevator.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AElevator::AElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Elevator Spline"));
	RootComponent = Spline;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	MovementCurve = CreateDefaultSubobject<UCurveFloat>(TEXT("Movement Curve"));

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->Intensity = LightIntensity;
	LightIntensity = 3000.f;
	Light->SetupAttachment(RootComponent);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->InitBoxExtent(FVector(300.f, 300.f, 300.f));
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	TriggerBox->SetupAttachment(RootComponent);

}

void AElevator::Tick(float DeltaTime) 
{

	Super::Tick(DeltaTime);

	if (MovementTimeline.IsPlaying()) {
		MovementTimeline.TickTimeline(DeltaTime);
	}
}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();
	
}

void AElevator::ProcessMovementTimeline(float Value)
{
	const float SplineLength = Spline->GetSplineLength();

	FVector CurrentSplineLocation = Spline->GetLocationAtDistanceAlongSpline(Value * SplineLength, ESplineCoordinateSpace::World);
	FRotator CurrentSplineRotation = Spline->GetRotationAtDistanceAlongSpline(Value * SplineLength, ESplineCoordinateSpace::World);

	Mesh->SetWorldLocationAndRotation(CurrentSplineLocation, CurrentSplineRotation);


}

void AElevator::MovementTimelineEnd()
{
	const float SplineLength = Spline->GetSplineLength();

	FVector OriginalSplineLocation = Spline->GetLocationAtDistanceAlongSpline(SplineLength, ESplineCoordinateSpace::World);
	FRotator OriginalSplineRotation = Spline->GetRotationAtDistanceAlongSpline(SplineLength, ESplineCoordinateSpace::World);

	Mesh->SetWorldLocationAndRotation(OriginalSplineLocation, OriginalSplineRotation);
}

void AElevator::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	Light->ToggleVisibility();

	FOnTimelineFloat ProgressFunction;
	ProgressFunction.BindUFunction(this, TEXT("ProcessMovementTimeline"));
	MovementTimeline.AddInterpFloat(MovementCurve, ProgressFunction);

	FOnTimelineEvent OnTimelineFinishedFunction;
	OnTimelineFinishedFunction.BindUFunction(this, TEXT("MovementTimelineEnd"));
	MovementTimeline.SetTimelineFinishedFunc(OnTimelineFinishedFunction);

	MovementTimeline.SetTimelineLengthMode(TL_LastKeyFrame);
	MovementTimeline.Play();

}

void AElevator::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{
	Light->ToggleVisibility();
}



