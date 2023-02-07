#pragma once
#include "CoreMinimal.h"
#include "Engine/InputActionDelegateBinding.h"
#include "SplitWindow.h"
#include "CustomBlueprintStickInputDelegateBinding.generated.h"

class UWatcherRecord;

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FCustomBlueprintStickInputDelegateBinding : public FBlueprintInputActionDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWatcherRecord* WatcherRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSplitWindow SplitWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesGameLogic;
    
    FCustomBlueprintStickInputDelegateBinding();
};

