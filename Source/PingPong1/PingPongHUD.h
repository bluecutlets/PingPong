// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PingPongHUD.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG1_API APingPongHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

	void UpdateScore(int Player1Score, int Player2Score);

private:

	int P1Score;
	int P2Score;


};
