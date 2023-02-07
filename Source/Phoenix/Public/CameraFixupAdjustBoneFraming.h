#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperation.h"
#include "CameraFixupAdjustBoneFraming.generated.h"

class UFloatProvider;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UCameraFixupAdjustBoneFraming : public UCameraFixupOperation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* TargetBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* ReferenceBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* DeadDistanceProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* WeightProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 DrawDebug: 1;
    
    UCameraFixupAdjustBoneFraming();
};

