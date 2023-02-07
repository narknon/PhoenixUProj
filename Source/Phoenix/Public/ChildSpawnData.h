#pragma once
#include "CoreMinimal.h"
#include "ChildSpawnData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FChildSpawnData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ParentActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SpawnChildren;
    
    PHOENIX_API FChildSpawnData();
};

