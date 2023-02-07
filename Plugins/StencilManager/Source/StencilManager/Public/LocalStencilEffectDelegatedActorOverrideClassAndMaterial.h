#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "Templates/SubclassOf.h"
#include "LocalStencilEffectDelegatedActorOverrideClassAndMaterial.generated.h"

class ULocalStencilComponentBase;
class UMaterialInterface;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorOverrideClassAndMaterial : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULocalStencilComponentBase> OverrideClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* OverrideMaterial;
    
    ULocalStencilEffectDelegatedActorOverrideClassAndMaterial();
};

