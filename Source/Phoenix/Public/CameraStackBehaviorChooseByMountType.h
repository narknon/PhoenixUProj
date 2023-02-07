#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorChooseByMountType.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorChooseByMountType : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackBehavior* DefaultBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FName, UCameraStackBehavior*> MountSpecificBehaviors;
    
    UCameraStackBehaviorChooseByMountType();
};

