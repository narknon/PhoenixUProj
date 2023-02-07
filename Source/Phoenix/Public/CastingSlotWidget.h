#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ESpellDirection.h"
#include "CastingSlotWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCastingSlotWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpellDirection SpellDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SpellIconName;
    
public:
    UCastingSlotWidget();
    UFUNCTION(BlueprintCallable)
    void SetImage(const FString& ImageName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetSpellIcon();
    
};

