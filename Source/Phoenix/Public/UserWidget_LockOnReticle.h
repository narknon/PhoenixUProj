#pragma once
#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "HUDElementGroup.h"
#include "UserWidget_LockOnReticle.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UUserWidget_LockOnReticle : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleMax;
    
    UUserWidget_LockOnReticle();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLockOnVisibility(const ESlateVisibility InVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAimModeVisibility(const ESlateVisibility InVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAimModeCircleScale(float InScale);
    
};

