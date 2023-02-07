#pragma once
#include "CoreMinimal.h"
#include "CachedMIDParameters.h"
#include "MeshSwappedMaterial.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMeshSwappedMaterial {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCachedMIDParameters CachedParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* OriginalMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* SwapMID;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int16 Index;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int16 flags;
    
public:
    FMeshSwappedMaterial();
};

