#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "ECustomInterpType.h"
#include "RootMotionModifierProperties_InterpToStop.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_InterpToStop : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> ToStopInterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToStopInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToStopTotalTime;
    
    URootMotionModifierProperties_InterpToStop();
};

