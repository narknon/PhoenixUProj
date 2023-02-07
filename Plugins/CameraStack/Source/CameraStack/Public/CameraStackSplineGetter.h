#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraStackSplineGetter.generated.h"

class UCameraStack;
class USplineComponent;

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class CAMERASTACK_API UCameraStackSplineGetter : public UObject {
    GENERATED_BODY()
public:
    UCameraStackSplineGetter();
    UFUNCTION(BlueprintCallable)
    void Update(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USplineComponent* GetSpline() const;
    
    UFUNCTION(BlueprintCallable)
    void Activate(UCameraStack* InList);
    
};

