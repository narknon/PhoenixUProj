#pragma once
#include "CoreMinimal.h"
#include "Curves/RichCurve.h"
#include "Sections/MovieScene3DTransformSection.h"
#include "ESceneRigAnimationTrackConstraintMode.h"
#include "SceneRigAnimationTrackPlacementOptions.generated.h"

class UAnimationTransformProvider;
class UTransformProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigAnimationTrackPlacementOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConstrainedToPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnscaleHipsBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigAnimationTrackConstraintMode ConstraintMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlacementRespectsBlends;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Placement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationTransformProvider* PlacementOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneTransformMask TransformMask;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve Translation[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve Rotation[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve Scale[3];
    
    FSceneRigAnimationTrackPlacementOptions();
};

