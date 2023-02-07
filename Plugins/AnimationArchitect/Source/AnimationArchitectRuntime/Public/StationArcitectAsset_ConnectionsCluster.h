#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StationArchitectAsset_Connection.h"
#include "StationArcitectAsset_ConnectionsCluster.generated.h"

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UStationArcitectAsset_ConnectionsCluster : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationArchitectAsset_Connection> ConnectionArray;
    
    UStationArcitectAsset_ConnectionsCluster();
};

