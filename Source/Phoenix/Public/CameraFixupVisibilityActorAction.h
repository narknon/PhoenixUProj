#pragma once
#include "CoreMinimal.h"
#include "EManagedVisibilityPriority.h"
#include "CameraFixupActorAction.h"
#include "CameraFixupVisibilityActorAction.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraFixupVisibilityActorAction : public UCameraFixupActorAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedVisibilityPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldBeHidden;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IncludeChildActors;
    
    UCameraFixupVisibilityActorAction();
};

