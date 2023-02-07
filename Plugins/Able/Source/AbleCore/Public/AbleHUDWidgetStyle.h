#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "AbleHUDStyle.h"
#include "AbleHUDWidgetStyle.generated.h"

UCLASS(Blueprintable)
class UAbleHUDWidgetStyle : public USlateWidgetStyleContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAbleHUDStyle AbleHUDWidgetStyle;
    
    UAbleHUDWidgetStyle();
};

