#pragma once
#include "CoreMinimal.h"
#include "Engine/InputActionDelegateBinding.h"
#include "SplitWindow.h"
#include "CustomBlueprintInputDelegateBinding.generated.h"

class UWatcherRecord;

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FCustomBlueprintInputDelegateBinding : public FBlueprintInputActionDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWatcherRecord* WatcherRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSplitWindow SplitWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesGameLogic;
    
    FCustomBlueprintInputDelegateBinding();
};

