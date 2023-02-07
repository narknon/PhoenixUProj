#pragma once
#include "CoreMinimal.h"
#include "ECustomInterpType.h"
#include "EWandLinkInputType.h"
#include "WandLinkUIMiniGame.h"
#include "WandLinkUIMiniGame_ButtonMashDifficultyLevels.h"
#include "WandLinkUIMiniGame_ButtonMash.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWandLinkUIMiniGame_ButtonMash : public UWandLinkUIMiniGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWandLinkUIMiniGame_ButtonMashDifficultyLevels EasyDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWandLinkUIMiniGame_ButtonMashDifficultyLevels MediumDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWandLinkUIMiniGame_ButtonMashDifficultyLevels HardDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWandLinkUIMiniGame_ButtonMashDifficultyLevels StoryModeDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> AntagonistStartingSurgeToPctInterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AntagonistStartingSurgeToPctInterpSpeedOrExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AntagonistStartingSurgeToPctInterpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ButtonMashTimeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWandLinkInputType WandLinkButtonMashInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> ProtagonistAttackInterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistAttackInterpSpeedOrExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistAttackInterpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FailDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SuccessDelay;
    
    UWandLinkUIMiniGame_ButtonMash();
    UFUNCTION(BlueprintCallable)
    void IncorrectButtonMashed();
    
    UFUNCTION(BlueprintCallable)
    void CorrectButtonMashed();
    
    UFUNCTION(BlueprintCallable)
    void CheatButtonSuccessPressed();
    
    UFUNCTION(BlueprintCallable)
    void CheatButtonFailPressed();
    
};

