#pragma once
#include "CoreMinimal.h"
#include "EWorldBaseHeightAffect.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainCameraHeight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URenderSettingsCustomBlendDomainCameraHeight : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartHeightMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullHeightMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWorldBaseHeightAffect Base;
    
    URenderSettingsCustomBlendDomainCameraHeight();
};

