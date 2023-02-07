#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SplineSceneRig.generated.h"

class ASceneRigActor;

USTRUCT(BlueprintType)
struct FSplineSceneRig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASceneRigActor* MainParallelSceneRigActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASceneRigActor* InterruptParallelSceneRigActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASceneRigActor* ResumeParallelSceneRigActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform LocalTransform;
    
    PHOENIX_API FSplineSceneRig();
};

