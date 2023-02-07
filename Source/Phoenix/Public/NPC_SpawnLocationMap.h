#pragma once
#include "CoreMinimal.h"
#include "ENPC_Spawn.h"
#include "NPC_SpawnLocationMap.generated.h"

USTRUCT(BlueprintType)
struct FNPC_SpawnLocationMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Spawn Type;
    
    PHOENIX_API FNPC_SpawnLocationMap();
};

