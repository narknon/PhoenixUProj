#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OrientToComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOrientToComponent : public USceneComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bValidTarget;
    
public:
    UOrientToComponent();
    UFUNCTION(BlueprintCallable)
    void ForceUpdate(bool& bSuccess);
    
};

