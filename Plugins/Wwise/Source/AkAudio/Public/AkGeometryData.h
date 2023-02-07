#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AkAcousticSurface.h"
#include "AkTriangle.h"
#include "AkGeometryData.generated.h"

class UPhysicalMaterial;

USTRUCT(BlueprintType)
struct FAkGeometryData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Vertices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAkAcousticSurface> Surfaces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAkTriangle> Triangles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPhysicalMaterial*> ToOverrideAcousticTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPhysicalMaterial*> ToOverrideOcclusion;
    
    AKAUDIO_API FAkGeometryData();
};

