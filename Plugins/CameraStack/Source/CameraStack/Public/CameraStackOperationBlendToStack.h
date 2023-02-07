#pragma once
#include "CoreMinimal.h"
#include "CameraStackOperationBase.h"
#include "CameraStackOperationBlendToStack.generated.h"

class UCameraStackSettings;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackOperationBlendToStack : public UCameraStackOperationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraStackSettings* StackSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLazyBlendOut;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReuseBehaviorOnReactivate;
    
    UCameraStackOperationBlendToStack();
};

