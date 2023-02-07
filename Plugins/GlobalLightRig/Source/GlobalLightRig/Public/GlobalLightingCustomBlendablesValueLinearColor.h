#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalLightingCustomBlendableNameLinearColor.h"
#include "GlobalLightingCustomBlendablesValueAllowDefaults.h"
#include "GlobalLightingCustomBlendablesValueLinearColor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValueLinearColor : public UGlobalLightingCustomBlendablesValueAllowDefaults {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingCustomBlendableNameLinearColor Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    UGlobalLightingCustomBlendablesValueLinearColor();
};

