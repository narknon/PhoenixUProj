#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraStackOperationBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class CAMERASTACK_API UCameraStackOperationBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UCameraStackOperationBase();
};

