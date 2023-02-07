#pragma once
#include "CoreMinimal.h"
#include "CameraFixupOperation.h"
#include "CameraFixupSetPositionOperation.generated.h"

class UCameraFixupSetPositionMethod;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UCameraFixupSetPositionOperation : public UCameraFixupOperation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraFixupSetPositionMethod* Method;
    
    UCameraFixupSetPositionOperation();
};

