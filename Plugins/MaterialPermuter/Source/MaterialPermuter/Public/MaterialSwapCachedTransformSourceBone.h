#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapCachedTransformSourceBone.generated.h"

class USkinnedMeshComponent;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapCachedTransformSourceBone {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkinnedMeshComponent> SkinnedMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BoneIndex;
    
    FMaterialSwapCachedTransformSourceBone();
};

