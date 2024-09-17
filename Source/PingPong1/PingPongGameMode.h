// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PingPongGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG1_API APingPongGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
    APingPongGameMode();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
    int Player1Score;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
    int Player2Score;

   
    void AddScore(int32 PlayerIndex);

protected:
  
    virtual void BeginPlay() override;


    class APingPongHUD* PingPongHUD;
};
