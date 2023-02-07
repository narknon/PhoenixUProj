#pragma once
#include "CoreMinimal.h"
#include "HUDElementGroup.h"
#include "QuickHealthActions.generated.h"

class AActor;
class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UQuickHealthActions : public UHUDElementGroup {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentHealthItem;
    
public:
    UQuickHealthActions();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateHealthBar(float NewPct);
    
    UFUNCTION(BlueprintCallable)
    void SetMaxHealth(int32 NewMaxHealth);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetMaxHealth(float NewHealthSize);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIconTextureLoaded(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(AActor* Actor, float Delta, bool IndicateHUD);
    
    UFUNCTION(BlueprintCallable)
    void LoadIconCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisplayItemCount(int32 Count);
    
};

