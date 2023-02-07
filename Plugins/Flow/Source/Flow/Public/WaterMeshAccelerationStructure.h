#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WaterMeshAccelerationStructure.generated.h"

USTRUCT(BlueprintType)
struct FWaterMeshAccelerationStructure {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LakeLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Extents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CellsInRow;
    
public:
    FLOW_API FWaterMeshAccelerationStructure();
};

