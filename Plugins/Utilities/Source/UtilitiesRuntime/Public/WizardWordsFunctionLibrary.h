#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WizardWordsFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UWizardWordsFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UWizardWordsFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static FString EncryptString(const FString& Word);
    
};

