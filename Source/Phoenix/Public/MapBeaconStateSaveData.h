#pragma once
#include "CoreMinimal.h"
#include "MapBeaconStateSaveData.generated.h"

USTRUCT(BlueprintType)
struct FMapBeaconStateSaveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, int32> BeaconStateMap;
    
    PHOENIX_API FMapBeaconStateSaveData();
};

