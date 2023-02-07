#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeaderWidget.generated.h"

class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UHeaderWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SubtitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Subtitle;
    
    UHeaderWidget();
    UFUNCTION(BlueprintCallable)
    void SetHeaderTitle(FText NewTitle);
    
    UFUNCTION(BlueprintCallable)
    void SetHeaderSubtitle(FText NewSubtitle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

