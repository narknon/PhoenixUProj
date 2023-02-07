#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperation.h"
#include "CameraFixupSetFocusDistanceOperation.generated.h"

class UFloatProvider;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UCameraFixupSetFocusDistanceOperation : public UCameraFixupOperation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* DistanceTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* DistanceOffsetProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 DrawDebug: 1;
    
    UCameraFixupSetFocusDistanceOperation();
};

