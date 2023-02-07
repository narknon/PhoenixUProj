#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "ECustomInterpType.h"
#include "RootMotionModifierProperties_DodgeDuckAssist.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_DodgeDuckAssist : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantRecovery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawRecoverySpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnAssistSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> TurnAssistType;
    
    URootMotionModifierProperties_DodgeDuckAssist();
};

