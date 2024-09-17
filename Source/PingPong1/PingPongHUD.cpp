#include "PingPongHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "UObject/ConstructorHelpers.h"


void APingPongHUD::DrawHUD()
{
    Super::DrawHUD();
  
    if (Canvas)
    {    
        FString ScoreText = FString::Printf(TEXT("Player 1: %d | Player 2: %d"), P1Score, P2Score);
    
        FVector2D ScreenPosition = FVector2D(50, 50);
        
        FCanvasTextItem TextItem(ScreenPosition, FText::FromString(ScoreText), GEngine->GetLargeFont(), FLinearColor::White);

        Canvas->DrawItem(TextItem);
    }
}

void APingPongHUD::UpdateScore(int Player1Score, int Player2Score)
{
    P1Score = Player1Score;
    P2Score = Player2Score;

}
