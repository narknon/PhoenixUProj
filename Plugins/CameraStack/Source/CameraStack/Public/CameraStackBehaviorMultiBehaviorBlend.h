#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorMultiBehaviorBlend.generated.h"

class UCameraStackBehavior;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorMultiBehaviorBlend : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraStackBehavior* FirstBehavior;
    
public:
    UCameraStackBehaviorMultiBehaviorBlend();
    UFUNCTION(BlueprintCallable)
    void Initialize(UCameraStackBehavior* InFirstBehavior);
    
};

