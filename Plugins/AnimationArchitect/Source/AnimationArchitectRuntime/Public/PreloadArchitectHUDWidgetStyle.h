#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "PreloadArchitectHUDStyle.h"
#include "PreloadArchitectHUDWidgetStyle.generated.h"

UCLASS(Blueprintable)
class UPreloadArchitectHUDWidgetStyle : public USlateWidgetStyleContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreloadArchitectHUDStyle PreloadArchitectHUDStyle;
    
    UPreloadArchitectHUDWidgetStyle();
};

