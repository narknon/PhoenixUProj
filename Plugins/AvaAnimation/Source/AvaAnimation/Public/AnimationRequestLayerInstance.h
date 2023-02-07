#pragma once
#include "CoreMinimal.h"
#include "AnimRequest.h"
#include "MoveRequest.h"
#include "AnimationRequestLayerInstance.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationRequestLayerInstance {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> AnimRequestProviders;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> PlacementRequestProviders;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> RootMotionRequestProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAnimRequest> AnimRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMoveRequest> PlacementRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMoveRequest> RootMotionRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LayerWeight;
    
    FAnimationRequestLayerInstance();
};

