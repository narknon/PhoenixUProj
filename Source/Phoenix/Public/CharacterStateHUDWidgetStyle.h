#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "CharacterStateHUDStyle.h"
#include "CharacterStateHUDWidgetStyle.generated.h"

UCLASS(Blueprintable)
class UCharacterStateHUDWidgetStyle : public USlateWidgetStyleContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterStateHUDStyle CharacterStateHUDWidgetStyle;
    
    UCharacterStateHUDWidgetStyle();
};

