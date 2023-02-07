#pragma once
#include "CoreMinimal.h"
#include "CameraStackOperationBase.h"
#include "ECameraStackBehaviorSorting.h"
#include "ECameraStackOperationInsertLocation.h"
#include "Templates/SubclassOf.h"
#include "CameraStackOperationInsert.generated.h"

class UCameraStackBehavior;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackOperationInsert : public UCameraStackOperationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackBehavior* Behavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackOperationInsertLocation InsertLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCameraStackBehavior>> BehaviorsToFind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackBehaviorSorting BehaviorSorting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FilterFlags;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLazyBlendOut;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReuseBehaviorOnReactivate;
    
    UCameraStackOperationInsert();
};

