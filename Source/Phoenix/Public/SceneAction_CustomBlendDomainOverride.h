#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainName.h"
#include "SceneAction_CustomBlendDomainOverrideBase.h"
#include "SceneAction_CustomBlendDomainOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CustomBlendDomainOverride : public USceneAction_CustomBlendDomainOverrideBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    USceneAction_CustomBlendDomainOverride();
};

