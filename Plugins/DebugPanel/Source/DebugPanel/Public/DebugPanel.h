#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DebugPanelControl.h"
#include "DebugPanel.generated.h"

UCLASS(Blueprintable, Transient)
class DEBUGPANEL_API UDebugPanel : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDebugPanelControl Controls[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bVisible;
    
public:
    UDebugPanel();
};

