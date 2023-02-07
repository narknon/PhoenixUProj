#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BTCustomBPFunctionLibrary.generated.h"

class UBTCustomComponent;
class UObject;

UCLASS(Blueprintable)
class BTCUSTOMRUNTIME_API UBTCustomBPFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBTCustomBPFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void EnableBTCustomAction(UObject* InputReceiver, UBTCustomComponent* InputComponent);
    
    UFUNCTION(BlueprintCallable)
    static void DisableBTCustomAction(UObject* InputReceiver, UBTCustomComponent* InputComponent);
    
};

