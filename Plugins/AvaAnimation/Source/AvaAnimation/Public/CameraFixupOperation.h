#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraFixupOperation.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UCameraFixupOperation : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IgnorePreviousStateTime;
    
    UCameraFixupOperation();
};

