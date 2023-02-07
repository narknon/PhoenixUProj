#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "RootMotionModifier_NPCMobilityTurnAssist.generated.h"

class AAmbulatory_Character;

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_NPCMobilityTurnAssist : public URootMotionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector RootMotionRotationDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector RootMotionTranslationDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector TranslateVec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bApplyTranslateVec;
    
    URootMotionModifier_NPCMobilityTurnAssist();
    UFUNCTION(BlueprintCallable)
    void CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FRotator AmountRotated);
    
    UFUNCTION(BlueprintCallable)
    void CharacterRotatedBySupport(FRotator AmountRotated);
    
};

