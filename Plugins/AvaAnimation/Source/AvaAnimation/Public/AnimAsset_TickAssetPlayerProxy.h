#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/ObjectMacros.h"
#include "Animation/AnimationAsset.h"
#include "TickAssetPlayerProxy_WeightedNotify.h"
#include "AnimAsset_TickAssetPlayerProxy.generated.h"

UCLASS(Blueprintable, DefaultToInstanced, Transient)
class AVAANIMATION_API UAnimAsset_TickAssetPlayerProxy : public UAnimationAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTickAssetPlayerProxy_WeightedNotify> WeightedNotifies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ActorMoveDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActorMoveDeltaWeight;
    
    UAnimAsset_TickAssetPlayerProxy();

    /*//Begin UObject Interface
    virtual void PostLoad() override;
    virtual void Serialize(FArchive& Ar) override;
    //End UObject Interface*/
    
};

