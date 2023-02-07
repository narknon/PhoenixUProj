#pragma once
#include "CoreMinimal.h"
#include "ESpellCategory.h"
#include "IconButtonWidget.h"
#include "SelectionRingItemBase.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API USelectionRingItemBase : public UIconButtonWidget {
    GENERATED_BODY()
public:
    USelectionRingItemBase();
    UFUNCTION(BlueprintCallable)
    void ShowUpdateVFX();
    
    UFUNCTION(BlueprintCallable)
    void SetItemData(int32 GroupIndex, int32 MacroIndex, int32 ItemIndex, bool ShowNone);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowUpdateVFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIconTextureLoaded(UTexture2D* Texture, bool IsBlacklisted);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBackgroundTextureLoaded(UTexture2D* Texture, bool IsBlacklisted);
    
private:
    UFUNCTION(BlueprintCallable)
    void LoadIconCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void LoadBackgroundCallback(UTexture2D* Texture, UObject* Param);
    
public:
    UFUNCTION(BlueprintCallable)
    ESpellCategory GetSpellCategory();
    
};

