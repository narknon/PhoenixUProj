#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectAsset_Connection.h"
#include "BaseArchitectAsset.h"
#include "AnimationArchitectAsset.generated.h"

class UAnimationArcitectAsset_ConnectionsCluster;

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UAnimationArchitectAsset : public UBaseArchitectAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationArchitectAsset_Connection> ConnectionArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimationArcitectAsset_ConnectionsCluster* ConnectionsCluster;
    
    UAnimationArchitectAsset();
};

