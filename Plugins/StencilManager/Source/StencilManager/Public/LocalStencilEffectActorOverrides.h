#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LocalStencilEffectActorOverride.h"
#include "LocalStencilEffectActorOverrideList.h"
#include "LocalStencilEffectActorOverrides.generated.h"

UCLASS(Blueprintable)
class STENCILMANAGER_API ULocalStencilEffectActorOverrides : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectActorOverride> GeneralActorOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectActorOverrideList> EffectOverrides;
    
    ULocalStencilEffectActorOverrides();
    UFUNCTION(BlueprintCallable)
    void Validate();
    
};

