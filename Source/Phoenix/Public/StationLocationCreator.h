#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StationLocationCreator.generated.h"

class AEncounterCreator;
class AStation;

UCLASS(Blueprintable)
class AStationLocationCreator : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StationLocationCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EncounterCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AEncounterCreator*> EncounterCreators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AStation*> StationLocations;
    
    AStationLocationCreator();
};

