#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BlueprintGlobalLightingCustomBlendablesLinearColor.h"
#include "BlueprintGlobalLightingCustomBlendablesScalar.h"
#include "BlueprintGlobalLightingCustomBlendables.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=BlueprintGlobalLightingCustomBlendables)
class GLOBALLIGHTRIG_API UBlueprintGlobalLightingCustomBlendables : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBlueprintGlobalLightingCustomBlendablesScalar> Scalars;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBlueprintGlobalLightingCustomBlendablesLinearColor> Colors;
    
    UBlueprintGlobalLightingCustomBlendables();
};

