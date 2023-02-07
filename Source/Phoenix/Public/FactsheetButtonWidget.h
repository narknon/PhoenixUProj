#pragma once
#include "CoreMinimal.h"
#include "EFactsheetButtonState.h"
#include "IconButtonWidget.h"
#include "FactsheetButtonWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UFactsheetButtonWidget : public UIconButtonWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FactsheetButtonItemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FactsheetButtonItemDesc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FactsheetButtonCharacterAsked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FactsheetButtonSuggestedLead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFactsheetButtonState FactsheetButtonItemState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FactsheetRelativeSocialCapital;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FactsheetSocialNeeded;
    
    UFactsheetButtonWidget();
};

