#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "HUDCompassIcon.generated.h"

class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UHUDCompassIcon : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAnimating;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InElevationRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldShowElevationHint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInPathedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInLockedState;
    
    UHUDCompassIcon();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TogglePathingBorder(bool ShowBorder, const FString& OutlineIconName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ToggleLockBadge(bool ShowLock);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowIndicatorArrow(bool ShouldShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowDistance(bool ShouldShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRotation(float Angle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPulse(bool Enable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIndicatorArrowRotation(float DegreeRot);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIconTextureByName(const FString& IconName, bool ShowPulse);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIconTexture(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIconSize(FVector2D NewSize);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIconScale(float Scale);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIconOpacity(float Opacity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetElevationVisibility(ESlateVisibility NewVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetElevationDistance(int32 Distance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetDistanceValue(int32 Distance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCompassIconVisibility(ESlateVisibility NewVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCompassIconColorAndOpacity(FLinearColor NewColor);
    
};

