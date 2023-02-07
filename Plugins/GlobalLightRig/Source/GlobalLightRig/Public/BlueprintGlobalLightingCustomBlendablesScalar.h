#pragma once
#include "CoreMinimal.h"
#include "BlueprintGlobalLightingCustomBlendablesScalar.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintGlobalLightingCustomBlendablesScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ScalarName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesMessage;
    
    GLOBALLIGHTRIG_API FBlueprintGlobalLightingCustomBlendablesScalar();
};

