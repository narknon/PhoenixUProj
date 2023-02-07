#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingBlendableInputType.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableCustomBlendables.generated.h"

class UGlobalLightingCustomBlendablesValue;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableCustomBlendables : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightingCustomBlendablesValue*> CustomBlendables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightingBlendableInputType OverrideSource;
    
    UGlobalLightingBlendableCustomBlendables();
};

