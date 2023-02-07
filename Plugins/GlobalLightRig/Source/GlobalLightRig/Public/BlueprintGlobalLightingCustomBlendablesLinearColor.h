#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BlueprintGlobalLightingCustomBlendablesLinearColor.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintGlobalLightingCustomBlendablesLinearColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ColorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesMessage;
    
    GLOBALLIGHTRIG_API FBlueprintGlobalLightingCustomBlendablesLinearColor();
};

