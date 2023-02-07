#pragma once
#include "CoreMinimal.h"
#include "CreatureSurfaceList.h"
#include "CreatureParticleSurfaceList.generated.h"

USTRUCT(BlueprintType)
struct FCreatureParticleSurfaceList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureSurfaceList Large;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureSurfaceList Medium;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureSurfaceList Small;
    
    PHOENIX_API FCreatureParticleSurfaceList();
};

