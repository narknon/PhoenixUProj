#pragma once
#include "CoreMinimal.h"
#include "ObjectSpawnTime.generated.h"

USTRUCT(BlueprintType)
struct FObjectSpawnTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Spawn24Hour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnMinute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnSecond;
    
    PHOENIX_API FObjectSpawnTime();
};

