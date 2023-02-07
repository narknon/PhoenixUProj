#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpellBarSlotWidget.generated.h"

class UImage;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class USpellBarSlotWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* slotIcon;
    
    USpellBarSlotWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateRechargeMaterial(UTexture2D* newSpellIcon);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSlotState(bool IsActive);
    
    UFUNCTION(BlueprintCallable)
    void SetImage(const FString& ImageName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

