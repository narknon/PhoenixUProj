#pragma once
#include "CoreMinimal.h"
#include "EAnimTrackRootMode.h"
#include "ESceneRigAnimationRootBlendMode.h"
#include "SceneRigAnimationPlacementOptions.generated.h"

class UAnimationTransformProvider;
class UBoolProvider;
class UTransformProvider;

USTRUCT(BlueprintType)
struct FSceneRigAnimationPlacementOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimTrackRootMode RootEvaluationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigAnimationRootBlendMode RootBlendMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigAnimationRootBlendMode BlendInRootBlendMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigAnimationRootBlendMode BlendOutRootBlendMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AccumulateRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* ConstrainedToPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* PlacementRespectsBlends;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* PlacementIsMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Placement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationTransformProvider* PlacementOffset;
    
    SCENERIG_API FSceneRigAnimationPlacementOptions();
};

