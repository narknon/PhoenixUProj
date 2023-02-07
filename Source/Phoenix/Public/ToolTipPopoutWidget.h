#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ToolTipPopoutWidget.generated.h"

class UHeaderWidget;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UToolTipPopoutWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PopoutTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PopoutSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PopoutDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PopoutLegend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHeaderWidget* Header;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Description;
    
    UToolTipPopoutWidget();
    UFUNCTION(BlueprintCallable)
    void SetHeaderData(FText NewTitle, FText NewSubtitle);
    
    UFUNCTION(BlueprintCallable)
    void SetDescription(FText NewDescription);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonLegend(FText Legend);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

