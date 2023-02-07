#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DevilsSnareInfo.generated.h"

class UMaterialInstance;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FDevilsSnareInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OffsetForAreaOfEffectVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector IncreaseExtentsForAreaOfEffectVolume;
    
    PHOENIX_API FDevilsSnareInfo();
};

