#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationArchitectAsset_Connection.h"
#include "AnimationArcitectAsset_ConnectionsCluster.generated.h"

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UAnimationArcitectAsset_ConnectionsCluster : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationArchitectAsset_Connection> ConnectionArray;
    
    UAnimationArcitectAsset_ConnectionsCluster();
};

