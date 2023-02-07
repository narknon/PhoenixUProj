#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PausePopoutWidget.generated.h"

class UHeaderWidget;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UPausePopoutWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHeaderWidget* PopoutHeader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* PopoutDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* LegendText;
    
    UPausePopoutWidget();
    UFUNCTION(BlueprintCallable)
    void SetPopoutData(FText NewTitle, FText NewDescription);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPopoutDataSet();
    
};

