#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "AmbulatoryHUDStyle.h"
#include "AmbulatoryHUDWidgetStyle.generated.h"

UCLASS(Blueprintable)
class UAmbulatoryHUDWidgetStyle : public USlateWidgetStyleContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAmbulatoryHUDStyle AmbulatoryHUDWidgetStyle;
    
    UAmbulatoryHUDWidgetStyle();
};

