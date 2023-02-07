#pragma once
#include "CoreMinimal.h"
#include "CameraStackOperationBase.h"
#include "Templates/SubclassOf.h"
#include "CameraStackOperationDisable.generated.h"

class UCameraStackBehavior;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackOperationDisable : public UCameraStackOperationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCameraStackBehavior>> BehaviorsToDisable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FilterFlags;
    
    UCameraStackOperationDisable();
};

