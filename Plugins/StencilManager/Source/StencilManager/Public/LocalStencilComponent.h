#pragma once
#include "CoreMinimal.h"
#include "LocalStencilComponentBase.h"
#include "LocalStencilEffectMesh.h"
#include "LocalStencilComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class STENCILMANAGER_API ULocalStencilComponent : public ULocalStencilComponentBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalStencilEffectMesh EffectMesh;
    
public:
    ULocalStencilComponent();
};

