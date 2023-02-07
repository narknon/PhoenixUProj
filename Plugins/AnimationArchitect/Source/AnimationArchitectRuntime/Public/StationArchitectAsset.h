#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset.h"
#include "StationArchitectAsset_Connection.h"
#include "StationArchitectAsset.generated.h"

class UStationArcitectAsset_ConnectionsCluster;

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UStationArchitectAsset : public UBaseArchitectAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationArchitectAsset_Connection> ConnectionArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStationArcitectAsset_ConnectionsCluster* ConnectionCluster;
    
    UStationArchitectAsset();
};

