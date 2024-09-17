#include "Goal.h"
#include "Components/StaticMeshComponent.h"
#include "Ball.h"
#include "GameFramework/Actor.h"
#include "PingPongGameMode.h"
#include <Kismet/GameplayStatics.h>

AGoal::AGoal()
{
	PrimaryActorTick.bCanEverTick = true;

	GoalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GoalMesh"));
	RootComponent = GoalMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> GoalMeshAsset(TEXT("/Engine/BasicShapes/Cube"));

	if (GoalMeshAsset.Succeeded())
	{
		GoalMesh->SetStaticMesh(GoalMeshAsset.Object);
	}

	GoalMesh->SetGenerateOverlapEvents(true);
	GoalMesh->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OnOverlapBegin);
}

void AGoal::BeginPlay()
{
	Super::BeginPlay();
}

void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGoal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(ABall::StaticClass()))
	{
		
		APingPongGameMode* GameMode = Cast<APingPongGameMode>(UGameplayStatics::GetGameMode(this));
		if (GameMode)
		{
			
			GameMode->AddScore(1); 
		}

		
		OtherActor->SetActorLocation(FVector(0.f, 0.f, 100.f)); 
	}
}


void AGoal::AddScore()
{
	
	UE_LOG(LogTemp, Warning, TEXT("Goal Scored!"));
}

