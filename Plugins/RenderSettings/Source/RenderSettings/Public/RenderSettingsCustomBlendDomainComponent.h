#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Interface_RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainNameWithValue.h"
#include "RenderSettingsCustomBlendDomainComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainComponent : public USceneComponent, public IInterface_RenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsCustomBlendDomainNameWithValue> Domains;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    URenderSettingsCustomBlendDomainComponent();
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

