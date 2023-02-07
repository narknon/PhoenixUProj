#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "RootMotionModifier_DodgeDuckAssist.generated.h"

class AAmbulatory_Character;

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_DodgeDuckAssist : public URootMotionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector DesiredFacingDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AngleOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float YawRecovery;
    
    URootMotionModifier_DodgeDuckAssist();
    UFUNCTION(BlueprintCallable)
    void CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated);
    
};

