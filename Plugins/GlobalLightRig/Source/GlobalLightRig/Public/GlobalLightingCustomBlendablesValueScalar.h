#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendableNameScalar.h"
#include "GlobalLightingCustomBlendablesValueAllowDefaults.h"
#include "GlobalLightingCustomBlendablesValueScalar.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValueScalar : public UGlobalLightingCustomBlendablesValueAllowDefaults {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingCustomBlendableNameScalar Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UGlobalLightingCustomBlendablesValueScalar();
};

