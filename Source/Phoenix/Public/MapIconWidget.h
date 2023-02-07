#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapIconWidget.generated.h"

class UImage;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UMapIconWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* IconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* RegionBorder;
    
    UMapIconWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayFanfare_Event();
    
    UFUNCTION(BlueprintCallable)
    float GetZoomFactor();
    
    UFUNCTION(BlueprintCallable)
    float GetPitchFactor();
    
    UFUNCTION(BlueprintCallable)
    float GetDistanceFromGround();
    
};

