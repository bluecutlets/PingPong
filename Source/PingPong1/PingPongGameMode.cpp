#include "PingPongGameMode.h"
#include "PingPongHUD.h"
#include "Kismet/GameplayStatics.h"

APingPongGameMode::APingPongGameMode()
{
   
    Player1Score = 0;
    Player2Score = 0;
}

void APingPongGameMode::BeginPlay()
{
    Super::BeginPlay();

    
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PlayerController)
    {
        
        PingPongHUD = Cast<APingPongHUD>(PlayerController->GetHUD());
        if (PingPongHUD)
        {
           // UE_LOG(LogTemp, Warning, TEXT("HUD найден и инициализирован."));
         
            PingPongHUD->UpdateScore(Player1Score, Player2Score);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Не удалось найти HUD."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Не удалось получить PlayerController."));
    }
}

void APingPongGameMode::AddScore(int32 PlayerIndex)
{
   
    if (PlayerIndex == 1)
    {
        Player1Score++;
        UE_LOG(LogTemp, Warning, TEXT("Счет игрока 1: %d"), Player1Score);
    }
    else if (PlayerIndex == 2)
    {
        Player2Score++;
        UE_LOG(LogTemp, Warning, TEXT("Счет игрока 2: %d"), Player2Score);
    }

    if (PingPongHUD)
    {
        PingPongHUD->UpdateScore(Player1Score, Player2Score);
    }
}
