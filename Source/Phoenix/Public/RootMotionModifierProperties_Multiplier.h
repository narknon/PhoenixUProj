#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "EMultiplierType.h"
#include "RootMotionModifierProperties_Multiplier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_Multiplier : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiplierType MultiplyType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float XAxis_Multiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YAxis_Multiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZAxis_Multiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Multiplier;
    
    URootMotionModifierProperties_Multiplier();
};

