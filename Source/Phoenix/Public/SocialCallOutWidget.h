#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SocialCallout.h"
#include "SocialCallOutWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USocialCallOutWidget : public UUserWidget {
    GENERATED_BODY()
public:
    USocialCallOutWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateCallout(FSocialCallout SocialCallout);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowCallout();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveCallout();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

