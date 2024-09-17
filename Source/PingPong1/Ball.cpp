#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"  

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	RootComponent = BallMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMeshAsset(TEXT("/Engine/BasicShapes/Sphere"));

	if (BallMeshAsset.Succeeded())
	{
		BallMesh->SetStaticMesh(BallMeshAsset.Object);
	}

	BallMesh->SetSimulatePhysics(true);
	BallMesh->SetNotifyRigidBodyCollision(true);
	BallMesh->BodyInstance.SetCollisionProfileName("BlockAll");

	BallMesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);

	BallVelocity = FVector(500.f, 0.f, 0.f); 
}

void ABall::BeginPlay()
{
	Super::BeginPlay();
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation() + (BallVelocity * DeltaTime);
	SetActorLocation(NewLocation);
}

void ABall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	BallVelocity = FMath::GetReflectionVector(BallVelocity, Hit.Normal);
}