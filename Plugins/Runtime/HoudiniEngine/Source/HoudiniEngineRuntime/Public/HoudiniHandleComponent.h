#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EHoudiniHandleType.h"
#include "HoudiniHandleComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class HOUDINIENGINERUNTIME_API UHoudiniHandleComponent : public USceneComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHoudiniHandleType HandleType;
    
public:
    UHoudiniHandleComponent();
};

