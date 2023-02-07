#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ObjectHabitatFoliageType.generated.h"

class UFoliageType_InstancedStaticMesh;

USTRUCT(BlueprintType)
struct FObjectHabitatFoliageType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFoliageType_InstancedStaticMesh> FoliageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFoliageDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequired;
    
    PHOENIX_API FObjectHabitatFoliageType();
};

