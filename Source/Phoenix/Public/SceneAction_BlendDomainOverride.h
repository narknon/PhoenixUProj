#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "SceneAction_CustomBlendDomainOverrideBase.h"
#include "SceneAction_BlendDomainOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_BlendDomainOverride : public USceneAction_CustomBlendDomainOverrideBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    USceneAction_BlendDomainOverride();
};

