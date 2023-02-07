#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperation.h"
#include "CameraFixupSetTargetOperation.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UCameraFixupSetTargetOperation : public UCameraFixupOperation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 DrawDebug: 1;
    
    UCameraFixupSetTargetOperation();
};

