#pragma once
#include "CoreMinimal.h"
#include "ESkinFXPreviewType.h"
#include "SkinFXMaterialOverride.h"
#include "SkinFXPreviewAnimationSetup.h"
#include "SkinFXPreviewSetup.generated.h"

class USkeletalMesh;
class UStaticMesh;

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXPreviewSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXPreviewType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> StaticMeshAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> SkeletalMeshAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXPreviewAnimationSetup Animation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialOverride MaterialOverrides;
    
    FSkinFXPreviewSetup();
};

