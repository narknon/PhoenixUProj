#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StencilManagerEffectInfoActorOverrides.h"
#include "StencilManagerWholeActorOverrides.generated.h"

UCLASS(Blueprintable)
class STENCILMANAGER_API UStencilManagerWholeActorOverrides : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStencilManagerEffectInfoActorOverrides> WholeActorOverrides;
    
    UStencilManagerWholeActorOverrides();
    UFUNCTION(BlueprintCallable)
    void Validate();
    
};

