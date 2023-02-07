#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimatedLightExtraParameter.h"
#include "AnimatedLightExtraParameterRuntime.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAnimatedLightExtraParameterRuntime : public FAnimatedLightExtraParameter {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLinearColor LastValue;
    
    ANIMATEDLIGHTS_API FAnimatedLightExtraParameterRuntime();
};

