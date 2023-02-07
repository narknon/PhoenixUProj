#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableGTAOFromAOVolume.generated.h"

class AAmbientOcclusionVolume;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableGTAOFromAOVolume : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAmbientOcclusionVolume* AmbientOcclusionVolume;
    
    UGlobalLightingBlendableGTAOFromAOVolume();
};

