#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocalizationDebuggerWindow.generated.h"

class UUserWidget;

UCLASS(Blueprintable)
class ULocalizationDebuggerWindow : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* Widget;
    
    ULocalizationDebuggerWindow();
};

