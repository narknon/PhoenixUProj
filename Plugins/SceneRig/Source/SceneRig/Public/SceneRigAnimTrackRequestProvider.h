#pragma once
#include "CoreMinimal.h"
#include "AnimDebugInfo.h"
#include "AnimRequest.h"
#include "AnimRequestProvider.h"
#include "MoveRequestProvider.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigAnimTrackRequestProvider.generated.h"

UCLASS(Blueprintable)
class USceneRigAnimTrackRequestProvider : public UObject, public IAnimRequestProvider, public IMoveRequestProvider, public IAnimDebugInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LayerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimRequest AnimationRequest;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> AnimationObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConstrainedToPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnscaleHipsBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlacementHandledByRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform TransformInWorldSpace;
    
    USceneRigAnimTrackRequestProvider();
    
    // Fix for true pure virtual functions not being implemented
};

