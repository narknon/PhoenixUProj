#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IconNoteWidget.generated.h"

class UImage;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UIconNoteWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* NoteImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* NoteLabel;
    
    UIconNoteWidget();
    UFUNCTION(BlueprintCallable)
    void SetDetails(const FString& IconName, int32 Quantity, FText DescriptionOverride, const bool bAlreadyTranslated);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

