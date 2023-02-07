#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interface_RenderSettingsCustomBlendDomainOverride.h"
#include "RenderSettingsCustomBlendDomainOverrideComponentBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainOverrideComponentBase : public UActorComponent, public IInterface_RenderSettingsCustomBlendDomainOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    URenderSettingsCustomBlendDomainOverrideComponentBase();
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bEnable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsEnabled(bool& bEnable) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

