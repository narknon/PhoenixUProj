#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectMeshBase.h"
#include "LocalStencilEffectMeshAttached.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FLocalStencilEffectMeshAttached : public FLocalStencilEffectMeshBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> ParentComponent;
    
    FLocalStencilEffectMeshAttached();
};

