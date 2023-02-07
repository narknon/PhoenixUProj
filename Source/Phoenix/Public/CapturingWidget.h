#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HUDElementGroup.h"
#include "CapturingWidget.generated.h"

class ACaptureDeviceItemTool;
class USceneComponent;

UCLASS(Blueprintable, EditInlineNew)
class UCapturingWidget : public UHUDElementGroup {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACaptureDeviceItemTool* CaptureDevice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* AttachedComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsProjectedFromOffscreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector2D ProjectionDirection;
    
public:
    UCapturingWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Show();
    
    UFUNCTION(BlueprintCallable)
    void RemoveFromHUD();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideWhenReady(float HideAfterTime);
    
};

