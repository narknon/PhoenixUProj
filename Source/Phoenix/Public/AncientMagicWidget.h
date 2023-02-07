#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AncientMagicWidget.generated.h"

class UImage;

UCLASS(Blueprintable, EditInlineNew)
class UAncientMagicWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* Reticule;
    
    UAncientMagicWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowDiscoverProgressButton(bool Show);
    
    UFUNCTION(BlueprintCallable)
    void SetReticuleScale(float Scale);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetProgress(float Progress);
    
};

