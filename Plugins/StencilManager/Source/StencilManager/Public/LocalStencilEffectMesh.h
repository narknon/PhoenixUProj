#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocalStencilEffectMeshBase.h"
#include "LocalStencilEffectMesh.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FLocalStencilEffectMesh : public FLocalStencilEffectMeshBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform LastTransform;
    
    FLocalStencilEffectMesh();
};

