#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AkBoolPropertyToControl.h"
#include "AkItemBoolPropertiesConv.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkItemBoolPropertiesConv : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAkItemBoolPropertiesConv();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText Conv_FAkBoolPropertyToControlToText(const FAkBoolPropertyToControl& INAkBoolPropertyToControl);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString Conv_FAkBoolPropertyToControlToString(const FAkBoolPropertyToControl& INAkBoolPropertyToControl);
    
};

