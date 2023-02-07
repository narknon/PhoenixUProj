#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ControlMapperBPFunctionLibrary.generated.h"

class AActor;
class UInputComponent;
class UObject;

UCLASS(Blueprintable)
class CONTROLMAPPER_API UControlMapperBPFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UControlMapperBPFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetInputAxisValue(AActor* InputComponentOwner, const FName InputAxisName);
    
    UFUNCTION(BlueprintCallable)
    static void EnableCustomInput(UObject* InputReceiver, UInputComponent* InputComponent);
    
    UFUNCTION(BlueprintCallable)
    static void DisableCustomInput(UObject* InputReceiver, UInputComponent* InputComponent);
    
};

