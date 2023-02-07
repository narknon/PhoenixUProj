#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CachedStation.h"
#include "NavMeshCache.generated.h"

UCLASS(Blueprintable)
class UNavMeshCache : public UDataAsset {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCachedStation> PathMatrix;
    
public:
    UNavMeshCache();
};

