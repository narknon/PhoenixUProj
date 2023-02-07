#pragma once
#include "CoreMinimal.h"
#include "CustomBlendableVDHW.h"
#include "EGlobalLightingBlendableInputType.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableVDHW.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableVDHW : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomBlendableVDHW VDHW;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightingBlendableInputType OverrideSource;
    
    UGlobalLightingBlendableVDHW();
};

