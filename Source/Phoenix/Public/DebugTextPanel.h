#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapDebugPane.h"
#include "DebugTextPanel.generated.h"

class UUserWidget;

UCLASS(Blueprintable)
class UDebugTextPanel : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* DebugTextPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapDebugPane DebugPanelInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* MapDebugWidgetClass;
    
public:
    UDebugTextPanel();
};

