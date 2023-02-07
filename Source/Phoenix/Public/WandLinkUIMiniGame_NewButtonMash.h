#pragma once
#include "CoreMinimal.h"
#include "ECustomInterpType.h"
#include "EWandLinkInputType.h"
#include "WandLinkUIMiniGame.h"
#include "WandLinkUIMiniGame_NewButtonMash.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWandLinkUIMiniGame_NewButtonMash : public UWandLinkUIMiniGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AntagonistAttackSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ButtonMashMeterInterpInSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ButtonMashTimeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ButtonMashDecreaseRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ButtonMashNearSuccessCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWandLinkInputType WandLinkButtonMashInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWandLinkInputType WandLinkSuccessInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistSuccessSurge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> ProtagonistAttackInterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistAttackInterpSpeedOrExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistAttackInterpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtagonistFailSurge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FailDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FailAttackonistSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SuccessDelay;
    
    UWandLinkUIMiniGame_NewButtonMash();
    UFUNCTION(BlueprintCallable)
    void SuccessTimerExpired();
    
    UFUNCTION(BlueprintCallable)
    void SuccessComboButtonReleased();
    
    UFUNCTION(BlueprintCallable)
    void SuccessComboButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    void SuccessButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    void IncorrectSuccessButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    void IncorrectButtonMashed();
    
    UFUNCTION(BlueprintCallable)
    void FailTimerExpired();
    
    UFUNCTION(BlueprintCallable)
    void CorrectButtonMashed();
    
    UFUNCTION(BlueprintCallable)
    void CheatButtonSuccessPressed();
    
    UFUNCTION(BlueprintCallable)
    void CheatButtonFailPressed();
    
};

