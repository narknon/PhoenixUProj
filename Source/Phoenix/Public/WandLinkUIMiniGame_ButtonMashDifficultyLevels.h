#pragma once
#include "CoreMinimal.h"
#include "WandLinkUIMiniGame_ButtonMashDifficultyLevels.generated.h"

USTRUCT(BlueprintType)
struct FWandLinkUIMiniGame_ButtonMashDifficultyLevels {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AntagonistAttackSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AntagonistStartingSurgeToPct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistMashInterpToSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistNoMashInterpToZero;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistAttackSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistWinConditionPct;
    
    PHOENIX_API FWandLinkUIMiniGame_ButtonMashDifficultyLevels();
};

