#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "UObject/NoExportTypes.h"
#include "RootMotionModifier_Strafe.generated.h"

class AAmbulatory_Character;

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_Strafe : public URootMotionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    URootMotionModifier_Strafe();
    UFUNCTION(BlueprintCallable)
    void CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FRotator AmountRotated);
    
    UFUNCTION(BlueprintCallable)
    void CharacterRotatedBySupport(FRotator AmountRotated);
    
};

