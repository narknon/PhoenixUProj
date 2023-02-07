#pragma once
#include "CoreMinimal.h"
#include "LocalStencilComponentBase.h"
#include "LocalStencilEffectMeshAttached.h"
#include "LocalStencilComponentMultiMesh.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class STENCILMANAGER_API ULocalStencilComponentMultiMesh : public ULocalStencilComponentBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectMeshAttached> EffectMeshes;
    
public:
    ULocalStencilComponentMultiMesh();
};

